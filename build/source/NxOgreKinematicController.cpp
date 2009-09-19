/** File: NxOgreKinematicController.cpp
    Created on: 22-Nov-08
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreKinematicController.h"
#include "NxOgreErrorStream.h"
#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreBox.h"
#include "NxOgreRigidBodyPrototype.h"
#include "NxOgreRigidBody.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

KinematicController::KinematicController(const NxOgre::Vec3 &size, const NxOgre::Vec3& globalPosition, Scene* scene)
: RigidBody(),
  mScene(scene),
  mMaxIter(10),  //< \to_prototype
  mPosition(globalPosition),
  mFilteredPosition(globalPosition),
  mCache(0),
  mStepOffset(0.5), //< \to_prototype,
  mSlopeLimit(0.707),
  mCacheModifier(1.5),
  mConstrainClimbing(false),
  mSkinWidth(0.1),
  mUpDirection(1),
  mSharpness(0.25),
  mMinDistance(0.1),
  mCollisionResponseBump(0),
  mCollisionResponseFriction(1.0),
  mContactPointHeight(0)
{
 mCache = mScene->getScene()->createSweepCache();

 mHandleSlope = mSlopeLimit != 0.0;

 mVolume = NxOgre_New(SimpleBox)();
 mVolume->mCenter = globalPosition;
 mVolume->mExtents = size;
 mVolume->mRotation = Matrix33_Identity;
 mVolume->mUser = this;
 mVolume->mType = Enums::SimpleShape_Box;

 mHalfHeight = mVolume->mExtents[mUpDirection];

 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 prototype->mType = Enums::RigidBodyType_Kinematic;
 prototype->mGlobalPose.set(globalPosition);

 Vec3 boxSize(size);
 boxSize *= Real(0.8);
// mShape = NxOgre_New(Box)(boxSize);
// prototype->mShapes.insert(mShape);

 create(prototype, mScene, &mShapes);

 NxOgre_Delete(prototype);
}

KinematicController::~KinematicController(void)
{
 destroy();
 NxOgre_Delete(mShape);

 mScene->getScene()->releaseSweepCache(mCache);
 mCache = 0;

 NxOgre_Delete(mVolume);
}

Vec3 KinematicController::getPosition(void) const
{
 return Functions::XYZ<NxVec3, Vec3>(mActor->getGlobalPosition());
}


unsigned int KinematicController::move(const Vec3& direction)
{
 
 if (direction.isZero())
  return Enums::KinematicCollisionFlag_NoMove;
 
 unsigned int nbCollisions = 0;
 unsigned int collisionFlags = 0;
 
 bool nonWalkable = false;
 
 Vec3 lastPosition = mVolume->mCenter;
 

 collisionFlags = sweep(direction, false, nonWalkable);
 
 if (nonWalkable)
 {
  mPosition = lastPosition;
  sweep(direction, true, nonWalkable);
 }
 
 if (mSharpness < 0)
  mVolume->mCenter = lastPosition;
 
 mPosition = mVolume->mCenter;
 
 Vec3 Delta = lastPosition;
 Delta -= mVolume->mCenter;
 
 double deltaM2 = (Delta.x * Delta.x) + (Delta.y * Delta.y) + (Delta.z * Delta.z);
 
 if (deltaM2 != 0)
  mActor->moveGlobalPosition(NxVec3(mPosition.x, mPosition.y, mPosition.z));
 
 mFilteredPosition = mPosition;
 
 //\ todo FilteredPosition and feedbackFiltered.
 
 return collisionFlags;
}


unsigned int KinematicController::sweep(const NxOgre::Vec3 &direction, bool isTest, bool &nonWalkable)
{
   
 //
 // Setup
 //
    unsigned int collisionFlags = 0;
    unsigned int nbCollisions = 0;
    
    float stepOffset = mStepOffset;
    
    DoubleReal originalHeight = mVolume->mCenter[mUpDirection];
    DoubleReal originalBottomPoint = originalHeight - mHalfHeight;
    
 //
 // Split direction into three components: Up, Down and Sides.
 //
    Vec3 UpVector;
    Vec3 DownVector;
    
    if (direction[mUpDirection] < 0.f)
     DownVector[mUpDirection] = direction[mUpDirection];
    else
     UpVector[mUpDirection] = direction[mUpDirection];
    
    Vec3 SideVector(direction.x, direction.y, direction.z);
    SideVector[mUpDirection] = 0.f;
   
    if (!SideVector.isZero())
      UpVector[mUpDirection] += stepOffset;
 
 //
 // Volume query caching.
 //
    Vec3 motionExtents = UpVector;
    motionExtents.max(SideVector);
    motionExtents.max(DownVector);
    
    Vec3 extents(mVolume->mExtents.x + mSkinWidth, mVolume->mExtents.y + mSkinWidth, mVolume->mExtents.z + mSkinWidth);
    extents += motionExtents;
    extents *= mCacheModifier;
    
    NxBox sweepLimits;
    sweepLimits.center = NxVec3(mPosition.x, mPosition.y, mPosition.z);
    sweepLimits.extents = NxVec3(extents.x, extents.y, extents.z);
    
    mCache->setVolume(sweepLimits);
    
 //
 // Passes
 //
    
  { //////////////////////////////// UP PASS ////////////////////////////////
    
   if (!isTest)
   {
    if (sweepTest(UpVector, nbCollisions, isTest, false))
    {
     if (nbCollisions)
     {
      collisionFlags |= Enums::KinematicCollisionFlag_Up;
    
      DoubleReal delta = mVolume->mCenter[mUpDirection] - originalHeight;
      if (delta < stepOffset)
       stepOffset = delta;
     }
    }
   }
   
  } //////////////////////////////// UP PASS ////////////////////////////////
  
  
  { //////////////////////////////// SIDE PASS ////////////////////////////////
  
  nbCollisions = 0;
  if (sweepTest(SideVector, nbCollisions, false, false))
   if (nbCollisions)
     collisionFlags |= Enums::KinematicCollisionFlag_Sides;
  
  } //////////////////////////////// SIDE PASS ////////////////////////////////
  
  { //////////////////////////////// DOWN PASS ////////////////////////////////
  
   nbCollisions = 0;
   if (!SideVector.isZero())
    DownVector[mUpDirection] -= stepOffset; 

   if (sweepTest(DownVector, nbCollisions, false, false))
   {
    if (nbCollisions)
    {
     collisionFlags |= Enums::KinematicCollisionFlag_Sides;
     if (mHandleSlope)
     {
      if (mConstrainClimbing && mContactPointHeight > originalBottomPoint + stepOffset)
      {
       nonWalkable = true;
       if (!isTest)
        return collisionFlags;
      }
     }
    }
   }

    //< \note second pass and walk experiment goes here.

  } //////////////////////////////// DOWN PASS ////////////////////////////////

  return collisionFlags;
}



bool KinematicController::sweepTest(const Vec3& direction, unsigned int &nbCollisions, bool isTest, bool normaliseResponse)
{
 
 if (direction.isZero())
  return false;
 
 bool hasMoved = false;
 
 Vec3 current_position = mVolume->mCenter;
 Vec3 target_position = mVolume->mCenter;
 target_position += direction;
 
 nbCollisions = 0;
 unsigned int max_iter = mMaxIter;
 
 while(max_iter--)
 {
  
  Vec3 current_direction = target_position;
  current_direction -= current_position;
  
  const double length = current_direction.magnitude();
  
  if (length < mMinDistance)
   break;
  
  current_direction /= length;
  
  if ((current_direction.dot(direction)) <= 0.0)
   break;
  
  hasMoved = true;
  double distance = length + mSkinWidth;

  NxVec3 sweep_direction(current_direction.x, current_direction.y, current_direction.z);
  sweep_direction *= distance;
  
  NxBox sweep_box;
  sweep_box.center.set(current_position.x, current_position.y, current_position.z);
  sweep_box.extents.set(mVolume->mExtents.x, mVolume->mExtents.y, mVolume->mExtents.z);
  
  NxSweepQueryHit result;

  unsigned int nbHits = mScene->getScene()->linearOBBSweep(sweep_box, sweep_direction, NX_SF_STATICS | NX_SF_DYNAMICS, NULL, 1, &result, NULL);

 // unsigned int nbHits = mActor->linearSweep(sweep_direction, NX_SF_STATICS | NX_SF_DYNAMICS, NULL, 1, &result, NULL, mCache);

  // Haven't hit anything can move.
  if (nbHits == 0)
  {
   current_position = target_position;
   break;
  }

  //< \todo User callback can be called here.
  
  nbCollisions++;
  mContactPointHeight = result.point[mUpDirection];

  if (distance > mSkinWidth)
  {
   Vec3 temp(current_direction);
   temp *= DoubleReal(distance - mSkinWidth);
   current_position += temp;
  }

  NxVec3 world_normal = result.normal;

  if (isTest)
  {
   world_normal[mUpDirection] = 0.0;
   world_normal.normalize();
  }

  sweepCollisionResponse(target_position, current_position, NxVec3(current_direction.x, current_direction.y, current_direction.z), world_normal, normaliseResponse); 

 }

 

 mVolume->mCenter = current_position;


 return hasMoved;

}

void KinematicController::sweepCollisionResponse(Vec3& target, const Vec3& current, const NxVec3& dir, const NxVec3& normal, bool normalise)
{

 NxVec3 reflectDir;
 ComputeReflexionVector(reflectDir, dir, normal);
 reflectDir.normalize();

 NxVec3 NormalCompo, TangentCompo;
 DecomposeVector(NormalCompo, TangentCompo, reflectDir, normal);

 const DoubleReal amplitude = target.distance(current);

 target = current;
 
 if (mCollisionResponseBump != 0.0)
 {
  if (normalise)
   NormalCompo.normalize();
  
  NormalCompo *= mCollisionResponseBump * amplitude;
  target.x += NormalCompo.x;
  target.y += NormalCompo.y;
  target.z += NormalCompo.z;
 }

 if (mCollisionResponseFriction != 0.0)
 {
  if (normalise)
   TangentCompo.normalize();
  
  TangentCompo *= mCollisionResponseFriction * amplitude;
  target.x += TangentCompo.x;
  target.y += TangentCompo.y;
  target.z += TangentCompo.z;
  
 }
 
}

                                                                                       

} // namespace NxOgre

                                                                                       

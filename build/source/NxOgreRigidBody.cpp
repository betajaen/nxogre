/** File: NxOgreRigidBody.cpp
    Created on: 7-Nov-08
    Author: Robin Southern "betajaen"
    SVN: $Id$

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
#include "NxOgreRigidBody.h"

#include "NxOgreScene.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreErrorStream.h"
#include "NxOgreRigidBodyPrototype.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreFunctions.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

RigidBody::RigidBody()
: mActor(0), mScene(0)
{
}

RigidBody::~RigidBody()
{
}

unsigned int RigidBody::getType() const
{
 return Enums::RigidBodyType_Unknown;
}

void RigidBody::create(RigidBodyPrototype* prototype, Scene* scene)
{

 if (mActor != 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that was already created.");
  return;
 }
 
 if (prototype == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no prototype.");
  return;
 }
 
 if (scene == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no scene.");
  return;
 }

 if (prototype->mShapes.size() == 0)
 {
  NxOgre_ThrowError("RigidBody has no shapes.");
  return;
 }

 mScene = scene;

 NxActorDesc actor_description;
 NxBodyDesc  body_description;
 
 ///  actor_description.compartment = 0
 actor_description.contactReportFlags = 0; //< \todo
 actor_description.density = prototype->mDensity;
 actor_description.dominanceGroup = prototype->mDominanceGroup;
 actor_description.flags = prototype->mActorFlags;
 actor_description.forceFieldMaterial = prototype->mForceFieldMaterial;
 actor_description.globalPose.setRowMajor44(prototype->mGlobalPose.ptr());
 actor_description.group = prototype->mGroup;
 actor_description.name = prototype->mName.c_str();

 if (prototype->mType == Enums::RigidBodyType_Dynamic || prototype->mType == Enums::RigidBodyType_Kinematic)
 {
  body_description.angularDamping = prototype->mAngularDamping;
  Functions::XYZ<Vec3, NxVec3>(prototype->mAngularVelocity, body_description.angularVelocity);
  body_description.CCDMotionThreshold = prototype->mCCDMotionThreshold;
  body_description.contactReportThreshold = prototype->mContactReportThreshold;
  body_description.flags = prototype->mBodyFlags;
  body_description.linearDamping = prototype->mLinearDamping;
  Functions::XYZ<Vec3, NxVec3>(prototype->mLinearVelocity, body_description.linearVelocity);
  body_description.mass = prototype->mMass;
  body_description.massLocalPose.setColumnMajor44(prototype->mMassLocalPose.ptr());
  Functions::XYZ<Vec3, NxVec3>(prototype->mMassSpaceInertia, body_description.massSpaceInertia);
  body_description.maxAngularVelocity = prototype->mMaxAngularVelocity;
  body_description.sleepAngularVelocity = prototype->mSleepAngularVelocity;
  body_description.sleepDamping = prototype->mSleepDamping;
  body_description.sleepEnergyThreshold = prototype->mSleepEnergyThreshold;
  body_description.sleepLinearVelocity = prototype->mSleepLinearVelocity;
  body_description.solverIterationCount = prototype->mSolverIterationCount;
  body_description.wakeUpCounter = prototype->mWakeUpCounter;
  actor_description.body = &body_description;

  if (prototype->mType == Enums::RigidBodyType_Kinematic)
  {
   printf("KINEMATIC!!!!!!!!!");
   body_description.flags |= NX_BF_KINEMATIC;
  }
 }
 else if (prototype->mType == Enums::RigidBodyType_Geometry)
 {
 }
 else if (prototype->mType == Enums::RigidBodyType_Volume)
 {
  for (unsigned int i=0;i < prototype->mShapes.size(); i++)
  {
   prototype->mShapes[i]->getBlueprint()->mFlags |= prototype->mVolumeCollisionType;
  }
 }

 // Create the shapes.
 for (unsigned int i=0;i < prototype->mShapes.size(); i++)
 {
  
  NxShapeDesc* description = prototype->mShapes[i]->create();
  
  if (description)
  {
   description->userData = (void*) i;
   actor_description.shapes.push_back(description);
   continue;
  }
  
 }

 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }

 NxShape*const* shapes = mActor->getShapes();
 NxU32 nShapes = mActor->getNbShapes();
  while (nShapes--)
  {
   
   NxShape* physxShape = shapes[nShapes];
   int index = (int) physxShape->userData;
   Shape* shape = prototype->mShapes[index];
   
   if (physxShape->getType() == NX_SHAPE_BOX)
   {
    NxBoxShape* actualShape = physxShape->isBox();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_SPHERE)
   {
    NxSphereShape* actualShape = physxShape->isSphere();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_CAPSULE)
   {
    NxCapsuleShape* actualShape = physxShape->isCapsule();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_PLANE)
   {
    NxPlaneShape* actualShape = physxShape->isPlane();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_CONVEX)
   {
    NxConvexShape* actualShape = physxShape->isConvexMesh();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_MESH)
   {
    NxTriangleMeshShape* actualShape = physxShape->isTriangleMesh();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_HEIGHTFIELD)
   {
    NxHeightFieldShape* actualShape = physxShape->isHeightField();
    shape->assign(actualShape);
   }
   else if (physxShape->getType() == NX_SHAPE_WHEEL)
   {
    NxWheelShape* actualShape = physxShape->isWheel();
    shape->assign(actualShape);
   }

   physxShape->userData = NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
  }
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType()); 
 
}

void RigidBody::create(const Matrix44& pose, SimpleShape* shape, Real mass, Scene* scene)
{
  if (mActor != 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that was already created.");
  return;
 }
 
 if (shape == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no shape.");
  return;
 }
 
 if (scene == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no scene.");
  return;
 }
 
 NxActorDesc actor_description;
 NxBodyDesc  body_description;
 
 actor_description.globalPose.setRowMajor44(pose.ptr());
 Functions::SimpleShapeToActorDescription(actor_description, shape);
 
 if (mass)
 {
  body_description.mass = mass;
  actor_description.body = &body_description;
 }
 
 mActor = scene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  NxOgre_ThrowError("RigidBody actor was not created.");
  return;
 }

 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType()); 
}

void RigidBody::destroy(void)
{
 if (mActor)
 {
  NxShape*const* shapes = mActor->getShapes();
  NxU32 nShapes = mActor->getNbShapes();
  while (nShapes--)
  {
   NxShape* shape = shapes[nShapes];
   PhysXPointer* ptr = pointer_cast(shape->userData);
   NxOgre_Delete(ptr);
  }

  PhysXPointer* ptr = pointer_cast(mActor->userData);
  NxOgre_Delete(ptr);
  NxScene& scene = mActor->getScene();
  scene.releaseActor(*mActor);
 }
}

bool RigidBody::isDynamic(void) const
{
 return ::NxOgre_Namespace::Functions::RigidBodyFunctions::isDynamic(mActor);
}

NxActor* RigidBody::getNxActor(void)
{
 return mActor;
}

Scene* RigidBody::getScene(void)
{
 return mScene;
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

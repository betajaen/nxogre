/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreVolume.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreCallback.h"
#include "NxOgreWorld.h"

#include "NxActor.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Volume::Volume(Scene* scene, Callback* callback)
: RigidBody(scene),
  mVolumeCallback(callback)
{
 if (mVolumeCallback)
  mVolumeCallback->increaseReference();
}

Volume::Volume(const ShapeDescription& shape, const Matrix44& pose, Enums::VolumeCollisionType type, Scene* scene, Callback* callback)
: RigidBody(scene),
  mVolumeCallback(callback)
{
 _createTrigger(pose, type, scene, shape);
 if (mVolumeCallback)
  mVolumeCallback->increaseReference();
}

Volume::Volume(const ShapeDescriptions& shapes, const Matrix44& pose, Enums::VolumeCollisionType type, Scene* scene, Callback* callback)
: RigidBody(scene),
  mVolumeCallback(callback)
{
 _createTrigger(pose, type, scene, shapes);
 if (mVolumeCallback)
  mVolumeCallback->increaseReference();
}

Volume::~Volume()
{
 
 _destroy();
 
 if (mVolumeCallback)
 {
  mVolumeCallback->decreaseReference();
  if (mVolumeCallback->getNbReferences() == 0 && mVolumeCallback->shouldDelete())
  {
   GC::safe_delete<Callback>(mVolumeCallback, NXOGRE_GC_THIS); 
  }
 }
}

bool Volume::isVolumeBased() const
{
 return true;
}

unsigned int Volume::getRigidBodyType() const
{
 return Classes::_Volume;
}

void Volume::setGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setGlobalPose(global_pose);
}

void Volume::setGlobalPosition(const Vec3& vec)
{
 mActor->setGlobalPosition(vec.as<NxVec3>());
}

void Volume::setGlobalOrientation(const Matrix33& mat)
{
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mActor->setGlobalOrientation(matrix);
}

void Volume::setGlobalOrientationQuat(const Quat& quat)
{
 mActor->setGlobalOrientationQuat(quat.as<NxQuat>());
}

Matrix44 Volume::getGlobalPose() const
{
 Matrix44 matrix;
 mActor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 Volume::getGlobalPosition() const
{
 return Vec3(mActor->getGlobalPosition());
}

Matrix33 Volume::getGlobalOrientation() const
{
 Matrix33 matrix;
 mActor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

Quat Volume::getGlobalOrientationQuat() const
{
 return Quat(mActor->getGlobalOrientationQuat());
}

Callback* Volume::getVolumeCallback()
{
 return mVolumeCallback;
}

void Volume::setVolumeCallback(Callback* callback)
{
 mVolumeCallback = callback;
 mVolumeCallback->increaseReference();
}

void Volume::removeVolumeCallback()
{
 if (mVolumeCallback)
  mVolumeCallback->decreaseReference();
 mVolumeCallback = World::getWorld()->getNullCallback();
}

void Volume::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType type, const ShapeDescription& shape)
{
 _createTrigger(pose, type, mScene, shape);
}

void Volume::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType type, const ShapeDescriptions& shapes)
{
 _createTrigger(pose, type, mScene, shapes);
}

                                                                                       

} // namespace NxOgre

                                                                                       

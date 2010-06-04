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

#include "NxOgreWorld.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Volume::Volume(Scene* scene, Callback* callback)
: RigidBody(),
  mScene(scene),
  mVolumeCallback(callback)
{
}

Volume::Volume(const ShapeDescription& shape, const Matrix44& pose, Enums::VolumeCollisionType type, Scene* scene, Callback* callback)
: RigidBody(),
  mScene(scene),
  mVolumeCallback(callback)
{
 createTrigger(pose, type, scene, shape);
}

Volume::Volume(const ShapeDescriptions& shapes, const Matrix44& pose, Enums::VolumeCollisionType type, Scene* scene, Callback* callback)
: RigidBody(),
  mScene(scene),
  mVolumeCallback(callback)
{
 createTrigger(pose, type, scene, shapes);
}

Volume::~Volume()
{
 destroy();
}

unsigned int Volume::getRigidBodyType() const
{
 return Classes::_Volume;
}

void Volume::setGlobalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPose(matrix, mActor);
}

void Volume::setGlobalPosition (const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPosition(r3, mActor);
}

void Volume::setGlobalOrientation(const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientation(r33, mActor);
}

void Volume::setGlobalOrientationQuat(const Quat& r4)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientationQuat(r4, mActor);
}

Matrix44 Volume::getGlobalPose() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 Volume::getGlobalPosition() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 Volume::getGlobalOrientation() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat Volume::getGlobalOrientationQuat() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}

unsigned int Volume::getNbShapes() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

Callback* Volume::getVolumeCallback()
{
 return mVolumeCallback;
}

void Volume::setVolumeCallback(Callback* callback)
{
 mVolumeCallback = callback;
}

void Volume::removeVolumeCallback()
{
 mVolumeCallback = World::getWorld()->getNullCallback();
}

                                                                                       

} // namespace NxOgre

                                                                                       

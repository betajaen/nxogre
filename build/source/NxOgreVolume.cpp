/** File: NxOgreVolume.cpp
    Created on: 30-Jan-09
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
#include "NxOgreVolume.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyPrototype.h"

#include "NxOgreWorld.h"

                                                                                       

namespace NxOgre
{

                                                                                       


Volume::Volume(Scene* scene, Callback* callback)
: RigidBody(),
  mScene(scene),
  mVolumeCallback(callback)
{
}

Volume::Volume(RigidBodyPrototype* prototype, Scene* scene, Callback* callback)
: RigidBody(),
  mScene(scene),
  mVolumeCallback(callback)
{
 create(prototype, scene, &mShapes);
}

Volume::~Volume(void)
{
 destroy();
 mShapes.destroyAll();
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

Matrix44 Volume::getGlobalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 Volume::getGlobalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 Volume::getGlobalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat Volume::getGlobalOrientationQuat(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}

unsigned int Volume::getNbShapes(void) const
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

                                                                                       

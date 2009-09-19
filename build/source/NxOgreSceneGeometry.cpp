/** File: NxOgreSceneGeometry.cpp
    Created on: 13-Nov-08
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
#include "NxOgreSceneGeometry.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyPrototype.h"

                                                                                       

namespace NxOgre
{

                                                                                       


SceneGeometry::SceneGeometry(Scene* scene)
: RigidBody(),
  mScene(scene)
{
}

SceneGeometry::SceneGeometry(RigidBodyPrototype* prototype, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 create(prototype, scene, &mShapes);
}

SceneGeometry::~SceneGeometry(void)
{
 destroy();
 mShapes.destroyAll();
}

unsigned int SceneGeometry::getClassType() const
{
 return Classes::_SceneGeometry;
}

void SceneGeometry::setGroup(GroupIdentifier SceneGeometryGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(SceneGeometryGroup, mActor);
}

GroupIdentifier SceneGeometry::getGroup(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGroup(mActor);
}

unsigned int SceneGeometry::getContactReportFlags(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportFlags(mActor);
}

void SceneGeometry::setContactReportFlags(unsigned int flags)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportFlags(flags, mActor);
}

Matrix44 SceneGeometry::getGlobalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 SceneGeometry::getGlobalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 SceneGeometry::getGlobalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat SceneGeometry::getGlobalOrientationQuat(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}


void SceneGeometry::createShape(Shape*)
{
 //< \argh
}

void SceneGeometry::releaseShape(Shape*)
{
 //< \argh
}

unsigned int SceneGeometry::getNbShapes(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

                                                                                       

} // namespace NxOgre

                                                                                       

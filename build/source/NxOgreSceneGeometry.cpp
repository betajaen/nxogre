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
#include "NxOgreSceneGeometry.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       


SceneGeometry::SceneGeometry(Scene* scene)
: RigidBody(),
  mScene(scene)
{
}

SceneGeometry::SceneGeometry(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 createStatic(pose, description, scene, shape);
}

SceneGeometry::SceneGeometry(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 createStatic(pose, description, scene, shapes);
}

SceneGeometry::~SceneGeometry()
{
 destroy();
}

unsigned int SceneGeometry::getRigidBodyType() const
{
 return Classes::_SceneGeometry;
}

void SceneGeometry::setGroup(GroupIdentifier SceneGeometryGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(SceneGeometryGroup, mActor);
}

GroupIdentifier SceneGeometry::getGroup() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGroup(mActor);
}

unsigned int SceneGeometry::getContactReportFlags() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportFlags(mActor);
}

void SceneGeometry::setContactReportFlags(unsigned int flags)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportFlags(flags, mActor);
}

Matrix44 SceneGeometry::getGlobalPose() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 SceneGeometry::getGlobalPosition() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 SceneGeometry::getGlobalOrientation() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat SceneGeometry::getGlobalOrientationQuat() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}


void SceneGeometry::createShape(const ShapeDescription&)
{
 //< \argh
}

void SceneGeometry::releaseShape(Shape*)
{
 //< \argh
}

unsigned int SceneGeometry::getNbShapes() const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

                                                                                       

} // namespace NxOgre

                                                                                       

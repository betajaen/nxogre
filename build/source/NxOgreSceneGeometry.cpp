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

#include "NxActor.h"

                                                                                       

namespace NxOgre
{

                                                                                       


SceneGeometry::SceneGeometry(Scene* scene)
: RigidBody(scene)
{
}

SceneGeometry::SceneGeometry(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(scene)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 
 _createStatic(pose, description, scene, shape);
}

SceneGeometry::SceneGeometry(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(scene)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 
 _createStatic(pose, description, scene, shapes);
}

SceneGeometry::~SceneGeometry()
{
 _destroy();
}

bool SceneGeometry::isSceneGeometryBased() const
{
 return true;
}

unsigned int SceneGeometry::getRigidBodyType() const
{
 return Classes::_SceneGeometry;
}

void SceneGeometry::setGroup(GroupIdentifier SceneGeometryGroup)
{
 mActor->setGroup(SceneGeometryGroup);
}

GroupIdentifier SceneGeometry::getGroup() const
{
 return mActor->getGroup();
}

unsigned int SceneGeometry::getContactReportFlags() const
{
 return mActor->getContactReportFlags();
}

void SceneGeometry::setContactReportFlags(unsigned int flags)
{
 mActor->setContactReportFlags(flags);
}

Matrix44 SceneGeometry::getGlobalPose() const
{
 Matrix44 matrix;
 mActor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 SceneGeometry::getGlobalPosition() const
{
 return Vec3(mActor->getGlobalPosition());
}

Matrix33 SceneGeometry::getGlobalOrientation() const
{
 Matrix33 matrix;
 mActor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

Quat SceneGeometry::getGlobalOrientationQuat() const
{
 return Quat(mActor->getGlobalOrientationQuat());
}

unsigned int SceneGeometry::getNbShapes() const
{
 return mActor->getNbShapes();
}

void SceneGeometry::createStatic(const Matrix44& matrix_pose, const RigidBodyDescription& description, const ShapeDescription& shape)
{
 _createStatic(matrix_pose, description, mScene, shape);
}

void SceneGeometry::createStatic(const Matrix44& matrix_pose, const RigidBodyDescription& description, const ShapeDescriptions& shapes)
{
 _createStatic(matrix_pose, description, mScene, shapes);
}

                                                                                       

} // namespace NxOgre

                                                                                       

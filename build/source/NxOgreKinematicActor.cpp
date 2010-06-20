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
#include "NxOgreKinematicActor.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"

#include "NxActor.h"

                                                                                       

namespace NxOgre
{

                                                                                       


KinematicActor::KinematicActor(Scene* scene)
: RigidBody(scene)
{
}

KinematicActor::KinematicActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(scene)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 
 _createKinematic(pose, description, scene, shape);
}

KinematicActor::KinematicActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(scene)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 
 _createKinematic(pose, description, scene, shapes);
}

KinematicActor::~KinematicActor()
{
 _destroy();
}

void KinematicActor::createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription& description, const ShapeDescription& shape)
{
 _createKinematic(matrix_pose, description, mScene, shape);
}

void KinematicActor::createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription& description, const ShapeDescriptions& shapes)
{
 _createKinematic(matrix_pose, description, mScene, shapes);
}

bool KinematicActor::isKinematicActorBased() const
{
 return true;
}

unsigned int KinematicActor::getRigidBodyType() const
{
 return Classes::_KinematicActor;
}

void KinematicActor::raiseDynamicFlag(DynamicRigidbodyFlags::Flags flag)
{
 mActor->raiseBodyFlag((NxBodyFlag) (int) flag);
}

void KinematicActor::clearDynamicFlag(DynamicRigidbodyFlags::Flags flag)
{
 mActor->clearBodyFlag((NxBodyFlag) (int) flag);
}

bool KinematicActor::hasDynamicFlag(DynamicRigidbodyFlags::Flags flag) const
{
 return mActor->readBodyFlag((NxBodyFlag) (int) flag);
}

void KinematicActor::setGroup(GroupIdentifier actorGroup)
{
 mActor->setGroup(actorGroup);
}

GroupIdentifier KinematicActor::getGroup() const
{
 return mActor->getGroup();
}

void KinematicActor::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 mActor->setGroup(dominanceGroup);
}

GroupIdentifier KinematicActor::getDominanceGroup() const
{
 return mActor->getDominanceGroup();
}

void KinematicActor::resetPairFiltering()
{
 mActor->resetUserActorPairFiltering();
}

bool KinematicActor::isDynamic() const
{
 return mActor->isDynamic();
}

Real KinematicActor::computeKineticEnergy() const
{
 return mActor->computeKineticEnergy();
}

void KinematicActor::setSolverIterationCount(unsigned int iterCount)
{
 mActor->setSolverIterationCount(iterCount);
}

unsigned int KinematicActor::getSolverIterationCount() const
{
 return mActor->getSolverIterationCount();
}

Real KinematicActor::getContactReportThreshold() const
{
 return mActor->getContactReportThreshold();
}

void KinematicActor::setContactReportThreshold(Real threshold)
{
 mActor->setContactReportThreshold(threshold);
}

unsigned int KinematicActor::getContactReportFlags() const
{
 return mActor->getContactReportFlags();
}

void KinematicActor::setContactReportFlags(unsigned int flags)
{
 mActor->setContactReportFlags(flags);
}

unsigned short KinematicActor::getForceFieldMaterial() const
{
 return mActor->getForceFieldMaterial();
}

void KinematicActor::setForceFieldMaterial(unsigned short ffm)
{
 mActor->setForceFieldMaterial(ffm);
}

void KinematicActor::setGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setGlobalPose(global_pose);
}

void KinematicActor::setGlobalPosition(const Vec3& vec)
{
 mActor->setGlobalPosition(vec.as<NxVec3>());
}

void KinematicActor::setGlobalOrientation(const Matrix33& mat)
{
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mActor->setGlobalOrientation(matrix);
}

void KinematicActor::setGlobalOrientationQuat(const Quat& quat)
{
 mActor->setGlobalOrientationQuat(quat.as<NxQuat>());
}

Matrix44 KinematicActor::getGlobalPose() const
{
 Matrix44 matrix;
 mActor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 KinematicActor::getGlobalPosition() const
{
 return Vec3(mActor->getGlobalPosition());
}

Matrix33 KinematicActor::getGlobalOrientation() const
{
 Matrix33 matrix;
 mActor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

Quat KinematicActor::getGlobalOrientationQuat() const
{
 return Quat(mActor->getGlobalOrientationQuat());
}

void KinematicActor::moveGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->moveGlobalPose(global_pose);
}

void KinematicActor::moveGlobalPosition(const Vec3& vec)
{
 mActor->moveGlobalPosition(vec.as<NxVec3>());
}

void KinematicActor::moveGlobalOrientation (const Matrix33& mat)
{
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mActor->moveGlobalOrientation(matrix);
}

void KinematicActor::moveGlobalOrientationQuat (const Quat& quat)
{
 mActor->moveGlobalOrientationQuat(quat.as<NxQuat>());
}

String KinematicActor::to_s() const
{
 return NxOgre::to_s((void*)this, (mName.length() ? String("'" + mName + "'") : String("KinematicActor") ));
}

                                                                                       

} // namespace NxOgre

                                                                                       

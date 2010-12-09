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
#include "NxOgreRigidBodyFunctions.h"

#include "NxPhysics.h"

namespace NxOgre
{
namespace Functions
{

void NxActorFunctions::raiseBodyFlag(int flag, NxActor* actor)
{
 actor->raiseBodyFlag((NxBodyFlag) flag);
}

void NxActorFunctions::clearBodyFlag(int flag, NxActor* actor)
{
 actor->clearBodyFlag((NxBodyFlag) flag);
}

bool NxActorFunctions::hasBodyFlag(int flag, NxActor* actor)
{
 return actor->readBodyFlag((NxBodyFlag) flag);
}

void NxActorFunctions::setGroup(GroupIdentifier actorGroup, NxActor* actor)
{
 actor->setGroup(actorGroup);
}

GroupIdentifier NxActorFunctions::getGroup(NxActor* actor)
{
 return actor->getGroup();
}

void NxActorFunctions::setDominanceGroup(GroupIdentifier dominanceGroup, NxActor* actor)
{
 actor->setDominanceGroup(dominanceGroup);
}

GroupIdentifier NxActorFunctions::getDominanceGroup(NxActor* actor)
{
 return actor->getDominanceGroup();
}

void NxActorFunctions::resetPairFiltering(NxActor* actor)
{
 actor->resetUserActorPairFiltering();
}

bool NxActorFunctions::isDynamic(NxActor* actor)
{
 return actor->isDynamic();
}

Real NxActorFunctions::computeKineticEnergy(NxActor* actor)
{
 return actor->computeKineticEnergy();
}

void NxActorFunctions::setSolverIterationCount(unsigned int iterCount, NxActor* actor)
{
 actor->setSolverIterationCount(iterCount);
}

unsigned int NxActorFunctions::getSolverIterationCount(NxActor* actor)
{
 return actor->getSolverIterationCount();
}

Real NxActorFunctions::getContactReportThreshold(NxActor* actor)
{
 return actor->getContactReportThreshold();
}

void NxActorFunctions::setContactReportThreshold(Real threshold, NxActor* actor)
{
 actor->setContactReportThreshold(threshold);
}

unsigned int NxActorFunctions::getContactReportFlags(NxActor* actor)
{
 return actor->getContactReportFlags();
}

void NxActorFunctions::setContactReportFlags(unsigned int flags, NxActor* actor)
{
 actor->setContactReportFlags(flags);
}

unsigned short NxActorFunctions::getForceFieldMaterial(NxActor* actor)
{
 return actor->getForceFieldMaterial();
}

void NxActorFunctions::setForceFieldMaterial(unsigned short ffm, NxActor* actor)
{
 actor->setForceFieldMaterial(ffm);
}

void NxActorFunctions::setGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setGlobalPose(global_pose);
}

void NxActorFunctions::setGlobalPosition (const Vec3& r3, NxActor* actor)
{
 static NxVec3 global_position;
 global_position.x = r3.x;
 global_position.y = r3.y;
 global_position.z = r3.z;
 actor->setGlobalPosition(global_position);
}

void NxActorFunctions::setGlobalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setGlobalOrientation(global_orientation);
}

void NxActorFunctions::setGlobalOrientationQuat(const Quat& r4, NxActor* actor)
{
 static NxQuat global_orientation_as_nx_quat;
 global_orientation_as_nx_quat.w = r4.w;
 global_orientation_as_nx_quat.x = r4.x;
 global_orientation_as_nx_quat.y = r4.y;
 global_orientation_as_nx_quat.z = r4.z;
 actor->setGlobalOrientationQuat(global_orientation_as_nx_quat);
}

Matrix44 NxActorFunctions::getGlobalPose(NxActor* actor)
{
 Matrix44 matrix;
 actor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 NxActorFunctions::getGlobalPosition(NxActor* actor)
{
 return Vec3(actor->getGlobalPosition());
}

Matrix33 NxActorFunctions::getGlobalOrientation(NxActor* actor)
{
 Matrix33 matrix;
 actor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

Quat NxActorFunctions::getGlobalOrientationQuat(NxActor* actor)
{
 return Quat(actor->getGlobalOrientationQuat());
}

void NxActorFunctions::moveGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->moveGlobalPose(global_pose);
}

void NxActorFunctions::moveGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->moveGlobalPosition(r3.as<NxVec3>());
}

void NxActorFunctions::moveGlobalOrientation (const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->moveGlobalOrientation(global_orientation);
}

void NxActorFunctions::moveGlobalOrientationQuat (const Quat& quat, NxActor* actor)
{
 actor->moveGlobalOrientationQuat(quat.as<NxQuat>());
}

unsigned int NxActorFunctions::getNbShapes(NxActor* actor)
{
 return actor->getNbShapes();
}

void NxActorFunctions::setCMassOffsetLocalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassOffsetLocalPose(global_pose);
}

void NxActorFunctions::setCMassOffsetLocalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassOffsetLocalPosition(r3.as<NxVec3>());
}

void NxActorFunctions::setCMassOffsetLocalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassOffsetLocalOrientation(global_orientation);
}

void NxActorFunctions::setCMassOffsetGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassOffsetGlobalPose(global_pose);
}

void NxActorFunctions::setCMassOffsetGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassOffsetGlobalPosition(r3.as<NxVec3>());
}

void NxActorFunctions::setCMassOffsetGlobalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassOffsetGlobalOrientation(global_orientation);
}

void NxActorFunctions::setCMassGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassGlobalPose(global_pose);
}

void NxActorFunctions::setCMassGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassGlobalPosition(r3.as<NxVec3>());
}

void NxActorFunctions::setCMassGlobalOrientation (const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassGlobalOrientation(global_orientation);
}

Matrix44 NxActorFunctions::getCMassLocalPose(NxActor* actor)
{
 static Matrix44 global_pose;
 actor->getCMassLocalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

Vec3 NxActorFunctions::getCMassLocalPosition(NxActor* actor)
{
 return Vec3(actor->getCMassLocalPosition());
}

Matrix33 NxActorFunctions::getCMassLocalOrientation(NxActor* actor)
{
 static Matrix33 global_orientation;
 actor->getCMassLocalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

Matrix44 NxActorFunctions::getCMassGlobalPose(NxActor* actor)
{
 static Matrix44 global_pose;
 actor->getCMassGlobalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

Vec3 NxActorFunctions::getCMassGlobalPosition(NxActor* actor)
{
 return Vec3(actor->getCMassGlobalPosition());
}

Matrix33 NxActorFunctions::getCMassGlobalOrientation(NxActor* actor)
{
 static Matrix33 global_orientation;
 actor->getCMassGlobalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

void NxActorFunctions::setMass(Real mass, NxActor* actor)
{
 actor->setMass(mass);
}

Real NxActorFunctions::getMass(NxActor* actor)
{
 return actor->getMass();
}

void NxActorFunctions::setMassSpaceInertiaTensor(const Vec3& r3, NxActor* actor)
{
 actor->setMassSpaceInertiaTensor(r3.as<NxVec3>());
}

Vec3 NxActorFunctions::getMassSpaceInertiaTensor(NxActor* actor)
{
 return Vec3(actor->getMassSpaceInertiaTensor());
}

Matrix33 NxActorFunctions::getGlobalInertiaTensor(NxActor* actor)
{
 static Matrix33 _real33;
 actor->getGlobalInertiaTensor().getRowMajor(_real33.ptr());
 return _real33;
}

Matrix33 NxActorFunctions::getGlobalInertiaTensorInverse(NxActor* actor)
{
 static Matrix33 _real33;
 actor->getGlobalInertiaTensorInverse().getRowMajor(_real33.ptr());
 return _real33;
}

bool NxActorFunctions::updateMassFromShapes(Real density, Real totalMass, NxActor* actor)
{
 return actor->updateMassFromShapes(density, totalMass);
}

void NxActorFunctions::setLinearDamping(Real linDamp, NxActor* actor)
{
 actor->setLinearDamping(linDamp);
}

Real NxActorFunctions::getLinearDamping(NxActor* actor)
{
 return actor->getLinearDamping();
}

void NxActorFunctions::setAngularDamping(Real angDamp, NxActor* actor)
{
 actor->setAngularDamping(angDamp);
}

Real NxActorFunctions::getAngularDamping(NxActor* actor)
{
 return actor->getAngularDamping();
}

void NxActorFunctions::setLinearVelocity(const Vec3& linVel, NxActor* actor)
{
 actor->setLinearVelocity(linVel.as<NxVec3>());
}

void NxActorFunctions::setAngularVelocity(const Vec3& angVel, NxActor* actor)
{
 actor->setAngularVelocity(angVel.as<NxVec3>());
}

Vec3 NxActorFunctions::getLinearVelocity(NxActor* actor)
{
 return Vec3(actor->getLinearVelocity());
}

Vec3 NxActorFunctions::getAngularVelocity (NxActor* actor)
{
 return Vec3(actor->getAngularVelocity());
}

void NxActorFunctions::setMaxAngularVelocity(Real maxAngVel, NxActor* actor)
{
 actor->setMaxAngularVelocity(maxAngVel);
}

Real NxActorFunctions::getMaxAngularVelocity(NxActor* actor)
{
 return actor->getMaxAngularVelocity();
}

void NxActorFunctions::setCCDMotionThreshold(Real thresh, NxActor* actor)
{
 actor->setCCDMotionThreshold(thresh);
}

Real NxActorFunctions::getCCDMotionThreshold(NxActor* actor)
{
 return actor->getCCDMotionThreshold();
}

void NxActorFunctions::setLinearMomentum(const Vec3& linMoment, NxActor* actor)
{
 actor->setLinearMomentum(linMoment.as<NxVec3>());
}

void NxActorFunctions::setAngularMomentum(const Vec3& angMoment, NxActor* actor)
{
 actor->setAngularMomentum(angMoment.as<NxVec3>());
}

Vec3 NxActorFunctions::getLinearMomentum(NxActor* actor)
{
 return Vec3(actor->getLinearMomentum());
}

Vec3 NxActorFunctions::getAngularMomentum(NxActor* actor)
{
 return Vec3(actor->getAngularMomentum());
}

void NxActorFunctions::addForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForceAtPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForceAtLocalPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addLocalForceAtPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForceAtPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForceAtLocalPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForce(force.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addLocalForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForce(force.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addTorque(torque.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void NxActorFunctions::addLocalTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalTorque(torque.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

Vec3 NxActorFunctions::getPointVelocity (const Vec3& point, NxActor* actor)
{
 return Vec3(actor->getPointVelocity(point.as<NxVec3>()));
}

Vec3 NxActorFunctions::getLocalPointVelocity(const Vec3& point, NxActor* actor)
{
 return Vec3(actor->getLocalPointVelocity(point.as<NxVec3>()));
}

bool NxActorFunctions::isGroupSleeping(NxActor* actor)
{
 return actor->isGroupSleeping();
}

bool NxActorFunctions::isSleeping(NxActor* actor)
{
 return actor->isSleeping();
}

Real NxActorFunctions::getSleepLinearVelocity(NxActor* actor)
{
 return actor->getSleepLinearVelocity();
}

void NxActorFunctions::setSleepLinearVelocity(Real threshold, NxActor* actor)
{
 actor->setSleepLinearVelocity(threshold);
}

Real NxActorFunctions::getSleepAngularVelocity(NxActor* actor)
{
 return actor->getSleepAngularVelocity();
}

void NxActorFunctions::setSleepAngularVelocity(Real threshold, NxActor* actor)
{
 actor->setSleepAngularVelocity(threshold);
}

Real NxActorFunctions::getSleepEnergyThreshold(NxActor* actor)
{
 return actor->getSleepEnergyThreshold();
}

void NxActorFunctions::setSleepEnergyThreshold(Real threshold, NxActor* actor)
{
 actor->setSleepEnergyThreshold(threshold);
}

void NxActorFunctions::wakeUp(Real wakeCounterValue, NxActor* actor)
{
 actor->wakeUp(wakeCounterValue);
}

void NxActorFunctions::putToSleep(NxActor* actor)
{
 actor->putToSleep();
} 

} // namespace Functions
} // namespace NxOgre
/** File: NxOgreRigidBodyDynamicFunctions.cpp
    Created on: 29-Apr-09
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
#include "NxOgreRigidBodyDynamicFunctions.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       


void RigidBodyDynamicFunctions::setGroup(GroupIdentifier actorGroup)
{
 mActor->setGroup(actorGroup);
}

GroupIdentifier RigidBodyDynamicFunctions::getGroup(void) const
{
 return mActor->getGroup();
}

void RigidBodyDynamicFunctions::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 mActor->setGroup(dominanceGroup);
}

GroupIdentifier RigidBodyDynamicFunctions::getDominanceGroup(void) const
{
 return mActor->getDominanceGroup();
}

void RigidBodyDynamicFunctions::resetPairFiltering(void)
{
 mActor->resetPairFiltering();
}

Real RigidBodyDynamicFunctions::computeKineticEnergy(void) const
{
 return mActor->computeKineticEnergy();
}

void RigidBodyDynamicFunctions::setSolverIterationCount(unsigned int iterCount)
{
 mActor->setSolverIterationCount(iterCount);
}

unsigned int RigidBodyDynamicFunctions::getSolverIterationCount(void) const
{
 return mActor->getSolverIterationCount();
}

Real RigidBodyDynamicFunctions::getContactReportThreshold(void) const
{
 return mActor->getContactReportThreshold();
}

void RigidBodyDynamicFunctions::setContactReportThreshold(Real threshold)
{
 mActor->setContactReportThreshold(threshold);
}

unsigned int RigidBodyDynamicFunctions::getContactReportFlags(void) const
{
 return mActor->getContactReportFlags();
}

void RigidBodyDynamicFunctions::setContactReportFlags(unsigned int flags)
{
 mActor->setContactReportFlags(flags);
}

unsigned short RigidBodyDynamicFunctions::getForceFieldMaterial(void) const
{
 return mActor->getForceFieldMaterial();
}

void RigidBodyDynamicFunctions::setForceFieldMaterial(unsigned short ffm)
{
 mActor->setForceFieldMaterial(ffm);
}

void RigidBodyDynamicFunctions::setGlobalPose(const Matrix44& matrix)
{
 mActor->setGlobalPose(matrix);
}

void RigidBodyDynamicFunctions::setGlobalPosition (const Real3& r3)
{
 mActor->setGlobalPosition(r3);
}

void RigidBodyDynamicFunctions::setGlobalOrientation(const Matrix33& r33)
{
 mActor->setGlobalOrientation(r33);
}

void RigidBodyDynamicFunctions::setGlobalOrientationQuat(const Real4& r4)
{
 mActor->setGlobalOrientationQuat(r4);
}

Matrix44 RigidBodyDynamicFunctions::getGlobalPose(void) const
{
 return mActor->getGlobalPose();
}

Real3 RigidBodyDynamicFunctions::getGlobalPosition(void) const
{
 return mActor->getGlobalPosition();
}

Matrix33 RigidBodyDynamicFunctions::getGlobalOrientation(void) const
{
 return mActor->getGlobalOrientation();
}

Real4 RigidBodyDynamicFunctions::getGlobalOrientationQuat(void) const
{
 return mActor->getGlobalOrientationQuat();
}

unsigned int RigidBodyDynamicFunctions::getNbShapes(void) const
{
 return mActor->getNbShapes();
}

void RigidBodyDynamicFunctions::setCMassOffsetLocalPose(const Matrix44& matrix)
{
 mActor->setCMassOffsetLocalPose(matrix);
}

void RigidBodyDynamicFunctions::setCMassOffsetLocalPosition(const Real3& r3)
{
 mActor->setCMassOffsetLocalPosition(r3);
}

void RigidBodyDynamicFunctions::setCMassOffsetLocalOrientation(const Matrix33& r33)
{
 mActor->setCMassOffsetLocalOrientation(r33);
}

void RigidBodyDynamicFunctions::setCMassOffsetGlobalPose(const Matrix44& matrix)
{
 mActor->setCMassOffsetGlobalPose(matrix);
}

void RigidBodyDynamicFunctions::setCMassOffsetGlobalPosition(const Real3& r3)
{
 mActor->setCMassOffsetGlobalPosition(r3);
}

void RigidBodyDynamicFunctions::setCMassOffsetGlobalOrientation(const Matrix33& r33)
{
 mActor->setCMassOffsetGlobalOrientation(r33);
}

void RigidBodyDynamicFunctions::setCMassGlobalPose(const Matrix44& matrix)
{
 mActor->setCMassGlobalPose(matrix);
}

void RigidBodyDynamicFunctions::setCMassGlobalPosition(const Real3& r3)
{
 mActor->setCMassGlobalPosition(r3);
}

void RigidBodyDynamicFunctions::setCMassGlobalOrientation (const Matrix33& r33)
{
 mActor->setCMassGlobalOrientation(r33);
}

Matrix44 RigidBodyDynamicFunctions::getCMassLocalPose(void) const
{
 return mActor->getCMassLocalPose();
}

Real3 RigidBodyDynamicFunctions::getCMassLocalPosition(void) const
{
 return mActor->getCMassLocalPosition();
}

Matrix33 RigidBodyDynamicFunctions::getCMassLocalOrientation(void) const
{
 return mActor->getCMassLocalOrientation();
}

Matrix44 RigidBodyDynamicFunctions::getCMassGlobalPose(void) const
{
 return mActor->getCMassGlobalPose();
}

Real3 RigidBodyDynamicFunctions::getCMassGlobalPosition(void) const
{
 return mActor->getCMassGlobalPosition();
}

Matrix33 RigidBodyDynamicFunctions::getCMassGlobalOrientation(void) const
{
 return mActor->getCMassGlobalOrientation();
}

void RigidBodyDynamicFunctions::setMass(Real mass)
{
 mActor->setMass(mass);
}

Real RigidBodyDynamicFunctions::getMass(void) const
{
 return mActor->getMass();
}

void RigidBodyDynamicFunctions::setMassSpaceInertiaTensor(const Real3& r3)
{
 mActor->setMassSpaceInertiaTensor(r3);
}

Real3 RigidBodyDynamicFunctions::getMassSpaceInertiaTensor(void) const
{
 return mActor->getMassSpaceInertiaTensor();
}

Matrix33 RigidBodyDynamicFunctions::getGlobalInertiaTensor(void) const
{
 return mActor->getGlobalInertiaTensor();
}

Matrix33 RigidBodyDynamicFunctions::getGlobalInertiaTensorInverse(void) const
{
 return mActor->getGlobalInertiaTensorInverse();
}

bool RigidBodyDynamicFunctions::updateMassFromShapes(Real density, Real totalMass) const
{
 return mActor->updateMassFromShapes(density, totalMass);
}

void RigidBodyDynamicFunctions::setLinearDamping(Real linDamp)
{
 mActor->setLinearDamping(linDamp);
}

Real RigidBodyDynamicFunctions::getLinearDamping(void) const
{
 return mActor->getLinearDamping();
}

void RigidBodyDynamicFunctions::setAngularDamping(Real angDamp)
{
 mActor->setAngularDamping(angDamp);
}

Real RigidBodyDynamicFunctions::getAngularDamping(void) const
{
 return mActor->getAngularDamping();
}

void RigidBodyDynamicFunctions::setLinearVelocity(const Real3& linVel)
{
 mActor->setLinearVelocity(linVel);
}

void RigidBodyDynamicFunctions::setAngularVelocity(const Real3& angVel)
{
 mActor->setAngularVelocity(angVel);
}

Real3 RigidBodyDynamicFunctions::getLinearVelocity(void) const
{
 return mActor->getLinearVelocity();
}

Real3 RigidBodyDynamicFunctions::getAngularVelocity (void) const
{
 return mActor->getAngularVelocity();
}

void RigidBodyDynamicFunctions::setMaxAngularVelocity(Real maxAngVel)
{
 mActor->setMaxAngularVelocity(maxAngVel);
}

Real RigidBodyDynamicFunctions::getMaxAngularVelocity(void) const
{
 return mActor->getMaxAngularVelocity();
}

void RigidBodyDynamicFunctions::setCCDMotionThreshold(Real thresh)
{
 mActor->setCCDMotionThreshold(thresh);
}

Real RigidBodyDynamicFunctions::getCCDMotionThreshold(void) const
{
 return mActor->getCCDMotionThreshold();
}

void RigidBodyDynamicFunctions::setLinearMomentum(const Real3& linMoment)
{
 mActor->setLinearMomentum(linMoment);
}

void RigidBodyDynamicFunctions::setAngularMomentum(const Real3& angMoment)
{
 mActor->setAngularMomentum(angMoment);
}

Real3 RigidBodyDynamicFunctions::getLinearMomentum(void) const
{
 return mActor->getLinearMomentum();
}

Real3 RigidBodyDynamicFunctions::getAngularMomentum(void) const
{
 return mActor->getAngularMomentum();
}

void RigidBodyDynamicFunctions::addForceAtPos(const Real3& force, const Real3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForceAtPos(force, pos, mode, wakeup);
}

void RigidBodyDynamicFunctions::addForceAtLocalPos(const Real3& force, const Real3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForceAtLocalPos(force, pos, mode, wakeup);
}

void RigidBodyDynamicFunctions::addLocalForceAtPos(const Real3& force, const Real3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForceAtPos(force, pos, mode, wakeup);
}

void RigidBodyDynamicFunctions::addLocalForceAtLocalPos (const Real3& force, const Real3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForceAtLocalPos(force, pos, mode, wakeup);
}

void RigidBodyDynamicFunctions::addForce(const Real3& force, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForce(force, mode, wakeup);
}

void RigidBodyDynamicFunctions::addLocalForce(const Real3& force, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForce(force, mode, wakeup);
}

void RigidBodyDynamicFunctions::addTorque (const Real3& torque, Enums::ForceMode mode, bool wakeup)
{
 mActor->addTorque(torque, mode, wakeup);
}

void RigidBodyDynamicFunctions::addLocalTorque(const Real3& torque, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalTorque(torque, mode, wakeup);
}

Real3 RigidBodyDynamicFunctions::getPointVelocity (const Real3& point) const
{
 return mActor->getPointVelocity(point);
}

Real3 RigidBodyDynamicFunctions::getLocalPointVelocity(const Real3& point) const
{
 return mActor->getLocalPointVelocity(point);
}

bool RigidBodyDynamicFunctions::isGroupSleeping(void) const
{
 return mActor->isGroupSleeping();
}

bool RigidBodyDynamicFunctions::isSleeping(void) const
{
 return mActor->isSleeping();
}

Real RigidBodyDynamicFunctions::getSleepLinearVelocity(void) const
{
 return mActor->getSleepLinearVelocity();
}

void RigidBodyDynamicFunctions::setSleepLinearVelocity(Real threshold)
{
}

Real RigidBodyDynamicFunctions::getSleepAngularVelocity(void) const
{
 return mActor->getSleepAngularVelocity();
}

void RigidBodyDynamicFunctions::setSleepAngularVelocity(Real threshold)
{
}

Real RigidBodyDynamicFunctions::getSleepEnergyThreshold(void) const
{
 return mActor->getSleepEnergyThreshold();
}

///void RigidBodyDynamicFunctions::setSleepEnergyThreshold(Real threshold)
///{
///}

///void RigidBodyDynamicFunctions::wakeUp(Real wakeCounterValue)
///{
///}

///void RigidBodyDynamicFunctions::putToSleep(void)
///{
///}

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

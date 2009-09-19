/** File: NxOgreActor.cpp
    Created on: 8-Nov-08
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
#include "NxOgreActor.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBodyPrototype.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Actor::Actor(Scene* scene) : RigidBody(), mScene(scene)
{
}

Actor::Actor(RigidBodyPrototype* prototype, Scene* scene)
: RigidBody(),
  mScene(scene)
{
 create(prototype, scene, &mShapes);
}

Actor::~Actor(void)
{
 destroy();
}

unsigned int Actor::getClassType() const 
{
 return ::NxOgre::Classes::_Actor;
}

void Actor::setGroup(GroupIdentifier actorGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(actorGroup, mActor);
}

GroupIdentifier Actor::getGroup(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGroup(mActor);
}

void Actor::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGroup(dominanceGroup, mActor);
}

GroupIdentifier Actor::getDominanceGroup(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getDominanceGroup(mActor);
}

void Actor::resetPairFiltering(void)
{
 ::NxOgre::Functions::RigidBodyFunctions::resetPairFiltering(mActor);
}

Real Actor::computeKineticEnergy(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::computeKineticEnergy(mActor);
}

void Actor::setSolverIterationCount(unsigned int iterCount)
{
 ::NxOgre::Functions::RigidBodyFunctions::setSolverIterationCount(iterCount, mActor);
}

unsigned int Actor::getSolverIterationCount(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getSolverIterationCount(mActor);
}

Real Actor::getContactReportThreshold(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportThreshold(mActor);
}

void Actor::setContactReportThreshold(Real threshold)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportThreshold(threshold, mActor);
}

unsigned int Actor::getContactReportFlags(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getContactReportFlags(mActor);
}

void Actor::setContactReportFlags(unsigned int flags)
{
 ::NxOgre::Functions::RigidBodyFunctions::setContactReportFlags(flags, mActor);
}

unsigned short Actor::getForceFieldMaterial(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getForceFieldMaterial(mActor);
}

void Actor::setForceFieldMaterial(unsigned short ffm)
{
 ::NxOgre::Functions::RigidBodyFunctions::setForceFieldMaterial(ffm, mActor);
}

void Actor::setGlobalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPose(matrix, mActor);
}

void Actor::setGlobalPosition (const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalPosition(r3, mActor);
}

void Actor::setGlobalOrientation(const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientation(r33, mActor);
}

void Actor::setGlobalOrientationQuat(const Quat& quat)
{
 ::NxOgre::Functions::RigidBodyFunctions::setGlobalOrientationQuat(quat, mActor);
}

Matrix44 Actor::getGlobalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPose(mActor);
}

Vec3 Actor::getGlobalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalPosition(mActor);
}

Matrix33 Actor::getGlobalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientation(mActor);
}

Quat Actor::getGlobalOrientationQuat(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalOrientationQuat(mActor);
}

unsigned int Actor::getNbShapes(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getNbShapes(mActor);
}

void Actor::setCMassOffsetLocalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetLocalPose(matrix, mActor);
}

void Actor::setCMassOffsetLocalPosition(const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetLocalPosition(r3, mActor);
}

void Actor::setCMassOffsetLocalOrientation(const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetLocalOrientation(r33, mActor);
}

void Actor::setCMassOffsetGlobalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetGlobalPose(matrix, mActor);
}

void Actor::setCMassOffsetGlobalPosition(const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetGlobalPosition(r3, mActor);
}

void Actor::setCMassOffsetGlobalOrientation(const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassOffsetGlobalOrientation(r33, mActor);
}

void Actor::setCMassGlobalPose(const Matrix44& matrix)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassGlobalPose(matrix, mActor);
}

void Actor::setCMassGlobalPosition(const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassGlobalPosition(r3, mActor);
}

void Actor::setCMassGlobalOrientation (const Matrix33& r33)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCMassGlobalOrientation(r33, mActor);
}

Matrix44 Actor::getCMassLocalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassLocalPose(mActor);
}

Vec3 Actor::getCMassLocalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassLocalPosition(mActor);
}

Matrix33 Actor::getCMassLocalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassLocalOrientation(mActor);
}

Matrix44 Actor::getCMassGlobalPose(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassGlobalPose(mActor);
}

Vec3 Actor::getCMassGlobalPosition(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassGlobalPosition(mActor);
}

Matrix33 Actor::getCMassGlobalOrientation(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCMassGlobalOrientation(mActor);
}

void Actor::setMass(Real mass)
{
 ::NxOgre::Functions::RigidBodyFunctions::setMass(mass, mActor);
}

Real Actor::getMass(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getMass(mActor);
}

void Actor::setMassSpaceInertiaTensor(const Vec3& r3)
{
 ::NxOgre::Functions::RigidBodyFunctions::setMassSpaceInertiaTensor(r3, mActor);
}

Vec3 Actor::getMassSpaceInertiaTensor(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getMassSpaceInertiaTensor(mActor);
}

Matrix33 Actor::getGlobalInertiaTensor(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalInertiaTensor(mActor);
}

Matrix33 Actor::getGlobalInertiaTensorInverse(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getGlobalInertiaTensorInverse(mActor);
}

bool Actor::updateMassFromShapes(Real density, Real totalMass) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::updateMassFromShapes(density, totalMass, mActor);
}

void Actor::setLinearDamping(Real linDamp)
{
 ::NxOgre::Functions::RigidBodyFunctions::setLinearDamping(linDamp, mActor);
}

Real Actor::getLinearDamping(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getLinearDamping(mActor);
}

void Actor::setAngularDamping(Real angDamp)
{
 ::NxOgre::Functions::RigidBodyFunctions::setAngularDamping(angDamp, mActor);
}

Real Actor::getAngularDamping(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getAngularDamping(mActor);
}

void Actor::setLinearVelocity(const Vec3& linVel)
{
 ::NxOgre::Functions::RigidBodyFunctions::setLinearVelocity(linVel, mActor);
}

void Actor::setAngularVelocity(const Vec3& angVel)
{
 ::NxOgre::Functions::RigidBodyFunctions::setAngularVelocity(angVel, mActor);
}

Vec3 Actor::getLinearVelocity(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getLinearVelocity(mActor);
}

Vec3 Actor::getAngularVelocity (void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getAngularVelocity(mActor);
}

void Actor::setMaxAngularVelocity(Real maxAngVel)
{
 ::NxOgre::Functions::RigidBodyFunctions::setMaxAngularVelocity(maxAngVel, mActor);
}

Real Actor::getMaxAngularVelocity(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getMaxAngularVelocity(mActor);
}

void Actor::setCCDMotionThreshold(Real thresh)
{
 ::NxOgre::Functions::RigidBodyFunctions::setCCDMotionThreshold(thresh, mActor);
}

Real Actor::getCCDMotionThreshold(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getCCDMotionThreshold(mActor);
}

void Actor::setLinearMomentum(const Vec3& linMoment)
{
 ::NxOgre::Functions::RigidBodyFunctions::setLinearMomentum(linMoment, mActor);
}

void Actor::setAngularMomentum(const Vec3& angMoment)
{
 ::NxOgre::Functions::RigidBodyFunctions::setAngularMomentum(angMoment, mActor);
}

Vec3 Actor::getLinearMomentum(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getLinearMomentum(mActor);
}

Vec3 Actor::getAngularMomentum(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getAngularMomentum(mActor);
}

void Actor::addForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addForceAtPos(force, pos, mode, wakeup, mActor);
}

void Actor::addForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addForceAtLocalPos(force, pos, mode, wakeup, mActor);
}

void Actor::addLocalForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addLocalForceAtPos(force, pos, mode, wakeup, mActor);
}

void Actor::addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addLocalForceAtLocalPos(force, pos, mode, wakeup, mActor);
}

void Actor::addForce(const Vec3& force, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addForce(force, mode, wakeup, mActor);
}

void Actor::addLocalForce(const Vec3& force, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addLocalForce(force, mode, wakeup, mActor);
}

void Actor::addTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addTorque(torque, mode, wakeup, mActor);
}

void Actor::addLocalTorque(const Vec3& torque, Enums::ForceMode mode, bool wakeup)
{
 NxOgre::Functions::RigidBodyFunctions::addLocalTorque(torque, mode, wakeup, mActor);
}

Vec3 Actor::getPointVelocity (const Vec3& point) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getPointVelocity(point, mActor);
}

Vec3 Actor::getLocalPointVelocity(const Vec3& point) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getLocalPointVelocity(point, mActor);
}

bool Actor::isGroupSleeping(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::isGroupSleeping(mActor);
}

bool Actor::isSleeping(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::isSleeping(mActor);
}

Real Actor::getSleepLinearVelocity(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getSleepLinearVelocity(mActor);
}

void Actor::setSleepLinearVelocity(Real threshold)
{
 ::NxOgre::Functions::RigidBodyFunctions::setSleepLinearVelocity(threshold, mActor);
}

Real Actor::getSleepAngularVelocity(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getSleepAngularVelocity(mActor);
}

void Actor::setSleepAngularVelocity(Real threshold)
{
 ::NxOgre::Functions::RigidBodyFunctions::setSleepAngularVelocity(threshold, mActor);
}

Real Actor::getSleepEnergyThreshold(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::getSleepEnergyThreshold(mActor);
}

void Actor::setSleepEnergyThreshold(Real threshold)
{
 ::NxOgre::Functions::RigidBodyFunctions::setSleepEnergyThreshold(threshold, mActor);
}

void Actor::wakeUp(Real wakeCounterValue)
{
 ::NxOgre::Functions::RigidBodyFunctions::wakeUp(wakeCounterValue, mActor);
}

void Actor::putToSleep(void)
{
 ::NxOgre::Functions::RigidBodyFunctions::putToSleep(mActor);
}

                                                                                       

} // namespace NxOgre

                                                                                       

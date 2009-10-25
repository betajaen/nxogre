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
#include "NxOgreActor.h"

#include "NxOgreScene.h"
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"

#include "NxActor.h"
#include "NxScene.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Actor::Actor(Scene* scene)
: RigidBody(), mScene(scene)
{
}

Actor::Actor(Shape* shape, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(), mScene(scene)
{
 mName = description.mName;
 mNameHash = Functions::StringHash(mName);
 
 createDynamic(pose, description, scene, shape);
}

Actor::Actor(Shapes& shapes, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene)
: RigidBody(), mScene(scene)
{
 mName = description.mName;
 mNameHash = Functions::StringHash(mName);
 
 createDynamic(pose, description, scene, shapes);
}

Actor::~Actor(void)
{
 destroy();
}

unsigned int Actor::getRigidBodyType() const 
{
 return ::NxOgre::Classes::_Actor;
}

void Actor::setGroup(GroupIdentifier actorGroup)
{
 mActor->setGroup(actorGroup);
}

GroupIdentifier Actor::getGroup(void) const
{
 return mActor->getGroup();
}

void Actor::setDominanceGroup(GroupIdentifier dominanceGroup)
{
 mActor->setGroup(dominanceGroup);
}

GroupIdentifier Actor::getDominanceGroup(void) const
{
 return mActor->getDominanceGroup();
}

void Actor::resetPairFiltering(void)
{
 mActor->resetUserActorPairFiltering();
}

Real Actor::computeKineticEnergy(void) const
{
 return mActor->computeKineticEnergy();
}

void Actor::setSolverIterationCount(unsigned int iterCount)
{
 mActor->setSolverIterationCount(iterCount);
}

unsigned int Actor::getSolverIterationCount(void) const
{
 return mActor->getSolverIterationCount();
}

Real Actor::getContactReportThreshold(void) const
{
 return mActor->getContactReportThreshold();
}

void Actor::setContactReportThreshold(Real threshold)
{
 mActor->setContactReportThreshold(threshold);
}

unsigned int Actor::getContactReportFlags(void) const
{
 return mActor->getContactReportFlags();
}

void Actor::setContactReportFlags(unsigned int flags)
{
 mActor->setContactReportFlags(flags);
}

unsigned short Actor::getForceFieldMaterial(void) const
{
 return mActor->getForceFieldMaterial();
}

void Actor::setForceFieldMaterial(unsigned short ffm)
{
 mActor->setForceFieldMaterial(ffm);
}

void Actor::setGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setGlobalPose(global_pose);
}

void Actor::setGlobalPosition(const Vec3& vec)
{
 mActor->setGlobalPosition(vec.as<NxVec3>());
}

void Actor::setGlobalOrientation(const Matrix33& mat)
{
 NxMat33 matrix;
 matrix.setRowMajor(mat.ptr());
 mActor->setGlobalOrientation(matrix);
}

void Actor::setGlobalOrientationQuat(const Quat& quat)
{
 mActor->setGlobalOrientationQuat(quat.as<NxQuat>());
}

Matrix44 Actor::getGlobalPose(void) const
{
 Matrix44 matrix;
 mActor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

Vec3 Actor::getGlobalPosition(void) const
{
 return Vec3(mActor->getGlobalPosition());
}

Matrix33 Actor::getGlobalOrientation(void) const
{
 Matrix33 matrix;
 mActor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

Quat Actor::getGlobalOrientationQuat(void) const
{
 return Quat(mActor->getGlobalOrientationQuat());
}

unsigned int Actor::getNbShapes(void) const
{
 return mActor->getNbShapes();
}

void Actor::setCMassOffsetLocalPose(const Matrix44& matrix)
{
 
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setCMassOffsetLocalPose(global_pose);
 
}

void Actor::setCMassOffsetLocalPosition(const Vec3& vec)
{
 mActor->setCMassOffsetLocalPosition(vec.as<NxVec3>());
}

void Actor::setCMassOffsetLocalOrientation(const Matrix33& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setCMassOffsetGlobalPose(global_pose);
}

void Actor::setCMassOffsetGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setCMassOffsetGlobalPose(global_pose);
}

void Actor::setCMassOffsetGlobalPosition(const Vec3& vec)
{
 mActor->setCMassOffsetGlobalPosition(vec.as<NxVec3>());
}

void Actor::setCMassOffsetGlobalOrientation(const Matrix33& r33)
{
 NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 mActor->setCMassOffsetGlobalOrientation(global_orientation);
}

void Actor::setCMassGlobalPose(const Matrix44& matrix)
{
 NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 mActor->setCMassGlobalPose(global_pose);
}

void Actor::setCMassGlobalPosition(const Vec3& vec)
{
 mActor->setCMassGlobalPosition(vec.as<NxVec3>());
}

void Actor::setCMassGlobalOrientation(const Matrix33& r33)
{
 NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 mActor->setCMassGlobalOrientation(global_orientation);
}

Matrix44 Actor::getCMassLocalPose(void) const
{
 Matrix44 global_pose;
 mActor->getCMassLocalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

Vec3 Actor::getCMassLocalPosition(void) const
{
 return Vec3(mActor->getCMassLocalPosition());
}

Matrix33 Actor::getCMassLocalOrientation(void) const
{
 Matrix33 global_orientation;
 mActor->getCMassLocalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

Matrix44 Actor::getCMassGlobalPose(void) const
{
 Matrix44 global_pose;
 mActor->getCMassGlobalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

Vec3 Actor::getCMassGlobalPosition(void) const
{
 return Vec3(mActor->getCMassGlobalPosition());
}

Matrix33 Actor::getCMassGlobalOrientation(void) const
{
 Matrix33 global_orientation;
 mActor->getCMassGlobalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

void Actor::setMass(Real mass)
{
 mActor->setMass(mass);
}

Real Actor::getMass(void) const
{
 return mActor->getMass();
}

void Actor::setMassSpaceInertiaTensor(const Vec3& vec)
{
 mActor->setMassSpaceInertiaTensor(vec.as<NxVec3>());
}

Vec3 Actor::getMassSpaceInertiaTensor(void) const
{
 return Vec3(mActor->getMassSpaceInertiaTensor());
}

Matrix33 Actor::getGlobalInertiaTensor(void) const
{
 Matrix33 matrix33;
 mActor->getGlobalInertiaTensor().getRowMajor(matrix33.ptr());
 return matrix33;
}

Matrix33 Actor::getGlobalInertiaTensorInverse(void) const
{
 Matrix33 matrix33;
 mActor->getGlobalInertiaTensorInverse().getRowMajor(matrix33.ptr());
 return matrix33;
}

bool Actor::updateMassFromShapes(Real density, Real totalMass) const
{
 return mActor->updateMassFromShapes(density, totalMass);
}

void Actor::setLinearDamping(Real linDamp)
{
 mActor->setLinearDamping(linDamp);
}

Real Actor::getLinearDamping(void) const
{
 return mActor->getLinearDamping();
}

void Actor::setAngularDamping(Real angDamp)
{
 mActor->setAngularDamping(angDamp);
}

Real Actor::getAngularDamping(void) const
{
 return mActor->getAngularDamping();
}

void Actor::setLinearVelocity(const Vec3& linVel)
{
 mActor->setLinearVelocity(linVel.as<NxVec3>());
}

void Actor::setAngularVelocity(const Vec3& angVel)
{
 mActor->setAngularVelocity(angVel.as<NxVec3>());
}

Vec3 Actor::getLinearVelocity(void) const
{
 return Vec3(mActor->getLinearVelocity());
}

Vec3 Actor::getAngularVelocity (void) const
{
 return Vec3(mActor->getAngularVelocity());
}

void Actor::setMaxAngularVelocity(Real maxAngVel)
{
 mActor->setMaxAngularVelocity(maxAngVel);
}

Real Actor::getMaxAngularVelocity(void) const
{
 return mActor->getMaxAngularVelocity();
}

void Actor::setCCDMotionThreshold(Real thresh)
{
 mActor->setCCDMotionThreshold(thresh);
}

Real Actor::getCCDMotionThreshold(void) const
{
 return mActor->getCCDMotionThreshold();
}

void Actor::setLinearMomentum(const Vec3& linMoment)
{
 mActor->setLinearMomentum(linMoment.as<NxVec3>());
}

void Actor::setAngularMomentum(const Vec3& angMoment)
{
 mActor->setAngularMomentum(angMoment.as<NxVec3>());
}

Vec3 Actor::getLinearMomentum(void) const
{
 return Vec3(mActor->getLinearMomentum());
}

Vec3 Actor::getAngularMomentum(void) const
{
 return Vec3(mActor->getAngularMomentum());
}

void Actor::addForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForceAtPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForceAtLocalPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addLocalForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForceAtPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addLocalForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForceAtLocalPos(force.as<NxVec3>(), pos.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addForce(const Vec3& force, Enums::ForceMode mode, bool wakeup)
{
 mActor->addForce(force.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addLocalForce(const Vec3& force, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalForce(force.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addTorque(const Vec3& torque, Enums::ForceMode mode, bool wakeup)
{
 mActor->addTorque(torque.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

void Actor::addLocalTorque(const Vec3& torque, Enums::ForceMode mode, bool wakeup)
{
 mActor->addLocalTorque(torque.as<NxVec3>(), NxForceMode(int(mode)), wakeup);
}

Vec3 Actor::getPointVelocity(const Vec3& point) const
{
 return Vec3(mActor->getPointVelocity(point.as<NxVec3>()));
}

Vec3 Actor::getLocalPointVelocity(const Vec3& point) const
{
 return Vec3(mActor->getLocalPointVelocity(point.as<NxVec3>()));
}

bool Actor::isGroupSleeping(void) const
{
 return mActor->isGroupSleeping();
}

bool Actor::isSleeping(void) const
{
 return mActor->isSleeping();
}

Real Actor::getSleepLinearVelocity(void) const
{
 return mActor->getSleepLinearVelocity();
}

void Actor::setSleepLinearVelocity(Real threshold)
{
 mActor->setSleepLinearVelocity(threshold);
}

Real Actor::getSleepAngularVelocity(void) const
{
 return mActor->getSleepAngularVelocity();
}

void Actor::setSleepAngularVelocity(Real threshold)
{
 mActor->setSleepAngularVelocity(threshold);
}

Real Actor::getSleepEnergyThreshold(void) const
{
 return mActor->getSleepEnergyThreshold();
}

void Actor::setSleepEnergyThreshold(Real threshold)
{
 mActor->setSleepEnergyThreshold(threshold);
}

void Actor::wakeUp(Real wakeCounterValue)
{
 mActor->wakeUp(wakeCounterValue);
}

void Actor::putToSleep(void)
{
 mActor->putToSleep();
}

Compartment* Actor::getCompartment()
{
 return mScene->getCompartment(mActor->getCompartment());
}

unsigned int Actor::linearSweep(const Vec3& motion, unsigned int sweep_flags, unsigned int size, SweepQueryHits& hits, SweepCache* cache)
{
 
 NxSweepQueryHit* query_hits = (NxSweepQueryHit*) malloc(sizeof(NxSweepQueryHit) * size);
  
 unsigned int count = mActor->linearSweep(motion.as<NxVec3>(), sweep_flags, 0, size, query_hits, 0, cache->getCache());
 Functions::SweepFunctions::NxSweepQueryHitsToBuffer(query_hits, count, hits);
 
 free(query_hits);
 
 return count;
}


/*
NxU32 Actor::linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL)
{
 NxSweepQueryHit
}
*/ 

                                                                                       

} // namespace NxOgre

                                                                                       

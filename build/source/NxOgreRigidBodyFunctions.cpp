/** File: NxOgreRigidBodyFunctions.h
    Created on: 10-Nov-08
    Author: Robin Southern "betajaen"
    Last-Modified-For: PhysX 2.8.1
    

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
#include "NxOgreCommon.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreFunctions.h"
#include "NxOgreMatrix.h"
#include "NxOgreShape.h"
#include "NxOgreBox.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

namespace RigidBodyFunctions
{

extern inline void setGroup(GroupIdentifier actorGroup, NxActor* actor)
{
 actor->setGroup(actorGroup);
}

extern inline GroupIdentifier getGroup(NxActor* actor)
{
 return actor->getGroup();
}

extern inline void setDominanceGroup(GroupIdentifier dominanceGroup, NxActor* actor)
{
 actor->setDominanceGroup(dominanceGroup);
}

extern inline GroupIdentifier getDominanceGroup(NxActor* actor)
{
 return actor->getDominanceGroup();
}

extern inline void resetPairFiltering(NxActor* actor)
{
 actor->resetUserActorPairFiltering();
}

extern inline bool isDynamic(NxActor* actor)
{
 return actor->isDynamic();
}

extern inline Real computeKineticEnergy(NxActor* actor)
{
 return actor->computeKineticEnergy();
}

extern inline void setSolverIterationCount(unsigned int iterCount, NxActor* actor)
{
 actor->setSolverIterationCount(iterCount);
}

extern inline unsigned int getSolverIterationCount(NxActor* actor)
{
 return actor->getSolverIterationCount();
}

extern inline Real getContactReportThreshold(NxActor* actor)
{
 return actor->getContactReportThreshold();
}

extern inline void setContactReportThreshold(Real threshold, NxActor* actor)
{
 actor->setContactReportThreshold(threshold);
}

extern inline unsigned int getContactReportFlags(NxActor* actor)
{
 return actor->getContactReportFlags();
}

extern inline void setContactReportFlags(unsigned int flags, NxActor* actor)
{
 actor->setContactReportFlags(flags);
}

extern inline unsigned short getForceFieldMaterial(NxActor* actor)
{
 return actor->getForceFieldMaterial();
}

extern inline void setForceFieldMaterial(unsigned short ffm, NxActor* actor)
{
 actor->setForceFieldMaterial(ffm);
}

extern inline void setGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setGlobalPose(global_pose);
}

extern inline void setGlobalPosition (const Vec3& r3, NxActor* actor)
{
 static NxVec3 global_position;
 global_position.x = r3.x;
 global_position.y = r3.y;
 global_position.z = r3.z;
 actor->setGlobalPosition(global_position);
}

extern inline void setGlobalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setGlobalOrientation(global_orientation);
}

extern inline void setGlobalOrientationQuat(const Quat& r4, NxActor* actor)
{
 static NxQuat global_orientation_as_nx_quat;
 global_orientation_as_nx_quat.w = r4.w;
 global_orientation_as_nx_quat.x = r4.x;
 global_orientation_as_nx_quat.y = r4.y;
 global_orientation_as_nx_quat.z = r4.z;
 actor->setGlobalOrientationQuat(global_orientation_as_nx_quat);
}

extern inline Matrix44 getGlobalPose(NxActor* actor)
{
 Matrix44 matrix;
 actor->getGlobalPose().getRowMajor44(matrix.ptr());
 return matrix;
}

extern inline Vec3 getGlobalPosition(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getGlobalPosition());
}

extern inline Matrix33 getGlobalOrientation(NxActor* actor)
{
 Matrix33 matrix;
 actor->getGlobalOrientation().getRowMajor(matrix.ptr());
 return matrix;
}

extern inline Quat getGlobalOrientationQuat(NxActor* actor)
{
 return WXYZ<NxQuat, Quat>(actor->getGlobalOrientationQuat());
}

extern inline void moveGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->moveGlobalPose(global_pose);
}

extern inline void moveGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->moveGlobalPosition(r3.as<NxVec3>());
}

extern inline void moveGlobalOrientation (const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->moveGlobalOrientation(global_orientation);
}

extern inline void moveGlobalOrientationQuat (const Quat& quat, NxActor* actor)
{
 actor->moveGlobalOrientationQuat(quat.as<NxQuat>());
}

extern inline void createShape(Shape*, NxActor* actor)
{
 //< ARGH.
}

extern inline void releaseShape(Shape*, NxActor* actor)
{
 //< ARGH.
}

extern inline unsigned int getNbShapes(NxActor* actor)
{
 return actor->getNbShapes();
}

extern inline void setCMassOffsetLocalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassOffsetLocalPose(global_pose);
}

extern inline void setCMassOffsetLocalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassOffsetLocalPosition(XYZ<Vec3, NxVec3>(r3));
}

extern inline void setCMassOffsetLocalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassOffsetLocalOrientation(global_orientation);
}

extern inline void setCMassOffsetGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassOffsetGlobalPose(global_pose);
}

extern inline void setCMassOffsetGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassOffsetGlobalPosition(XYZ<Vec3, NxVec3>(r3));
}

extern inline void setCMassOffsetGlobalOrientation(const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassOffsetGlobalOrientation(global_orientation);
}

extern inline void setCMassGlobalPose(const Matrix44& matrix, NxActor* actor)
{
 static NxMat34 global_pose;
 global_pose.setRowMajor44(matrix.ptr());
 actor->setCMassGlobalPose(global_pose);
}

extern inline void setCMassGlobalPosition(const Vec3& r3, NxActor* actor)
{
 actor->setCMassGlobalPosition(XYZ<Vec3, NxVec3>(r3));
}

extern inline void setCMassGlobalOrientation (const Matrix33& r33, NxActor* actor)
{
 static NxMat33 global_orientation;
 global_orientation.setRowMajor(r33.ptr());
 actor->setCMassGlobalOrientation(global_orientation);
}

extern inline Matrix44 getCMassLocalPose(NxActor* actor)
{
 static Matrix44 global_pose;
 actor->getCMassLocalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

extern inline Vec3 getCMassLocalPosition(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getCMassLocalPosition());
}

extern inline Matrix33 getCMassLocalOrientation(NxActor* actor)
{
 static Matrix33 global_orientation;
 actor->getCMassLocalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

extern inline Matrix44 getCMassGlobalPose(NxActor* actor)
{
 static Matrix44 global_pose;
 actor->getCMassGlobalPose().getRowMajor44(global_pose.ptr());
 return global_pose;
}

extern inline Vec3 getCMassGlobalPosition(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getCMassGlobalPosition());
}

extern inline Matrix33 getCMassGlobalOrientation(NxActor* actor)
{
 static Matrix33 global_orientation;
 actor->getCMassGlobalOrientation().getRowMajor(global_orientation.ptr());
 return global_orientation;
}

extern inline void setMass(Real mass, NxActor* actor)
{
 actor->setMass(mass);
}

extern inline Real getMass(NxActor* actor)
{
 return actor->getMass();
}

extern inline void setMassSpaceInertiaTensor(const Vec3& r3, NxActor* actor)
{
 actor->setMassSpaceInertiaTensor(XYZ<Vec3, NxVec3>(r3));
}

extern inline Vec3 getMassSpaceInertiaTensor(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getMassSpaceInertiaTensor());
}

extern inline Matrix33 getGlobalInertiaTensor(NxActor* actor)
{
 static Matrix33 _real33;
 actor->getGlobalInertiaTensor().getRowMajor(_real33.ptr());
 return _real33;
}

extern inline Matrix33 getGlobalInertiaTensorInverse(NxActor* actor)
{
 static Matrix33 _real33;
 actor->getGlobalInertiaTensorInverse().getRowMajor(_real33.ptr());
 return _real33;
}

extern inline bool updateMassFromShapes(Real density, Real totalMass, NxActor* actor)
{
 return actor->updateMassFromShapes(density, totalMass);
}

extern inline void setLinearDamping(Real linDamp, NxActor* actor)
{
 actor->setLinearDamping(linDamp);
}

extern inline Real getLinearDamping(NxActor* actor)
{
 return actor->getLinearDamping();
}

extern inline void setAngularDamping(Real angDamp, NxActor* actor)
{
 actor->setAngularDamping(angDamp);
}

extern inline Real getAngularDamping(NxActor* actor)
{
 return actor->getAngularDamping();
}

extern inline void setLinearVelocity(const Vec3& linVel, NxActor* actor)
{
 actor->setLinearVelocity(XYZ<Vec3, NxVec3>(linVel));
}

extern inline void setAngularVelocity(const Vec3& angVel, NxActor* actor)
{
 actor->setAngularVelocity(XYZ<Vec3, NxVec3>(angVel));
}

extern inline Vec3 getLinearVelocity(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getLinearVelocity());
}

extern inline Vec3 getAngularVelocity (NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getAngularVelocity());
}

extern inline void setMaxAngularVelocity(Real maxAngVel, NxActor* actor)
{
 actor->setMaxAngularVelocity(maxAngVel);
}

extern inline Real getMaxAngularVelocity(NxActor* actor)
{
 return actor->getMaxAngularVelocity();
}

extern inline void setCCDMotionThreshold(Real thresh, NxActor* actor)
{
 actor->setCCDMotionThreshold(thresh);
}

extern inline Real getCCDMotionThreshold(NxActor* actor)
{
 return actor->getCCDMotionThreshold();
}

extern inline void setLinearMomentum(const Vec3& linMoment, NxActor* actor)
{
 actor->setLinearMomentum(XYZ<Vec3, NxVec3>(linMoment));
}

extern inline void setAngularMomentum(const Vec3& angMoment, NxActor* actor)
{
 actor->setAngularMomentum(XYZ<Vec3, NxVec3>(angMoment));
}

extern inline Vec3 getLinearMomentum(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getLinearMomentum());
}

extern inline Vec3 getAngularMomentum(NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getAngularMomentum());
}

extern inline void addForceAtPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForceAtPos(XYZ<Vec3, NxVec3>(force), XYZ<Vec3, NxVec3>(pos), NxForceMode(int(mode)), wakeup);
}

extern inline void addForceAtLocalPos(const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForceAtLocalPos(XYZ<Vec3, NxVec3>(force), XYZ<Vec3, NxVec3>(pos), NxForceMode(int(mode)), wakeup);
}

extern inline void addLocalForceAtPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForceAtPos(XYZ<Vec3, NxVec3>(force), XYZ<Vec3, NxVec3>(pos), NxForceMode(int(mode)), wakeup);
}

extern inline void addLocalForceAtLocalPos (const Vec3& force, const Vec3& pos, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForceAtLocalPos(XYZ<Vec3, NxVec3>(force), XYZ<Vec3, NxVec3>(pos), NxForceMode(int(mode)), wakeup);
}

extern inline void addForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addForce(XYZ<Vec3, NxVec3>(force), NxForceMode(int(mode)), wakeup);
}

extern inline void addLocalForce (const Vec3& force, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalForce(XYZ<Vec3, NxVec3>(force), NxForceMode(int(mode)), wakeup);
}

extern inline void addTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addTorque(XYZ<Vec3, NxVec3>(torque), NxForceMode(int(mode)), wakeup);
}

extern inline void addLocalTorque (const Vec3& torque, Enums::ForceMode mode, bool wakeup, NxActor* actor)
{
 actor->addLocalTorque(XYZ<Vec3, NxVec3>(torque), NxForceMode(int(mode)), wakeup);
}

extern inline Vec3 getPointVelocity (const Vec3& point, NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getPointVelocity(XYZ<Vec3, NxVec3>(point)));
}

extern inline Vec3 getLocalPointVelocity(const Vec3& point, NxActor* actor)
{
 return XYZ<NxVec3, Vec3>(actor->getLocalPointVelocity(XYZ<Vec3, NxVec3>(point)));
}

extern inline bool isGroupSleeping(NxActor* actor)
{
 return actor->isGroupSleeping();
}

extern inline bool isSleeping(NxActor* actor)
{
 return actor->isSleeping();
}

extern inline Real getSleepLinearVelocity(NxActor* actor)
{
 return actor->getSleepLinearVelocity();
}

extern inline void setSleepLinearVelocity(Real threshold, NxActor* actor)
{
 actor->setSleepLinearVelocity(threshold);
}

extern inline Real getSleepAngularVelocity(NxActor* actor)
{
 return actor->getSleepAngularVelocity();
}

extern inline void setSleepAngularVelocity(Real threshold, NxActor* actor)
{
 actor->setSleepAngularVelocity(threshold);
}

extern inline Real getSleepEnergyThreshold(NxActor* actor)
{
 return actor->getSleepEnergyThreshold();
}

extern inline void setSleepEnergyThreshold(Real threshold, NxActor* actor)
{
 actor->setSleepEnergyThreshold(threshold);
}

extern inline void wakeUp(Real wakeCounterValue, NxActor* actor)
{
 actor->wakeUp(wakeCounterValue);
}

extern inline void putToSleep(NxActor* actor)
{
 actor->putToSleep();
}

extern inline RigidBody* NxShapeToRigidBody(NxShape& shape)
{
/*
 if (shape.isBox())
  return static_cast<Box*>(shape.userData)->getRigidBody();
 if (shape.isSphere())
  return static_cast<Sphere*>(shape.userData)->getRigidBody();
 if (shape.isCapsule())
  return static_cast<Capsule*>(shape.userData)->getRigidBody();
 if (shape.isPlane())
  return static_cast<PlaneGeometry*>(shape.userData)->getRigidBody();
*/
 // Convex
 // Wheel
 // HeightFieldGeometry
 // TriangleGeometry
 return 0;
}


                                                                                       

} // namspace RigidBodyFunctions

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

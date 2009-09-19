/** File: NxOgrePrototype.cpp
    Created on: 4-Nov-08
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
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreFunctions.h"
#include "NxOgreWorldPrototype.h"
#include "NxOgreScenePrototype.h"
#include "NxOgreRigidBodyPrototype.h"
#include "NxOgreShape.h"
#include "NxOgreBox.h"

#include "NxOgreMaterialPrototype.h"
#include "NxOgreMaterialDescription.h"
#include "NxOgreMesh.h"

#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreD6JointDescription.h"

#include "NxOgreClothDescription.h"
#include "NxOgreSoftBodyDescription.h"

#include "NxOgreCompartment.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions 
{

                                                                                       

void PrototypeFunctions::WorldPrototypeToNxPhysicsSDKDesc(WorldPrototype* prototype, NxPhysicsSDKDesc& description)
{
 description.cookerThreadMask = prototype->mCookerThreadMask;
 if (prototype->mNoHardware)
  description.flags |= NX_SDKF_NO_HARDWARE;
 description.hwConvexMax = prototype->mHardwareMaximumConvex;
 description.hwPageMax= prototype->mHardwareMaximumPage;
 description.hwPageSize = prototype->mHardwarePageSize;
}

void PrototypeFunctions::SceneDescriptionToScenePrototype(const SceneDescription& description, ScenePrototype* prototype)
{
 prototype->mName                         = description.mName;
 prototype->mProcessingPriority           = description.mProcessingPriority;
 prototype->mFetchingPriority             = description.mFetchingPriority;
 prototype->mGravity                      = description.mGravity;
 prototype->mMaxTimeStep                  = description.mMaxTimeStep;
 prototype->mMaxSubSteps                  = description.mMaxSubSteps;
 prototype->mTimeStepMethod               = description.mTimeStepMethod;
 prototype->mBounds.min                   = description.mBounds.min;
 prototype->mBounds.max                   = description.mBounds.max;
 prototype->mMaxDynamicRigidBodies        = description.mMaxDynamicRigidBodies;
 prototype->mMaxDynamicShapes             = description.mMaxDynamicShapes;
 prototype->mMaxNonDynamicRigidBodies     = description.mMaxNonDynamicRigidBodies;
 prototype->mMaxStaticShapes              = description.mMaxStaticShapes;
 prototype->mMaxJoints                    = description.mMaxJoints;
 prototype->mUseHardware                  = description.mUseHardware;
 prototype->mBoundsPlane                  = description.mBoundsPlane;
 prototype->mFlags                        = description.mFlags;
 prototype->mBoundsUpAxis                 = description.mBoundsUpAxis;
 prototype->mBoundsSubdivisionLevel       = description.mBoundsSubdivisionLevel;
 prototype->mPruningStaticStructure       = description.mPruningStaticStructure;
 prototype->mPruningDynamicStructure      = description.mPruningDynamicStructure;
 prototype->mDynamicTreeBuildRateHint     = description.mDynamicTreeBuildRateHint;
 prototype->mWorkerThreadsCount           = description.mWorkerThreadsCount;
 prototype->mWorkerThreadsStackSize       = description.mWorkerThreadsStackSize;
 prototype->mWorkerThreadsPriority        = description.mWorkerThreadsPriority;
 prototype->mWorkerThreadsMask            = description.mWorkerThreadsMask;
 prototype->mBackgroundThreadsCount       = description.mBackgroundThreadsCount;
 prototype->mBackgroundThreadsStackSize   = description.mBackgroundThreadsStackSize;
 prototype->mBackgroundThreadsPriority    = description.mBackgroundThreadsPriority;
 prototype->mBackgroundThreadsMask        = description.mBackgroundThreadsMask;
 prototype->mSimulationThreadMask         = description.mSimulationThreadMask;
 prototype->mSimulationThreadStackSize    = description.mSimulationThreadStackSize;
 prototype->mSimulationThreadPriority     = description.mSimulationThreadPriority;
 prototype->mBroadPhaseType               = description.mBroadPhaseType;
 prototype->mBroadPhaseNbCellsX           = description.mBroadPhaseNbCellsX;
 prototype->mBroadPhaseNbCellsY           = description.mBroadPhaseNbCellsY;
 prototype->mSolverBatchSize              = description.mSolverBatchSize;
}

void PrototypeFunctions::ScenePrototypeToNxSceneDesc(NxOgre::ScenePrototype* prototype, NxSceneDesc& description)
{
 description.backgroundThreadCount      = prototype->mBackgroundThreadsCount;
 description.backgroundThreadMask       = prototype->mBackgroundThreadsMask;
 description.backgroundThreadPriority   = NxThreadPriority(int(prototype->mBackgroundThreadsPriority));
 description.boundsPlanes               = prototype->mBoundsPlane;
 description.bpType                     = NxBroadPhaseType(int(prototype->mBroadPhaseType));
 description.dynamicStructure           = NxPruningStructure(int(prototype->mPruningDynamicStructure));
 description.dynamicTreeRebuildRateHint = prototype->mDynamicTreeBuildRateHint;
 description.flags                      = prototype->mFlags;
 Functions::XYZ<Vec3, NxVec3>          ( prototype->mGravity, description.gravity );
 description.internalThreadCount        = prototype->mWorkerThreadsCount;
 description.maxIter                    = prototype->mMaxSubSteps;
 description.maxTimestep                = prototype->mMaxTimeStep;
 description.nbGridCellsX               = prototype->mBroadPhaseNbCellsX;
 description.nbGridCellsY               = prototype->mBroadPhaseNbCellsY;
 description.simThreadMask              = prototype->mSimulationThreadMask;
 description.simThreadPriority          = NxThreadPriority(int(prototype->mSimulationThreadPriority));
 description.simThreadStackSize         = prototype->mSimulationThreadStackSize;
 description.simType                    = prototype->mUseHardware == true ? NX_SIMULATION_HW : NX_SIMULATION_SW;
 description.solverBatchSize            = prototype->mSolverBatchSize;
 description.staticStructure            = NxPruningStructure(int(prototype->mPruningStaticStructure));
 description.subdivisionLevel           = prototype->mBoundsSubdivisionLevel;
 description.threadMask                 = prototype->mWorkerThreadsMask;
 description.timeStepMethod             = NxTimeStepMethod(int(prototype->mTimeStepMethod));
 description.upAxis                     = int(prototype->mBoundsUpAxis);
 if (description.upAxis == Enums::NoAxis)
  description.upAxis = 0;
 description.workerThreadPriority       = NxThreadPriority(int(prototype->mWorkerThreadsPriority));
 description.workerThreadStackSize      = prototype->mWorkerThreadsStackSize;
}

void PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(const RigidBodyDescription& description, RigidBodyPrototype* prototype)
{
 prototype->mAngularDamping = description.mAngularDamping;
 prototype->mAngularVelocity = description.mAngularVelocity;
 prototype->mActorFlags = description.mActorFlags;
 prototype->mBodyFlags = description.mBodyFlags;
 prototype->mCCDMotionThreshold = description.mCCDMotionThreshold;
 prototype->mCompartment = description.mCompartment;
 prototype->mContactReportThreshold = description.mContactReportThreshold;
 prototype->mDensity = description.mDensity;
 prototype->mDominanceGroup = description.mDominanceGroup;
 prototype->mForceFieldMaterial = description.mForceFieldMaterial;
 prototype->mGroup = description.mGroup;
 prototype->mInternalThreadCount = description.mInternalThreadCount;
 prototype->mLinearDamping = description.mLinearDamping;
 prototype->mLinearVelocity = description.mLinearVelocity;
 prototype->mMass = description.mMass;
 prototype->mMassLocalPose = description.mMassLocalPose;
 prototype->mMassSpaceInertia = description.mMassSpaceInertia;
 prototype->mMaxAngularVelocity = description.mMaxAngularVelocity;
 prototype->mName = description.mName;
 prototype->mSleepAngularVelocity = description.mSleepAngularVelocity;
 prototype->mSleepDamping = description.mSleepDamping;
 prototype->mSleepEnergyThreshold = description.mSleepEnergyThreshold;
 prototype->mSleepLinearVelocity = description.mSleepLinearVelocity;
 prototype->mSolverIterationCount = description.mSolverIterationCount;
}

void PrototypeFunctions::RigidBodyPrototypeToNxActorAndNxBodyDesc(RigidBodyPrototype* prototype, NxActorDesc& actor_description, NxBodyDesc& body_description)
{
 
 if (prototype->mCompartment != NULL && prototype->mCompartment->getType() == Enums::CompartmentType_RigidBody)
  actor_description.compartment = prototype->mCompartment->getCompartment();
 
 actor_description.contactReportFlags = prototype->mContactReportFlags;
 actor_description.density = prototype->mDensity;
 actor_description.dominanceGroup = prototype->mDominanceGroup;
 actor_description.flags = prototype->mActorFlags;
 actor_description.forceFieldMaterial = prototype->mForceFieldMaterial;
 actor_description.globalPose.setRowMajor44(prototype->mGlobalPose.ptr());
 actor_description.group = prototype->mGroup;
 actor_description.name = prototype->mName.c_str();
 
 if (prototype->mType == Enums::RigidBodyType_Dynamic || prototype->mType == Enums::RigidBodyType_Kinematic)
 {
  body_description.angularDamping = prototype->mAngularDamping;
  Functions::XYZ<Vec3, NxVec3>(prototype->mAngularVelocity, body_description.angularVelocity);
  body_description.CCDMotionThreshold = prototype->mCCDMotionThreshold;
  body_description.contactReportThreshold = prototype->mContactReportThreshold;
  body_description.flags = prototype->mBodyFlags;
  body_description.linearDamping = prototype->mLinearDamping;
  Functions::XYZ<Vec3, NxVec3>(prototype->mLinearVelocity, body_description.linearVelocity);
  body_description.mass = prototype->mMass;
  body_description.massLocalPose.setColumnMajor44(prototype->mMassLocalPose.ptr());
  Functions::XYZ<Vec3, NxVec3>(prototype->mMassSpaceInertia, body_description.massSpaceInertia);
  body_description.maxAngularVelocity = prototype->mMaxAngularVelocity;
  body_description.sleepAngularVelocity = prototype->mSleepAngularVelocity;
  body_description.sleepDamping = prototype->mSleepDamping;
  body_description.sleepEnergyThreshold = prototype->mSleepEnergyThreshold;
  body_description.sleepLinearVelocity = prototype->mSleepLinearVelocity;
  body_description.solverIterationCount = prototype->mSolverIterationCount;
  body_description.wakeUpCounter = prototype->mWakeUpCounter;
  actor_description.body = &body_description;

  if (prototype->mType == Enums::RigidBodyType_Kinematic)
  {
   body_description.flags |= NX_BF_KINEMATIC;
  }
 }
 else if (prototype->mType == Enums::RigidBodyType_Geometry)
 {
 }
 else if (prototype->mType == Enums::RigidBodyType_Volume)
 {
  for (unsigned int i=0;i < prototype->mShapes.size(); i++)
  {
   prototype->mShapes[i]->getBlueprint()->mFlags |= prototype->mVolumeCollisionType;
  }
 }
}

void PrototypeFunctions::MaterialDescriptionToMaterialPrototype(const MaterialDescription& description, MaterialPrototype* prototype)
{
 prototype->mDirectionOfAnisotropy = description.mDirectionOfAnisotropy;
 prototype->mDynamicFriction = description.mDynamicFriction;
 prototype->mFlags = description.mFlags;
 prototype->mFrictionCombineMode = description.mFrictionCombineMode;
 prototype->mResitutionCombineMode = description.mResitutionCombineMode;
 prototype->mRestitution = description.mRestitution;
 prototype->mStaticFriction = description.mStaticFriction;
 prototype->mVDynamicFriction = description.mVDynamicFriction;
 prototype->mVStaticFriction = description.mVStaticFriction;
}

void PrototypeFunctions::MaterialPrototypeToNxMaterialDesc(NxOgre::MaterialPrototype* prototype, NxMaterialDesc& description)
{
 description.dirOfAnisotropy = XYZ<Vec3, NxVec3>(prototype->mDirectionOfAnisotropy);
 description.dynamicFriction = prototype->mDynamicFriction;
 description.dynamicFrictionV = prototype->mVDynamicFriction;
 description.flags = prototype->mFlags;
 description.frictionCombineMode = NxCombineMode(int(prototype->mFrictionCombineMode));
 description.restitution = prototype->mRestitution;
 description.restitutionCombineMode = NxCombineMode(int(prototype->mResitutionCombineMode));
 description.staticFriction = prototype->mStaticFriction;
 description.staticFrictionV = prototype->mVStaticFriction;
}

void PrototypeFunctions::JointDescriptionToNxJointDescription(const JointDescription& source, NxJointDesc& desc)
{
 desc.jointFlags = source.mJointFlags;
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[0], desc.localAnchor[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[1], desc.localAnchor[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[0], desc.localAxis[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[1], desc.localAxis[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[0], desc.localNormal[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[1], desc.localNormal[1]);
}


void PrototypeFunctions::SphericalJointDescriptionToNxSphericalJointDescription(const SphericalJointDescription& source, NxSphericalJointDesc& desc)
{
 desc.flags = source.mSphericalJointFlags;
 desc.jointFlags = source.mJointFlags;
 SpringDescriptionToNxSpringDesc(source.mJointSpring, desc.jointSpring);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[0], desc.localAnchor[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[1], desc.localAnchor[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[0], desc.localAxis[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[1], desc.localAxis[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[0], desc.localNormal[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[1], desc.localNormal[1]);
 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 desc.projectionDistance = source.mProjectionDistance;
 desc.projectionMode = NxJointProjectionMode(int(source.mProjectionMode));
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor;
 Functions::XYZ<Vec3, NxVec3>(source.mSwingAxis, desc.swingAxis);
 JointLimitDescriptionToNxJointLimitDesc(source.mSwingLimit, desc.swingLimit);
 SpringDescriptionToNxSpringDesc(source.mSwingSpring, desc.swingSpring);
 JointLimitDescriptionToNxJointLimitDesc(source.mTwistLimit.first, desc.twistLimit.low);
 JointLimitDescriptionToNxJointLimitDesc(source.mTwistLimit.second, desc.twistLimit.high);
 SpringDescriptionToNxSpringDesc(source.mTwistSpring, desc.twistSpring);
 desc.useAccelerationSpring = int(source.mSpringType);
}

void PrototypeFunctions::RevoluteJointDescriptionToNxRevoluteJointDescription(const RevoluteJointDescription& source, NxRevoluteJointDesc& desc)
{
 desc.flags = source.mRevoluteJointFlags;
 desc.jointFlags = source.mJointFlags;
 JointLimitDescriptionToNxJointLimitDesc(source.mLimit.first, desc.limit.low);
 JointLimitDescriptionToNxJointLimitDesc(source.mLimit.second, desc.limit.high);
  Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[0], desc.localAnchor[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[1], desc.localAnchor[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[0], desc.localAxis[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[1], desc.localAxis[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[0], desc.localNormal[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[1], desc.localNormal[1]);
 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 MotorDescriptionToNxMotorDesc(source.mMotor, desc.motor);
 desc.projectionAngle = source.mProjectionAngle;
 desc.projectionDistance = source.mProjectionDistance;
 desc.projectionMode = NxJointProjectionMode(int(source.mProjectionMode));
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor;
 desc.useAccelerationSpring = int(source.mSpringType);
}

void PrototypeFunctions::SpringDescriptionToNxSpringDesc(const SpringDescription& source, NxSpringDesc& desc)
{
 desc.damper = source.mDamper;
 desc.spring = source.mSpring;
 desc.targetValue = source.mTargetValue;
}

void PrototypeFunctions::JointLimitDescriptionToNxJointLimitDesc(const JointLimitDescription& source, NxJointLimitDesc& desc)
{
 desc.restitution = source.mRestitution;
 desc.value = source.mValue;
}

void PrototypeFunctions::MotorDescriptionToNxMotorDesc(const MotorDescription& source, NxMotorDesc& desc)
{
 desc.freeSpin = source.mFreeSpin;
 desc.maxForce = source.mMaxForce;
 desc.velTarget = source.mVelocityTarget;
}

void PrototypeFunctions::D6JointDescriptionToNxD6JointDescription(const D6JointDescription& source, NxD6JointDesc& desc)
{

 Functions::XYZ<Vec3, NxVec3>(source.mDriveAngularVelocity, desc.driveAngularVelocity);
 Functions::XYZ<Vec3, NxVec3>(source.mDriveLinearVelocity, desc.driveLinearVelocity);
 Functions::WXYZ<Vec4, NxQuat>(source.mDriveOrientation, desc.driveOrientation);
 Functions::XYZ<Vec3, NxVec3>(source.mDrivePosition, desc.drivePosition);
 desc.flags = source.mD6Flags;
 desc.gearRatio = source.mGearRatio;
 desc.jointFlags = source.mJointFlags;
 desc.linearLimit.damping = source.mLinearLimit.mDamping;
 desc.linearLimit.restitution = source.mLinearLimit.mRestitution;
 desc.linearLimit.spring = source.mLinearLimit.mSpring;
 desc.linearLimit.value = source.mLinearLimit.mValue;

 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[0], desc.localAnchor[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAnchor[1], desc.localAnchor[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[0], desc.localAxis[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalAxis[1], desc.localAxis[1]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[0], desc.localNormal[0]);
 Functions::XYZ<Vec3, NxVec3>(source.mLocalNormal[1], desc.localNormal[1]);

 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 desc.slerpDrive.damping = source.mSlerpDrive.mDamping;
 desc.slerpDrive.driveType = source.mSlerpDrive.mDriveType;
 desc.slerpDrive.forceLimit = source.mSlerpDrive.mForceLimit;
 desc.slerpDrive.spring = source.mSlerpDrive.mSpring;
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor;

 desc.swing1Limit.damping = source.mSwing1Limit.mDamping;
 desc.swing1Limit.restitution = source.mSwing1Limit.mRestitution;
 desc.swing1Limit.spring = source.mSwing1Limit.mSpring;
 desc.swing1Limit.value = source.mSwing1Limit.mValue;
 desc.swing1Motion = NxD6JointMotion(int(source.mSwing1Motion));

 desc.swing2Limit.damping = source.mSwing2Limit.mDamping;
 desc.swing2Limit.restitution = source.mSwing2Limit.mRestitution;
 desc.swing2Limit.spring = source.mSwing2Limit.mSpring;
 desc.swing2Limit.value = source.mSwing2Limit.mValue;
 desc.swing2Motion = NxD6JointMotion(int(source.mSwing2Motion));

 desc.swingDrive.damping = source.mSwingDrive.mDamping;
 desc.swingDrive.driveType = source.mSwingDrive.mDriveType;
 desc.swingDrive.forceLimit = source.mSwingDrive.mForceLimit;
 desc.swingDrive.spring = source.mSwingDrive.mSpring;

 desc.twistDrive.damping = source.mTwistDrive.mDamping;
 desc.twistDrive.driveType = source.mTwistDrive.mDriveType;
 desc.twistDrive.forceLimit = source.mTwistDrive.mForceLimit;
 desc.twistDrive.spring = source.mTwistDrive.mSpring;

 desc.twistLimit.low.damping = source.mTwistLimit.first.mDamping;
 desc.twistLimit.low.restitution = source.mTwistLimit.first.mRestitution;
 desc.twistLimit.low.spring = source.mTwistLimit.first.mSpring;
 desc.twistLimit.low.value = source.mTwistLimit.first.mValue;

 desc.twistLimit.high.damping = source.mTwistLimit.second.mDamping;
 desc.twistLimit.high.restitution = source.mTwistLimit.second.mRestitution;
 desc.twistLimit.high.spring = source.mTwistLimit.second.mSpring;
 desc.twistLimit.high.value = source.mTwistLimit.second.mValue;

 desc.twistMotion = NxD6JointMotion(int(source.mTwistMotion));
 desc.useAccelerationSpring = int(source.mSpringType);

 desc.xDrive.damping = source.mXDrive.mDamping;
 desc.xDrive.driveType = source.mXDrive.mDriveType;
 desc.xDrive.forceLimit = source.mXDrive.mForceLimit;
 desc.xDrive.spring = source.mXDrive.mSpring;
 desc.xMotion = NxD6JointMotion(int(source.mXMotion));

 desc.yDrive.damping = source.mYDrive.mDamping;
 desc.yDrive.driveType = source.mYDrive.mDriveType;
 desc.yDrive.forceLimit = source.mYDrive.mForceLimit;
 desc.yDrive.spring = source.mYDrive.mSpring;
 desc.yMotion = NxD6JointMotion(int(source.mYMotion));

 desc.zDrive.damping = source.mZDrive.mDamping;
 desc.zDrive.driveType = source.mZDrive.mDriveType;
 desc.zDrive.forceLimit = source.mZDrive.mForceLimit;
 desc.zDrive.spring = source.mZDrive.mSpring;
 desc.zMotion = NxD6JointMotion(int(source.mZMotion));

}

void PrototypeFunctions::ClothDescriptionToNxClothDesc(const ClothDescription& source, NxClothDesc& desc)
{
 desc.attachmentResponseCoefficient = source.mAttachmentResponseCoefficient;
 desc.attachmentTearFactor = source.mAttachmentTearFactor;
 desc.bendingStiffness = source.mBendingStiffness;
 desc.clothMesh = source.mMesh->getAsCloth();
 desc.collisionGroup = source.mCollisionGroup;
 desc.collisionResponseCoefficient = source.mCollisionResponseCoefficient;
 desc.compartment = 0;
 desc.dampingCoefficient = source.mDampingCoefficient;
 desc.density = source.mDensity;
 desc.externalAcceleration = source.mExternalAcceleration.as<NxVec3>();
 desc.flags = source.mFlags;
 desc.forceFieldMaterial = source.mForceFieldMaterial;
 desc.friction = source.mFriction;
 desc.fromFluidResponseCoefficient = source.mFromFluidResponseCoefficient;
 desc.globalPose.setRowMajor44(source.mGlobalPose.ptr());
 desc.groupsMask.bits0 = source.mGroupsMask.w;
 desc.groupsMask.bits1 = source.mGroupsMask.x;
 desc.groupsMask.bits2 = source.mGroupsMask.y;
 desc.groupsMask.bits3 = source.mGroupsMask.z;
 desc.minAdhereVelocity = source.mMinAdhereVelocity;
 desc.name = source.mName.c_str();
 desc.pressure = source.mPressure;
 desc.relativeGridSpacing = source.mRelativeGridSpacing;
 desc.sleepLinearVelocity = source.mSleepLinearVelocity;
 desc.solverIterations = source.mSolverIterations;
 desc.stretchingStiffness = source.mStretchingStiffness;
 desc.tearFactor = source.mTearFactor;
 desc.thickness = source.mThickness;
 desc.toFluidResponseCoefficient = source.mToFluidResponseCoefficient;
 desc.validBounds.min = source.mValidBounds.min.as<NxVec3>();
 desc.validBounds.max = source.mValidBounds.max.as<NxVec3>();
 desc.wakeUpCounter = source.mWakeUpCounter;
 desc.windAcceleration = source.mWindAcceleration.as<NxVec3>(); 
}


void PrototypeFunctions::SoftBodyDescriptionToNxSoftBodyDesc(const SoftBodyDescription& source, NxSoftBodyDesc& desc)
{
 desc.attachmentResponseCoefficient = source.mAttachmentResponseCoefficient;
 desc.attachmentTearFactor = source.mAttachmentTearFactor;
 desc.softBodyMesh = source.mMesh->getAsSoftBody();
 desc.collisionGroup = source.mCollisionGroup;
 desc.collisionResponseCoefficient = source.mCollisionResponseCoefficient;
 desc.compartment = 0;
 desc.dampingCoefficient = source.mDampingCoefficient;
 desc.density = source.mDensity;
 desc.externalAcceleration = source.mExternalAcceleration.as<NxVec3>();
 desc.flags = source.mFlags;
 desc.forceFieldMaterial = source.mForceFieldMaterial;
 desc.friction = source.mFriction;
 desc.fromFluidResponseCoefficient = source.mFromFluidResponseCoefficient;
 desc.globalPose.setRowMajor44(source.mGlobalPose.ptr());
 desc.groupsMask.bits0 = source.mGroupsMask.w;
 desc.groupsMask.bits1 = source.mGroupsMask.x;
 desc.groupsMask.bits2 = source.mGroupsMask.y;
 desc.groupsMask.bits3 = source.mGroupsMask.z;
 desc.minAdhereVelocity = source.mMinAdhereVelocity;
 desc.name = source.mName.c_str();
 desc.particleRadius = source.mParticleRadius;
 desc.sleepLinearVelocity = source.mSleepLinearVelocity;
 desc.solverIterations = source.mSolverIterations;
 desc.stretchingStiffness = source.mStretchingStiffness;
 desc.tearFactor = source.mTearFactor;
 desc.toFluidResponseCoefficient = source.mToFluidResponseCoefficient;
 desc.validBounds.min = source.mValidBounds.min.as<NxVec3>();
 desc.validBounds.max = source.mValidBounds.max.as<NxVec3>();
 desc.volumeStiffness = source.mVolumeStiffness;
 desc.wakeUpCounter = source.mWakeUpCounter;
 
}
                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

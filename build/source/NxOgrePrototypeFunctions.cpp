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
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreSceneDescription.h"
#include "NxOgreFunctions.h"
#include "NxOgreWorldPrototype.h"
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


void PrototypeFunctions::SceneDescriptionToNxSceneDesc(const NxOgre::SceneDescription& description, NxSceneDesc& physx_description)
{
 physx_description.backgroundThreadCount      = description.mBackgroundThreadsCount;
 physx_description.backgroundThreadMask       = description.mBackgroundThreadsMask;
 physx_description.backgroundThreadPriority   = NxThreadPriority(int(description.mBackgroundThreadsPriority));
 physx_description.boundsPlanes               = description.mBoundsPlane;
 physx_description.bpType                     = NxBroadPhaseType(int(description.mBroadPhaseType));
 physx_description.dynamicStructure           = NxPruningStructure(int(description.mPruningDynamicStructure));
 physx_description.dynamicTreeRebuildRateHint = description.mDynamicTreeBuildRateHint;
 physx_description.flags                      = description.mFlags;
 Functions::XYZ<Vec3, NxVec3>          ( description.mGravity, physx_description.gravity );
 physx_description.internalThreadCount        = description.mWorkerThreadsCount;
 physx_description.maxIter                    = description.mMaxSubSteps;
 physx_description.maxTimestep                = description.mMaxTimeStep;
 physx_description.nbGridCellsX               = description.mBroadPhaseNbCellsX;
 physx_description.nbGridCellsY               = description.mBroadPhaseNbCellsY;
 physx_description.simThreadMask              = description.mSimulationThreadMask;
 physx_description.simThreadPriority          = NxThreadPriority(int(description.mSimulationThreadPriority));
 physx_description.simThreadStackSize         = description.mSimulationThreadStackSize;
 physx_description.simType                    = description.mUseHardware == true ? NX_SIMULATION_HW : NX_SIMULATION_SW;
 physx_description.solverBatchSize            = description.mSolverBatchSize;
 physx_description.staticStructure            = NxPruningStructure(int(description.mPruningStaticStructure));
 physx_description.subdivisionLevel           = description.mBoundsSubdivisionLevel;
 physx_description.threadMask                 = description.mWorkerThreadsMask;
 physx_description.timeStepMethod             = NxTimeStepMethod(int(description.mTimeStepMethod));
 physx_description.upAxis                     = int(description.mBoundsUpAxis);
 if (physx_description.upAxis == Enums::NoAxis)
  physx_description.upAxis = 0;
 physx_description.workerThreadPriority       = NxThreadPriority(int(description.mWorkerThreadsPriority));
 physx_description.workerThreadStackSize      = description.mWorkerThreadsStackSize;
}

void PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(const RigidBodyDescription& description, NxActorDesc& actor_description, NxBodyDesc& body_description)
{
 
 if (description.mCompartment != NULL && description.mCompartment->getType() == Enums::CompartmentType_RigidBody)
  actor_description.compartment = description.mCompartment->getCompartment();
 
 actor_description.contactReportFlags = description.mContactReportFlags;
 actor_description.density = description.mDensity;
 actor_description.dominanceGroup = description.mDominanceGroup;
 actor_description.flags = description.mActorFlags;
 actor_description.forceFieldMaterial = description.mForceFieldMaterial;
 actor_description.group = description.mGroup;
 actor_description.name = description.mName.c_str();
 
 body_description.angularDamping = description.mAngularDamping;
 Functions::XYZ<Vec3, NxVec3>(description.mAngularVelocity, body_description.angularVelocity);
 body_description.CCDMotionThreshold = description.mCCDMotionThreshold;
 body_description.contactReportThreshold = description.mContactReportThreshold;
 body_description.flags = description.mBodyFlags;
 body_description.linearDamping = description.mLinearDamping;
 Functions::XYZ<Vec3, NxVec3>(description.mLinearVelocity, body_description.linearVelocity);
 body_description.mass = description.mMass;
 body_description.massLocalPose.setColumnMajor44(description.mMassLocalPose.ptr());
 Functions::XYZ<Vec3, NxVec3>(description.mMassSpaceInertia, body_description.massSpaceInertia);
 body_description.maxAngularVelocity = description.mMaxAngularVelocity;
 body_description.sleepAngularVelocity = description.mSleepAngularVelocity;
 body_description.sleepDamping = description.mSleepDamping;
 body_description.sleepEnergyThreshold = description.mSleepEnergyThreshold;
 body_description.sleepLinearVelocity = description.mSleepLinearVelocity;
 body_description.solverIterationCount = description.mSolverIterationCount;
 body_description.wakeUpCounter = description.mWakeUpCounter;
 actor_description.body = &body_description;

 
}

void PrototypeFunctions::RigidBodyDescriptionToNxActorDesc(const RigidBodyDescription& description, NxActorDesc& actor_description)
{
 
 if (description.mCompartment != NULL && description.mCompartment->getType() == Enums::CompartmentType_RigidBody)
  actor_description.compartment = description.mCompartment->getCompartment();
 
 actor_description.contactReportFlags = description.mContactReportFlags;
 actor_description.density = description.mDensity;
 actor_description.dominanceGroup = description.mDominanceGroup;
 actor_description.flags = description.mActorFlags;
 actor_description.forceFieldMaterial = description.mForceFieldMaterial;
 actor_description.group = description.mGroup;
 actor_description.name = description.mName.c_str();
 
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

 desc.driveAngularVelocity = source.mDriveAngularVelocity.as<NxVec3>();
 desc.driveLinearVelocity = source.mDriveLinearVelocity.as<NxVec3>();
 desc.driveOrientation = source.mDriveOrientation.as<NxQuat>();
 desc.drivePosition = source.mDrivePosition.as<NxVec3>();

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

                                                                                       

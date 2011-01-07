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
#include "NxOgreShape.h"
#include "NxOgreBox.h"

#include "NxOgreMaterialDescription.h"
#include "NxOgreMesh.h"

#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreDistanceJointDescription.h"
#include "NxOgreD6JointDescription.h"

#include "NxOgreClothDescription.h"
#include "NxOgreSoftBodyDescription.h"

#include "NxOgreForceFieldLinearKernelDescription.h"

#include "NxOgreCompartment.h"

#include "NxPhysics.h"



namespace NxOgre
{



namespace Functions
{



void PrototypeFunctions::JointDescriptionToNxJointDescription(const JointDescription& source, NxJointDesc& desc)
{
 desc.jointFlags = source.mJointFlags;
 desc.localAnchor[0] = source.mLocalAnchor[0].as<NxVec3>();
 desc.localAnchor[1] = source.mLocalAnchor[1].as<NxVec3>();
 desc.localAxis[0]  = source.mLocalAxis[0].as<NxVec3>();
 desc.localAxis[1]  = source.mLocalAxis[1].as<NxVec3>();
 desc.localNormal[0] = source.mLocalNormal[0].as<NxVec3>();
 desc.localNormal[1] = source.mLocalNormal[1].as<NxVec3>();
}


void PrototypeFunctions::SphericalJointDescriptionToNxSphericalJointDescription(const SphericalJointDescription& source, NxSphericalJointDesc& desc)
{
 desc.flags = source.mSphericalJointFlags;
 desc.jointFlags = source.mJointFlags;
 SpringDescriptionToNxSpringDesc(source.mJointSpring, desc.jointSpring);
 desc.localAnchor[0] = source.mLocalAnchor[0].as<NxVec3>();
 desc.localAnchor[1] = source.mLocalAnchor[1].as<NxVec3>();
 desc.localAxis[0]   = source.mLocalAxis[0].as<NxVec3>();
 desc.localAxis[1]   = source.mLocalAxis[1].as<NxVec3>();
 desc.localNormal[0] = source.mLocalNormal[0].as<NxVec3>();
 desc.localNormal[1] = source.mLocalNormal[1].as<NxVec3>();
 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 desc.projectionDistance = source.mProjectionDistance;
 desc.projectionMode = NxJointProjectionMode(int(source.mProjectionMode));
#if NxOgreMinimalPhysXVersion >= 281
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor; // Not in 2.8.0
#endif
 desc.swingAxis = source.mSwingAxis.as<NxVec3>();
 JointLimitDescriptionToNxJointLimitDesc(source.mSwingLimit, desc.swingLimit);
 SpringDescriptionToNxSpringDesc(source.mSwingSpring, desc.swingSpring);
 JointLimitDescriptionToNxJointLimitDesc(source.mTwistLimit.first, desc.twistLimit.low);
 JointLimitDescriptionToNxJointLimitDesc(source.mTwistLimit.second, desc.twistLimit.high);
 SpringDescriptionToNxSpringDesc(source.mTwistSpring, desc.twistSpring);

#if NxOgreMinimalPhysXVersion >= 281
 desc.useAccelerationSpring = int(source.mSpringType); // Not in 2.8.0
#endif

}

void PrototypeFunctions::RevoluteJointDescriptionToNxRevoluteJointDescription(const RevoluteJointDescription& source, NxRevoluteJointDesc& desc)
{
 desc.flags = source.mRevoluteJointFlags;
 desc.jointFlags = source.mJointFlags;
 JointLimitDescriptionToNxJointLimitDesc(source.mLimit.first, desc.limit.low);
 JointLimitDescriptionToNxJointLimitDesc(source.mLimit.second, desc.limit.high);
 desc.localAnchor[0] = source.mLocalAnchor[0].as<NxVec3>();
 desc.localAnchor[1] = source.mLocalAnchor[1].as<NxVec3>();
 desc.localAxis[0]   = source.mLocalAxis[0].as<NxVec3>();
 desc.localAxis[1]   = source.mLocalAxis[1].as<NxVec3>();
 desc.localNormal[0] = source.mLocalNormal[0].as<NxVec3>();
 desc.localNormal[1] = source.mLocalNormal[1].as<NxVec3>();
 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 MotorDescriptionToNxMotorDesc(source.mMotor, desc.motor);
 desc.projectionAngle = source.mProjectionAngle;
 desc.projectionDistance = source.mProjectionDistance;
 desc.projectionMode = NxJointProjectionMode(int(source.mProjectionMode));
#if NxOgreMinimalPhysXVersion >= 281
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor; // Not in 2.8.0
 desc.useAccelerationSpring = int(source.mSpringType); // Not in 2.8.0
#endif
}

void PrototypeFunctions::DistanceJointDescriptionToNxDistanceJointDescription(const DistanceJointDescription& source, NxDistanceJointDesc& desc)
{
 
 desc.flags = source.mDistanceJointFlags;
 desc.jointFlags = source.mJointFlags;
 desc.localAnchor[0] = source.mLocalAnchor[0].as<NxVec3>();
 desc.localAnchor[1] = source.mLocalAnchor[1].as<NxVec3>();
 desc.localAxis[0] = source.mLocalAxis[0].as<NxVec3>();
 desc.localAxis[1] = source.mLocalAxis[1].as<NxVec3>();
 desc.localNormal[0] = source.mLocalNormal[0].as<NxVec3>();
 desc.localNormal[1] = source.mLocalNormal[1].as<NxVec3>();
 desc.maxDistance = source.mMaxDistance;
 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 desc.minDistance = source.mMinDistance;
#if NxOgreMinimalPhysXVersion >= 281
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor; // Not in 2.8.0
 desc.spring.damper = source.mSpring.mDamper; // Not in 2.8.0
 desc.spring.spring = source.mSpring.mSpring;
 desc.spring.targetValue = source.mSpring.mTargetValue;
#endif
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

 desc.localAnchor[0] = source.mLocalAnchor[0].as<NxVec3>();
 desc.localAnchor[1] = source.mLocalAnchor[1].as<NxVec3>();
 desc.localAxis[0]   = source.mLocalAxis[0].as<NxVec3>();
 desc.localAxis[1]   = source.mLocalAxis[1].as<NxVec3>();
 desc.localNormal[0] = source.mLocalNormal[0].as<NxVec3>();
 desc.localNormal[1] = source.mLocalNormal[1].as<NxVec3>();

 desc.maxForce = source.mMaxForce;
 desc.maxTorque = source.mMaxTorque;
 desc.slerpDrive.damping = source.mSlerpDrive.mDamping;
 desc.slerpDrive.driveType = source.mSlerpDrive.mDriveType;
 desc.slerpDrive.forceLimit = source.mSlerpDrive.mForceLimit;
 desc.slerpDrive.spring = source.mSlerpDrive.mSpring;
#if NxOgreMinimalPhysXVersion >= 281
 desc.solverExtrapolationFactor = source.mSolverExtrapolationFactor; // Not in 2.8.0
#endif

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
#if NxOgreMinimalPhysXVersion >= 281
 desc.useAccelerationSpring = int(source.mSpringType); // Not in 2.8.0
#endif
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

 if (source.mCompartment != 0)
  desc.compartment = source.mCompartment->getCompartment();
 else
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

void PrototypeFunctions::ForceFieldLinearKernelDescriptionToNxForceFieldLinearKernelDesc(const ForceFieldLinearKernelDescription& desc, NxForceFieldLinearKernelDesc& description)
{
 description.constant = desc.mConstant.as<NxVec3>();
 description.falloffLinear = desc.mFalloffLinear.as<NxVec3>();
 description.falloffQuadratic = desc.mFalloffQuadratic.as<NxVec3>();
 description.noise = desc.mNoise.as<NxVec3>();
 description.positionMultiplier.setRowMajor(desc.mPositionMultiplier.ptr());
 description.positionTarget = desc.mPositionTarget.as<NxVec3>();
 description.torusRadius = desc.mTorusRadius;
 description.velocityMultiplier.setRowMajor(desc.mVelocityMultiplier.ptr());
 description.velocityTarget = desc.mVelocityTarget.as<NxVec3>();
}



}



} // namespace NxOgre



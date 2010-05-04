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
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreCompartment.h"

#include "NxPhysics.h"


                                                                                       

namespace NxOgre
{

                                                                                       

RigidBodyDescription::RigidBodyDescription(void)
{
 reset();
}

void RigidBodyDescription::to_nxactor(NxActorDesc* actor) const
{
 
 if (mCompartment != 0)
  actor->compartment = mCompartment->getCompartment();
 else
  actor->compartment = 0;
 
 actor->contactReportFlags = mContactReportFlags;
 actor->density = mDensity;
 actor->dominanceGroup = mDominanceGroup;
 actor->flags = mRigidbodyFlags.to_i();
 actor->forceFieldMaterial = mForceFieldMaterial;
 actor->group = mGroup;
 actor->name = mName.c_str();
 
}

void RigidBodyDescription::to_nxactor(NxActorDesc* actor, NxBodyDesc* body) const
{
 
 to_nxactor(actor);
 
 body->angularDamping = mAngularDamping;
 body->angularVelocity.set(mAngularVelocity.as<NxVec3>());
 body->CCDMotionThreshold = mCCDMotionThreshold;
 body->contactReportThreshold = mContactReportThreshold;
 body->flags = mDynamicRigidbodyFlags.to_i();
 body->linearDamping = mLinearDamping;
 body->linearVelocity.set(mLinearVelocity.as<NxVec3>());
 body->mass = mMass;
 body->massLocalPose.setRowMajor44(mMassLocalPose.ptr());
 body->massSpaceInertia.set(mMassSpaceInertia.as<NxVec3>());
 body->maxAngularVelocity = mMaxAngularVelocity;
 body->sleepAngularVelocity = mSleepAngularVelocity;
 body->sleepDamping = mSleepDamping;
 body->sleepEnergyThreshold = mSleepEnergyThreshold;
 body->sleepLinearVelocity = mSleepLinearVelocity;
 body->solverIterationCount = mSolverIterationCount;
 body->wakeUpCounter = mWakeUpCounter;
 
}

                                                                                       

} // namespace NxOgre

                                                                                       




// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

RigidBodyDescription::RigidBodyDescription(const RigidBodyDescription& other)
{
 other.copy_into(this);
}

RigidBodyDescription& RigidBodyDescription::operator=(const RigidBodyDescription& other)
{
 other.copy_into(this);
 return *this;
}

RigidBodyDescription* RigidBodyDescription::duplicate() const
{
 RigidBodyDescription* dup = new RigidBodyDescription();
 copy_into(dup);
 return dup;
}

void RigidBodyDescription::copy_into(RigidBodyDescription* other) const
{
 other->mAngularDamping = mAngularDamping;
 other->mAngularVelocity = mAngularVelocity;
 other->mAuxiliaryMirror = mAuxiliaryMirror;
 other->mCCDMotionThreshold = mCCDMotionThreshold;
 other->mCompartment = mCompartment;
 other->mContactReportFlags = mContactReportFlags;
 other->mContactReportThreshold = mContactReportThreshold;
 other->mDensity = mDensity;
 other->mDominanceGroup = mDominanceGroup;
 other->mDynamicRigidbodyFlags = mDynamicRigidbodyFlags;
 other->mForceFieldMaterial = mForceFieldMaterial;
 other->mGroup = mGroup;
 other->mInternalThreadCount = mInternalThreadCount;
 other->mLinearDamping = mLinearDamping;
 other->mLinearVelocity = mLinearVelocity;
 other->mMass = mMass;
 other->mMassLocalPose = mMassLocalPose;
 other->mMassSpaceInertia = mMassSpaceInertia;
 other->mMaxAngularVelocity = mMaxAngularVelocity;
 other->mName = mName;
 other->mRigidbodyFlags = mRigidbodyFlags;
 other->mSleepAngularVelocity = mSleepAngularVelocity;
 other->mSleepDamping = mSleepDamping;
 other->mSleepEnergyThreshold = mSleepEnergyThreshold;
 other->mSleepLinearVelocity = mSleepLinearVelocity;
 other->mSolverIterationCount = mSolverIterationCount;
 other->mWakeUpCounter = mWakeUpCounter;
}

void RigidBodyDescription::reset()
{
 mAngularDamping = 0.05;
 mAngularVelocity.zero();
 mAuxiliaryMirror = false;
 mCCDMotionThreshold = 0;
 mCompartment = NULL;
 mContactReportFlags = 0;
 mContactReportThreshold = NxOgreRealMax;
 mDensity = 0;
 mDominanceGroup = 0;
 mDynamicRigidbodyFlags.reset();;
 mForceFieldMaterial = 0;
 mGroup = 0;
 mInternalThreadCount = 0;
 mLinearDamping = 0.0;
 mLinearVelocity.zero();
 mMass = 1.0;
 mMassLocalPose.identity();
 mMassSpaceInertia.zero();
 mMaxAngularVelocity = -1.0;
 mName.clear();
 mSleepAngularVelocity = -1.0;
 mSleepDamping = 0;
 mSleepEnergyThreshold = -1.0;
 mSleepLinearVelocity = -1.0;
 mSolverIterationCount = 4;
 mWakeUpCounter = 0.04;
}

bool RigidBodyDescription::valid() const
{
 // mAngularDamping cannot be negative
 if ((mAngularDamping < 0.0))
  return false;
 // mCCDMotionThreshold cannot be negative
 if ((mCCDMotionThreshold < 0.0))
  return false;
 // mContactReportThreshold cannot be negative
 if ((mContactReportThreshold < 0.0))
  return false;
 // mDensity cannot be negative and/or mass cannot non-zero
 if ((mDensity < 0.0) || (mDensity > 0.0 && mMass > 0.0))
  return false;
 // mLinearDamping cannot be negative
 if ((mLinearDamping < 0.0))
  return false;
 // mMass cannot be negative and/or density cannot non-zero
 if ((mMass < 0.0) || (mMass > 0.0 && mDensity > 0.0))
  return false;
 // mSolverIterationCount cannot be less than 1 or more than 255
 if ((mSolverIterationCount < 1) || (mSolverIterationCount > 255))
  return false;
 // mWakeUpCounter cannot be negative
 if ((mWakeUpCounter < 0.0))
  return false;

 return true;
}

void RigidBodyDescription::inspect() const
{
 std::cout << "RigidBodyDescription => {\n";
 std::cout << "  mAngularDamping => '" << mAngularDamping << "'\n";
 std::cout << "  mAngularVelocity => '" << mAngularVelocity << "'\n";
 std::cout << "  mAuxiliaryMirror => '" << mAuxiliaryMirror << "'\n";
 std::cout << "  mCCDMotionThreshold => '" << mCCDMotionThreshold << "'\n";
 std::cout << "  mCompartment => '" << mCompartment << "'\n";
 std::cout << "  mContactReportFlags => '" << mContactReportFlags << "'\n";
 std::cout << "  mContactReportThreshold => '" << mContactReportThreshold << "'\n";
 std::cout << "  mDensity => '" << mDensity << "'\n";
 std::cout << "  mDominanceGroup => '" << mDominanceGroup << "'\n";
 std::cout << "  mDynamicRigidbodyFlags => '" << mDynamicRigidbodyFlags << "'\n";
 std::cout << "  mForceFieldMaterial => '" << mForceFieldMaterial << "'\n";
 std::cout << "  mGroup => '" << mGroup << "'\n";
 std::cout << "  mInternalThreadCount => '" << mInternalThreadCount << "'\n";
 std::cout << "  mLinearDamping => '" << mLinearDamping << "'\n";
 std::cout << "  mLinearVelocity => '" << mLinearVelocity << "'\n";
 std::cout << "  mMass => '" << mMass << "'\n";
 std::cout << "  mMassLocalPose => '" << mMassLocalPose << "'\n";
 std::cout << "  mMassSpaceInertia => '" << mMassSpaceInertia << "'\n";
 std::cout << "  mMaxAngularVelocity => '" << mMaxAngularVelocity << "'\n";
 std::cout << "  mName => '" << mName << "'\n";
 std::cout << "  mRigidbodyFlags => '" << mRigidbodyFlags << "'\n";
 std::cout << "  mSleepAngularVelocity => '" << mSleepAngularVelocity << "'\n";
 std::cout << "  mSleepDamping => '" << mSleepDamping << "'\n";
 std::cout << "  mSleepEnergyThreshold => '" << mSleepEnergyThreshold << "'\n";
 std::cout << "  mSleepLinearVelocity => '" << mSleepLinearVelocity << "'\n";
 std::cout << "  mSolverIterationCount => '" << mSolverIterationCount << "'\n";
 std::cout << "  mWakeUpCounter => '" << mWakeUpCounter << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "RigidBodyDescription-e94c041377ba1096a6cfef32ba15503c"


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

                                                                                       

namespace NxOgre
{

                                                                                       

RigidBodyDescription::RigidBodyDescription(void)
{
 reset();
}

void RigidBodyDescription::reset(void)
{
 mActorFlags = 0;
 mAngularDamping = Real(0.05);
 mAngularVelocity = Vec3::ZERO;
 mBodyFlags = Enums::BodyFlags_Visualisation;
 mCCDMotionThreshold = Real(0.0);
 mCompartment = 0;
 mContactReportThreshold = NxOgreRealMax;
 mDensity = Real(0.0);
 mDominanceGroup = 0;
 mForceFieldMaterial = 0;
 mGroup = 0;
 mInternalThreadCount = 0;
 mLinearDamping = Real(0.0);
 mLinearVelocity = Vec3::ZERO;
 mMass = Real(1.0);
 mMassLocalPose = Matrix44::IDENTITY;
 mMassSpaceInertia = Vec3::ZERO;
 mMaxAngularVelocity = Real(-1.0);
 mSleepAngularVelocity = Real(-1.0);
 mSleepDamping = Real(0.0);
 mSleepEnergyThreshold = Real(0.005);
 mSleepLinearVelocity = Real(-1.0);
 mSolverIterationCount = 4;
 mWakeUpCounter = Real(0.02);
}

void RigidBodyDescription::clone(RigidBodyDescription& target) const
{
 target.mActorFlags = mActorFlags;
 target.mAngularDamping = mAngularDamping;
 target.mAngularVelocity = mAngularVelocity;
 target.mBodyFlags = mBodyFlags;
 target.mCCDMotionThreshold = mCCDMotionThreshold;
 target.mCompartment = mCompartment;
 target.mContactReportThreshold = mContactReportThreshold;
 target.mDensity = mDensity;
 target.mDominanceGroup = mDominanceGroup;
 target.mForceFieldMaterial = mForceFieldMaterial;
 target.mGroup = mGroup;
 target.mInternalThreadCount = mInternalThreadCount;
 target.mLinearDamping = mLinearDamping;
 target.mLinearVelocity = mLinearVelocity;
 target.mMass = mMass;
 target.mMassLocalPose = mMassLocalPose;
 target.mMassSpaceInertia = mMassSpaceInertia;
 target.mMaxAngularVelocity = mMaxAngularVelocity;
 target.mSleepAngularVelocity = mSleepAngularVelocity;
 target.mSleepDamping = mSleepDamping;
 target.mSleepEnergyThreshold = mSleepEnergyThreshold;
 target.mSleepLinearVelocity = mSleepLinearVelocity;
 target.mSolverIterationCount = mSolverIterationCount;
 target.mWakeUpCounter = mWakeUpCounter;
}

bool RigidBodyDescription::valid(void)
{
  if (mDensity < Real(0))
   return false;

  if (mMass < Real(0))
   return false;

  if (mWakeUpCounter < Real(0))
   return false;

  if (mLinearDamping < Real(0))
   return false;

  if (mAngularDamping < Real(0))
   return false;

  if (mCCDMotionThreshold < Real(0))
   return false;

  if (mSolverIterationCount < 1)
   return false;

  if (mSolverIterationCount > 255) 
   return false;

  if (mContactReportThreshold < Real(0)) //must be nonnegative
   return false;

  if (!(mType < Enums::RigidBodyType_SceneGeometry) && mDominanceGroup) //only dynamic actors may have a nonzero dominance group.
   return false;

 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

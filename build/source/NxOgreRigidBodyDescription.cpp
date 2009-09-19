/** File: NxOgreRigidBodyDescription.cpp
    Created on: 7-Nov-08
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
 mMassLocalPose = Matrix44_Identity;
 mMassSpaceInertia = Vec3::ZERO;
 mMaxAngularVelocity = Real(-1.0);
 mSleepAngularVelocity = Real(-1.0);
 mSleepDamping = Real(0.0);
 mSleepEnergyThreshold = Real(0.005);
 mSleepLinearVelocity = Real(-1.0);
 mSolverIterationCount = 4;
 mWakeUpCounter = Real(0.02);
 mVolumeCollisionType = Enums::VolumeCollisionType_None;
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

  if (!(mType < Enums::RigidBodyType_Geometry) && mDominanceGroup) //only dynamic actors may have a nonzero dominance group.
   return false;

 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

/** File: NxOgreSoftBodyDescription.cpp
    Created on: 31-May-09
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
#include "NxOgreSoftBodyDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

SoftBodyDescription::SoftBodyDescription(void)
{
 reset();
}

void SoftBodyDescription::reset(void)
{
 mMesh = 0;
 mGlobalPose.identity();
 mParticleRadius = Real(0.1);
 mVolumeStiffness = Real(1.0);
 mDensity = Real(1.0);
 mStretchingStiffness = Real(1.0);
 mDampingCoefficient = Real(0.5);
 mFriction = Real(0.5);
 mTearFactor = Real(1.5);
 mAttachmentTearFactor = Real(1.5);
 mAttachmentResponseCoefficient = Real(0.2);
 mCollisionResponseCoefficient = Real(0.2);
 mToFluidResponseCoefficient = Real(1.0);
 mFromFluidResponseCoefficient = Real(1.0);
 mMinAdhereVelocity = Real(1.0);
 mFlags = 0; //Enums::SoftBodyFlags_Gravity;
 mSolverIterations = 5;
 mWakeUpCounter = Real(0.4);
 mSleepLinearVelocity = Real(-1.0);
 mCollisionGroup = 0;
 mForceFieldMaterial = 0;
 mExternalAcceleration.zero();
 mGroupsMask.w = 0;
 mGroupsMask.x = 0;
 mGroupsMask.y = 0;
 mGroupsMask.z = 0;
 mValidBounds.empty();
}

bool SoftBodyDescription::valid(void)
{

 return true; /// TEMP!
}

                                                                                       

} // namespace NxOgre

                                                                                       

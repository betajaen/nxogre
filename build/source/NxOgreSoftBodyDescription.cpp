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
#include "NxOgreSoftBodyDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

SoftBodyDescription::SoftBodyDescription()
{
 reset();
}

void SoftBodyDescription::reset()
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

bool SoftBodyDescription::valid()
{

 return true; /// TEMP!
}

                                                                                       

} // namespace NxOgre

                                                                                       

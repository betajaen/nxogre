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
#include "NxOgreFluidDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FluidDescription::FluidDescription(void)
{
 reset();
}

void FluidDescription::reset(void)
{
 mMaxParticles                       = 32767;
 mNbReserveParticles                 = 0;
 mRestParticlesPerMetre              = 50.0f;
 mRestDensity                        = 1000.0f;
 mKernelRadiusMultiplier             = 1.2f;
 mMotionLimitMultiplier              = 3.0f * mKernelRadiusMultiplier;
 mCollisionDistanceMultiplier        = 0.1f * mKernelRadiusMultiplier;
 mPacketSizeMultiplier               = 16;
 mStiffness                          = 20.0f;
 mViscosity                          = 6.0f;
 mSurfaceTension                     = 0.0f;
 mDamping                            = 0.0f;
 mFadeInTime                         = 0.0f;
 mExternalAcceleration               . zero();
 mProjectionPlane.mDistance          = 0;
 mProjectionPlane.mNormal            . set(0.0f, 0.0f, 1.0f);
 mRestitutionForStaticShapes         = 0.5f;
 mDynamicFrictionForStaticShapes     = 0.05f;
 mStaticFrictionForStaticShapes      = 0.05f;
 mAttractionForStaticShapes          = 0.0f;
 mRestitutionForDynamicShapes        = 0.5f;
 mDynamicFrictionForDynamicShapes    = 0.5f;
 mStaticFrictionForDynamicShapes     = 0.5f;
 mAttractionForDynamicShapes         = 0.0f;
 mCollisionResponseCoefficient       = 0.2f;
 mSimulationMethod                   = Enums::FluidSimulationMethod_SPH;
 mCollisionMethod                    = Enums::FluidCollisionMethod_Static | Enums::FluidCollisionMethod_Dynamic;
 mCollisionGroup                     = 0;
 mForceFieldMaterial                 = 0;
 mGroupsMask.w                       = 0;
 mGroupsMask.x                       = 0;
 mGroupsMask.y                       = 0;
 mGroupsMask.z                       = 0;
 mFlags                              = Enums::FluidFlags_Visualisation | Enums::FluidFlags_Enabled | Enums::FluidFlags_Hardware;
 mCompartment                        = NULL;
}

bool FluidDescription::valid(void)
{
 if (mKernelRadiusMultiplier < 1.0f)
  return false;
 if (mRestDensity <= 0.0f)
  return false;
 if (mRestParticlesPerMetre <= 0.0f)
  return false;
 if (mPacketSizeMultiplier < 4)
  return false;
 if (mPacketSizeMultiplier & ( mPacketSizeMultiplier - 1 ) )
  return false;
 if (mMotionLimitMultiplier <= 0.0f)
  return false;
 if (mMotionLimitMultiplier > mPacketSizeMultiplier*mKernelRadiusMultiplier)
  return false;
 if (mCollisionDistanceMultiplier <= 0.0f)
  return false;
 if (mCollisionDistanceMultiplier > mPacketSizeMultiplier*mKernelRadiusMultiplier)
  return false;
 if (mStiffness <= 0.0f)
  return false;
 if (mViscosity <= 0.0f)
  return false;
 if (mSurfaceTension < 0.0f)
  return false;
 
 bool isNoInteraction = (mSimulationMethod & Enums::FluidSimulationMethod_NoParticleInteraction) > 0;
 bool isSPH = (mSimulationMethod & Enums::FluidSimulationMethod_SPH);
 bool isMixed = (mSimulationMethod & Enums::FluidSimulationMethod_MixedMode);
 
 if (mDamping < 0.0f) 
  return false;
 
 if (mFadeInTime < 0.0f)
  return false;
 
 if (mProjectionPlane.mNormal.isZero())
  return false;
 
 if (mDynamicFrictionForDynamicShapes < 0.0f || mDynamicFrictionForDynamicShapes > 1.0f)
  return false;
 
 if (mStaticFrictionForDynamicShapes < 0.0f || mStaticFrictionForDynamicShapes > 1.0f)
  return false;
 
 if (mRestitutionForDynamicShapes < 0.0f || mRestitutionForDynamicShapes > 1.0f)
  return false;
 
 if (mAttractionForDynamicShapes < 0.0f)
  return false;
 
 if (mDynamicFrictionForStaticShapes < 0.0f || mDynamicFrictionForStaticShapes > 1.0f)
  return false;
 
 if (mStaticFrictionForStaticShapes < 0.0f || mStaticFrictionForStaticShapes > 1.0f)
  return false;
 
 if (mRestitutionForStaticShapes < 0.0f || mRestitutionForStaticShapes > 1.0f)
  return false;
 
 if (mAttractionForStaticShapes < 0.0f)
  return false;
 
 if (mCollisionResponseCoefficient < 0.0f)
  return false;
 
 if (mMaxParticles >= (1<<16))
  return false;
 
 if (mMaxParticles < 1)
  return false;
 
 if (mNbReserveParticles >= mMaxParticles)
  return false;
 
 if (mCollisionGroup >= 32)
  return false;
 
 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

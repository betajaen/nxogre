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
#include "NxOgreFluidEmitterDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FluidEmitterDescription::FluidEmitterDescription(void)
{
 reset();
}

void FluidEmitterDescription::reset(void)
{
 mPose.identity();
 mFrameShape = 0;
 mType = Enums::FluidEmitterType_Pressure;
 mMaxParticles = 0;
 mShape = Enums::FluidEmitterShape_Rectangular;
 mDimensionX = 0.25f;
 mDimensionY = 0.25f;
 mRandomPosition.zero();
 mRandomAngle = 0.0f;
 mFluidSpeed = 1.0f;
 mRate = 100.0f;
 mParticleLifetime = 0.0f;
 mReplusionCoefficient = 1.0f;
 mFlags = Enums::FluidEmitterFlags_Enabled | Enums::FluidEmitterFlags_Visualisation | Enums::FluidEmitterFlags_AddBodyVelocity;
 
}

bool FluidEmitterDescription::valid(void)
{
 if (mDimensionX < 0.0f || mDimensionY < 0.0f)
  return false;
 
 if (mRandomPosition.x < 0 || mRandomPosition.y < 0 || mRandomPosition.z < 0)
  return false;

 if (mRandomAngle < 0.0f)
  return false;

 if (!(((mShape & Enums::FluidEmitterShape_Ellipse) > 0) ^ ((mShape & Enums::FluidEmitterShape_Rectangular) > 0)))
  return false;

 if (!(((mType & Enums::FluidEmitterType_FlowRate) > 0) ^ ((mType & Enums::FluidEmitterType_Pressure) > 0)))
  return false;

 if (mRate < 0.0f)
  return false;

 if (mFluidSpeed < 0.0f)
  return false;

 if (mParticleLifetime < 0.0f)
  return false;

 if (mReplusionCoefficient < 0.0f)
  return false;

 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

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
#include "NxOgreForceFieldLinearKernel.h"

#include "NxPhysics.h"
#include "NxOgrePrototypeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ForceFieldLinearKernel::ForceFieldLinearKernel(const ForceFieldLinearKernelDescription& desc, Scene* scene)
: ForceFieldKernel(desc.mName) 
{
 
 NxForceFieldLinearKernelDesc description;
 NxOgre::Functions::PrototypeFunctions::ForceFieldLinearKernelDescriptionToNxForceFieldLinearKernelDesc(desc, description);
 description.name = mName.c_str();
 
 
}

ForceFieldLinearKernel::~ForceFieldLinearKernel(void)
{
}


void ForceFieldLinearKernel::saveToDescription(ForceFieldLinearKernelDescription& description)
{
 NxForceFieldLinearKernelDesc desc;
 mKernel->saveToDesc(desc);
 description.mConstant.from<NxVec3>(desc.constant);
 description.mFalloffLinear.from<NxVec3>(desc.falloffLinear);
 description.mFalloffQuadratic.from<NxVec3>(desc.falloffQuadratic);
 description.mName = String(desc.name);
 description.mNoise.from<NxVec3>(desc.noise);
 desc.positionMultiplier.getRowMajor(description.mPositionMultiplier.ptr());
 description.mTorusRadius = desc.torusRadius;
 desc.velocityMultiplier.getRowMajor(description.mVelocityMultiplier.ptr());
 description.mVelocityTarget.from<NxVec3>(desc.velocityTarget);

}

String ForceFieldLinearKernel::to_s() const
{
 return "ForceFieldLinearKernel";
}

                                                                                       

} // namespace NxOgre

                                                                                       

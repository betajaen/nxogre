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
#include "NxOgreJointDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

JointDescription::JointDescription(void)
{
 reset();
}

JointDescription::~JointDescription(void)
{
}

void JointDescription::reset(void)
{
 for (unsigned int i = 0; i < 2;i ++)
 {
  mLocalAxis[i].set(0,0,1);
  mLocalNormal[i].set(1,0,0);
  mLocalAnchor[i].zero();
 }
 mMaxForce = NxOgreRealMax;
 mMaxTorque = NxOgreRealMax;
 mSolverExtrapolationFactor = 1.0f;
 mSpringType = Enums::JointSpringType_Force;
 mJointFlags = Enums::JointFlag_Visualisation;
}

bool JointDescription::isValid(void) const
{
 return true; // temp.
}

                                                                                       

} // namespace NxOgre

                                                                                       

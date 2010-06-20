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
#include "NxOgreTimeStep.h"
#include "NxOgreScene.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

TimeStep::TimeStep(NxOgre::Scene* scene)
:
  mMaxTimeStep(0),
  mSubSteps(0),
  mMaxIterator(0),
  mAlpha(0),
  mModified(0),
  mAccumulator(0),
  mMethod(0)
{
 NxTimeStepMethod m;
 scene->getScene()->getTiming(mMaxTimeStep, mMaxIterator, m, &mSubSteps);
 mMethod = (int) mMethod;
}

TimeStep::~TimeStep()
{
}


FixedTimeStep::FixedTimeStep(Scene* scene)
: TimeStep(scene)
{
}

void FixedTimeStep::calculate(float deltaTime)
{
 
 mActual = deltaTime;
 mAccumulator += deltaTime;
 mModified = 0;
 
 while(mAccumulator >= mMaxTimeStep)
 {
  mModified += mMaxTimeStep;
  mAccumulator -= mMaxTimeStep;
 }
 
 mAlpha = mAccumulator / mMaxTimeStep;
 
}

float TimeStep::getMaxTimeStep() const
{
 return mMaxTimeStep;
}

unsigned int TimeStep::getSubSteps() const
{
 return mSubSteps;
}

unsigned int TimeStep::getMaxIterator() const
{
 return mMaxIterator;
}

float TimeStep::getAlpha() const
{
 return mAlpha;
}

float TimeStep::getModified() const
{
 return mModified;
}

float TimeStep::getAccumulator() const
{
 return mAccumulator;
}

float TimeStep::getActual() const
{
 return mActual;
}

                                                                                       

} // namespace NxOgre

                                                                                       

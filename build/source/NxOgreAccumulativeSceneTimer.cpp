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
#include "NxOgreAccumulativeSceneTimer.h"
#include "NxOgreScene.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

AccumulativeSceneTimer::AccumulativeSceneTimer(Scene* scene, Real maxTime, Real expectedTime)
: SceneTimer(scene, maxTime, expectedTime), mAccumulator(0)
{
}

AccumulativeSceneTimer::~AccumulativeSceneTimer(void)
{
}

void AccumulativeSceneTimer::simulate(float user_deltaTime)
{
 
 if (mScene->isWritable() == false)
  return;
 
 if (user_deltaTime > mMaxTime)
  user_deltaTime = mMaxTime;
 
 mAccumulator += user_deltaTime;
 
 TimeStep& ts = mParent->getTimeStep();
 ts.mActual = user_deltaTime;
 ts.mSubSteps = 0;
 
 while (mAccumulator >= mExpectedTime)
 {
  ts.mSubSteps++;
  mScene->simulate(mExpectedTime);
  mScene->flushStream();
  mScene->fetchResults(NX_RIGID_BODY_FINISHED, true);
  mAccumulator -= mExpectedTime;
 }
 
 ts.mAlpha = mAccumulator / mExpectedTime;
 ts.mModified = mExpectedTime;
 
}

bool AccumulativeSceneTimer::hasResults(void) const
{
 return true;// mScene->checkResults(NX_RIGID_BODY_FINISHED);
}

void AccumulativeSceneTimer::fetchResults(void) const
{
}



                                                                                       

} // namespace NxOgre

                                                                                       

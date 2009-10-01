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
#include "NxOgreScene.h"
#include "NxOgreFixedSceneTimer.h"
#include "NxOgreTimer.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FixedSceneTimer::FixedSceneTimer(Scene* scene, Real maxTime, Real expectedTime)
: SceneTimer(scene, maxTime, expectedTime),
  mMaxTimeStep(1.0f / 60.0f),
  mOldTime(0.0f),
  mAccumulator(0.0f),
  mTimer()
{
 mScene->setTiming(mMaxTimeStep / 8.0f, 8, NX_TIMESTEP_FIXED);
 TimeStep& ts = mParent->getTimeStep();
 ts.mAlpha = 1.0f;
 ts.mModified = mMaxTimeStep;
 ts.mSubSteps = 8;
}

FixedSceneTimer::~FixedSceneTimer(void)
{
}

void FixedSceneTimer::simulate(float user_deltaTimer)
{
 
 float now = mTimer.now();
 float deltaTime = now - mOldTime;
 mOldTime = now;
 
 // Go ahead PhysX.
 mScene->simulate(deltaTime);
 mScene->flushStream();

 // Calculate how much time PhysX did process.
 mAccumulator += deltaTime;

 TimeStep& ts = mParent->getTimeStep();

 for (unsigned int i=0; i < ts.mSubSteps;i++)
  if (mAccumulator <= mMaxTimeStep)
   break;
  else
   mAccumulator -= mExpectedTime;

 ts.mAlpha = mAccumulator / mMaxTimeStep;
 ts.mModified = mExpectedTime;

 // We probably simulated so in goes.
 mTimerMode = Enums::TimerMode_Simulating;
 ts.mActual = deltaTime;
 
}

bool FixedSceneTimer::hasResults(void) const
{
 return mScene->checkResults(NX_RIGID_BODY_FINISHED, false);
}

void FixedSceneTimer::fetchResults(void)
{
 mScene->fetchResults(NX_RIGID_BODY_FINISHED, true);
 mTimerMode = Enums::TimerMode_FetchedResults;
}



                                                                                       

} // namespace NxOgre

                                                                                       

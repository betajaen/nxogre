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

                                                                                       

FixedSceneTimer::FixedSceneTimer(Scene* scene, Real maxTime)
: SceneTimer(scene, maxTime),
  mTimeStep(scene)
{
}

FixedSceneTimer::~FixedSceneTimer(void)
{
}

void FixedSceneTimer::simulate(float dt)
{
 
 float deltaTime = dt; //mTimer.nowReset();
 
 // Go ahead PhysX.
 mScene->simulate(deltaTime);
 mScene->flushStream();
 
 mTimeStep.calculate(deltaTime);
 
 // We probably simulated so in goes.
 mTimerMode = Enums::TimerMode_Simulating;
 
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

const TimeStep&  FixedSceneTimer::getTimeStep() const
{
 return mTimeStep;
}

                                                                                       

} // namespace NxOgre

                                                                                       

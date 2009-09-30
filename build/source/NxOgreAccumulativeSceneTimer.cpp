/** File: NxOgreXXX.cpp
    Created on: X-XXX-XX
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
#include "NxOgreAccumulativeSceneTimer.h"
#include "NxOgreScene.h"
#include "NxOgreTime.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

AccumulativeSceneTimer::AccumulativeSceneTimer(Scene* scene, Real maxTime, Real expectedTime)
: SceneTimer(scene, maxTime, expectedTime), mOldTime(0.0f), mAccumulator(0.0f)
{
}

AccumulativeSceneTimer::~AccumulativeSceneTimer(void)
{
}

void AccumulativeSceneTimer::simulate(float userDeltaTime)
{
 
 if (mScene->isWritable() == false)
  return;
 
 const float now = Functions::time();
 float deltaTime = now - mOldTime;
 mOldTime = now;
 
 if (deltaTime > mMaxTime)
  deltaTime = mMaxTime;
 
 mAccumulator += deltaTime;

 TimeStep& ts = mParent->getTimeStep();
 ts.mSubSteps = 0;
 ts.mActual = userDeltaTime;
 
 float sim_time = 0.0f;
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

 if (ts.mSubSteps)
 {
  mTimerMode = Enums::TimerMode_Simulating;
 }
 else
 {
  mTimerMode = Enums::TimerMode_Miss;
 }

}

#if 0
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
#endif

bool AccumulativeSceneTimer::hasResults(void) const
{
 return mScene->checkResults(NX_RIGID_BODY_FINISHED);
}

void AccumulativeSceneTimer::fetchResults(void)
{
/*
 mScene->flushStream();
 mScene->fetchResults(NX_RIGID_BODY_FINISHED, true);
*/
 mTimerMode = Enums::TimerMode_FetchedResults;
}

                                                                                       

} // namespace NxOgre

                                                                                       

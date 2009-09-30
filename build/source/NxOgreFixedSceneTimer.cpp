/** File: NxOgreFixedSceneTimer.cpp
    Created on: 10-May-09
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
#include "NxOgreScene.h"
#include "NxOgreFixedSceneTimer.h"
#include "NxOgreTime.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

FixedSceneTimer::FixedSceneTimer(Scene* scene, Real maxTime, Real expectedTime)
: SceneTimer(scene, maxTime, expectedTime),
  mMaxTimeStep(1.0f / 60.0f),
  mOldTime(0.0f),
  mAccumulator(0.0f)
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
 
 float now = Functions::time();
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

                                                                                       

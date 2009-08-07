/** File: NxOgreXXX.cpp
    Created on: X-XXX-XX
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

#include "NxPhysics.h"

                                                                                       

namespace NxOgre_Namespace
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



                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

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
#include "NxOgreSceneDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

const Vec3 SceneDescription::MEAN_EARTH_GRAVITY(0, Real(-9.80665), 0);

                                                                                       

SceneDescription::SceneDescription(void)
{
 reset();
}

void SceneDescription::reset(void)
{
 mProcessingPriority           = Enums::Priority_High;
 mFetchingPriority             = Enums::Priority_MediumHigh;
 mGravity                      = Vec3::ZERO;
 mMaxTimeStep                  = _1_60;
 mMaxSubSteps                  = 8;
 mTimeStepMethod               = Enums::TimeStepMethod_FixedAccumulator;
 mBounds.min                   = Vec3::ZERO;
 mBounds.max                   = Vec3::ZERO;
 mMaxDynamicRigidBodies        = 0;
 mMaxDynamicShapes             = 0;
 mMaxNonDynamicRigidBodies     = 0;
 mMaxStaticShapes              = 0;
 mMaxJoints                    = 0;
 mUseHardware                  = false;
 mBoundsPlane                  = false;
 mFlags                        = NX_SF_SIMULATE_SEPARATE_THREAD | NX_SF_DISABLE_SCENE_MUTEX;
 mBoundsUpAxis                 = Enums::NoAxis;
 mBoundsSubdivisionLevel       = 5;
 mPruningStaticStructure       = Enums::PruningStructure_StaticAABBTree;
 mPruningDynamicStructure      = Enums::PruningStructure_None;
 mDynamicTreeBuildRateHint     = 100;
 mWorkerThreadsCount           = 0;
 mWorkerThreadsStackSize       = 0;
 mWorkerThreadsPriority        = Enums::Priority_Medium;
 mWorkerThreadsMask            = 0;
 mBackgroundThreadsCount       = 0;
 mBackgroundThreadsStackSize   = 0;
 mBackgroundThreadsPriority    = Enums::Priority_Medium;
 mBackgroundThreadsMask        = 0;
 mSimulationThreadMask         = 0;
 mSimulationThreadStackSize    = 0;
 mSimulationThreadPriority     = Enums::Priority_Medium;
 mBroadPhaseType               = Enums::BroadPhase_SAPSingle;
 mBroadPhaseNbCellsX           = 0;
 mBroadPhaseNbCellsY           = 0;
 mSolverBatchSize              = 32;
 
}

bool SceneDescription::valid(void)
{
 //< \todo
 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

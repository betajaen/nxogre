/** File: NxOgreSceneDescription.cpp
    Created on: 6-Nov-08
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

                                                                                       

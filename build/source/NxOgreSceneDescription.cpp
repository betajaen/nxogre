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



SceneDescription::SceneDescription()
{
 reset();
}

void SceneDescription::to_nxscene(NxSceneDesc* scene) const
{
 scene->backgroundThreadCount = mBackgroundThreadsCount;
 scene->backgroundThreadMask = mBackgroundThreadsMask;
#if NxOgreMinimalPhysXVersion >= 281
 scene->backgroundThreadPriority = NxThreadPriority(int(mBackgroundThreadsPriority)); // Not in 2.8.0
#endif
 scene->boundsPlanes = mBoundsPlane;
 scene->bpType = NxBroadPhaseType(int(mBroadPhaseType));
 scene->dynamicStructure = NxPruningStructure(int(mPruningDynamicStructure));
#if NxOgreMinimalPhysXVersion >= 281
 scene->dynamicTreeRebuildRateHint = mDynamicTreeBuildRateHint; // Not in 2.8.0
#endif
 scene->flags = mFlags.to_i();
 scene->gravity = mGravity.as<NxVec3>();
 scene->internalThreadCount = mWorkerThreadsCount;
 scene->maxIter = mMaxSubSteps;
 scene->maxTimestep = mMaxTimeStep;
 scene->nbGridCellsX = mBroadPhaseNbCellsX;
 scene->nbGridCellsY = mBroadPhaseNbCellsY;
 scene->simThreadMask = mSimulationThreadMask;
 scene->simThreadPriority = NxThreadPriority(int(mSimulationThreadPriority));
 scene->simThreadStackSize = mSimulationThreadStackSize;
 scene->simType = mUseHardware == true ? NX_SIMULATION_HW : NX_SIMULATION_SW;
 scene->solverBatchSize = mSolverBatchSize;
 scene->staticStructure = NxPruningStructure(int(mPruningStaticStructure));
 scene->subdivisionLevel = mBoundsSubdivisionLevel;
 scene->threadMask = mWorkerThreadsMask;
 scene->timeStepMethod = NxTimeStepMethod(int(mTimeStepMethod));
 scene->upAxis = int(mBoundsUpAxis);
 if (scene->upAxis == Enums::NoAxis)
  scene->upAxis = 0;
 scene->workerThreadPriority = NxThreadPriority(int(mWorkerThreadsPriority));
 scene->workerThreadStackSize = mWorkerThreadsStackSize;


}



} // namespace NxOgre




// BEGIN - Serialisation
// The following code is computer generated. Please do not modify.

namespace NxOgre
{

SceneDescription::SceneDescription(const SceneDescription& other)
{
 other.copy_into(this);
}

SceneDescription& SceneDescription::operator=(const SceneDescription& other)
{
 other.copy_into(this);
 return *this;
}

SceneDescription* SceneDescription::duplicate() const
{
 SceneDescription* dup = new SceneDescription();
 copy_into(dup);
 return dup;
}

void SceneDescription::copy_into(SceneDescription* other) const
{
 other->mBackgroundThreadsCount = mBackgroundThreadsCount;
 other->mBackgroundThreadsMask = mBackgroundThreadsMask;
 other->mBackgroundThreadsPriority = mBackgroundThreadsPriority;
 other->mBackgroundThreadsStackSize = mBackgroundThreadsStackSize;
 other->mBounds = mBounds;
 other->mBoundsPlane = mBoundsPlane;
 other->mBoundsSubdivisionLevel = mBoundsSubdivisionLevel;
 other->mBoundsUpAxis = mBoundsUpAxis;
 other->mBroadPhaseNbCellsX = mBroadPhaseNbCellsX;
 other->mBroadPhaseNbCellsY = mBroadPhaseNbCellsY;
 other->mBroadPhaseType = mBroadPhaseType;
 other->mDynamicTreeBuildRateHint = mDynamicTreeBuildRateHint;
 other->mFetchingPriority = mFetchingPriority;
 other->mFlags = mFlags;
 other->mGravity = mGravity;
 other->mMaxDynamicShapes = mMaxDynamicShapes;
 other->mMaxJoints = mMaxJoints;
 other->mMaxNonDynamicRigidBodies = mMaxNonDynamicRigidBodies;
 other->mMaxStaticShapes = mMaxStaticShapes;
 other->mMaxSubSteps = mMaxSubSteps;
 other->mMaxTimeStep = mMaxTimeStep;
 other->mName = mName;
 other->mProcessingPriority = mProcessingPriority;
 other->mPruningDynamicStructure = mPruningDynamicStructure;
 other->mPruningStaticStructure = mPruningStaticStructure;
 other->mSimulationThreadMask = mSimulationThreadMask;
 other->mSimulationThreadPriority = mSimulationThreadPriority;
 other->mSimulationThreadStackSize = mSimulationThreadStackSize;
 other->mSolverBatchSize = mSolverBatchSize;
 other->mTimeStepMethod = mTimeStepMethod;
 other->mUseHardware = mUseHardware;
 other->mWorkerThreadsCount = mWorkerThreadsCount;
 other->mWorkerThreadsMask = mWorkerThreadsMask;
 other->mWorkerThreadsPriority = mWorkerThreadsPriority;
 other->mWorkerThreadsStackSize = mWorkerThreadsStackSize;
}

void SceneDescription::reset()
{
 mBackgroundThreadsCount = 0;
 mBackgroundThreadsMask = 0;
 mBackgroundThreadsPriority = Enums::Priority_Medium;
 mBackgroundThreadsStackSize = 0;
 mBounds.zero();
 mBoundsPlane = false;
 mBoundsSubdivisionLevel = 5;
 mBoundsUpAxis = Enums::NoAxis;
 mBroadPhaseNbCellsX = 0;
 mBroadPhaseNbCellsY = 0;
 mBroadPhaseType = Enums::BroadPhase_SAPSingle;
 mDynamicTreeBuildRateHint = 100;
 mFetchingPriority = Enums::Priority_High;
 mFlags.reset();
 mGravity.zero();
 mMaxDynamicShapes = 0;
 mMaxJoints = 0;
 mMaxNonDynamicRigidBodies = 0;
 mMaxStaticShapes = 0;
 mMaxSubSteps = 4;
 mMaxTimeStep = _1_60;
 mName = BLANK_STRING;
 mProcessingPriority = Enums::Priority_High;
 mPruningDynamicStructure = Enums::PruningStructure_None;
 mPruningStaticStructure = Enums::PruningStructure_StaticAABBTree;
 mSimulationThreadMask = 0;
 mSimulationThreadPriority = Enums::Priority_Medium;
 mSimulationThreadStackSize = 0;
 mSolverBatchSize = 32;
 mTimeStepMethod = Enums::TimeStepMethod_Fixed;
 mUseHardware = false;
 mWorkerThreadsCount = 0;
 mWorkerThreadsMask = 0;
 mWorkerThreadsPriority = Enums::Priority_Medium;
 mWorkerThreadsStackSize = 0;
}

bool SceneDescription::valid() const
{
 // mMaxSubSteps cannot be less than 1
 if (mMaxSubSteps < 0)
  return false;
 // mMaxTimeStep cannot be zero or negative
 if (mMaxTimeStep <= 0)
  return false;

 return true;
}

void SceneDescription::inspect() const
{
 std::cout << "SceneDescription => {\n";
 std::cout << "  mBackgroundThreadsCount => '" << mBackgroundThreadsCount << "'\n";
 std::cout << "  mBackgroundThreadsMask => '" << mBackgroundThreadsMask << "'\n";
 std::cout << "  mBackgroundThreadsPriority => '" << mBackgroundThreadsPriority << "'\n";
 std::cout << "  mBackgroundThreadsStackSize => '" << mBackgroundThreadsStackSize << "'\n";
 std::cout << "  mBounds => '" << mBounds << "'\n";
 std::cout << "  mBoundsPlane => '" << mBoundsPlane << "'\n";
 std::cout << "  mBoundsSubdivisionLevel => '" << mBoundsSubdivisionLevel << "'\n";
 std::cout << "  mBoundsUpAxis => '" << mBoundsUpAxis << "'\n";
 std::cout << "  mBroadPhaseNbCellsX => '" << mBroadPhaseNbCellsX << "'\n";
 std::cout << "  mBroadPhaseNbCellsY => '" << mBroadPhaseNbCellsY << "'\n";
 std::cout << "  mBroadPhaseType => '" << mBroadPhaseType << "'\n";
 std::cout << "  mDynamicTreeBuildRateHint => '" << mDynamicTreeBuildRateHint << "'\n";
 std::cout << "  mFetchingPriority => '" << mFetchingPriority << "'\n";
 std::cout << "  mFlags => '" << mFlags << "'\n";
 std::cout << "  mGravity => '" << mGravity << "'\n";
 std::cout << "  mMaxDynamicShapes => '" << mMaxDynamicShapes << "'\n";
 std::cout << "  mMaxJoints => '" << mMaxJoints << "'\n";
 std::cout << "  mMaxNonDynamicRigidBodies => '" << mMaxNonDynamicRigidBodies << "'\n";
 std::cout << "  mMaxStaticShapes => '" << mMaxStaticShapes << "'\n";
 std::cout << "  mMaxSubSteps => '" << mMaxSubSteps << "'\n";
 std::cout << "  mMaxTimeStep => '" << mMaxTimeStep << "'\n";
 std::cout << "  mName => '" << mName << "'\n";
 std::cout << "  mProcessingPriority => '" << mProcessingPriority << "'\n";
 std::cout << "  mPruningDynamicStructure => '" << mPruningDynamicStructure << "'\n";
 std::cout << "  mPruningStaticStructure => '" << mPruningStaticStructure << "'\n";
 std::cout << "  mSimulationThreadMask => '" << mSimulationThreadMask << "'\n";
 std::cout << "  mSimulationThreadPriority => '" << mSimulationThreadPriority << "'\n";
 std::cout << "  mSimulationThreadStackSize => '" << mSimulationThreadStackSize << "'\n";
 std::cout << "  mSolverBatchSize => '" << mSolverBatchSize << "'\n";
 std::cout << "  mTimeStepMethod => '" << mTimeStepMethod << "'\n";
 std::cout << "  mUseHardware => '" << mUseHardware << "'\n";
 std::cout << "  mWorkerThreadsCount => '" << mWorkerThreadsCount << "'\n";
 std::cout << "  mWorkerThreadsMask => '" << mWorkerThreadsMask << "'\n";
 std::cout << "  mWorkerThreadsPriority => '" << mWorkerThreadsPriority << "'\n";
 std::cout << "  mWorkerThreadsStackSize => '" << mWorkerThreadsStackSize << "'\n";
 std::cout << "}\n";
}


} // namespace NxOgre

// END - Serialisation. "SceneDescription-3cb54ed5984aa3a9dbf79533388be3e4"


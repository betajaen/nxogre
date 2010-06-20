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

                                                                                       

#ifndef NXOGRE_SCENEDESCRIPTION_H
#define NXOGRE_SCENEDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreSceneFlags.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. SceneDescription
    desc.
      Description to describe a Scene
    properties.
      String mName -- Name of the Scene (optional). default: BLANK_STRING
      Enums::Priority mProcessingPriority -- Priority (or when) to start processing the scene. default: Enums::Priority_High
      Enums::Priority mFetchingPriority -- Priority (or when) to fetch the results of the scene; thus altering the state. default: Enums::Priority_High
      Vec3 mGravity -- Acceleration of gravity, measured in ms^-2. default: mGravity.zero()
      Real mMaxTimeStep -- Maximum timestep. default: _1_60
      unsigned int mMaxSubSteps -- Maximum substeps. default: 4
      Enums::TimeStepMethod mTimeStepMethod -- Time stepping method. default: Enums::TimeStepMethod_Fixed
      Bounds3 mBounds -- Maximum scene bounds. (When zero, there is none). default: mBounds.zero()
      bool mBoundsPlane -- Enable 6 planes around bounds (if mBounds is not zero). default: false
      unsigned int mMaxNonDynamicRigidBodies -- Max Dynamic RigidBodies (0 is no max). default: 0
      unsigned int mMaxDynamicShapes -- Max Dynamic shapes (0 is no max). default: 0
      unsigned int mMaxStaticShapes -- Max Static shapes (0 is no max). default: 0
      unsigned int mMaxJoints -- Max joints (0 is no max). default: 0
      bool mUseHardware -- Make the scene a "hardware" scene and simulate on a GPU or PPU. default: false
      SceneFlags mFlags -- Scene flags. default: mFlags.reset()
      unsigned int mSimulationThreadStackSize -- Stack size for the main simulation thread (When set to 0 uses Operating System's default). default: 0
      Enums::Priority mSimulationThreadPriority -- Thread priority for the main simulation thread. default: Enums::Priority_Medium
      unsigned int mSimulationThreadMask -- Thread mask for the simulation thread. default: 0
      unsigned int mWorkerThreadsCount -- Number of worker threads used. default: 0
      unsigned int mWorkerThreadsStackSize -- Stack size for the worker threads. (When set to 0 uses Operating System's default). default: 0
      Enums::Priority mWorkerThreadsPriority -- Thread priority for the worker threads. default: Enums::Priority_Medium
      unsigned int mWorkerThreadsMask -- Thread mask for the worker threads. default: 0
      unsigned int mBackgroundThreadsCount -- Number of background threads used. default: 0
      unsigned int mBackgroundThreadsStackSize -- Stack size for the background threads. (When set to 0 uses Operating System's default). default: 0
      Enums::Priority mBackgroundThreadsPriority -- Thread priority for the background threads. default: Enums::Priority_Medium
      unsigned int mBackgroundThreadsMask -- Thread mask for the background threads. default: 0
      Enums::Axis mBoundsUpAxis -- Up axis when using bounds. default: Enums::NoAxis
      unsigned int mBoundsSubdivisionLevel -- The subdivision level for acceleration structures used for scene queries. default: 5
      Enums::PruningStructure mPruningStaticStructure --  Defines the structure to store static objects. (Pruning_StaticAABBTree or Pruning_DynamicAABBTree) default: Enums::PruningStructure_StaticAABBTree
      Enums::PruningStructure mPruningDynamicStructure -- Defines the structure to store dynamic objects. default: Enums::PruningStructure_None
      unsigned int mDynamicTreeBuildRateHint -- How much work should be done per simulation to rebuild the pruning structure. default: 100
      unsigned int mBroadPhaseType -- Which broadphase to use. default: Enums::BroadPhase_SAPSingle
      unsigned int mBroadPhaseNbCellsX -- Number of broadphase cells across the x axis. default: 0
      unsigned int mBroadPhaseNbCellsY -- Number of broadphase cells across the y axis. default: 0
      unsigned int mSolverBatchSize -- Number of RigidBodies required to spawn a seperate solver thread. default: 32
    validations.
      mMaxTimeStep cannot be zero or negative -- mMaxTimeStep <= 0
      mMaxSubSteps cannot be less than 1 --  mMaxSubSteps < 0
    namespace. NxOgre
*/
class NxOgrePublicClass SceneDescription
{
 public:
  
  SceneDescription();

  void to_nxscene(NxSceneDesc*) const;

  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mBackgroundThreadsCount
      desc.
          Number of background threads used.
      default.
          0
  */
  unsigned int mBackgroundThreadsCount;

  /*! variable. mBackgroundThreadsMask
      desc.
          Thread mask for the background threads.
      default.
          0
  */
  unsigned int mBackgroundThreadsMask;

  /*! variable. mBackgroundThreadsPriority
      desc.
          Thread priority for the background threads.
      default.
          Enums::Priority_Medium
  */
  Enums::Priority mBackgroundThreadsPriority;

  /*! variable. mBackgroundThreadsStackSize
      desc.
          Stack size for the background threads. (When set to 0 uses Operating System's default).
      default.
          0
  */
  unsigned int mBackgroundThreadsStackSize;

  /*! variable. mBounds
      desc.
          Maximum scene bounds. (When zero, there is none).
      default.
          mBounds.zero()
  */
  Bounds3 mBounds;

  /*! variable. mBoundsPlane
      desc.
          Enable 6 planes around bounds (if mBounds is not zero).
      default.
          false
  */
  bool mBoundsPlane;

  /*! variable. mBoundsSubdivisionLevel
      desc.
          The subdivision level for acceleration structures used for scene queries.
      default.
          5
  */
  unsigned int mBoundsSubdivisionLevel;

  /*! variable. mBoundsUpAxis
      desc.
          Up axis when using bounds.
      default.
          Enums::NoAxis
  */
  Enums::Axis mBoundsUpAxis;

  /*! variable. mBroadPhaseNbCellsX
      desc.
          Number of broadphase cells across the x axis.
      default.
          0
  */
  unsigned int mBroadPhaseNbCellsX;

  /*! variable. mBroadPhaseNbCellsY
      desc.
          Number of broadphase cells across the y axis.
      default.
          0
  */
  unsigned int mBroadPhaseNbCellsY;

  /*! variable. mBroadPhaseType
      desc.
          Which broadphase to use.
      default.
          Enums::BroadPhase_SAPSingle
  */
  unsigned int mBroadPhaseType;

  /*! variable. mDynamicTreeBuildRateHint
      desc.
          How much work should be done per simulation to rebuild the pruning structure.
      default.
          100
  */
  unsigned int mDynamicTreeBuildRateHint;

  /*! variable. mFetchingPriority
      desc.
          Priority (or when) to fetch the results of the scene; thus altering the state.
      default.
          Enums::Priority_High
  */
  Enums::Priority mFetchingPriority;

  /*! variable. mFlags
      desc.
          Scene flags.
      default.
          mFlags.reset()
  */
  SceneFlags mFlags;

  /*! variable. mGravity
      desc.
          Acceleration of gravity, measured in ms^-2.
      default.
          mGravity.zero()
  */
  Vec3 mGravity;

  /*! variable. mMaxDynamicShapes
      desc.
          Max Dynamic shapes (0 is no max).
      default.
          0
  */
  unsigned int mMaxDynamicShapes;

  /*! variable. mMaxJoints
      desc.
          Max joints (0 is no max).
      default.
          0
  */
  unsigned int mMaxJoints;

  /*! variable. mMaxNonDynamicRigidBodies
      desc.
          Max Dynamic RigidBodies (0 is no max).
      default.
          0
  */
  unsigned int mMaxNonDynamicRigidBodies;

  /*! variable. mMaxStaticShapes
      desc.
          Max Static shapes (0 is no max).
      default.
          0
  */
  unsigned int mMaxStaticShapes;

  /*! variable. mMaxSubSteps
      desc.
          Maximum substeps.
      default.
          4
      condition.
          mMaxSubSteps cannot be less than 1
  */
  unsigned int mMaxSubSteps;

  /*! variable. mMaxTimeStep
      desc.
          Maximum timestep.
      default.
          _1_60
      condition.
          mMaxTimeStep cannot be zero or negative
  */
  Real mMaxTimeStep;

  /*! variable. mName
      desc.
          Name of the Scene (optional).
      default.
          BLANK_STRING
  */
  String mName;

  /*! variable. mProcessingPriority
      desc.
          Priority (or when) to start processing the scene.
      default.
          Enums::Priority_High
  */
  Enums::Priority mProcessingPriority;

  /*! variable. mPruningDynamicStructure
      desc.
          Defines the structure to store dynamic objects.
      default.
          Enums::PruningStructure_None
  */
  Enums::PruningStructure mPruningDynamicStructure;

  /*! variable. mPruningStaticStructure
      desc.
          Defines the structure to store static objects. (Pruning_StaticAABBTree or Pruning_DynamicAABBTree)
      default.
          Enums::PruningStructure_StaticAABBTree
  */
  Enums::PruningStructure mPruningStaticStructure;

  /*! variable. mSimulationThreadMask
      desc.
          Thread mask for the simulation thread.
      default.
          0
  */
  unsigned int mSimulationThreadMask;

  /*! variable. mSimulationThreadPriority
      desc.
          Thread priority for the main simulation thread.
      default.
          Enums::Priority_Medium
  */
  Enums::Priority mSimulationThreadPriority;

  /*! variable. mSimulationThreadStackSize
      desc.
          Stack size for the main simulation thread (When set to 0 uses Operating System's default).
      default.
          0
  */
  unsigned int mSimulationThreadStackSize;

  /*! variable. mSolverBatchSize
      desc.
          Number of RigidBodies required to spawn a seperate solver thread.
      default.
          32
  */
  unsigned int mSolverBatchSize;

  /*! variable. mTimeStepMethod
      desc.
          Time stepping method.
      default.
          Enums::TimeStepMethod_Fixed
  */
  Enums::TimeStepMethod mTimeStepMethod;

  /*! variable. mUseHardware
      desc.
          Make the scene a "hardware" scene and simulate on a GPU or PPU.
      default.
          false
  */
  bool mUseHardware;

  /*! variable. mWorkerThreadsCount
      desc.
          Number of worker threads used.
      default.
          0
  */
  unsigned int mWorkerThreadsCount;

  /*! variable. mWorkerThreadsMask
      desc.
          Thread mask for the worker threads.
      default.
          0
  */
  unsigned int mWorkerThreadsMask;

  /*! variable. mWorkerThreadsPriority
      desc.
          Thread priority for the worker threads.
      default.
          Enums::Priority_Medium
  */
  Enums::Priority mWorkerThreadsPriority;

  /*! variable. mWorkerThreadsStackSize
      desc.
          Stack size for the worker threads. (When set to 0 uses Operating System's default).
      default.
          0
  */
  unsigned int mWorkerThreadsStackSize;

  /*! constructor. SceneDescription
      desc.
          Copy constructor for SceneDescription
  */
  SceneDescription(const SceneDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  SceneDescription& operator=(const SceneDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this SceneDescription as a pointer.
  */
  virtual SceneDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of SceneDescription into another.
  */
  virtual void copy_into(SceneDescription*) const;

  /*! function. reset
      desc.
          Resets SceneDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this SceneDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "SceneDescription-0d3cf6f4e3a3bb2de896bbb39c298462"

}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

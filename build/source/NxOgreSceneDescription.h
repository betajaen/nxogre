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

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SceneDescription
{ 
  
  public: // Functions
  
  static const          Vec3                 MEAN_EARTH_GRAVITY;

  /** \brief SceneDescription constructor, all it does is call SceneDescription::reset.
  */
                                              SceneDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                        reset(void);
  
  /** \brief Priority (or when) to start processing the scene.
  */
                        Enums::Priority       mProcessingPriority;
  
  /** \brief Priority (or when) to fetch the results of the scene; thus altering the state.
  */
                        Enums::Priority       mFetchingPriority;

  /** \brief Returns if the variables are in a valid range or not.
  */
                        bool                  valid(void);
  
  /** \brief Optional name of the Scene
      \default NULL (no name)
  */
                        String                mName;
  
  /** \brief Acceleration of gravity, measured in ms^-2
      \default 0 0 0
  */
                        Vec3                 mGravity;

  /** \brief Maximum substep size.
      \range (0, inf)
      \default _1_60
  */
                        Real                  mMaxTimeStep;

  /** \brief Maximum substep size.
      \range (0, inf)
      \default 4
  */
                        unsigned int          mMaxSubSteps;

  /** \brief Integration method.
      \default TimeStepMethod_Fixed
  */
                 Enums::TimeStepMethod        mTimeStepMethod;

  /** \brief Max scene bounds.
      \default 0 0 0, 0 0 0 (No bounds)
  */
                        Bounds3                mBounds;

  /** \brief Enable/Disable 6 planes around Bounds (if available)
  */
                        bool                  mBoundsPlane;

  /** \brief Max Non-Dynamic RigidBodies
      \default 0 (No max)
  */
                        unsigned int          mMaxNonDynamicRigidBodies;

  /** \brief Max Dynamic RigidBodies
      \default 0 (No max)
  */
                        unsigned int          mMaxDynamicRigidBodies;

  /** \brief Max dynamic shapes
      \default 0 (No max)   
  */
                        unsigned int          mMaxDynamicShapes;

  /** \brief Max static shapes
      \default 0 (No max)
  */
                        unsigned int          mMaxStaticShapes;

  /** \brief Max joints
      \default 0 (No max)
  */
                        unsigned int          mMaxJoints;

  /** \brief Make the scene a "hardware" scene and simulate on a GPU or PPU.
      \default false
  */
                        bool                  mUseHardware;

  /** \brief Flags (temporary holder)
      \default 0
      \todo Turn into a class.
  */
                        unsigned int          mFlags;

  /** \brief Stack size for the main simulation thread
      \default OS Default
  */
                        unsigned int          mSimulationThreadStackSize;

  /** \brief Thread priority for the main simulation thread.
      \note  This is nothing to do with the TimeController
      \default Priority_Medium
  */
                        Enums::Priority       mSimulationThreadPriority;

  /** \brief Thread mask for the simulation thread.
      \default 0
  */
                        unsigned int          mSimulationThreadMask;


  /** \brief Number of worker threads used.
      \default 0
  */
                        unsigned int          mWorkerThreadsCount;

  /** \brief Stack size for the worker threads.
      \default OS Default
  */
                        unsigned int          mWorkerThreadsStackSize;

  /** \brief Thread priority for the worker threads.
      \note  This is nothing to do with the TimeController
      \default Priority_Medium
  */
                        Enums::Priority       mWorkerThreadsPriority;

  /** \brief Thread mask for the worker threads.
      \default 0
  */
                        unsigned int          mWorkerThreadsMask;


  /** \brief Number of background threads used.
      \default 0
  */
                        unsigned int          mBackgroundThreadsCount;

  /** \brief Stack size for the background threads.
      \default OS Default
  */
                        unsigned int          mBackgroundThreadsStackSize;

  /** \brief Thread priority for the background threads.
      \note  This is nothing to do with the TimeController
      \default Priority_Medium
  */
                        Enums::Priority       mBackgroundThreadsPriority;

  /** \brief Thread mask for the background threads.
      \default 0
  */
                        unsigned int          mBackgroundThreadsMask;

  /** \brief Up axis when using bounds.
      \range NoAxis, Y or Z only
      \default NoAxis
  */
                        Enums::Axis           mBoundsUpAxis;

  /** \brief The subdivision level for acceleration structures used for scene queries.
      \note  Only used when using bounds
      \default 5
  */
                        unsigned int          mBoundsSubdivisionLevel;

  /** \brief Defines the structure to store static objects
      \range Pruning_StaticAABBTree or Pruning_DynamicAABBTree
      \default Pruning_StaticAABBTree
  */
                     Enums::PruningStructure  mPruningStaticStructure;

  /** \brief Defines the structure to store dynamic objects
      \default Pruning_None
  */
                     Enums::PruningStructure  mPruningDynamicStructure;

  /** \brief How much work should be done per simulation to rebuild the pruning structure.
      \default 100
  */
                       unsigned int           mDynamicTreeBuildRateHint;

  /** \brief Which broadphase to use.
      \default BroadPhase_SAPSingle
  */
                       unsigned int           mBroadPhaseType;

  /** \brief Number of broadphase cells across the x axis.
      \range 0, 1, 2, 4 or 8
      \default 0
  */
                       unsigned int           mBroadPhaseNbCellsX;

  /** \brief Number of broadphase cells across the y axis.
      \range 0, 1, 2, 4 or 8
      \default 0
  */
                       unsigned int           mBroadPhaseNbCellsY;

  /** \brief Number of NxActors(RigidBodies) required to spawn a seperate solver thread.
      \note  SceneFlags EnableMultiThreading must be enabbled for this to have any effect.
      \default 32
  */
                       unsigned int           mSolverBatchSize;

}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreSceneDescription.h
    Created on: 5-Nov-08
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
                        String          mName;
  
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
      \default 8
  */
                        unsigned int          mMaxSubSteps;

  /** \brief Integration method.
      \default TimeStepMethod_FixedAccumulator
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

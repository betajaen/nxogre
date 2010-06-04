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

                                                                                       

#ifndef NXOGRE_PHYSX_CONFIGURATION_H
#define NXOGRE_PHYSX_CONFIGURATION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. PhysXConfiguration
    desc.
        A collection of functions to change the configuration of PhysX.
*/ 
class NxOgrePublicClass PhysXConfiguration
{
  
 public:
  
  enum PhysXParameter
  {
   SkinWidth = 1,

   DefaultSleepLinVelSquared = 2,

   DefaultSleepAngVelSquared = 3,

   BounceThreshold = 4,

   DynamicFrictScaling = 5,

   StaticFrictScaling = 6,

   MaxAngularVelocity = 7,

   ContinuousCD = 8,

   VisualizationScale = 9,

   VisualizeWorldAxes = 10,

   VisualizeBodyAxes = 11,

   VisualizeBodyMassAxes = 12,

   VisualizeBodyLinVelocity = 13,

   VisualizeBodyAngVelocity = 14,

   VisualizeBodyJointGroups = 22,

   VisualizeJointLocalAxes = 27,

   VisualizeJointWorldAxes = 28,

   VisualizeJointLimits = 29,

   VisualizeContactPoint = 33,

   VisualizeContactNormal = 34,

   VisualizeContactError = 35,

   VisualizeContactForce = 36,

   VisualizeActorAxes = 37,

   VisualizeCollisionAabbs = 38,

   VisualizeCollisionShapes = 39,

   VisualizeCollisionAxes = 40,

   VisualizeCollisionCompounds = 41,

   VisualizeCollisionVnormals = 42,

   VisualizeCollisionFnormals = 43,

   VisualizeCollisionEdges = 44,

   VisualizeCollisionSpheres = 45,

   VisualizeCollisionStatic = 47,

   VisualizeCollisionDynamic = 48,

   VisualizeCollisionFree = 49,

   VisualizeCollisionCcd = 50,

   VisualizeCollisionSkeletons = 51,

   VisualizeFluidEmitters = 52,

   VisualizeFluidPosition = 53,

   VisualizeFluidVelocity = 54,

   VisualizeFluidKernelRadius = 55,

   VisualizeFluidBounds = 56,

   VisualizeFluidPackets = 57,

   VisualizeFluidMotionLimit = 58,

   VisualizeFluidDynCollision = 59,

   VisualizeFluidStcCollision = 60,

   VisualizeFluidMeshPackets = 61,

   VisualizeFluidDrains = 62,

   VisualizeFluidPacketData = 90,

   VisualizeClothMesh = 63,

   VisualizeClothCollisions = 64,

   VisualizeClothSelfcollisions = 65,

   VisualizeClothWorkpackets = 66,

   VisualizeClothSleep = 67,

   VisualizeClothSleepVertex = 94,

   VisualizeClothTearableVertices = 80,

   VisualizeClothTearing = 81,

   VisualizeClothAttachment = 82,

   VisualizeClothValidbounds = 92,

   VisualizeSoftbodyMesh = 83,

   VisualizeSoftbodyCollisions = 84,

   VisualizeSoftbodyWorkpackets = 85,

   VisualizeSoftbodySleep = 86,

   VisualizeSoftbodySleepVertex = 95,

   VisualizeSoftbodyTearableVertices = 87,

   VisualizeSoftbodyTearing = 88,

   VisualizeSoftbodyAttachment = 89,

   VisualizeSoftbodyValidbounds = 93,

   AdaptiveForce = 68,

   CollVetoJointed = 69,

   TriggerTriggerCallback = 70,

   SelectHWAlgo = 71,

   VisualizeActiveVertices = 72,

   CCDEpsilon = 73,

   SolverConvergenceThreshold = 74,

   BBoxNoiseLevel = 75,

   ImplicitSweepCacheSize = 76,

   DefaultSleepEnergy = 77,

   ConstantFluidMaxPackets = 78,

   ConstantFluidMaxParticlesPerStep = 79,

   VisualizeForceFields = 91,

   AsynchronousMeshCreation = 96,

   ForceFieldCustomKernelEpsilon = 97,

   ImprovedSpringSolver = 98,

   FastMassiveBpVolumeDeletion = 99,

   LegacyJointDrive = 100,

   VisualizeClothHierarchy = 101,

   VisualizeClothHardStretchingLimitation = 102
  };
  
  static void setSkinWidth(Real skinWidth);
  
  static void setCCDEnabled(bool is_enabled, float delta);

  static void setSDKParameter(PhysXParameter parameter, Real value);
  
}; // class PhysXConfiguration

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreCommon.h
    Created on: 2-Nov-08
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

#ifndef NXOGRE_COMMON_H
#define NXOGRE_COMMON_H

                                                                                       

#include "NxOgreMemory.h"
#include "NxOgreClasses.h"
#include "NxOgreErrorStream.h"
#include "NxOgrePointerClass.h"
#include "NxOgrePhysXPointer.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreSharedBuffer.h"
#include "NxOgreSingleton.h"
#include "NxOgreArray.h"
#include "NxOgreBuffer.h"
#include "NxOgreCircularBuffer.h"
#include "NxOgreMath.h"
#include "NxOgreTuple.h"
#include "NxOgreVec2.h"
#include "NxOgreVec3.h"
#include "NxOgreVec4.h"
#include "NxOgreQuat.h"
#include "NxOgreBounds.h"
#include "NxOgreMatrix.h"
#include "NxOgreString.h"
#include "NxOgreIntVectors.h"
#include "NxOgreSharedStringStream.h"
#include "NxOgreUniformResourceIdentifier.h"
#include "NxOgreArchiveResourceIdentifier.h"
#include "NxOgreVertex.h"
#include "NxOgreTriangle.h"
#include "NxOgreEntityReport.h"
#include "NxOgrePhysXPrototypes.h"
#include "NxOgreTimeStep.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Enums
{

/** \brief Axis as an integer, semi-compatible with NxHeightFieldAxis and other classes.
*/
enum Axis
{
 X      = 0,
 Y      = (1<<0),
 Z      = (1<<2),
 NoAxis = (1<<3)
};

enum TimerMode
{
 TimerMode_Simulating,
 TimerMode_FetchedResults,
 TimerMode_Miss
};

/** \brief Matrix translation
*/
enum Translation
{
 T_None,         //!< Set the matrix as it is.
 T_Identity,     //!< Set the matrix to an identity one.
 T_Zero          //!< Set the matrix components to zero.
};


/** \brief Combine mode when two integrals meet.
    \note Compatible with NxCombineMode
*/
enum CombineMode
{
 CombineMode_Average    = 0,  //!< (A + B) / 2
 CombineMode_Min        = 1,  //!< a < b ? a : b
 CombineMode_Multiply   = 2,  //!< A * B
 CombineMode_Max        = 3   //!< a > b ? a : b
};

/** \brief Actor flags to use with all types of RigidBodies. Compatible with NxActorFlag
*/
enum ActorFlags
{
 ActorFlags_DisableCollision       = (1 << 0), //!< Do not collide with other RigidBodies. Note this excludes from overlap tests.
 ActorFlags_DisableResponse        = (1 << 1), //!< Disable collision response
 ActorFlags_LockCOM                = (1 << 2), //!< Disable COM (Center of Mass) update when computing inertial properties at creation.
 ActorFlags_DisableFluidCollision  = (1 << 3), //!< Disable Collision with fluids.
 ActorFlags_ContactModification    = (1 << 4), //!< Turn on contact modification for the RigidBody.
 ActorFlags_ForceConeFriction      = (1 << 5), //!< Force cone friction to be used with this RigidBody.
 ActorFlags_UserActorPairFiltering = (1 << 6)  //!< Enable custom contact filering.
};

/** \brief Body flags to use with Actor (and inherited) and Particle types of RigidBodies ONLY. Compatible with NxBodyFlag
*/
enum BodyFlags
{
 BodyFlags_DisableGravity          = (1 << 0), //!< Gravity should not be applied to this RigidBody.
 BodyFlags_FreezePositionX         = (1 << 1), //!< Freeze movement in the X axis.
 BodyFlags_FreezePositionY         = (1 << 2), //!< Freeze movement in the Y axis.
 BodyFlags_FreezePositionZ         = (1 << 3), //!< Freeze movement in the Z axis.
 BodyFlags_FreezePosition          = BodyFlags_FreezePositionX | BodyFlags_FreezePositionY  | BodyFlags_FreezePositionZ, //!< Freeze position in all axis.
 BodyFlags_FreezeRotationX         = (1 << 4), //!< Freeze rotation in the X axis.
 BodyFlags_FreezeRotationY         = (1 << 5), //!< Freeze rotation in the Y axis.
 BodyFlags_FreezeRotationZ         = (1 << 6), //!< Freeze rotation in the Z axis.
 BodyFlags_FreezeRotation          = BodyFlags_FreezeRotationX | BodyFlags_FreezeRotationY | BodyFlags_FreezeRotationZ, //!< Freeze rotation in all axis.
 BodyFlags_Frozen                  = BodyFlags_FreezePosition | BodyFlags_FreezeRotation, //!< Freeze position and rotation, in a sense pretend to be like a KinematicActor or StaticGeometry for a period of time.
 BodyFlags_Visualisation           = (1 << 8), //!< Visualise the body component in the VisualDebugger.
 BodyFlags_FilterSleepVelocity     = (1 <<10), //!< Filter sleep velocity.
 BodyFlags_EnergySleepTest         = (1 <<11), //!< Enable energy-based sleepig algorithm.
};

/** \brief Force mode for when using addForce in a RigidBody.
    \note Compatible with NxForceMode
*/
enum ForceMode
{
 ForceMode_Force,                 //!< parameter has unit of mass * distance/time^2, i.e. a force
 ForceMode_Impulse,               //!< parameter has unit of mass * distance/time
 ForceMode_VelocityChange,        //!< parameter has unit of distance/time, i.e. the effect is mass independent: a velocity change.
 ForceMode_SmoothImpulse,         //!< same as Impulse but the effect is applied over all substeps. Use this for motion controllers that repeatedly apply an impulse.
 ForceMode_SmoothVelocityChange,  //!< same as VelocityChange but the effect is applied over all substeps. Use this for motion controllers that repeatedly apply an impulse.
 ForceMode_Acceleration           //!< parameter has unit of distance/time^2, i.e. an acceleration. It gets treated just like a force except the mass is not divided out before integration.
};

/** \brief Priorities are an order of importantance. Which is executed first.
*/
enum Priority
{
 Priority_High       = 0,  //!< Highest priority.
 Priority_MediumHigh = 1,  //!< High but not the highest
 Priority_Medium     = 2,  //!< Medium or normal priority
 Priority_MediumLow  = 3,  //!< Not as much as medium.
 Priority_Low        = 4   //!< Lowest priority, always last.
};

/** \brief What the RigidBody type is.
*/
enum RigidBodyType
{
 RigidBodyType_Dynamic          = -1,  //!< RigidBody is likely to move.
 RigidBodyType_Kinematic        = -2,  //!< RigidBody is likely to move, but it should not have the usual physics properties.
 RigidBodyType_Geometry         = -3,  //!< RigidBody will never move.
 RigidBodyType_Volume           = -4,  //!< RigidBody will never move, and others can pass through it.
 RigidBodyType_Unknown          = -5,  //!< Unknown Type.
 RigidBodyType_DynamicInherited =  0   //!< Non-NxOgre class that is dynamic.
};

/** \brief What do when there is an assertion from PhysX
*/
enum PhysXAssertionResponse
{
 PhysXAssertion_Continue,
 PhysXAssertion_Ignore,
 PhysXAssertion_Breakpoint
};

/** \brief Inbuilt time stepping methods for scene intergration.
*/
enum TimeStepMethod
{
 TimeStepMethod_Fixed            = 0, //!< Divides the time equally, used with compartments.
 TimeStepMethod_FixedAccumulator = 0, //!< Divides the time equally, used with scenes.
 TimeStepMethod_Variable         = 1, //!< Uses the time as is.
 TimeStepMethod_Inherit          = 2, //!< Inherit from the main scene, Used with compartments.

};

/** \brief Pruning structure for Scenes. Compatible with NxPruningStructure
*/
enum PruningStructure
{
 PruningStructure_None,
 PruningStructure_Octree,
 PruningStructure_Quadtree,
 PruningStructure_DynamicAABBTree,
 PruningStructure_StaticAABBTree,
};

/** \brief Broadphase type for Scenes. Compatible with NxBroadPhaseType
*/
enum BroadPhase
{
 BroadPhase_SAPSingle,
 BroadPhase_SAPMulti
};

/** \brief The directions that a Resource can be read or written to. Omidrectional like a file, or sucessional like a stream.
*/
enum ResourceDirectionality
{
 ResourceDirectionality_Unknown        = 0,  //!< Unknown directionaility probably due to the resource not being opened yet.
 ResourceDirectionality_Omidirectional = 1,  //!< Data can be read or written backwards and forwards. This is for most part true with saved files.
 ResourceDirectionality_Sucessional    = 2   //!< Data can be read or written in succession. This is for most part true with streams.
};

/** \brief Last known status of a resource
*/
enum ResourceStatus
{
 ResourceStatus_NotFound    = 0,  //!< The resource cannot be written or read to. The file or stream cannot be found.
 ResourceStatus_Opening     = 1,  //!< The resource is in the process of being opened. It cannot be read or written to.
 ResourceStatus_Opened      = 2,  //!< The resource is opened. It can be read or written to, depending on the ResourceAccess.
 ResourceStatus_Closing     = 3,  //!< The resource is closing.  It cannot be read or written to.
 ResourceStatus_Closed      = 4,  //!< The resource is closed.  It cannot be read or written to.
 ResourceStatus_Maintenance = 5,  //!< The resource is under maintance. e.x. A memory buffer may be resized, or the file is the middle of being created.
 ResourceStatus_Waiting     = 5,  //!< The resource has been created, but the open() function has not been called yet. It cannot be read or written to.
 ResourceStatus_HasError    = 7,  //!< There has been an error. The resource may be closed. It cannot be read or written to.
 ResourceStatus_Unknown     = 8,  //!< Status is unknown. This happens when the Resource class does not fully inherit all of it's functions.
};

/** \brief Type of access to a resource
*/
enum ResourceAccess
{
 ResourceAccess_ReadOnly     = 0,  //!< Read but do not write
 ResourceAccess_ReadAndWrite = 1,  //!< Read and write.
 ResourceAccess_WriteOnly    = 2,  //!< Write but do not read
 ResourceAccess_AppendOnly   = 3,  //!< Write to the end of the file only.
};

/** \brief Hashing
*/
enum HashAlgorithm
{
 HashAlgorithm_DJB2 = 0  //!< The DJB2 hash by D.J. Bernstein http://cr.yp.to/djb.html
};

/** \brief
*/
enum KinematicInteractionFlag
{
 KinematicInteractionFlag_Include   = 0,
 KinematicInteractionFlag_Exclude   = 1,
 KinematicInteractionFlag_UseFilter = 2
};

/** \brief
*/
enum KinematicCollisionFlag
{
 KinematicCollisionFlag_NoNone = 0,        //!< KinematicController hasn't collided with anything.
 KinematicCollisionFlag_Sides  = (1 << 0), //!< KinematicController has collided with something to the side.
 KinematicCollisionFlag_Up     = (2 << 0), //!< KinematicController has collided with something above.
 KinematicCollisionFlag_Down   = (2 << 0), //!< KinematicController has collided with something below.
 KinematicCollisionFlag_NoMove = (3 << 0)  //!< KinematicController was not moved. Probably due to the direction being zero.
};

/** \brief
*/
enum KinematicContactAction
{
 KinematicContactAction_None     = 0,
 KinematicContactAction_AutoPush = 1,
 KinematicContactAction_Callback = 2
};

/** \brief Type of shape filted by restriced movement of parent RigidBody, used with scene queries, and test methods in the Scene
           Compatible with NxShapesType
    \see   NxShapesType
*/
enum ShapesType
{
 ShapesType_Static = (1<<0), //!< Hit static shapes (SceneGeometries, Volumes)
 ShapesType_Dynamic= (1<<1), //!< Hit dynamic shapes (Actors, Particles, KinematicActors)
 ShapesType_All    = ShapesType_Dynamic | ShapesType_Static //!< Hit both types of shape.
};

/** \brief
*/
enum SimpleShapeType
{
 SimpleShape_Box,
 SimpleShape_Sphere,
 SimpleShape_Capsule,
 SimpleShape_PointCloud,
 SimpleShape_TriangleMesh,
};

/** \brief A list of the possible functions of shapes in NxOgre. Compatible with NxShapeType
*/
enum ShapeFunctionType
{
 ShapeFunctionType_Plane,
 ShapeFunctionType_Sphere,
 ShapeFunctionType_Box,
 ShapeFunctionType_Capsule,
 ShapeFunctionType_Wheel,
 ShapeFunctionType_Convex,
 ShapeFunctionType_Mesh,
 ShapeFunctionType_HeightField,
 ShapeFunctionType_Unknown = 10
};

/** \brief Describes the compartment types a rigid body shape might interact with. Compatible with NxShapeCompartmentType
*/
enum ShapeCompartmentType
{
 ShapeCompartmentType_RigidBody_Software = (1 << 0),
 ShapeCompartmentType_RigidBody_Hardware = (1 << 1),
 ShapeCompartmentType_Fluid_Software     = (1 << 2),
 ShapeCompartmentType_Fluid_Hardware     = (1 << 3),
 ShapeCompartmentType_Cloth_Software     = (1 << 4),
 ShapeCompartmentType_Cloth_Hardware     = (1 << 5),
 ShapeCompartmentType_SoftBody_Software  = (1 << 6),
 ShapeCompartmentType_SoftBody_Hardware  = (1 << 7)
};

/** \brief Flags used when building a shape, Mostly Compatible with the NxShapeFlags enum.
*/
enum ShapeFlags
{
 ShapeFlags_Visualisation       = (1<<3),  //!< \brief Allow a visualation of this shape in the VisualDebugger.
 ShapeFlags_NoCollision         = (1<<4),  //!< \brief Use only with Compound Shapes, otherwise raise NX_AF_DISABLE_COLLISION
 ShapeFlags_FeatureIndices      = (1<<5),  //!< \brief Enable feature indices in the contact stream.
 ShapeFlags_DisableRaycasting   = (1<<6),  //!< \brief Disable raycasting for this shape.
 ShapeFlags_PointContactForce   = (1<<7),  //!< \brief Enable contact force reporting per contact point in contact stream.
 ShapeFlags_IsFluidDrain        = (1<<8),  //!< \brief Sets the shape to be a fluid drain.
 ShapeFlags_NoFluids            = (1<<10), //!< \brief Disable collision with fluids.
 ShapeFlags_TwoWayFluid         = (1<<11), //!< \brief Enables the reaction of the shapes rigidbody on fluid collision.
 ShapeFlags_DiableResponse      = (1<<12), //!< \brief Disbale collision response for this shape.
 ShapeFlags_DynamicDynamicCCD   = (1<<13), //!< \brief Enable dynamic-dynamic CCD for this shape.
 ShapeFlags_DisableSceneQueries = (1<<14), //!< \brief Diable participation in raycasts, overlap tests and sweeps.
 ShapeFlags_IsClothDrain        = (1<<15), //!< \brief Sets the shape to be a cloth drain.
 ShapeFlags_NoCloth             = (1<<16), //!< \brief Disable Collision with Cloth.
 ShapeFlags_TwoWayCloth         = (1<<17), //!< \brief Enables the reaction of the shapes rigidbody on cloth collision.
 ShapeFlags_IsSoftBodyDrain     = (1<<18), //!< \brief Sets the shape to be a SoftBody drain.
 ShapeFlags_NoSoftBody          = (1<<19), //!< \brief Disable Collision with SoftBody.
 ShapeFlags_TwoWaySoftBody      = (1<<20), //!< \brief Enables the reaction of the shapes rigidbody on SoftBody collision.
};

enum MeshType
{
 MeshType_Unknown  = 0, //!< Mesh has a malformed header, or has not been loaded.
 MeshType_Convex   = 1, //!< A point cloud used in a Convex shape.
 MeshType_Triangle = 2, //!< A triangle "soup" used in TriangleGeometry shape.
 MeshType_Cloth    = 3, //!< A cloth used with the Cloth class.
 MeshType_SoftBody = 4  //!< A soft body used with the SoftBody class.
};

enum XType
{
 XType_Unknown     = 0, //!< \brief Unknown file type.
 XType_HeightField = 1, //!< \brief Is a heightfield file.
 XType_Skeleton    = 2, //!< \brief Is a skeleton file.
};

enum VolumeCollisionType
{
 VolumeCollisionType_None        = 0,       //!< No Collision.
 VolumeCollisionType_OnEnter     = (1<<0),  //!< When a RigidBody enters the volume
 VolumeCollisionType_OnExit      = (1<<1),  //!< When a RigidBody exits the volume.
 VolumeCollisionType_OnPresence  = (1<<2),  //!< When a RigidBody is inside the volume (called per timestep).
 /** \brief When a RigidBody enters, exits or inside a Volume
 */
 VolumeCollisionType_All         = VolumeCollisionType_OnEnter | VolumeCollisionType_OnExit | VolumeCollisionType_OnPresence,
 /** \brief When a RigidBody enters or exits
 */
 VolumeCollisionType_EnterOrExit = VolumeCollisionType_OnEnter | VolumeCollisionType_OnExit
};

enum VisualDebugger
{
 VisualDebugger_ShowNone = 0, //!< \brief Don't show anything.
 VisualDebugger_ShowAll  = 1, //!< \brief Show all configurations of the debugger.
};

enum RenderableType
{
 RenderableType_VisualDebugger    = 0, //!< \brief PhysX Visual Debugger.
 RenderableType_PhysXMesh         = 1, //!< \brief Any class (i.e. cloth) that PhysX determines the visual mesh.
 RenderableType_ParticlePoints    = 2, //!< \brief Particles represented as seperate vertex points.
 RenderableType_SoftBody          = 3, //!< \brief A SoftBody.
};

enum ParticleStatus
{
 ParticleStatus_Inactive = 0,  //!< \brief Particle is inactive
 ParticleStatus_Sleep    = 1,  //!< \brief Particle is asleep
 ParticleStatus_Active   = 2,  //!< \brief Particle is active
 ParticleStatus_Old      = 3,  //!< \brief Particle has reached it's typical half-life.
 ParticleStatus_Focused  = 4,  //!< \brief Particle has focus which it should be re-used until it is no longer so.
};

/** \brief Flags to use with Meshes. Compatible with NxMeshShapeFlag
*/
enum MeshShapeFlag
{
 MeshShapeFlag_SmoothSphereCollisions = (1 << 0), //!< \brief Apply a Gouaud algorithm to smooth the triangles out. \see NX_MESH_SMOOTH_SPHERE_COLLISIONS
 MeshShapeFlag_DoubleSided            = (1 << 1), //!< \brief Mesh is double sided, but only used with Raycasting. \see NX_MESH_DOUBLE_SIDED
};

/** \brief Tesselation mode for HeightFields)
*/
enum HeightFieldTesselation
{
 HeightFieldTesselation_NE_SW = 0, //!< \brief NorthEast (TopRight) to SouthWest (BottomLeft).
 HeightFieldTesselation_NW_SE = 1, //!< \brief NorthWest (TopLeft) to SouthEast (BottomRight).
};

/** \brief Terrain local pose adjustment - or not.
*/
enum TerrainCentering
{
 TerrainCentering_LocalPose    = 0, //!< \brief Don't center, use the local pose.
 TerrainCentering_CenterXZ     = 1, //!< \brief Center the heightfield to scale.x / 2, scale.z / 2
 TerrainCentering_CenterAbove  = 2, //!< \brief Center and move upwards, so any negative height is above the global pose of the actor.
};


enum RemoteDebuggerEventGroup
{
 // Basic
 RemoteDebuggerGroup_BasicObjects             = 0x00000001,
 RemoteDebuggerGroup_BasicObjectsDynamicData  = 0x00000002,
 RemoteDebuggerGroup_BasicObjectsStaticData   = 0x00000004,
 // Joints
 RemoteDebuggerGroup_Joints                   = 0x00000008,
 RemoteDebuggerGroup_JointsData               = 0x00000010,
 // Contacts
 RemoteDebuggerGroup_Contacts                 = 0x00000020,
 RemoteDebuggerGroup_ContactsData             = 0x00000040,
 // Triggers
 RemoteDebuggerGroup_Triggers                 = 0x00000080,
 // Profiles
 RemoteDebuggerGroup_Profiling                = 0x00000100,
 // Cloth
 RemoteDebuggerGroup_Cloth                    = 0x00000200,
 RemoteDebuggerGroup_ClothDynamicData         = 0x00000400,
 RemoteDebuggerGroup_ClothStaticData          = 0x00000800,
 // SoftBody
 RemoteDebuggerGroup_SoftBody                 = 0x00001000,
 RemoteDebuggerGroup_SoftBodyDynamicData      = 0x00002000,
 RemoteDebuggerGroup_SoftBodyStaticData       = 0x00004000,
 // Fluid
 RemoteDebuggerGroup_Fluid                    = 0x00008000,
 RemoteDebuggerGroup_FluidDynamicData         = 0x00010000,
 RemoteDebuggerGroup_FluidStaticData          = 0x00020000,
};

enum RemoteDebuggerMask
{
 // Everything
 RemoteDebuggerMask_Everything                = 0xFFFFFFFF,
 RemoteDebuggerMask_BasicObjects              = RemoteDebuggerGroup_BasicObjects,
 RemoteDebuggerMask_BasicObjectsDynamicData   = (RemoteDebuggerGroup_BasicObjects | RemoteDebuggerGroup_BasicObjectsDynamicData),
 RemoteDebuggerMask_BasicObjectsStaticData    = (RemoteDebuggerGroup_BasicObjects | RemoteDebuggerGroup_BasicObjectsStaticData),
 RemoteDebuggerMask_BasicObjectsAll           = (RemoteDebuggerMask_BasicObjectsDynamicData | RemoteDebuggerMask_BasicObjectsStaticData),
 // Joints
 RemoteDebuggerMask_Joints                    = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_JointsData                = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_JointsData | RemoteDebuggerGroup_BasicObjects),
 // Contacts
 RemoteDebuggerMask_Contacts                  = (RemoteDebuggerGroup_Contacts | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_ContactsData              = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_JointsData | RemoteDebuggerGroup_BasicObjects),
 // Triggers
 RemoteDebuggerMask_Triggers                  = (RemoteDebuggerGroup_Triggers),
 // Profiling
 RemoteDebuggerMask_Profiling                 = (RemoteDebuggerGroup_Profiling),
 // Cloth
 RemoteDebuggerMask_Cloth                     = (RemoteDebuggerGroup_Cloth),
 RemoteDebuggerMask_ClothDynamicData          = (RemoteDebuggerGroup_Cloth | RemoteDebuggerGroup_ClothDynamicData),
 RemoteDebuggerMask_ClothStaticData           = (RemoteDebuggerGroup_Cloth | RemoteDebuggerGroup_ClothStaticData),
 RemoteDebuggerMask_ClothAllData              = (RemoteDebuggerMask_ClothDynamicData | RemoteDebuggerMask_ClothStaticData),
 // Fluid
 RemoteDebuggerMask_Fluid                     = (RemoteDebuggerGroup_Fluid),
 RemoteDebuggerMask_FluidDynamicData          = (RemoteDebuggerGroup_Fluid | RemoteDebuggerGroup_FluidDynamicData),
 RemoteDebuggerMask_FluidStaticData           = (RemoteDebuggerGroup_Fluid | RemoteDebuggerGroup_FluidStaticData),
 RemoteDebuggerMask_FluidAllData              = (RemoteDebuggerMask_FluidDynamicData | RemoteDebuggerMask_FluidStaticData),
};

enum RemoteDebuggerObjectType
{
 RemoteDebuggerObjectType_Generic             = 0,
 RemoteDebuggerObjectType_Actor               = 1,
 RemoteDebuggerObjectType_Plane               = 2,
 RemoteDebuggerObjectType_Box                 = 3,
 RemoteDebuggerObjectType_Sphere              = 4,
 RemoteDebuggerObjectType_Capsule             = 5,
 RemoteDebuggerObjectType_Cylinder            = 6,
 RemoteDebuggerObjectType_Convex              = 7,
 RemoteDebuggerObjectType_Mesh                = 8,
 RemoteDebuggerObjectType_Wheel               = 9,
 RemoteDebuggerObjectType_Joint               = 10,
 RemoteDebuggerObjectType_Contact             = 11,
 RemoteDebuggerObjectType_BoundingBox         = 12,
 RemoteDebuggerObjectType_Vector              = 13,
 RemoteDebuggerObjectType_Camera              = 14,
 RemoteDebuggerObjectType_Cloth               = 15,
 RemoteDebuggerObjectType_SoftBody            = 16,
 RemoteDebuggerObjectType_Fluid               = 17,
 RemoteDebuggerObjectType_Forcefield          = 18,

};

/** \brief Joint type as an enum. Compatible with NxJointType.
*/
enum JointFunctionType
{
 JointFunctionType_Prismatic,
 JointFunctionType_Revolute,
 JointFunctionType_Cylindrical,
 JointFunctionType_Spherical,
 JointFunctionType_PointOnLine,
 JointFunctionType_PointInPlane,
 JointFunctionType_Distance,
 JointFunctionType_Pulley,
 JointFunctionType_Fixed,
 JointFunctionType_D6,
 JointFunctionType_Count,
 JointFunctionType_DWORD_NEVER_USE = 0x7fffffff
};

/** \brief State flags for Joints. Compatible with NxJointState, apart from JointState_Dead.
*/
enum JointState
{
 JointState_Unbound,
 JointState_Simulating,
 JointState_Broken,
 JointState_Dead
};

/** \brief Construction flags for Joints. Compatible with NxJointFlag
*/
enum JointFlag
{
 JointFlag_CollisionEnabled = (1 << 0),
 JointFlag_Visualisation    = (1 << 1)
};

/** \brief Joint projection modes. Compatible with NxJointProjectionMode
*/
enum JointProjectionMode
{
 JointProjectionMode_None                   = 0,
 JointProjectionMode_Point_MiniumDistance   = 1,
 JointProjectionMode_Linear_MiniumDistance  = 2
};

/** \brief Flags to control the behaviour to revolute joints. Compatible NxRevoluteJointFlag
*/
enum RevoluteJointFlags
{
 RevoluteJointFlags_LimitEnabled  = 1 << 0,
 RevoluteJointFlags_MotorEnabled  = 1 << 1,
 RevoluteJointFlags_SpringEnabled = 1 << 2,
};

/** \brief Flags to control the behaviour to pulley joints. Compatible NxPulleyJointFlag
*/
enum PullyJointFlags
{
 PullyJointFlags_IsRigid       = 1 << 0,
 PullyJointFlags_MotorEnabled  = 1 << 1
};

/** \brief Flags to control the behaviour to distance joints. Compatible NxDistanceJointFlag
*/
enum DistanceJointFlags
{
 DistanceJointFlags_MaxDistanceEnabled = 1 << 0,
 DistanceJointFlags_MinDistanceEnabled = 1 << 1,
 DistanceJointFlags_SpringEnabled      = 1 << 1
};

/** \brief Used to specifiy the range of motions allowed for a DOF in a D6 joint. Compatible with NxD6JointMotion.
*/
enum D6JointMotion
{
 D6JointMotion_Locked,
 D6JointMotion_Limited,
 D6JointMotion_Free,
};

/** \brief Used to specify a particular drive method. Compatible with NxD6JointDrive.
*/
enum D6JointDriveType
{
 D6JointDriveType_Position = 1 << 0,
 D6JointDriveType_Velocity = 1 << 1
};

/** \brief Flags to control the behaviour to D6 joints. Compatible NxDistanceJointFlag
*/
enum D6JointFlag
{
 D6JointFlag_SlerpDrive  = 1 << 0,
 D6JointFlag_GearEnabled = 1 << 1
};

/** \brief 
*/
enum JointSpringType
{
 JointSpringType_Force        = 0,
 JointSpringType_Acceleration = 1
};

/** \brief Flags to use with SpherialJointDescription
*/
enum SphericalJointFlags
{
 SphericalJointFlags_TwistLimitEnabled                 = (1<<0),
 SphericalJointFlags_SwingLimitEnabled                 = (1<<1),
 SphericalJointFlags_TwistSpringEnabled                = (1<<2),
 SphericalJointFlags_SwingSpringEnabled                = (1<<3),
 SphericalJointFlags_JointSpringEnabled                = (1<<4),
 SphericalJointFlags_PerpendicularDirectionConstraints = (1<<5),
};


/** \brief Flags to use with Wheels
*/
enum WheelFlags
{
 WheelFlags_AxisContactNormal           = (1<<0), //!< \brief Determines whether the suspension axis or ground contact normal is used for the suspension constraint.
 WheelFlags_InputLatSlipVelocity        = (1<<1), //!< \brief The laterial slip veloicty is used as the input to the tire function, rather than the slip angle.
 WheelFlags_InputLongSlipVelocity       = (1<<2), //!< \brief The longutudal slip veloicty is used as the input to the tire function, rather than the slip angle.
 WheelFlags_UnscaledSpringBehaviour     = (1<<3), //!< \brief Does not factor out the suspension travel and wheel radius from the spring force computation. This is the legacy behaviour from the raycast capsule approach.
 WheelFlags_AxleSpeedOverride           = (1<<4), //!< \brief The axle speed is not computed by the simulation but is rather expected to be provided by the user every simulation step via Wheel::setAxleSpeed()
 WheelFlags_EmulateLegacyWheel          = (1<<5), //!< \brief The Wheel will emulate the PhysX legacy raycast capsule based wheel.
 WheelFlags_ClampedFriction             = (1<<6), //!< \brief The Wheel will clamp the force in the friction constraints.
};

enum ClothFlags
{
 ClothFlags_Pressure                    = (1<<0), //!< \brief Enable pressure simulation for closed cloth meshes.
 ClothFlags_Static                      = (1<<1), //!< \brief Make the cloth static.
 ClothFlags_DisableRigidBodyCollision   = (1<<2), //!< \brief Disable collision with RigidBodies.
 ClothFlags_DisableSelfCollision        = (1<<3), //!< \brief Disable collision with itself.
 ClothFlags_DebugVisualisation          = (1<<4), //!< \brief Enable to be visualised when the visual debugger is on.
 ClothFlags_Gravity                     = (1<<5), //!< \brief Respond to scene gravity.
 ClothFlags_BendingResistance           = (1<<6), //!< \brief Enable bending resistance.
 ClothFlags_OrthogonalBendingResistance = (1<<7), //!< \brief Enable orthogonal bending resistance.
 ClothFlags_Damping                     = (1<<8), //!< \brief Enable damping of internal velocities.
 ClothFlags_TwoWayCollisions            = (1<<9), //!< \brief Enable two way collisions with rigid bodies.
// ClothFlags_TriangleCollision,          = (1<<11), // N/A
 ClothFlags_Tearable                    = (1<<12), //!< \brief Enables tearing of the cloth.
 ClothFlags_Hardware                    = (1<<13), //!< \brief Enables simulating the cloth on a PPU or GPU.
 ClothFlags_COMDamping                  = (1<<14), //!< \brief Enable center of mass damping of internal velocities.
 ClothFlags_ValidBounds                 = (1<<15), //!< \brief If set particles outside the bounds will be removed.
 ClothFlags_FluidCollision              = (1<<16), //!< \brief Enable collisions with fluids.
 ClothFlags_DisableDynamicCCD           = (1<<17), //!< \brief Disable continuous collision detection with dynamic actors.
 ClothFlags_Adhere                      = (1<<18), //!< \brief Moves cloth partially in the frame of the attached actor.
};

enum ClothAttachmentFlags
{
 ClothAttachmentFlags_Twoway            = (1<<0), //!< \brief The default is only object->cloth interaction (one way).
 ClothAttachmentFlags_Tearable          = (1<<1), //!< \brief When this flag is set, the attachment is tearable.
};

enum ClothVertexAttachmentStatus
{
 ClothVertexAttachmentStatus_None       ,         //!< \brief Vertex is not attached.
 ClothVertexAttachmentStatus_Global     ,         //!< \brief Vertex is attached to the global frame.
 ClothVertexAttachmentStatus_Shape      ,         //!< \brief Vertex is attached to a shape.
};

enum MeshConstructionFlags
{
 MeshConstructionsFlags_FlipNormals,
 MeshConstructionsFlags_16bitIndices,
 MeshConstructionsFlags_HardwareMesh
};

enum SoftBodyFlags
{
 SoftBodyFlags_Static                      = (1<<1), //!< \brief Make the Soft Body static.
 SoftBodyFlags_DisableRigidBodyCollision   = (1<<2), //!< \brief Disable collision with RigidBodies.
 SoftBodyFlags_DisableSelfCollision        = (1<<3), //!< \brief Disable collision with itself.
 SoftBodyFlags_DebugVisualisation          = (1<<4), //!< \brief Enable to be visualised when the visual debugger is on.
 SoftBodyFlags_Gravity                     = (1<<5), //!< \brief Respond to scene gravity.
 SoftBodyFlags_VolumeConservation          = (1<<6), //!< \brief Enable volume conservation.
 SoftBodyFlags_Damping                     = (1<<7), //!< \brief Enable of internal velocities.
 SoftBodyFlags_TwoWayCollisions            = (1<<8), //!< \brief Enable two way collisions with rigid bodies.
 SoftBodyFlags_Tearable                    = (1<<9), //!< \brief Enables tearing of the Soft Body.
 SoftBodyFlags_Hardware                    = (1<<10), //!< \brief Enables simulating the Soft Body on a PPU or GPU.
 SoftBodyFlags_COMDamping                  = (1<<11), //!< \brief Enable center of mass damping of internal velocities.
 SoftBodyFlags_ValidBounds                 = (1<<12), //!< \brief If set particles outside the bounds will be removed.
 SoftBodyFlags_FluidCollision              = (1<<13), //!< \brief Enable collisions with fluids.
 SoftBodyFlags_DisableDynamicCCD           = (1<<14), //!< \brief Disable continuous collision detection with dynamic actors.
 SoftBodyFlags_Adhere                      = (1<<15), //!< \brief Moves Soft Body partially in the frame of the attached actor.
};

enum SoftBodyAttachmentFlags
{
 SoftBodyAttachmentFlags_Twoway            = (1<<0), //!< \brief The default is only object->Soft Body interaction (one way).
 SoftBodyAttachmentFlags_Tearable          = (1<<1), //!< \brief When this flag is set, the attachment is tearable.
};

enum DeviceCode
{
 DeviceCode_PPU0                           = 0,      //!< \brief Explicit PPU index corresponds to index numeric value (reserved for future use, currently only PPU 0 is valid). 
 DeviceCode_PPU1                           = 1,      //!< \brief Not Used.
 DeviceCode_PPU2                           = 2,      //!< \brief Not Used.
 DeviceCode_PPU3                           = 3,      //!< \brief Not Used.
 DeviceCode_PPU4                           = 4,      //!< \brief Not Used.
 DeviceCode_PPU5                           = 5,      //!< \brief Not Used.
 DeviceCode_PPU6                           = 6,      //!< \brief Not Used.
 DeviceCode_PPU7                           = 7,      //!< \brief Not Used.
 DeviceCode_PPU8                           = 8,      //!< \brief Not Used.
 DeviceCode_CPU                      = 0xffff0000,   //!< \brief Compartment is to be simulated on CPU.
 DeviceCode_AutoAssign               = 0xffff0001    //!< \brief Compartment is to be simulated on a processor (PPU or CPU) chosen by the HSM for best performance (CPU is only used in the absence of a PPU). .
};

enum CompartmentType
{
 CompartmentType_RigidBody                 = 0,
 CompartmentType_Fluid                     = 1,
 CompartmentType_Cloth                     = 2,
 CompartmentType_SoftBody                  = 2,
};

enum CompartmentFlags
{
 CompartmentFlags_SleepNotification        = (1<<0),
 CompartmentFlags_Continuous               = (1<<1),
 CompartmentFlags_RestrictedScene          = (1<<2),
 CompartmentFlags_InheritSettings          = (1<<3)
};

enum ParticleFlags
{
 ParticleFlags_CollisionWithStatic         = (1<<0),
 ParticleFlags_CollisionWithDynamic        = (1<<1),
 ParticleFlags_Seperated                   = (1<<2),
 ParticleFlags_MotionLimitReached          = (1<<3)
};

enum FluidSimulationMethod
{
 FluidSimulationMethod_SPH                   = (1<<0),
 FluidSimulationMethod_NoParticleInteraction = (1<<1),
 FluidSimulationMethod_MixedMode             = (1<<2)
};

enum FluidCollisionMethod
{
 FluidCollisionMethod_Static                 = (1<<0),
 FluidCollisionMethod_Dynamic                = (1<<1)
};

enum FluidFlags
{
 FluidFlags_Visualisation                    = (1<<0), //!< \brief Enables debug visualization for the Fluid.
 FluidFlags_DisableGravity                   = (1<<1), //!< \brief Disables scene gravity for the Fluid.
 FluidFlags_CollisionTwoWay                  = (1<<2), //!< \brief Enable/disable two way collision of fluid with the rigid body scene.
 FluidFlags_Enabled                          = (1<<3), //!< \brief Enable/disable execution of fluid simulation.
 FluidFlags_Hardware                         = (1<<4), //!< \brief Defines whether this fluid is simulated on the PPU.
 FluidFlags_PriorityMode                     = (1<<5), //!< \brief Enable/disable particle priority mode. 
 FluidFlags_ProjectToPlane                   = (1<<6), //!< \brief Defines whether the particles of this fluid should be projected to a plane.
 FluidFlags_ForceStrictCookingFormat         = (1<<7)  //!< \note Currently not implemented
};

enum ContactPairFlags
{
 ContactPairFlags_Ignore                     = (1<<0), //!< \brief Disable contact generation
 ContactPairFlags_StartTouch                 = (1<<1), //!< \brief Pair callback will be called when the pair starts to be in contact.
 ContactPairFlags_StopTouch                  = (1<<2), //!< \brief Pair callback will be called when the pair stops to be in contact.
 ContactPairFlags_Touch                      = (1<<3), //!< \brief Pair callback will be called whilst the pair is in contact.
 ContactPairFlags_Forces                     = (1<<7), //!< \brief The (summed total) frictional force and normal force will be given in the ContactPair struct
 ContactPairFlags_StartTouchThreshold        = (1<<8), //!< \brief Pair callback will be called when the contact force between two RigidBodies exceeds one of the actor-defined force thresholds.
 ContactPairFlags_StopTouchThreshold         = (1<<9), //!< \brief Pair callback will be called when the contact force between two RigidBodies falls below one of the actor-defined force thresholds.
 ContactPairFlags_TouchThreshold             = (1<<10),//!< \brief Pair callback will keep getting called when the contact force between two RigidBodies falls below one of the actor-defined force thresholds.
 
 ContactPairFlags_ContactModifcation         = (1<<16),//!< \brief Generate a callback for all associated contact constraints, making it possible to edit the constraint.
 
 ContactPairFlags_All                        = (
                                                ContactPairFlags_StartTouch          |
                                                ContactPairFlags_StopTouch           |
                                                ContactPairFlags_Touch               |
                                                ContactPairFlags_Forces              |
                                                ContactPairFlags_StartTouchThreshold |
                                                ContactPairFlags_StopTouchThreshold  |
                                                ContactPairFlags_TouchThreshold
                                               )
 
};

} // namespace Enums



                                                                                       

// Prototypes classes, used through NxOgre, and with the Python generation scripts. Which turns
// the names into an enum value in NxOgreClasses.h, any lines with prefixed with //:: are private
// or in different namespaces, which cannot be prototyped in C++.

                 class                      AccumulativeSceneTimer;        //!<
                 struct                     ActiveParticle;                //!<
                 class                      Actor;                         //!<
                 class                      ActorMachinePart;              //!<
                 class                      Archive;                       //!<
                 class                      ArchiveMetaData;               //!<
                 class                      ArchiveResourceIdentifier;     //!<
//::             struct         ArchiveResourceIdentifierReferenceCounter; //!< \internal Do Not Use.
     template<typename T> class             Array;                         //!<
//::             struct                     ArrayReferenceCounter;         //!< \internal Do Not Use.
//::             struct                     ArrayUnknown;                  //!< \internal Do Not Use.
                 class                      Box;                           //!<
     template<typename T> class             Buffer;                        //!<
//::             struct                     BufferReferenceCounter;        //!< \internal Do Not Use.
//::             struct                     BufferUnknown;                 //!< \internal Do Not Use.
                 class                      Capsule;                       //!<
                 class                      Callback;                      //!<
//::             struct                     CircularBufferReferenceCounter; //!<
                 class                      Cloth;                         //!<
                 class                      ClothDescription;              //!<
                 struct                     ClothRaycastHit;               //!<
                 class                      Compartment;                   //!<
                 class                      CompartmentDescription;        //!<
                 class                      ContactPair;                   //!<
        template<class T> class             ConstantArray;                 //!<
                 class                      Convex;                        //!<
                 class                      D6Joint;                       //!<
                 class                      D6JointDescription;            //!<
                 class                      DebugRenderable;               //!<
                 class                      ErrorStream;                   //!<
                 class                      FixedJoint;                    //!<
                 class                      FixedSceneTimer;               //!<
                 class                      Fluid;                         //!<
                 class                      FluidDescription;              //!<
                 class                      FluidEmitter;                  //!<
                 class                      FluidEmitterDescription;       //!<
                 class                      FluidDrain;                    //!<
                 class                      FluidDrainDescription;         //!<
                 class                      FluidPacket;                   //!<
                 class                      HeightField;                   //!<
                 class                      HeightFieldGeometry;           //!<
                 class                      HeightFieldGeometryBlueprint;  //!< 
                 struct                     HeightFieldSample;             //!<
                 class                      HeightFieldManager;            //!<
                 class                      Geometry;                      //!<
                 class                      int2;                          //!<
                 class                      int3;                          //!<
                 class                      int4;                          //!<
                 class                      Joint;                         //!<
                 class                      JointDescription;              //!<
                 class                      JointLimitDescription;         //!<
                 class                      JointLimitSoftDescription;     //!<
                 class                      KinematicActor;                //!<
                 class                      KinematicController;           //!<
                 class                      ParticleData;                  //!<
     template<unsigned int Ti> class        PointerClass;                  //!<
                 class                      PhysXOutputStream;             //!<
                 class                      PhysXUserAllocator;            //!<
                 class                      Machine;                       //!<
                 class                      MachinePart;                   //!<
                 class                      Material;                      //!<
                 class                      MaterialDescription;           //!<
                 class                      MaterialPrototype;             //!<
                 class                      ManualMesh;                    //!<
//::             struct                     ManualMeshReferenceCounter;    //!<
                 class                      MeshData;                      //!<
                 class                      ManualHeightField;             //!<
//::             struct                     ManualHeightFieldReferenceCounter //!<
                 class                      HeightFieldData;               //!<
                 class                      Memory;                        //!<
                 class                      MemoryArchive;                 //!<
                 class                      MemoryResource;                //!<
                 class                      MemoryResourceProtocol;        //!<
                 class                      Mesh;                          //!<
                 class                      MeshManager;                   //!<
                 class                      MeshStats;                     //!<
                 class                      MotorDescription;              //!<
//::             class                      MSWindowsFileArchive;          //!< \brief Part of NxOgre for Windows
//::             class                      MSWindowsFileResource;         //!< \brief Part of NxOgre for Windows
//::             class                      MSWindowsFileResourceProtocol; //!< \brief Part of NxOgre for Windows
                 class                      PlaneGeometry;                 //!<
                 class                      PlaneGeometryPrototype;        //!<
                 class                      Particle;                      //!<
                 class                      PhysXMeshData;                 //!<
                 class                      PhysXCallback;                 //!< \internal Do Not Use.
                 class                      PhysXPointer;                  //!<
                 class                      PhysXShapePointer;             //!<
                 class                      PointParticleRenderer;         //!<
                 class                      PointRenderable;               //!<
                 class                      Resource;                      //!<
                 class                      ResourceSystem;                //!<
                 class                      RigidBody;                     //!<
                 class                      RigidBodyDescription;          //!<
                 class                      RigidBodyPrototype;            //!<
                 class                      RemoteDebugger;                //!<
                 class                      RemoteDebuggerListener;        //!<
                 class                      Renderable;                    //!<
                 class                      Resource;                      //!<
                 class                      ResourceProtocol;              //!<
                 class                      ResourceSystem;                //!<
                 union                      RestingParticle;               //!<
                 class                      RevoluteJoint;                 //!<
                 class                      RevoluteJointDescription;      //!<
                 class                      Ray;                           //!<
                 struct                     RaycastHit;                    //!<
                 class                      Scene;                         //!<
                 class                      SceneDescription;              //!<
                 class                      SceneGeometry;                 //!<
                 class                      ScenePrototype;                //!<
                 class                      SceneRenderer;                 //!<
                 class                      SceneTimer;                    //!<
//::             class                      Shape_Abstract;                //!< \virtual
                 class                      Sphere;                        //!<
                 class                      SphericalJoint;                //!<
                 class                      SphericalJointDescription;     //!<
//::             class                      SharedArray;                   //!< \brief Part of NxOgreArray.h
                 struct                     SimpleShape;                   //!<
                 struct                     SimpleBox;                     //!<
                 struct                     SimpleCapsule;                 //!<
//::             class                      SharedCircularBuffer;          //!< \brief Part of NxOgreArray.h
                 struct                     SimpleSegment;                 //!<
                 struct                     SimplePlane;                   //!<
                 struct                     SimplePointCloud;              //!<
                 struct                     SimpleTriangleMesh;            //!<
 template<class T, unsigned int Ti> class   Singleton;                     //!<
//::             class                      SharedBuffer;                  //!<
                 class                      SharedKinematicFunctions;      //!<
                 class                      String;                        //!<
                 class                      StringBase;                    //!<
                 class                      SoftBody;                      //!<
                 class                      SoftBodyDescription;           //!<
                 class                      SoftBodyMesh;                  //!<
                 class                      SharedStringStream;            //!<
//::             class                      SharedStringStream_Buffer;     //!<
//::             struct                 SharedStringStreamReferenceCounter //!<
                 class                      Shape;                         //!<
                 class                      ShapeBlueprint;                //!<
                 class                      SpringDescription;             //!<
//::             struct                     TBuffer;                       //!< \brief Part of NxOgreArray.h
                 class                      TimeController;                //!<
                 class                      TimeListener;                  //!<
                 class                      TireFunction;                  //!<
                 class                      TriangleGeometry;              //!<
                 class                      UniformResourceIdentifier;     //!<
//::             struct                     URIHash;                       //!< \brief Part of UniformResourceIdentifer
                 class                      VisualDebugger;                //!<
                 class                      VisualDebuggerMeshData;        //!<
                 class                      Volume;                        //!<
                 class                      Wheel;                         //!<
                 class                      WheelBlueprint;                //!<
                 class                      WheelMachinePart;              //!<
                 class                      World;                         //!<
                 class                      WorldDescription;              //!<
                 class                      WorldPrototype;                //!<

                 typedef                    BoundsT<Vec2>           Bounds2;
                 typedef                    BoundsT<Vec3>           Bounds3;
                 typedef                    BoundsT<Vec4>           Bounds4;

                                                                                       

namespace Functions
{
                 class                      NxShapeFunctions;              //!<
}

                                                                                       


/** \brief 1/30th of a second, to 8 sig. figs.
*/
#define _1_30 0.0333333f

/** \brief 1/60th of a second, to 8 sig. figs.
*/
#define _1_60 0.0166666f

/** \brief 1/100th of a second.
*/
#define _1_100 0.01f

/** \brief 1/5th of a second
*/
#define _1_5 0.2f

/** \brief A Collision Model or an array shape pointers.
*/
typedef Array<Shape*> Shapes;

/** \brief Numerical identifier for ActorGroups and ShapeGroups.
*/
typedef unsigned short GroupIdentifier;

/** \brief Numerical identifier for Materials.
*/
typedef unsigned short MaterialIdentifier;

/** \brief Shorthand for a UniformResourceIdentifier.
*/
typedef UniformResourceIdentifier URI;

/** \brief An index in a triangle
*/
typedef unsigned int Index;

/** \brief A pair of JointLimitDescriptions.
*/
typedef Pair<JointLimitDescription> JointLimitPairDescription;

/** \brief A pair of JointLimitDescriptions.
*/
typedef Pair<JointLimitSoftDescription> JointLimitPairSoftDescription;

/** \brief
*/
typedef JointDescription FixedJointDescription;

/** \brief Used by the SDK for caching raycasts.
*/
typedef NxShape** RaycastCache;


typedef String SharedString;

                                                                                       

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointDouble
 typedef Vec3 DoubleVec3;
#endif

#define Matrix33_Zero ::NxOgre::Matrix33(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0)

#define Matrix33_Identity ::NxOgre::Matrix33(1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0)

#define Matrix44_Zero ::NxOgre::Matrix44(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0)

#define Matrix44_Identity ::NxOgre::Matrix44(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0)

                                                                                       

namespace Constants
{

static const Real Pi = 3.141592653589793f;
static const Real HalfPi = 1.57079632679489661923f;
static const Real TwoPi = 6.28318530717958647692f;
static const Real InversePi = 0.31830988618379067154f;

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
static const DoubleReal Pi_Double = 3.141592653589793;
static const DoubleReal HalfPi_Double = 1.57079632679489661923;
static const DoubleReal TwoPi_Double = 6.28318530717958647692;
static const DoubleReal InversePi_Double = 0.31830988618379067154;
#endif

/** \brief Unknown resource size constant.
*/
static const size_t ResourceSizeUnknown = -1;

enum
{
 DefaultRemoteDebuggerPort = 5425
};

}; // namespace Constants

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

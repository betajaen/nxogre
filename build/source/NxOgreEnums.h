/* 
    
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

                                                                                       

#ifndef NXOGRE_ENUMS_H
#define NXOGRE_ENUMS_H

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Enums
{

/*! enum. UserDestructionPolicy
    desc.
        What to do when faced with deleting a user class that has originated outside of NxOgre.
    enums.
        UserDestructionPolicy_NeverDelete -- Don't delete. Pointer will be left as it is.
        UserDestructionPolicy_Delete -- Delete it, using the NXOGRE_DELETE macro.
        UserDestructionPolicy_Callback -- Use the given callback (UserDestructionCallback) with the pointer. Callback is OWNED by user application.
*/
enum UserDestructionPolicy
{
 UserDestructionPolicy_NeverDelete = 0,
 UserDestructionPolicy_Delete = 1,
 UserDestructionPolicy_Callback = 2,
};

/*! enum. ExceptionType
*/
enum ExceptionType
{
 ExceptionType_UnknownError,
 ExceptionType_InternalError,
 ExceptionType_IOException,
 ExceptionType_NoPhysXSDKError,
 ExceptionType_PhysXInternalError,
 ExceptionType_NullPointerException,
 ExceptionType_NonNullPointerException,
 ExceptionType_PhysXSDKCreationFailed,
 ExceptionType_DescriptionInvalid,
 ExceptionType_WrongType,
 ExceptionType_PathInvalidException
};

/*! enum. Axis
    desc.
         Axis as an integer, semi-compatible with NxHeightFieldAxis and other classes.
    enums.
         X -- X Axis.
         Y -- Y Axis.
         Z -- Z Axis.
         NoAxis -- No Axis.
*/
enum Axis
{
 X      = 0,
 Y      = (1<<0),
 Z      = (1<<2),
 NoAxis = (1<<3)
};

/*! enum. CoordinateSystem
    desc.
        Type of Coordinate systems.
    enums.
        CoordinateSystem_Cartesian -- Cartesian
        CoordinateSystem_Spherical -- Spherical
        CoordinateSystem_Cylindrical Cylindrical
        CoordinateSystem_Toroidal -- Toroidal
*/
enum CoordinateSystem
{
 CoordinateSystem_Cartesian,
 CoordinateSystem_Spherical,
 CoordinateSystem_Cylindrical,
 CoordinateSystem_Toroidal
};

/*! enum. TimerMode
    desc.
         Current state of the SceneTimer.
    enums.
         TimerMode_Simulating -- Timer is simulating.
         TimerMode_FetchedResults -- Timer has results that have been fetched.
         TimerMode_Miss -- Timer did not simulate this frame.
*/
enum TimerMode
{
 TimerMode_Simulating,
 TimerMode_FetchedResults,
 TimerMode_Miss
};

/*! enum. CombineMode
    desc.
         Combine mode when two integrals meet.
    note.
         Compatible with @NxCombineMode@
    enums.
          CombineMode_Average -- (A + B) / 2
          CombineMode_Min -- a < b ? a : b
          CombineMode_Multiply -- A &times; B
          CombineMode_Max -- a > b ? a : b
*/
enum CombineMode
{
 CombineMode_Average    = 0,
 CombineMode_Min        = 1,
 CombineMode_Multiply   = 2,
 CombineMode_Max        = 3 
};

/*! enum. SceneLink
    desc.
        
*/
enum SceneType
{
 SceneType_Prinicipal   = 0,
 SceneType_Auxiliary    = 1
};

/*! enum. SceneLink
    desc.
        
*/
enum RigidBodyRole
{
 RigidBodyRole_None       = 0,
 RigidBodyRole_Puppeteer  = 1,
 RigidBodyRole_Puppet     = 2
};

/*! enum. ForceMode
    desc.
         Force mode for when using addForce in a RigidBody.
    note.
         Compatible with @NxForceMode@.
    enums.
         ForceMode_Force                -- Parameter has unit of <span class="math">m &times; s / t ^2^</span>, i.e. a force
         ForceMode_Impulse              -- Parameter has unit of <span class="math">m &times; s / t</span>
         ForceMode_VelocityChange       -- Parameter has unit of distance/time, i.e. the effect is mass independent: a velocity change.
         ForceMode_SmoothImpulse        -- Same as Impulse but the effect is applied over all substeps. Use this for motion controllers that repeatedly apply an impulse.
         ForceMode_SmoothVelocityChange -- Same as VelocityChange but the effect is applied over all substeps. Use this for motion controllers that repeatedly apply an impulse.
         ForceMode_Acceleration         -- Parameter has unit of <span class="math">d / t ^2^</span>, i.e. an acceleration. It gets treated just like a force except the mass is not divided out before integration.
*/
enum ForceMode
{
 ForceMode_Force,
 ForceMode_Impulse,
 ForceMode_VelocityChange,
 ForceMode_SmoothImpulse,
 ForceMode_SmoothVelocityChange,
 ForceMode_Acceleration
};

/*! enum. Priority
    desc.
         Priorities are an order of importantance. Which is executed first.
    enums.
         Priority_High       -- Highest priority.
         Priority_MediumHigh -- High but not the highest
         Priority_Medium     -- Medium or normal priority
         Priority_MediumLow  -- Not as much as medium.
         Priority_Low        -- Lowest priority, always last.
*/
enum Priority
{
 Priority_High       = 0,
 Priority_MediumHigh = 1,
 Priority_Medium     = 2,
 Priority_MediumLow  = 3,
 Priority_Low        = 4 
};

/*! enum. RigidBodyType
    desc.
         What the RigidBody type is.
    enums.
         RigidBodyType_Dynamic   -- RigidBody is likely to move.
         RigidBodyType_Kinematic -- RigidBody is likely to move, but it should not conserve momentum.
         RigidBodyType_Geometry  -- RigidBody will never move.
         RigidBodyType_Volume    -- RigidBody will never move, and others can pass through it.
         RigidBodyType_Unknown   -- Unknown Type.
*/
enum RigidBodyType
{
 RigidBodyType_Actor               = -1,
 RigidBodyType_KinematicActor      = -2,
 RigidBodyType_SceneGeometry       = -3,
 RigidBodyType_Volume              = -4,
 RigidBodyType_KinematicController = -5,
 RigidBodyType_Unknown             = 0,
 RigidBodyType_USER_BEGIN          = 0
};

/*! enum. PhysXAssertionResponse
    desc.
         What do when there is an assertion from PhysX
    enums.
         PhysXAssertion_Continue -- Continue
         PhysXAssertion_Ignore -- Ignore
         PhysXAssertion_Breakpoint -- Breakpoint
*/
enum PhysXAssertionResponse
{
 PhysXAssertion_Continue,
 PhysXAssertion_Ignore,
 PhysXAssertion_Breakpoint
};

/*! enum. PhysXAssertionResponse
    desc.
         Time stepping method.
    enums.
         TimeStepMethod_Fixed    -- Uses a fixed time-step, but divides &#Delta;Time equally and carries any remaing time to the next frame.
         TimeStepMethod_Variable -- Uses the &#Delta;time as is.
         TimeStepMethod_Inherit  -- Inherit from the main scene, Used with compartments.
*/
enum TimeStepMethod
{
 TimeStepMethod_Fixed     = 0,
 TimeStepMethod_Variable  = 1,
 TimeStepMethod_Inherit   = 2
};

/*! enum. PruningStructure
    desc.
         Time stepping method.
    note.
         Compatible with @NxPruningStructure@.
    enums.
         PruningStructure_None -- No structure, using a linear list of objects.
         PruningStructure_Octree -- Using a preallocated loose octree.
         PruningStructure_Quadtree -- Using a preallocated loose quadtree.
         PruningStructure_DynamicAABBTree -- Using a dynamic AABB tree.
         PruningStructure_StaticAABBTree -- Using a static AABB tree.
*/
enum PruningStructure
{
 PruningStructure_None,
 PruningStructure_Octree,
 PruningStructure_Quadtree,
 PruningStructure_DynamicAABBTree,
 PruningStructure_StaticAABBTree
};

/*! enum. BroadPhase
    desc.
         Broadphase type for Scenes.
    note.
         Compatible with NxBroadPhaseType
    enums.
         BroadPhase_SAPSingle -- A sweep-and-prune (SAP) algorithm to find pairs of potentially colliding shapes
         BroadPhase_SAPMulti -- A multi sweep-and-prune algorithm to find pairs of potentially colliding shapes.
*/
enum BroadPhase
{
 BroadPhase_SAPSingle,
 BroadPhase_SAPMulti
};

/*! enum. ResourceDirectionality
    desc.
         The directions that a Resource can be read or written to. Omidrectional like a file, or sucessional like a stream.
    enums.
         ResourceDirectionality_Unknown        -- Unknown directionaility probably due to the resource not being opened yet.
         ResourceDirectionality_Omidirectional -- Data can be read or written backwards and forwards. This is for most part true with saved files.
         ResourceDirectionality_Sucessional    -- Data can be read or written in succession. This is for most part true with streams.
*/
enum ResourceDirectionality
{
 ResourceDirectionality_Unknown        = 0,
 ResourceDirectionality_Omidirectional = 1,
 ResourceDirectionality_Sucessional    = 2 
};

/*! enum. ResourceStatus
    desc.
         Status of a resource
    enums.
         ResourceStatus_NotFound    -- The resource cannot be written or read to. The file or stream cannot be found.
         ResourceStatus_Opening     -- The resource is in the process of being opened. It cannot be read or written to.
         ResourceStatus_Opened      -- The resource is opened. It can be read or written to, depending on the ResourceAccess.
         ResourceStatus_Closing     -- The resource is closing.  It cannot be read or written to.
         ResourceStatus_Closed      -- The resource is closed.  It cannot be read or written to.
         ResourceStatus_Maintenance -- The resource is under maintance. e.x. A memory buffer may be resized, or the file is the middle of being created.
         ResourceStatus_Waiting     -- The resource has been created, but the open() function has not been called yet. It cannot be read or written to.
         ResourceStatus_HasError    -- There has been an error. The resource may be closed. It cannot be read or written to.
         ResourceStatus_Unknown     -- Status is unknown. This happens when the Resource Class does not fully inherit all of it's functions.
*/
enum ResourceStatus
{
 ResourceStatus_NotFound    = 0,
 ResourceStatus_Opening     = 1,
 ResourceStatus_Opened      = 2,
 ResourceStatus_Closing     = 3,
 ResourceStatus_Closed      = 4,
 ResourceStatus_Maintenance = 5,
 ResourceStatus_Waiting     = 5,
 ResourceStatus_HasError    = 7,
 ResourceStatus_Unknown     = 8
};

/*! enum. ResourceAccess
    desc.
         Type of access to a resource
    enums.
         ResourceAccess_ReadOnly     -- Read but do not write
         ResourceAccess_ReadAndWrite -- Read and write.
         ResourceAccess_WriteOnly    -- Write but do not read
         ResourceAccess_AppendOnly   -- Write to the end of the file only.
         ResourceAccess_NoAccess     -- Resource access is unknown. Probably due to the file hasn't been opened yet.
*/
enum ResourceAccess
{
 ResourceAccess_ReadOnly     = 0,
 ResourceAccess_ReadAndWrite = 1,
 ResourceAccess_WriteOnly    = 2,
 ResourceAccess_AppendOnly   = 3,
 ResourceAccess_NoAccess     = 4 
};

/*! enum. KinematicInteractionFlag
    desc.
         Kinematic controller interaction flags.
    enums.
         KinematicInteractionFlag_Include   -- Include
         KinematicInteractionFlag_Exclude   -- Exclude
         KinematicInteractionFlag_UseFilter -- Use filter
*/
enum KinematicInteractionFlag
{
 KinematicInteractionFlag_Include   = 0,
 KinematicInteractionFlag_Exclude   = 1,
 KinematicInteractionFlag_UseFilter = 2
};

/*! enum. KinematicCollisionFlag
    desc.
         Kinematic controller collision flags.
    enums.
         KinematicCollisionFlag_NoNone -- KinematicController hasn't collided with anything.
         KinematicCollisionFlag_Sides  -- KinematicController has collided with something to the side.
         KinematicCollisionFlag_Up     -- KinematicController has collided with something above.
         KinematicCollisionFlag_Down   -- KinematicController has collided with something below.
         KinematicCollisionFlag_NoMove -- KinematicController was not moved. Probably due to the direction being zero.
*/
enum KinematicCollisionFlag
{
 KinematicCollisionFlag_NoNone = 0,
 KinematicCollisionFlag_Sides  = (1 << 0),
 KinematicCollisionFlag_Up     = (2 << 0),
 KinematicCollisionFlag_Down   = (2 << 0),
 KinematicCollisionFlag_NoMove = (3 << 0)
};

/*! enum. KinematicContactAction
    desc.
         Kinematic controller contact action flags.
    enums.
         KinematicContactAction_None     -- Do nothing (pass through)
         KinematicContactAction_AutoPush -- Apply a pushing force against the RigidBody
         KinematicContactAction_Callback -- Use a callback to handle action.
*/
enum KinematicContactAction
{
 KinematicContactAction_None     = 0,
 KinematicContactAction_AutoPush = 1,
 KinematicContactAction_Callback = 2
};

/*! enum. ShapesType
    desc.
         Type of shape filted by restriced movement of parent RigidBody, used with scene queries, and test methods in the Scene
    note.
         Compatible with @NxShapesType@.
    enums.
         ShapesType_Static  -- Static shapes (SceneGeometries and Volumes)
         ShapesType_Dynamic -- Dynamic shapes (Actors and KinematicActors)
         ShapesType_All     -- Both types of shapes.
*/
enum ShapesType
{
 ShapesType_Static = (1<<0), //!< Hit static shapes (SceneGeometries, Volumes)
 ShapesType_Dynamic= (1<<1), //!< Hit dynamic shapes (Actors, Particles, KinematicActors)
 ShapesType_All    = ShapesType_Dynamic | ShapesType_Static //!< Hit both types of shape.
};

/*! enum. SimpleShapeType
    desc.
         Type of SimpleShape.
    enums.
         SimpleShape_Box               -- Cuboid
         SimpleShape_Sphere            -- Sphere
         SimpleShape_Capsule           -- Capsule
         SimpleShape_ConvexPointCloud  -- Convex point cloud
         SimpleShape_TriangleMesh      -- Triangle mesh.
         SimpleShape_Plane             -- Plane.
*/
enum SimpleShapeType
{
 SimpleShape_Box,
 SimpleShape_Sphere,
 SimpleShape_Capsule,
 SimpleShape_ConvexPointCloud,
 SimpleShape_TriangleMesh,
 SimpleShape_Plane
};

/*! enum. ShapeFunctionType
    desc.
         A list of the possible functions of shapes in NxOgre.
    note.
         Compatible with @NxShapeType@.
    enums.
         ShapeFunctionType_Plane -- PlaneGeometry,
         ShapeFunctionType_Sphere -- Sphere,
         ShapeFunctionType_Box -- Box,
         ShapeFunctionType_Capsule -- Capsule,
         ShapeFunctionType_Wheel -- Wheel,
         ShapeFunctionType_Convex -- Convex,
         ShapeFunctionType_Mesh -- TriangleMeshGeometry,
         ShapeFunctionType_HeightField -- HeightFieldGeometry,
         ShapeFunctionType_Unknown -- Not used.
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

/*! enum. ShapeFunctionType
    desc.
         Describes the compartment types a rigid body shape might interact with.
    note.
         Compatible with @NxShapeCompartmentType@.
    enums.
         ShapeCompartmentType_RigidBody_Software -- RigidBody Software
         ShapeCompartmentType_RigidBody_Hardware -- RigidBody Hardware
         ShapeCompartmentType_Fluid_Software     -- Fluid Software    
         ShapeCompartmentType_Fluid_Hardware     -- Fluid Hardware    
         ShapeCompartmentType_Cloth_Software     -- Cloth Software    
         ShapeCompartmentType_Cloth_Hardware     -- Cloth Hardware    
         ShapeCompartmentType_SoftBody_Software  -- SoftBody Software 
         ShapeCompartmentType_SoftBody_Hardware  -- SoftBody Hardware 
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

/*! enum. ShapeFlags
    desc.
         Flags used when building a shape.
    note.
         Mostly Compatible with the @NxShapeFlag@ enum.
    enums.
         ShapeFlags_Visualisation       -- Allow a visualation of this shape in the VisualDebugger.
         ShapeFlags_NoCollision         -- Used only with Compound Shapes, otherwise raise ActorFlags_DisableCollision.
         ShapeFlags_FeatureIndices      -- Enable feature indices in the contact stream.
         ShapeFlags_DisableRaycasting   -- Disable raycasting for this shape.
         ShapeFlags_PointContactForce   -- Enable contact force reporting per contact point in contact stream.
         ShapeFlags_IsFluidDrain        -- Sets the shape to be a fluid drain.
         ShapeFlags_NoFluids            -- Disable collision with fluids.
         ShapeFlags_TwoWayFluid         -- Enables the reaction of the shapes rigidbody on fluid collision.
         ShapeFlags_DiableResponse      -- Disbale collision response for this shape.
         ShapeFlags_DynamicDynamicCCD   -- Enable dynamic-dynamic CCD for this shape.
         ShapeFlags_DisableSceneQueries -- Diable participation in raycasts, overlap tests and sweeps.
         ShapeFlags_IsClothDrain        -- Sets the shape to be a cloth drain.
         ShapeFlags_NoCloth             -- Disable Collision with Cloth.
         ShapeFlags_TwoWayCloth         -- Enables the reaction of the shapes rigidbody on cloth collision.
         ShapeFlags_IsSoftBodyDrain     -- Sets the shape to be a SoftBody drain.
         ShapeFlags_NoSoftBody          -- Disable Collision with SoftBody.
         ShapeFlags_TwoWaySoftBody      -- Enables the reaction of the shapes rigidbody on SoftBody collision.
         ShapeFlags_Default             -- Enable Visualisation, TwoWayCloth and TwoWaySoftBody
*/
enum ShapeFlags
{
 ShapeFlags_Visualisation       = (1<<3),
 ShapeFlags_NoCollision         = (1<<4),
 ShapeFlags_FeatureIndices      = (1<<5),
 ShapeFlags_DisableRaycasting   = (1<<6),
 ShapeFlags_PointContactForce   = (1<<7),
 ShapeFlags_IsFluidDrain        = (1<<8),
 ShapeFlags_NoFluids            = (1<<10),
 ShapeFlags_TwoWayFluid         = (1<<11),
 ShapeFlags_DisableResponse     = (1<<12),
 ShapeFlags_DynamicDynamicCCD   = (1<<13),
 ShapeFlags_DisableSceneQueries = (1<<14),
 ShapeFlags_IsClothDrain        = (1<<15),
 ShapeFlags_NoCloth             = (1<<16),
 ShapeFlags_TwoWayCloth         = (1<<17),
 ShapeFlags_IsSoftBodyDrain     = (1<<18),
 ShapeFlags_NoSoftBody          = (1<<19),
 ShapeFlags_TwoWaySoftBody      = (1<<20),
 ShapeFlags_Default             = Enums::ShapeFlags_Visualisation | Enums::ShapeFlags_TwoWayCloth | Enums::ShapeFlags_TwoWaySoftBody
};

/*! enum. MeshType
    desc.
         Type of NxOgre and PhysX Meshes.
    enums.
         MeshType_Unknown  -- Mesh has a malformed header, or has not been loaded.
         MeshType_Convex   -- A point cloud used in a Convex shape.
         MeshType_Triangle -- A triangle "soup" used in TriangleGeometry shape.
         MeshType_Cloth    -- A cloth used with the Cloth class.
         MeshType_SoftBody -- A soft body used with the SoftBody class.
         MeshType_Skeleton -- A CCD Skeleton.
*/
enum MeshType
{
 MeshType_Unknown  = 0,
 MeshType_Convex   = 1,
 MeshType_Triangle = 2,
 MeshType_Cloth    = 3,
 MeshType_SoftBody = 4,
 MeshType_Skeleton = 5
};

/*! enum. XType
    desc.
         Type of NxOgre file; xhf or xcl.
    enums.
         XType_Unknown     -- Unknown file type.
         XType_HeightField -- Is a heightfield file.
         XType_Skeleton    -- Is a skeleton file.
*/
enum XType
{
 XType_Unknown     = 0,
 XType_HeightField = 1,
 XType_Skeleton    = 2
};

/*! enum. VolumeCollisionType
    desc.
         Type of collisions to look for in a Volume.
    note.
         VolumeCollisionTypes are combined together with the @|@ (or) operator.
    enums.
         VolumeCollisionType_None        -- No Collision.
         VolumeCollisionType_OnEnter     -- When a RigidBody enters the volume
         VolumeCollisionType_OnExit      -- When a RigidBody exits the volume.
         VolumeCollisionType_OnPresence  -- When a RigidBody is inside the volume (called per timestep).
         VolumeCollisionType_All         -- When a RigidBody enters, exits or inside a Volume
         VolumeCollisionType_EnterOrExit -- When a RigidBody enters or exits
*/
enum VolumeCollisionType
{
 VolumeCollisionType_None        = 0,     
 VolumeCollisionType_OnEnter     = (1<<0),
 VolumeCollisionType_OnExit      = (1<<1),
 VolumeCollisionType_OnPresence  = (1<<2),
 VolumeCollisionType_All         = VolumeCollisionType_OnEnter | VolumeCollisionType_OnExit | VolumeCollisionType_OnPresence,
 VolumeCollisionType_EnterOrExit = VolumeCollisionType_OnEnter | VolumeCollisionType_OnExit
};

/*! enum. VolumeCollisionType
    desc.
         Type of collisions to look for in a Volume.
    note.
         VisualDebugger are combined together with the @|@ (or) operator.
    enums.
         VisualDebugger_ShowNone -- Don't show anything.
         VisualDebugger_ShowAll  -- Show all configurations of the debugger (Cannot be used with the @|@ (or) operator)
         VisualDebugger_World_Axes                  -- World Axes
         VisualDebugger_Body_Axes                   -- Body Axes
         VisualDebugger_Body_Mass_Axes              -- Body Mass Axes
         VisualDebugger_Body_Lin_Velocity           -- Body Lin Velocity
         VisualDebugger_Body_Ang_Velocity           -- Body Ang Velocity
         VisualDebugger_Body_Joint_Groups           -- Body Joint Groups
         VisualDebugger_Joint_Local_Axes            -- Joint Local Axes
         VisualDebugger_Joint_World_Axes            -- Joint World Axes
         VisualDebugger_Joint_Limits                -- Joint Limits
         VisualDebugger_Contact_Point               -- Contact Point
         VisualDebugger_Contact_Normal              -- Contact Normal
         VisualDebugger_Contact_Error               -- Contact Error
         VisualDebugger_Contact_Force               -- Contact Force
         VisualDebugger_Actor_Axes                  -- Actor Axes
         VisualDebugger_Collision_Aabbs             -- Collision Aabbs
         VisualDebugger_Collision_Shapes            -- Collision Shapes
         VisualDebugger_Collision_Axes              -- Collision Axes
         VisualDebugger_Collision_Compounds         -- Collision Compounds
         VisualDebugger_Collision_Vnormals          -- Collision Vnormals
         VisualDebugger_Collision_Fnormals          -- Collision Fnormals
         VisualDebugger_Collision_Edges             -- Collision Edges
         VisualDebugger_Collision_Spheres           -- Collision Spheres
         VisualDebugger_Collision_Static            -- Collision Static
         VisualDebugger_Collision_Dynamic           -- Collision Dynamic
         VisualDebugger_Collision_Free              -- Collision Free
         VisualDebugger_Collision_CCD               -- Collision CCD
         VisualDebugger_Collision_Skeletons         -- Collision Skeletons
         VisualDebugger_Fluid_Emitters              -- Fluid Emitters
         VisualDebugger_Fluid_Position              -- Fluid Position
         VisualDebugger_Fluid_Velocity              -- Fluid Velocity
         VisualDebugger_Fluid_Kernel_Radius         -- Fluid Kernel Radius
         VisualDebugger_Fluid_Bounds                -- Fluid Bounds
         VisualDebugger_Fluid_Packets               -- Fluid Packets
         VisualDebugger_Fluid_Motion_Limit          -- Fluid Motion Limit
         VisualDebugger_Fluid_Dyn_Collision         -- Fluid Dyn Collision
         VisualDebugger_Fluid_Stc_Collision         -- Fluid Stc Collision
         VisualDebugger_Fluid_Mesh_Packets          -- Fluid Mesh Packets
         VisualDebugger_Fluid_Drains                -- Fluid Drains
         VisualDebugger_Fluid_Packet_Data           -- Fluid Packet Data
         VisualDebugger_Cloth_Mesh                  -- Cloth Mesh
         VisualDebugger_Cloth_Collisions            -- Cloth Collisions
         VisualDebugger_Cloth_Selfcollisions        -- Cloth Selfcollisions
         VisualDebugger_Cloth_Workpackets           -- Cloth Workpackets
         VisualDebugger_Cloth_Sleep                 -- Cloth Sleep
         VisualDebugger_Cloth_Sleep_Vertex          -- Cloth Sleep Vertex
         VisualDebugger_Cloth_Tearable_Vertices     -- Cloth Tearable Vertices
         VisualDebugger_Cloth_Tearing               -- Cloth Tearing
         VisualDebugger_Cloth_Attachment            -- Cloth Attachment
         VisualDebugger_Cloth_Validbounds           -- Cloth Validbounds
         VisualDebugger_Softbody_Mesh               -- Softbody Mesh
         VisualDebugger_Softbody_Collisions         -- Softbody Collisions
         VisualDebugger_Softbody_Workpackets        -- Softbody Workpackets
         VisualDebugger_Softbody_Sleep              -- Softbody Sleep
         VisualDebugger_Softbody_Sleep_Vertex       -- Softbody Sleep Vertex
         VisualDebugger_Softbody_Tearable_Vertices  -- Softbody Tearable Vertices
         VisualDebugger_Softbody_Tearing            -- Softbody Tearing
         VisualDebugger_Softbody_Attachment         -- Softbody Attachment
         VisualDebugger_Softbody_Validbounds        -- Softbody Validbounds
*/
enum VisualDebugger
{
 VisualDebugger_ShowNone = 0, //!< \brief Don't show anything.
 VisualDebugger_ShowAll  = 1, //!< \brief Show all configurations of the debugger.
 VisualDebugger_World_Axes = 10,
 VisualDebugger_Body_Axes = 11,
 VisualDebugger_Body_Mass_Axes = 12,
 VisualDebugger_Body_Lin_Velocity = 13,
 VisualDebugger_Body_Ang_Velocity = 14,
 VisualDebugger_Body_Joint_Groups = 22,
 VisualDebugger_Joint_Local_Axes = 27,
 VisualDebugger_Joint_World_Axes = 28,
 VisualDebugger_Joint_Limits = 29,
 VisualDebugger_Contact_Point = 33,
 VisualDebugger_Contact_Normal = 34,
 VisualDebugger_Contact_Error = 35,
 VisualDebugger_Contact_Force = 36,
 VisualDebugger_Actor_Axes = 37,
 VisualDebugger_Collision_AABBs = 38,
 VisualDebugger_Collision_Shapes = 39,
 VisualDebugger_Collision_Axes = 40,
 VisualDebugger_Collision_Compounds = 41,
 VisualDebugger_Collision_VNormals = 42,
 VisualDebugger_Collision_FNormals = 43,
 VisualDebugger_Collision_Edges = 44,
 VisualDebugger_Collision_Spheres = 45,
 VisualDebugger_Collision_Static = 47,
 VisualDebugger_Collision_Dynamic = 48,
 VisualDebugger_Collision_Free = 49,
 VisualDebugger_Collision_CCD = 50,
 VisualDebugger_Collision_Skeletons = 51,
 VisualDebugger_Fluid_Emitters = 52,
 VisualDebugger_Fluid_Position = 53,
 VisualDebugger_Fluid_Velocity = 54,
 VisualDebugger_Fluid_Kernel_Radius = 55,
 VisualDebugger_Fluid_Bounds = 56,
 VisualDebugger_Fluid_Packets = 57,
 VisualDebugger_Fluid_Motion_Limit = 58,
 VisualDebugger_Fluid_Dyn_Collision = 59,
 VisualDebugger_Fluid_Stc_Collision = 60,
 VisualDebugger_Fluid_Mesh_Packets = 61,
 VisualDebugger_Fluid_Drains = 62,
 VisualDebugger_Fluid_Packet_Data = 90,
 VisualDebugger_Cloth_Mesh = 63,
 VisualDebugger_Cloth_Collisions = 64,
 VisualDebugger_Cloth_Selfcollisions = 65,
 VisualDebugger_Cloth_Workpackets = 66,
 VisualDebugger_Cloth_Sleep = 67,
 VisualDebugger_Cloth_Sleep_Vertex = 94,
 VisualDebugger_Cloth_Tearable_Vertices = 80,
 VisualDebugger_Cloth_Tearing = 81,
 VisualDebugger_Cloth_Attachment = 82,
 VisualDebugger_Cloth_ValidBounds = 92,
 VisualDebugger_Softbody_Mesh = 83,
 VisualDebugger_Softbody_Collisions = 84,
 VisualDebugger_Softbody_Workpackets = 85,
 VisualDebugger_Softbody_Sleep = 86,
 VisualDebugger_Softbody_Sleep_Vertex = 95,
 VisualDebugger_Softbody_Tearable_Vertices = 87,
 VisualDebugger_Softbody_Tearing = 88,
 VisualDebugger_Softbody_Attachment = 89,
 VisualDebugger_Softbody_Validbounds = 93
};

/*! enum. RenderableType
    desc.
         Type of Renderables
    enums.
         RenderableType_VisualDebugger -- PhysX Visual Debugger.
         RenderableType_PhysXMesh      -- Any Class (i.e. cloth) that PhysX determines the visual mesh.
         RenderableType_ParticlePoints -- Particles represented as seperate vertex points.
         RenderableType_SoftBody       -- A SoftBody.
*/
enum RenderableType
{
 RenderableType_VisualDebugger = 0,
 RenderableType_PhysXMesh      = 1,
 RenderableType_ParticlePoints = 2,
 RenderableType_SoftBody       = 3
};

/*! enum. MeshShapeFlag
    desc.
         Type of Renderables
         
         h4. Smooth Sphere Collisions
         
         p. Select between "normal" or "smooth" sphere-mesh/raycastcapsule-mesh contact generation routines.
         
         p. The 'normal' algorithm assumes that the mesh is composed from flat triangles. When a ball rolls
         or a raycast capsule slides along the mesh surface, it will experience small, sudden changes in
         velocity as it rolls from one triangle to the next. The smooth algorithm, on the other hand, assumes
         that the triangles are just an approximation of a surface that is smooth. It uses the Gouraud algorithm
         to smooth the triangles' vertex normals (which in this case are particularly important). 
         This way the rolling sphere's/capsule's velocity will change smoothly over time, instead of suddenly.
         We recommend this algorithm for simulating car wheels on a terrain.
         
    enums.
         MeshShapeFlag_SmoothSphereCollisions -- Apply a Gouaud algorithm to smooth the triangles out.
         MeshShapeFlag_DoubleSided            -- Mesh is double sided, but only used with Raycasting.
*/
enum MeshShapeFlag
{
 MeshShapeFlag_SmoothSphereCollisions = (1 << 0),
 MeshShapeFlag_DoubleSided            = (1 << 1)
};

/*! enum. HeightFieldTesselation
    desc.
         Tesselation mode for Quads in HeightFields
    enums.
         HeightFieldTesselation_NE_SW -- NorthEast (TopRight) to SouthWest (BottomLeft).
         HeightFieldTesselation_NW_SE -- NorthWest (TopLeft) to SouthEast (BottomRight).
*/
enum HeightFieldTesselation
{
 HeightFieldTesselation_NE_SW = 0,
 HeightFieldTesselation_NW_SE = 1
};

/*! enum. TerrainCentering
    desc.
         Terrain local pose adjustment - or not.
    enums.
         TerrainCentering_LocalPose   -- Don't center, use the local pose.
         TerrainCentering_CenterXZ    -- Center the heightfield to @scale.x / 2@ and @scale.z / 2@
         TerrainCentering_CenterAbove -- Center and move upwards, so any negative height is above the global pose of the actor.
*/
enum TerrainCentering
{
 TerrainCentering_LocalPose    = 0,
 TerrainCentering_CenterXZ     = 1,
 TerrainCentering_CenterAbove  = 2
};

/*! enum. RemoteDebuggerEventGroup
    desc.
          Used with RemoteDebuggerObjects
    enums.
         RemoteDebuggerGroup_BasicObjects             -- Basic Objects
         RemoteDebuggerGroup_BasicObjectsDynamicData  -- Basic Objects Dynamic Data
         RemoteDebuggerGroup_BasicObjectsStaticData   -- Basic Objects Static Data
         RemoteDebuggerGroup_Joints                   -- Joints
         RemoteDebuggerGroup_JointsData               -- Joints Data
         RemoteDebuggerGroup_Contacts                 -- Contacts
         RemoteDebuggerGroup_ContactsData             -- Contacts Data
         RemoteDebuggerGroup_Triggers                 -- Triggers
         RemoteDebuggerGroup_Profiling                -- Profiling
         RemoteDebuggerGroup_Cloth                    -- Cloth
         RemoteDebuggerGroup_ClothDynamicData         -- Cloth Dynamic Data
         RemoteDebuggerGroup_ClothStaticData          -- Cloth Static Data
         RemoteDebuggerGroup_SoftBody                 -- SoftBody
         RemoteDebuggerGroup_SoftBodyDynamicData      -- SoftBody Dynamic Data
         RemoteDebuggerGroup_SoftBodyStaticData       -- SoftBody Static Data
         RemoteDebuggerGroup_Fluid                    -- Fluid
         RemoteDebuggerGroup_FluidDynamicData         -- Fluid Dynamic Data
         RemoteDebuggerGroup_FluidStaticData          -- Fluid Static Data
*/
enum RemoteDebuggerEventGroup
{
 RemoteDebuggerGroup_BasicObjects             = 0x00000001,
 RemoteDebuggerGroup_BasicObjectsDynamicData  = 0x00000002,
 RemoteDebuggerGroup_BasicObjectsStaticData   = 0x00000004,
 RemoteDebuggerGroup_Joints                   = 0x00000008,
 RemoteDebuggerGroup_JointsData               = 0x00000010,
 RemoteDebuggerGroup_Contacts                 = 0x00000020,
 RemoteDebuggerGroup_ContactsData             = 0x00000040,
 RemoteDebuggerGroup_Triggers                 = 0x00000080,
 RemoteDebuggerGroup_Profiling                = 0x00000100,
 RemoteDebuggerGroup_Cloth                    = 0x00000200,
 RemoteDebuggerGroup_ClothDynamicData         = 0x00000400,
 RemoteDebuggerGroup_ClothStaticData          = 0x00000800,
 RemoteDebuggerGroup_SoftBody                 = 0x00001000,
 RemoteDebuggerGroup_SoftBodyDynamicData      = 0x00002000,
 RemoteDebuggerGroup_SoftBodyStaticData       = 0x00004000,
 RemoteDebuggerGroup_Fluid                    = 0x00008000,
 RemoteDebuggerGroup_FluidDynamicData         = 0x00010000,
 RemoteDebuggerGroup_FluidStaticData          = 0x00020000
};
 
/*! enum. RemoteDebuggerMask
    desc.
          Used to filter out events in the Remote Debugger.
    note.
         RemoteDebuggerMasks are combined together with the @|@ (or) operator.
    enums.
         RemoteDebuggerMask_Everything                -- Everything.
         RemoteDebuggerMask_BasicObjects              -- Basic Objects.
         RemoteDebuggerMask_BasicObjectsDynamicData   -- Dynamic data for Basic Objects.
         RemoteDebuggerMask_BasicObjectsStaticData    -- Static data for Basic Objects.
         RemoteDebuggerMask_BasicObjectsAll           -- Dynamic and Static data for Basic Objects.
         RemoteDebuggerMask_Joints                    -- Joints.
         RemoteDebuggerMask_JointsData                -- Joints data.
         RemoteDebuggerMask_Contacts                  -- Contacts
         RemoteDebuggerMask_ContactsData              -- Contacts data,
         RemoteDebuggerMask_Triggers                  -- Volumes/Triggers
         RemoteDebuggerMask_Profiling                 -- Profiling data.
         RemoteDebuggerMask_Cloth                     -- Cloth
         RemoteDebuggerMask_ClothDynamicData          -- Cloth Dynamic Data
         RemoteDebuggerMask_ClothStaticData           -- Cloth Static Data
         RemoteDebuggerMask_ClothAllData              -- Cloth Dynamic and Static data.
         RemoteDebuggerMask_Fluid                     -- Fluid
         RemoteDebuggerMask_FluidDynamicData          -- Fluid Dynamic data
         RemoteDebuggerMask_FluidStaticData           -- Fluid Static data
         RemoteDebuggerMask_FluidAllData              -- Fluid Dynamic and Static data.
*/
enum RemoteDebuggerMask
{
 RemoteDebuggerMask_Everything                = 0xFFFFFFFF,
 RemoteDebuggerMask_BasicObjects              = RemoteDebuggerGroup_BasicObjects,
 RemoteDebuggerMask_BasicObjectsDynamicData   = (RemoteDebuggerGroup_BasicObjects | RemoteDebuggerGroup_BasicObjectsDynamicData),
 RemoteDebuggerMask_BasicObjectsStaticData    = (RemoteDebuggerGroup_BasicObjects | RemoteDebuggerGroup_BasicObjectsStaticData),
 RemoteDebuggerMask_BasicObjectsAll           = (RemoteDebuggerMask_BasicObjectsDynamicData | RemoteDebuggerMask_BasicObjectsStaticData),
 RemoteDebuggerMask_Joints                    = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_JointsData                = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_JointsData | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_Contacts                  = (RemoteDebuggerGroup_Contacts | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_ContactsData              = (RemoteDebuggerGroup_Joints | RemoteDebuggerGroup_JointsData | RemoteDebuggerGroup_BasicObjects),
 RemoteDebuggerMask_Triggers                  = (RemoteDebuggerGroup_Triggers),
 RemoteDebuggerMask_Profiling                 = (RemoteDebuggerGroup_Profiling),
 RemoteDebuggerMask_Cloth                     = (RemoteDebuggerGroup_Cloth),
 RemoteDebuggerMask_ClothDynamicData          = (RemoteDebuggerGroup_Cloth | RemoteDebuggerGroup_ClothDynamicData),
 RemoteDebuggerMask_ClothStaticData           = (RemoteDebuggerGroup_Cloth | RemoteDebuggerGroup_ClothStaticData),
 RemoteDebuggerMask_ClothAllData              = (RemoteDebuggerMask_ClothDynamicData | RemoteDebuggerMask_ClothStaticData),
 RemoteDebuggerMask_Fluid                     = (RemoteDebuggerGroup_Fluid),
 RemoteDebuggerMask_FluidDynamicData          = (RemoteDebuggerGroup_Fluid | RemoteDebuggerGroup_FluidDynamicData),
 RemoteDebuggerMask_FluidStaticData           = (RemoteDebuggerGroup_Fluid | RemoteDebuggerGroup_FluidStaticData),
 RemoteDebuggerMask_FluidAllData              = (RemoteDebuggerMask_FluidDynamicData | RemoteDebuggerMask_FluidStaticData),
};

/*! enum. RemoteDebuggerObjectType
    desc.
          Type of Remote Debugger Object
    enums.
         RemoteDebuggerObjectType_Generic     -- Generic Object
         RemoteDebuggerObjectType_Actor       -- RigidBody (NxActor)
         RemoteDebuggerObjectType_Plane       -- PlaneGeometry
         RemoteDebuggerObjectType_Box         -- Box
         RemoteDebuggerObjectType_Sphere      -- Sphere
         RemoteDebuggerObjectType_Capsule     -- Capsule
         RemoteDebuggerObjectType_Cylinder    -- Cylinder
         RemoteDebuggerObjectType_Convex      -- Convex
         RemoteDebuggerObjectType_Mesh        -- TriangleMeshGeometry
         RemoteDebuggerObjectType_Wheel       -- Wheel
         RemoteDebuggerObjectType_Joint       -- Joint
         RemoteDebuggerObjectType_Contact     -- Contacts
         RemoteDebuggerObjectType_BoundingBox -- Bounding Box
         RemoteDebuggerObjectType_Vector      -- Vector (NxVec3)
         RemoteDebuggerObjectType_Camera      -- RemoteDebugger Camera
         RemoteDebuggerObjectType_Cloth       -- Cloth
         RemoteDebuggerObjectType_SoftBody    -- SoftBody
         RemoteDebuggerObjectType_Fluid       -- Fluid
         RemoteDebuggerObjectType_Forcefield  -- Forcefield
*/
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

/*! enum. JointFunctionType
    desc.
          Type of Joint
    note.
         Compatible with @NxJointType@.
    enums.
         JointFunctionType_Prismatic     -- Prismatic joint
         JointFunctionType_Revolute      -- Revolute joint
         JointFunctionType_Cylindrical   -- Cylindrical joint
         JointFunctionType_Spherical     -- Spherical joint
         JointFunctionType_PointOnLine   -- PointOnLine joint
         JointFunctionType_PointInPlane  -- PointInPlane joint
         JointFunctionType_Distance      -- Distance joint
         JointFunctionType_Pulley        -- Pulley joint
         JointFunctionType_Fixed         -- Fixed joint
         JointFunctionType_D6            -- D6 Joint
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

/*! enum. JointState
    desc.
          Type of Joint
    note.
         Mostly compatible with @NxJointState@. apart from JointState_Dead
    enums.
         JointState_Unbound -- Not used. 
         JointState_Simulating -- The joint is being simulated under normal conditions. I.e. it is not broken or deleted. 
         JointState_Broken -- Set when the joint has been broken or one of the actors connected to the joint has been remove.
         JointState_Dead -- Joint has not been created yet or has been deleted.
*/
enum JointState
{
 JointState_Unbound,
 JointState_Simulating,
 JointState_Broken,
 JointState_Dead
};

/*! enum. JointFlag
    desc.
         Flags for Joints
    note.
         Compatible with @NxJointFlag@.
    enums.
         JointFlag_CollisionEnabled --  Raised if collision detection should be enabled between the bodies attached to the joint.
         JointFlag_Visualisation -- Visualised in the debug renderer.
*/
enum JointFlag
{
 JointFlag_CollisionEnabled = (1 << 0), 
 JointFlag_Visualisation    = (1 << 1)
};

/*! enum. JointProjectionMode
    desc.
         Joint projection is a method for correcting large joint errors.
    note.
         Compatible with @NxJointProjectionMode@.
    enums.
         JointProjectionMode_None -- Don't project this joint 
         JointProjectionMode_Point_MiniumDistance -- Linear and angular minimum distance projection 
         JointProjectionMode_Linear_MiniumDistance -- Linear only minimum distance projection 
*/
enum JointProjectionMode
{
 JointProjectionMode_None                   = 0,
 JointProjectionMode_Point_MiniumDistance   = 1,
 JointProjectionMode_Linear_MiniumDistance  = 2
};

/*! enum. RevoluteJointFlags
    desc.
         Control the behavior of revolute joints.
    note.
         Compatible with @NxRevoluteJointFlag@.
    enums.
         RevoluteJointFlags_LimitEnabled  -- Are limits enabled
         RevoluteJointFlags_MotorEnabled  -- Is the motor enabled
         RevoluteJointFlags_SpringEnabled -- Is the spring enabled, but will only take effect if the motor is _disabled_.
*/
enum RevoluteJointFlags
{
 RevoluteJointFlags_LimitEnabled  = 1 << 0,
 RevoluteJointFlags_MotorEnabled  = 1 << 1,
 RevoluteJointFlags_SpringEnabled = 1 << 2,
};

/*! enum. PulleyJointFlags
    desc.
         Control the behavior of pulley joints.
    note.
         Compatible with @NxPulleyJointFlag@.
    enums.
         PulleyJointFlags_IsRigid  -- The joint also maintains a minimum distance, not just a maximum
         PulleyJointFlags_MotorEnabled  -- Is the motor enabled
*/
enum PulleyJointFlags
{
 PulleyJointFlags_IsRigid       = 1 << 0,
 PulleyJointFlags_MotorEnabled  = 1 << 1
};

/*! enum. DistanceJointFlags
    desc.
         Control the behavior of distance joints.
    note.
         Compatible with @NxDistanceJointFlag@.
    enums.
         DistanceJointFlags_MaxDistanceEnabled -- The joint enforces the maximum separate distance.
         DistanceJointFlags_MinDistanceEnabled -- The joint enforces the minimum separate distance.
         DistanceJointFlags_SpringEnabled      -- The spring is enabled
*/
enum DistanceJointFlags
{
 DistanceJointFlags_MaxDistanceEnabled = 1 << 0,
 DistanceJointFlags_MinDistanceEnabled = 1 << 1,
 DistanceJointFlags_SpringEnabled      = 1 << 2
};

/*! enum. D6JointMotion
    desc.
         Used to specifiy the range of motions allowed for a DOF in a D6 joint.
    note.
         Compatible with @NxD6JointMotion@.
    enums.
         D6JointMotion_Locked  -- The DOF is locked, it does not allow relative motion.
         D6JointMotion_Limited -- The DOF is limited, it only allows motion within a specific range.
         D6JointMotion_Free    -- The DOF is free and has its full range of motions.
*/
enum D6JointMotion
{
 D6JointMotion_Locked,
 D6JointMotion_Limited,
 D6JointMotion_Free,
};

/*! enum. D6JointMotion
    desc.
         Used to specify a particular drive method. i.e. Having a position based goal or a velocity based goal.
    note.
         Compatible with @NxD6JointDriveType@.
    enums.
         D6JointDriveType_Position  -- Used to set a position goal when driving.
         D6JointMotion_Limited -- Used to set a velocity goal when driving.
*/
enum D6JointDriveType
{
 D6JointDriveType_Position = 1 << 0,
 D6JointDriveType_Velocity = 1 << 1
};


/*! enum. D6JointFlag
    desc.
         Control the general behavior of D6 joints.
    note.
         Compatible with @NxD6JointFlag@.
    enums.
         D6JointFlag_SlerpDrive  -- Drive along the shortest spherical arc
         D6JointFlag_GearEnabled -- Apply gearing to the angular motion, e.g. body 2s angular motion is twice body 1s etc.
*/
enum D6JointFlag
{
 D6JointFlag_SlerpDrive  = 1 << 0,
 D6JointFlag_GearEnabled = 1 << 1
};

/*! enum. JointSpringType
    desc.
         Joint spring type
    enums.
         JointSpringType_Force  -- Force
         JointSpringType_Acceleration -- Acceleration
*/
enum JointSpringType
{
 JointSpringType_Force        = 0,
 JointSpringType_Acceleration = 1
};

/*! enum. SphericalJointFlags
    desc.
         Spherical joint spring type
    note.
         Compatible with @NxSphericalJointFlag@.
    enums.
         SphericalJointFlags_TwistLimitEnabled - Enable twist limits.
         SphericalJointFlags_SwingLimitEnabled - Enable swing limits.
         SphericalJointFlags_TwistSpringEnabled - Enable twist spring.
         SphericalJointFlags_SwingSpringEnabled - Enable swing spring.
         SphericalJointFlags_JointSpringEnabled - Enable joint spring.
         SphericalJointFlags_PerpendicularDirectionConstraints - Enable perpendicular direction constraints.
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

/*! enum. WheelFlags
    desc.
         Flags to use with Wheels
    note.
         Compatible with @NxWheelFlag@.
    enums.
         WheelFlags_AxisContactNormal       -- Determines whether the suspension axis or ground contact normal is used for the suspension constraint.
         WheelFlags_InputLatSlipVelocity    -- The laterial slip veloicty is used as the input to the tire function, rather than the slip angle.
         WheelFlags_InputLongSlipVelocity   -- The longutudal slip veloicty is used as the input to the tire function, rather than the slip angle.
         WheelFlags_UnscaledSpringBehaviour -- Does not factor out the suspension travel and wheel radius from the spring force computation. This is the legacy behaviour from the raycast capsule approach.
         WheelFlags_AxleSpeedOverride       -- The axle speed is not computed by the simulation but is rather expected to be provided by the user every simulation step via Wheel::setAxleSpeed()
         WheelFlags_EmulateLegacyWheel      -- The Wheel will emulate the PhysX legacy raycast capsule based wheel.
         WheelFlags_ClampedFriction         -- The Wheel will clamp the force in the friction constraints.
*/
enum WheelFlags
{
 WheelFlags_AxisContactNormal           = (1<<0),
 WheelFlags_InputLatSlipVelocity        = (1<<1),
 WheelFlags_InputLongSlipVelocity       = (1<<2),
 WheelFlags_UnscaledSpringBehaviour     = (1<<3),
 WheelFlags_AxleSpeedOverride           = (1<<4),
 WheelFlags_EmulateLegacyWheel          = (1<<5),
 WheelFlags_ClampedFriction             = (1<<6)
};

/*! enum. ClothFlags
    desc.
         Flags to use with Cloth
    note.
         Compatible with @NxClothFlag@.
    enums.
         ClothFlags_Pressure                    -- Enable pressure simulation for closed cloth meshes.
         ClothFlags_Static                      -- Make the cloth static.
         ClothFlags_DisableRigidBodyCollision   -- Disable collision with RigidBodies.
         ClothFlags_DisableSelfCollision        -- Disable collision with itself.
         ClothFlags_DebugVisualisation          -- Enable to be visualised when the visual debugger is on.
         ClothFlags_Gravity                     -- Respond to scene gravity.
         ClothFlags_BendingResistance           -- Enable bending resistance.
         ClothFlags_OrthogonalBendingResistance -- Enable orthogonal bending resistance.
         ClothFlags_Damping                     -- Enable damping of internal velocities.
         ClothFlags_TwoWayCollisions            -- Enable two way collisions with rigid bodies.
         ClothFlags_Tearable                    -- Enables tearing of the cloth.
         ClothFlags_Hardware                    -- Enables simulating the cloth on a PPU or GPU.
         ClothFlags_COMDamping                  -- Enable center of mass damping of internal velocities.
         ClothFlags_ValidBounds                 -- If set particles outside the bounds will be removed.
         ClothFlags_FluidCollision              -- Enable collisions with fluids.
         ClothFlags_DisableDynamicCCD           -- Disable continuous collision detection with dynamic actor
         ClothFlags_Adhere                      -- Moves cloth partially in the frame of the attached actor.
*/
enum ClothFlags
{
 ClothFlags_Pressure                    = (1<<0), 
 ClothFlags_Static                      = (1<<1), 
 ClothFlags_DisableRigidBodyCollision   = (1<<2), 
 ClothFlags_DisableSelfCollision        = (1<<3), 
 ClothFlags_DebugVisualisation          = (1<<4), 
 ClothFlags_Gravity                     = (1<<5), 
 ClothFlags_BendingResistance           = (1<<6), 
 ClothFlags_OrthogonalBendingResistance = (1<<7), 
 ClothFlags_Damping                     = (1<<8), 
 ClothFlags_TwoWayCollisions            = (1<<9), 
// ClothFlags_TriangleCollision,        = (1<<11)
 ClothFlags_Tearable                    = (1<<12),
 ClothFlags_Hardware                    = (1<<13),
 ClothFlags_COMDamping                  = (1<<14),
 ClothFlags_ValidBounds                 = (1<<15),
 ClothFlags_FluidCollision              = (1<<16),
 ClothFlags_DisableDynamicCCD           = (1<<17),
 ClothFlags_Adhere                      = (1<<18),
};

/*! enum. ClothAttachmentFlags
    desc.
         Flags to use with Cloth when attaching vertices.
    note.
         Compatible with @NxClothAttachmentFlag@.
    enums.
         ClothAttachmentFlags_Twoway            -- Allow cloth &rArr; object interaction.
         ClothAttachmentFlags_Tearable          -- Vertex is tearable.
*/
enum ClothAttachmentFlags
{
 ClothAttachmentFlags_Twoway            = (1<<0), 
 ClothAttachmentFlags_Tearable          = (1<<1), 
};

/*! enum. ClothVertexAttachmentStatus
    desc.
         Set of attachment states a vertex can be in.
    note.
         Compatible with @NxClothVertexAttachmentStatus@.
    enums.
         ClothVertexAttachmentStatus_None   -- Vertex is not attached.
         ClothVertexAttachmentStatus_Global -- Vertex is attached to the global frame.
         ClothVertexAttachmentStatus_Shape  -- Vertex is attached to a shape.
*/
enum ClothVertexAttachmentStatus
{
 ClothVertexAttachmentStatus_None,
 ClothVertexAttachmentStatus_Global,
 ClothVertexAttachmentStatus_Shape
};

/*! enum. MeshConstructionFlags
    desc.
         Set of flags used when constructing meshes.
    enums.
         MeshConstructionsFlags_FlipNormals   -- Flip the normals
         MeshConstructionsFlags_16bitIndices  -- Use smaller 16-bit vertices
         MeshConstructionsFlags_HardwareMesh  -- Mesh will be used in hardware scenes.
*/
enum MeshConstructionFlags
{
 MeshConstructionsFlags_FlipNormals,
 MeshConstructionsFlags_16bitIndices,
 MeshConstructionsFlags_HardwareMesh
};

/*! enum. SoftBodyFlags
    desc.
         Set of flags used when constructing softbodies.
    enums.
         SoftBodyFlags_Static                     -- Make the Soft Body static.
         SoftBodyFlags_DisableRigidBodyCollision  -- Disable collision with RigidBodies.
         SoftBodyFlags_DisableSelfCollision       -- Disable collision with itself.
         SoftBodyFlags_DebugVisualisation         -- Enable to be visualised when the visual debugger is on.
         SoftBodyFlags_Gravity                    -- Respond to scene gravity.
         SoftBodyFlags_VolumeConservation         -- Enable volume conservation.
         SoftBodyFlags_Damping                    -- Enable of internal velocities.
         SoftBodyFlags_TwoWayCollisions           -- Enable two way collisions with rigid bodies.
         SoftBodyFlags_Tearable                   -- Enables tearing of the Soft Body.
         SoftBodyFlags_Hardware                   -- Enables simulating the Soft Body on a PPU or GPU.
         SoftBodyFlags_COMDamping                 -- Enable center of mass damping of internal velocities.
         SoftBodyFlags_ValidBounds                -- If set particles outside the bounds will be removed.
         SoftBodyFlags_FluidCollision             -- Enable collisions with fluids.
         SoftBodyFlags_DisableDynamicCCD          -- Disable continuous collision detection with dynamic actors.
         SoftBodyFlags_Adhere                     -- Moves Soft Body partially in the frame of the attached actor.
*/
enum SoftBodyFlags
{
 SoftBodyFlags_Static                      = (1<<1), 
 SoftBodyFlags_DisableRigidBodyCollision   = (1<<2), 
 SoftBodyFlags_DisableSelfCollision        = (1<<3), 
 SoftBodyFlags_DebugVisualisation          = (1<<4), 
 SoftBodyFlags_Gravity                     = (1<<5), 
 SoftBodyFlags_VolumeConservation          = (1<<6), 
 SoftBodyFlags_Damping                     = (1<<7), 
 SoftBodyFlags_TwoWayCollisions            = (1<<8), 
 SoftBodyFlags_Tearable                    = (1<<9), 
 SoftBodyFlags_Hardware                    = (1<<10),
 SoftBodyFlags_COMDamping                  = (1<<11),
 SoftBodyFlags_ValidBounds                 = (1<<12),
 SoftBodyFlags_FluidCollision              = (1<<13),
 SoftBodyFlags_DisableDynamicCCD           = (1<<14),
 SoftBodyFlags_Adhere                      = (1<<15)
};

/*! enum. SoftBodyAttachmentFlags
    desc.
         Set of flags used when attach softbody vertices.
    enums.
         SoftBodyAttachmentFlags_Twoway    -- The default is only object->Soft Body interaction (one way).
         SoftBodyAttachmentFlags_Tearable  -- When this flag is set, the attachment is tearable.
*/
enum SoftBodyAttachmentFlags
{
 SoftBodyAttachmentFlags_Twoway   = (1<<0),
 SoftBodyAttachmentFlags_Tearable = (1<<1)
};

/*! enum. DeviceCode
    desc.
         DeviceCode are used with compartments
    note.
         Compatible with @NxDeviceCode@.
    enums.
         DeviceCode_PPU0       -- Explicit PPU index corresponds to index numeric value (reserved for future use, currently only PPU 0 is valid). 
         DeviceCode_PPU1       -- Not Used.
         DeviceCode_PPU2       -- Not Used.
         DeviceCode_PPU3       -- Not Used.
         DeviceCode_PPU4       -- Not Used.
         DeviceCode_PPU5       -- Not Used.
         DeviceCode_PPU6       -- Not Used.
         DeviceCode_PPU7       -- Not Used.
         DeviceCode_PPU8       -- Not Used.
         DeviceCode_CPU        -- Compartment is to be simulated on CPU.
         DeviceCode_AutoAssign -- Compartment is to be simulated on a processor (PPU or CPU) chosen by the HSM for best performance (CPU is only used in the absence of a PPU). .
*/
enum DeviceCode
{
 DeviceCode_PPU0       = 0,
 DeviceCode_PPU1       = 1,
 DeviceCode_PPU2       = 2,
 DeviceCode_PPU3       = 3,
 DeviceCode_PPU4       = 4,
 DeviceCode_PPU5       = 5,
 DeviceCode_PPU6       = 6,
 DeviceCode_PPU7       = 7,
 DeviceCode_PPU8       = 8,
 DeviceCode_CPU        = 0xffff0000,
 DeviceCode_AutoAssign = 0xffff0001
};

/*! enum. CompartmentType
    desc.
         DeviceCode are used with compartments
    note.
         Compatible with @NxCompartmentType@.
    enums.
         CompartmentType_RigidBody -- RigidBody Compartment.
         CompartmentType_Fluid     -- Fluid Compartment.
         CompartmentType_Cloth     -- Cloth Compartment.
         CompartmentType_SoftBody  -- SoftBody Compartment.
*/
enum CompartmentType
{
 CompartmentType_RigidBody = 0,
 CompartmentType_Fluid     = 1,
 CompartmentType_Cloth     = 2,
 CompartmentType_SoftBody  = 2,
};

/*! enum. CompartmentFlags
    desc.
         DeviceCode are used with compartments
    note.
         Compatible with @NxCompartmentType@.
    enums.
         CompartmentFlags_SleepNotification -- Enable/disable sleep event reporting
         CompartmentFlags_ContinuousCD      -- Enable/disable continuous collision detection
         CompartmentFlags_RestrictedScene   -- Enable Restricted Scene on the compartment. (Hardware only) (Immutable)
         CompartmentFlags_InheritSettings   -- Inherit CCD and Restricted Scene.
*/
enum CompartmentFlags
{
 CompartmentFlags_SleepNotification        = (1<<0),
 CompartmentFlags_ContinuousCD             = (1<<1),
 CompartmentFlags_RestrictedScene          = (1<<2),
 CompartmentFlags_InheritSettings          = (1<<3)
};

/*! enum. ParticleFlags
    desc.
         Particle flags are used to give some additional information about the particles.
    note.
         Compatible with @NxParticleFlag@.
    enums.
         ParticleFlags_CollisionWithStatic  -- Collision with Static
         ParticleFlags_CollisionWithDynamic -- Collision with Dynamic
         ParticleFlags_Seperated            -- Seperated
         ParticleFlags_MotionLimitReached   -- ParticleFlags_MotionLimitReached
*/
enum ParticleFlags
{
 ParticleFlags_CollisionWithStatic         = (1<<0),
 ParticleFlags_CollisionWithDynamic        = (1<<1),
 ParticleFlags_Seperated                   = (1<<2),
 ParticleFlags_MotionLimitReached          = (1<<3)
};

/*! enum. FluidSimulationMethod
    desc.
         Describes the particle simulation method
         
         p. Particles can be treated in two ways: either they are simulated considering
         interparticular forces (SPH), or they are simulated independently.
         In the latter case (with the simulation method set to FluidSimulationMethod_NoParticleInteraction),
         you still get collision between particles and static/dynamic shapes, damping,
         acceleration due to gravity, and the user force.
   note.
         Compatible with @NxFluidSimulationMethod@.
   enums.
        FluidSimulationMethod_SPH                   -- Enable simulation of inter particle forces.
        FluidSimulationMethod_NoParticleInteraction -- Do not simulate inter particle forces.
        FluidSimulationMethod_MixedMode             -- Alternate between SPH and simple particles
*/
enum FluidSimulationMethod
{
 FluidSimulationMethod_SPH                   = (1<<0), 
 FluidSimulationMethod_NoParticleInteraction = (1<<1),
 FluidSimulationMethod_MixedMode             = (1<<2)
};

/*! enum. FluidCollisionMethod
    desc.
         The NxFluid instance can be selected for collision with both static and dynamic shapes.
    note.
         Compatible with @NxFluidCollisionMethod@.
    enums.
         FluidCollisionMethod_Static         -- Collide with static shapes.
         FluidCollisionMethod_Dynamic        -- Collide with dynamic shapes.
*/
enum FluidCollisionMethod
{
 FluidCollisionMethod_Static                 = (1<<0),
 FluidCollisionMethod_Dynamic                = (1<<1)
};

/*! enum. FluidFlags
    desc.
         Flags used with fluids.
    note.
         Compatible with @NxFluidFlag@.
    enums.
         FluidFlags_Visualisation               -- Enables debug visualization for the Fluid.
         FluidFlags_DisableGravity              -- Disables scene gravity for the Fluid.
         FluidFlags_CollisionTwoWay             -- Enable/disable two way collision of fluid with the rigid body scene.
         FluidFlags_Enabled                     -- Enable/disable execution of fluid simulation.
         FluidFlags_Hardware                    -- Defines whether this fluid is simulated on the PPU.
         FluidFlags_PriorityMode                -- Enable/disable particle priority mode. 
         FluidFlags_ProjectToPlane              -- Defines whether the particles of this fluid should be projected to a plane.
         FluidFlags_ForceStrictCookingFormat    -- Currently not implemented
*/
enum FluidFlags
{
 FluidFlags_Visualisation                    = (1<<0),
 FluidFlags_DisableGravity                   = (1<<1),
 FluidFlags_CollisionTwoWay                  = (1<<2),
 FluidFlags_Enabled                          = (1<<3),
 FluidFlags_Hardware                         = (1<<4),
 FluidFlags_PriorityMode                     = (1<<5),
 FluidFlags_ProjectToPlane                   = (1<<6),
 FluidFlags_ForceStrictCookingFormat         = (1<<7)
};


/*! enum. ContactPairFlags
    desc.
         Flags used for contacts
    note.
         Compatible with @NxContactPairFlag@.
         ContactPairFlags are combined together with the @|@ (or) operator.
    enums.
         ContactPairFlags_Ignore                     -- Disable contact generation
         ContactPairFlags_StartTouch                 -- Pair callback will be called when the pair starts to be in contact.
         ContactPairFlags_StopTouch                  -- Pair callback will be called when the pair stops to be in contact.
         ContactPairFlags_Touch                      -- Pair callback will be called whilst the pair is in contact.
         ContactPairFlags_Forces                     -- The (summed total) frictional force and normal force will be given in the ContactPair struct
         ContactPairFlags_StartTouchThreshold        -- Pair callback will be called when the contact force between two RigidBodies exceeds one of the actor-defined force thresholds.
         ContactPairFlags_StopTouchThreshold         -- Pair callback will be called when the contact force between two RigidBodies falls below one of the actor-defined force thresholds.
         ContactPairFlags_TouchThreshold             -- Pair callback will keep getting called when the contact force between two RigidBodies falls below one of the actor-defined force thresholds.
         ContactPairFlags_ContactModifcation         -- Generate a callback for all associated contact constraints, making it possible to edit the constraint.
         ContactPairFlags_All                        -- Generate all contacts
*/
enum ContactPairFlags
{
 ContactPairFlags_Ignore                     = (1<<0),
 ContactPairFlags_StartTouch                 = (1<<1),
 ContactPairFlags_StopTouch                  = (1<<2),
 ContactPairFlags_Touch                      = (1<<3),
 ContactPairFlags_Forces                     = (1<<7),
 ContactPairFlags_StartTouchThreshold        = (1<<8),
 ContactPairFlags_StopTouchThreshold         = (1<<9),
 ContactPairFlags_TouchThreshold             = (1<<10),
 ContactPairFlags_ContactModifcation         = (1<<16),
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


/*! enum. SweepFlags
    desc.
         Flags used for sweep testings
    note.
         Compatible with @NxSweepFlags@.
         ContactPairFlags are combined together with the @|@ (or) operator.
    enums.
         SweepFlags_Statics             -- Sweep vs static objects (SceneGeometries)
         SweepFlags_Dynamics            -- Sweep vs dynamic objects (Not SceneGeometries)
         SweepFlags_AllHits             -- Reports all hits rather than the closest ones.
*/
enum SweepFlags
{
 SweepFlags_Statics                          = (1 << 0),
 SweepFlags_Dynamics                         = (1 << 1),
 SweepFlags_AllHits                          = (1 << 3)
};


/*! enum. FluidEmitterFlags
    desc.
        Flags that control the behaviour of fluid emitters.
    note.
        Compatible with @NxFluidEmitterFlag@
    enums.
         FluidEmitterFlags_Visualisation   -- Should the emitters be shown in the VisualDebugger.
         FluidEmitterFlags_ForceOnBody     -- Should the emission cause a force on the attached Shape's RigidBody.
         FluidEmitterFlags_AddBodyVelocity -- If set, then the attached RigidBody's velocity should be added to the particles velocity.
         FluidEmitterFlags_Enabled         -- Enable/Disable the FluidEmitter.
*/
enum FluidEmitterFlags
{
 FluidEmitterFlags_Visualisation   = (1<<0),
 FluidEmitterFlags_ForceOnBody     = (1<<2),
 FluidEmitterFlags_AddBodyVelocity = (1<<3),
 FluidEmitterFlags_Enabled         = (1<<4)
};


/*! enum. FluidEmitterShape
    desc.
         The shape of the area of the emission.
    note.
         Compatible with @NxEmitterShape@
    enums.
         FluidEmitterShape_Rectangular -- A Rectangle
         FluidEmitterShape_Ellipse     -- An Ellipse
*/
enum FluidEmitterShape
{
 FluidEmitterShape_Rectangular = (1<<0),
 FluidEmitterShape_Ellipse     = (1<<1)
};

/*! enum. FluidEmitterType
    desc.
         Type of Fluid Emitter
    note.
         Compatible with @NxEmitterType@
    enums.
         FluidEmitterType_Pressure -- Pressure
         FluidEmitterType_FlowRate -- Flow rate
*/
enum FluidEmitterType
{
 FluidEmitterType_Pressure = (1<<0),
 FluidEmitterType_FlowRate = (1<<1)
};


enum MeshPagingMode
{
 MeshPagingMode_Manual,
 MeshPagingMode_Fallback,
 MeshPagingMode_Auto,
};

/*! enum. ForceFieldType
    desc.
         Type of Force Field.
    note.
         Compatible with @NxForceFieldType@
    enums.
         ForceFieldType_Gravitational -- Scales the force by the mass of the particle or rigid body.
         ForceFieldType_Other -- Does not scale the value from the force field.
         ForceFieldType_NoInteraction -- Used to disable force field interaction with a specific feature.
*/
enum ForceFieldType
{
 ForceFieldType_Gravitational = 2,
 ForceFieldType_Other = 3,
 ForceFieldType_NoInteraction = 4,
};

/*! enum. ForceFieldType
    desc.
         Type of Force Field.
    note.
         Compatible with @NxForceFieldFlags@
    enums.
         ForceFieldFlag_ScalingFluid -- indicates whether the force is scaled by the amount of volume represented by the feature.
         ForceFieldFlag_ScalingCloth -- indicates whether the force is scaled by the amount of volume represented by the feature.
         ForceFieldFlag_ScalingSoftBody -- indicates whether the force is scaled by the amount of volume represented by the feature.
         ForceFieldFlag_ScalingRigidBody -- indicates whether the force is scaled by the amount of volume represented by the feature.
*/
enum ForceFieldFlags
{
 ForceFieldFlag_ScalingFluid = (1 << 5),
 ForceFieldFlag_ScalingCloth = (1 << 6),
 ForceFieldFlag_ScalingSoftBody = (1 << 7),
 ForceFieldFlag_ScalingRigidBody = (1 << 8),
};

#if NxOgreHasCharacterController == 1

enum CharacterControllerInteractionFlag
{
 CharacterControllerInteractionFlag_Include,
 CharacterControllerInteractionFlag_Exclude,
 CharacterControllerInteractionFlag_UseFilter
};

#endif

enum FilterOp
{
 FilterOp_And,
 FilterOp_Or,
 FilterOp_Xor,
 FilterOp_Nand,
 FilterOp_Nor,
 FilterOp_NXor,
 FilterOp_SwapAnd
};

enum SceneFunction
{
 SceneFunction_Simulate,
 SceneFunction_Render
};

                                                                                       

} // namespace Enums

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

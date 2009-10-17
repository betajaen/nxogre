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

                                                                                       

#ifndef NXOGRE_CLASSES_H
#define NXOGRE_CLASSES_H

                                                                                       


namespace NxOgre
{

namespace Classes
{

enum
{
  NXOGRE_CLASSES_BEGIN = 457,
  _void,
  _bool,
  _char,
  _short,
  _int,
  _float,
  _double,
  _long,
  _unsigned_char,
  _unsigned_short,
  _unsigned_int,
  _unsigned_long,
  _AccumulativeSceneTimer,
  _ActiveParticle,
  _Actor,
  _ActorMachinePart,
  _Archive,
  _ArchiveMetaData,
  _Array,
  _ArrayReferenceCounter,
  _ArrayUnknown,
  _Box,
  _Buffer,
  _BufferReferenceCounter,
  _BufferUnknown,
  _Callback,
  _Capsule,
  _CCDSkeletonMeshData,
  _CircularBufferReferenceCounter,
  _Cloth,
  _ClothDescription,
  _ClothRaycastHit,
  _Compartment,
  _CompartmentDescription,
  _ConstantArray,
  _ContactPair,
  _Convex,
  _D6Joint,
  _D6JointDescription,
  _DebugRenderable,
  _ErrorStream,
  _FileArchive,
  _FileResource,
  _FileResourceProtocol,
  _FixedJoint,
  _FixedSceneTimer,
  _Fluid,
  _FluidDescription,
  _FluidDrain,
  _FluidDrainDescription,
  _FluidEmitter,
  _FluidEmitterDescription,
  _FluidPacket,
  _Geometry,
  _HeightField,
  _HeightFieldData,
  _HeightFieldGeometry,
  _HeightFieldGeometryBlueprint,
  _HeightFieldManager,
  _HeightFieldSample,
  _int2,
  _int3,
  _int4,
  _Joint,
  _JointDescription,
  _JointLimitDescription,
  _JointLimitSoftDescription,
  _KinematicActor,
  _KinematicController,
  _Machine,
  _MachinePart,
  _ManualHeightField,
  _ManualHeightFieldReferenceCounter,
  _ManualMesh,
  _ManualMeshReferenceCounter,
  _Material,
  _MaterialDescription,
  _MaterialPrototype,
  _Memory,
  _MemoryArchive,
  _MemoryResource,
  _MemoryResourceProtocol,
  _Mesh,
  _MeshData,
  _MeshManager,
  _MeshSerialiser,
  _MeshStats,
  _MotorDescription,
  _NxShapeFunctions,
  _Particle,
  _ParticleData,
  _Path,
  _PhysXCallback,
  _PhysXMeshData,
  _PhysXOutputStream,
  _PhysXParticleData,
  _PhysXPointer,
  _PhysXShapePointer,
  _PhysXUserAllocator,
  _PlaneGeometry,
  _PlaneGeometryPrototype,
  _PointerClass,
  _PointParticleRenderer,
  _PointRenderable,
  _Ray,
  _RaycastHit,
  _RemoteDebugger,
  _RemoteDebuggerListener,
  _Renderable,
  _Resource,
  _ResourceProtocol,
  _ResourceSystem,
  _RestingParticle,
  _RevoluteJoint,
  _RevoluteJointDescription,
  _RigidBody,
  _RigidBodyDescription,
  _Scene,
  _SceneDescription,
  _SceneGeometry,
  _ScenePrototype,
  _SceneRenderer,
  _SceneTimer,
  _Shape,
  _Shape_Abstract,
  _ShapeBlueprint,
  _SharedArray,
  _SharedBuffer,
  _SharedCircularBuffer,
  _SharedKinematicFunctions,
  _SimpleBox,
  _SimpleCapsule,
  _SimplePlane,
  _SimplePointCloud,
  _SimpleSegment,
  _SimpleShape,
  _SimpleTriangleMesh,
  _Singleton,
  _SoftBody,
  _SoftBodyDescription,
  _SoftBodyMesh,
  _Sphere,
  _SphericalJoint,
  _SphericalJointDescription,
  _SpringDescription,
  _SweepCache,
  _SweepQueryHit,
  _TBuffer,
  _TimeController,
  _TimeListener,
  _Timer,
  _TimerStep,
  _TireFunction,
  _TriangleGeometry,
  _URIHash,
  _VisualDebugger,
  _VisualDebuggerMeshData,
  _Volume,
  _Wheel,
  _WheelBlueprint,
  _WheelMachinePart,
  _World,
  _WorldDescription,
  _WorldPrototype,
  RENDERSYSTEMS_CLASSES_BEGIN,
  USER_CLASS = 50000
};

                                                                                       

  /** \brief Turns a NxOgre::Classes::Enum into a String and any PhysX MemoryType enum value as well.
  */
  const char*  TypeToCStr(int i);

                                                                                       
} // namespace Classes
} // namespace NxOgre

                                                                                       
#endif

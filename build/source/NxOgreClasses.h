/** File: NxOgreClasses.h
    Author: Robin Southern "betajaen"
    SVN: $Id$
    This is an automatically created file.

    (c) Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

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
  _ArchiveResourceIdentifier,
  _ArchiveResourceIdentifierReferenceCounter,
  _Array,
  _ArrayReferenceCounter,
  _ArrayUnknown,
  _Box,
  _Buffer,
  _BufferReferenceCounter,
  _BufferUnknown,
  _Callback,
  _Capsule,
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
  _MeshStats,
  _MotorDescription,
  _MSWindowsFileArchive,
  _MSWindowsFileResource,
  _MSWindowsFileResourceProtocol,
  _NxShapeFunctions,
  _Particle,
  _ParticleData,
  _PhysXCallback,
  _PhysXMeshData,
  _PhysXOutputStream,
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
  _RigidBodyPrototype,
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
  _SharedStringStream,
  _SharedStringStream_Buffer,
  _SharedStringStreamReferenceCounter,
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
  _String,
  _StringBase,
  _TBuffer,
  _TimeController,
  _TimeListener,
  _TireFunction,
  _TriangleGeometry,
  _UniformResourceIdentifier,
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

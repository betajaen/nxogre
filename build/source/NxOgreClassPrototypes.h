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

                                                                                       

#ifndef NXOGRE_CLASS_PROTOTYPES_H
#define NXOGRE_CLASS_PROTOTYPES_H

                                                                                       

namespace NxOgre
{

                                                                                       

class AccumulativeSceneTimer;
class Actor;
class ActorMachinePart;
class AuxiliaryScene;
class Box;
class BoxDescription;
template<typename T> class buffer;
class Capsule;
class CapsuleDescription;
class Callback;
class Cloth;
class ClothDescription;
struct ClothRaycastHit;
class Compartment;
class CompartmentDescription;
class ContactPair;
class Convex;
class ConvexDescription;
class D6Joint;
class D6JointDescription;
class DebugRenderable;
class ErrorStream;
class ErrorListener;
class Exception;
class FixedJoint;
class FixedSceneTimer;
class Fluid;
class FluidDescription;
class FluidEmitter;
class FluidEmitterDescription;
class FluidDrain;
class FluidDrainDescription;
class FluidPacket;
class HeightField;
class HeightFieldGeometry;
class HeightFieldGeometryDescription;
struct HeightFieldSample;
class HeightFieldManager;
class Geometry;
class int2;
class int3;
class int4;
class Joint;
class JointDescription;
class JointLimitDescription;
class JointLimitSoftDescription;
class KinematicActor;
class KinematicController;
class Notice;
class Machine;
class MachinePart;
class Material;
class MaterialDescription;
class ManualMesh;
class MeshData;
class MeshRenderable;
class ManualHeightField;
class HeightFieldData;
class Memory;
class MemoryArchive;
class MemoryResource;
class MemoryResourceProtocol;
class Mesh;
class MeshManager;
class MeshStats;
class MotorDescription;
class ForceField;
class ForceFieldDescription;
class ForceFieldKernel;
class ForceFieldLinearKernel;
class ForceFieldLinearKernelDescription;
class FileArchive;
class FileResource;
class FileResourceProtocol;
class PlaneGeometry;
class PlaneGeometryDescription;
class Particle;
class ParticleData;
class PhysXMeshData;
class PhysXCallback;
class PhysXPointer;
class PhysXShapePointer;
class PhysXParticleData;
class PhysXOutputStream;
class PhysXUserAllocator;
class PointParticleRenderer;
class PointRenderable;
class PrincipalScene;
class Path;
class Resource;
class ResourceSystem;
class RigidBody;
class RigidBodyDescription;
class RigidBodyEventIterator;
class RemoteDebugger;
class RemoteDebuggerListener;
class Renderable;
class Resource;
class ResourceProtocol;
class ResourceSystem;
class RevoluteJoint;
class RevoluteJointDescription;
class Ray;
struct RaycastHit;
class Scene;
class SceneDescription;
class SceneGeometry;
class ScenePrototype;
class SceneRenderer;
class SceneTimer;
class SceneLink;
class Sphere;
class SphereDescription;
class SphericalJoint;
class SphericalJointDescription;
struct SimpleShape;
struct SimpleBox;
struct SimpleCapsule;
struct SimpleSegment;
struct SimplePlane;
struct SimplePointCloud;
struct SimpleSphere;
struct SimpleTriangleMesh;
template<class T> class Singleton;
class SoftBody;
class SoftBodyDescription;
class SoftBodyMesh;
class SceneLink;
class Shape;
class ShapeDescription;
class SpringDescription;
class SweepCache;
struct SweepQueryHit;
class TimeListener;
class TimeListenerGroup;
class TimerStep;
class Timer;
class TireFunction;
class TriangleGeometry;
class TriangleGeometryDescription;
class VisualDebugger;
class VisualDebuggerMeshData;
class Volume;
class Warning;
class Wheel;
class WheelDescription;
class WheelMachinePart;
class World;
class WorldDescription;
class WorldPrototype;


#if NxOgreHasCharacterController == 1

class CharacterController;
class CharacterControllerDescription;

#endif

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

#ifndef NXOGRE_COMMON_H
#define NXOGRE_COMMON_H

                                                                                       

#include "NxOgrePhysXPrototypes.h"
#include "NxOgreEnums.h"
#include "NxOgrePointerFunctions.h"
#include "NxOgreMemory.h"
#include "NxOgreClasses.h"
#include "NxOgreErrorStream.h"
#include "NxOgrePointerClass.h"
#include "NxOgrePhysXPointer.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreSingleton.h"
#include "NxOgreArray.h"
#include "NxOgrePtrVector.h"
#include "NxOgrePtrHashmap.h"
#include "NxOgrePtrMultiHashmap.h"
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
#include "NxOgrePath.h"
#include "NxOgreVertex.h"
#include "NxOgreTriangle.h"
#include "NxOgreEntityReport.h"
#include "NxOgreTimeStep.h"
#include "NxOgreTimer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

// Prototypes classes, used through NxOgre, and with the Python generation scripts. Which turns
// the names into an enum value in NxOgreClasses.h, any lines with prefixed with //:: are private
// or in different namespaces, which cannot be prototyped in C++.

                 class                      AccumulativeSceneTimer;        //!<
                 struct                     ActiveParticle;                //!<
                 class                      Actor;                         //!<
                 class                      ActorMachinePart;              //!<
                 class                      Archive;                       //!<
                 class                      ArchiveMetaData;               //!<
     template<typename T> class             Array;                         //!<
//::             struct                     ArrayReferenceCounter;         //!< \internal Do Not Use.
//::             struct                     ArrayUnknown;                  //!< \internal Do Not Use.
                 class                      Box;                           //!<
     template<typename T> class             Buffer;                        //!<
//::             struct                     BufferReferenceCounter;        //!< \internal Do Not Use.
//::             struct                     BufferUnknown;                 //!< \internal Do Not Use.
                 class                      Capsule;                       //!<
                 class                      Callback;                      //!<
//::             struct                     CCDSkeletonMeshData;           //!<
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
//::             class                      FileArchive;          //!< \brief Part of NxOgre for Windows
//::             class                      FileResource;         //!< \brief Part of NxOgre for Windows
//::             class                      FileResourceProtocol; //!< \brief Part of NxOgre for Windows
                 class                      PlaneGeometry;                 //!<
                 class                      PlaneGeometryPrototype;        //!<
                 class                      Particle;                      //!<
                 class                      ParticleData;                  //!<
                 class                      PhysXMeshData;                 //!<
                 class                      PhysXCallback;                 //!< \internal Do Not Use.
                 class                      PhysXPointer;                  //!<
                 class                      PhysXShapePointer;             //!<
                 class                      PhysXParticleData;             //!<
                 class                      PhysXOutputStream;             //!<
                 class                      PhysXUserAllocator;            //!<
                 class                      PointParticleRenderer;         //!<
                 class                      PointRenderable;               //!<
                 class                      Path;                          //!<
     template<unsigned int Ti> class        PointerClass;                  //!<
                 class                      Resource;                      //!<
                 class                      ResourceSystem;                //!<
                 class                      RigidBody;                     //!<
                 class                      RigidBodyDescription;          //!<
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
                 class                      SoftBody;                      //!<
                 class                      SoftBodyDescription;           //!<
                 class                      SoftBodyMesh;                  //!<
                 class                      SharedStringStream;            //!<
//::             class                      SharedStringStream_Buffer;     //!<
//::             struct                 SharedStringStreamReferenceCounter //!<
                 class                      Shape;                         //!<
                 class                      ShapeBlueprint;                //!<
                 class                      SpringDescription;             //!<
                 class                      SweepCache;                    //!<
                 struct                     SweepQueryHit;                 //!<
//::             struct                     TBuffer;                       //!< \brief Part of NxOgreArray.h
                 class                      TimeController;                //!<
                 class                      TimeListener;                  //!<
                 class                      TimerStep;                     //!<
                 class                      Timer;                         //!<
                 class                      TireFunction;                  //!<
                 class                      TriangleGeometry;              //!<
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
                 typedef                    Real                    Radian;
                                                                                       

namespace Functions
{
                 class                      NxShapeFunctions;              //!<
}


namespace Serialisation
{
                 class                      MeshSerialiser;                //!<
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

/** \brief Numerical identifier for ActorGroups and ShapeGroups.
*/
typedef unsigned short GroupIdentifier;

/** \brief Numerical identifier for Materials.
*/
typedef unsigned short MaterialIdentifier;

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

/** \brief Buffer of SweepQueryHits
*/
typedef Buffer<SweepQueryHit> SweepQueryHits;

// TEMP.
typedef String SharedString;

//
static const Path MEMORY_PATH = Path("memory://");

                                                                                       

#define Matrix33_Zero     NxOgre::Matrix33::ZERO

#define Matrix33_Identity NxOgre::Matrix33::IDENTITY

#define Matrix44_Zero     NxOgre::Matrix44::ZERO

#define Matrix44_Identity NxOgre::Matrix44::IDENTITY

                                                                                       

namespace Constants
{

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

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

                                                                                       

#ifndef NXOGRE_PHYSX_PROTOTYPES_H
#define NXOGRE_PHYSX_PROTOTYPES_H

                                                                                       

#include "NxOgreConfiguration.h"

/*
    
          This isn't PhysX. This is just a copy of the PhysX classes and structs so they can be used in NxOgre without
          the user's application requiring the PhysX headers. You can't actually do anything with them unless you import
          the headers and libraries from the PhysX SDK into your application; otherwise it's just an unknown class that
          your application cannot use.
*/


                                                                                       

//    Prototype classes generated with the PhysX SDK 2.8.1.

                                                                                         
  
class NxActor;                        //< \internal Prototyped class. DO NOT USE.
class NxActorDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxActorDescBase;                //< \internal Prototyped class. DO NOT USE.
class NxBodyDesc;                     //< \internal Prototyped class. DO NOT USE.
class NxBoolExp;                      //< \internal Prototyped class. DO NOT USE.
class NxBounds3;                      //< \internal Prototyped class. DO NOT USE.
class NxBox;                          //< \internal Prototyped class. DO NOT USE.
class NxBoxController;                //< \internal Prototyped class. DO NOT USE.
class NxBoxControllerDesc;            //< \internal Prototyped class. DO NOT USE.
class NxBoxForceFieldShape;           //< \internal Prototyped class. DO NOT USE.
class NxBoxForceFieldShapeDesc;       //< \internal Prototyped class. DO NOT USE.
class NxBoxShape;                     //< \internal Prototyped class. DO NOT USE.
class NxBoxShapeDesc;                 //< \internal Prototyped class. DO NOT USE.
class NxBoxShapeOffCenter;            //< \internal Prototyped class. DO NOT USE.
class NxCapsule;                      //< \internal Prototyped class. DO NOT USE.
class NxCapsuleController;            //< \internal Prototyped class. DO NOT USE.
class NxCapsuleControllerDesc;        //< \internal Prototyped class. DO NOT USE.
class NxCapsuleForceFieldShape;       //< \internal Prototyped class. DO NOT USE.
class NxCapsuleForceFieldShapeDesc;   //< \internal Prototyped class. DO NOT USE.
class NxCapsuleShape;                 //< \internal Prototyped class. DO NOT USE.
class NxCapsuleShapeDesc;             //< \internal Prototyped class. DO NOT USE.
class NxCCDSkeleton;                  //< \internal Prototyped class. DO NOT USE.
class NxCloth;                        //< \internal Prototyped class. DO NOT USE.
class NxClothDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxClothMesh;                    //< \internal Prototyped class. DO NOT USE.
class NxClothMeshDesc;                //< \internal Prototyped class. DO NOT USE.
class NxClothUserNotify;              //< \internal Prototyped class. DO NOT USE.
class NxCmd;                          //< \internal Prototyped class. DO NOT USE.
class NxCollisionSpace;               //< \internal Prototyped class. DO NOT USE.
class NxCompartment;                  //< \internal Prototyped class. DO NOT USE.
class NxCompartmentDesc;              //< \internal Prototyped class. DO NOT USE.
class NxController;                   //< \internal Prototyped class. DO NOT USE.
class NxControllerDesc;               //< \internal Prototyped class. DO NOT USE.
class NxControllerManager;            //< \internal Prototyped class. DO NOT USE.
class NxConvexForceFieldShape;        //< \internal Prototyped class. DO NOT USE.
class NxConvexForceFieldShapeDesc;    //< \internal Prototyped class. DO NOT USE.
class NxConvexMesh;                   //< \internal Prototyped class. DO NOT USE.
class NxConvexMeshDesc2;              //< \internal Prototyped class. DO NOT USE.
class NxConvexMeshDesc;               //< \internal Prototyped class. DO NOT USE.
class NxConvexShape;                  //< \internal Prototyped class. DO NOT USE.
class NxConvexShapeDesc;              //< \internal Prototyped class. DO NOT USE.
class NxCookingInterface;             //< \internal Prototyped class. DO NOT USE.
class NxCylindricalJoint;             //< \internal Prototyped class. DO NOT USE.
class NxCylindricalJointDesc;         //< \internal Prototyped class. DO NOT USE.
class NxD6Joint;                      //< \internal Prototyped class. DO NOT USE.
class NxD6JointDesc;                  //< \internal Prototyped class. DO NOT USE.
class NxDebugRenderable;              //< \internal Prototyped class. DO NOT USE.
class NxDistanceJoint;                //< \internal Prototyped class. DO NOT USE.
class NxDistanceJointDesc;            //< \internal Prototyped class. DO NOT USE.
class NxEffector;                     //< \internal Prototyped class. DO NOT USE.
class NxEffectorDesc;                 //< \internal Prototyped class. DO NOT USE.
class NxFixedJoint;                   //< \internal Prototyped class. DO NOT USE.
class NxFixedJointDesc;               //< \internal Prototyped class. DO NOT USE.
class NxFloatExp;                     //< \internal Prototyped class. DO NOT USE.
class NxFluid;                        //< \internal Prototyped class. DO NOT USE.
class NxFluidDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxFluidEmitter;                 //< \internal Prototyped class. DO NOT USE.
class NxFluidEmitterDesc;             //< \internal Prototyped class. DO NOT USE.
class NxFluidUserNotify;              //< \internal Prototyped class. DO NOT USE.
class NxForceField;                   //< \internal Prototyped class. DO NOT USE.
class NxForceFieldDesc;               //< \internal Prototyped class. DO NOT USE.
class NxForceFieldKernel;             //< \internal Prototyped class. DO NOT USE.
class NxForceFieldLinearKernel;       //< \internal Prototyped class. DO NOT USE.
class NxForceFieldLinearKernelDesc;   //< \internal Prototyped class. DO NOT USE.
class NxForceFieldShape;              //< \internal Prototyped class. DO NOT USE.
class NxForceFieldShapeDesc;          //< \internal Prototyped class. DO NOT USE.
class NxForceFieldShapeGroup;         //< \internal Prototyped class. DO NOT USE.
class NxForceFieldShapeGroupDesc;     //< \internal Prototyped class. DO NOT USE.
class NxFoundationSDK;                //< \internal Prototyped class. DO NOT USE.
class NxGroupsMask;                   //< \internal Prototyped class. DO NOT USE.
class NxHeightField;                  //< \internal Prototyped class. DO NOT USE.
class NxHeightFieldDesc;              //< \internal Prototyped class. DO NOT USE.
class NxHeightFieldShape;             //< \internal Prototyped class. DO NOT USE.
class NxHeightFieldShapeDesc;         //< \internal Prototyped class. DO NOT USE.
class NxHw;                           //< \internal Prototyped class. DO NOT USE.
class NxHwBool;                       //< \internal Prototyped class. DO NOT USE.
class NxHwBoolConst;                  //< \internal Prototyped class. DO NOT USE.
class NxHwBoolVar;                    //< \internal Prototyped class. DO NOT USE.
class NxHwFloat;                      //< \internal Prototyped class. DO NOT USE.
class NxHwFloatConst;                 //< \internal Prototyped class. DO NOT USE.
class NxHwFloatVar;                   //< \internal Prototyped class. DO NOT USE.
class NxHwVec;                        //< \internal Prototyped class. DO NOT USE.
class NxHwVecConst;                   //< \internal Prototyped class. DO NOT USE.
class NxHwVecVar;                     //< \internal Prototyped class. DO NOT USE.
class NxInterfaceStats;               //< \internal Prototyped class. DO NOT USE.
class NxJoint;                        //< \internal Prototyped class. DO NOT USE.
class NxJointDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxJointLimitDesc;               //< \internal Prototyped class. DO NOT USE.
class NxMat33;                        //< \internal Prototyped class. DO NOT USE.
class NxMaterial;                     //< \internal Prototyped class. DO NOT USE.
class NxMaterialDesc;                 //< \internal Prototyped class. DO NOT USE.
class NxMeshData;                     //< \internal Prototyped class. DO NOT USE.
class NxMotorDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxParticleData;                 //< \internal Prototyped class. DO NOT USE.
class NxPhysicsSDK;                   //< \internal Prototyped class. DO NOT USE.
class NxPhysicsSDKDesc;               //< \internal Prototyped class. DO NOT USE.
class NxPlane;                        //< \internal Prototyped class. DO NOT USE.
class NxPlaneShape;                   //< \internal Prototyped class. DO NOT USE.
class NxPlaneShapeDesc;               //< \internal Prototyped class. DO NOT USE.
class NxPMap;                         //< \internal Prototyped class. DO NOT USE.
class NxPointInPlaneJoint;            //< \internal Prototyped class. DO NOT USE.
class NxPointInPlaneJointDesc;        //< \internal Prototyped class. DO NOT USE.
class NxPointOnLineJoint;             //< \internal Prototyped class. DO NOT USE.
class NxPointOnLineJointDesc;         //< \internal Prototyped class. DO NOT USE.
class NxPrismaticJoint;               //< \internal Prototyped class. DO NOT USE.
class NxPrismaticJointDesc;           //< \internal Prototyped class. DO NOT USE.
class NxProfileData;                  //< \internal Prototyped class. DO NOT USE.
class NxProfilingZone;                //< \internal Prototyped class. DO NOT USE.
class NxPulleyJoint;                  //< \internal Prototyped class. DO NOT USE.
class NxPulleyJointDesc;              //< \internal Prototyped class. DO NOT USE.
class NxRay;                          //< \internal Prototyped class. DO NOT USE.
class NxRemoteDebugger;               //< \internal Prototyped class. DO NOT USE.
class NxRevoluteJoint;                //< \internal Prototyped class. DO NOT USE.
class NxRevoluteJointDesc;            //< \internal Prototyped class. DO NOT USE.
class NxScene;                        //< \internal Prototyped class. DO NOT USE.
class NxSceneDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxSegment;                      //< \internal Prototyped class. DO NOT USE.
class NxShape;                        //< \internal Prototyped class. DO NOT USE.
class NxShapeDesc;                    //< \internal Prototyped class. DO NOT USE.
class NxSimpleTriangleMesh;           //< \internal Prototyped class. DO NOT USE.
class NxSoftBody;                     //< \internal Prototyped class. DO NOT USE.
class NxSoftBodyDesc;                 //< \internal Prototyped class. DO NOT USE.
class NxSoftBodyMesh;                 //< \internal Prototyped class. DO NOT USE.
class NxSoftBodyMeshDesc;             //< \internal Prototyped class. DO NOT USE.
class NxSoftBodyUserNotify;           //< \internal Prototyped class. DO NOT USE.
class NxSphere;                       //< \internal Prototyped class. DO NOT USE.
class NxSphereForceFieldShape;        //< \internal Prototyped class. DO NOT USE.
class NxSphereForceFieldShapeDesc;    //< \internal Prototyped class. DO NOT USE.
class NxSphereShape;                  //< \internal Prototyped class. DO NOT USE.
class NxSphereShapeDesc;              //< \internal Prototyped class. DO NOT USE.
class NxSphericalJoint;               //< \internal Prototyped class. DO NOT USE.
class NxSphericalJointDesc;           //< \internal Prototyped class. DO NOT USE.
class NxSpringAndDamperEffector;      //< \internal Prototyped class. DO NOT USE.
class NxSpringAndDamperEffectorDesc;  //< \internal Prototyped class. DO NOT USE.
class NxSpringDesc;                   //< \internal Prototyped class. DO NOT USE.
class NxStream;                       //< \internal Prototyped class. DO NOT USE.
class NxSw;                           //< \internal Prototyped class. DO NOT USE.
class NxSwBoolVar;                    //< \internal Prototyped class. DO NOT USE.
class NxSweepCache;                   //< \internal Prototyped class. DO NOT USE.
class NxSwFloat;                      //< \internal Prototyped class. DO NOT USE.
class NxSwFloatVar;                   //< \internal Prototyped class. DO NOT USE.
class NxSwVec;                        //< \internal Prototyped class. DO NOT USE.
class NxSwVecVar;                     //< \internal Prototyped class. DO NOT USE.
class NxThread;                       //< \internal Prototyped class. DO NOT USE.
class NxTriangle;                     //< \internal Prototyped class. DO NOT USE.
class NxTriangleMesh;                 //< \internal Prototyped class. DO NOT USE.
class NxTriangleMeshDesc;             //< \internal Prototyped class. DO NOT USE.
class NxTriangleMeshShape;            //< \internal Prototyped class. DO NOT USE.
class NxTriangleMeshShapeDesc;        //< \internal Prototyped class. DO NOT USE.
class NxUserActorPairFiltering;       //< \internal Prototyped class. DO NOT USE.
class NxUserAllocator;                //< \internal Prototyped class. DO NOT USE.
class NxUserAllocatorDefault;         //< \internal Prototyped class. DO NOT USE.
class NxUserContactModify;            //< \internal Prototyped class. DO NOT USE.
class NxUserContactReport;            //< \internal Prototyped class. DO NOT USE.
class NxUserDebugRenderer;            //< \internal Prototyped class. DO NOT USE.
class NxUserFluidContactReport;       //< \internal Prototyped class. DO NOT USE.
class NxUserNotify;                   //< \internal Prototyped class. DO NOT USE.
class NxUserOutputStream;             //< \internal Prototyped class. DO NOT USE.
class NxUserScheduler;                //< \internal Prototyped class. DO NOT USE.
class NxUserTriggerReport;            //< \internal Prototyped class. DO NOT USE.
class NxUserWheelContactModify;       //< \internal Prototyped class. DO NOT USE.
class NxUtilLib;                      //< \internal Prototyped class. DO NOT USE.
class NxVec3;                         //< \internal Prototyped class. DO NOT USE.
class NxVecExp;                       //< \internal Prototyped class. DO NOT USE.
class NxWheelShape;                   //< \internal Prototyped class. DO NOT USE.
class NxWheelShapeDesc;               //< \internal Prototyped class. DO NOT USE.
struct NxExtendedBounds3;             //< \internal Prototyped class. DO NOT USE.
struct NxExtendedCapsule;             //< \internal Prototyped class. DO NOT USE.
struct NxIntegrals;                   //< \internal Prototyped class. DO NOT USE.
struct NxRaycastHit;                  //< \internal Prototyped class. DO NOT USE.
struct NxSweepQueryHit;               //< \internal Prototyped class. DO NOT USE.


#if NxOgreHasCharacterController == 1

class NxController;                   //< \internal Prototyped class. DO NOT USE.
class NxControllerManager;            //< \internal Prototyped class. DO NOT USE.

#endif

                                                                                         
  
  
#endif

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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreRigidBody.h"

#include "NxOgreScene.h"
#include "NxOgreWorld.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreErrorStream.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreFunctions.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreCompartment.h"
#include "NxOgreShapeFunctions.h"

#include "NxActor.h"
#include "NxPhysics.h"

#if NxOgreHasCharacterController == 1
#include "NxController.h"
#include "NxBoxController.h"
#include "NxCapsuleController.h"
#include "ControllerManager.h"
#include "NxOgrePhysXControllerHitReport.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

RigidBody::RigidBody(Scene* scene)
: mActor(0), mScene(scene), mContactCallback(0), mDirtyActor(false), mNameHash(0)
{
}

RigidBody::~RigidBody()
{
}

String RigidBody::getName() const
{
 return mName;
}

StringHash RigidBody::getNameHash() const
{
 return mNameHash;
}

unsigned int RigidBody::getRigidBodyType() const
{
 return Classes::_RigidBody;
}

void RigidBody::_createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
{
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_NON_STATIC_PASS
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 NxBodyDesc body_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;
 description.to_nxactor(&actor_description, &body_description);
 //////////////////////////////////////////////////

 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(SHAPE)
 //////////////////////////////////////////////////
 NxShapeDesc* shape_description = shape.createShapeDescription();
 if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)
  NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody);
 actor_description.shapes.push_back(shape_description);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(shape_description, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////

 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}

void RigidBody::_createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_NON_STATIC_PASS
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 NxBodyDesc body_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;
 description.to_nxactor(&actor_description, &body_description);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(SHAPES)
 //////////////////////////////////////////////////
 for (unsigned int i=0;i < shapes.size();i++)
 {
  NxShapeDesc* shape_description = shapes[i]->createShapeDescription();
  if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)
   NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody);
  actor_description.shapes.push_back(shape_description);
 }
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* ptr = actor_description.shapes[i];
  GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(ptr, NXOGRE_GC_THIS);
 }
 //////////////////////////////////////////////////

 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////

 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
{
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////

 //RIGIDBODY_STATIC_PASS(MATRIX)
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = 0;
 description.to_nxactor(&actor_description);
 //////////////////////////////////////////////////

 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(SHAPE)
 //////////////////////////////////////////////////
 NxShapeDesc* shape_description = shape.createShapeDescription();
 actor_description.shapes.push_back(shape_description);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
 {
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 }
 //////////////////////////////////////////////////
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(shape_description, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 //RIGIDBODY_STATIC_PASS(MATRIX)
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = 0;
 description.to_nxactor(&actor_description);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(SHAPES)
 //////////////////////////////////////////////////
 for (unsigned int i=0;i < shapes.size();i++)
 {
  NxShapeDesc* shape_description = shapes[i]->createShapeDescription();
  actor_description.shapes.push_back(shape_description);
 }
 //////////////////////////////////////////////////

 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* ptr = actor_description.shapes[i];
  GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(ptr, NXOGRE_GC_THIS);
 }
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
{
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_NON_STATIC_PASS
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 NxBodyDesc body_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;
 description.to_nxactor(&actor_description, &body_description);
 //////////////////////////////////////////////////
 
 body_description.flags |= NX_BF_KINEMATIC;
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(SHAPE)
 //////////////////////////////////////////////////
 NxShapeDesc* shape_description = shape.createShapeDescription();
 if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)
  NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody);
 actor_description.shapes.push_back(shape_description);
 //////////////////////////////////////////////////

 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(shape_description, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_NON_STATIC_PASS
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 NxBodyDesc body_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;
 description.to_nxactor(&actor_description, &body_description);
 //////////////////////////////////////////////////
 
 body_description.flags |= NX_BF_KINEMATIC;
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(SHAPES)
 //////////////////////////////////////////////////
 for (unsigned int i=0;i < shapes.size();i++)
 {
  NxShapeDesc* shape_description = shapes[i]->createShapeDescription();
  if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)
   NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody);
  actor_description.shapes.push_back(shape_description);
 }
 //////////////////////////////////////////////////

 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* ptr = actor_description.shapes[i];
  GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(ptr, NXOGRE_GC_THIS);
 }
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescription& shape)
{

 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_TRIGGER_PASS(pose)
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = 0;
 //////////////////////////////////////////////////
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(SHAPE)
 //////////////////////////////////////////////////
 NxShapeDesc* shape_description = shape.createShapeDescription();
 actor_description.shapes.push_back(shape_description);
 //////////////////////////////////////////////////
 
 shape_description->shapeFlags |= collision_type;
 
 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(shape_description, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}


void RigidBody::_createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescriptions& shapes)
{
 
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
  if (mActor)
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_TRIGGER_PASS(pose)
 //////////////////////////////////////////////////
 mScene = scene;
 NxActorDesc actor_description;
 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = 0;
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(SHAPES)
 //////////////////////////////////////////////////
 for (unsigned int i=0;i < shapes.size();i++)
 {
  NxShapeDesc* shape_description = shapes[i]->createShapeDescription();
  actor_description.shapes.push_back(shape_description);
 }
 //////////////////////////////////////////////////
 
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
  actor_description.shapes[i]->shapeFlags |= collision_type;
 
 // RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 //////////////////////////////////////////////////
 mActor = mScene->getScene()->createActor(actor_description);
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 //////////////////////////////////////////////////
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* ptr = actor_description.shapes[i];
  GC::safe_allocated_delete<NxShapeDesc, PhysXClassAllocator>(ptr, NXOGRE_GC_THIS);
 }
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////
 
 // RIGIDBODY USERDATA PASS
 //////////////////////////////////////////////////
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 //////////////////////////////////////////////////
}

#if NxOgreHasCharacterController == 1

NxController* RigidBody::_createCharacterController(const Vec3& globalPos, Scene* scene, const SimpleShape& shape, const CharacterControllerDescription& description)
{
 
 // RIGIDBODY_EXCEPTIONS_PASS
 //////////////////////////////////////////////////
 if (mActor)
   NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody);
 NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);
 //////////////////////////////////////////////////
 
 // RIGIDBODY_CHARACTER_CONTROLLER
 //////////////////////////////////////////////////
 mScene = scene;
 NxController* controller = 0;

 // BOX_CHARACTER_CONTROLLER
 //////////////////////////////////////////////////
 if (shape.getType() == Enums::SimpleShape_Box)
 {
  NxBoxControllerDesc controller_desc;
  Vec3 box_desc = shape.to_cc_shape();
  box_desc *= 0.5f;
  controller_desc.extents.x = box_desc.x;
  controller_desc.extents.y = box_desc.y;
  controller_desc.extents.z = box_desc.z;
  controller_desc.interactionFlag = (NxCCTInteractionFlag) (int) description.mInteractionFlag;
  controller_desc.position = globalPos.as<NxExtendedVec3>();
  controller_desc.skinWidth = description.mSkinWidth;
  controller_desc.slopeLimit = description.mSlopeLimit.rad();
  controller_desc.stepOffset = description.mStepOffset;
  controller_desc.upDirection = (NxHeightFieldAxis) (int) description.mUpDirection;
  controller_desc.callback = World::getSingleton()->getPhysXCharacterHitReport();

  //controller_desc.userData = GC::safe_new2<PhysXPointer>(this, Classes::_CharacterController, NXOGRE_GC_THIS);
  
  controller = World::getSingleton()->getPhysXControllerManager()->createController(mScene->getScene(), controller_desc);
  mActor = controller->getActor();
 }
 // CAPSULE_CHARACTER_CONTROLLER
 //////////////////////////////////////////////////
 else if (shape.getType() == Enums::SimpleShape_Capsule)
 {
  NxCapsuleControllerDesc controller_desc;
  controller_desc.climbingMode = description.mCapsuleEasyClimbing ? CLIMB_EASY : CLIMB_CONSTRAINED;
  Vec3 capsule_desc = shape.to_cc_shape();
  controller_desc.height = capsule_desc.y;
  controller_desc.radius = capsule_desc.x;
  controller_desc.position = globalPos.as<NxExtendedVec3>();
  controller_desc.skinWidth = description.mSkinWidth;
  controller_desc.slopeLimit = description.mSlopeLimit.rad();
  controller_desc.stepOffset = description.mStepOffset;
  controller_desc.upDirection = (NxHeightFieldAxis) (int) description.mUpDirection;
  controller_desc.callback = World::getSingleton()->getPhysXCharacterHitReport();

  //controller_desc.userData = GC::safe_new2<PhysXPointer>(this, Classes::_CharacterController, NXOGRE_GC_THIS);
  
  controller = World::getSingleton()->getPhysXControllerManager()->createController(mScene->getScene(), controller_desc);
  mActor = controller->getActor();
 }
 
 if (mActor == 0)
  NxOgre_ThrowException(DescriptionInvalidException, "Character Controller was not created", Classes::_RigidBody);
 
 mDirtyActor = true;
 
 mActor->userData = GC::safe_new2<PhysXPointer>(this, Classes::_RigidBody, NXOGRE_GC_THIS);
 
 // RIGIDBODY_CREATE_SHAPES_PASS
 //////////////////////////////////////////////////
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 while (nbShapes--)
  mShapes.push_back(Functions::ShapeFunctions::createDirtyShape(physx_shapes[nbShapes], this));
 //////////////////////////////////////////////////

 
 return controller;
}

#endif

void RigidBody::_destroy()
{
 
 if (mActor == 0)
  return;
 
 PhysXPointer* ptr = pointer_cast(mActor->userData);
 GC::safe_delete(ptr, NXOGRE_GC_THIS);
 
 for (vector_iterator<Shape*> shape = mShapes.elements(); shape != shape.end(); shape++)
 {
  PhysXPointer* shape_ptr = pointer_cast(shape->getAbstractShape()->userData);
  GC::safe_delete(shape_ptr, NXOGRE_GC_THIS);
 }
 
 if (!mDirtyActor)
 {
  NxScene& scene = mActor->getScene();
  scene.releaseActor(*mActor);
 }
 
}

bool RigidBody::isDynamic() const
{
 return mActor->isDynamic();
}

bool RigidBody::isSceneGeometryBased() const
{
 return false;
}

bool RigidBody::isVolumeBased() const
{
 return false;
}

bool RigidBody::isActorBased() const
{
 return false;
}

bool RigidBody::isKinematicActorBased() const
{
 return false;
}

#if NxOgreHasCharacterController == 1

bool RigidBody::isCharacterControllerBased() const
{
 return false;
}

#endif

void RigidBody::raiseFlag(RigidbodyFlags::Flags flag)
{
 mActor->raiseBodyFlag((NxBodyFlag) (int) flag);
}

void RigidBody::clearFlag(RigidbodyFlags::Flags flag)
{
 mActor->clearBodyFlag((NxBodyFlag) (int) flag);
}

bool RigidBody::hasFlag(RigidbodyFlags::Flags flag) const
{
 return mActor->readBodyFlag((NxBodyFlag) (int) flag);
}

NxActor* RigidBody::getNxActor()
{
 return mActor;
}

Scene* RigidBody::getScene()
{
 return mScene;
}

void RigidBody::setContactCallback(Callback* callback)
{
 mContactCallback = callback;
}

Callback* RigidBody::getContactCallback()
{
 return mContactCallback;
}

CollisionModelIterator RigidBody::getShapes()
{
 return mShapes.elements();
}

Shape* RigidBody::getShape(unsigned int index)
{
 if (index > mShapes.size() - 1)
  return 0;
 return mShapes.at(index);
}

Shape* RigidBody::getShapeById(unsigned int id)
{
 for (unsigned int i=0;i < mShapes.size();i++)
  if (mShapes[i]->getId() == id)
   return mShapes[i];
 return 0;
}

unsigned int RigidBody::getNbShapes() const
{
 return mShapes.size();
}

String RigidBody::to_s() const
{
 return String("RigidBody");
}

#undef RIGIDBODY_EXCEPTIONS_PASS
#undef RIGIDBODY_NON_STATIC_PASS
#undef RIGIDBODY_STATIC_PASS
#undef RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS
#undef RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS
#undef RIGIDBODY_CREATE_OR_THROW_EXCEPTION
#undef RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
#undef RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
#undef RIGIDBODY_CREATE_SHAPES_PASS

                                                                                       

} // namespace NxOgre

                                                                                       

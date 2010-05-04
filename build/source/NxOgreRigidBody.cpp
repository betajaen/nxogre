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

                                                                                       

namespace NxOgre
{

                                                                                       

RigidBody::RigidBody()
: mActor(0), mScene(0), mContactCallback(0), mNameHash(BLANK_HASH)
{
}

RigidBody::~RigidBody()
{
}

unsigned int RigidBody::getRigidBodyType() const
{
 return Classes::_RigidBody;
}

void RigidBody::createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
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
 NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, shape_description);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}

void RigidBody::createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
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
  NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, ptr);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
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
 NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, shape_description);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
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
  NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, ptr);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
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
 NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, shape_description);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
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
  NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, ptr);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescription& shape)
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
 NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, shape_description);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescriptions& shapes)
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
  NXOGRE_DELETE_PHYSX(NxShapeDesc, PhysXClassAllocator, ptr);
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
 mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);
 //////////////////////////////////////////////////
}


void RigidBody::destroy(void)
{
 
 if (mActor == 0)
  return;
 
 
 PhysXPointer* ptr = pointer_cast(mActor->userData);
 NXOGRE_DELETE_NXOGRE(ptr);
 
 for (CollisionModel::iterator_t shape = mShapes.iterator(); shape != shape.end(); shape++)
 {
  PhysXPointer* shape_ptr = pointer_cast(shape->getAbstractShape()->userData);
  NXOGRE_DELETE_NXOGRE(shape_ptr);
 }
 
 NxScene& scene = mActor->getScene();
 scene.releaseActor(*mActor);
 
}

bool RigidBody::isDynamic(void) const
{
 return mActor->isDynamic();
}

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

NxActor* RigidBody::getNxActor(void)
{
 return mActor;
}

Scene* RigidBody::getScene(void)
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

StringHash RigidBody::getNameHash() const
{
 return mNameHash;
}

CollisionModelIterator RigidBody::getShapes()
{
 return mShapes.const_iterator();
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

                                                                                       

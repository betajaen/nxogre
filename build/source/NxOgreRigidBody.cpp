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
#include "NxOgreRigidBody.h"

#include "NxOgreScene.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreErrorStream.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreFunctions.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreCompartment.h"

#include "NxActor.h"

                                                                                       

namespace NxOgre
{

/** \brief This namespace and functions is an alternate to group of if/elseif/else statements.
*/
namespace PhysXShapeBinder
{
 
 typedef void (*PhysXShapeBindingFunctionPtr)(NxShape*);
 
 PhysXShapeBindingFunctionPtr       gFunctions[NX_SHAPE_COUNT];
 
#define NXOGRE_SHAPE_BINDFUNCTION(BINDING_FUNCTION, PHYSX_SHAPE, PHYSX_FUNCTION)                     \
 void BINDING_FUNCTION (NxShape* physx_shape)                                                        \
 {                                                                                                   \
  Shape* shape = pointer_representive_cast<Shape>(physx_shape->userData);                            \
  shape->assign(physx_shape->PHYSX_FUNCTION());                                                      \
 }                                                                                                    

 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxPlaneShape_BindFunction,  NxPlaneShape, isPlane)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxSphereShape_BindFunction, NxSphereShape, isSphere)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxBoxShape_BindFunction, NxBoxShape, isBox)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxCapsuleShape_BindFunction, NxCapsuleShape, isCapsule)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxWheelShape_BindFunction, NxWheelShape, isWheel)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxConvexShape_BindFunction, NxConvexShape, isConvexMesh)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxTriangleMeshShape_BindFunction, NxTriangleMeshShape, isTriangleMesh)
 NXOGRE_SHAPE_BINDFUNCTION(PhysX_NxHeightFieldShape_BindFunction, NxHeightFieldShape, isHeightField)
 
 void PhysX_BindFunction_NULL(NxShape*)
 {}

 struct PhysXShapeSelfBindingT
 {
  PhysXShapeSelfBindingT()
  {
   gFunctions[NX_SHAPE_PLANE]       = &PhysX_NxPlaneShape_BindFunction;
   gFunctions[NX_SHAPE_SPHERE]      = &PhysX_NxSphereShape_BindFunction;
   gFunctions[NX_SHAPE_BOX]         = &PhysX_NxBoxShape_BindFunction;
   gFunctions[NX_SHAPE_CAPSULE]     = &PhysX_NxCapsuleShape_BindFunction;
   gFunctions[NX_SHAPE_WHEEL]       = &PhysX_NxWheelShape_BindFunction;
   gFunctions[NX_SHAPE_CONVEX]      = &PhysX_NxConvexShape_BindFunction;
   gFunctions[NX_SHAPE_HEIGHTFIELD] = &PhysX_NxHeightFieldShape_BindFunction;
   gFunctions[NX_SHAPE_MESH]        = &PhysX_NxTriangleMeshShape_BindFunction;
   gFunctions[NX_SHAPE_RAW_MESH]    = &PhysX_BindFunction_NULL;
   gFunctions[NX_SHAPE_COMPOUND]    = &PhysX_BindFunction_NULL;
  }
 } PhysXShapeSelfBindingT;
 
 inline void BindShape(NxShape* shape)
 {
  (*gFunctions[shape->getType()])(shape);
 }
 

};

                                                                                       

RigidBody::RigidBody()
: mActor(0), mScene(0), mContactCallback(0), mNameHash(BLANK_HASH)
{
}

RigidBody::~RigidBody()
{
}

unsigned int RigidBody::getType() const
{
 return Enums::RigidBodyType_Unknown;
}

void RigidBody::createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shape* shape)
{
 
 NxOgre_ThrowIf(mActor, "createDynamic tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shape == 0, "createDynamic tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createDynamic tried to create an actor, but has no scene (Null Pointer).");
 
 mScene = scene;
 
 NxActorDesc actor_description;
 NxBodyDesc body_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(description, actor_description, body_description);
 
 NxShapeDesc* shape_description = shape->create();
 if (shape_description)
 {
  shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
  actor_description.shapes.push_back(shape_description);
 }
  
 mActor = mScene->getScene()->createActor(actor_description);
 
 NxOgre_Delete(shape_description);
 
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 
 while (nbShapes--)
 {
  NxShape* physx_shape = physx_shapes[nbShapes];
  PhysXShapeBinder::BindShape(physx_shape);
  mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));
 }
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
}

void RigidBody::createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shapes& shapes)
{

 NxOgre_ThrowIf(mActor, "createVolume tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shapes.size() == 0, "createVolume tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createVolume tried to create an actor, but has no scene (Null Pointer).");

 mScene = scene;
 
 NxActorDesc actor_description;
 NxBodyDesc body_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(description, actor_description, body_description);
  for (unsigned int i=0;i < shapes.size(); i++)
 {
  NxShapeDesc* shape_description = shapes[i]->create();
  if (shape_description)
  {
   shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shapes[i], shapes[i]->getClassType(), this);
   actor_description.shapes.push_back(shape_description);
  }
 }
 
 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }
 
  for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* description = actor_description.shapes[i];
  NxOgre_Delete(description);
 }
 NxShape* physx_shape = mActor->getShapes()[0];
 PhysXShapeBinder::BindShape(physx_shape);
 mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));

 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
 
}

void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shape* shape)
{

 NxOgre_ThrowIf(mActor, "createSceneGeometry tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shape == 0, "createSceneGeometry tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createSceneGeometry tried to create an actor, but has no scene (Null Pointer).");

 mScene = scene;
 
 NxActorDesc actor_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorDesc(description, actor_description);
 
 NxShapeDesc* shape_description = shape->create();
 if (shape_description)
 {
  shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
  actor_description.shapes.push_back(shape_description);
 }
  
 mActor = mScene->getScene()->createActor(actor_description);
 
 NxOgre_Delete(shape_description);
 
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 
 while (nbShapes--)
 {
  NxShape* physx_shape = physx_shapes[nbShapes];
  PhysXShapeBinder::BindShape(physx_shape);
  mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));
 }
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
}

void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shapes& shapes)
{

 NxOgre_ThrowIf(mActor, "createSceneGeometry tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shapes.size() == 0, "createSceneGeometry tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createSceneGeometry tried to create an actor, but has no scene (Null Pointer).");

 mScene = scene;
 
 NxActorDesc actor_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorDesc(description, actor_description);
  for (unsigned int i=0;i < shapes.size(); i++)
 {
  NxShapeDesc* shape_description = shapes[i]->create();
  if (shape_description)
  {
   shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shapes[i], shapes[i]->getClassType(), this);
   actor_description.shapes.push_back(shape_description);
  }
 }
 
 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }
 
  for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* description = actor_description.shapes[i];
  NxOgre_Delete(description);
 }
 NxShape* physx_shape = mActor->getShapes()[0];
 PhysXShapeBinder::BindShape(physx_shape);
 mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));

 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
}

void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shape* shape)
{

 NxOgre_ThrowIf(mActor, "createKinematicActor tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shape == 0, "createKinematicActor tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createKinematicActor tried to create an actor, but has no scene (Null Pointer).");

 mScene = scene;
 
 NxActorDesc actor_description;
 NxBodyDesc body_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(description, actor_description, body_description);
  body_description.flags |= NX_BF_KINEMATIC;
 
 NxShapeDesc* shape_description = shape->create();
 if (shape_description)
 {
  shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
  actor_description.shapes.push_back(shape_description);
 }
  
 mActor = mScene->getScene()->createActor(actor_description);
 
 NxOgre_Delete(shape_description);
 
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 
 while (nbShapes--)
 {
  NxShape* physx_shape = physx_shapes[nbShapes];
  PhysXShapeBinder::BindShape(physx_shape);
  mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));
 }
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
}

void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, Shapes& shapes)
{

 NxOgre_ThrowIf(mActor, "createKinematicActor tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shapes.size() == 0, "createKinematicActor tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createKinematicActor tried to create an actor, but has no scene (Null Pointer).");

 mScene = scene;
 
 NxActorDesc actor_description;
 NxBodyDesc body_description;

 actor_description.globalPose.setRowMajor44(pose.ptr());
 actor_description.body = &body_description;

 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(description, actor_description, body_description);

 body_description.flags |= NX_BF_KINEMATIC;

 for (unsigned int i=0;i < shapes.size(); i++)
 {
  NxShapeDesc* shape_description = shapes[i]->create();
  if (shape_description)
  {
   shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shapes[i], shapes[i]->getClassType(), this);
   actor_description.shapes.push_back(shape_description);
  }
 }
 
 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }
 
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* description = actor_description.shapes[i];
  NxOgre_Delete(description);
 }
 
 NxShape* physx_shape = mActor->getShapes()[0];
 PhysXShapeBinder::BindShape(physx_shape);
 mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
 
}

void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, Shape* shape)
{
 mScene = scene;
 
 
 NxOgre_ThrowIf(mActor, "createVolume tried to create an actor, but this RigidBody already has an actor.")
 NxOgre_ThrowIf(shape == 0, "createVolume tried to create an actor, but has no shape (Null Pointer).")
 NxOgre_ThrowIf(scene == 0, "createVolume tried to create an actor, but has no scene (Null Pointer).")
 
 NxActorDesc actor_description;
 actor_description.body = 0;
 actor_description.globalPose.setRowMajor44(pose.ptr());

 NxShapeDesc* shape_description = shape->create();
 if (shape_description)
 {
  shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
  shape_description->shapeFlags |= collision_type;
  actor_description.shapes.push_back(shape_description);
 }
  
 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }
 

 NxOgre_Delete(shape_description);
 
 NxShape* const* physx_shapes = mActor->getShapes();
 NxU32 nbShapes = mActor->getNbShapes();
 
 while (nbShapes--)
 {
  NxShape* physx_shape = physx_shapes[nbShapes];
  PhysXShapeBinder::BindShape(physx_shape);
  mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));
 }
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
 
}

void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, Shapes& shapes)
{
 mScene = scene;
 
 NxOgre_ThrowIf(mActor, "createVolume tried to create an actor, but this RigidBody already has an actor.");
 NxOgre_ThrowIf(shapes.size() == 0, "createVolume tried to create an actor, but has no shape (Null Pointer).");
 NxOgre_ThrowIf(scene == 0, "createVolume tried to create an actor, but has no scene (Null Pointer).");

 NxActorDesc actor_description;
 actor_description.body = 0;
 actor_description.globalPose.setRowMajor44(pose.ptr());

 for (unsigned int i=0;i < shapes.size(); i++)
 {
  NxShapeDesc* shape_description = shapes[i]->create();
  if (shape_description)
  {
   shape_description->userData = (void*) NxOgre_New(PhysXPointer)(shapes[i], shapes[i]->getClassType(), this);
   shape_description->shapeFlags |= collision_type;
   actor_description.shapes.push_back(shape_description);
  }
 }
 
 mActor = mScene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  SharedStringStream ss;
  ss << "RigidBody actor was not created! \n"
     << "Reason(s) are: \n" <<  Reason::whyAsStream(actor_description);
  NxOgre_ThrowError(ss.get());
  return;
 }
 
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
 {
  NxShapeDesc* description = actor_description.shapes[i];
  NxOgre_Delete(description);
 }
 NxShape* physx_shape = mActor->getShapes()[0];
 PhysXShapeBinder::BindShape(physx_shape);
 mShapes.push_back(pointer_representive_cast<Shape>(physx_shape->userData));

 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
 
 
}

void RigidBody::destroy(void)
{
 
 if (mActor == 0)
  return;
 
 PhysXPointer* ptr = pointer_cast(mActor->userData);
 NxOgre_Delete(ptr);
 
 for (CollisionModel::iterator_t shape = mShapes.iterator(); shape != shape.end(); shape++)
 {
  PhysXPointer* shape_ptr = pointer_cast(shape->getAbstractShape()->userData);
  NxOgre_Delete(shape_ptr);
 }
 
 NxScene& scene = mActor->getScene();
 scene.releaseActor(*mActor);
 
}

bool RigidBody::isDynamic(void) const
{
 return mActor->isDynamic();
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

                                                                                       

} // namespace NxOgre

                                                                                       

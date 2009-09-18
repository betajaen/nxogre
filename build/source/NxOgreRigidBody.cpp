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
#include "NxOgreRigidBodyPrototype.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"
#include "NxOgreFunctions.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreSimple.h"
#include "NxOgreFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreCompartment.h"

#include "NxPhysics.h"

                                                                                       

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
: mActor(0), mScene(0), mContactCallback(0)
{
}

RigidBody::~RigidBody()
{
}

unsigned int RigidBody::getType() const
{
 return Enums::RigidBodyType_Unknown;
}

                                                                                       

void RigidBody::create(RigidBodyPrototype* prototype, Scene* scene, Shapes* final_shapes)
{

 if (mActor != 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that was already created.");
  return;
 }
 
 if (prototype == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no prototype.");
  return;
 }
 
 if (scene == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no scene.");
  return;
 }

 if (prototype->mShapes.size() == 0)
 {
  NxOgre_ThrowError("RigidBody has no shapes.");
  return;
 }

 mScene = scene;
 
 
 NxActorDesc actor_description;
 NxBodyDesc  body_description;
 
 // Copy over the prototype into the Actor and possible Body descriptions.
 Functions::PrototypeFunctions::RigidBodyPrototypeToNxActorAndNxBodyDesc(prototype, actor_description, body_description);
 
 // Create the shapes, and bind them to the shape that represents them - or not.

 for (unsigned int i=0;i < prototype->mShapes.size(); i++)
 {
  Shape* shape = prototype->mShapes[i];
  NxShapeDesc* description = shape->create();
  if (description)
  {
   if (final_shapes)
    description->userData = (void*) NxOgre_New(PhysXPointer)(shape, shape->getClassType(), this);
   actor_description.shapes.push_back(description);
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
 
 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType());
 
 if (final_shapes)
 {
  NxShape* const* shapes = mActor->getShapes();
  NxU32 nbShapes = mActor->getNbShapes();
  
  while (nbShapes--)
  {
   NxShape* physx_shape = shapes[nbShapes];
   PhysXShapeBinder::BindShape(physx_shape);
   final_shapes->insert(pointer_representive_cast<Shape>(physx_shape->userData));
  }
 }
 
}

                                                                                       

void RigidBody::create(const Matrix44& pose, SimpleShape* shape, Real mass, Scene* scene)
{
  if (mActor != 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that was already created.");
  return;
 }
 
 if (shape == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no shape.");
  return;
 }
 
 if (scene == 0)
 {
  NxOgre_ThrowError("RigidBody tried to create an actor that has no scene.");
  return;
 }
 
 NxActorDesc actor_description;
 NxBodyDesc  body_description;
 
 actor_description.globalPose.setRowMajor44(pose.ptr());
 Functions::SimpleShapeToActorDescription(actor_description, shape);
 
 if (mass)
 {
  body_description.mass = mass;
  actor_description.body = &body_description;
 }
 
 mActor = scene->getScene()->createActor(actor_description);
 
 if (mActor == 0)
 {
  NxOgre_ThrowError("RigidBody actor was not created.");
  return;
 }

 mActor->userData = (void*) NxOgre_New(PhysXPointer)(this, getClassType()); 
}

void RigidBody::destroy(void)
{
 if (mActor)
 {
  PhysXPointer* ptr = pointer_cast(mActor->userData);
  NxOgre_Delete(ptr);
  NxScene& scene = mActor->getScene();
  scene.releaseActor(*mActor);
 }
}

bool RigidBody::isDynamic(void) const
{
 return ::NxOgre::Functions::RigidBodyFunctions::isDynamic(mActor);
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

                                                                                       

} // namespace NxOgre

                                                                                       

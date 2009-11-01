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

                                                                                       

#define RIGIDBODY_EXCEPTIONS_PASS                         \
  if (mActor)                                             \
    NxOgre_ThrowException(NonNullPointerException, "Tried to create an NxActor but this RigidBody already has one.", Classes::_RigidBody); \
  NxOgre_ThrowExceptionIfNull(scene, Classes::_Scene);    \

#define RIGIDBODY_NON_STATIC_PASS(MATRIX)                 \
 mScene = scene;                                          \
 NxActorDesc actor_description;                           \
 NxBodyDesc body_description;                             \
 actor_description.globalPose.setRowMajor44(MATRIX.ptr());\
 actor_description.body = &body_description;              \
 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorAndNxBodyDesc(description, actor_description, body_description);

#define RIGIDBODY_STATIC_PASS(MATRIX)                     \
 mScene = scene;                                          \
 NxActorDesc actor_description;                           \
 actor_description.globalPose.setRowMajor44(MATRIX.ptr());\
 actor_description.body = 0;                              \
 Functions::PrototypeFunctions::RigidBodyDescriptionToNxActorDesc(description, actor_description);

#define RIGIDBODY_TRIGGER_PASS(MATRIX)                    \
 mScene = scene;                                          \
 NxActorDesc actor_description;                           \
 actor_description.globalPose.setRowMajor44(MATRIX.ptr());\
 actor_description.body = 0;                              \


#define RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(SHAPE)                                                                                                                      \
 NxShapeDesc* shape_description = SHAPE.createShapeDescription();                                                                                               \
 if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)                                                                                             \
  NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody); \
 actor_description.shapes.push_back(shape_description);

#define RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(SHAPES)                                                                                                       \
 for (unsigned int i=0;i < SHAPES.size();i++)                                                                                                                    \
 {                                                                                                                                                               \
  NxShapeDesc* shape_description = SHAPES[i].createShapeDescription();                                                                                           \
  if (shape_description->getType() >= Enums::ShapeFunctionType_Mesh)                                                                                             \
   NxOgre_ThrowException(DescriptionInvalidException, "Cannot attach a TriangleMeshGeometry or HeightFieldShape shape to a dynamic actor", Classes::_RigidBody); \
  actor_description.shapes.push_back(shape_description);                                                                                                         \
 }                                                                                                                                                                

#define RIGIDBODY_CREATE_OR_THROW_EXCEPTION                         \
 mActor = mScene->getScene()->createActor(actor_description);       \
 if (mActor == 0)                                                   \
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(actor_description), Classes::_RigidBody);

#define RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST                            \
 NxOgreAllocatedDelete<NxShapeDesc, PhysXClassAllocator>(shape_description);     

#define RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST                                  \
  for (unsigned int i=0; i < actor_description.shapes.size(); i++)                       \
   NxOgreAllocatedDelete<NxShapeDesc, PhysXClassAllocator>(actor_description.shapes[i]);  

#define RIGIDBODY_CREATE_SHAPES_PASS                                                       \
 NxShape* const* physx_shapes = mActor->getShapes();                                       \
 NxU32 nbShapes = mActor->getNbShapes();                                                   \
 while (nbShapes--)                                                                        \
  mShapes.push_back(Functions::ShapeFunctions::createShape(physx_shapes[nbShapes], this));  


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
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_NON_STATIC_PASS(pose)
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(shape)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createDynamic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_NON_STATIC_PASS(pose)
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(shapes)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
{
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_STATIC_PASS(pose)
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(shape)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createStatic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_STATIC_PASS(pose)
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(shapes)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape)
{
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_NON_STATIC_PASS(pose)
 
 body_description.flags |= NX_BF_KINEMATIC;
 
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(shape)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createKinematic(const Matrix44& pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescriptions& shapes)
{
 
 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_NON_STATIC_PASS(pose)
 
 body_description.flags |= NX_BF_KINEMATIC;
 
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(shapes)
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
}

void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescription& shape)
{

 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_TRIGGER_PASS(pose)
 
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS(shape)
 shape_description->shapeFlags |= collision_type;

 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_SINGLE_SHAPE_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
 
}

void RigidBody::createTrigger(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescriptions& shapes)
{

 RIGIDBODY_EXCEPTIONS_PASS
 RIGIDBODY_TRIGGER_PASS(pose)
 
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS(shapes)
 
 for (unsigned int i=0; i < actor_description.shapes.size(); i++)
  actor_description.shapes[i]->shapeFlags |= collision_type;
 
 RIGIDBODY_CREATE_OR_THROW_EXCEPTION
 RIGIDBODY_MULTIPLE_SHAPES_DESCRIPTION_PASS_POST
 RIGIDBODY_CREATE_SHAPES_PASS
 
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

                                                                                       

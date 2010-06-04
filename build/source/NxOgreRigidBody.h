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

                                                                                       

#ifndef NXOGRE_RIGIDBODY_H
#define NXOGRE_RIGIDBODY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShape.h"

#include "NxOgreRigidbodyFlags.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. RigidBody
    Represents a abstract NxActor class; Actors, SceneGeometries, KinematicActors, Volumes and classes that inherit from
    these are all RigidBodies. All raycasting, sweeping, and other testing functions refer to NxActors as RigidBodies.
    
    To differentiate between RigidBodies (to re-cast them), use the RigidBody::getType() function, which returns a specific
    class code. User classes may also use this coding system to help differentiating between their classes and NxOgre's.
    
*/
class NxOgrePublicClass RigidBody : public RigidBodyBasedAllocatable
{
  
 public: // Functions
  
  /*! function. getNameHash
      desc.
           Get the hashed name of the RigidBody.
      return.
           **StringHash** -- The hash of the name, or *BLANK_HASH* if there is no name.
  */
  StringHash  getNameHash() const;
  
  /*! function. getScene
      desc.
           Retrieves the scene which this rigid body belongs to. 
      return
           **Scene** * -- Scene that this RigidBody belongs to.
  */
  Scene*  getScene(); 
  
  /*! function. isDynamic
      desc.
           Returns true if the RigidBody is dynamic, i.e. Had a NxBodyDesc when creating; such as a KinematicActor, Actor or Actor based class.
      return.
           **bool** -- If the Actor is dynamic or not.
  */
  bool  isDynamic() const;
  

  /*! function. raiseFlag
      desc. 
          Set a flag.
  */
  void raiseFlag(RigidbodyFlags::Flags);
  
  /*! function. clearFlag
      desc. 
          Clear a flag.
  */
  void clearFlag(RigidbodyFlags::Flags);
  
  /*! function. hasFlag
      desc. 
          Is a flag set?
  */
  bool hasFlag(RigidbodyFlags::Flags) const;


  /*! function. getNxActor
      desc.
           Get the PhysX *NxActor* that this RigidBody represents.
      note.
           Do not delete, or otherwise modify the pointer.
      return.
           **NxActor** * -- NxActor instance.
      !physx
  */
  NxActor*  getNxActor();
  
  /*! function. getRigidBodyType
      desc.
          Get the cpp type (see Classes namespace) as a unsigned integer.
      note.
          All classes that inherit from RigidBody, and classes that inherit from them, and them must implement getRigidBodyType.
      return.
          **unsigned int** -- The class type.
  */
  virtual unsigned int getRigidBodyType() const;
  
  /*! function. setContactCallback
      desc.
          Set a callback for contact reporting. If there is a previous callback, it won't be deleted.
      note.
          As this contact can be shared between RigidBodies it is upto YOU to delete the callback at the appropriate time.
          See the reference functions in callback for more information.
      args.
          Callback* __callback__ -- New callback to set, or NULL to clear.
  */
  void  setContactCallback(Callback* callback);
  
  /*! function. getContactCallback
      desc.
           Get the assigned callback for contact reporting.
      note.
          As this contact can be shared between RigidBodies it is upto YOU to delete the callback at the appropriate time.
          See the reference functions in callback for more information.
      return.
          **Callback** * -- Callback, or NULL if there is none.
  */
  Callback* getContactCallback();
  
  /*! function. GetShapes
      desc.
           Get a iterator to the current shapes in this RigidBody.
      return.
           **CollisionModelIterator** -- Iterator to the shapes.
  */
  CollisionModelIterator getShapes();
  
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  virtual String to_s() const;
  
  protected: // Function
  
  /*! constructor. RigidBody
      desc.
           RigidBody constructor
  */
  RigidBody();
  
  /*! destructor. RigidBody
      desc.
           RigidBody destructor
      !virtual
  */
  virtual  ~RigidBody();
  
  /*! function. createDynamic.0
      desc.
          Become a Dynamic RigidBody (Actors) based on the arguments.
      note.
          User classes that inherit from Actor do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription& description, Scene* scene, const ShapeDescription& shape);
  
  /*! function. createDynamic.1
      desc.
          Become a Dynamic RigidBody (Actor) based on the arguments.
      note.
          User classes that inherit from Actor do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescriptions& shapes);
  
  /*! function. createStatic.0
      desc.
          Become a Static RigidBody (StaticGeometry) based on the arguments.
      note.
          User classes that inherit from StaticGeometry do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescription& shape);
  
  /*! function. createStatic.1
      desc.
          Become a Static RigidBody (StaticGeometry) based on the arguments.
      note.
          User classes that inherit from StaticGeometry do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescriptions& shapes);

  /*! function. createKinematic.0
      desc.
          Become a Kinematic RigidBody (KinematicActor, KinematicController) based on the arguments.
      note.
          User classes that inherit from KinematicActor do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescription& shape);
  
  /*! function. createKinematic.1
      desc.
          Become a Kinematic RigidBody (KinematicActor, KinematicController) based on the arguments.
      note.
          User classes that inherit from KinematicActor do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescriptions& shapes);
  
  /*! function. createTrigger.0
      desc.
          Become a Trigger RigidBody (Volume) based on the arguments.
      note.
          User classes that inherit from Volume do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           Enums::VolumeCollisionType _colType__ -- Collision types (composed with the @|@ (or) operator) of the types of Collisions to report.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createTrigger(const Matrix44& pose, Enums::VolumeCollisionType, Scene*, const ShapeDescription&);
  
  /*! function. createTrigger.1
      desc.
          Become a Trigger RigidBody (Volume) based on the arguments.
      note.
          User classes that inherit from Volume do not need to call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           Enums::VolumeCollisionType _colType__ -- Collision types (composed with the @|@ (or) operator) of the types of Collisions to report.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createTrigger(const Matrix44& pose, Enums::VolumeCollisionType, Scene*, const ShapeDescriptions&);
  
  /*! function. destroy
      desc.
          Destroy the NxActor safely and delete all shapes from mShapes.
      note.
          User classes that inherit from Actor, StaticGeometry, KinematicActor, KinematicController or Volume do not need to call this.
  */
  void  destroy();
  
  protected: // Variables
  
  NxActor*              mActor;
  
  Scene*                mScene;
  
  Callback*             mContactCallback;
  
  StringHash            mNameHash;
  
  CollisionModel        mShapes;
  
  Enums::RigidBodyRole  mRole;
  
}; // class RigidBody


                                                                                       

} // namespace NxOgre

                                                                                       

#endif

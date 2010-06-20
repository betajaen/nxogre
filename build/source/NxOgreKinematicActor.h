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

                                                                                       

#ifndef NXOGRE_KINEMATICACTOR_H
#define NXOGRE_KINEMATICACTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreRigidBody.h"
#include "NxOgreDynamicRigidBodyFlags.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A kinematic actor is used mostly with the Character class. However it can be used for moving platforms,
           sliding doors and anything else that requires precise and predictable movement.
           
           NxOgre Kinematic Actors are more than an NxActor with a raised NX_BF_KINEMATIC flag, it has
           much more support functions and provides actual collision responses and callbacks. However if you
           just want an Actor with kinematic properties with no NxOgre powered callbacks or collisions then
           use a DynamicActor with a kinematic flag; but NxOgre will treat it as a dynamic actor and may
           or may not assume certain things about it.
    \example
     <code>
      mScene->createKinematicActor(new Box(4,1,4));
     </code>
*/
class NxOgrePublicClass KinematicActor : public RigidBody
{
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
  public:
  
  /** \brief
  */
  virtual  unsigned int  getRigidBodyType() const;

  /*! function. raiseDynamicFlag
      desc. 
          Set a dynamic flag.
  */
  void raiseDynamicFlag(DynamicRigidbodyFlags::Flags);
  
  /*! function. clearDynamicFlag
      desc. 
          Clear a dynamic flag.
  */
  void clearDynamicFlag(DynamicRigidbodyFlags::Flags);
  
  /*! function. hasDynamicFlag
      desc. 
          Is a dynamic flag set?
  */
  bool hasDynamicFlag(DynamicRigidbodyFlags::Flags) const;

  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
  void                   setGroup(GroupIdentifier actorGroup); 
  
  /** \brief Retrieves the value set with setGroup(). 
  */
  GroupIdentifier        getGroup() const;
  
  /** \brief Assigns dynamic actors a dominance group identifier. 
  */
  void                   setDominanceGroup(GroupIdentifier dominanceGroup); 
  
  /** \brief Retrieves the value set with setDominanceGroup(). 
  */
  GroupIdentifier        getDominanceGroup() const;
  
  /**  \brief Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
       to be called again for any pairs involving this actor. Use this method when you wish to change
       the filtering policy of an actor that may already be in contact with other actors. 
  */
  void                   resetPairFiltering(); 
  
  /** \brief Returns true if the actor is dynamic. 
  */
  bool                   isDynamic() const; 
  
  /*! function. isKinematicActorBased
      desc.
          Returns true if this class is a KinematicActor or inherits from it.
      return.
          **true** -- It is an KinematicActor or KinematicActor based class.
  */
  bool  isKinematicActorBased() const;

  /** \brief Computes the total kinetic (rotational and translational) energy of the object.
  */
  Real                   computeKineticEnergy() const;
  
  /** \brief Sets the solver iteration count for the body. 
  */
  void                   setSolverIterationCount(unsigned int iterCount);
  
  /** \brief Retrieves the solver iteration count.
  */
  unsigned int           getSolverIterationCount() const; 
  
  /** \brief Retrieves the force threshold for contact reports. 
  */
  Real                   getContactReportThreshold() const;
  
  /** \brief Sets the force threshold for contact reports. 
  */
  void                   setContactReportThreshold(Real threshold);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
  unsigned int           getContactReportFlags() const;
  
  /** \brief Sets the actor's contact report flags.
  */
  void                   setContactReportFlags(unsigned int flags);
  
  /// /** \brief Performs a linear sweep through space with the actor. 
  /// */
  ///                   NxU32                  linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL)=0 
  
  /// /** \brief  Retrieves the actor's simulation compartment, if any. 
  /// */
  ///                   NxCompartment*         getCompartment() const;
  
  /** \brief Retrieves the actor's force field material index, default index is 0. 
  */
  unsigned short         getForceFieldMaterial() const; 
  
  /** \brief Sets the actor's force field material index, default index is 0. 
  */
  void                   setForceFieldMaterial(unsigned short); 
  
  /** \brief Methods for setting a dynamic actor's pose in the world. 
  */
  void                   setGlobalPose(const Matrix44&);
 
  /** \brief Sets a dynamic actor's position in the world.
   */
  void                   setGlobalPosition (const Vec3&);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
  void                   setGlobalOrientation(const Matrix33&);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
  void                   setGlobalOrientationQuat(const Quat&);
  
  /** \brief Retrieves the actors world space transform.
  */
  Matrix44               getGlobalPose() const;
  
  /** \brief Retrieves the actors world space position.
  */
  Vec3                  getGlobalPosition() const;
  
  /** \brief Retrieves the actors world space orientation.
  */
  Matrix33               getGlobalOrientation() const;
  
  /** \brief Retrieves the actors world space orientation.
  */
  Quat                  getGlobalOrientationQuat() const;
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
  void                   moveGlobalPose(const Matrix44&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
  void                   moveGlobalPosition(const Vec3&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
  void                   moveGlobalOrientation (const Matrix33&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
  void                   moveGlobalOrientationQuat (const Quat&);

  /** \brief Creates a new shape and adds it to the list of shapes of this actor. 
  */
  void                   createShape(Shape*);
  
  /** \brief Deletes the specified shape.
  */
  void                   releaseShape(Shape*);
  
  protected: // Functions
  
  /** \internal Classes that inherit from KinematicActor should use this constructor.
  */
  KinematicActor(Scene*);
  /** \internal Use Scene::createKinematicActor
  */
  KinematicActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene);

  /** \internal Use Scene::createKinematicActor
  */
  KinematicActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description, Scene* scene);

  /** \internal Use Scene::destroyKinematicActor
  */
  virtual  ~KinematicActor();
  
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected: // Variables
    /*! function. createKinematic.0
      desc.
          Become a Kinematic RigidBody (KinematicActor, KinematicController) based on the arguments.
      note.
          User classes that inherit KinematicActor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription&, const ShapeDescription& shape);
  
  /*! function. createKinematic.1
      desc.
          Become a Kinematic RigidBody (KinematicActor, KinematicController) based on the arguments.
      note.
          User classes that inherit KinematicActor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createKinematic(const Matrix44& matrix_pose, const RigidBodyDescription&, const ShapeDescriptions& shapes);
  
}; // class KinematicActor

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

#ifndef NXOGRE_CHARACTERCONTROLLER_H
#define NXOGRE_CHARACTERCONTROLLER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#if NxOgreHasCharacterController == 1

#include "NxOgreRigidBody.h"
#include "NxOgreDynamicRigidBodyFlags.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** 
*/
class NxOgrePublicClass CharacterController : public RigidBody
{
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
  public:
  
  void   setMovingActiveGroups(unsigned int);
  
  /*! function. setMinimalMoveDistance
      desc.
          Set the minimal amount of distance the character should move.
  */
  unsigned int getMovingActiveGroups();
  
  /*! function. setMinimalMoveDistance
      desc.
          Set the minimal amount of distance the character should move.
  */
  void   setMinimalMoveDistance(Real minDist);
  
  /*! function. getMovingSharpness
      desc.
          Get the minimal amount of distance the character should move.
  */
  Real   getMinimalMoveDistance() const;
  
  /*! function. getMovingSharpness
      desc.
          Set the autostep sharpness to prevent sudden height changes.
      note.
          1.0 - means no smoothing.
  */
  void   setMovingSharpness(Real);
  
  /*! function. getMovingSharpness
      desc.
          Get the autostep sharpness
  */
  Real   getMovingSharpness() const;
  
  /*! function. getLastCollisionFlags
      desc.
          Get the flags reported during the last collision.
  */
  unsigned int getLastCollisionFlags() const;
  
  /*! function. moveGlobal
      desc.
          Try and move globally (without orientation)
  */
  void   move(const Vec3& displacement);
  
  /** \brief
  */
  virtual unsigned int getRigidBodyType() const;
  
  /** \brief Returns true if the character is dynamic. 
  */
  bool isDynamic() const; 
  
  /*! function. isCharacterControllerBased
      desc.
          Returns true if this class is a CharacterController or inherits from it.
      return.
          **true** -- It is an CharacterController or CharacterController based class.
  */
  bool  isCharacterControllerBased() const;
  
  /*! function. setPosition
      desc.
          "Teleport" the character controller to another position.
  */
  void  setPosition(const Vec3& globalPosition);
  
  /*! function. getPosition
      desc.
          Get the position of the character controller in the global frame.
  */
  Vec3  getPosition() const;

  /*! function. setStepOffset
      desc.
           Set the offset for auto-stepping for the controller.
  */
  void  setStepOffset(Real offset);

  /*! function. setCollisionsEnabled
      desc.
          Enable/Disable collisions with other objects colliding with the controller.
      note.
          Disabling collision for example would allow a box to fall through the controller,
          but a box would block the movement of the controller.
  */
  void  setCollisionsEnabled(bool);

  /*! function. setInteraction
      desc.
          Set the interaction flag
  */
  void  setInteractionFlag(Enums::CharacterControllerInteractionFlag);

  /*! function. getInteraction
      desc.
          Get the current interaction flag.
  */
  Enums::CharacterControllerInteractionFlag getInteraction() const;

  /*! function. reportSceneChanged
      desc.
          Update the cache if the scene geometry has changed.
  */
  void  reportSceneChanged();

  /*! function. isBoxShaped
      desc.
          Is the controller in the shape of a box, otherwise a capsule?
  */
  bool  isBoxShaped() const;

  /*! function. isCapsuleShaped
      desc.
          Is the controller in the shape of a capsule, otherwise a box?
  */
  bool  isCapsuleShaped() const;

  protected: // Functions

  /*! function. createCharacterController
      desc.
          Become a Character Controller based on the arguments.
      note.
          User classes that inherit CharacterController should call this. Usually in the constructor, or close by.
      args.
           const Vec3& __pose__ -- Pose of where the Dynamic RigidBody should be.
           Scene* __scene__ -- Which scene the CharacterController to exist in. Cannot be NULL.
           const SimpleShape& __shape__ -- The Single shape for the Character to use. Can only be SimpleBox or SimpleCapsule
           const CharacterControllerDescription& -- Additional properties to describe the controller.
      !protected
  */
  void createCharacterController(const Vec3& globalPos, const SimpleShape&, const CharacterControllerDescription&);

  /** \internal Classes that inherit from CharacterController should use this constructor.
  */
  CharacterController(Scene*);

  /** \internal Use Scene::createCharacterController
  */
  CharacterController(const SimpleShape& shape, const Vec3& globalPosition, const CharacterControllerDescription& description, Scene* scene);

  /** \internal Use Scene::destroyCharacterController
  */
  virtual  ~CharacterController();
  
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected: // Variables
    
  NxController*  mController;
  
  Real           mMinDistance;
  
  Real           mSharpness;
  
  unsigned int   mActiveGroups;
  
  unsigned int   mCollisionFlags;
  
}; // class CharacterController


                                                                                       

} // namespace NxOgre

                                                                                       

// HasCharacterController
#endif

#endif

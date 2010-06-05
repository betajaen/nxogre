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
#include "NxOgreShape.h"

#if NxOgreHasCharacterController == 1

class NxCharacter;

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. CharacterController
*/
class NxOgrePublicClass CharacterController : public RigidBodyBasedAllocatable
{
  
 friend class Scene;
 template<class T> friend inline void Functions::safe_delete(T*);
 
 public: // Functions
  
  /*! constructor. CharacterController
      desc.
           Inheritance Constructor
  */
  CharacterController();

  /*! function. getNameHash
      desc.
           Get the hashed name of the CharacterController.
      return.
           **StringHash** -- The hash of the name, or *BLANK_HASH* if there is no name.
  */
  StringHash  getNameHash() const;
  
  /*! function. getScene
      desc.
           Retrieves the scene which this rigid body belongs to. 
      return
           **Scene** * -- Scene that this CharacterController belongs to.
  */
  Scene*  getScene(); 
  
  /*! function. getNxActor
      desc.
           Get the PhysX *NxActor* that this CharacterController represents.
      note.
           Do not delete, or otherwise modify the pointer.
      return.
           **NxActor** * -- NxActor instance.
      !physx
  */
  NxActor*  getNxActor();
  
  /*! function. getNxActor
      desc.
           Get the PhysX *NxActor* that this CharacterController represents.
      note.
           Do not delete, or otherwise modify the pointer.
      return.
           **NxActor** * -- NxActor instance.
      !physx
  */
  NxController*  getNxController();
  
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
  
  /*! constructor. CharacterController
      desc.
           Create NxCharacter
      note.
           To be used by inherited classes of CharacterController ONLY.
  */
  void  create(const SimpleBox& shape, const Vec3& globalPosition, const Radian& yaw, const CharacterControllerDescription& description, Scene*);
  
  
  protected: // Function
  
  /*! constructor. CharacterController
      desc.
           CharacterController constructor
  */
  CharacterController(const SimpleBox& shape, const Vec3& globalPosition, const Radian& yaw, const CharacterControllerDescription& description, Scene*);

  /*! constructor. CharacterController
      desc.
           CharacterController constructor
  */
  CharacterController(const SimpleCapsule& shape, const Vec3& globalPosition, const Radian& yaw, const CharacterControllerDescription& description, Scene*);

  /*! destructor. CharacterController
      desc.
           CharacterController destructor
      !virtual
  */
  virtual  ~CharacterController();
  
  /*! function. destroy
      desc.
          Destroy the NxCharacter safely and delete all shapes from mShapes.
      note.
          User classes that inherit from CharacterController do not need to call this.
  */
  void  destroy();
  
  protected: // Variables
  
  NxController*         mController;
  
  Scene*                mScene;
  
  Callback*             mContactCallback;
  
  StringHash            mNameHash;
  
}; // class CharacterController


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif

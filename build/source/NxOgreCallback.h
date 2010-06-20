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

                                                                                       

#ifndef NXOGRE_CALLBACK_H
#define NXOGRE_CALLBACK_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Callback
    desc.
         A callback handles physics events i.e. collision and contact, by the user app inheriting
         the callback and using the virtual functions to handle response.
    example.
         class myCallback : public Callback
         {
          public:
           myCallback : Callback()
           {
            // my set up code.
           }
           
           void onVolumeEvent(Volume* volume, Shape* volumeShape, RigidBody* collision_body, Shape* rigidBodyShape, unsigned int collisionEvent)
           {
            std::cout << "Volume Event!" << std::endl;
           }
         };
*/
class NxOgrePublicClass Callback
{
  
  public: // Functions
   
   /*! constructor. Callback
       desc.
            Required constructor for inherited classes.
       note.
            Reference count is set to 1.
   */
   Callback();
   
   /*! destructor. ~Callback
       desc.
            Required destructor
       !virtual
   */
   virtual ~Callback();
   
   /*! function. shouldDelete
       desc.
           Should this callback be deleted when no longer used?
       note.
           This automatically returns true, and should be overriden when you want a different
           behaviour.
           When returning true -- the callback will be deleted on the following events:
            - Volume destroyed, when reference count is 0.
            - Scene destroyed, when reference count is 0.
       return.
           **false** -- Don't delete it
    */
    virtual bool shouldDelete() const;

   /*! function. onVolumeEvent
       desc.
          A RigidBody has entered, exited or otherwise is existing inside the Volume.
       note.
          Depending on the RigidBody the collision_shape may be zero, you should always check
            to see if the pointer exists before using it!
       args.
          Volume* __volume__ -- Volume of the collisionBody has an event with.
          Shape*  __volumeShape__ -- the specific shape of the volume.
          RigidBody* __collisionBody__ -- The collisionBody in question.
          Shape* __collisionShape__ -- The shape in contact with the volumeShape.
          unsigned int __collisionEvent__ -- The type of collision, used with Enums::VolumeCollisionType
       example.
          void onVolumeEvent(Volume* volume, Shape* volumeShape, RigidBody* collision_body, Shape* rigidBodyShape, unsigned int collisionEvent)
          {
           if (collisionEvent & Enums::VolumeCollisionType_OnEnter)
           {
            std::cout << "RigidBody has entered the Volume for the first time!" << std::endl;
           }
          }
   */
   virtual void onVolumeEvent(Volume* volume, Shape* volumeShape, RigidBody* collisionBody, Shape* rigidBodyShape, unsigned int collisionEvent);
   
   /*! function. onHitEvent
       desc.
           When a callback is used with a Raycast hit.
       note.
           Do not modify the Scene whilst in the onRaycastHit function; i.e. destroyActor, or createActor
       args.
           const RaycastHit& __hit__ -- Raycast hit to parse
       return. **bool** -- True if the ray should continue, or false to abort.
       example.
          void onHitEvent(const RaycastHit& hit)
          {
           return (hit.mDistance < 20) // Return true if less than 20m.
          }
       see. Scene::raycastAllBounds
   */
   virtual bool onHitEvent(const RaycastHit& hit);
   
   /*! function. onContact
       desc.
            When a contact even happens, between two RigidBodies
       args.
            const ContactPair& __pair__ -- Contact pair when hit.
       note.
           Do not modify the Scene whilst in the onContact function; i.e. destroyActor, or createActor
       example.
          void onContact(const ContactPair& pair)
          {
           // Things to do.
          }
       see. RigidBody::setContactCallback, Scene::setActorFlags
   */
   virtual void onContact(const ContactPair& pair);
   
   
   /*! function. onOverlap
       desc.
           When shapes are detected in an overlap
       note.
           This function may be called many times in an overlap test.
       args.
       
       return.
            true to continue overlap processing, false to cancel.
   */
   virtual bool onOverlap(const buffer<Shape*>& shapes);


   /*! function. onSleep
   */
   virtual void onSleep(const RigidBodyEventIterator& rigidbodies);

   /*! function. onSleep
   */
   virtual void onWake(const RigidBodyEventIterator& rigidbodies);

   /*! function. increaseReference
       desc.
            Increase the reference count of the callback
   */
   void increaseReference();
   
   /*! function. decreaseReference
       desc.
            Decrease the reference count of the callback
   */
   void decreaseReference();
   
   /*! function. getNbReferences
       desc.
            Get the number of references to this callback. 
       note.
            Although not exactly essential, reference counting the callback is useful
            for you to decide when the callback should be deleted. If you use the callback
            multiple times.
       return.
            **unsigned int** -- Number of references.
   */
   unsigned int getNbReferences() const;
   
  private:
   
   unsigned int mNbReferences;

}; // class Callback

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

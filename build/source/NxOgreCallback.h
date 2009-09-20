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

                                                                                       

/** \brief
*/
class NxOgrePublicClass Callback
{
  
  public: // Functions
   
   Callback();
   
   virtual ~Callback();

   /* \brief A Volume has had an event. Use collisionEvent with Enums::VolumeCollisionType for filtering.
      \param Volume of the collision_body has an event with.
      \param volumeShape the specific shape of the volume.
      \param collision_body The collision_body in question.
      \param collision_shape The shape in contact with the volumeShape.
      \param collisionEvent The type of collision.
      \note Depending on the RigidBody the collision_shape may be zero, you should always check
            to see if the pointer exists before using it!
   */
   virtual void onVolumeEvent(Volume* volume, Shape* volumeShape, RigidBody* collision_body, Shape* rigidBodyShape, unsigned int collisionEvent);
   
   /** \brief Is called every time a rayquery gets a hit.
       \return True if the ray should continue, or false to abort.
       \warning Do not modify the Scene whilst in the onRaycastHit function; i.e. destroyActor, or createActor. 
       \see NxUserRaycastReport::onHit
   */
   virtual bool onHitEvent(const RaycastHit&);
   
   /** \brief
   */
   virtual void onContact(const ContactPair&);
   
   /** \brief A class is using the callback.
   */
   void increaseReference();
   
   /** \brief A class is no longer using the callback.
   */
   void decreaseReference();
   
   /** \brief Get the number of references to this callback. Useful for you to decide when the callback should be deleted.
   */
   unsigned int getNbReferences() const;
   
  private:
   
   unsigned int mNbReferences;

}; // class Callback

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

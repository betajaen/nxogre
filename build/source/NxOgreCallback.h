/** File: NxOgreCallback.h
    Created on: 30-Jan-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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

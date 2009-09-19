/** File: NxOgreRigidBody.h
    Created on: 7-Nov-08
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

#ifndef NXOGRE_RIGIDBODY_H
#define NXOGRE_RIGIDBODY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A rigid body
    \important Use an inherited class such as Actor, SceneGeometry, KinematicActor or Trigger.
*/
class NxOgrePublicClass RigidBody : public PointerClass<Classes::_RigidBody>
{
  public: // Functions
  
  /** \brief Retrieves the scene which this rigid body belongs to. 
  */
                        Scene*                getScene(void); 
  
  /** \brief Returns true if the RigidBody is dynamic.
  */
                        bool                  isDynamic(void) const;
  
  /** \internal
  */
                        NxActor*              getNxActor(void);
  
  /** \brief Get the type of RigidBody
  */
  virtual               unsigned int          getType() const;
  
  /** \brief Set a callback for contact reporting.
      \note  As this contact can be shared between RigidBodies it is upto YOU to delete the callback at the appropriate time.
  */
                        void                  setContactCallback(Callback*);
  
  /** \brief Get the assigned callback for contact reporting.
  */
                        Callback*             getContactCallback();
  
  protected: // Function
  
  /** \brief Text
  */
                                              RigidBody(void);
  
  /** \brief Text
  */
  virtual                                    ~RigidBody(void);
  
  /** \brief Create an NxActor based upon the RigidBodyPrototype, in the Scene.
      
  */
  virtual               void                  create(RigidBodyPrototype*, Scene* scene, Shapes* shapes);
  
  /** \brief Create an NxActor using a more simplier form of position, mass, and collision shape.
      \note  A dynamic actor will be created based upon if the mass is 0 or not.
      \param  matrix_pose  Position and orientation of the NxActor.
      \param  shape        Simple shape to use (Automatically deleted after used)
      \param  mass         Mass of the NxActor. Set 0 for a static NxActor.
      \param  scene        Scene to put the NxActor in.
  */
  virtual               void                  create(const Matrix44& matrix_pose, SimpleShape* shape, Real mass, Scene* scene);
  
  /** \internal
  */
  virtual               void                  destroy(void);
  
  protected: // Variables
  
                        NxActor*              mActor;
  
                        Scene*                mScene;
  
                        Callback*             mContactCallback;
  
}; // class RigidBody


                                                                                       

} // namespace NxOgre

                                                                                       

#endif

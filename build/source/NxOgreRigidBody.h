/** File: NxOgreRigidBody.h
    Created on: 7-Nov-08
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

                                                                                       

namespace NxOgre_Namespace
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
  
  protected: // Function
  
  /** \brief Text
  */
                                              RigidBody(void);
  
  /** \brief Text
  */
  virtual                                    ~RigidBody(void);
  
  /** \internal
  */
  virtual               void                  create(RigidBodyPrototype*, Scene*);
  
  /** \internal
  */
  virtual               void                  create(const Matrix44&, SimpleShape*, Real mass, Scene*);
  
  /** \internal
  */
  virtual               void                  destroy(void);
  
  protected: // Variables
  
                        NxActor*              mActor;
  
                        Scene*                mScene;
  
}; // class RigidBody


                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif

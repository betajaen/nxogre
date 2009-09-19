/** File: NxOgreSphericalJoint.h
    Created on: 15-Apr-09
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

#ifndef NXOGRE_SPHERICALJOINT_H
#define NXOGRE_SPHERICALJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SphericalJoint : public Joint
{
  
  friend class Scene;
  
  public: // Functions
  
  /** \brief Returns the current flag settings.
  */
  void                                        setProjectionMode(Enums::JointProjectionMode);
  
  /** \brief Sets the joint projection mode. 
  */
  Enums::JointProjectionMode                  getProjectionMode(void) const;

  /** \brief Get the type of joint
  */
  Enums::JointFunctionType                    getJointType();

  
  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createSphericalJoint.
  */
                                              SphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~SphericalJoint(void);
  
  protected: // Spherical
  
                         NxSphericalJoint*    mSphericalJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

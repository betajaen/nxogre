/** File: NxOgreFixedJoint.h
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

#ifndef NXOGRE_FIXEDJOINT_H
#define NXOGRE_FIXEDJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass FixedJoint : public Joint
{
  
  friend class Scene;
  
  public: // Functions
  
  /** \brief Get the type of joint
  */
  Enums::JointFunctionType                    getJointType();

  
  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createFixedJoint.
  */
                                              FixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~FixedJoint(void);
  
  protected: // Fixed
  
                         NxFixedJoint*    mFixedJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

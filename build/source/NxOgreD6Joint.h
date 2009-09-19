/** File: NxOgreD6Joint.h
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

#ifndef NXOGRE_D6JOINT_H
#define NXOGRE_D6JOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass D6Joint : public Joint
{
  
  friend class Scene;
  
  public: // Functions
  
  /** \brief Set the drive position goal position when it is being driven.
      \see NxD6Joint::setDrivePosition
  */
  void                                        setDrivePosition(const Vec3& position);

  
  /** \brief Set the drive goal orientation when it is being driven.
      \see NxD6Joint::setDriveOrientation
      \note Parameter must be a quaternion.
  */
  void                                        setDriveOrientation(const Vec4& orientation);

  /** \brief Set the drive goal linear velocity when it is being driven.
      \see NxD6Joint::setDriveLinearVelocity
  */
  void                                        setDriveLinearVelocity(const Vec3& linearVelocity);


  /** \brief Set the drive angular velocity goal when it is being driven.
      \see NxD6Joint::setDriveAngularVelocity
  */
  void                                        setDriveAngularVelocity(const Vec3& angularVelocity);

  /** \brief Get the type of joint
  */
  Enums::JointFunctionType                    getJointType();

  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createD6Joint.
  */
                                              D6Joint(RigidBody* first, RigidBody* second, const D6JointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~D6Joint(void);
  
  protected: // D6
  
                         NxD6Joint*    mD6Joint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreRevoluteJoint.h
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

#ifndef NXOGRE_REVOLUTEJOINT_H
#define NXOGRE_REVOLUTEJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass RevoluteJoint : public Joint
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
  Enums::JointFunctionType                    getJointType(void);

  /** \brief Set the angular joint limits
  */
  void                                        setLimits(const JointLimitPairDescription&);

  /** \brief Get the angular joint limits
  */
  JointLimitPairDescription                   getLimits(void);

  /** \brief Set motor parameters for the joints
  */
  void                                        setMotor(const MotorDescription&);

  /** \brief Get back the motor parameters.
  */
  MotorDescription                            getMotor(void);

  /** \brief Get back the motor parameters.
  */
  void                                        setSpring(const SpringDescription&);

  /** \brief Get back the motor parameters.
  */
  SpringDescription                           getSpring(void);

  /** \brief Get the current revolute joint angle.
  */
  Real                                        getAngle(void);

  /** \brief Get the current angular velocity.
  */
  Real                                        getVelocity(void);

  /** \brief Set Revolute joint Flags using the OR operator
      \see Enums::RevoluteJointFlags
  */
  void                                        setRevoluteJointFlags(unsigned int flags);

  /** \brief Set Revolute joint Flags using the OR operator
      \see Enums::RevoluteJointFlags
  */
  unsigned int                                getRevoluteJointFlags(void);


  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createRevoluteJoint.
  */
                                              RevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~RevoluteJoint(void);
  
  protected: // Revolute
  
                         NxRevoluteJoint*    mRevoluteJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

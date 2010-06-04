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
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  /** \brief Returns the current flag settings.
  */
  void                                        setProjectionMode(Enums::JointProjectionMode);
  
  /** \brief Sets the joint projection mode. 
  */
  Enums::JointProjectionMode                  getProjectionMode() const;

  /** \brief Get the type of joint
  */
  Enums::JointFunctionType                    getJointType();

  /** \brief Set the angular joint limits
  */
  void                                        setLimits(const JointLimitPairDescription&);

  /** \brief Get the angular joint limits
  */
  JointLimitPairDescription                   getLimits();

  /** \brief Set motor parameters for the joints
  */
  void                                        setMotor(const MotorDescription&);

  /** \brief Get back the motor parameters.
  */
  MotorDescription                            getMotor();

  /** \brief Get back the motor parameters.
  */
  void                                        setSpring(const SpringDescription&);

  /** \brief Get back the motor parameters.
  */
  SpringDescription                           getSpring();

  /** \brief Get the current revolute joint angle.
  */
  Real                                        getAngle();

  /** \brief Get the current angular velocity.
  */
  Real                                        getVelocity();

  /** \brief Set Revolute joint Flags using the OR operator
      \see Enums::RevoluteJointFlags
  */
  void                                        setRevoluteJointFlags(unsigned int flags);

  /** \brief Set Revolute joint Flags using the OR operator
      \see Enums::RevoluteJointFlags
  */
  unsigned int                                getRevoluteJointFlags();


  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createRevoluteJoint.
  */
                                              RevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~RevoluteJoint();
  
  protected: // Revolute
  
                         NxRevoluteJoint*    mRevoluteJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

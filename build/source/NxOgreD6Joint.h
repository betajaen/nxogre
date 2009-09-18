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

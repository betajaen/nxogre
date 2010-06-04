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

                                                                                       

/*! class. D6Joint
    desc.
        A D6 joint is a general constraint between two actors.
         
        It allows the user to individually define the linear and rotational degrees of freedom. 
        It also allows the user to configure the joint with limits and driven degrees of freedom as they wish.
        
*/
class NxOgrePublicClass D6Joint : public Joint
{
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  /*! function. setDrivePosition
      desc.
          Set the drive position goal position when it is being driven.
      args.
          const Vec3& __position__ -- New drive position.
  */
  void setDrivePosition(const Vec3& position);

  
  /*! function. setDriveOrientation
      desc.
          Set the drive goal orientation when it is being driven.
      args.
          const Quat& __orientation__ -- New drive orientation.
  */
  void setDriveOrientation(const Quat& orientation);

  /*! function. setDriveLinearVelocity
      desc.
          Set the drive goal linear velocity when it is being driven.
      args.
          const Vec3& __linearVelocity__ -- New drive linear velocity.
  */
  void setDriveLinearVelocity(const Vec3& linearVelocity);


  /*! function. setDriveAngularVelocity
      desc.
          Set the drive angular velocity goal when it is being driven.
      args.
          const Vec3& __angularVelocity__ -- New drive angular velocity.
  */
  void setDriveAngularVelocity(const Vec3& angularVelocity);

  /*! function. getJointType
      desc.
          Get the type of joint as JointFunctionType
      return.
          **Enums::JointFunctionType** -- Joint type as a JointFunctionType.
  */
  Enums::JointFunctionType getJointType();

  protected: // Functions
  
  /*! constructor. D6Joint
      see. Scene::createD6Joint
      !protected
  */
  D6Joint(RigidBody* first, RigidBody* second, const D6JointDescription&);
  
  /*! destructor. D6Joint
      see. Scene::destroyJoint
      !protected
  */
  ~D6Joint();
  
  /*! function. to_s
      desc.
          Returns the pointer and class type as string.
  */
  virtual String to_s() const;

  protected: // Variables
  
  NxD6Joint*    mD6Joint;
  
}; // class D6Joint

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

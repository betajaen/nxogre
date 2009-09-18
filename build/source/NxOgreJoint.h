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

                                                                                       

#ifndef NXOGRE_JOINT_H
#define NXOGRE_JOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Joint
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              Joint(RigidBody* first, RigidBody* second);
  
  /** \brief Text
  */
                                             ~Joint(void);
  
  /** \brief Get the type of joint
  */
  virtual Enums::JointFunctionType            getJointType();

  /** \brief Text
  */
  RigidBody*                                  getFirstRigidBody(void);
  
  /** \brief Text
  */
  RigidBody*                                  getSecondRigidBody(void);
  
  /** \brief Text
  */
  void                                        setGlobalAnchor(const Vec3&);
  
  /** \brief Text
  */
  void                                        setGlobalAxis(const Vec3&);
  
  /** \brief Text
  */
  Vec3                                       getGlobalAnchor(void) const;
  
  /** \brief Text
  */
  Vec3                                       getGlobalAxis(void) const;
  
  /** \brief Text.
  */
  Enums::JointState                           getState(void);
  
  /** \brief Text.
  */
  void                                        setBreakable(Real maxForce, Real maxTorque);
  
  /** \brief Retrieves the max force and max torque of a breakable joint.
  */
  void                                        getBreakable(Real& force, Real& torque);

  /** \brief Retrieves the max force of a breakable joint.
  */
  Real                                        getBreakableForce(void);
  
  /** \brief Retrieves the max torque of a breakable joint.
  */
  Real                                        getBreakableTorque(void);
  
  /** \brief Sets the solver extrapolation factor.
  */
  void                                        setSolverExtrapolationFactor(Real solverExtrapolationFactor);
  
  /** \brief Gets the solver extrapolation factor.
  */
  Real                                        getSolverExtrapolationFactor(void) const;
  
  /** \brief Switch between acceleration and force based spring.
  */
  void                                        setUseAccelerationSpring(Enums::JointSpringType);
  
  /** \brief Checks whether acceleration spring is used.
  */
  Enums::JointSpringType                      getUseAccelerationSpring(void) const;
  
  /** \brief Sets the limit point.
  */
  void                                        setLimitPoint(const Vec3& point, bool pointIsOnRigidBody2 = true);
  
  /** \brief Retrieves the global space limit point.
  */
  bool                                        getLimitPoint(const Vec3& worldLimitPoint) const;
  
  /** \brief Adds a limit plane.
  */
  void                                        addLimitPoint(const Vec3& normal, const Vec3& pointInPlane, Real restitution = 0.0f);
  
  /** \brief Purge all limit planes added to the joint.
  */
  void                                        purgeLimitPlanes(void);

  /** \brief Get the limit planes of this Joint.
  */
  Array<SimplePlane>                          getLimitPlaneIterator(void);

  protected:
  
  
    RigidBody* mRigidBodies[2];
    NxJoint*   mJoint;
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreJoint.h
    Created on: 14-Apr-09
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

/** File: NxOgreSphericalJointDescription.h
    Created on: 16-Apr-09
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

#ifndef NXOGRE_SPHERICALJOINTDESCRIPTION_H
#define NXOGRE_SPHERICALJOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SphericalJointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              SphericalJointDescription(void);
  
  /** \brief Text
  */
                                             ~SphericalJointDescription(void);
  
  /** \brief Text
  */
  void                                        reset(void);
  
  /** \brief
  */
  bool                                        isValid(void) const;


  /** \brief Swing limit axis (directional vector) defined in the joint space of RigidBody 0.
      \default Vec3::POS_Z
      \see NxSphericalJointDesc::swingAxis
  */
                Vec3                     mSwingAxis;
  
  /** \brief Distance above which to project joint.
      \default 1.0
      \see NxSphericalJointDesc::projectionDistance
  */
                Real                      mProjectionDistance;

  /** \brief Limits rotation around twist axis
      \default JointLimitDescription::reset()
      \see NxSphericalJointDesc::twistLimit
  */
                JointLimitPairDescription mTwistLimit;

  /** \brief Limits swing of twist axis
      \default JointLimitDescription::reset()
      \see NxSphericalJointDesc::swingLimit
  */
                JointLimitDescription     mSwingLimit;

  /** \brief Spring that works against twisting.
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::twistSpring
  */
                SpringDescription         mTwistSpring;

  /** \brief Spring that works against swinging
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::swingSpring
  */
                SpringDescription         mSwingSpring;

  /** \brief Spring that lets the joint get pulled apart
      \default SpringDescription::reset()
      \see NxSphericalJointDesc::jointSpring
  */
                SpringDescription         mJointSpring;

  /** \brief Combination of Enums::SphericalJointFlags using the OR | operator.
      \default 0
      \see NxSphericalJointDesc::jointSpring
  */
                unsigned int              mSphericalJointFlags;

  /** \brief Enable joint projection.
      \default JointProjectionMode_None
      \see NxSphericalJointDesc::projectionMode
  */
             Enums::JointProjectionMode   mProjectionMode;

  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreRevoluteJointDescription.h
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

#ifndef NXOGRE_REVOLUTEJOINTDESCRIPTION_H
#define NXOGRE_REVOLUTEJOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreMotorDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass RevoluteJointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              RevoluteJointDescription(void);
  
  /** \brief Text
  */
                                             ~RevoluteJointDescription(void);
  
  /** \brief Text
  */
  void                                        reset(void);
  
  /** \brief
  */
  bool                                        isValid(void) const;
  
  /** \brief Distance above which to project joint.
      \default 1.0
      \see NxRevoluteJointDesc::projectionDistance
  */
                Real                      mProjectionDistance;

  /** \brief Angle (in  radians) that is beyond the joint is projected.
      \default 0.0872 (~5 degrees)
      \see NxRevoluteJointDesc::projectionDistance
  */
                Real                      mProjectionAngle;

  /** \brief Limits rotation around twist axis
      \default JointLimitDescription::reset()
      \see NxRevoluteJointDesc::limit
  */
                JointLimitPairDescription mLimit;

  /** \brief Optional motor
      \default JointLimitDescription::reset()
      \see NxRevoluteJointDesc::motor
  */
                MotorDescription          mMotor;

  /** \brief Optional Spring
      \default SpringDescription::reset()
      \see NxRevoluteJointDesc::spring
  */
                SpringDescription         mSpring;

  /** \brief Combination of Enums::RevoluteJointFlags using the OR | operator.
      \default 0
      \see NxRevoluteJointDesc::jointSpring
  */
                unsigned int              mRevoluteJointFlags;

  /** \brief Enable joint projection.
      \default JointProjectionMode_None
      \see NxRevoluteJointDesc::projectionMode
  */
             Enums::JointProjectionMode   mProjectionMode;

  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

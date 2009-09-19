/** File: NxOgreJointLimitSoftDescription.h
    Created on: 19-Apr-09
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

#ifndef NXOGRE_JOINTLIMITSOFTDESCRIPTION_H
#define NXOGRE_JOINTLIMITSOFTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Describes a Joint Limit
*/
class NxOgrePublicClass JointLimitSoftDescription
{
  
  public:
  
  /** \brief Constructor and calls reset.
  */
  JointLimitSoftDescription();

  /** \brief Reset function
  */
  void reset();

  /** \brief Angle (in radians) beyond which the limit is active.
      \see NxJointLimitSoftDesc::value
      \default 0
  */
  Real mValue;
  
  /** \brief Limit bounce
      \see NxJointLimitSoftDesc::restitution
      \default 0
      \range [0,1]
  */
  Real mRestitution;

  /** \brief If greater than zero, the limit is soft, i.e. a spring pulls the joint back to the limit
      \range [0,inf)
      \default 0
  */
  Real mSpring;

  /** \brief Damping of the spring (if the spring is over zero).
      \range [0,inf)
      \default 0
  */
  Real mDamping;

  
}; // class JointLimitSoftDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

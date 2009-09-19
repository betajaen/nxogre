/** File: NxOgreJointDriveDescription.h
    Created on: 20-Apr-09
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

#ifndef NXOGRE_JOINTDRIVEDESCRIPTION_H
#define NXOGRE_JOINTDRIVEDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass JointDriveDescription
{
  
  public: // Functions
  
  /** \brief Constructor which calls reset.
  */
  JointDriveDescription();
  
  
  /** \brief
  */
  void reset();

  /** \brief Type of drive to apply, use operator | to combine flags.
      \see   D6JointDriveType
      \default 0
  */
  unsigned int               mDriveType;
  
  /** \brief Spring coefficient
      \default 0
      \range (-inf, inf)
  */
  Real                       mSpring;
  
  /** \brief Damper coefficient
      \default 0
      \range (-inf, inf)
  */
  Real                       mDamping;
  
  /** \brief Maximum force/torque the drive can exert.
      \default NxOgreRealMax
      \range [0, inf)
  */
  Real                       mForceLimit;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

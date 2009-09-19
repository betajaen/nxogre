/** File: NxOgreMotorDescription.h
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

#ifndef NXOGRE_MOTORDESCRIPTION_H
#define NXOGRE_MOTORDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass MotorDescription
{
  
  public: // Functions
  
  /** \brief "Blank" constructor, calls reset
  */
  MotorDescription();

  /** \brief Alternate constructor
  */
  MotorDescription(Real velocityTarget, Real maxForce, bool freeSpin);
  
  /** \brief Resets the description per the PhysX SDK guidelines.
  */
  void reset();

  /** \brief The relative velocity the motor should try to reach.
      \see NxMotorDesc::velTarget
      \range [0,inf]
      \default NxOgrRealMax
  */
  Real       mVelocityTarget;
  
  /** \brief Max force (or torque) the motor can exert.
      \range [0, inf]
      \default 0 (Off)
  */
  Real       mMaxForce;
  
  /** \brief Break when the motor spins faster than the velocity target.
      \default false
  */
  bool       mFreeSpin;

}; // class MotorDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

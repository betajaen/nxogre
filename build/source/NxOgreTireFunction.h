/** File: NxOgreTireFunction.h
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

#ifndef NXOGRE_TIREFUNCTION_H
#define NXOGRE_TIREFUNCTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Describes a Joint Tire
    \see NxTireFunctionDesc
*/
class NxOgrePublicClass TireFunction
{
 public:
  
  /** \brief Constructor and calls reset.
  */
  TireFunction();

  /** \brief Reset function
  */
  void reset();

  /** \brief Extremal point of curve.  Both values must be positive.
      \range (0, inf)
      \default 1.0
  */
  Real mExtremumSlip;

  /** \brief Extremal point of curve.  Both values must be positive.
      \range (0, inf)
      \default 0.02
  */
  Real mExtremumValue;

  /** \brief Ppoint on curve at which for all x > minumumX, function equals minimumY.  Both values must be positive.
      \range (0, inf)
      \default 2.0
  */
  Real mAsymptoteSlip;

  /** \brief Point on curve at which for all x > minumumX, function equals minimumY.  Both values must be positive.
      \range (0, inf)
      \default 0.01
  */
  Real mAsymptoteValue;

  /** \brief Scaling factor for tire force.
      \range (0, inf)
      \default 1000000.0
  */
  Real mStiffnessFactor;

}; // class TireFunction

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

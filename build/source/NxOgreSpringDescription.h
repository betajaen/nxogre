/** File: NxOgreSpringDescription.h
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

#ifndef NXOGRE_SPRINGDESCRIPTION_H
#define NXOGRE_SPRINGDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Describes a Joint Spring
*/
class NxOgrePublicClass SpringDescription
{
 public:
  
  /** \brief Constructor and calls reset.
  */
  SpringDescription();

  /** \brief Reset function
  */
  void reset();

  /** \brief Spring coefficient
      \see NxSpringDesc::spring
      \default 0
  */
  Real mSpring;

  /** \brief Damper coefficient
      \see NxSpringDesc::damper
      \default 0
  */
  Real mDamper;

  /** \brief Target value (either in radians or positional) of spring where the 
             spring force is zero.
      \see NxSpringDesc::targetValue
      \default 0
  */
  Real mTargetValue;
  
}; // class SpringDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

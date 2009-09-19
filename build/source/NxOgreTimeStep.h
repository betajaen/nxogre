/** File: NxOgreTimeStep.h
    Created on: 9-Nov-08
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

#ifndef NXOGRE_TIMESTEP_H
#define NXOGRE_TIMESTEP_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
struct NxOgrePublicClass TimeStep
{
  
  public: // Variables
  
  /** \brief Actual timestep given to the TimeController
  */
                        Real                  mActual;
  
  /** \brief Modified timestep by the TimeController; unless your doing anything special. You
             should always use the modified version.
  */
                        Real                  mModified;
  
  /** \brief Interpolation alpha.
  */
                        Real                  mAlpha;
  
  /** \brief Number of times the scene was simulated during a given timestep.
  */
                        unsigned int          mSubSteps;
  
}; // class TimeStep

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

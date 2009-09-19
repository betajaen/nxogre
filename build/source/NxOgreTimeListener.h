/** File: NxOgreTimeListener.h
    Created on: 09-Nov-08
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

#ifndef NXOGRE_TIMELISTENER_H
#define NXOGRE_TIMELISTENER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreTimeStep.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A TimeListener is any class that needs to react when the timestep goes fowards in NxOgre.
*/
class NxOgrePublicClass TimeListener
{
  
  public: // Functions
  
  /** \brief Must be implemented by user. Called when a time step is injected into NxOgre.
             In some cases your class advance function may not be ready for use (such as waiting for
             a thread to finish); in that case return false to be placed onto a waiting list - which
             the time controller will try again at the end of each priority and at the next timestep.
      \return True if the function was carried out normally, false if the function needs to be revisited later in this timeStep.
  */
  virtual bool                               advance(float deltaTime, const Enums::Priority&) = 0;
  
}; // class TimeListener

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreMachine.h
    Created on: 18-May-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lessebr General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_MACHINE_H
#define NXOGRE_MACHINE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreActorMachinePart.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A machine is a dynamic RigidBody, which has many parts that may be "rendered" or controlled seperatly. A vehicle
           is a type of machine.
*/
class NxOgrePublicClass Machine : public ActorMachinePart
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              Machine(void);
  
  /** \brief Text
  */
                                             ~Machine(void);
  
  /** \brief Text
  */
  MachinePart*                                createWheelMachinePart(Wheel*, PointRenderable*);
  
  /** \brief
  */
  virtual void                                simulate(float user_deltaTime);
  
  protected: // Variables
  
  Array<MachinePart*>                         mMachineParts;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreMachinePart.h
    Created on: 18-May-09
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

#ifndef NXOGRE_ACTORMACHINEPART_H
#define NXOGRE_ACTORMACHINEPART_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMachinePart.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ActorMachinePart : public MachinePart
{
  
  public: // Functions
  
  /** \brief Text
  */
  ActorMachinePart();

  /** \brief Text
  */
  ActorMachinePart(Actor* actor, PointRenderable* = 0);
  
  /** \brief Text
  */
  ~ActorMachinePart();
  
  /** \brief Text
  */
  virtual void                                simulate(float user_deltaTime);
  
  /** \brief
  */
  Actor*                                      mActor;
  
  /** \brief
  */
  PointRenderable*                            mPointRenderable;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

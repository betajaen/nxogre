/** File: NxOgrePhysXCallback.h
    Created on: 31-Jan-09
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

#ifndef NXOGRE_PHYSX_CALLBACK_H
#define NXOGRE_PHYSX_CALLBACK_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK

/** \brief
*/
class NxOgrePublicClass PhysXCallback : public PointerClass<Classes::_PhysXCallback>,
                                        public NxUserTriggerReport,
                                        public NxUserContactReport
{
  
  public: // Functions
  
   PhysXCallback(Scene*);
  
  ~PhysXCallback();
  
   void onTrigger(NxShape& triggerShape, NxShape& otherShape, NxTriggerFlag status);
  
   void onContactNotify(NxContactPair& pair, NxU32 events);
  
  protected: // Variables
  
   Scene*    mScene;
  
}; // class ClassName

#endif
                                                                                       

} // namespace NxOgre

                                                                                       

#endif

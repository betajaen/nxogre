/** File: NxOgrePhysXUserEntityReport.h
    Created on: 09-Apr-09
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

#ifndef NXOGRE_PHYSXUSERENTIYREPORT_H
#define NXOGRE_PHYSXUSERENTIYREPORT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreEntityReport.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif


                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK

/** \brief
*/
template <typename T>
class NxOgrePublicClass PhysXUserEntityReport : public NxUserEntityReport<T>
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              PhysXUserEntityReport(EntityReport<T>* entityReport)
  : mEntityReport(entityReport)
  {
  }
  
  /** \brief Text
  */
                                             ~PhysXUserEntityReport(void)
  {
  }
  
  /** \brief Text
  */
  bool                                        onEvent(unsigned int tSize, T* t)
  {
   ReadOnlyBuffer<T> buffer(t, t + tSize);
   return mEntityReport->onEvent(buffer);
  }
  
  
  protected: // Variables
  
  EntityReport<T>*                            mEntityReport;
  
  
}; // class ClassName

#endif

                                                                                       

} // namespace PhysXEntityReport

                                                                                       

#endif

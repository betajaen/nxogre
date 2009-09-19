/** File: NxOgrePhysXOutputStream.h
    Created on: 3-Nov-08
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

#ifndef NXOGRE_PHYSX_OUTPUTSTREAM_H
#define NXOGRE_PHYSX_OUTPUTSTREAM_H

                                                                                       

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
class NxOgrePublicClass PhysXOutputStream : public PointerClass<Classes::_PhysXOutputStream>, public NxUserOutputStream
{
  
  friend class World;
  
  public:
  
  /** \brief What do when there is an assertion from PhysX
  */
                        void                  setAssertionResponse(Enums::PhysXAssertionResponse);

  protected: // Functions
  
  /** \internal
  */
                                              PhysXOutputStream(void);
  
  /** \internal
  */
                                             ~PhysXOutputStream(void);
  
  /** \internal
  */
                        void                  reportError(NxErrorCode code, const char * message, const char *file, int line);

  /** \internal
  */
                        NxAssertResponse      reportAssertViolation(const char * message, const char *file, int line);

  /** \internal
  */
                        void                  print(const char*);
  
  protected: // Variables
  
                        NxAssertResponse      mAssertionResponse;
  
}; // class ClassName

#endif
                                                                                       

} // namespace NxOgre

                                                                                       

#endif

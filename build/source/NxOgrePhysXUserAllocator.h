/** File: NxOgrePhysXUserAllocator.h
    Created on: 6-Nov-08
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

#ifndef NXOGRE_PHYSXUSERALLOCATOR_H
#define NXOGRE_PHYSXUSERALLOCATOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif
                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK
/** \internal
*/
class NxOgrePublicClass PhysXUserAllocator : public PointerClass<Classes::_PhysXUserAllocator>, public NxUserAllocator
{
  
  friend class World;
  
  protected: // Functions
  
  /** \internal
  */
                                              PhysXUserAllocator(void);
  
  /** \internal
  */
                                             ~PhysXUserAllocator(void);
  
  /** \internal
  */
                        void*                 mallocDEBUG(size_t, const char*, int);
  
  /** \internal
  */
                        void*                 mallocDEBUG(size_t, const char*, int, const char*, NxMemoryType);
  
  /** \internal
  */
                        void*                 malloc(size_t);
  
  /** \internal
  */
                        void*                 malloc(size_t, NxMemoryType);
  
  /** \internal
  */
                        void*                 realloc(void*, size_t);
  
  /** \internal
  */
                        void                  free(void*);
  
  /** \internal
  */
                        void                  checkDEBUG(void);
  
}; // class ClassName

#endif

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreMemory.h
    Created on: 2-Nov-08
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

#ifndef NXOGRE_MEMORY_H
#define NXOGRE_MEMORY_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Memory is a class to handle all memory functions off the stack. Every class
           or piece of memory allocated via NxOgre or PhysX is routed through here for
           intelligent allocation and recording.
*/
class NxOgrePublicClass Memory
{
  
  private: // Functions
  
  /** \brief Memory is a static only class, do not create.
  */
                                              Memory(void);
  
  /** \brief Memory is a static only class, do not destroy.
  */
                                             ~Memory(void);
  
  public: // Functions
  
  /** \brief Force the memory debugger (if running) to clean up any un-used space (except for ~320 bytes).
  */
  static                 void                 performHouseKeeping(void);

  /** \brief Get the amount of over-head (allocation storage) the MemoryDebugger is using.
  */
  static                 unsigned int         overhead(void);
  
  /** \brief Allocate some memory using the internal memory allocation system.
             All calls to malloc or new must be routed through here.
  */
#if (NxOgreMemoryDebugger == 1)
  static                 void*                allocate(size_t, unsigned int type_id = 0, const char* file = 0, unsigned int file_line = 0);
#else
  static                 void*                allocate(size_t);
#endif

  
  /** \brief Reallocate some memory using the internal memory allocation system.
             All calls to realloc must be routed through here.
  */
  static                 void*                reallocate(void*, size_t);
  
  /** \brief Unallocate some memory using the internal memory allocation system.
             All calls to free or delete must be routed through here.
  */
  static                 void                 unallocate(void*);
  
  /** \brief Just like memcpy.
  */
  static                 void                 copy(void* dest, const void* src, size_t length);
}; // class Memory

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

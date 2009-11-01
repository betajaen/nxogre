/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
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

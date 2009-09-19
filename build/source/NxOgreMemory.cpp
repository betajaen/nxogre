/** File: NxOgreMemory.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMemory.h"
#include "NxOgreMemoryDebugger.h"

#include <string.h>                 // For memcpy

                                                                                       

#if (NxOgreMemoryAllocator==NxOgreMemoryAllocatorMalloc)
#
# include "malloc.h"
# define NxOgreMalloc  ::malloc
# define NxOgreFree    ::free
# define NxOgreRealloc ::realloc
#
#elif (NxOgreMemoryAllocator==NxOgreMemoryAllocatorNedmalloc)
#
# include "nedmalloc.h"
# define NxOgreMalloc   ::nedalloc::nedmalloc
# define NxOgreFree     ::nedalloc::nedfree
# define NxOgreRealloc  ::nedalloc::nedrealloc
#
#else
#  error Unknown Memory Allocator type.
#endif

                                                                                       

#if (NxOgreMemoryDebugger == 1)
 extern NxOgre::MemoryDebugger gMemoryDebugger;
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

#if (NxOgreMemoryDebugger == 1)

void* Memory::allocate(size_t size, unsigned int type_id, const char* file, unsigned int file_line)
{
 return gMemoryDebugger.addAllocation(NxOgreMalloc(size), size, type_id, file, file_line);
}

#else

void* Memory::allocate(size_t size)
{
 return NxOgreMalloc(size);
}

#endif


#if (NxOgreMemoryDebugger == 1)

void* Memory::reallocate(void* mem, size_t new_size)
{
 if (mem != 0)
 {
  void* new_mem = NxOgreRealloc(mem, new_size);
  gMemoryDebugger.changeAllocation(mem, new_mem, new_size);
  return new_mem;
 }
 return 0;
}

#else

void* Memory::reallocate(void* ptr, size_t size)
{
 if (ptr != 0)
  return NxOgreRealloc(ptr, size);
 else
  return 0;
}

#endif


#if (NxOgreMemoryDebugger == 1)

void Memory::unallocate(void *mem)
{
 if (mem == 0)
  return;

 NxOgreFree(mem);
 gMemoryDebugger.removeAllocation(mem);

}

#else

void Memory::unallocate(void* mem)
{
  if (mem)
   NxOgreFree(mem);
}

#endif

void  Memory::performHouseKeeping(void)
{
#if NxOgreMemoryDebugger == 1
 gMemoryDebugger.clean();
#endif
}

unsigned int  Memory::overhead(void)
{
#if NxOgreMemoryDebugger == 1
 return gMemoryDebugger.getOverhead();
#else
 return 0;
#endif
}

void Memory::copy(void* dest, const void* source, size_t length)
{
 memcpy(dest, source, length);
}

                                                                                       

#undef NxOgreMalloc
#undef NxOgreFree
#undef NxOgreRealloc

                                                                                       

} // namespace NxOgre

                                                                                       

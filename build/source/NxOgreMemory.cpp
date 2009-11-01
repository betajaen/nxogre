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

                                                                                       

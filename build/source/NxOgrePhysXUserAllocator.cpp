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
#include "NxOgrePhysXUserAllocator.h"

                                                                                       

namespace NxOgre 
{

                                                                                       

PhysXUserAllocator::PhysXUserAllocator()
{
}

PhysXUserAllocator::~PhysXUserAllocator()
{
}

void* PhysXUserAllocator::mallocDEBUG(size_t size, const char* filename, int line)
{
 return GC::safe_malloc<void, PhysXClassAllocator>(size, filename, line);
}

void* PhysXUserAllocator::mallocDEBUG(size_t size, const char* filename, int line, const char* class_name, NxMemoryType type)
{
 return GC::safe_malloc<void, PhysXClassAllocator>(size, Classes::TypeToCStr(type), filename, line);
}

void* PhysXUserAllocator::malloc(size_t size)
{
 return GC::safe_malloc<void, PhysXClassAllocator>(size, NXOGRE_GC_THIS);
}

void* PhysXUserAllocator::malloc(size_t size, NxMemoryType type)
{
 return GC::safe_malloc<void, PhysXClassAllocator>(size, Classes::TypeToCStr(type), NXOGRE_GC_THIS);
}

void* PhysXUserAllocator::realloc(void* memory, size_t size)
{
 return GC::safe_realloc<void, PhysXClassAllocator>(memory, size, NXOGRE_GC_THIS);
}

void PhysXUserAllocator::free(void* mem)
{
 GC::safe_free<void, PhysXClassAllocator>(mem, NXOGRE_GC_THIS);
}

void PhysXUserAllocator::checkDEBUG()
{ // cannot be not implemented.
}

                                                                                       

} // namespace NxOgre

                                                                                       

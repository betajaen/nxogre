/** File: NxOgrePhysXUserAllocator.cpp
    Created on: 6-Nov-08
    Author: Robin Southern "betajaen"
    Last-Modified-For: PhysX 2.8.1
    

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
#include "NxOgrePhysXUserAllocator.h"

                                                                                       

namespace NxOgre 
{

                                                                                       

PhysXUserAllocator::PhysXUserAllocator(void)
{
}

PhysXUserAllocator::~PhysXUserAllocator(void)
{
}

void* PhysXUserAllocator::mallocDEBUG(size_t size, const char* fileName, int line)
{
#if NxOgreMemoryDebugger == 1
 return Memory::allocate(size, Classes::_void, fileName, line);
#else
 return Memory::allocate(size);
#endif
}

void* PhysXUserAllocator::mallocDEBUG(size_t size, const char* fileName, int line, const char* className, NxMemoryType type)
{
#if NxOgreMemoryDebugger == 1
 return Memory::allocate(size, type, fileName, line);
#else
 return Memory::allocate(size);
#endif
}

void* PhysXUserAllocator::malloc(size_t size)
{
#if NxOgreMemoryDebugger == 1
 return Memory::allocate(size, Classes::_void);
#else
 return Memory::allocate(size);
#endif
}

void* PhysXUserAllocator::malloc(size_t size, NxMemoryType type)
{
#if NxOgreMemoryDebugger == 1
 return Memory::allocate(size, type);
#else
 return Memory::allocate(size);
#endif
}

void* PhysXUserAllocator::realloc(void* memory, size_t size)
{
 return Memory::reallocate(memory, size);
}

void PhysXUserAllocator::free(void* memory)
{
 Memory::unallocate(memory);
}

void PhysXUserAllocator::checkDEBUG(void)
{
}

                                                                                       

} // namespace NxOgre

                                                                                       

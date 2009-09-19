/** File: NxOgreMemoryDebugger.cpp
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

# if (NxOgreMemoryDebugger == 1)

#include "NxOgreMemoryDebugger.h"
#include "stdio.h"

#include "NxPhysicsSDK.h"

                                                                                       

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

/** \brief The Everything Is Okay Alarm.
    \note  It will keep beeping until something is wrong, then you know something isn't OKAY!
*/
int NxOgre_CreationStatus = 0;

extern void setNxOgreCreationStatus(int b)
{
 NxOgre_CreationStatus = b;
}


#if NxOgreCompiler == NxOgreCompilerMSVC
 #define NXOGRE_COMPILER_STRING "Microsoft Visual C++ (" NxOgre_Stringify(_MSC_VER) ")"
#elif NxOgreCompiler == NxOgreCompilerGNUC
 #define NXOGRE_COMPILER_STRING "GCC"
#else
 #define NXOGRE_COMPILER_STRING "?"
#endif

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
 #define NXOGRE_ACCURACY_STRING "float"
#else
 #define NXOGRE_ACCURACY_STRING "double"
#endif

#ifdef NXOGRE_DEBUG
 #define NXOGRE_DEBUG_STRING "Debug"
#else
 #define NXOGRE_DEBUG_STRING ""
#endif

#ifdef NXOGRE_OPTIONS_DYNAMIC_LIBRARY
 #define NXOGRE_DYNAMIC_LIBRARY_STRING "Shared Library"
#elif defined NXOGRE_OPTIONS_STATIC_LIBRARY
 #define NXOGRE_DYNAMIC_LIBRARY_STRING "Static Library"
#else
 #define NXOGRE_DYNAMIC_LIBRARY_STRING ""
#endif

#if (NxOgreMemoryDebugger == 1)
::NxOgre::MemoryDebugger gMemoryDebugger;
#endif

                                                                                       

namespace NxOgre
{

                                                                     


MemoryDebugger::MemoryDebugger(void)
: _First(0),
  _Last(0),
  _End(0),
  _CleanAllowed(true)
{
 // Reserve ~NxOgreMemoryDebuggerInitialAllocationSize of space for early allocations.
 _reserve((NxOgreMemoryDebuggerInitialAllocationSize / sizeof(MemoryAllocation)));
}

MemoryDebugger::~MemoryDebugger(void)
{
 writeAllocationsToFile();
 if (_First)
  NxOgreFree(_First);
}

void* MemoryDebugger::addAllocation(void* ptr, size_t size, unsigned int class_id, const char* file, unsigned int line)
{
 if (_End <= _Last)
  _reserve((1 + _size()) * 2);
 _Last->_Ptr = ptr;
 _Last->_Size = size;
 _Last->_Type = class_id;
 _Last->_File = file;
 _Last->_Line = line;
 _Last++;
 return ptr;
}

void MemoryDebugger::removeAllocation(void* ptr)
{
 VtIterator begin = _First, last = _Last;
 for (;begin != last; ++begin)
  if (ptr == begin->_Ptr)
  {
   *begin = *(_Last - 1);
   _Last--;
  }
 clean();
}

void MemoryDebugger::changeAllocation(void* ptr, void* new_ptr, size_t new_size)
{
 VtIterator begin = _First, last = _Last;
 for (;begin != last; ++begin)
  if (ptr == begin->_Ptr)
  {
   begin->_Ptr = new_ptr;
   begin->_Size = new_size;
  }
}

unsigned int MemoryDebugger::_size() const
{
 return unsigned int(_Last - _First);
}

unsigned int MemoryDebugger::_capacity() const
{
 return unsigned int(_End - _First);
}

void MemoryDebugger::_clear()
{
 _Last = _First;
}

void MemoryDebugger::_copy(VtIterator begin, VtIterator end, VtIterator dest)
{
 for (;begin != end; ++dest, ++begin)
  *dest = *begin;
}

void MemoryDebugger::_clip(unsigned int size)
{
 if (size < _size())
  return;
 _resize(size);
}

void MemoryDebugger::_reserve(unsigned int new_size)
{
 if (_capacity() >= new_size)
  return;
 _resize(new_size);
}

void MemoryDebugger::_resize(unsigned int new_size)
{
 VtIterator new_first = (VtIterator) NxOgreMalloc(new_size * sizeof(Vt));
 _copy(_First, _Last, new_first);
 _range_destruct(_First, _Last);
 if (_First)
  NxOgreFree(_First);
 _End = new_first + new_size;
 _Last = new_first + _size();
 _First = new_first;
}

void MemoryDebugger::_range_destruct(VtIterator begin, VtIterator end)
{
 for (;begin != end; ++begin)
  begin->~MemoryAllocation();
}

void MemoryDebugger::clean(void)
{
 if (_CleanAllowed && (_size() < _capacity() / 2))
 {
  _reserve(_size() + 16);
 }
}

void MemoryDebugger::allowCleanups(bool b)
{
 _CleanAllowed = b;
}

unsigned int MemoryDebugger::getOverhead(void)
{
 return _capacity() * sizeof(MemoryAllocation);
}

void MemoryDebugger::writeAllocationsToFile(const char* fileName)
{
#ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE

 FILE * file;
 file = fopen(fileName,"w");

 if (_size() == 0)
 {
  fclose(file);
  return;
 }
 
 fprintf(file, "# NxOgre Allocations\n---\nVersions:\n    - NxOgre: %i.%i.%i '%s'\n    - PhysX: %i.%i.%i (%i)\nConfiguration:\n    - Compiler: %s\n    - Accuracy: %s\n    - Build: %s %s\n",
               NxOgreVersionMajor, NxOgreVersionMinor, NxOgreVersionRelease, NxOgreCodeName,
               NX_SDK_VERSION_MAJOR, NX_SDK_VERSION_MINOR, NX_SDK_VERSION_BUGFIX, NX_SDK_VERSION_NUMBER,
               NXOGRE_COMPILER_STRING, NXOGRE_ACCURACY_STRING,
               NXOGRE_DEBUG_STRING, NXOGRE_DYNAMIC_LIBRARY_STRING
 );
 
 VtIterator allocation = _First, last = _Last;
 fprintf(file, "Allocations:\n");
 for (;allocation != last; ++allocation)
 {
  int allocType = abs(allocation->_Type);

  if (allocType < Classes::NXOGRE_CLASSES_BEGIN)
  {
    fprintf(file, "    - PhysX memory: #%p\n", allocation->_Ptr);
  }
  else if (allocType > Classes::RENDERSYSTEMS_CLASSES_BEGIN)
  {
   if (allocation->_Type < 0)
    fprintf(file, "    - User array: #%p\n", allocation->_Ptr);
   else
    fprintf(file, "    - User pointer: #%p\n", allocation->_Ptr);
  }
  else
  {
   if (allocation->_Type < 0)
    fprintf(file, "    - Array: #%p\n", allocation->_Ptr);
   else
    fprintf(file, "    - Pointer: #%p\n", allocation->_Ptr);
  }
  
  if (allocType > Classes::RENDERSYSTEMS_CLASSES_BEGIN)
  {
   fprintf(file, "      Pointer class Id: %i\n", allocType);
  }
  else
  {
   fprintf(file, "      Type: %s\n", ::NxOgre::Classes::TypeToCStr(allocType));
  }
  
  if (allocation->_Size >= 1024)
  {
   fprintf(file, "      Size: %.1f kb\n", float(allocation->_Size) / 1024.0f);
  }
  else
   fprintf(file, "      Size: %i b\n", allocation->_Size);
  
  if (allocation->_File && allocation->_Line)
  {
   fprintf(file, "      Source: %s#%i\n", allocation->_File, allocation->_Line);
  }
 
  if (allocation->_Size > 4)
  {
   if (allocation->_Size > 256)
    fprintf(file, "      Partial dump:  >\n");
   else
    fprintf(file, "      Dump:  >\n");
    
    unsigned int m = allocation->_Size;
    if (m > 256)
     m = 256;
    
    fprintf(file, "           ");
    unsigned int k=0;
    for (unsigned int i=0;i < m;i++)
    {
     unsigned char c = ((unsigned char*)allocation->_Ptr)[i];
     if (c < 32 || c > 128)
      fprintf(file, ".");
     else
      fprintf(file, "%c", c);
     k++;
     if (k==32 || i == m)
     {
      k=0;
      fprintf(file, "\n           ");
     }
    }
    
    fprintf(file, "\n");
  }


  fflush(file);
 }



 
 fprintf(file, "\n# End of %i allocations.", _size());
 fclose(file);
 
#endif
}


                                                                                       

#undef NxOgreMalloc
#undef NxOgreFree
#undef NxOgreRealloc
#undef NXOGRE_COMPILER_STRING
#undef NXOGRE_ACCURACY_STRING
                                                                                       

} // namespace NxOgre

                                                                                       


#endif

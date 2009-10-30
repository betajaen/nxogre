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

                                                                                       

#ifndef NXOGRE_ALLOCATOR_H
#define NXOGRE_ALLOCATOR_H

                                                                                       

#include "NxOgreStable.h"
#include <map>
#include <fstream>

                                                                                       

namespace NxOgre
{

                                                                                       

class MallocAllocator
{
  
 public:
  
  MallocAllocator()
  {
  }

  ~MallocAllocator()
  {
  }

  static inline void* allocateBytes(size_t length, const char* file, unsigned int line)
  {
   return malloc(length);
  }
  
  static inline void* allocateBytes(size_t length)
  {
   return malloc(length);
  }
  
  static inline void* reallocateBytes(void* memory, size_t newLength)
  {
   return realloc(memory, newLength);
  }
  
  static inline void deallocateBytes(void* memory)
  {
   free(memory);
  }
  
};


class TrackedMallocAllocator
{
 public:

  TrackedMallocAllocator()
  {
  }

 ~TrackedMallocAllocator()
  {
   #ifdef NXOGRE_MEMORY_DEBUGGER_USEFILE
    std::ofstream s("NxOgreLeaks.txt");
    for (std::map<void*, size_t>::iterator i = sMemory.begin(); i != sMemory.end(); i++)
     s << (*i).first << " => " << (*i).second << " b\n";
    s.close();
   #endif
  }

  static inline void* allocateBytes(size_t length, const char* file, unsigned int line)
  {
   void* ptr = malloc(length);
   pushMem(ptr, length, file, line);
   return ptr;
  }

  static inline void* allocateBytes(size_t length)
  {
   void* ptr = malloc(length);
   pushMem(ptr, length,0,0);
   return ptr;
  }

  static inline void* reallocateBytes(void* memory, size_t newLength)
  {
   void* newPtr = realloc(memory, newLength);
   popMem(memory);
   pushMem(newPtr, newLength, 0, 0);
  }

  static inline void deallocateBytes(void* memory)
  {
   free(memory);
   popMem(memory);
  }

 protected:

  static void pushMem(void* ptr, size_t length, const char* file, unsigned int line)
  {
   sMemory.insert(std::pair<void*, size_t>(ptr, length));
  }

  static void popMem(void* ptr)
  {
   std::map<void*, size_t>::iterator i = sMemory.find(ptr);
   if (i != sMemory.end())
    sMemory.erase(i);
  }

  static std::map<void*, size_t> sMemory;

};

template<class SpecialisedAllocator> class Allocator : public SpecialisedAllocator {};


template<class Allocator> class Allocatable
{
 public:
  
  explicit Allocatable() {}
  
  ~Allocatable() {}
  
  void* operator new (size_t length, const char* file, int line)
  {
   return Allocator::allocateBytes(length, file, line);
  }
  
  void* operator new(size_t length)
  {
   return Allocator::allocateBytes(length);
  }

  void* operator new[](size_t length, const char* file, int line)
  {
   return Allocator::allocateBytes(length, file, line);
  }
  
  void* operator new[](size_t length)
  { 
   return Allocator::allocateBytes(length);
  }

  void operator delete(void* ptr)
  {
   Allocator::deallocateBytes(ptr);
  }
  
  void operator delete(void* ptr, const char*, int)
  { 
   Allocator::deallocateBytes(ptr);
  }
  
  void operator delete[](void* ptr)
  { 
   Allocator::deallocateBytes(ptr);
  }
  
  void operator delete[](void* ptr, const char*, int)
  {
   Allocator::deallocateBytes(ptr);
  }

};


#define NxOgreNew new

#define NxOgreDelete(PTR) if (PTR){delete PTR;PTR=0;}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

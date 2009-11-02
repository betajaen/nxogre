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

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator> inline T* NxOgreAllocatedNew()
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T();
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0> inline T* NxOgreAllocatedNew(const _0& arg0)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2, typename _3> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const _3& arg3)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2, arg3);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2, typename _3, typename _4> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const _3& arg3, const _4& arg4)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2, arg3, arg4);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2, typename _3, typename _4, typename _5> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const _3& arg3, const _4& arg4, const _5& arg5)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2, arg3, arg4, arg5);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2, typename _3, typename _4, typename _5, typename _6> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const _3& arg3, const _4& arg4, const _5& arg5, const _6& arg6)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator, typename _0, typename _1, typename _2, typename _3, typename _4, typename _5, typename _6, typename _7> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const _3& arg3, const _4& arg4, const _5& arg5, const _6& arg6, const _7& arg7)
{
 void* mem = Allocator::allocateBytes(sizeof(T));
 T* ptr = new(mem) T(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
 return ptr;
}

/* Safe way of deleting a pointer of a class that was previously new'd through NxOgreAllocatedNew
   Note: Only classes that don't inherit from Allocatable should use this function.
*/
template<typename T, class Allocator> inline void NxOgreAllocatedDelete(T* ptr)
{
 if (ptr == 0)
  return;
 ptr->~T();
 Allocator::deallocateBytes(ptr);
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

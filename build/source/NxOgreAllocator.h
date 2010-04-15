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
#include "NxOgreEnums.h"

                                                                                       

namespace NxOgre
{

                                                                                       

template<class SpecialisedAllocator> class Allocator : public SpecialisedAllocator {};


template<class Allocator> class Allocatable
{
 public:
  
  typedef Allocator Allocator;
  
  explicit Allocatable() {}
  
  ~Allocatable() {}
  
  void* operator new (size_t length, const char* file, int line)
  {
#ifdef NXOGRE_DEBUG
   return Allocator::allocateBytes(length, file, line);
#else
   return Allocator::allocateBytes(length);
#endif
  }
  
  void* operator new(size_t length)
  {
#ifdef NXOGRE_DEBUG
   return Allocator::allocateBytes(length, 0, 0);
#else
   return Allocator::allocateBytes(length);
#endif
  }

  void* operator new[](size_t length, const char* file, int line)
  {
#ifdef NXOGRE_DEBUG
   return Allocator::allocateBytes(length, file, line);
#else
   return Allocator::allocateBytes(length);
#endif
  }
  
  void* operator new[](size_t length)
  {
#ifdef NXOGRE_DEBUG
   return Allocator::allocateBytes(length, 0, 0);
#else
   return Allocator::allocateBytes(length);
#endif
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

/* Macro for new, for any class that doesn't inherit from allocatable and won't be involved with the allocator.
*/
#define NXOGRE_NEW new

/* Non-Safe way of deleting a class that inherits from Alloctable.
*/
#define NXOGRE_DELETE(PTR) if (PTR){delete PTR;PTR=0;}

/* Safe way of new'ing a class that inherits from Allocatable.
*/
#ifdef NXOGRE_DEBUG
#define NXOGRE_NEW_NXOGRE new(__FILE__, __LINE__)
#else
#define NXOGRE_NEW_NXOGRE new
#endif

/* Safe way of deleting a class that inherits from Alloctable.
*/
#define NXOGRE_DELETE_NXOGRE(A_PTR) if (A_PTR){delete A_PTR;A_PTR=0;}

#define NXOGRE_DELETE_PHYSX(TYPE, ALLOCATOR, PTR) NxOgreAllocatedDelete<TYPE, ALLOCATOR>(PTR);PTR=0;

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

/* Safe way of new'ing a class that doesn't inherit from Allocatable but wants to be managed by the Allocator.
   Note: Only classes that don't inherit from Allocatable but want to use the allocator for memory, should use this function.
   Remember to use the NXOGRE_NEW_PHYSX macro, rather than directly using the function.
*/
#ifdef NXOGRE_DEBUG
#define NXOGRE_NEW_PHYSX(TYPE, ALLOCATOR) NxOgreAllocatedNew<TYPE, ALLOCATOR>(__FILE__, __LINE__)
template<typename T, class Allocator> inline T* NxOgreAllocatedNew(const char* file, unsigned int line)
#else
#define NXOGRE_NEW_PHYSX(TYPE, ALLOCATOR) NxOgreAllocatedNew<TYPE, ALLOCATOR>()
template<typename T, class Allocator> inline T* NxOgreAllocatedNew()
#endif
{
 void* mem = Allocator::allocateBytes(sizeof(T)
#ifdef NXOGRE_DEBUG
 ,file,line
#endif
 );
 T* ptr = new(mem) T();
 return ptr;
}

/* Safe way of new'ing a class that doesn't inherit from Allocatable but wants to be managed by the Allocator.
   Note: Only classes that don't inherit from Allocatable but want to use the allocator for memory, should use this function.
   Remember to use the NXOGRE_NEW_PHYSX1 macro, rather than directly using the function.
*/
#ifdef NXOGRE_DEBUG
#define NXOGRE_NEW_PHYSX1(TYPE, ALLOCATOR, TYPE0, ARG0) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0>(ARG0, __FILE__, __LINE__)
template<typename T, class Allocator, typename _0> inline T* NxOgreAllocatedNew(const _0& arg0, const char* file, unsigned int line)
#else
#define NXOGRE_NEW_PHYSX1(TYPE, ALLOCATOR, TYPE0, ARG0) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0>(ARG0)
template<typename T, class Allocator, typename _0> inline T* NxOgreAllocatedNew(const _0& arg0)
#endif
{
 void* mem = Allocator::allocateBytes(sizeof(T)
#ifdef NXOGRE_DEBUG
 ,file,line
#endif
 );
 T* ptr = new(mem) T(arg0);
 return ptr;
}

/* Safe way of new'ing a class that doesn't inherit from Allocatable but wants to be managed by the Allocator.
   Note: Only classes that don't inherit from Allocatable but want to use the allocator for memory, should use this function.
   Remember to use the NXOGRE_NEW_PHYSX2 macro, rather than directly using the function.
*/
#ifdef NXOGRE_DEBUG
#define NXOGRE_NEW_PHYSX2(TYPE, ALLOCATOR, TYPE0, ARG0, TYPE1, ARG1) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0, TYPE1>(ARG0, ARG1, __FILE__, __LINE__)
template<typename T, class Allocator, typename _0, typename _1> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const char* file, unsigned int line)
#else
#define NXOGRE_NEW_PHYSX2(TYPE, ALLOCATOR, TYPE0, ARG0, TYPE1, ARG1) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0, TYPE1>(ARG0, ARG1)
template<typename T, class Allocator, typename _0, typename _1> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1)
#endif
{
 void* mem = Allocator::allocateBytes(sizeof(T)
#ifdef NXOGRE_DEBUG
 ,file,line
#endif
 );
 T* ptr = new(mem) T(arg0, arg1);
 return ptr;
}

/* Safe way of new'ing a class through an Allocator.
   Note: Only classes that don't inherit from Allocatable should use this function.
   Remember to use the NXOGRE_NEW_PHYSX3 macro, rather than directly using the function.
*/
#ifdef NXOGRE_DEBUG
#define NXOGRE_NEW_PHYSX3(TYPE, ALLOCATOR, TYPE0, ARG0, TYPE1, ARG1, TYPE2, ARG2) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0, TYPE1, TYPE2>(ARG0, ARG1, ARG2__FILE__, __LINE__)
template<typename T, class Allocator, typename _0, typename _1, typename _2> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2, const char* file, unsigned int line)
#else
#define NXOGRE_NEW_PHYSX3(TYPE, ALLOCATOR, TYPE0, ARG0, TYPE1, ARG1, TYPE2, ARG2) NxOgreAllocatedNew<TYPE, ALLOCATOR, TYPE0, TYPE1, TYPE2>(ARG0, ARG1, ARG2)
template<typename T, class Allocator, typename _0, typename _1, typename _2> inline T* NxOgreAllocatedNew(const _0& arg0, const _1& arg1, const _2& arg2)
#endif
{
 void* mem = Allocator::allocateBytes(sizeof(T)
#ifdef NXOGRE_DEBUG
 ,file,line
#endif
 );
 T* ptr = new(mem) T(arg0, arg1, arg2);
 return ptr;
}

#ifdef NXOGRE_DEBUG
#define NXOGRE_ALLOCATE(ALLOCATOR, LENGTH) NxOgreAllocate<ALLOCATOR>(LENGTH, __FILE__, __LINE__)
template<typename Allocator> void* NxOgreAllocate(size_t length, const char* file, unsigned int line)
#else
#define NXOGRE_ALLOCATE(ALLOCATOR, LENGTH) NxOgreAllocate<ALLOCATOR>(LENGTH)
template<typename Allocator> void* NxOgreAllocate(size_t length)
#endif
{
 return Allocator::allocateBytes(length
#ifdef NXOGRE_DEBUG
, file, line
#endif
 );
}


template<typename Allocator> void NxOgreDeallocate(void* ptr)
{
 Allocator::deallocateBytes(ptr);
}

#define NXOGRE_DEALLOCATE(ALLOCATOR, PTR) NxOgreDeallocate<ALLOCATOR>(PTR)

template<typename Allocator> void* NxOgreReallocate(void* ptr, size_t newLength)
{
 return Allocator::reallocateBytes(ptr, newLength);
}

#define NXOGRE_REALLOCATE(ALLOCATOR, PTR, NEW_LENGTH) NxOgreReallocate<ALLOCATOR>(PTR, NEW_LENGTH)

inline void NxOgreCopy(void* dest, const void* src, size_t length)
{
 memcpy(dest, src, length);
}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif



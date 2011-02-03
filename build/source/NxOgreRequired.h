/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#ifndef NXOGRE_REQUIRED_H
#define NXOGRE_REQUIRED_H

#include "NxOgreVersion.h"
#include "NxOgreConfiguration.h"

#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <sstream>

// ------------------------------------------------------------------

#define NXOGRE_PLATFORM_WINDOWS 0
#define NXOGRE_PLATFORM_LINUX 1
#define NXOGRE_PLATFORM_APPLE 2

#define NXOGRE_COMPILER_MSVC 0
#define NXOGRE_COMPILER_GCC 1

// ------------------------------------------------------------------

#ifdef _WIN32
  
  #if ( defined (_MSC_VER) )

   #define NXOGRE_FORCE_INLINE __forceinline
   #define NXOGRE_ALIGN_16 1

   #ifdef NXOGRE_IS_LIBRARY
       
       #ifdef NXOGRE_SDK
        #define NXOGRE_CLASS __declspec(dllexport)
        #define NXOGRE_FUNCTION __declspec(dllexport)
       #else
        #define NXOGRE_CLASS __declspec(dllimport)
        #define NXOGRE_FUNCTION __declspec(dllimport)
       #endif
       
   #else
       
       #define NXOGRE_CLASS
       #define NXOGRE_FUNCTION
       
   #endif
   
   #define NXOGRE_ASSERT(COND) assert(COND)
   
#endif

// ------------------------------------------------------------------

#define NXOGRE_GC_THIS __FILE__, __LINE__

#define NXOGRE_GC_FRIEND_DELETE template<class T> friend inline void ::NxOgre::GC::safe_delete(T*,const char*,int);
#define NXOGRE_GC_FRIEND_NEW0 template<class T> friend inline T* ::NxOgre::GC::safe_new0(const char*,int);
#define NXOGRE_GC_FRIEND_NEW1 template<class T, typename A1> friend inline T* ::NxOgre::GC::safe_new1(const A1&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW2 template<class T, typename A1, typename A2> friend inline T* ::NxOgre::GC::safe_new2(const A1&,const A2&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW3 template<class T, typename A1, typename A2, typename A3> friend inline T* ::NxOgre::GC::safe_new3(const A1&,const A2&,const A3&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW4 template<class T, typename A1, typename A2, typename A3, typename A4> friend inline T* ::NxOgre::GC::safe_new4(const A1&,const A2&,const A3&,const A4&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW5 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5> friend inline T* ::NxOgre::GC::safe_new5(const A1&,const A2&,const A3&,const A4&,const A5&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW6 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> friend inline T* ::NxOgre::GC::safe_new6(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW7 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> friend inline T* ::NxOgre::GC::safe_new7(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const char*,int);
#define NXOGRE_GC_FRIEND_NEW8 template<class T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> friend inline T* ::NxOgre::GC::safe_new8(const A1&,const A2&,const A3&,const A4&,const A5&,const A6&,const A7&,const A8&,const char*,int);

// ---------------------------------------------------------------
namespace NxOgre
{
namespace GC
{

#if NXOGRE_DEBUG_MEMORY == 1
 void NXOGRE_FUNCTION gc_debugger_push_ptr(void* ptr, unsigned int size, const char* type, const char* file, unsigned int line);
 void NXOGRE_FUNCTION gc_debugger_change_ptr(void* old_ptr, void* new_ptr, unsigned int new_size, const char* file, unsigned int line);
 void NXOGRE_FUNCTION gc_debugger_pop_ptr(void* ptr, const char* file, unsigned int line);
 void NXOGRE_FUNCTION gc_debugger_first_frame();
 void NXOGRE_FUNCTION gc_debugger_frame(unsigned int id, float time);
 void NXOGRE_FUNCTION gc_debugger_last_frame();
#endif

 template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* file, unsigned line)
 {
  T* mem = (T*) AX::allocatebytes(bytes);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(mem, bytes, type2id<T>::type_name(), file, line);
#endif
  return mem;
 }

 template<typename T, typename AX> inline T* safe_malloc(size_t bytes, const char* type, const char* file, unsigned line)
 {
  T* mem = (T*) AX::allocatebytes(bytes);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(mem, bytes, type, file, line);
#endif
  return mem;
 }

 template<typename T, typename AX> inline T* safe_realloc(T* mem, size_t new_size, const char* file, unsigned line)
 {
  T* new_mem = (T*) AX::reallocatebytes(mem, new_size);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_change_ptr(mem, new_mem, new_size, file, line);
#endif
  return new_mem;
 }

 template<typename T, typename AX> inline void safe_free(T* mem, const char* file, unsigned line)
 {
  if (mem == 0)
   return;
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_pop_ptr(mem, file, line);
#endif
  AX::deallocatebytes(mem);
 }

 template<typename T> inline T* safe_new0(const char* file, int line)
 {
  T* ptr = new T();
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX> inline T* safe_allocated_new0(const char* file, int line)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T();
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1> inline T* safe_new1(const A1& v1, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1> inline T* safe_allocated_new1(const A1& v1, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2> inline T* safe_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2> inline T* safe_allocated_new2(const A1& v1, const A2& v2, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3> inline T* safe_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3> inline T* safe_allocated_new3(const A1& v1, const A2& v2, const A3& v3, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3, typename A4> inline T* safe_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3, v4);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4> inline T* safe_allocated_new4(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3, v4);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3, v4, v5);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5> inline T* safe_allocated_new5(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3, v4, v5);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3, v4, v5, v6);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> inline T* safe_allocated_new6(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3, v4, v5, v6, v7);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> inline T* safe_allocated_new7(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> inline T* safe_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
 {
  T* ptr = new T(v1, v2, v3, v4, v5, v6, v7, v8);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T, typename AX, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> inline T* safe_allocated_new8(const A1& v1, const A2& v2, const A3& v3, const A4& v4, const A5& v5, const A6& v6, const A7& v7, const A8& v8, const char* file = 0, int line = 0)
 {
  void* mem = AX::allocatebytes(sizeof(T));
  T* ptr = new(mem) T(v1, v2, v3, v4, v5, v6, v7, v8);
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_push_ptr(ptr, sizeof(T), type2id<T>::type_name(), file, line);
#endif
  return ptr;
 };

 template<typename T> void inline safe_delete(T* ptr, const char* file, int line)
 {
  if (ptr == 0)
   return;
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_pop_ptr(ptr, file, line);
#endif
  delete ptr;
 }

 template<typename T, typename AX> void inline safe_allocated_delete(T* ptr, const char* file, int line)
 {
  if (ptr == 0)
   return;
  ptr->~T();
#if NXOGRE_DEBUG_MEMORY == 1
  gc_debugger_pop_ptr(ptr, file, line);
#endif
  AX::deallocatebytes(ptr);
 }

 class NoGarbageCollection
 {
 public:

  // map<K,T>, multimap<K,T>, hashmap<K,T>
  template<typename K, typename T> class impl_map
  {
  public:
   inline void gc_free(T&) {}
   template<typename it> inline void gc_free_range(it first, it last) {}
  };

  // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
  template<typename K, typename T> class impl_map<K,T*>
  {
  public:
   inline void gc_free(T*) {}
   template<typename it> inline void gc_free_range(it first, it last) {}
  };

  // vector<T>
  template<typename T> class impl_vector
  {
  protected:

   inline void gc_free(T&) {}
   template<typename it> inline void gc_free_range(it first, it last) {}
  };

  // vector<T*>
  template<typename T> class impl_vector<T*>
  {
  protected:

   inline void gc_free(T*) {}
   template<typename it> inline void gc_free_range(it first, it last) {}
  };

 };

 class HasGarbageCollection
 {
 public:

  // map<K,T>, multimap<K,T>, hashmap<K,T>
  template<typename K, typename T> class impl_map
  {
  public:
   inline void gc_free(T& ref) {ref.~T();}
   template<typename it> inline void gc_free_range(it first, it last)
   {
    while(first != last)
    {
     (*first).second.~T();
     first++;
    }
   }
  };

  // map<K,T*>, multimap<K,T*>, hashmap<K,T*>
  template<typename K, typename T> class impl_map<K,T*>
  {
  public:
   inline void gc_free(T* ptr) {safe_delete(ptr, NXOGRE_GC_THIS);}
   template<typename it> inline void gc_free_range(it first, it last)
   {
    while(first != last)
    {
     //delete (*first).second;
     safe_delete((*first).second, NXOGRE_GC_THIS);
     first++;
    }
   }
  };

  // vector<T>
  template<typename T> class impl_vector
  {
  protected:

   inline void gc_free(T& ref) {ref.~T();}
   template<typename it> inline void gc_free_range(it first, it last)
   {
    while(first != last)
    {
     (*first).~T();
     first++;
    }
   }
  };

  // vector<T*>
  template<typename T> class impl_vector<T*>
  {
  protected:

   inline void gc_free(T* ptr) {safe_delete<T>(ptr, NXOGRE_GC_THIS);}
   template<typename it> inline void gc_free_range(it first, it last)
   {
    while(first != last)
    {
     safe_delete<T>((*first), NXOGRE_GC_THIS);
     first++;
    }
   }
  };

 };


} // namespace NxOgre::GC

} // namespace NxOgre


// ---------------------------------------------------------------

namespace NxOgre
{
class AllocatedClass
{
  
 public:
  
  enum AllocatedType
  {
   AT_Unallocated        =0x00,
   AT_Generic            =0x01,
   AT_FrequentOperations =0x02,
   AT_PhysX              =0x03,
   AT_BigClass           =0x04,
   AT_Resource           =0x05,
   AT_Shape              =0x06,
   AT_RigidBody          =0x07,
   AT_Cloth              =0x08,
   AT_Joint              =0x09,
   AT_ForceField         =0x0A,
   AT_Fluid              =0x0B,
   AT_FourBytes          =0x0C,
   AT_STL                =0x0D,
   AT_UserExtended       =0x0E,
   AT_UserBigClass       =0x0F
  };
  
  template<int alloc_type = AT_Unallocated> class Allocatable
  {
    
   public:
    
    enum
    {
     ALLOCATED_CLASS_TYPE = alloc_type
    };
    
    void* operator new(size_t length)
    {
     return GC::safe_malloc(length, NXOGRE_GC_THIS);
    }
    
    void* operator new[](size_t length)
    {
     return GC::safe_malloc(length, NXOGRE_GC_THIS);
    }
    
    void operator delete(void* ptr)
    {
     GC::safe_free(ptr, NXOGRE_GC_THIS);
    }
    
    void operator delete[](void* ptr)
    {
     GC::safe_free(ptr, NXOGRE_GC_THIS);
    }
    
  };
  
  typedef Allocatable<AT_Unallocated>        Unallocated;
  typedef Allocatable<AT_Generic>            Generic;
  typedef Allocatable<AT_FrequentOperations> FrequentOperations;
  typedef Allocatable<AT_PhysX>              PhysX;
  typedef Allocatable<AT_BigClass>           BigClass;
  typedef Allocatable<AT_Resource>           Resource;
  typedef Allocatable<AT_Shape>              Shape;
  typedef Allocatable<AT_RigidBody>          RigidBody;
  typedef Allocatable<AT_Cloth>              Cloth;
  typedef Allocatable<AT_Joint>              Joint;
  typedef Allocatable<AT_ForceField>         ForceField;
  typedef Allocatable<AT_Fluid >             Fluid;
  typedef Allocatable<AT_FourBytes>          FourBytes;
  typedef Allocatable<AT_STL>                STL;
  typedef Allocatable<AT_UserExtended>       UserExtended;
  typedef Allocatable<AT_UserBigClass>       UserBigClass;
  
}; // AllocatedClass
} // namespace NxOgre

// ---------------------------------------------------------------


#ifdef NXOGRE_USES_DOUBLE_PRECISION

#define NXOGRE_REAL_EPSILON DBL_EPSILON
#define NXOGRE_REAL_MAX DBL_MAX
#define NXOGRE_REAL_MIN DBL_MIN

namespace NxOgre
{
 typedef double Real;
}

#else

#define NXOGRE_REAL_EPSILON FLT_EPSILON
#define NXOGRE_REAL_MAX FLT_MAX
#define NXOGRE_REAL_MIN FLT_MIN

namespace NxOgre
{
 typedef float Real;
}
#endif


// -------------------------------------------------

namespace NxOgre
{
 typedef unsigned int uint;
 typedef unsigned short ushort;
 typedef unsigned char uchar;
 typedef char byte;
}

// -------------------------------------------------

namespace NxOgre
{

 class NXOGRE_CLASS Math
 {
 public:

  static const Real TWO_PI;
  static const Real PI;
  static const Real HALF_PI;
  static const Real RADIANS_PER_DEGREE;
  static const Real DEGREES_PER_RADIAN;

  NXOGRE_FORCE_INLINE static Real abs(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::fabs(v);
#else
   return ::fabsf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static bool nearlyZero(Real v)
  {
   return abs(v) < NXOGRE_REAL_EPSILON;
  }

  NXOGRE_FORCE_INLINE static Real lerp(const Real& a, const Real& b, const Real& t)
  {
   return a + (b - a) * t;
  }

  NXOGRE_FORCE_INLINE static Real min(const Real& a, const Real& b)
  {
   return a < b ? a : b;
  }

  NXOGRE_FORCE_INLINE static Real max(const Real& a, const Real& b)
  {
   return a > b ? a : b;
  }

  NXOGRE_FORCE_INLINE static void clampUpper(Real& a, const Real& b)
  {
   if (a < b)
    a = b;
  }

  NXOGRE_FORCE_INLINE static void clampLower(Real& a, const Real& b)
  {
   if (a > b)
    a = b;
  }

  NXOGRE_FORCE_INLINE static void clamp(Real& v, const Real& lb, const Real& ub)
  {
   if (v < lb)
    v = lb;
   if (v > ub)
    v = ub;
  }

  NXOGRE_FORCE_INLINE static Real radians(Real v)
  {
   return v * RADIANS_PER_DEGREE;
  }

  NXOGRE_FORCE_INLINE static Real degrees(Real v)
  {
   return v * DEGREES_PER_RADIAN;
  }

  NXOGRE_FORCE_INLINE static Real sqrt(Real v)
  {
   return ::sqrt(v);
  }

  NXOGRE_FORCE_INLINE static Real square(Real v)
  {
   return v * v;
  }

  NXOGRE_FORCE_INLINE static Real cos(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::cos(v);
#else
   return ::cosf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real sin(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::sin(v);
#else
   return ::sinf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real tan(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::tan(v);
#else
   return ::tanf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real acos(Real v)
  {
   if (v < Real(-1))
    v = Real(-1);
   if (v > Real(-1))
    v = Real(1);
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::acos(v);
#else
   return ::acosf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real asin(Real v)
  {
   if (v < Real(-1))
    v = Real(-1);
   if (v > Real(-1))
    v = Real(1);
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::asin(v);
#else
   return ::asinf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real atan(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::atan(v);
#else
   return ::atanf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real atan2(Real x, Real y)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::atan2(x, y);
#else
   return ::atan2f(x, y);
#endif
  }

  NXOGRE_FORCE_INLINE static Real exp(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::exp(v);
#else
   return ::expf(v);
#endif
  }

  NXOGRE_FORCE_INLINE static Real log(Real v)
  {
#ifdef NXOGRE_USES_DOUBLE_PRECISION
   return ::log(v);
#else
   return ::logf(v);
#endif
  }


 }; // class Math


 // ---------------------------------------------------------------


 class NXOGRE_CLASS Util
 {

 public:

  template<typename T> NXOGRE_FORCE_INLINE static void swap(T& a, T& b)
  {
   T t = a;
   a = b;
   b = t;
  }

  template<typename T> NXOGRE_FORCE_INLINE static bool copy(T* first, T* last, T* dest)
  {
   if (first == 0 || last == 0 || dest == 0)
    return false;
   for (; first != last; ++dest, ++first)
    *dest = *first;
   return true;
  }

  template<typename T> NXOGRE_FORCE_INLINE static bool isNull(T* ptr)
  {
   return ptr == 0;
  }

 }; // class Util

} // namespace NxOgre

 // ---------------------------------------------------------------
 
namespace NxOgre
{
 
 typedef std::string String;
 
 
} // namespace NxOgre


 // ---------------------------------------------------------------
 
namespace NxOgre
{
namespace Enums
{

 // ---------------------------------------------------------------

 /*! enum. PhysXAssertionResponse
     desc.
          What do when there is an assertion from PhysX
     enums.
          PhysXAssertion_Continue -- Continue
          PhysXAssertion_Ignore -- Ignore
          PhysXAssertion_Breakpoint -- Breakpoint
          PhysXAssertion_Exception -- Throw a detailed STL exception
 */
 enum PhysXAssertionResponse
 {
  PhysXAssertion_Continue,
  PhysXAssertion_Ignore,
  PhysXAssertion_Breakpoint,
  PhysXAssertion_Exception,
 };

 // ---------------------------------------------------------------

} // namespace NxOgre::Enums
} // namespace NxOgre

 // ---------------------------------------------------------------


#endif



#endif

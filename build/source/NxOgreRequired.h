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


// ------------------------------------------------------------------

#define NXOGRE_PLATFORM_WINDOWS 0
#define NXOGRE_PLATFORM_LINUX 1
#define NXOGRE_PLATFORM_APPLE 2

#define NXOGRE_COMPILER_MSVC 0
#define NXOGRE_COMPILER_GCC 1

// ------------------------------------------------------------------

#ifdef _WIN32
  
  #include <math.h>
  #include <stdlib.h>
  #include <float.h>
  #include <assert.h>
  #include <string.h>
  #include <string>
  #include <sstream>
  #include <iostream>
  #include <map>
  #include <vector>
  
  #define NXOGRE_PLATFORM NXOGRE_PLATFORM_WINDOWS

  #if ( defined (_MSC_VER) )
   
   #define NXOGRE_COMPILER NXOGRE_COMPILER_MSVC

   // Remove Warning: "class 'std::map<_Kty,_Ty>' needs to have dll-interface to be used by clients of class"
   #pragma warning(disable: 4251)

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
   #define NXOGRE_UNUSED(X) (void) X
   #define NXOGRE_NULL_POINTER NULL

   namespace NxOgre
   {
   namespace GC
   {
     
     // ------------------------------------------------------------------
     
#if NXOGRE_DEBUG_MEMORY >= 1
     
     class NXOGRE_CLASS WindowsMemoryTracker
     {
       
       public:
        
        static WindowsMemoryTracker Tracker;
        
#if NXOGRE_DEBUG_MEMORY == 1
        NXOGRE_FORCE_INLINE void push_memory(void* memory)
        {
         mAllocations++;
        }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
        NXOGRE_FORCE_INLINE void push_memory(void* memory, size_t length, const char* file, size_t line)
        {
         Allocation allocation;
         allocation.file_pushed = hash(file);
         allocation.line_pushed = line;
         allocation.size = length;
         
         if (allocation.file_pushed != 0)
         {
          mStringsIterator = mStrings.find(allocation.file_pushed);
          if (mStringsIterator == mStrings.end())
          {
           mStrings.insert(std::pair<size_t, std::string>(allocation.file_pushed, std::string(file)));
          }
         }
         
         mCurrentAllocations.insert(std::pair<void*, Allocation>(memory, allocation));
         
         #if NXOGRE_DEBUG_MEMORY == 3
           mAllAllocations.insert(std::pair<void*, Allocation>(memory, allocation));
         #endif
        }
#endif

#if NXOGRE_DEBUG_MEMORY == 1
        NXOGRE_FORCE_INLINE void push_memory(void* memory)
        {
         mAllocations--;
        }
#endif


#if NXOGRE_DEBUG_MEMORY >= 2
        NXOGRE_FORCE_INLINE void pop_memory(void* memory, const char* file, size_t line)
        {
         mCurrentAllocationsIterator = mCurrentAllocations.find(memory);
         if (mCurrentAllocationsIterator == mCurrentAllocations.end())
         {
          mCurrentAllocations.erase(mCurrentAllocationsIterator);
         }
         
#if NXOGRE_DEBUG_MEMORY == 3
         mAllAllocationsIterator = mAllAllocations.find(memory);
         if (mAllAllocationsIterator == mAllAllocations.end())
         {
          (*mAllAllocationsIterator).second.file_popped = hash(file);
          (*mAllAllocationsIterator).second.line_popped = 0;

          if ((*mAllAllocationsIterator).second.file_popped != 0)
          {
           mStringsIterator = mStrings.find( (*mAllAllocationsIterator).second.file_popped );
           if (mStringsIterator == mStrings.end())
           {
            mStrings.insert(std::pair<size_t, std::string>((*mAllAllocationsIterator).second.file_popped, std::string(file)));
           }
          }
         }
#endif
        
        }
#endif
       
       protected:
        
#if NXOGRE_DEBUG_MEMORY == 1
        size_t mAllocations;
#elif NXOGRE_DEBUG_MEMORY >= 2
        
        NXOGRE_FORCE_INLINE size_t hash(const char* str)
        {
         size_t len = strlen(str);
         if (len == 0)
          return 0;
         size_t ret = 2166136261U;
         for (size_t i=0;i < len;i++)
          ret = 16777619 * ret ^ (size_t) * &str[i];
         return ret;
        }
        
        std::map<size_t, std::string>                  mStrings;
        std::map<size_t, std::string>::const_iterator  mStringsIterator;
        
        struct Allocation
        {
         size_t file_pushed, file_popped;
         size_t line_pushed, line_popped;
         size_t size;
        };

        std::map<void*, Allocation>            mCurrentAllocations;
        std::map<void*, Allocation>::iterator  mCurrentAllocationsIterator;
#endif

#if NXOGRE_DEBUG_MEMORY == 3
        std::map<void*, Allocation>                mAllAllocations;
        std::map<void*, Allocation>::iterator      mAllAllocationsIterator;
#endif

     };

     typedef WindowsMemoryTracker MemoryTracker;

#endif

     // ------------------------------------------------------------------
     
     class NXOGRE_CLASS WindowsMemoryAllocator
     {
       
#if NXOGRE_DEBUG_MEMORY >= 2
       friend void* safe_malloc(size_t,const char*,size_t);
       friend void  safe_free(void*,const char*,size_t);
       friend void* safe_realloc(void* ptr, size_t length, const char* file, size_t line);
#else
       friend void* safe_malloc(size_t);
       friend void  safe_free(void*);
       friend void* safe_realloc(void* ptr, size_t length);
#endif
      protected:
       
       // ------------------------------------------------------------------
       
       static WindowsMemoryAllocator Allocator;
       
       // ------------------------------------------------------------------
       
       WindowsMemoryAllocator()
       {
       }
       
       // ------------------------------------------------------------------
       
       ~WindowsMemoryAllocator()
       {
       }
       
       // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
       NXOGRE_FORCE_INLINE void* allocateMemory(size_t length, const char* file, size_t line)
       {
        void* ptr = malloc(length);
        WindowsMemoryTracker::Tracker.push_memory(ptr, length, file, line);
        return ptr;
       }
#else
       NXOGRE_FORCE_INLINE void* allocateMemory(size_t length)
       {
       return malloc(length)
       }
#endif
       
       // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
       NXOGRE_FORCE_INLINE void* reallocateMemory(void* ptr, size_t length, const char* file, size_t line)
       {
        void* new_ptr = realloc(ptr, length);
        WindowsMemoryTracker::Tracker.pop_memory(ptr, file, line);
        WindowsMemoryTracker::Tracker.push_memory(new_ptr, length, file, line);
        return new_ptr;
       }
#else
       NXOGRE_FORCE_INLINE void* reallocateMemory(void* ptr, size_t length)
       {
       return realloc(ptr, length);
       }
#endif
       
       // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
       NXOGRE_FORCE_INLINE void freeMemory(void* ptr, const char* file, size_t line)
       {
        WindowsMemoryTracker::Tracker.pop_memory(ptr, file, line);
        free(ptr);
       }
#else
       NXOGRE_FORCE_INLINE void freeMemory(void* ptr)
       {
        free(ptr);
       }
#endif

     }; // WindowsMemoryAllocator
     
     typedef WindowsMemoryAllocator MemoryAllocator;

     // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
#define NXOGRE_MALLOC(LENGTH) ::NxOgre::GC::safe_malloc(LENGTH, __FILE__, __LINE__)
#define NXOGRE_REALLOC(PTR, LENGTH) ::NxOgre::GC::safe_realloc(PTR, LENGTH, __FILE__, __LINE__)
#define NXOGRE_FREE(PTR) ::NxOgre::GC::safe_free(PTR, __FILE__, __LINE__)
#else
#define NXOGRE_MALLOC(LENGTH) ::NxOgre::GC::safe_malloc(LENGTH)
#define NXOGRE_REALLOC(PTR, LENGTH) ::NxOgre::GC::safe_realloc(PTR, LENGTH)
#define NXOGRE_FREE(PTR) ::NxOgre::GC::safe_free(PTR)
#endif

     // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void* safe_malloc(size_t length, const char* file, size_t line)
     {
      return MemoryAllocator::Allocator.allocateMemory(length, file, line);
     }
#else
     NXOGRE_FORCE_INLINE void* safe_malloc(size_t length)
     {
      return MemoryAllocator::Allocator.allocateMemory(length);
     }
#endif
     
     // ------------------------------------------------------------------
     
#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void* safe_realloc(void* ptr, size_t length, const char* file, size_t line)
     {
      return MemoryAllocator::Allocator.reallocateMemory(ptr, length, file, line);
     }
#else
     NXOGRE_FORCE_INLINE void* safe_realloc(void* ptr, size_t length)
     {
      return MemoryAllocator::Allocator.reallocateMemory(ptr, length);
     }
#endif
     
     // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void safe_free(void* ptr, const char* file, size_t line)
     {
      if (ptr != NXOGRE_NULL_POINTER)
      {
       MemoryAllocator::Allocator.freeMemory(ptr, file, line);
      }
     }
#else
     NXOGRE_FORCE_INLINE void safe_free(void* ptr)
     {
      if (ptr != NXOGRE_NULL_POINTER)
      {
       MemoryAllocator::Allocator.freeMemory(ptr);
      }
     }
#endif
     
     // ------------------------------------------------------------------
     
   } // namespace NxOgre::GC
   } // namespace NxOgre

#endif  // WIN32

// ---------------------------------------------------------------

namespace NxOgre
{
namespace GC
{
 
 
} // namespace NxOgre::GC
} // namespace NxOgre

// ---------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
#define NXOGRE_NEW new(__FILE__, __LINE__) 
#define NXOGRE_DELETE(PTR) operator delete(PTR, __FILE__, __LINE__); PTR = 0;
#else
#define NXOGRE_NEW new
#define NXOGRE_DELETE(PTR) delete PTR; PTR = 0;
#endif

namespace NxOgre
{
class NXOGRE_CLASS AllocatedClass
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
    
#if NXOGRE_DEBUG_MEMORY >= 2
    void* operator new(size_t length, const char* file, size_t line)
    {
     return GC::safe_malloc(length, file, line);
    }
#else
    void* operator new(size_t length)
    {
     return GC::safe_malloc(length);
    }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
    void* operator new[](size_t length, const char* file, size_t line)
    {
     return GC::safe_malloc(length, file, line);
    }
#else
    void* operator new[](size_t length)
    {
     return GC::safe_malloc(length);
    }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
    void operator delete(void* ptr, const char* file, size_t line)
    {
     GC::safe_free(ptr, file, line);
    }
#else
    void operator delete(void* ptr)
    {
     GC::safe_free(ptr);
    }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
    void operator delete[](void* ptr, const char* file, size_t line)
    {
     GC::safe_free(ptr, file, line);
    }
#else
    void operator delete[](void* ptr)
    {
     GC::safe_free(ptr);
    }
#endif
  
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

  // ---------------------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE static void swap(T& a, T& b)
  {
   T t = a;
   a = b;
   b = t;
  }

  // ---------------------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE static bool copy(T* first, T* last, T* dest)
  {
   if (first == 0 || last == 0 || dest == 0)
    return false;
   for (; first != last; ++dest, ++first)
    *dest = *first;
   return true;
  }

  // ---------------------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE static bool isNull(T* ptr)
  {
   return ptr == 0;
  }
  
  // ---------------------------------------------------------------

   struct boolean
   {
     template<typename T> struct less
     {
      bool operator()(const T& a, const T& b)
      {
       return (a < b);
      }
     };

     template<typename T> struct more
     {
      bool operator()(const T& a, const T& b)
      {
       return (a > b);
      }
     };

     template<typename T> struct equals
     {
      bool operator()(const T& a, const T& b)
      {
       return (a == b);
      }
     };

     template<typename T> struct not
     {
      bool operator()(const T& a, const T& b)
      {
       return (a != b);
      }
     };
   };

  // ---------------------------------------------------------------

   template<typename T, typename Comparision = boolean::less<T> > struct sort
   {
    NXOGRE_FORCE_INLINE void operator()(T* begin, T* end)
    {
     std::sort(begin, end, Comparision());
    }
   };

  // ---------------------------------------------------------------

   template<typename T, typename Comparision = boolean::equals<T> > struct unique
   {
    NXOGRE_FORCE_INLINE T* operator()(T* begin, T* end)
    {
     return std::unique(begin, end, Comparision());
    }
   };

  // ---------------------------------------------------------------

   template<typename T, typename Comparision = boolean::equals<T> > struct linear_find
   {
    NXOGRE_FORCE_INLINE T* operator()(T* begin, T* end, const T& search)
    {
     Comparision c;
     while(begin < end)
     {
      if ( c(*begin, search) )
       return begin;
      begin++;
     }
     return end;
    }
   };

  // ---------------------------------------------------------------

 }; // class Util

} // namespace NxOgre

 // ---------------------------------------------------------------
 
namespace NxOgre
{
 
 typedef std::string String;
 
 struct Strings
 {
   
   // ---------------------------------------------------------------
   
   template<typename T> NXOGRE_FORCE_INLINE static void join(std::ostream& s, T* begin, T* end, char delimiter = '\n')
   {
    while(begin < end)
    {
     s << *begin;
     if (begin != end -1)
      s << delimiter;
     begin++;
    }
   }
   
   // ---------------------------------------------------------------
   
 };
 
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

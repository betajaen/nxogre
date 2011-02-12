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
 
 #define NXOGRE_STRINGIFY(STR) NXOGRE_STRINGIFY_IMPL(STR)
 #define NXOGRE_STRINGIFY_IMPL(STR) #STR

#ifdef _WIN32
  #include "NxOgreRequiredWindows.h"
#endif

 namespace NxOgre
 {
 namespace GC
 {

     // ------------------------------------------------------------------

     #if NXOGRE_DEBUG_MEMORY >= 2
          #define NXOGRE_MALLOC(LENGTH) ::NxOgre::GC::safe_malloc(LENGTH, __FILE__, __FUNCTION__, __LINE__)
          #define NXOGRE_REALLOC(PTR, LENGTH) ::NxOgre::GC::safe_realloc(PTR, LENGTH, __FILE__, __FUNCTION__, __LINE__)
          #define NXOGRE_FREE(PTR) ::NxOgre::GC::safe_free(PTR, __FILE__, __FUNCTION__, __LINE__)
     #else
          #define NXOGRE_MALLOC(LENGTH) ::NxOgre::GC::safe_malloc(LENGTH)
          #define NXOGRE_REALLOC(PTR, LENGTH) ::NxOgre::GC::safe_realloc(PTR, LENGTH)
          #define NXOGRE_FREE(PTR) ::NxOgre::GC::safe_free(PTR)
     #endif

     // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void* safe_malloc(size_t length, const char* file, const char* function, size_t line)
     {
      return MemoryAllocator::Allocator.allocateMemory(length, file, function, line);
     }
#else
     NXOGRE_FORCE_INLINE void* safe_malloc(size_t length)
     {
      return MemoryAllocator::Allocator.allocateMemory(length);
     }
#endif
     
     // ------------------------------------------------------------------
     
#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void* safe_realloc(void* ptr, size_t length, const char* file, const char* function, size_t line)
     {
      return MemoryAllocator::Allocator.reallocateMemory(ptr, length, file, function, line);
     }
#else
     NXOGRE_FORCE_INLINE void* safe_realloc(void* ptr, size_t length)
     {
      return MemoryAllocator::Allocator.reallocateMemory(ptr, length);
     }
#endif
     
     // ------------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void safe_free(void* ptr, const char* file, const char* function, size_t line)
     {
      if (ptr != NXOGRE_NULL_POINTER)
      {
       MemoryAllocator::Allocator.freeMemory(ptr, file, function, line);
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

#if NXOGRE_DEBUG_MEMORY >= 2
     NXOGRE_FORCE_INLINE void safe_debug_delete(void* ptr)
     {
       MemoryAllocator::Allocator.freeMemory(ptr, 0, 0, 0);
     }
#endif

     // ------------------------------------------------------------------
     
   } // namespace NxOgre::GC
   } // namespace NxOgre

// ---------------------------------------------------------------

#if NXOGRE_DEBUG_MEMORY >= 2
#define NXOGRE_NEW new(__FILE__, __FUNCTION__,  __LINE__) 
#define NXOGRE_DELETE(PTR) ::NxOgre::GC::MemoryTracker::Tracker.pop_memory(PTR, __FILE__, __FUNCTION__, __LINE__); \
                          delete PTR; PTR = 0;
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
    void* operator new(size_t length, const char* file, const char* function, size_t line)
    {
     return GC::safe_malloc(length, file, function, line);
    }
#else
    void* operator new(size_t length)
    {
     return GC::safe_malloc(length);
    }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
    void* operator new[](size_t length, const char* file, const char* function, size_t line)
    {
     return GC::safe_malloc(length, file, function, line);
    }
#else
    void* operator new[](size_t length)
    {
     return GC::safe_malloc(length);
    }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
    // Required by new
    void operator delete(void* ptr, const char* file, const char* function, size_t line)
    {
     GC::safe_free(ptr, file, function, line);
    }
#endif

    void operator delete(void* ptr)
    {
#if NXOGRE_DEBUG_MEMORY >= 2
     GC::safe_debug_delete(ptr);
#else
     GC::safe_free(ptr);
#endif
    }

#if NXOGRE_DEBUG_MEMORY >= 2
    void operator delete[](void* ptr, const char* file, const char* function, size_t line)
    {
     GC::safe_free(ptr, file, function, line);
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

#if NXOGRE_USE_STLALLOCATOR == 1
    
  // ---------------------------------------------------------------
  
  template<typename T> struct STLAllocatorBase
  {
   typedef T value_type;
  };
    
  // ---------------------------------------------------------------
  
  template<typename T> struct STLAllocatorBase<const T>
  {
   typedef T value_type;
  };
    
  // ---------------------------------------------------------------
  
  template<typename T> class STLAllocator : public STLAllocatorBase<T>
  {
     
   public:
     
     typedef STLAllocatorBase<T> Base;
     typedef typename Base::value_type value_type;
     typedef value_type*               pointer;
     typedef const value_type*         const_pointer;
     typedef value_type&               reference;
     typedef const value_type&         const_reference;
     typedef std::size_t               size_type;
     typedef std::ptrdiff_t            difference_type;
     
     template<typename U> struct rebind
     {
      typedef STLAllocator<U> other;
     };
     
     NXOGRE_FORCE_INLINE explicit STLAllocator()
     {
     }
     
     NXOGRE_FORCE_INLINE virtual ~STLAllocator()
     {
     }
     
     NXOGRE_FORCE_INLINE STLAllocator(STLAllocator const&)
     {
     }
     
     template<typename U> NXOGRE_FORCE_INLINE STLAllocator(STLAllocator<U> const&)
     {
     }
     
     NXOGRE_FORCE_INLINE pointer allocate(size_type count,
                                          typename std::allocator<void>::const_pointer ptr = 0)
     {
      NXOGRE_UNUSED(ptr);
      register size_type sz = count * sizeof(T);
      pointer p = static_cast<pointer>( NXOGRE_MALLOC(sz) );
      return p;
     }
     
     NXOGRE_FORCE_INLINE void deallocate(pointer ptr, size_type)
     {
      NXOGRE_FREE(ptr);
     }
     
     pointer address(reference x) const
     {
      return x;
     }

     const_pointer address(const_reference x) const
     {
      return &x;
     }

     size_type max_size() const throw()
     {
      return std::numeric_limits<size_t>::max();
     }

     void construct(pointer p, const T& val)
     {
      new(static_cast<void*>(p)) T(val);
     }

     void destroy(pointer p)
     {
      p->~T();
     }

  };
  
  // ---------------------------------------------------------------
  
  template<typename T, typename T2>
  NXOGRE_FORCE_INLINE bool operator==(STLAllocator<T> const&, STLAllocator<T2> const&)
  {
   return true;
  }
  
  // ---------------------------------------------------------------
  
  template<typename T, typename OtherAllocator>
  NXOGRE_FORCE_INLINE bool operator==(STLAllocator<T> const&, OtherAllocator const&)
  {
   return false;
  }
  
  // ---------------------------------------------------------------
  
  template<typename T, typename T2>
  NXOGRE_FORCE_INLINE bool operator!=(STLAllocator<T> const&, STLAllocator<T2> const&)
  {
   return false;
  }
  
  // ---------------------------------------------------------------
  
  template<typename T, typename OtherAllocator>
  NXOGRE_FORCE_INLINE bool operator!=(STLAllocator<T> const&, OtherAllocator const&)
  {
   return true;
  }
  
  // ---------------------------------------------------------------
  
#endif
 
}
 
 // ---------------------------------------------------------------
 
 namespace NxOgre
 {
  
#if NXOGRE_USE_STLALLOCATOR == 0
  typedef std::ostringstream OStringStream;
  typedef std::stringstream StringStream;
  typedef std::istringstream IStringStream;
  typedef std::string String;
#else
  typedef std::basic_ostringstream<char, std::char_traits<char>, STLAllocator<char>> OStringStream;
  typedef std::basic_stringstream<char, std::char_traits<char>, STLAllocator<char>> StringStream;
  typedef std::basic_istringstream<char, std::char_traits<char>, STLAllocator<char>> IStringStream;
  typedef std::basic_string<char, std::char_traits<char>, STLAllocator<char> > String;
#endif
  
  template<typename K, typename V> struct map
  {
   
#if NXOGRE_USE_STLALLOCATOR == 0
   typedef std::map<K,V> type;
   typedef typename std::map<K,V>::iterator iterator;
   typedef typename std::map<K,V>::const_iterator const_iterator;
   typedef K key_t;
   typedef V val_t;
#else
   typedef std::map<K,V, std::less<K>, STLAllocator<std::pair<K,V>>> type;
   typedef typename std::map<K,V, std::less<K>, STLAllocator<std::pair<K,V>>>::iterator iterator;
   typedef typename std::map<K,V, std::less<K>, STLAllocator<std::pair<K,V>>>::const_iterator const_iterator;
   typedef K key_t;
   typedef V val_t;
#endif
   
  };
  
  template<typename T> struct vector
  {
   
#if NXOGRE_USE_STLALLOCATOR == 0
   typedef std::vector<T> type;
   typedef typename std::vector<T>::iterator iterator;
   typedef typename std::vector<T>::const_iterator const_iterator;
   typedef T val_t;
#else
   typedef std::vector<T, STLAllocator<T>> type;
   typedef typename std::vector<T, STLAllocator<T>>::iterator iterator;
   typedef typename std::vector<T, STLAllocator<T>>::const_iterator const_iterator;
   typedef T val_t;
#endif
   
  };
  
 
 };

 // ---------------------------------------------------------------
  
namespace NxOgre
{
 
 struct Strings
 {
   
   // ---------------------------------------------------------------
   
   template<typename T> NXOGRE_FORCE_INLINE static void join(StringStream& s, T* begin, T* end, char delimiter = '\n')
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
   
   template<typename T> NXOGRE_FORCE_INLINE static void join(StringStream& s, typename vector<T>::type& vec, char delimiter = '\n')
   {
    return join(s, vec.begin(), vec.end(), delimiter);
   }
   
   // ---------------------------------------------------------------
   
 };
 

} // namespace NxOgre


// ---------------------------------------------------------------

namespace NxOgre
{
 
 class Log
 {
   
  public:
   
   static Log LOG;
   
   void push(const char* message)
   {
#if NXOGRE_LOG_TO_CONSOLE == 1
    Platform::printf("[NxOgre] %s\n", message);
#endif
    
#if NXOGRE_LOG_TO_FILE == 1
    mNow.refresh();
    mLogFile.writef("[%i:%i:%i] %s\n", mNow.hour(), mNow.minute(), mNow.second(), message);
#endif
   }
   
   void push(const String& message)
   {
#if NXOGRE_LOG_TO_CONSOLE == 1
    Platform::printf("[NxOgre] %s\n", message.c_str());
#endif
    
#if NXOGRE_LOG_TO_FILE == 1
    mNow.refresh();
    mLogFile.writef("[%i:%i:%i] %s\n", mNow.hour(), mNow.minute(), mNow.second(), message.c_str());
#endif
   }

   void push(const StringStream& message)
   {
#if NXOGRE_LOG_TO_CONSOLE == 1
    Platform::printf("[NxOgre] %s\n", message.str().c_str());
#endif
    
#if NXOGRE_LOG_TO_FILE == 1
    mNow.refresh();
    mLogFile.writef("[%i:%i:%i] %s\n", mNow.hour(), mNow.minute(), mNow.second(), message.str().c_str());
#endif
   }
   
   Log()
   {
#if NXOGRE_LOG_TO_FILE == 1
    mLogFile.open("NxOgre.log", false, true);
    mLogFile.writef(
    "NxOgre %i.%i.%i '%s/%s' built with %s\n\n[%i:%i:%i] ** Log Started\n",
     NxOgreVersionMajor, NxOgreVersionMinor, NxOgreVersionBuild, NxOgreBranchName, NxOgreBuildName, NXOGRE_COMPILER_STRING,
     mNow.hour(), mNow.minute(), mNow.second());
#endif
   }
   
  ~Log()
   {
#if NXOGRE_LOG_TO_FILE == 1
    mLogFile.writef("[%i:%i:%i] ** Log Stopped\n", mNow.hour(), mNow.minute(), mNow.second());
    mLogFile.close();
#endif
   }
   
  protected:
   
#if NXOGRE_LOG_TO_FILE == 1
   Platform::File  mLogFile;
   Platform::Time  mNow;
#endif
   
 };


#if NXOGRE_LOG_TO_FILE == 0 && NXOGRE_LOG_TO_CONSOLE == 0
 #define NXOGRE_LOG_MESSAGE(MESSAGE)
 #define NXOGRE_LOG_LONG_MESSAGE_BEGIN if (0) {
 #define NXOGRE_LOG_LONG_MESSAGE_END(MESSAGE) }
#else
 #define NXOGRE_LOG_MESSAGE(MESSAGE) Log::LOG.push(MESSAGE);
 #define NXOGRE_LOG_LONG_MESSAGE_BEGIN {
 #define NXOGRE_LOG_LONG_MESSAGE_END(MESSAGE) Log::LOG.push(MESSAGE); }
#endif

} // namespace NxOgre

// ---------------------------------------------------------------

namespace NxOgre
{
    
    class Exception : public std::exception
    {
      
     public:
      
      NXOGRE_FORCE_INLINE Exception(const char* message, const char* file, const char* function, size_t line)
      : mMessage(message), mFile(file), mFunction(function), mLine(line)
      {
       String s = to_s();
       #if NXOGRE_LOG_TO_FILE == 0 && NXOGRE_LOG_TO_CONSOLE == 0
         Platform::printf(s.c_str());
       #else
         NXOGRE_LOG_MESSAGE(s);
       #endif
      }

      NXOGRE_FORCE_INLINE ~Exception() throw()
      {
      }

      void operator=(const Exception& other)
      {
       mMessage = other.mMessage;
       mFile = other.mFile;
       mFunction = other.mFunction;
       mLine = other.mLine;
      }
      
      String to_s()
      {
       StringStream s;
       s << getName() << " Thrown!\n\n" << mMessage << "\nThrown by " << mFunction << " in " << mFile << "(" << mLine << ")\n";
       return s.str();
      }

      virtual const char* getName() const { return "Exception"; }

     protected:
      
      std::string  mMessage, mFile, mFunction;
      size_t       mLine;
    };

    class BadStateException : public Exception
    {
     public:
      BadStateException(const char* message, const char* file, const char* function, size_t line)
      : Exception(message, file, function, line) {}
      const char* getName() const { return "BadStateException"; }
    };
    
    class PhysXException : public Exception
    {
     public:
      PhysXException(const char* message, const char* file, const char* function, size_t line)
      : Exception(message, file, function, line) {}
      const char* getName() const { return "PhysXException"; }
    };
    
    class BadDescriptionException : public Exception
    {
     public:
      BadDescriptionException(const char* message, const char* file, const char* function, size_t line)
      : Exception(message, file, function, line) {}
      const char* getName() const { return "BadDescriptionException"; }
    };
    
   void throw_assert_message(const char* s, const char* file, const char* function, int line);
   
   void throw_assert_message(const StringStream& s, const char* file, const char* function, int line);

   #if NXOGRE_USES_ASSERT == 0
     #define NXOGRE_THROW_EXCEPTION(EXCEPTION_TYPE, MESSAGE)                       \
      throw EXCEPTION_TYPE(MESSAGE, __FILE__, __FUNCTION__, __LINE__);      
   #else
     #define NXOGRE_THROW_EXCEPTION(EXCEPTION_TYPE, MESSAGE)                       \
      ::NxOgre::throw_assert_message(MESSAGE, __FILE__, __FUNCTION__, __LINE__);  \
      assert(0);                                                                   
   #endif

} // namespace NxOgre

// ---------------------------------------------------------------

namespace NxOgre
{
 
 namespace Enums
 {
  
   /*! enum. FrameType
       desc.
           Type of frame.
       enums.
           FrameType_Simulate -- Simulation frame. Physics state will be updated in this frame.
           FrameType_Interpolation -- Render frame, interpolate position. Physics state won't be updated in this frame.
           FrameType_Extrapolation -- Render frame, extrapolation position. Physics state is currently lost/out of sync.
   */
   enum FrameType
   {
    FrameType_Simulate,
    FrameType_Interpolation,
    FrameType_Extrapolation
   };
 };

 struct TimeStep
 {
   
   friend class SceneIntegrator;
   
   NXOGRE_FORCE_INLINE TimeStep()
   {
   }
   
   NXOGRE_FORCE_INLINE Real getInterpolationAlpha() const
   {
    return mAlpha;
   }
   
   NXOGRE_FORCE_INLINE Real getDeltaTime() const
   {
    return mDeltaTimeSeconds;
   }
   
   NXOGRE_FORCE_INLINE unsigned long getDeltaTimeMilliseconds() const
   {
    return mDeltaTimeMilliseconds;
   }

   NXOGRE_FORCE_INLINE Enums::FrameType getFrameType() const
   {
    return mFrameType;
   }
   
  protected:
   
   Real              mDeltaTimeSeconds, mAlpha;
   unsigned long     mDeltaTimeMilliseconds;
   Enums::FrameType  mFrameType;
   
 };
 
} // namespace NxOgre

// ---------------------------------------------------------------

#endif

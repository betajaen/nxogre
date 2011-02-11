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

#ifndef NXOGRE_REQUIRED_WINDOWS_H
#define NXOGRE_REQUIRED_WINDOWS_H

#include "NxOgreConfiguration.h"
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
#include <cstdarg>

#define NXOGRE_PLATFORM_WINDOWS 0
#define NXOGRE_COMPILER_MSVC 0

  #define NXOGRE_PLATFORM NXOGRE_PLATFORM_WINDOWS

  #if ( defined (_MSC_VER) )
   
   // Remove Warning: "class 'std::map<_Kty,_Ty>' needs to have dll-interface to be used by clients of class"
   #pragma warning(disable: 4251)
   
   // ------------------------------------------------------------------
   
   #define NXOGRE_COMPILER NXOGRE_COMPILER_MSVC

   // ------------------------------------------------------------------
   
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

   // ------------------------------------------------------------------
   
   #define NXOGRE_FORCE_INLINE __forceinline
   #define NXOGRE_ASSERT(COND) assert(COND)
   #define NXOGRE_UNUSED(X) (void) X
   #define NXOGRE_NULL_POINTER NULL
   
   // ------------------------------------------------------------------
   
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
   
   // ------------------------------------------------------------------

   namespace NxOgre
   {
    class Exception : public std::exception
    {
      
     public:
      
      NXOGRE_FORCE_INLINE Exception(const char* message, const char* file, size_t line)
      : mMessage(message), mFile(file), mLine(line)
      {
      }

      NXOGRE_FORCE_INLINE ~Exception() throw()
      {
      }

      void operator=(const Exception& other)
      {
      }
      
     protected:
      
      std::string  mMessage, mFile;
      size_t       mLine;
    };

    class BadStateException : public Exception
    {
     public:
      BadStateException(const char* message, const char* file, size_t line)
      : Exception(message, file, line) {}
    };

    class PhysXException : public Exception
    {
     public:
      PhysXException(const char* message, const char* file, size_t line)
      : Exception(message, file, line) {}
    };


   }



   #if NXOGRE_USES_ASSERT == 0
     #define NXOGRE_THROW_EXCEPTION(EXCEPTION_TYPE, STRING_MESSAGE)                                      \
     ::NxOgre::Platform::printf("\nException thrown!\n" STRING_MESSAGE "\n%s:%d\n", __FILE__, __LINE__); \
      throw EXCEPTION_TYPE(STRING_MESSAGE, __FILE__, __LINE__);                                          
   #else
     #define NXOGRE_THROW_EXCEPTION(EXCEPTION_TYPE, STRING_MESSAGE)   \
     ::NxOgre::Platform::printf("\nAssertion!\n" STRING_MESSAGE "\n%s:%d\n", __FILE__, __LINE__);       \
     assert(0);                                                                                          
   #endif

   // ------------------------------------------------------------------
   
   namespace NxOgre
   {
    namespace Platform
    {
     
     NXOGRE_FORCE_INLINE static void printf(const char* format, ...)
     {
      va_list args;
      va_start(args, format);
      ::printf(format, args);
      va_end(args);
     }
     
     struct File
     {
      
      NXOGRE_FORCE_INLINE File()
      : fp(0)
      {
      }
      
      NXOGRE_FORCE_INLINE File(const char* path, bool read = true, bool write = false)
      : fp(NXOGRE_NULL_POINTER)
      {
       open(path, read, write);
      }

      NXOGRE_FORCE_INLINE ~File()
      {
       close();
      }

      NXOGRE_FORCE_INLINE void open(const char* path, bool read, bool write)
      {
       close();
       if (read == true && write == false)
        fopen_s(&fp, path, "r");
       else if (read == false && write == true)
        fopen_s(&fp, path, "w");
       else if (read == true && write == true)
        fopen_s(&fp, path, "w+");
      }

      NXOGRE_FORCE_INLINE void close()
      {
       if (fp)
       {
        fclose(fp);
        fp = 0;
       }
      }

      NXOGRE_FORCE_INLINE bool eof() const
      {
       return feof(fp) == 0;
      }

      NXOGRE_FORCE_INLINE bool hasError() const
      {
       return ferror(fp) == 0;
      }
      
      NXOGRE_FORCE_INLINE void flush()
      {
       fflush(fp);
      }

      NXOGRE_FORCE_INLINE void seek(size_t length)
      {
       fseek(fp, length, SEEK_SET);
      }
      
      NXOGRE_FORCE_INLINE void skip(size_t length)
      {
       fseek(fp, length, SEEK_CUR);
      }

      NXOGRE_FORCE_INLINE void seekEnd(size_t length)
      {
       fseek(fp, length, SEEK_END);
      }

      NXOGRE_FORCE_INLINE size_t position() const
      {
       return ftell(fp);
      }

      NXOGRE_FORCE_INLINE size_t read(void* ptr, size_t size, size_t count = 1) const
      {
       return fread(ptr, size, count, fp);
      }
      
      NXOGRE_FORCE_INLINE bool read(char& c, size_t size, size_t count = 1) const
      {
       c = fgetc(fp);
       return c != EOF;
      }

      NXOGRE_FORCE_INLINE bool write(void* ptr, size_t size, size_t count = 1)
      {
       return fwrite(ptr, size, count, fp) == count;
      }

      NXOGRE_FORCE_INLINE bool write(char c, size_t size, size_t count = 1)
      {
       return fputc(c, fp) == EOF;
      }

      NXOGRE_FORCE_INLINE void write(const char* format, ...)
      {
       va_list args;
       va_start(args, format);
       fprintf(fp, format, args);
       va_end(args);
      }
      
     protected:
      
      FILE* fp;
      
     };
    }
   }

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
        
        WindowsMemoryTracker()
        {
         
        }
        
       ~WindowsMemoryTracker()
        {

#if NXOGRE_DEBUG_MEMORY >= 1
         Platform::File f;
         f.open("NxOgreMemoryWindows.txt", false, true);
#if NXOGRE_DEBUG_MEMORY == 1
         f.write("Remaining allocations: %i", mAllocations);
#elif NXOGRE_DEBUG_MEMORY >= 2
         f.write("Unfreed Allocations\n--------\n");
         for (mCurrentAllocationsIterator = mCurrentAllocations.begin(); mCurrentAllocationsIterator != mCurrentAllocations.end(); mCurrentAllocationsIterator++)
         {
          if ((*mCurrentAllocationsIterator).second.file_pushed != 0)
          {
           mStringsIterator = mStrings.find((*mCurrentAllocationsIterator).second.file_pushed);
           f.write("#%p %i bytes from %s:%i\n", 
              (*mCurrentAllocationsIterator).first,
              (*mCurrentAllocationsIterator).second.size,
              (*mStringsIterator).second.c_str(),
              (*mCurrentAllocationsIterator).second.line_pushed
            );
          }
         }
#endif
#if NXOGRE_DEBUG_MEMORY  == 3
         f.write("Freed Allocations\n--------\n");
         for (mAllAllocationsIterator = mAllAllocations.begin(); mAllAllocationsIterator != mAllAllocations.end(); mAllAllocationsIterator++)
         {
          if ((*mAllAllocationsIterator).second.file_pushed != 0)
          {
           mStringsIterator = mStrings.find((*mAllAllocationsIterator).second.file_pushed);
           f.write("+ %i bytes\n new %s:%i\n", 
              (*mAllAllocationsIterator).second.size,
              (*mStringsIterator).second.c_str(),
              (*mAllAllocationsIterator).second.line_pushed
            );
            
           mStringsIterator = mStrings.find((*mAllAllocationsIterator).second.file_popped);
           f.write(" delete %s:%i\n",
              (*mStringsIterator).second.c_str(),
              (*mAllAllocationsIterator).second.line_popped
            );
           
          }

         }

#endif
#endif
         f.close();

        }
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
     
   } // namespace NxOgre::GC
   } // namespace NxOgre

  #endif // _MSC_VER


#endif

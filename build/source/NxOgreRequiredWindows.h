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
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "string.h"

#ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX) && defined(_MSC_VER)
#       define NOMINMAX // required to stop windows.h messing up std::min
#endif
#include "windows.h"

#define NXOGRE_PLATFORM_WINDOWS 0
#define NXOGRE_COMPILER_MSVC 0

  #define NXOGRE_PLATFORM NXOGRE_PLATFORM_WINDOWS
  #define NXOGRE_PLATFORM_STRING "Windows"

  #if ( defined (_MSC_VER) )
   
   // Remove Warning: "class 'std::map<_Kty,_Ty>' needs to have dll-interface to be used by clients of class"
   #pragma warning(disable: 4251)
   
   // ------------------------------------------------------------------
   
   #define NXOGRE_COMPILER NXOGRE_COMPILER_MSVC
   #define NXOGRE_COMPILER_STRING "Microsoft Visual C++ " NXOGRE_STRINGIFY(_MSC_VER)
   
   // ------------------------------------------------------------------
   
   #ifdef NXOGRE_IS_LIBRARY
       
       #define NXOGRE_C_FUNCTION extern __declspec(dllexport)
       
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
    namespace Platform
    {
     
     
     NXOGRE_FORCE_INLINE static void printf(const char* format, ...)
     {
      va_list args;
      va_start(args, format);
      ::vprintf(format, args);
      va_end(args);
     }
     
     
     class Timer
     {
       
      public:
       
       NXOGRE_FORCE_INLINE Timer()
       {
        reset();
       }
       
       NXOGRE_FORCE_INLINE Real nowSeconds()
       {
        return Real(nowMilliseconds()) * Real(0.001);
       }
       
       NXOGRE_FORCE_INLINE unsigned long nowMilliseconds()
       {
        LARGE_INTEGER curTime;
        
        HANDLE thread = GetCurrentThread();

        DWORD_PTR oldMask = SetThreadAffinityMask(thread, mTimerMask);
        
        QueryPerformanceCounter(&curTime);
        
        SetThreadAffinityMask(thread, oldMask);
        
        LONGLONG newTime = curTime.QuadPart - mStartTime.QuadPart;
        
        unsigned long newTicks = (unsigned long) (1000 * newTime / mFrequency.QuadPart);

        unsigned long check = GetTickCount() - mStartTick;
        signed long msecOff = (signed long)(newTicks - check);
        if (msecOff < -100 || msecOff > 100)
        {
         LONGLONG adjust = (std::min)(msecOff * mFrequency.QuadPart / 1000, newTime - mLastTime);
         mStartTime.QuadPart += adjust;
         newTime -= adjust;
         newTicks = (unsigned long) (1000 * newTime / mFrequency.QuadPart);
        }
        mLastTime = newTime;
        return newTicks;
       }
       
       NXOGRE_FORCE_INLINE void reset()
       {
        DWORD_PTR procMask;
        DWORD_PTR sysMask;
        GetProcessAffinityMask(GetCurrentProcess(), &procMask, &sysMask);
        
        if (procMask == 0)
         procMask = 1;
        
        if (mTimerMask == 0)
        {
         mTimerMask = 1;
         while ( ( mTimerMask & procMask ) == 0 )
         {
          mTimerMask <<= 1;
         }
        }
        
        HANDLE thread = GetCurrentThread();
        
        DWORD_PTR oldMask = SetThreadAffinityMask(thread, mTimerMask);
        
        QueryPerformanceFrequency(&mFrequency);
        QueryPerformanceCounter(&mStartTime);
        mStartTick = GetTickCount();
        
        SetThreadAffinityMask(thread, oldMask);
        
        mLastTime = 0;
        mZeroClock = clock();
       }

       NXOGRE_FORCE_INLINE bool setAffinityMask(const DWORD& newTimerMask)
       {
        DWORD_PTR procMask;
        DWORD_PTR sysMask;
        
        GetProcessAffinityMask(GetCurrentProcess(), &procMask, &sysMask);
        
        if ( ( (newTimerMask == 0) || ((newTimerMask & procMask) != 0) ) && (newTimerMask & (newTimerMask-1)) )
        {
         mTimerMask = newTimerMask;
         return true;
        }
        return false;
       }
       
      protected:
       
       clock_t        mZeroClock;
       DWORD          mStartTick;
       LONGLONG       mLastTime;
       LARGE_INTEGER  mStartTime;
       LARGE_INTEGER  mFrequency;
       DWORD_PTR      mTimerMask;
       
     };
     
     
     struct Time
     {
        
        NXOGRE_FORCE_INLINE Time()
        {
         refresh();
        }
        
        NXOGRE_FORCE_INLINE void refresh()
        {
         time(&timestamp);
         localtime_s(&now, &timestamp);
        }
        
        NXOGRE_FORCE_INLINE int second() const
        {
         return now.tm_sec;
        }
        
        NXOGRE_FORCE_INLINE int minute() const
        {
         return now.tm_min;
        }
      
        NXOGRE_FORCE_INLINE int hour() const
        {
         return now.tm_hour;
        }
        
        NXOGRE_FORCE_INLINE int day() const
        {
         return now.tm_mday;
        }
        
        NXOGRE_FORCE_INLINE int month() const
        {
         return now.tm_mon + 1;
        }
        
        NXOGRE_FORCE_INLINE int year() const
        {
         return now.tm_year + 1900;
        }
        
      protected:
        
        struct tm now;
        time_t timestamp;
        
     };
     
     
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
       return ferror(fp) != 0;
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

      NXOGRE_FORCE_INLINE bool write(char c, size_t count = 1)
      {
       return fputc(c, fp) == EOF;
      }

      NXOGRE_FORCE_INLINE void write(const char* string)
      {
       fputs (string, fp);
      }

      NXOGRE_FORCE_INLINE void writef(const char* format, ...)
      {
       va_list args;
       va_start(args, format);
       vfprintf(fp, format, args);
       va_end(args);
      }
      
     protected:
      
      FILE* fp;
      
     };
     
     
    } // namespace NxOgre::Platform
    
    typedef Platform::Timer Timer;
    
   } // namespace NxOgre

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
         writeToFile();
        }

#if NXOGRE_DEBUG_MEMORY == 1
        NXOGRE_FORCE_INLINE void push_memory(void* memory)
        {
         mAllocations++;
        }
#endif

#if NXOGRE_DEBUG_MEMORY >= 2
        NXOGRE_FORCE_INLINE void push_memory(void* memory, size_t length, const char* file, const char* function, size_t line)
        {
         Allocation allocation;
         allocation.file_pushed = pushFileString(file);
         allocation.function_pushed = pushFunctionString(function);
         allocation.line_pushed = line;
         allocation.size = length;
         allocation.file_popped = 0;
         allocation.line_popped = 0;
         allocation.function_popped = 0;
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
        NXOGRE_FORCE_INLINE void pop_memory(void* memory, const char* file, const char* function, size_t line)
        {
         mCurrentAllocationsIterator = mCurrentAllocations.find(memory);
         if (mCurrentAllocationsIterator != mCurrentAllocations.end())
         {
          mCurrentAllocations.erase(mCurrentAllocationsIterator);
         }
         
#if NXOGRE_DEBUG_MEMORY == 3
         mAllAllocationsIterator = mAllAllocations.find(memory);
         if (mAllAllocationsIterator != mAllAllocations.end())
         {
          (*mAllAllocationsIterator).second.file_popped = pushFileString(file);
          (*mAllAllocationsIterator).second.function_popped = pushFunctionString(function);
          (*mAllAllocationsIterator).second.line_popped = line;
         }
#endif
        
        }
#endif
       
       protected:
        
#if NXOGRE_DEBUG_MEMORY == 1
        size_t mAllocations;
#elif NXOGRE_DEBUG_MEMORY >= 2
        

#if NXOGRE_DEBUG_MEMORY == 1
        NXOGRE_FORCE_INLINE void writeToFile()
        {
         NxOgre::Platform::File f;
         f.open("NxOgreMemoryAllocator.txt", false, true);
         if (mAllocations > 0)
          f.writef("%i allocations un-freed.", mAllocations)
         else
          f.write("All allocations freed.");
         f.close();
        }
#endif

#if NXOGRE_DEBUG_MEMORY == 2
        NXOGRE_FORCE_INLINE void writeToFile()
        {
         NxOgre::Platform::File f;
         f.open("NxOgreMemoryAllocator.txt", false, true);
         if (mCurrentAllocations.size() > 0)
         {
          f.write("Memory leaks detected!!\n");
          size_t remaining_memory = 0;
          for (std::map<void*, Allocation>::const_iterator it = mCurrentAllocations.begin(); it != mCurrentAllocations.end(); it++)
          {
           remaining_memory += (*it).second.size;
          }
          
          f.writef("%i allocations with a total of %i bytes\n\n", mCurrentAllocations.size(), remaining_memory);
          
          for (std::map<void*, Allocation>::const_iterator it = mCurrentAllocations.begin(); it != mCurrentAllocations.end(); it++)
          {
           const char* file_name = getString((*it).second.file_pushed);
           const char* function_name = getString((*it).second.function_pushed);
           f.writef("%i bytes\n + %s %s(%i)\n",(*it).second.size, function_name, file_name, (*it).second.line_pushed );
          }
          
         }
         else
         {
          f.write("No leaks detected.\n");
         }
         
         f.close();
        }
#endif

#if NXOGRE_DEBUG_MEMORY == 3
        NXOGRE_FORCE_INLINE void writeToFile()
        {
         NxOgre::Platform::File f;
         f.open("NxOgreMemoryAllocator.txt", false, true);
         if (mCurrentAllocations.size() > 0)
         {
          f.write("Memory leaks detected!!\n");
          size_t remaining_memory = 0;
          for (std::map<void*, Allocation>::const_iterator it = mCurrentAllocations.begin(); it != mCurrentAllocations.end(); it++)
          {
           remaining_memory += (*it).second.size;
          }
          
          f.writef("%i allocations with a total of %i bytes\n\n", mCurrentAllocations.size(), remaining_memory);
          
          for (std::map<void*, Allocation>::const_iterator it = mCurrentAllocations.begin(); it != mCurrentAllocations.end(); it++)
          {
           const char* file_name = getString((*it).second.file_pushed);
           const char* function_name = getString((*it).second.function_pushed);
           f.writef("%i bytes\n + %s %s(%i)\n",(*it).second.size, function_name, file_name, (*it).second.line_pushed );
          }
          
         }
         else
         {
          f.write("No leaks detected.\n");
         }
         
         
         f.write("\nAllocation History\n");
         
          for (std::map<void*, Allocation>::const_iterator it = mAllAllocations.begin(); it != mAllAllocations.end(); it++)
          {
           const char* push_file = getString((*it).second.file_pushed);
           const char* push_function = getString((*it).second.function_pushed);
           const char* pop_file = getString((*it).second.file_popped);
           const char* popped_function = getString((*it).second.function_popped);
           f.writef("%i bytes\n + %s %s(%i)\n", (*it).second.size, push_function, push_file, (*it).second.line_pushed);
           
           if (popped_function != 0)
            f.writef(" - %s %s(%i)\n", popped_function, pop_file, (*it).second.line_popped );
           else
            f.write(" ? No deallocation record.\n");
          }

         f.close();
        }
#endif


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
        
        NXOGRE_FORCE_INLINE const char* getString(size_t hashed_string) const
        {
         std::map<size_t, std::string>::const_iterator it = mStrings.find(hashed_string);
         if (it == mStrings.end())
          return 0;
         return (*it).second.c_str();
        }

        NXOGRE_FORCE_INLINE size_t pushFileString(const char* string)
        {
         const char* file_name = strrchr(string, '\\');
                  
         if (file_name != 0)
         {
          if (strlen(file_name) > 1)
          {
           return pushString(file_name + 1);
          }
          else
          {
           return pushString(file_name);
          }
         }
         else
         {
          return pushString(string);
         }
        }
        

        NXOGRE_FORCE_INLINE size_t pushFunctionString(const char* string)
        {
         const char* function_name = strstr(string, "NxOgre::");
         if (function_name != 0)
          return pushString(function_name + 8);
         else
          return pushString(string);
        }

        NXOGRE_FORCE_INLINE size_t pushString(const char* string)
        {
         size_t string_hash = hash(string);
         mStringsIterator = mStrings.find(string_hash);
         if (mStringsIterator == mStrings.end())
         {
          mStrings.insert(std::pair<size_t, std::string>(string_hash, std::string(string)));
         }
         return string_hash;
        }

        struct Allocation
        {
         size_t file_pushed, file_popped;
         size_t line_pushed, line_popped;
         size_t function_pushed, function_popped;
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
       friend void* safe_malloc(size_t,const char*,const char*,size_t);
       friend void  safe_free(void*,const char*,const char*,size_t);
       friend void* safe_realloc(void* ptr, size_t length, const char* file, const char*, size_t line);
       friend void  safe_debug_delete(void*);
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
       NXOGRE_FORCE_INLINE void* allocateMemory(size_t length, const char* file, const char* function, size_t line)
       {
        void* ptr = malloc(length);
        WindowsMemoryTracker::Tracker.push_memory(ptr, length, file, function, line);
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
       NXOGRE_FORCE_INLINE void* reallocateMemory(void* ptr, size_t length, const char* file, const char* function, size_t line)
       {
        void* new_ptr = realloc(ptr, length);
        WindowsMemoryTracker::Tracker.pop_memory(ptr, file, function, line);
        WindowsMemoryTracker::Tracker.push_memory(new_ptr, length, file, function, line);
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
       NXOGRE_FORCE_INLINE void freeMemory(void* ptr, const char* file, const char* function, size_t line)
       {
        if (file != 0)
        {
          WindowsMemoryTracker::Tracker.pop_memory(ptr, file, function, line);
        }
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

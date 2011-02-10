#include <string.h>
#include "malloc.h"
#include <iostream>
#include <map>
#include "assert.h"
#include <algorithm>
#include <ostream>

#define NXOGRE_FORCE_INLINE __forceinline
#define NXOGRE_CLASS
#define NXOGRE_NULL_POINTER 0

#define NXOGRE_DEBUG_ARRAY 1


#if NXOGRE_DEBUG_ARRAY == 1
#define NXOGRE_DEBUG_PRINT_ARRAY(MESSAGE) std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << MESSAGE << "\n";
#else
#define NXOGRE_DEBUG_PRINT_ARRAY(MESSAGE)
#endif

#define NXOGRE_DEBUG_MEMORY 1


   namespace NxOgre
   {
    
    
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

     template<typename T, typename Comparision = boolean::less<T> > struct sort
     {
      NXOGRE_FORCE_INLINE void operator()(T* begin, T* end)
      {
       std::sort(begin, end, Comparision());
      }
     };

     template<typename T, typename Comparision = boolean::equals<T> > struct unique
     {
      NXOGRE_FORCE_INLINE T* operator()(T* begin, T* end)
      {
       return std::unique(begin, end, Comparision());
      }
     };

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


    }; // class Util


    struct Strings
    {
     
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
     
    };

    namespace GC
    {
     class NXOGRE_CLASS MemoryAllocator
     {
      
      friend void* safe_new(size_t);
      friend void  safe_free(void*);
      
      protected:
       
       static MemoryAllocator Allocator;

       MemoryAllocator()
       {
#if NXOGRE_DEBUG_MEMORY == 1
       mNbAllocations = 0;
       mHighestAllocations = 0;
       mMemoryUsed = 0;
       mHighestMemoryUsed = 0;
#endif
       }

       ~MemoryAllocator()
       {
#if NXOGRE_DEBUG_MEMORY == 1
        std::cout << "Memory Usage---\n"
                  << "Highest: " << mHighestMemoryUsed << " bytes\n"
                  << "Current: " << mMemoryUsed << " bytes\n"
                  << "Highest Allocations: " << mHighestAllocations << "\n"
                  << "Current Allocations: " << mNbAllocations << "\n";
#endif
       }

       NXOGRE_FORCE_INLINE void* allocateMemory(size_t length)
       {
        
#if NXOGRE_DEBUG_MEMORY == 1
        mNbAllocations++;
        mMemoryUsed += length;
        if (mMemoryUsed > mHighestMemoryUsed)
         mHighestMemoryUsed = mMemoryUsed;
        if (mNbAllocations > mHighestAllocations)
         mHighestAllocations = mNbAllocations;
        void* ptr = malloc(length);
        mAllocatedSizes[ptr] = length;
        return ptr;
#else
        return malloc(length);
#endif
       }
       
       NXOGRE_FORCE_INLINE void freeMemory(void* ptr)
       {
#if NXOGRE_DEBUG_MEMORY == 1
        std::map<void*, size_t>::iterator it = mAllocatedSizes.find(ptr);
        if (it != mAllocatedSizes.end())
        {
         mNbAllocations--;
         mMemoryUsed -= (*it).second;
         mAllocatedSizes.erase(it);
        }
#endif
         free(ptr);
       }

#if NXOGRE_DEBUG_MEMORY == 1
       unsigned int mNbTotalAllocations, mNbAllocations, mHighestAllocations;
       unsigned int mMemoryUsed, mHighestMemoryUsed;
       std::map<void*, size_t> mAllocatedSizes;
#endif
     };

     NXOGRE_FORCE_INLINE void* safe_new(size_t length)
     {
      return MemoryAllocator::Allocator.allocateMemory(length);
     }

     NXOGRE_FORCE_INLINE void safe_free(void* ptr)
     {
      if (ptr != NXOGRE_NULL_POINTER)
      {
       MemoryAllocator::Allocator.freeMemory(ptr);
      }
     }

     class NXOGRE_CLASS NoGarbageCollectionPolicy
     {
       
      public:
       
       // array<T>
       template<typename T> class gc
       {
        public:
          NXOGRE_FORCE_INLINE void free(T&) {}
          NXOGRE_FORCE_INLINE void free(T* first, T* last) {}
       };
      
       // array<T*>
       template<typename T> class gc<T*>
       {
        public:
          NXOGRE_FORCE_INLINE void free(T*) {}
          NXOGRE_FORCE_INLINE void free(T* first, T* last) {}
       };
       
     };

     class NXOGRE_CLASS HasGarbageCollectionPolicy
     {
       
      public:
       
       // array<T>
       template<typename T> class gc
       {
        public:
          NXOGRE_FORCE_INLINE void free(T& val)
          {
           val.~T();
          }
          NXOGRE_FORCE_INLINE void free(T* first, T* last)
          {
           while (first != last)
           {
            (*first).~T();
            first++;
           }
          }
       };
      
       // array<T*>
       template<typename T> class gc<T*>
       {
        public:
          NXOGRE_FORCE_INLINE void free(T*) {}
          NXOGRE_FORCE_INLINE void free(T* first, T* last) {}
       };
       
     };


    }
   }

   namespace NxOgre
   {

   namespace GC
   {
   
   /* class. safe_memory
      desc.
          Block of resizable memory of T, that is automatically
          deleted on the destructor of safe_memory.
      note.
          safe_memory isn't concerned about the content of your
          data, so won't initialize or destruct any values when
          resizing or destruction.
   */
   template<typename T> class safe_memory
   {
     
    public:
     
     NXOGRE_FORCE_INLINE safe_memory()
     : mData(0), mCapacity(0)
     {
     }
     
     NXOGRE_FORCE_INLINE ~safe_memory()
     {
      GC::safe_free(mData);
     }
     
     /*
       function. resize
       desc.
           Resize the block of memory to a larger or smaller size.
       note.
           - If the new size is larger then the contents is copied
             and preserved.
           - If the new size is smaller then the only the number of
             new_size is copied, and the other remaining data is removed.
     */
     NXOGRE_FORCE_INLINE void resize(size_t new_capacity)
     {
      if (new_capacity == mCapacity)
      {
       // Do nothing.
      }
      else if (mCapacity == 0)
      {
       // Enlarge, but don't copy.
       mData = static_cast<T*>(  GC::safe_new(new_capacity * sizeof(T))  );
      }
      else if (new_capacity < mCapacity)
      {
       // Shrink and preserve some of the data.
       T* new_data = static_cast<T*>(  GC::safe_new(new_capacity * sizeof(T))  );
       Util::copy(begin(), begin() + new_capacity, new_data);
       GC::safe_free(mData);
       mData = new_data;
      }
      else
      {
       // Enlarge and preserve all data.
       T* new_data = static_cast<T*>(  GC::safe_new(new_capacity * sizeof(T))  );
       Util::copy(begin(), end(), new_data);
       GC::safe_free(mData);
       mData = new_data;
      }
      mCapacity = new_capacity;
     }

     /* function. fill
        desc.
            Fill all values with a single value.
     */
     NXOGRE_FORCE_INLINE void fill(const T& value = T())
     {
      for(size_t i=0;i < mCapacity;i++)
       mData[i] = value;
     }

     /* function. begin
        desc.
            Get the first element
     */
     NXOGRE_FORCE_INLINE T* begin()
     {
      return mData;
     }
     
     /* function. end
        desc.
            Get the last + 1 element
     */
     NXOGRE_FORCE_INLINE T* end()
     {
      return mData + mCapacity;
     }
     
     /* function. operator[]
        desc.
            Get any element.
     */
     NXOGRE_FORCE_INLINE T& operator[](size_t index)
     {
      return mData[index];
     }
     
     NXOGRE_FORCE_INLINE const T& operator[](size_t index) const
     {
      return mData[index];
     }

     NXOGRE_FORCE_INLINE size_t capacity() const
     {
      return mCapacity;
     }
     
    protected:
     
     T*      mData;
     size_t  mCapacity;
   };

   } // namespace GC


template <typename T, typename GarbageCollectionPolicy = GC::NoGarbageCollectionPolicy> class array
{
  
 public:
  


  NXOGRE_FORCE_INLINE array()
  : mUsed(0)
  {
  }

  NXOGRE_FORCE_INLINE array(const array& other)
  : mUsed(0)
  {
   copy_from(other);
  }
  
  NXOGRE_FORCE_INLINE ~array()
  {
   mGC.free(mMemory.begin(), mMemory.begin() + mUsed);
  }

  NXOGRE_FORCE_INLINE void copy_from(const array& other)
  {
   remove_all();
   reserve(other.size());
   for (size_t i=0; i < other.size();i++)
    mMemory[i] = other.mMemory[i];
  }

  NXOGRE_FORCE_INLINE void remove_all()
  {
   mGC.free(mMemory.begin(), mMemory.end());
   mUsed = 0;
  }

  NXOGRE_FORCE_INLINE size_t size() const
  {
   return mUsed;
  }

  NXOGRE_FORCE_INLINE size_t capacity() const
  {
   return mMemory.capacity();
  }

  NXOGRE_FORCE_INLINE T& operator[](size_t index)
  {
   assert(index < mUsed);
   return mMemory[index];
  }

  NXOGRE_FORCE_INLINE const T& operator[](size_t index) const
  {
   assert(index < mUsed);
   return mMemory[index];
  }
  
  NXOGRE_FORCE_INLINE T& at(size_t index)
  {
   assert(index < mUsed);
   return mMemory[index];
  }

  NXOGRE_FORCE_INLINE const T& at(size_t index) const
  {
   assert(index < mUsed);
   return mMemory[index];
  }
  
  /* function. firstOf
     desc.
         Performs a linear search of the first occurrence of
         a given value.
         
     return.
         - If the value is found, then the position of that value 
           in the array is returned.
         - If the value is not found, then the size of the array
           is returned as an indicator of a failed search.
  */
  NXOGRE_FORCE_INLINE size_t firstOf(const T& value) const
  {
   for(size_t i=0;i < mUsed;i++)
   {
    if (mMemory[i] == value)
     return i; // Success.
   }
   return mUsed; // Failure.
  }

  NXOGRE_FORCE_INLINE void reserve(size_t size)
  {
   if (size != 0 && size > mMemory.capacity())
   {
    mMemory.resize(size);
   }
  }

  NXOGRE_FORCE_INLINE void push_back(const T& value)
  {
   if (mMemory.capacity() == 0 || mUsed >= mMemory.capacity())
    reserve(mUsed == 0 ? 1 : mUsed * 2);
   mMemory[mUsed] = value;
   mUsed++;
  }

  NXOGRE_FORCE_INLINE void pop_back()
  {
   if (mUsed == 0)
    return;
   mGC.free(mMemory[mUsed-1]);
   mUsed--;
  }

  NXOGRE_FORCE_INLINE void erase(size_t index)
  {
   assert(index < mUsed);
   
   if (index == mUsed-1)
   {
    mGC.free(mMemory[index]);
    mUsed--;
   }
   else
   {   
    mGC.free(mMemory[index]);
    Util::swap(mMemory[index], mMemory[mUsed-1]);
    mUsed--;
   }
  }
  
 protected:
  
  GC::safe_memory<T>                       mMemory;
  size_t                                   mUsed;
  typename GarbageCollectionPolicy::gc<T>  mGC;
};

} // namespace NxOgre


class X
{
 public:
  
  X()
  {
   std::cout << "X constructor\n";
  }
  
 ~X()
  {
   std::cout << "X destructor\n";
  }
  
  int x, y, z;
};

void main()
{
 NxOgre::array<int, NxOgre::GC::HasGarbageCollectionPolicy> x;
 
 x.push_back(1);
 x.pop_back();
 x.push_back(2);
 x.push_back(3);
 x.push_back(4);
 x.erase(1);
 x.erase(0);
 for (size_t i=0; i < x.size(); i++)
 {
  std::cout << "[" << i << "] => " << x[i] << "\n";
 }

 std::cout << x.firstOf(4) << "\n";

}

void main1()
{
 int ints[] = { 5,3,2,4,1 };
 NxOgre::Util::sort<int> s;
 s(&ints[0], &ints[5]);
 
 
 NxOgre::Strings::join(std::cout, &ints[0], &ints[5], ',');
 std::cout << std::endl;
}

NxOgre::GC::MemoryAllocator NxOgre::GC::MemoryAllocator::Allocator = NxOgre::GC::MemoryAllocator();
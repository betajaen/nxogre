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

                                                                                       

#ifndef NXOGRE_BUFFER_H
#define NXOGRE_BUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreAllocatables.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. buffer
    desc.
        A class that is like a self-resizable array with garbage collection.
*/
template<typename T> class buffer
{

 public:

  static const size_t npos = -1;

  inline buffer() : mFirst(0), mLast(0), mEnd(0)
  { // constructor.
  }

  inline buffer(const char* file, unsigned int line) : mFirst(0), mLast(0), mEnd(0)
  { // constructor.
  }

  inline buffer(const buffer& other) : mFirst(0), mLast(0), mEnd(0)
  { // copy constructor.
   resize(other.size());
   std::copy(other.mFirst, other.mLast, mFirst);
  }

  inline ~buffer()
  {
   if (mFirst)
    GC::safe_free<T, FrequentOperationsAllocator>(mFirst, NXOGRE_GC_THIS);
  }

  inline size_t size() const
  {
   return size_t(mLast - mFirst);
  }

  inline size_t capacity() const
  {
   return size_t(mEnd - mFirst);
  }

  inline T& operator[](size_t index)
  {
   return *(mFirst + index);
  }

  inline T& at(size_t index)
  {
   return *(mFirst + index);
  }

  inline const T& at(size_t index) const
  {
   return *(mFirst + index);
  }

  /*! function. index
      desc.
          Find the mFirst index of that matches the given value.
  */
  inline size_t index(const T& value)
  {
   T* it = mFirst;
   while(it != mLast)
   {
    if (*it == value)
     return it - mFirst;
   }
   return npos;
  }

  /*! function. resize
      desc.
          Change the buffer size to nb_elements. If the size is reduced, then some of the existing elements will be copied otherwise all of the elements will be copied.
  */
  inline void resize(size_t new_size)
  {
   
   NxOgre_DebugPrint_Buffer("resize type='" << typeid(T).name() << "', first => '" << mFirst << "', current_size = '" << size() << "', new_size = '" << new_size << "'");
   
   T* new_first = GC::safe_malloc<T, FrequentOperationsAllocator>(sizeof(T) * new_size, __FILE__, __LINE__);

   if (size() != 0)
   {
    if (size() < new_size)
     std::copy(mFirst, mLast, new_first);
    else if (size() >= new_size)
     std::copy(mFirst, mFirst + new_size, new_first);
   }
   
   GC::safe_free<T, FrequentOperationsAllocator>(mFirst, __FILE__, __LINE__);
   mEnd = new_first + new_size;
   mLast = new_first + size();
   mFirst = new_first;
   
  }

  inline void remove_all()
  {
   mLast = mFirst;
  }

  /*! function. push_back
      desc.
          Put value at the "mLast" pointer of the buffer, and increase "mLast" by one.
      note.
          If "mLast" is the same as "mEnd", then the buffer is doubled in size.
  */
  inline void push_back(const T& value)
  {
   if (mLast == mEnd)
    resize(size() == 0 ? 1 : size() * 2);
   *mLast = value;
   mLast++;
  }

  inline void pop_back()
  {
   if (mLast != mFirst)
    mLast--;
  }

  inline void fill(const T& value)
  {
   std::fill(mFirst, mLast, value);
  }

  inline T* first()
  {
   return mFirst;
  }

  inline T* last()
  {
   return mLast;
  }
  
 protected:
  
   T *mFirst, *mLast, *mEnd;
  
};

                                                                                       

/*! class. const_buffer
    desc.
        Interface to access memory between two pointers for read only access.
*/
template<typename T> class  const_buffer
{

  public:

   inline const_buffer()
   {
    first_ptr = 0;
    last_ptr = 0;
   };

   inline const_buffer(T* first, T* last)
   {
    first_ptr = first;
    last_ptr = last;
   };

   inline const_buffer(const const_buffer<T>& other)
   {
    first_ptr = other.first_ptr;
    last_ptr = other.last_ptr;
   }

   inline ~const_buffer()
   { // empty destructor.
   }

   inline const_buffer<T>& operator=(const const_buffer<T>& other)
   {
    first_ptr = other.first_ptr;
    last_ptr = other.last_ptr;
    return *this;
   }

   /*! function. size
       desc.
           Get the number of elements.
   */
   inline size_t size() const
   {
    return size_t(last_ptr - first_ptr);
   }

   /*! function. operator[]
       desc.
           Get the value at the index given.
   */
   inline const T& operator[](size_t index) const
   {
    return *(first_ptr + index);
   }

   /*! function. at
       desc.
           Get the value at the index given.
   */
   inline const T& at(size_t index) const
   {
    return *(first_ptr + index);
   }

   /*! function. index
       desc.
           Find the first index of that matches the given value, or npos if none.
   */
   inline size_t index(const T& value)
   {
    T* it = first_ptr;
    while(it != last_ptr)
    {
     if (*it == value)
      return it - first_ptr;
    }
    return npos;
   }

   inline const T* first() const
   {
    return first_ptr;
   }

   inline const T* last() const
   {
    return last_ptr;
   }

  protected:

   T*  first_ptr;
   T*  last_ptr;

                                                                                       

}; // class const_buffer

                                                                                       

/** \brief Fill a chunk of memory with a value
*/
template<typename T> void fill(T* start, T* end, T value)
{
 for (;start != end; ++start)
  (*start) = value;
}

                                                                                       


} // namespace NxOgre



#endif

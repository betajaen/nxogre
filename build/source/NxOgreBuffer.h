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
#include "NxOgreClasses.h"
#include "NxOgreAllocatables.h"
#include "stdio.h"

                                                                                       

namespace NxOgre
{

                                                                                       

template<class T> class  Buffer;

                                                                                       

namespace Functions
{
 
    template<typename T> class SharedBuffer : public SixteenBytesAllocatable
    {
      public:
        
       friend class ::NxOgre::Buffer<T>;
       
       typedef typename T* TIterator;
       
       static const int nPos = -1;

        SharedBuffer(int type = ::NxOgre::Classes::USER_CLASS)
        {
         _First = _Last = _End = 0;
         _Type = type;
        }
        
        ~SharedBuffer()
        {
         if (_First)
         {
          NXOGRE_DEALLOCATE(FrequentOperationsAllocator, _First);
         }
         _First = _Last = _End = 0;
        }
        
        TIterator _First, _Last, _End;
        int       _Type;
    };
    
  NxOgreSixteenBytesRestriction(SharedBuffer<int>);

  template<typename T> class BufferFunctions
  {
    public:
    
    friend class ::NxOgre::Buffer<T>;
    
    typedef typename T* TIterator;
    
    typedef typename SharedBuffer<T> SharedBufferT;

    static const int nPos = -1;
    
    
    class Functions
    {
      public:
        
       static size_t size(SharedBufferT* shared_list)
       {
        return size_t(shared_list->_Last - shared_list->_First);
       }
        
       static size_t capacity(SharedBufferT* shared_list)
       {
        return size_t(shared_list->_End - shared_list->_First);
       }
        
       static T& get(SharedBufferT* shared_list, size_t nth_pos)
       {
        return *(shared_list->_First + nth_pos);
       }
        
       static size_t where(SharedBufferT* shared_list, const T& t)
       {
        TIterator begin = shared_list->_First, last = shared_list->_Last;
        for (;begin != last; ++begin)
        if (t == *begin)
         return (begin - shared_list->_First);
        return nPos;
       }
       
       static void insert(SharedBufferT* shared_list, const T& t)
       {
        if (shared_list->_End <= shared_list->_Last)
        {
         size_t new_size = size(shared_list) == 0 ? 1 : size(shared_list) * 2;
         reserve(shared_list, new_size);
        }
       *shared_list->_Last = t;
        shared_list->_Last++;
       }

       static void insertMany(SharedBufferT* shared_buffer, T* t_ptr, unsigned int length)
       {
        if (shared_list->_End <= shared_list->_Last + length)
        {
         size_t new_size = size(shared_list) == 0 ? length : size(shared_list) + length ;
         reserve(shared_list, new_size);
        }
        NxOgreCopy(shared_list->_Last, t_ptr, sizeof(T) * length);
        shared_list->_Last += length;
       }
        
       static void insertMany(SharedBufferT* shared_list, unsigned int length, const void* t_ptr)
       {
        if (shared_list->_End <= shared_list->_Last + length)
        {
         size_t new_size = size(shared_list) == 0 ? length : size(shared_list) + length ;
         reserve(shared_list, new_size);
        }
        NxOgreCopy(shared_list->_Last, t_ptr, sizeof(T) * length);
        shared_list->_Last += length;
       }

       static void removeAll(SharedBufferT* shared_list)
       {
        shared_list->_Last = shared_list->_First;
       }
        
       static void copy(TIterator begin, TIterator end, TIterator dest)
       {
        for (;begin != end; ++dest, ++begin)
         *dest = *begin;
       }
        
       static void clip(SharedBufferT* shared_list, size_t new_size)
       {
        if (new_size < size(shared_list))
         return;
        resize(shared_list, new_size);
       }
        
       static void reserve(SharedBufferT* shared_list, size_t new_size)
       {
        if (capacity(shared_list) >= new_size)
         return;
        resize(shared_list, new_size);
       }
        
       static void resize(SharedBufferT* shared_list, size_t new_size)
       {
        TIterator new_first = (TIterator) NXOGRE_ALLOCATE(FrequentOperationsAllocator, (new_size * sizeof(T)));
        copy(shared_list->_First, shared_list->_Last, new_first);
        range_destruct(shared_list->_First, shared_list->_Last);
        NXOGRE_DEALLOCATE(FrequentOperationsAllocator, shared_list->_First);
        shared_list->_End = new_first + new_size;
        shared_list->_Last = new_first + size(shared_list);
        shared_list->_First = new_first;
       }
        
       static void range_destruct(TIterator begin, TIterator end)
       {
        for (;begin != end; ++begin)
         begin->~T();
       }
        
    };
   
  }; // class BufferFunctions<T>
   
} // namespace Functions

                                                                                       

/** \brief A block of non resizable memory that holds and manipulates non-pointer types; typically used for
           short lasting data or scratch space.
*/
template<typename T> class  Buffer
{
  
  typedef typename ::NxOgre::Functions::BufferFunctions<T>::TIterator    Iterator;
  typedef typename ::NxOgre::Functions::SharedBuffer<T> TPayload;
  typedef typename ::NxOgre::Functions::BufferFunctions<T>::Functions    TFunctions;

  public:

   Buffer(void)
   {
    _T = NXOGRE_NEW_NXOGRE TPayload();
    _Usage = (RefT*) NXOGRE_ALLOCATE(FourByteAllocator, sizeof(unsigned int));
    (*_Usage) = 1;
   };

   Buffer(int type)
   {
    _T = NXOGRE_NEW_NXOGRE TPayload();
    _Usage = (RefT*) NXOGRE_ALLOCATE(FourByteAllocator, sizeof(unsigned int));
    (*_Usage) = 1;
   };

   Buffer(const Buffer<T>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    if (other._Usage)
     (*_Usage)++;
   }

  ~Buffer(void)
   {
    if(--(*_Usage) == 0)
    {
     NXOGRE_DEALLOCATE(FourByteAllocator, _Usage);
     NXOGRE_DELETE_NXOGRE(_T);
    }
   }

   Buffer<T>& operator=(const Buffer<T>& other)
   {
    if(--(*_Usage) == 0)
    {
     NXOGRE_DEALLOCATE(FourByteAllocator, _Usage);
     NXOGRE_DELETE_NXOGRE(_T);
    }
    _T      = other._T;
    _Usage  = other._Usage;
    (*_Usage)++;
    return *this;
   }

   unsigned int size(void) const
   {
    return TFunctions::size(_T);
   }

   unsigned int capacity(void) const
   {
    return TFunctions::capacity(_T);
   }

   T& operator[](size_t nth_pos)
   {
    return *(_T->_First + nth_pos);
   }

   const T& operator[](size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   T& at(size_t nth_pos)
   {
    return *(_T->_First + nth_pos);
   }

   const T& at(size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   unsigned int where(const T& t) const
   {
    return TFunctions::where(_T, t);
   }

   void clear(void)
   {
    TFunctions::removeAll(_T);
   }

   void reserve(size_t reserveSize)
   {
    TFunctions::reserve(_T, reserveSize);
   }

   void append(const T& t)
   {
    TFunctions::insert(_T, t);
   }

   void appendMany(T* t_ptr, size_t length)
   {
    TFunctions::insertMany(_T, t_ptr, length);
   }

   // Like appendMany but with a void* ptr. What ever void* actually is it MUST be same size as T.
   void appendMany(unsigned int length, const void* t_ptr)
   {
    TFunctions::insertMany(_T, length, t_ptr);
   }

   Iterator first()
   {
    return _T->_First;
   }

   Iterator last()
   {
    return _T->_Last;
   }

   Iterator end()
   {
    return _T->_End;
   }
   
   unsigned int contains(const T& value)
   {
    unsigned int s = size();
    for (unsigned int i=0;i < s;i++)
    {
     if ((_T->_First + i) == value)
      return true;
    }
    return false;
   }

   void replace(const T& existing, const T& newValue)
   {
    unsigned int s = size();
    for (unsigned int i=0;i < s;i++)
    {
     if (*(_T->_First + i) == existing)
      *(_T->_First + i) = newValue;
    }
   }

  protected:

    TPayload*      _T;
    RefT*          _Usage;

}; // class Buffer


template<typename T> class  ReadOnlyBuffer
{
  
  public:
   
   typedef typename T* Iterator;

   ReadOnlyBuffer()
   {
    _First = 0;
    _Last = 0;
   };

   ReadOnlyBuffer(Iterator bufferStart, Iterator bufferEnd )
   {
    _First = bufferStart;
    _Last = bufferEnd;
   };

   ReadOnlyBuffer(const ReadOnlyBuffer<T>& other)
   {
    _First = other._First;
    _Last = other._Last;
   }

  ~ReadOnlyBuffer(void)
   {
   }

   ReadOnlyBuffer<T>& operator=(const ReadOnlyBuffer<T>& other)
   {
    _First = other._First;
    _Last = other._Last;
    return *this;
   }

   size_t size(void) const
   {
    return (_Last - _First);
   }

   const T& operator[](size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   Iterator first()
   {
    return _T->_First;
   }

   Iterator last()
   {
    return _T->_Last;
   }

  protected:

   Iterator      _First, _Last;

}; // class Buffer

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

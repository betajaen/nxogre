/** File: NxOgreBuffer.h
    Created on: 15-Feb-09
    Author: Robin Southern "betajaen"
    

    (c) Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_BUFFER_H
#define NXOGRE_BUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreClasses.h"
#include "stdio.h"

                                                                                       

namespace NxOgre
{

                                                                                       

template<class T> class             Buffer;

                                                                                       

namespace Functions
{
  
  template<typename T> class BufferFunctions
  {
    public:
    
    friend class ::NxOgre::Buffer<T>;
    
    typedef typename T* TIterator;
    
    static const int nPos = -1;
    
    class SharedBuffer
    {
      public:
        
        SharedBuffer(int type = ::NxOgre::Classes::USER_CLASS)
        {
         _First = _Last = _End = 0;
         _Type = type;
        }
        
        ~SharedBuffer()
        {
         if (_First)
          ::NxOgre::Memory::unallocate(_First);
         _First = _Last = _End = 0;
        }
        
        void* operator new(size_t size)
        {
         return NxOgre_Allocate(size, ::NxOgre::Classes::_SharedBuffer);
        }
        
        void operator delete(void* ptr)
        {
         ::NxOgre::Memory::unallocate(ptr);
        }
        
        TIterator _First, _Last, _End;
        int       _Type;
    };
    
    class Functions
    {
      public:
        
       static size_t size(SharedBuffer* shared_list)
       {
        return size_t(shared_list->_Last - shared_list->_First);
       }
        
       static size_t capacity(SharedBuffer* shared_list)
       {
        return size_t(shared_list->_End - shared_list->_First);
       }
        
       static T& get(SharedBuffer* shared_list, size_t nth_pos)
       {
        return *(shared_list->_First + nth_pos);
       }
        
       static size_t where(SharedBuffer* shared_list, const T& t)
       {
        TIterator begin = shared_list->_First, last = shared_list->_Last;
        for (;begin != last; ++begin)
        if (t == *begin)
         return (begin - shared_list->_First);
        return nPos;
       }
       
       static void insert(SharedBuffer* shared_list, const T& t)
       {
        if (shared_list->_End <= shared_list->_Last)
        {
         size_t new_size = size(shared_list) == 0 ? 1 : size(shared_list) * 2;
         reserve(shared_list, new_size);
        }
       *shared_list->_Last = t;
        shared_list->_Last++;
       }

       static void insertMany(SharedBuffer* shared_buffer, T* t_ptr, unsigned int length)
       {
        if (shared_list->_End <= shared_list->_Last + length)
        {
         size_t new_size = size(shared_list) == 0 ? length : size(shared_list) + length ;
         reserve(shared_list, new_size);
        }
        Memory::copy(shared_list->_Last, t_ptr, sizeof(T) * length);
        shared_list->_Last += length;
       }
        
       static void insertMany(SharedBuffer* shared_list, unsigned int length, const void* t_ptr)
       {
        if (shared_list->_End <= shared_list->_Last + length)
        {
         size_t new_size = size(shared_list) == 0 ? length : size(shared_list) + length ;
         reserve(shared_list, new_size);
        }
        Memory::copy(shared_list->_Last, t_ptr, sizeof(T) * length);
        shared_list->_Last += length;
       }

       static void removeAll(SharedBuffer* shared_list)
       {
        shared_list->_Last = shared_list->_First;
       }
        
       static void copy(TIterator begin, TIterator end, TIterator dest)
       {
        for (;begin != end; ++dest, ++begin)
         *dest = *begin;
       }
        
       static void clip(SharedBuffer* shared_list, size_t new_size)
       {
        if (new_size < size(shared_list))
         return;
        resize(shared_list, new_size);
       }
        
       static void reserve(SharedBuffer* shared_list, size_t new_size)
       {
        if (capacity(shared_list) >= new_size)
         return;
        resize(shared_list, new_size);
       }
        
       static void resize(SharedBuffer* shared_list, size_t new_size)
       {
        TIterator new_first = (TIterator) NxOgre_Allocate(new_size * sizeof(T), -(shared_list->_Type));
        copy(shared_list->_First, shared_list->_Last, new_first);
        range_destruct(shared_list->_First, shared_list->_Last);
        ::NxOgre::Memory::unallocate(shared_list->_First);
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
  
  typedef typename ::NxOgre::Functions::BufferFunctions<T>::TIterator  Iterator;
  typedef typename ::NxOgre::Functions::BufferFunctions<T>::SharedBuffer TPayload;
  typedef typename ::NxOgre::Functions::BufferFunctions<T>::Functions  TFunctions;

  public:

   Buffer(void)
   {
    _T = NxOgre_New(TPayload)(::NxOgre::Classes::_BufferUnknown);
    _Usage = (RefT*)  NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_BufferReferenceCounter);
    (*_Usage) = 1;
   };

   Buffer(int type)
   {
    _T = NxOgre_New(TPayload)(type);
    _Usage = (RefT*)  NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_BufferReferenceCounter);
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
     ::NxOgre::Memory::unallocate(_Usage);
     delete _T;
    }
   }

   Buffer<T>& operator=(const Buffer<T>& other)
   {
    if(--(*_Usage) == 0)
    {
     ::NxOgre::Memory::unallocate(_Usage);
     delete _T;
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

  protected:

    TPayload*       _T;
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

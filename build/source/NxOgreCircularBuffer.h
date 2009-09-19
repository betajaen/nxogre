/** File: NxOgreCircularBuffer.h
    Created on: 15-Feb-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

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

#ifndef NXOGRE_CIRCULARBUFFER_H
#define NXOGRE_CIRCULARBUFFER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreClasses.h"
#include "stdio.h"

                                                                                       

namespace NxOgre
{

                                                                                       

template<class T> class             CircularBuffer;

                                                                                       

namespace Functions
{
  
  template<typename T> class CircularBufferFunctions
  {
    public:

    friend class ::NxOgre::CircularBuffer<T>;
    
    typedef typename T* TIterator;
    
    static const int nPos = -1;
    
    class SharedCircularBuffer
    {
      public:
        
        SharedCircularBuffer(int type = ::NxOgre::Classes::USER_CLASS)
        {
         _First = _End = _Read = _Write = 0;
         _Type = type;
        }
        
        ~SharedCircularBuffer()
        {
         if (_First)
          NxOgre::Memory::unallocate(_First);
         _First = _End = _Read = _Write = 0;
        }
        
        void* operator new(size_t size)
        {
         return NxOgre_Allocate(size, ::NxOgre::Classes::_SharedCircularBuffer);
        }
        
        void operator delete(void* ptr)
        {
         ::NxOgre::Memory::unallocate(ptr);
        }
        
        TIterator _First, _End, _Read, _Write;
        int       _Type;
    };
    
    class Functions
    {
      public:
        
       static size_t size(SharedCircularBuffer* shared_buffer)
       {
        return size_t(shared_buffer->_Last - shared_buffer->_First);
       }
        
       static size_t capacity(SharedCircularBuffer* shared_buffer)
       {
        return size_t(shared_buffer->_End - shared_buffer->_First);
       }
        
       static T& fetch(SharedCircularBuffer* shared_buffer)
       {
        T& t_ref = *(shared_buffer->_Read);
        shared_buffer->_Read++;
        if (shared_buffer->_Read == shared_buffer->_End)
         shared_buffer->_Read = shared_buffer->_First;
        return t_ref;
       }

       static void append(SharedCircularBuffer* shared_buffer, const T& t)
       {
       *shared_buffer->_Write = t;
        shared_buffer->_Write++;
        if (shared_buffer->_Write == shared_buffer->_End)
         shared_buffer->_Write = shared_buffer->_First;
       }

       static void removeAll(SharedCircularBuffer* shared_buffer)
       {
        shared_buffer->_Last = shared_buffer->_First;
       }

       static void copy(TIterator begin, TIterator end, TIterator dest)
       {
        for (;begin != end; ++dest, ++begin)
         *dest = *begin;
       }
        
       static void reserve(SharedCircularBuffer* shared_buffer, size_t new_size)
       {
        if (capacity(shared_buffer) >= new_size)
         return;
        resize(shared_buffer, new_size);
       }
        
       static void resize(SharedCircularBuffer* shared_buffer, size_t new_size)
       {
        TIterator new_first = (TIterator) ::NxOgre::Memory::allocate(new_size * sizeof(T), -(shared_buffer->_Type));
        copy(shared_buffer->_First, shared_buffer->_End, new_first);
        range_destruct(shared_buffer->_First, shared_buffer->_End);
        ::NxOgre::Memory::unallocate(shared_buffer->_First);
        shared_buffer->_End = new_first + new_size;
        shared_buffer->_First = new_first;
       }

       static void range_destruct(TIterator begin, TIterator end)
       {
        for (;begin != end; ++begin)
         begin->~T();
       }

       static void resetReadWrite(SharedCircularBuffer* shared_buffer)
       {
        shared_buffer->_Write = shared_buffer->_Read = shared_buffer->_First;
       }

    };

  }; // class CircularBufferFunctions<T>


} // namespace Functions

                                                                                       

/** \brief A block of non resizable memory that holds and manipulates non-pointer types; typically used for
           short lasting data or scratch space.
*/
template<typename T> class  CircularBuffer
{
  
  typedef typename ::NxOgre::Functions::CircularBufferFunctions<T>::TIterator  Iterator;
  typedef typename ::NxOgre::Functions::CircularBufferFunctions<T>::SharedCircularBuffer TPayload;
  typedef typename ::NxOgre::Functions::CircularBufferFunctions<T>::Functions  TFunctions;

  public:

   CircularBuffer(void)
   {
    _T = NxOgre_New(TPayload)(::NxOgre::Classes::USER_CLASS);
    _Usage = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_CircularBufferReferenceCounter);
    (*_Usage) = 1;
   };

   CircularBuffer(int type)
   {
    _T = NxOgre_New(TPayload)(type);
    _Usage = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_CircularBufferReferenceCounter);
    (*_Usage) = 1;
   };

   CircularBuffer(const CircularBuffer<T>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    if (other._Usage)
     (*_Usage)++;
   }

  ~CircularBuffer(void)
   {
    if(--(*_Usage) == 0)
    {
     ::NxOgre::Memory::unallocate(_Usage);
     delete _T;
    }
   }

   CircularBuffer<T>& operator=(const CircularBuffer<T>& other)
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

   size_t capacity(void) const
   {
    return TFunctions::capacity(_T);
   }

   size_t where(const T& t) const
   {
    return TFunctions::where(_T, t);
   }

   void reserve(size_t size)
   {
    TFunctions::reserve(_T, size);
    TFunctions::resetReadWrite(_T);
   }

   void clear(void)
   {
    TFunctions::removeAll(_T);
   }

   void append(const T& t)
   {
    return TFunctions::append(_T, t);
   }

   T& fetch()
   {
    return TFunctions::fetch(_T);
   }

  protected:

    TPayload*       _T;
    RefT*          _Usage;

}; // class CircularBuffer


                                                                                       

} // namespace NxOgre

                                                                                       

#endif

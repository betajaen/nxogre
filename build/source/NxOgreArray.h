/** File: NxOgreArray.h
    Created on: 2-Nov-08
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

#ifndef NXOGRE_ARRAY_H
#define NXOGRE_ARRAY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreClasses.h"
#include "stdio.h"
#include <new>

                                                                                       

namespace NxOgre
{

                                                                                       

template<class T> class             Array;
template<class T> class             ConstantArray;
template<class T> class             ArrayIterator;

                                                                                       

namespace Functions
{
  template<typename T> class SharedArray
  {
    public:
      
      enum
      {
       nPos = -1
      };
      
      typedef typename T* TIterator;
      
      SharedArray(int type = ::NxOgre::Classes::_ArrayUnknown)
      {
       _First = _Last = _End = 0;
       _Type = type;
       _Usage = 1;
      }
      
      ~SharedArray()
      {
       if (_First)
       {
        range_destruct(_First, _End);
        ::NxOgre::Memory::unallocate(_First);
       }
       _First = _Last = _End = 0;
      }
      
      void* operator new(size_t size)
      {
       return NxOgre_Allocate(size, ::NxOgre::Classes::_SharedArray);
      }
      
      void operator delete(void* ptr)
      {
       ::NxOgre::Memory::unallocate(ptr);
      }
       
      size_t size(void)
      {
       return size_t(_Last - _First);
      }
       
      size_t capacity(void)
      {
       return size_t(_End - _First);
      }
       
      T& get(size_t nth_pos)
      {
       return *(_First + nth_pos);
      }
       
      size_t where(const T& t)
      {
       TIterator begin = _First, last = _Last;
       for (;begin != last; ++begin)
       if (t == *begin)
        return (begin - _First);
       return nPos;
      }
      
      inline void insert(const T t)
      {
        if (_End <= _Last)
        {
         size_t new_size = size() == 0 ? 1 : size() * 2;
         reserve(new_size);
        }
       (*_Last) = t;
        _Last++;
      }
      
      inline void removeAll(void)
      {
       _Last = _First;
      }
      
      inline void copy(TIterator begin, TIterator end, TIterator dest)
      {
       for (;begin != end; ++dest, ++begin)
        *dest = *begin;
      }
        
      inline void clip(size_t new_size)
      {
       if (new_size < size(shared_array))
        return;
       resize(new_size);
      }
      
      inline void reserve(size_t new_size)
      {
       if (capacity() >= new_size)
        return;
       resize(new_size);
      }
      
      inline void resize(size_t new_size)
      {
       TIterator new_first = (TIterator) NxOgre_Allocate(new_size * sizeof(T), -(_Type));
       range_construct(new_first, new_first + new_size);
       copy(_First, _Last, new_first);
       range_destruct(_First, _End);
       ::NxOgre::Memory::unallocate(_First);
       _End = new_first + new_size;
       _Last = new_first + size();
       _First = new_first;
      }


      static inline void range_construct(TIterator begin, TIterator end)
      {
       for (;begin != end; ++begin)
        new((void*) begin) T();
      }

      static inline void range_destruct(TIterator begin, TIterator end)
      {
       for (;begin != end; ++begin)
        (*begin).~T();
      }


      TIterator _First, _Last, _End;
      int       _Type;
      unsigned int _Usage;
  };

  template<typename T> class ArrayFunctions
  {
  };

  template<typename T> class ArrayFunctions<T*>
  {
    public:

    friend class ::NxOgre::Array<T*>;
    friend class ::NxOgre::ConstantArray<T*>;
    friend class ::NxOgre::ArrayIterator<T*>;
    
    typedef typename T** TIterator;
    
    static const int nPos = -1;
    
    class SharedArray
    {
      public:

        inline SharedArray(int type = ::NxOgre::Classes::USER_CLASS)
        {
         _First = _Last = _End = 0;
         _Type = type;
        }

        inline ~SharedArray()
        {
         if (_First)
          ::NxOgre::Memory::unallocate(_First);
         _First = _Last = _End = 0;
        }

        inline void* operator new(size_t size)
        {
         return NxOgre_Allocate(size, ::NxOgre::Classes::_SharedArray);
        }

        inline void operator delete(void* ptr)
        {
         ::NxOgre::Memory::unallocate(ptr);
        }

        TIterator _First, _Last, _End;
        int       _Type;
    };

    class Read
    {
      public:

       static inline unsigned int size(SharedArray* shared_array)
       {
        return unsigned int(shared_array->_Last - shared_array->_First);
       }

       static inline size_t capacity(SharedArray* shared_array)
       {
        return size_t(shared_array->_End - shared_array->_First);
       }

       static inline T* get(SharedArray* shared_array, size_t nth_pos)
       {
        return *(shared_array->_First + nth_pos);
       }

       static inline size_t where(SharedArray* shared_array, const T* t)
       {
        TIterator begin = shared_array->_First, last = shared_array->_Last;
        for (;begin != last; ++begin)
        if (t == (*begin))
         return (begin - shared_array->_First);
        return nPos;
       }

    };

    class Write
    {
     public:

      static inline size_t size(SharedArray* shared_array)
      {
       return size_t(shared_array->_Last - shared_array->_First);
      }

      static inline size_t capacity(SharedArray* shared_array)
      {
       return size_t(shared_array->_End - shared_array->_First);
      }

      static inline void insert(SharedArray* shared_array, T* t)
      {
       if (shared_array->_End <= shared_array->_Last)
       {
        size_t new_size = size(shared_array) == 0 ? 1 : size(shared_array) * 2;
        reserve(shared_array, new_size);
       }
       (*shared_array->_Last) = t;
       shared_array->_Last++;
      }

      static inline void removeAll(SharedArray* shared_array, bool delete_them)
      {
       if (delete_them)
       {
        TIterator begin = shared_array->_First, last = shared_array->_Last;
        for (;begin != last; ++begin)
        {
         NxOgre_Delete((*begin));
        }
       }
       shared_array->_Last = shared_array->_First;
      }

      static inline void remove(SharedArray* shared_array, size_t nth_pos, bool delete_them)
      {
       if (nth_pos == nPos || nth_pos < 0 || nth_pos > size(shared_array))
        return;
       
       if (delete_them)
       {
        NxOgre_Delete(*(shared_array->_First + nth_pos));
       }

       //copy(shared_array->_First + nth_pos + 1, shared_array->_Last, shared_array->_First + nth_pos);
       *(shared_array->_First + nth_pos) = *(shared_array->_Last -1);
       shared_array->_Last--;
      }

      private:

       static inline void copy(TIterator begin, TIterator end, TIterator dest)
       {
        for (;begin != end; ++dest, ++begin)
         *dest = *begin;
       }

       static inline void clip(SharedArray* shared_array, size_t new_size)
       {
        if (new_size < size(shared_array))
         return;
        resize(shared_array, new_size);
       }

       static inline void reserve(SharedArray* shared_array, size_t new_size)
       {
        if (capacity(shared_array) >= new_size)
         return;
        resize(shared_array, new_size);
       }

       static inline void resize(SharedArray* shared_array, size_t new_size)
       {
        TIterator new_first = (TIterator) NxOgre_Allocate(new_size * sizeof(T*), -(shared_array->_Type));
        copy(shared_array->_First, shared_array->_Last, new_first);
        /// range_destruct(shared_array->_First, shared_array->_Last);
        ::NxOgre::Memory::unallocate(shared_array->_First);
        shared_array->_End = new_first + new_size;
        shared_array->_Last = new_first + size(shared_array);
        shared_array->_First = new_first;
       }

    };

  }; // class ArrayFunctions<T*>


} // namespace Functions

                                                                                       

/** \brief An iterator for Array<T> and ConstantArray<T> types
*/
template<typename T> class  ArrayIterator
{
  
  typedef typename ::NxOgre::Functions::SharedArray<T>            TPayload;
  typedef typename ::NxOgre::Functions::SharedArray<T>::TIterator TIterator;
  
  public:
  
    ArrayIterator(void)
    {
     _T = 0;
    }

    ArrayIterator(const Array<T>& other)
    {
      _T     = other._T;
    }

    ArrayIterator(const ConstantArray<T>& other)
    {
      _T     = other._T;
    }

   ~ArrayIterator(void)
    {
    }

    ArrayIterator<T>& operator=(const ArrayIterator<T>& other)
    {
     _T      = other._T;
     return *this;
    }

    T& begin(void)
    {
     if (_T->_First == 0)
      return 0;
     _Iterator = _T->_First;
     return (_Iterator);
    }

    T* last(void)
    {
     if (_T->_First == 0)
      return 0;
     _Iterator = _T->Last - 1;
     return (*_Iterator);
    }

    T* next(void)
    {
     if (_T->_First == 0 || _Iterator == _T->_Last)
      return 0;
     return (*_Iterator++);
    }

    T* previous(void)
    {
     if (_T->_First == 0 || _Iterator == _T->_First - 1)
      return 0;
     return (*_Iterator--);
    }

    operator T*(void)
    {
     return (*_T);
    }

  protected:

    TPayload*           _T;
    TIterator           _Iterator;
};

                                                                                       

/** \brief An iterator for Array<T*> and ConstantArray<T*> types.
    \example
     <code>
      Array<T*> tA;
      Array<T*>::Iterator it = tA.getIterator();
      for (T* t = it.begin();t = it.next();)
       t->doThings();
     </code>
    \note This ArrayIterator references to the SharedArray; but does not claim
          responsability over deleting it. So you should remove the ArrayIterator
          before the Array, and not the other way around.
*/
template<typename T> class  ArrayIterator<T*>
{
  
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::SharedArray TPayload;
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::TIterator TIterator;
  
  public:
  
    ArrayIterator(void)
    {
     _T = 0;
    }

    ArrayIterator(const Array<T*>& other)
    {
      _T     = other._T;
    }

    ArrayIterator(const ConstantArray<T*>& other)
    {
      _T     = other._T;
    }

   ~ArrayIterator(void)
    {
    }

    ArrayIterator<T*>& operator=(const ArrayIterator<T*>& other)
    {
     _T      = other._T;
     return *this;
    }

    T* begin(void)
    {
     if (_T->_First == 0)
      return 0;
     _Iterator = _T->_First;
     return (*_Iterator);
    }

    T* last(void)
    {
     if (_T->_First == 0)
      return 0;
     _Iterator = _T->Last - 1;
     return (*_Iterator);
    }

    T* next(void)
    {
     if (_T->_First == 0 || _Iterator == _T->_Last)
      return 0;
     return (*_Iterator++);
    }

    T* previous(void)
    {
     if (_T->_First == 0 || _Iterator == _T->_First - 1)
      return 0;
     return (*_Iterator--);
    }

    operator T*(void)
    {
     return (*_T);
    }

  protected:

    TPayload*           _T;
    TIterator           _Iterator;
};

                                                                                       

/** \brief A STL vector like class that holds and manipulates non-pointer types.
*/
template<typename T> class  Array
{
  
  typedef typename ::NxOgre::Functions::SharedArray<T> SharedArrayT;

  public:

   Array(void)
   {
    // printf("Array constructor\n");
    _Array = NxOgre_New(SharedArrayT)(::NxOgre::Classes::_ArrayUnknown);
   };

   Array(int type)
   {
    _Array = NxOgre_New(SharedArrayT)(type);
   };

   Array(const Array<T>& other)
   {
    _Array     = other._Array;
    if (other._Array->_Usage)
     other._Array->_Usage++;
   }

  ~Array(void)
   {
    // printf("Array destructor\n");
    if(--_Array->_Usage == 0)
    {
     NxOgre_Delete(_Array);
    }
   }

   Array<T>& operator=(const Array<T>& other)
   {
    if(--other._Array->_Usage == 0)
    {
     NxOgre_Delete(_Array);
    }
    _Array = other._Array;
    other._Array->_Usage++;
    return *this;
   }

   unsigned int size(void) const
   {
    return _Array->size();
   }

   unsigned int capacity(void) const
   {
    return _Array->capacity();
   }

   T& operator[](size_t nth_pos)
   {
    return *(_Array->_First + nth_pos);
   }

   const T& operator[](size_t nth_pos) const
   {
    return *(_Array->_First + nth_pos);
   }

   size_t where(const T& t) const
   {
    return _Array->where(t);
   }

   void reserve(size_t size)
   {
    _Array->reserve(size);
   }

   void removeAll(void)
   {
    _Array->removeAll();
   }

   void insert(const T val)
   {
    _Array->insert(val);
   }

   T* ptr()
   {
    return _Array->_First;
   }

   const T* ptr() const
   {
    return _Array->_First;
   }

  protected:

    SharedArrayT*  _Array;

}; // class Array

                                                                                       

/** \brief A STL vector like class that holds and manipulates non-pointer types.
*/
template<typename T> class  Array<T*>
{
  
  friend class ArrayIterator<T*>;
  
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::SharedArray TPayload;
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::Read    TRead;
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::Write   TWrite;

  public:

   typedef typename ::NxOgre::ArrayIterator<T*> Iterator;

   Array(void)
   {
    _T = new TPayload(::NxOgre::Classes::USER_CLASS);
    _Usage = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_ArrayReferenceCounter);

//::NxOgre::Memory::allocate(sizeof(RefT), ::NxOgre::Classes::_ArrayReferenceCounter);
    (*_Usage) = 1;
   };
  
   Array(int type)
   {
    _T = new TPayload(type);
    _Usage = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_ArrayReferenceCounter);
    (*_Usage) = 1;
   };

   Array(const Array<T*>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    (*_Usage)++;
   }

  ~Array(void)
   {
    if(--(*_Usage) == 0)
    {
     ::NxOgre::Memory::unallocate(_Usage);
     delete _T;
    }
   }

   Array<T*>& operator=(const Array<T*>& other)
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
    return TRead::size(_T);
   }

   size_t capacity(void) const
   {
    return TRead::capacity(_T);
   }

   T* operator[](size_t nth_pos)
   {
    return *(_T->_First + nth_pos);
   }

   const T* operator[](size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   size_t where(const T* t) const
   {
    return TRead::where(_T, t);
   }

   void insert(T* t)
   {
    TWrite::insert(_T, t);
   }

   void removeAll(void)
   {
    TWrite::removeAll(_T, false);
   }

   void destroyAll(void)
   {
    TWrite::removeAll(_T, true);
   }

   Iterator getIterator(void)
   {
    return Iterator(*this);
   }
   
   void remove(size_t nthPos)
   {
    TWrite::remove(_T, nthPos, false);
   }
   
   void remove(T* t)
   {
    TWrite::remove(_T, TRead::where(_T, t), false);
   }
   
  protected:

    TPayload*       _T;
    RefT*          _Usage;

}; // class Array<T*>

                                                                                       

/** \brief A STL vector like class that holds non-pointer types.
*/
template<typename T> class  ConstantArray
{
  friend class ArrayIterator<T>;
  
  typedef typename ::NxOgre::Functions::ArrayFunctions<T>::SharedArray TPayload;
  typedef typename ::NxOgre::Functions::ArrayFunctions<T>::Read    TRead;

  public:

   ConstantArray(const Array<T>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    if (other._Usage)
     (*_Usage)++;
   }

   ConstantArray(const ConstantArray<T>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    if (other._Usage)
     (*_Usage)++;
   }

  ~ConstantArray(void)
   {
    --(*_Usage);
   }

   ConstantArray<T>& operator=(const ConstantArray<T>& other)
   {
    --(*_Usage);
    _T      = other._T;
    _Usage  = other._Usage;
    (*_Usage)++;
    return *this;
   }

   size_t size(void) const
   {
    return TRead::size(_T);
   }

   size_t capacity(void) const
   {
    return TRead::capacity(_T);
   }

   T& operator[](size_t nth_pos)
   {
    return *(_T->_First + nth_pos);
   }

   const T& operator[](size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   size_t where(const T& t) const
   {
    return TRead::where(_T, t);
   }

  protected:

    TPayload*       _T;
    RefT*          _Usage;

}; // class Array

                                                                                       

/** \brief A STL vector like class that holds non-pointer types.
*/
template<typename T> class  ConstantArray<T*>
{
  
  friend class ArrayIterator<T*>;
  
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::SharedArray TPayload;
  typedef typename ::NxOgre::Functions::ArrayFunctions<T*>::Read        TRead;

  public:

   typedef typename ::NxOgre::ArrayIterator<T*> Iterator;

   ConstantArray(const Array<T*>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    (*_Usage)++;
   }

   ConstantArray(const ConstantArray<T*>& other)
   {
    _T     = other._T;
    _Usage = other._Usage;
    (*_Usage)++;
   }

  ~ConstantArray(void)
   {
    --(*_Usage);
   }

   ConstantArray<T*>& operator=(const ConstantArray<T*>& other)
   {
    --(*_Usage);
    _T      = other._T;
    _Usage  = other._Usage;
    (*_Usage)++;
    return *this;
   }

   size_t size(void) const
   {
    return TRead::size(_T);
   }

   size_t capacity(void) const
   {
    return TRead::capacity(_T);
   }

   T* operator[](size_t nth_pos)
   {
    return *(_T->_First + nth_pos);
   }

   const T* operator[](size_t nth_pos) const
   {
    return *(_T->_First + nth_pos);
   }

   size_t where(T* t) const
   {
    return TRead::where(_T, t);
   }

   void insert(T* t)
   {
    TWrite::insert(_T, t);
   }

   Iterator getIterator(void)
   {
    return Iterator(*this);
   }

  protected:

    TPayload*       _T;
    RefT* _Usage;

}; // class Array<T*>

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

#ifndef NXOGRE_REF_VECTOR_H
#define NXOGRE_REF_VECTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerFunctions.h"
#include <vector>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename type> class ref_vector;
template<typename type> class ref_vector_iterator;
template<typename type> class const_ref_vector_iterator;

template<typename type> class ref_vector
{
  
 public:

  friend class const_ref_vector_iterator<type>;
  friend class ref_vector_iterator<type>;

  typedef type                             type;

  typedef type*                            type_ref;
  
  typedef std::vector<type_ref>            vector_type;
  
  typedef ref_vector_iterator<type>        iterator_t;
  
  typedef const_ref_vector_iterator<type>  const_iterator_t;
  
  ref_vector(size_t reserve_size = 2) : vector()
  {
   if (reserve_size)
    reserve(reserve_size);
  }
  
 ~ref_vector()
  {
   clear();
  }
  
  iterator_t iterator()
  {
   return iterator_t(*this);
  }
  
  const_iterator_t const_iterator()
  {
   return const_iterator_t(*this);
  }
  
  template<class Each>
  void each(Each each)
  {
   for (vector_type::const_iterator it = vector.begin(); it != vector.end(); ++it)
    each((*it));
  }

  size_t capacity() const
  {
   return vector.capacity();
  }
  
  void reserve(size_t reserve_size)
  {
   vector.reserve(reserve_size);
  }
  
  size_t size() const
  {
   return vector.size();
  }
  
  type_ref at(size_t n)
  {
   return vector.at(n);
  }
  
  type_ref operator[](size_t n)
  {
   return vector.at(n);
  }

  const type_ref at(size_t n) const
  {
   return vector.at(n);
  }
  
  const type_ref operator[](size_t n) const
  {
   return vector.at(n);
  }

  bool empty() const
  {
   return vector.empty();
  }
  
  type_ref front()
  {
   if (vector.empty())
    return 0;
   
   return (*vector.begin());
  }

  const type_ref front() const
  {
   if (vector.empty())
    return 0;
   
   return (*vector.begin());
  }

  type_ref back()
  {
   if (vector.empty())
    return 0;
   
   return (*--vector.end());
  }
  
  const type_ref back() const
  {
   if (vector.empty())
    return 0;
   
   return (*--vector.end());
  }
  
  // Add a new ref to the end of the vector.
  void push_back(type_ref val)
  {
   vector.push_back(val);
  }
  
  // Erase the last ref in the vector, and delete it.
  void pop_back()
  {
   if (vector.empty())
    return;
   
   type_ref ref = back();
   vector.pop_back();
   Functions::safe_delete<type>(ref);
  }
  
  // Sort the pointers in the vector.
  void sort()
  {
   std::sort(vector.begin(), vector.end());
  }

  // Erase a pointer from the vector, but don't delete it, and return pointer.
  type_ref release(const_ref_vector_iterator<type>& it)
  {
   type_ref ref = (*it);
   vector.erase(it);
   return ref;
  }
  
  // Erase a pointer from the vector, but don't delete it, and return pointer.
  void release(type_ref ref)
  {
   if (ref == 0)
    return;
   for (vector_type::iterator it = vector.begin(); it != vector.end(); ++it)
   {
    if ((*it) == ref)
    {
     vector.erase(it);
     break;
    }
   }
  }

  // Erase a pointer from the vector then delete it.
  void erase(iterator_t& it)
  {
   type_ref ref = (*it);
   vector.erase(it);
  }
/*
  // Erase a pointer from the vector then delete it.
  void erase(type_ref ref)
  {
   if (ref == 0)
    return;
   for (vector_type::iterator it = vector.begin(); it != vector.end(); ++it)
   {
    if ((*it) == ref)
    {
     vector.erase(it);
     break;
    }
   }
  }*/
  
  // Erase all pointers from the vector
  void clear()
  {
   vector.clear();
  }
  
  
 private:
  
  vector_type vector;
  
};



                                                                                                      



template<typename type> class const_ref_vector_iterator
{
 public:
  
  friend class ref_vector<type>;

  typedef type*                                                 type_ref;
  typedef ref_vector<type>                                      ref_vector_type;
  typedef typename std::vector<type*>::const_iterator           iterator_t;
  
  const_ref_vector_iterator()
  {
  }
  
  const_ref_vector_iterator(const ref_vector_type& vec)
  : _begin(vec.vector.begin()), _end(vec.vector.end()), _current(_begin) 
  {
  }

  const_ref_vector_iterator<type> operator=(const ref_vector_type& vec)
  {
   _begin = vec.vector.begin();
   _end = vec.vector.end();
   _current = _current;
  }

  type_ref operator->()
  {
   return (*_current);
  }
  
  type_ref operator*()
  {
   return (*_current);
  }

  void operator++()
  {
   _current++;
  }
  
  void operator++(int)
  {
   ++_current;
  }
  
  iterator_t& end()
  {
   return _end;
  }

  operator iterator_t&()
  {
   return _current;
  }
  
  operator iterator_t&() const
  {
   return _current;
  }

  bool operator !=(const iterator_t& it) const
  {
   return _current != it;
  }

  bool operator ==(const iterator_t& it) const
  {
   return _current == it;
  }
 private:
  
  iterator_t _begin, _end, _current;
  
};



                                                                                                      



template<typename type> class ref_vector_iterator
{
 public:
  
  friend class ref_vector<type>;

  typedef type*                                                 type_ref;
  typedef ref_vector<type>                                      ref_vector_type;
  typedef typename std::vector<type*>::iterator                 iterator_t;
  
  ref_vector_iterator()
  {
  }
  
  ref_vector_iterator(ref_vector_type& vec)
  : _begin(vec.vector.begin()), _end(vec.vector.end()), _current(_begin) 
  {
  }

  ref_vector_iterator<type> operator=(ref_vector_type& vec)
  {
   _begin = vec.vector.begin();
   _end = vec.vector.end();
   _current = _current;
  }

  type_ref operator->()
  {
   return (*_current);
  }
  
  type_ref operator*()
  {
   return (*_current);
  }

  void operator++()
  {
   _current++;
  }
  
  void operator++(int)
  {
   ++_current;
  }
  
  iterator_t& end()
  {
   return _end;
  }

  operator iterator_t&()
  {
   return _current;
  }
  
  operator iterator_t&() const
  {
   return _current;
  }

  bool operator !=(const iterator_t& it) const
  {
   return _current != it;
  }

  bool operator ==(const iterator_t& it) const
  {
   return _current == it;
  }
 private:
  
  iterator_t _begin, _end, _current;
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

#ifndef NXOGRE_PTR_VECTOR_H
#define NXOGRE_PTR_VECTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerFunctions.h"
#include <vector>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename type> class ptr_vector;
template<typename type> class ptr_vector_iterator;
template<typename type> class const_ptr_vector_iterator;

template<typename type> class NxOgrePublicTemplateClass ptr_vector
{
  
 public:

  friend class const_ptr_vector_iterator<type>;
  friend class ptr_vector_iterator<type>;

  typedef type                             type;

  typedef type*                            type_ptr;
  
  typedef std::vector<type_ptr>            vector_type;
  
  typedef ptr_vector_iterator<type>        iterator_t;
  
  typedef const_ptr_vector_iterator<type>  const_iterator_t;
  
  ptr_vector(size_t reserve_size = 2) : vector()
  {
   if (reserve_size)
    reserve(reserve_size);
  }
  
 ~ptr_vector()
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
  
  type_ptr at(size_t n)
  {
   return vector.at(n);
  }
  
  type_ptr operator[](size_t n)
  {
   return vector.at(n);
  }

  const type_ptr at(size_t n) const
  {
   return vector.at(n);
  }
  
  const type_ptr operator[](size_t n) const
  {
   return vector.at(n);
  }

  bool empty() const
  {
   return vector.empty();
  }
  
  type_ptr front()
  {
   if (vector.empty())
    return 0;
   
   return (*vector.begin());
  }

  const type_ptr front() const
  {
   if (vector.empty())
    return 0;
   
   return (*vector.begin());
  }

  type_ptr back()
  {
   if (vector.empty())
    return 0;
   
   return (*--vector.end());
  }
  
  const type_ptr back() const
  {
   if (vector.empty())
    return 0;
   
   return (*--vector.end());
  }
  
  // Add a new ptr to the end of the vector.
  void push_back(type_ptr val)
  {
   vector.push_back(val);
  }
  
  // Erase the last ptr in the vector, and delete it.
  void pop_back()
  {
   if (vector.empty())
    return;
   
   type_ptr ptr = back();
   vector.pop_back();
   Functions::safe_delete<type>(ptr);
  }
  
  // Sort the pointers in the vector.
  void sort()
  {
   std::sort(vector.begin(), vector.end());
  }

  // Erase a pointer from the vector, but don't delete it, and return pointer.
  type_ptr release(const_ptr_vector_iterator<type>& it)
  {
   type_ptr ptr = (*it);
   vector.erase(it);
   return ptr;
  }

  // Erase a pointer from the vector then delete it.
  void erase(iterator_t& it)
  {
   type_ptr ptr = (*it);
   vector.erase(it);
   Functions::safe_delete<type>(ptr);
  }

  // Erase a pointer from the vector then delete it.
  void erase(type_ptr ptr)
  {
   if (ptr == 0)
    return;
   for (vector_type::iterator it = vector.begin(); it != vector.end(); ++it)
   {
    if ((*it) == ptr)
    {
     vector.erase(it);
     break;
    }
   }
   Functions::safe_delete<type>(ptr);
  }
  
  // Erase all pointers from the vector then delete them.
  void clear()
  {
   for (vector_type::iterator it = vector.begin(); it != vector.end(); it++)
    Functions::safe_delete<type>((*it));
   
   vector.clear();
  }
  
  // Erase all pointers from the vector but don't delete them.
  void release_all()
  {
   vector.clear();
  }
  
  
 private:
  
  vector_type vector;
  
};



                                                                                                      



template<typename type> class NxOgrePublicTemplateClass const_ptr_vector_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_vector<type>                                      ptr_vector_type;
  typedef typename std::vector<type*>::const_iterator           iterator_t;
  
  const_ptr_vector_iterator()
  {
  }
  
  const_ptr_vector_iterator(const ptr_vector_type& vec)
  : _begin(vec.vector.begin()), _end(vec.vector.end()), _current(_begin) 
  {
  }

  const_ptr_vector_iterator<type> operator=(const ptr_vector_type& vec)
  {
   _begin = vec.vector.begin();
   _end = vec.vector.end();
   _current = _current;
  }

  type_ptr operator->()
  {
   return (*_current);
  }
  
  type_ptr operator*()
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



                                                                                                      



template<typename type> class NxOgrePublicTemplateClass ptr_vector_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_vector<type>                                      ptr_vector_type;
  typedef typename std::vector<type*>::iterator                 iterator_t;
  
  ptr_vector_iterator()
  {
  }
  
  ptr_vector_iterator(ptr_vector_type& vec)
  : _begin(vec.vector.begin()), _end(vec.vector.end()), _current(_begin) 
  {
  }

  ptr_vector_iterator<type> operator=(ptr_vector_type& vec)
  {
   _begin = vec.vector.begin();
   _end = vec.vector.end();
   _current = _current;
  }

  type_ptr operator->()
  {
   return (*_current);
  }
  
  type_ptr operator*()
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

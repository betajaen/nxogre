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

                                                                                       

#ifndef NXOGRE_ITERATORS_H
#define NXOGRE_ITERATORS_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       


/** \brief Forward iterator for Containers
    \usage
     <code>
        vector_iterator<T> it = ...
        
        for(it.begin(); it != it.end(); ++it)
         it->function();
     </code>
*/
template<typename value_type> class vector_iterator
{
 public:
  
  typedef value_type                                       type;
  typedef boost::ptr_vector<value_type>                    container_type;
  typedef typename boost::ptr_vector<value_type>::iterator iterator_type;
  
  vector_iterator(const container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  vector_iterator(container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  void begin()
  {
   mCurrent = mBegin;
  }
  
  const iterator_type& end() const
  {
   return mEnd;
  }
  
  value_type* operator->()
  {
   return (&*mCurrent);
  }
  
  value_type* operator*()
  {
   return (&*mCurrent);
  }

  void operator++()
  {
   mCurrent++;
  }
  
  void operator++(int)
  {
   ++mCurrent;
  }

  operator iterator_type&()
  {
   return mCurrent;
  }
  
  operator iterator_type&() const
  {
   return mCurrent;
  }
  
  bool operator !=(const iterator_type& it) const
  {
   return mCurrent != it;
  }

  bool operator ==(const iterator_type& it) const
  {
   return mCurrent == it;
  }
  
 protected:
  
  iterator_type mBegin, mEnd, mCurrent;
};

/** \brief Reverse iterator for Containers
    \usage
     <code>
        ReverseContainerIterator<T> it = ...
        
        for(it.begin(); it != it.end(); ++it)
         it->function();
     </code>
*/
template<typename value_type> class ReverseContainerIterator
{
 public:
  
  typedef value_type                                       type;
  typedef boost::ptr_vector<value_type>                    container_type;
  typedef typename boost::ptr_vector<value_type>::reverse_iterator iterator_type;
  
  ReverseContainerIterator(const container_type& vector)
  : mBegin(vector.rbegin()), mEnd(vector.rend()), mCurrent(mBegin) {}
  
  ReverseContainerIterator(container_type& vector)
  : mBegin(vector.rbegin()), mEnd(vector.rend()), mCurrent(mBegin) {}
  
  void begin()
  {
   mCurrent = mBegin;
  }
  
  const iterator_type& end() const
  {
   return mEnd;
  }
  
  void operator++()
  {
   mCurrent++;
  }
  
  void operator++(int)
  {
   ++mCurrent;
  }

  operator iterator_type&()
  {
   return mCurrent;
  }
  
  operator iterator_type&() const
  {
   return mCurrent;
  }
  
  value_type* operator->()
  {
   return (&*mCurrent);
  }
  
  value_type* operator*()
  {
   return (&*mCurrent);
  }

  bool operator !=(const iterator_type& it) const
  {
   return mCurrent != it;
  }

  bool operator ==(const iterator_type& it) const
  {
   return mCurrent == it;
  }
  
 protected:
  
  iterator_type mBegin, mEnd, mCurrent;
};

/** \brief Forward iterator for Associative Containers
    \usage
     <code>
        map_iterator<K,T> it = ...
        
        for(it.begin(); it != it.end(); ++it)
         it->function();
     </code>
*/
template<typename key_type, typename value_type> class map_iterator
{
 public:
  
  typedef key_type                                                 key_type;
  typedef value_type                                               value_type;
  typedef boost::ptr_map<key_type, value_type>                               container_type;
  typedef typename boost::ptr_map<key_type, value_type>::iterator            iterator_type;
  
  map_iterator(const container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  map_iterator(container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  void begin()
  {
   mCurrent = mBegin;
  }
  
  const iterator_type& end() const
  {
   return mEnd;
  }
  
  void operator++()
  {
   mCurrent++;
  }
  
  void operator++(int)
  {
   ++mCurrent;
  }

  operator iterator_type&()
  {
   return mCurrent;
  }
  
  operator iterator_type&() const
  {
   return mCurrent;
  }
  
  value_type* operator->()
  {
   return &*(*mCurrent).second;
  }

  value_type* operator*()
  {
   return (*mCurrent).second;
  }

  bool operator !=(const iterator_type& it) const
  {
   return mCurrent != it;
  }

  bool operator ==(const iterator_type& it) const
  {
   return mCurrent == it;
  }
  
 protected:
  
  iterator_type mBegin, mEnd, mCurrent;
};

/** \brief Forward iterator for Multi Associative Containers
    \usage
     <code>
        map_iterator<K,T> it = ...
        
        for(it.begin(); it != it.end(); ++it)
         it->function();
     </code>
*/
template<typename key_type, typename value_type> class multimap_iterator
{
 public:
  
  typedef key_type                                                        key_type;
  typedef value_type                                                      value_type;
  typedef boost::ptr_multimap<key_type, value_type>                       container_type;
  typedef typename boost::ptr_multimap<key_type, value_type>::iterator    iterator_type;
  
  multimap_iterator(const container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  multimap_iterator(container_type& vector)
  : mBegin(vector.begin()), mEnd(vector.end()), mCurrent(mBegin) {}
  
  void begin()
  {
   mCurrent = mBegin;
  }
  
  const iterator_type& end() const
  {
   return mEnd;
  }
  
  void operator++()
  {
   mCurrent++;
  }
  
  void operator++(int)
  {
   ++mCurrent;
  }

  operator iterator_type&()
  {
   return mCurrent;
  }
  
  operator iterator_type&() const
  {
   return mCurrent;
  }
  
  value_type* operator->()
  {
   return &*(*mCurrent).second;
  }

  value_type* operator*()
  {
   return (*mCurrent).second;
  }

  bool operator !=(const iterator_type& it) const
  {
   return mCurrent != it;
  }

  bool operator ==(const iterator_type& it) const
  {
   return mCurrent == it;
  }
  
 protected:
  
  iterator_type mBegin, mEnd, mCurrent;
};



                                                                                       

} // namespace NxOgre

                                                                                       

#endif

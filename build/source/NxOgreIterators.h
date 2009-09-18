/** File: NxOgreIterators.h
    Created on: 17-Sept-09
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

#ifndef NXOGRE_ITERATORS_H
#define NXOGRE_ITERATORS_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre_Namespace
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



                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif

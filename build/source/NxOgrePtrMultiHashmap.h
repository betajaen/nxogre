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

                                                                                       

#ifndef NXOGRE_PTR_MULTIHASHMAP_H
#define NXOGRE_PTR_MULTIHASHMAP_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerFunctions.h"
#include <map>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename type> class ptr_multihashmap;
template<typename type> class ptr_multihashmap_iterator;
template<typename type> class const_ptr_multihashmap_iterator;

                                                                                       

template<typename type> class ptr_multihashmap
{
  
 public:
  
  friend class ptr_multihashmap_iterator<type>;
  friend class const_ptr_multihashmap_iterator<type>;
  
  typedef StringHash                            key_type;
  
  typedef type                                  type;
  
  typedef type*                                 type_ptr;
  
  typedef std::multimap<key_type, type_ptr>     multimap_type;
  
  typedef ptr_multihashmap_iterator<type>       iterator_t;
  
  typedef const_ptr_multihashmap_iterator<type> const_iterator_t;
  
  // constructor
  ptr_multihashmap() : multimap()
  {
    
  }
  
  // destructor
  ~ptr_multihashmap()
  {
   clear();
  }
  
  // get a iterator.
  iterator_t iterator()
  {
   return iterator_t(*this);
  }
  
  // get a constant iterator.
  const_iterator_t const_iterator()
  {
   return const_iterator_t(*this);
  }
  
  // loop through each pointer in the multimap, and pass it to an operator()(type*) in a class "Each".
  template<class Each> void each(Each each)
  {
   for (multimap_type::const_iterator it = multimap.begin(); it != multimap.end(); ++it)
    each((*it).second);
  }
  
  // size of the multimap
  size_t size() const
  {
   return multimap.size();
  }
  
  // fetch using a hash.
  type_ptr at(const key_type& key)
  {
   multimap_type::iterator it = multimap.find(key);
   if (it == multimap.end())
    return 0;
   
   return (*it).second;
  }
  
  // fetch using a hash.
  const type_ptr at(const key_type& key) const
  {
   multimap_type::const_iterator it = multimap.find(key);
   if (it == multimap.end())
    return 0;
   
   return (*it).second;
  }
  
  // fetch using a string.
  type_ptr at(const String&)
  {
   return at(Functions::HashString(key));
  }
  
  // fetch using a string.
  const type_ptr at(const String&) const
  {
   return at(Functions::HashString(key));
  }

  // fetch using a string.
  type_ptr at(const char* key)
  {
   return at(Functions::HashString(key));
  }
  
  // fetch using a string.
  const type_ptr at(const char* key) const
  {
   return at(Functions::HashString(key));
  }
  
  // operator[] with a hash.
  type_ptr operator[](key_type& key)
  {
   multimap_type::iterator it = multimap.find(key);
   if (it == multimap.end())
    return 0;
   
   return (*it).second;
  }
  
  // operator[] with a hash.
  const type_ptr operator[](key_type& key) const
  {
   multimap_type::const_iterator it = multimap.find(key);
   if (it == multimap.end())
    return 0;
   
   return (*it).second;
  }
 
  // operator[] with a const char* as string.
  type_ptr operator[](const char* key_name)
  {
   return operator[](Functions::HashString(key_name));
  }

  // operator[] with a const char* as string.
  const type_ptr operator[](const char* key_name) const
  {
   return operator[](Functions::HashString(key_name));
  }
  
  // Is the multimap empty?
  bool empty() const
  {
   return multimap.empty();
  }
  
  // Insert a pointer into the multimap, using a prehashed key.
  void insert(const key_type& key, type_ptr value)
  {
   multimap.insert(std::pair<key_type, type_ptr>(key, value));
  }
  
  // Insert a pointer into the multimap, using a String which is hashed.
  void insert(const String& key, type_ptr value)
  {
   StringHash key = Functions::StringHash(unhashed_string_key);
   multimap.insert(std::pair<key_type, type_ptr>(key, value));
  }
  
  // Erase a pointer from the multimap then delete it.
  void erase(key_type& key) 
  {
   multimap_type::const_iterator it = multimap.find(key);
   if (it == multimap.end())
    return;
   
   type_ptr ptr = (*it);
   multimap.erase(it);
   Functions::safe_delete<type>(ptr);
  }

  // Erase a pointer from the multimap then delete it.
  void erase(const key_type& key) 
  {
   multimap_type::const_iterator it = multimap.find(key);
   if (it == multimap.end())
    return;
   
   type_ptr ptr = (*it).second;
   multimap.erase(it);
   Functions::safe_delete<type>(ptr);
  }
  
  // Erase a pointer from the multimap then delete it.
  void erase(type* ptr)
  {
   for (multimap_type::iterator it = multimap.begin(); it != multimap.end(); ++it)
    if ((*it).second == ptr)
    {
     multimap.erase(it);
     Functions::safe_delete<type>(ptr);
    }
  }

  // delete all pointers and clear the multimap.
  void clear()
  {
   for (multimap_type::iterator it = multimap.begin(); it != multimap.end(); ++it)
    Functions::safe_delete<type>((*it).second);
   
   multimap.clear();
  }
  
 protected:
  
  multimap_type  multimap;
  
};



                                                                                                      



template<typename type> class const_ptr_multihashmap_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_multihashmap<type>                                     ptr_multihashmap_type;
  typedef typename std::multimap<StringHash, type*>::const_iterator  iterator_t;
  
  const_ptr_multihashmap_iterator()
  {
  }
  
  const_ptr_multihashmap_iterator(const ptr_multihashmap_type& vec)
  : _begin(vec.multimap.begin()), _end(vec.multimap.end()), _current(_begin) 
  {
  }

  const_ptr_multihashmap_iterator<type>& operator=(const ptr_multihashmap_type& multimap)
  {
   _begin = multimap.multimap.begin();
   _end = multimap.multimap.end();
   _current = _current;
   return *this;
  }

  type_ptr operator->()
  {
   return (*_current).second;
  }
  
  type_ptr operator*()
  {
   return (*_current).second;
  }
  
  const StringHash hash() const
  {
   return (*_current).first;
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



                                                                                                      



template<typename type> class ptr_multihashmap_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_multihashmap<type>                                     ptr_multihashmap_type;
  typedef typename std::multimap<StringHash, type*>::iterator        iterator_t;
  
  ptr_multihashmap_iterator()
  {
  }
  
  ptr_multihashmap_iterator(ptr_multihashmap_type& multimap)
  : _begin(multimap.multimap.begin()), _end(multimap.multimap.end()), _current(_begin) 
  {
  }

  ptr_multihashmap_iterator<type>& operator=(ptr_multihashmap_type& multimap)
  {
   _begin = multimap.multimap.begin();
   _end = multimap.multimap.end();
   _current = _current;
   return *this;
  }
  
  StringHash hash() const
  {
   return (*_current).first;
  }

  type_ptr operator->()
  {
   return (*_current).second;
  }
  
  type_ptr operator*()
  {
   return (*_current).second;
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

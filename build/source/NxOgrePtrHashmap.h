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

                                                                                       

#ifndef NXOGRE_PTR_HASHMAP_H
#define NXOGRE_PTR_HASHMAP_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerFunctions.h"
#include "NxOgreString.h"
#include <map>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename type> class ptr_hashmap;
template<typename type> class ptr_hashmap_iterator;
template<typename type> class const_ptr_hashmap_iterator;


template<typename type> class ptr_hashmap
{
  
 public:
  
  friend class ptr_hashmap_iterator<type>;
  friend class const_ptr_hashmap_iterator<type>;
  
  typedef StringHash                       key_type;
  
  typedef type                             type;
  
  typedef type*                            type_ptr;
  
  typedef std::map<key_type, type_ptr>     map_type;
  
  typedef ptr_hashmap_iterator<type>       iterator_t;
  
  typedef const_ptr_hashmap_iterator<type> const_iterator_t;
  
  // constructor
  ptr_hashmap() : map()
  {
    
  }
  
  // destructor
  ~ptr_hashmap()
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
  
  // loop through each pointer in the map, and pass it to an operator()(type*) in a class "Each".
  template<class Each> void each(Each each)
  {
   for (map_type::const_iterator it = map.begin(); it != map.end(); ++it)
    each((*it).second);
  }
  
  // size of the map
  size_t size() const
  {
   return map.size();
  }
  
  // fetch using a hash.
  type_ptr at(const key_type& key)
  {
   map_type::iterator it = map.find(key);
   if (it == map.end())
    return 0;
   
   return (*it).second;
  }
  
  // fetch using a hash.
  const type_ptr at(const key_type& key) const
  {
   map_type::const_iterator it = map.find(key);
   if (it == map.end())
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
   map_type::iterator it = map.find(key);
   if (it == map.end())
    return 0;
   
   return (*it).second;
  }
  
  // operator[] with a hash.
  const type_ptr operator[](key_type& key) const
  {
   map_type::const_iterator it = map.find(key);
   if (it == map.end())
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
  
  // Is the map empty?
  bool empty() const
  {
   return map.empty();
  }
  
  // Insert a pointer into the map, using a prehashed key.
  void insert(const key_type& key, type_ptr value)
  {
   map.insert(std::pair<key_type, type_ptr>(key, value));
  }
  
  // Insert a pointer into the map, using a String which is hashed.
  void insert(const String& key, type_ptr value)
  {
   const StringHash key = Functions::StringHash(unhashed_string_key);
   map.insert(std::pair<key_type, type_ptr>(key, value));
  }
  
  // Erase a pointer from the map then delete it.
  void erase(key_type& key) 
  {
   map_type::const_iterator it = map.find(key);
   if (it == map.end())
    return;
   
   type_ptr ptr = (*it).second;
   map.erase(it);
   Functions::safe_delete<type>(ptr);
  }
  
  // Erase a pointer from the map then delete it.
  void erase(const key_type& key) 
  {
   map_type::const_iterator it = map.find(key);
   if (it == map.end())
    return;
   
   type_ptr ptr = (*it).second;
   map.erase(it);
   Functions::safe_delete<type>(ptr);
  }

  // delete all pointers and clear the map.
  void clear()
  {
   for (map_type::iterator it = map.begin(); it != map.end(); ++it)
    Functions::safe_delete<type>((*it).second);
   
   map.clear();
  }
  
 protected:
  
  map_type  map;
  
};



                                                                                                      



template<typename type> class const_ptr_hashmap_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_hashmap<type>                                     ptr_hashmap_type;
  typedef typename std::map<StringHash, type*>::const_iterator  iterator_t;
  
  const_ptr_hashmap_iterator()
  {
  }
  
  const_ptr_hashmap_iterator(const ptr_hashmap_type& vec)
  : _begin(vec.map.begin()), _end(vec.map.end()), _current(_begin) 
  {
  }

  const_ptr_hashmap_iterator<type>& operator=(const ptr_hashmap_type& map)
  {
   _begin = map.map.begin();
   _end = map.map.end();
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



                                                                                                      



template<typename type> class ptr_hashmap_iterator
{
 public:
  
  friend class ptr_vector<type>;

  typedef type*                                                 type_ptr;
  typedef ptr_hashmap<type>                                     ptr_hashmap_type;
  typedef typename std::map<StringHash, type*>::iterator        iterator_t;
  
  ptr_hashmap_iterator()
  {
  }
  
  ptr_hashmap_iterator(ptr_hashmap_type& map)
  : _begin(map.map.begin()), _end(map.map.end()), _current(_begin) 
  {
  }

  ptr_hashmap_iterator<type>& operator=(ptr_hashmap_type& map)
  {
   _begin = map.map.begin();
   _end = map.map.end();
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

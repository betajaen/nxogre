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

                                                                                       

#ifndef NXOGRE_MAP_H
#define NXOGRE_MAP_H

                                                                                       

#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"

#include <iostream>
#include <map>
#include <algorithm>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename K, typename T> class map_iterator;

template<typename K, typename T, typename garbage_collection = GC::NoGarbageCollection>
class map : protected garbage_collection::template impl_map<K, T>
{

 public:

  map() : container(new std::map<K, T>() )
  { // constructor
  }

  map(const map& other) : container(other.container)
  { // empty constructor.
  }

 ~map()
  {
   if (container.references() == 1)
    remove_all();
  }

  map& operator=(const map& other)
  {
   container = other.container;
   return *this;
  }

  map_iterator<K, T> elements() const
  {
   return map_iterator<K, T>(container->begin(), container->end());
  }

  T& operator[](const K& key)
  {
   return container->operator [](key);
  }

  const T& operator[](const K& key) const
  {
   return container->operator [](key);
  }

  T& at(const K& key)
  {
   return container->operator [](key);
  }

  const T& at(const K& key) const
  {
   return container->operator [](key);
  }

  void insert(const K& key, const T& value)
  {
   container->insert(std::pair<K,T>(key, value));
  }

  void remove(const K& key)
  {
   typename std::map<K, T>::iterator it = container->find(key);
   if (it == container->end())
    return;
   gc_free((*it).second);
   container->erase(it);
  }

  void remove_all()
  {
   gc_free_range(container->begin(), container->end());
   container->clear();
  }

  bool has(const K& search) const
  {
   return container->find(search) != container->end();
  }

  size_t size() const
  {
   return container->size();
  }

  size_t length() const
  {
   return container->size();
  }

 protected:

  SharedPointer< std::map<K, T> > container;

};


template<typename K, typename T, typename garbage_collection>
class map<K, T*, garbage_collection> : protected garbage_collection::template impl_map<K, T*>
{

 public:

  map() : container(new std::map<K, T*>() )
  { // constructor
  }

  map(const map& other) : container(other.container)
  { // empty constructor.
  }

 ~map()
  {
   if (container.references() == 1)
    remove_all();
  }

  map& operator=(const map& other)
  {
   container = other.container;
   return *this;
  }

  map_iterator<K, T*> elements() const
  {
   return map_iterator<K, T*>(container->begin(), container->end());
  }

  T* operator[](const K& key)
  {
   return container->operator [](key);
  }

  const T* operator[](const K& key) const
  {
   return container->operator [](key);
  }

  T* at(const K& key)
  {
   return container->operator [](key);
  }

  const T* at(const K& key) const
  {
   return container->operator [](key);
  }

  void insert(const K& key, T* value)
  {
   container->insert(std::pair<K,T*>(key, value));
  }

  void remove(const K& key)
  {
   typename std::map<K, T*>::iterator it = container->find(key);
   if (it == container->end())
    return;
   gc_free((*it).second);
   container->erase(it);
  }

  void remove_all()
  {
   gc_free_range(container->begin(), container->end());
   container->clear();
  }

  bool has(const K& key) const
  {
   return container->find(key) != container->end();
  }

  size_t size() const
  {
   return container->size();
  }

  size_t length() const
  {
   return container->size();
  }

 protected:

  SharedPointer< std::map<K, T*> > container;

};

                                                                                       

namespace Maps
{

                                                                                       

template<typename K, typename T> T* get_or_null(const NxOgre::map<K,T*>& map, const K& lookFor)
{
 if (map.has(lookFor) == false)
  return NULL;
 return map.at(lookFor);
}

template<typename K, typename T> T* get_or_null(const std::map<K,T*>& map, const K& lookFor)
{
 std::map<K,T*>::const_iterator it = map.find(lookFor);
 if (it == map.end())
  return NULL;
 return (*it).second;
}

template<typename K, typename T> T* get_or_null(NxOgre::map<K,T*>& map, const K& lookFor)
{
 if (map.has(lookFor) == false)
  return NULL;
 return map.at(lookFor);
}

template<typename K, typename T> T* get_or_null(std::map<K,T*>& map, const K& lookFor)
{
 std::map<K,T*>::const_iterator it = map.find(lookFor);
 if (it == map.end())
  return NULL;
 return (*it).second;
}

                                                                                       

}; // namespace Maps

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

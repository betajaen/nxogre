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



#ifndef NXOGRE_MULTIMAP_H
#define NXOGRE_MULTIMAP_H



#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"

#include <iostream>
#include <map>
#include <algorithm>




namespace NxOgre
{



template<typename K, typename T> class multimap_iterator;

template<typename K, typename T, typename garbage_collection = GC::NoGarbageCollection>
class multimap : protected garbage_collection::template impl_map<K, T>
{

 public:

  multimap() : container(new std::multimap<K, T>() )
  { // constructor
  }

  multimap(const multimap& other) : container(other.container)
  { // empty constructor.
  }

 ~multimap()
  {
   if (container.references() == 1)
    remove_all();
  }

  multimap& operator=(const multimap& other)
  {
   container = other.container;
   return *this;
  }

  multimap_iterator<K, T> elements() const
  {
   return multimap_iterator<K, T>(container->begin(), container->end());
  }

  T& operator[](const K& key)
  {
   return container->at(key);
  }

  const T& operator[](const K& key) const
  {
   return container->at(key);
  }

  T& at(const K& key)
  {
   return container->at(key);
  }

  const T& at(const K& key) const
  {
   return container->at(index);
  }

  void insert(const K& key, const T& value)
  {
   container->insert(std::pair<K,T>(key, value));
  }

  void remove(const K& key)
  {
   typename std::multimap<K, T>::iterator it = container->find(key);
   if (key == container->end())
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

  size_t length() const
  {
   return container->length();
  }

 protected:

  SharedPointer< std::multimap<K, T> > container;

};


template<typename K, typename T, typename garbage_collection>
class multimap<K, T*, garbage_collection> : protected garbage_collection::template impl_map<K, T*>
{

 public:

  multimap() : container(new std::multimap<K, T*>() )
  { // constructor
  }

  multimap(const multimap& other) : container(other.container)
  { // empty constructor.
  }

 ~multimap()
  {
   if (container.references() == 1)
    remove_all();
  }

  multimap& operator=(const multimap& other)
  {
   container = other.container;
   return *this;
  }

  multimap_iterator<K, T*> elements() const
  {
   return multimap_iterator<K, T*>(container->begin(), container->end());
  }

  T* operator[](const K& key)
  {
   return container->at(key);
  }

  const T* operator[](const K& key) const
  {
   return container->at(key);
  }

  T* at(const K& key)
  {
   return container->at(key);
  }

  const T* at(const K& key)const
  {
   return container->at(key);
  }

  void insert(const K& key, T* value)
  {
   container->insert(std::pair<K,T*>(key, value));
  }

  void remove_first_of(const K& key)
  {
   typename std::multimap<K, T*>::iterator it = container->find(key);
   if (it == container->end())
    return;
   gc_free((*it).second);
   container->erase(it);
  }

  void remove_all_of(const K& key)
  {
   while(true)
   {
    typename std::multimap<K, T*>::iterator it = container->find(key);
    if (it == container->end())
     return;
    gc_free((*it).second);
    container->erase(it);
   }
  }

  void remove_all()
  {
   gc_free_range(container->begin(), container->end());
   container->clear();
  }

  unsigned int count(const K& key)
  {
   unsigned int ret = 0;
   for (typename std::multimap<K, T*>::iterator it = container->begin(); it != container->end(); it++)
    if ((*it).first == key)
     ret++;
   return ret;
  }

  bool has(const K& search) const
  {
   return container->find(search) != container->end();
  }

  size_t length() const
  {
   return container->length();
  }

 protected:

  SharedPointer< std::multimap<K, T*> > container;

};



} // namespace NxOgre



#endif

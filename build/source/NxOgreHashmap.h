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



#ifndef NXOGRE_HASHMAP_H
#define NXOGRE_HASHMAP_H



#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreHash.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <string>




namespace NxOgre
{


template<typename T> class hashmap_iterator;

template<typename T, typename garbage_collection = GC::NoGarbageCollection>
class hashmap : protected garbage_collection::template impl_map<size_t, T>
{

 public:

  hashmap() : container(new std::map<size_t, T>() )
  { // constructor
  }

  hashmap(const hashmap& other) : container(other.container)
  { // empty constructor.
  }

 ~hashmap()
  {
   if (container.references() == 1)
    remove_all();
  }

  hashmap& operator=(const hashmap& other)
  {
   container(other.container);
   return *this;
  }

  hashmap_iterator<T> elements() const
  {
   return hashmap_iterator<T>(container->begin(), container->end());
  }

  T& operator[](const size_t& key)
  {
   return container->at(key);
  }

  const T& operator[](const size_t& key) const
  {
   return container->at(key);
  }

  T& at(const size_t& key)
  {
   return container->at(key);
  }

  const T& at(const size_t& key) const
  {
   return container->at(index);
  }

  void insert(const size_t& key, const T& value)
  {
   container->insert(std::pair<size_t,T>(key, value));
  }

  void remove(const size_t& key)
  {
   typename std::map<size_t, T>::iterator it = container->find(key);
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

  bool has(const size_t& search) const
  {
   return container->find(search) != container->end();
  }

  size_t size() const
  {
   return container->length();
  }

  size_t length() const
  {
   return container->length();
  }

 protected:

  SharedPointer< std::map<size_t, T> > container;

};


template<typename T, typename garbage_collection>
class hashmap<T*, garbage_collection> : protected garbage_collection::template impl_map<size_t, T*>
{

 public:

  hashmap() : container(new std::map<size_t, T*>() )
  { // constructor
  }

  hashmap(const hashmap& other) : container(other.container)
  { // empty constructor.
  }

 ~hashmap()
  {
   if (container.references() == 1)
    remove_all();
  }

  hashmap& operator=(const hashmap& other)
  {
   container = other.container;
   return *this;
  }

  hashmap_iterator<T*> elements() const
  {
   return hashmap_iterator<T*>(container->begin(), container->end());
  }

  T* operator[](const size_t& key)
  {
   return container->at(key);
  }

  const T* operator[](const size_t& key) const
  {
   return container->at(key);
  }

  T* at(const size_t& key)
  {
   return container->at(key);
  }

  const T* at(const size_t& key)const
  {
   return container->at(key);
  }

  void insert(const size_t& key, T* value)
  {
   container->insert(std::pair<size_t,T*>(key, value));
  }

  void remove(const size_t& key)
  {
   typename std::map<size_t, T*>::iterator it = container->find(key);
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

  bool has(const size_t& key) const
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

  SharedPointer< std::map<size_t, T*> > container;

};



} // namespace NxOgre



#endif

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



#ifndef NXOGRE_MULTIHASHMAP_H
#define NXOGRE_MULTIHASHMAP_H



#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreHash.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <string>




namespace NxOgre
{



template<typename T> class multihashmap_iterator;

template<typename T, typename garbage_collection = GC::NoGarbageCollection>
class multihashmap : protected garbage_collection::template impl_map<size_t, T>
{

 public:

  multihashmap() : container(new std::multimap<size_t, T>() )
  { // constructor
  }

  multihashmap(const multihashmap& other) : container(other.container)
  { // empty constructor.
  }

 ~multihashmap()
  {
   if (container.references() == 1)
    remove_all();
  }

  multihashmap& operator=(const multihashmap& other)
  {
   container = other.container;
   return *this;
  }

  multihashmap_iterator<T> elements() const
  {
   return multihashmap_iterator<T>(container->begin(), container->end());
  }

  void insert(const size_t& key, const T& value)
  {
   container->insert(std::pair<size_t,T>(key, value));
  }

  void remove(const size_t& key, const T& value)
  {
   for (typename std::multimap<size_t, T>::iterator it = container->begin(); it != container->end(); it++)
   {
    if ((*it).first != key)
     continue;

    if ((*it).second != value)
     continue;

    gc_free((*it).second);
    container->erase(it);
    break;
   }

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
   return container->size();
  }

  size_t length() const
  {
   return container->size();
  }

 protected:

  SharedPointer< std::multimap<size_t, T> > container;

};


template<typename T, typename garbage_collection>
class multihashmap<T*, garbage_collection> : protected garbage_collection::template impl_map<size_t, T*>
{

 public:

  multihashmap() : container(new std::multimap<size_t, T*>() )
  { // constructor
  }

  multihashmap(const multihashmap& other) : container(other.container)
  { // empty constructor.
  }

 ~multihashmap()
  {
   if (container.references() == 1)
    remove_all();
  }

  multihashmap& operator=(const multihashmap& other)
  {
   container = other.container;
   return *this;
  }

  multihashmap_iterator<T*> elements() const
  {
   return multihashmap_iterator<T*>(container->begin(), container->end());
  }

  void insert(const size_t& key, T* value)
  {
   container->insert(std::pair<size_t,T*>(key, value));
  }

  void remove(const size_t& key, T* value)
  {
   for (typename std::multimap<size_t, T*>::iterator it = container->begin(); it != container->end(); it++)
   {
    if ((*it).first != key)
     continue;

    if ((*it).second != value)
     continue;

    gc_free((*it).second);
    container->erase(it);
    break;
   }

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

  SharedPointer< std::multimap<size_t, T*> > container;

};



} // namespace NxOgre



#endif

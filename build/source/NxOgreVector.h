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

                                                                                       

#ifndef NXOGRE_VECTOR_H
#define NXOGRE_VECTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreSharedPointer.h"
#include "NxOgreGC.h"

#include <vector>
#include <algorithm>
#include <vector>

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename T> class vector_iterator;

template<typename T, typename garbage_collection = GC::NoGarbageCollection>
class vector : protected garbage_collection::template impl_vector<T>
{

 public:

  static const size_t npos = -1;

  vector() : container(new std::vector<T>() )
  { // constructor
  }

  vector(const vector& other) : container(other.container)
  { // empty constructor.
  }

 ~vector()
  {
   if (container.references() == 1)
    remove_all();
  }

  vector& operator=(const vector& other)
  {
   container = other.container;
   return *this;
  }

  vector_iterator<T> elements() const
  {
   return vector_iterator<T>(container->begin(), container->end());
  }

  T& operator[](size_t index)
  {
   return container->at(index);
  }

  const T& operator[](size_t index) const
  {
   return container->at(index);
  }

  T& at(size_t index)
  {
   return container->at(index);
  }

  const T& at(size_t index) const
  {
   return container->at(index);
  }

  void push_back(const T& value)
  {
   container->push_back(value);
  }

  void pop_back()
  {
   typename std::vector<T>::iterator it = container->end() - 1;
   gc_free((*it));
   container->pop_back();
  }

  void remove(unsigned int index)
  {
   typename std::vector<T>::iterator it = container->begin() + index;
   gc_free((*it));
   container->erase(it);
  }

  void remove_all()
  {
   gc_free_range(container->begin(), container->end());
   container->clear();
  }

  size_t index(const T& search) const
  {
   typename std::vector<T>::iterator  it = std::find(container->begin(), container->end(), search);
   if (it == container->end())
    return npos;
   return it - container->begin();
  }

  bool has(const T& search) const
  {
   return std::find(container->begin(), container->end(), search) != container->end();
  }

  size_t size() const
  {
   return container->size();
  }

  size_t length() const
  {
   return container->size();
  }

  std::string join(const std::string& seperator = ", ") const
  {
   std::ostringstream stream;
   for (std::vector<T>::const_iterator it = container->begin(); it != container->end(); ++it)
    stream << (*it) << seperator;
   std::string out = stream.str();
   return out.substr(0, out.length() - seperator.length());
  }

  std::string to_s() const
  {
   return join();
  }

 /*! function. split
     desc.
         Split a string by a seperator and convert them into T then append them into a new vector, in the order of the string.
 */
  static vector<T, garbage_collection> split(const std::string& string, const std::string& sep = " ")
  {
   vector<T, garbage_collection> vec;
   
   size_t b = string.find_first_not_of(sep, 0);
   size_t a = string.find_first_of(sep, b);
   
   T val;
   while (a != std::string::npos || b != std::string::npos)
   {
    std::stringstream s(string.substr(b, a - b));
    s >> val;
    vec.push_back(val);
    b = string.find_first_not_of(sep, a);
    a = string.find_first_of(sep, b);
   }
   
   return vec;
  }

 protected:

  SharedPointer< std::vector<T> > container;

};


template<typename T, typename garbage_collection>
class vector<T*, garbage_collection> : protected garbage_collection::template impl_vector<T*>
{

 public:

  static const size_t npos = -1;

  vector() : container(new std::vector<T*>() )
  { // constructor
  }

  vector(const vector& other) : container(other.container)
  { // empty constructor.
  }

 ~vector()
  {
   if (container.references() == 1)
    remove_all();
  }

  vector& operator=(const vector& other)
  {
   container = other.container;
   return *this;
  }

  vector_iterator<T*> elements() const
  {
   return vector_iterator<T*>(container->begin(), container->end());
  }

  T* operator[](size_t index)
  {
   return container->at(index);
  }

  const T* operator[](size_t index) const
  {
   return container->at(index);
  }

  T* at(size_t index)
  {
   return container->at(index);
  }

  const T* at(size_t index) const
  {
   return container->at(index);
  }

  void push_back(T* value)
  {
   container->push_back(value);
  }

  void pop_back()
  {
   typename std::vector<T*>::iterator it = container->end() - 1;
   gc_free((*it));
   container->pop_back();
  }

  void remove(unsigned int index)
  {
   if (index == npos || index > container->size() - 1)
    return;
   typename std::vector<T*>::iterator it = container->begin() + index;
   gc_free((*it));
   container->erase(it);
  }

  void remove_all()
  {
   gc_free_range(container->begin(), container->end());
   container->clear();
  }

  size_t index(T* search) const
  {
   typename std::vector<T*>::iterator  it = std::find(container->begin(), container->end(), search);
   if (it == container->end())
    return npos;
   return it - container->begin();
  }

  bool has(T* search) const
  {
   return std::find(container->begin(), container->end(), search) != container->end();
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

  SharedPointer< std::vector<T*> > container;

};
                                                                               

namespace Vectors
{

/*! class. collect
    desc.
       Collection of functions to iterate through a vector and replace them with the result
       of a lambda class.
       example.
       struct lower_case
       {
        string operator()(const string& ref)
        {
         Strings::lower_copy(ref);
        }
       };
       ...
       std::vector<string> strings;
       ...
       Vectors::collect<string, lower_case>::inplace(strings);
*/
template<typename T, class Lambda, typename AX = std::allocator<T> >
struct NxOgrePublicTemplateClass collect
{
 typedef typename std::vector<T, AX> vector;
 typedef typename std::vector<T, AX>::iterator iterator;
 typedef typename std::vector<T, AX>::const_iterator const_iterator;

 Lambda lambda;
 
 void NxOgreForceInline inplace(vector& vec)
 {
  for (iterator it = vec.begin(); it != vec.end(); ++it)
   (*it) = lambda((*it));
 }
 
 vector NxOgreForceInline copy(const vector& vec)
 {
  std::vector<T, AX> out;
  out.reserve(vec.size);
  
  for (iterator it = vec.begin(); it != vec.end(); ++it)
   out.push_back(lambda((*it)));
  
  return out;
 }

};


/*! function. has
    desc.
        Does a vector have a specific value present?
    return.
        bool -- If it does or not.
*/
template<typename T> bool has(const std::vector<T>& vec, const T& checkAgainst)
{
 for (std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
  if ( (*it) == checkAgainst)
   return true;
 return false;
}

/*! function. has
    desc.
        Does a vector have a specific value present?
    return.
        bool -- If it does or not.
*/
template<typename T, typename AX> bool has(const std::vector<T, AX>& vec, const T& checkAgainst)
{
 for (std::vector<T, AX>::const_iterator it = vec.begin(); it != vec.end(); ++it)
  if ( (*it) == checkAgainst)
   return true;
 return false;
}

template<typename T> std::string join(const std::vector<T>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (std::vector<T>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}

template<typename T, typename AX> std::string join(const std::vector<T, AX>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (std::vector<T, AX>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}

template<typename T> void safe_erase(std::vector<T*>& values)
{
 for (std::vector<T*>::iterator it = values.begin(); it != values.end(); ++it)
   Functions::safe_delete<T>((*it));
 values.clear();
}

template<typename T, typename AX> void safe_erase(std::vector<T*, AX>& values)
{
 for (std::vector<T*, AX>::iterator it = values.begin(); it != values.end(); ++it)
   Functions::safe_delete<T>((*it));
 values.clear();
}

                                                                                       

} // namespace Vectors

                                                                                       


                                                                                       

} // namespace NxOgre

                                                                                       

#endif

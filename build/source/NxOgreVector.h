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
#include "NxOgreString.h"
#include "NxOgrePointerFunctions.h"

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#ifdef _DEBUG
 #include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

template<typename T, typename Ax = std::allocator<T> >
class gc_vector
{
public:
  
 gc_vector() : count(1)
 {
 #ifdef _DEBUG
  std::cout << "gc_vector constructor\n";
 #endif
 }
  
~gc_vector() {
 #ifdef _DEBUG
  if (count != 0)
   std::cout << "gc_vector warning. ref count is not zero when destructor called!\n";

  std::cout << "gc_vector destructor ref\n";
 #endif
  }
 
 inline void inc_ref() { ++count;
 #ifdef _DEBUG
  std::cout << "gc_vector increase ref\n";
 #endif
  }
 inline void dec_ref() { --count;
 #ifdef _DEBUG
  std::cout << "gc_vector decrease ref\n";
 #endif
  }
 inline unsigned ref() const { return count; }

 std::vector<T, Ax> vector;
 
 private:

  unsigned int       count;
};

template<typename T, typename Ax = std::allocator<T> > class vector_iterator;
template<typename T, typename Ax = std::allocator<T> > class vector_const_iterator;
template<typename T, typename Ax = std::allocator<T> > class vector;

/* class. vector
   desc.
      vector is a equivalent to a stl vector in a shared pointer.
*/
template<typename T, typename Ax > class vector
{
  
public:
 
 friend class vector_iterator<T, Ax>;
 friend class vector_const_iterator<T, Ax>;
 
 typedef typename std::vector<T, Ax>::const_iterator stl_const_iterator;
 typedef typename std::vector<T, Ax>::iterator stl_iterator;
 
 static const unsigned int npos = -1;
 
 /*! constructor. vector
 */
 explicit vector()
 {
  gc_vec = new gc_vector<T, Ax>();
 }

 /*! constructor. vector
     desc.
          Split a string by a seperator and convert them into T then append them into the vector, in the order of the string.
 */
 vector(const std::string& str, const std::string& sep = " ")
 {
  
  gc_vec = new gc_vector<T, Ax>();
  
  size_t b = str.find_first_not_of(sep, 0);
  size_t a = str.find_first_of(sep, b);
  
  T val;
  while (a != std::string::npos || b != std::string::npos)
  {
   std::stringstream s(str.substr(b, a - b));
   s >> val; 
   push_back(val);
   b = str.find_first_not_of(sep, a);
   a = str.find_first_of(sep, b);
  }
 }
 
 /*! destructor. vector
 */
 ~vector()
 {
  gc_vec->dec_ref();
  if (gc_vec->ref() == 0)
   delete gc_vec;
  gc_vec = 0;
 }

 /*! constructor. vector
     desc.
         Share the stl vector from another vector.
 */
 vector(const vector& other)
 {
  gc_vec = other.gc_vec;
  gc_vec->inc_ref();
 }

 /*! function. operator=
     desc.
         Release use of this vector and acquire one from another.
 */
 vector& operator=(const vector& other)
 {
  gc_vec->dec_ref();
  if (gc_vec->ref() == 0)
   delete gc_vec;
  
  gc_vec = other.gc_vec;
  gc_vec->inc_ref();
  return *this;
 }

 /*! function. clear
     desc.
         Clear all elements in this array.
 */
 void clear()
 {
  gc_vec->vector.clear();
 }

 /*! function. operator[]
     desc.
         element access operator.
 */
 T& operator[](unsigned int n)
 {
  return gc_vec->vector[n];
 }
 
 /*! function. operator[]
     desc.
         element access operator.
 */
 const T& operator[](unsigned int n) const
 {
  return gc_vec->vector[n];
 }
 
 /*! function. iterator
     desc.
         Get an iterator to all of the elements in this vector.
 */
 vector_iterator<T, Ax> iterator()
 {
  return vector_iterator<T, Ax>(gc_vec->vector.begin(), gc_vec->vector.end());
 }

 /*! function. const_iterator
     desc.
         Get an const iterator to all of the elements in this vector.
 */
 vector_const_iterator<T, Ax> const_iterator()
 {
  return vector_const_iterator<T, Ax>(gc_vec->vector.begin(), gc_vec->vector.end());
 }

 /*! function. erase
     desc.
         Erase an element based on it's position in the vector.
 */
 void erase(unsigned int pos)
 {
  if (pos != npos)
   gc_vec->vector.erase(gc_vec->vector.begin() + pos);
 }

 /*! function. destroy
     desc.
         Erase all elements that are equal to value.
 */
 void destroy(const T& value)
 {
  stl_iterator it;
  while (1)
  {
   it = std::find(gc_vec->vector.begin(), gc_vec->vector.end(), value);
   if (it == gc_vec->vector.end())
    break;
   gc_vec->vector.erase(it);
  }
 }

 /*! function. sort
     desc.
         Sort this vector
 */
 void sort()
 {
  std::sort(gc_vec->vector.begin(), gc_vec->vector.end());
 }
 
 /*! function. sort_copy
     desc.
         Create a copy of this vector, sort it then return that.
 */
 vector<T, Ax> sort_copy() const
 {
  vector<T, Ax> cpy = copy();
  cpy.sort();
  return cpy;
 }

 /*! function. unique
     desc.
         Remove all duplicate elements in the vector.
 */
 void unique()
 {
  std::sort(gc_vec->vector.begin(), gc_vec->vector.end());
  stl_iterator end = std::unique(gc_vec->vector.begin(), gc_vec->vector.end());
  gc_vec->vector.erase(end, gc_vec->vector.end());
 }

 /*! function. unique_copy
     desc.
         Create a copy of this vector, remove all duplicate elements from it, then return that.
 */
 vector<T, Ax> unique_copy() const
 {
  vector<T, Ax> cpy = copy();
  cpy.unique();
  return cpy;
 }

 /*! function. reserve
     desc.
         Reserve a number of slots in the vector.
 */
 void reserve(size_t length)
 {
  gc_vec->vector.reserve(count);
 }

 /*! function. fill
     desc.
         Fill the vector with a single value
 */
 void fill(const T& value)
 {
  std::fill(gc_vec->vector.begin(), gc_vec->vector.end(), val);
 }

 /*! function. has
     desc.
         Does the vector contain at least one value?
 */
 void has(const T& value)
 {
  return std::find(gc_vec->vector.begin(), gc_vec->vector.end(), val) != gc_vec->vector.end();
 }

 /*! function. has
     desc.
         Count the number of elements that is equal to value.
 */
 unsigned int count(const T& value)
 {
  return std::count(gc_vec->vector.begin(), gc_vec->vector.end(), val);
 }

 /*! function. has
     desc.
         Find the first element that is equal to value, otherwise return vector<T,Ax>::npos
 */
 unsigned int index(const T& value)
 {
  stl_iterator search = std::find(gc_vec->vector.begin(), gc_vec->vector.end(), value);
  if (search == gc_vec->vector.end())
   return npos;
  return search - gc_vec->vector.begin();
 }

 /*! function. has
     desc.
         Insert value into a specific position in the vector.
 */
 void insert(unsigned int where, const T& val)
 {
  gc_vec->vector.insert(gc_vec->vector.begin() + where, val);
 }

 /*! function. operator+=
     desc.
         Append the elements of another vector that is the same type as this one.
 */
 void operator+=(const vector<T,Ax>& other)
 {
  concat(other);
 }

 /*! function. operator+=
     desc.
         Append a new element to this vector.
 */
 void operator+=(T& t_val)
 {
  push_back(t_val);
 }

 /*! function. concat
     desc.
         Append the elements of another vector that is the same type as this one.
 */
 void concat(const vector<T,Ax>& other)
 {
  for (stl_const_iterator it = other.gc_vec->vector.begin(); it != other.gc_vec->vector.end(); ++it)
   gc_vec->vector.push_back((*it));
 }

 /*! function. reverse
     desc.
         Reverse the order of elements in this vector.
 */
 void reverse()
 {
  std::reverse(gc_vec->vector.begin(), gc_vec->vector.end());
 }

 /*! function. reverse_copy
     desc.
         Create a copy, reverse the order of elements in the copy, and return that.
 */
 vector<T, Ax> reverse_copy() const
 {
  vector<T, Ax> cpy = copy();
  cpy.reverse();
  return cpy;
 }

 /*! function. push_back
     desc.
         Insert a value at the end of the vector.
 */
 void push_back(const T& t_val)
 {
  gc_vec->vector.push_back(t_val);
 }

 /*! function. pop_back
     desc.
         Erase the value at the end of the vector, if there is one.
 */
 void pop_back()
 {
  gc_vec->vector.pop_back();
 }

 /*! function. length
     desc.
         Return the length of the vector.
 */
 unsigned int length() const
 {
  return size();
 }

 /*! function. size
     desc.
         Return the length of the vector.
 */
 unsigned int size() const
 {
  return gc_vec->vector.size();
 }

 /*! function. join
     desc.
         Convert each element into a string, and join them to together seperating them by a string.
 */
 std::string join(const std::string& sep = " ") const
 {
  std::ostringstream s;
  for (stl_const_iterator it = gc_vec->vector.begin(); it != gc_vec->vector.end(); ++it)
   s << (*it) << sep;
  std::string o(s.str());
  return o.substr(0, o.length() - sep.length());
 }

 /*! function. split
     desc.
          Split a string by a seperator and convert them into T then append them into a new vector, in the order of the string.
 */
 static vector<T, Ax> split(const std::string& string, const std::string& sep = " ")
 {
  vector<T, Ax> vec;
  
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

 /*! function. to_s
     desc.
         To String; Joins the elements together as a string seperated by a comma.
 */
 std::string to_s() const
 {
  return join(", ");
 }

 /*! function. copy
     desc.
         Create a copy of this vector.
 */
 vector<T, Ax> copy() const
 {
  vector<T, Ax> cpy;
  cpy.gc_vec->vector.reserve(gc_vec->vector.size());
  for (stl_iterator it = gc_vec->vector.begin(); it != gc_vec->vector.end(); ++it)
   cpy.gc_vec->vector.push_back((*it));
  return cpy;
 }

 /*! function. gc_ref
     desc.
         Number of vectors using the vector.
 */
 unsigned int gc_ref()
 {
  return gc_vec->ref();
 }

 /*! function. each
     desc.
         Calls the operator() on Class with a reference to the element for modification, or comparision.
 */
 template<typename Class> void each(Class& c)
 {
  for (stl_iterator it = gc_vec->vector.begin(); it != gc_vec->vector.end(); ++it)
   c((*it));
 }

 /*! function. each
     desc.
         Calls a function with a reference to the element for modification, or comparision.
 */
 void each(void (*function)(T&) )
 {
  for (stl_iterator it = gc_vec->vector.begin(); it != gc_vec->vector.end(); ++it)
   function((*it));
 }

protected:
 
 gc_vector<T, Ax>* gc_vec;
 
};

/*
 for (vector_iterator<int> it = vecs.iterator(); it.end(); it++)
 {
  std::cout << (*it) << std::endl;
 }
*/
template<typename T, typename Ax> class vector_iterator
{

 public:
  
  typedef typename std::vector<T,Ax>::iterator stl_iterator;
    
  vector_iterator()
  {
  }

  vector_iterator(stl_iterator begin, stl_iterator end)
  : begin_it(begin), end_it(end), current_it(begin_it)
  {
  }

  vector_iterator& operator=(const vector_iterator& other)
  {
   begin_it = other.begin_it;
   end_it = other.end_it;
   current_it = begin_it;
   return *this;
  }

 ~vector_iterator()
  {
  }

  bool start() const
  {
   return current != begin;
  }

  bool end() const
  {
   return current_it != end_it;
  }

  void operator++()
  {
   current_it++;
  }

  void operator++(int)
  {
   current_it++;
  }

  void operator--()
  {
   current_it--;
  }

  void operator--(int)
  {
   current_it--;
  }

  T& operator->()
  {
   return (*current_it);
  }
  
  T& operator*()
  {
   return (*current_it);
  }

 protected:
  
  stl_iterator begin_it, end_it, current_it;
  
};



/*
 for (vector_iterator<int> it = vecs.iterator(); it.end(); it++)
 {
  std::cout << (*it) << std::endl;
 }
*/
template<typename T, typename Ax> class vector_const_iterator
{

 public:
  
  typedef typename std::vector<T,Ax>::const_iterator stl_const_iterator;
    
  vector_const_iterator()
  {
  }

  vector_const_iterator(stl_const_iterator begin, stl_const_iterator end)
  : begin_it(begin), end_it(end), current_it(begin_it)
  {
  }

  vector_const_iterator& operator=(const vector_const_iterator& other)
  {
   begin_it = other.begin_it;
   end_it = other.end_it;
   current_it = begin_it;
  }

 ~vector_const_iterator()
  {
  }

  bool start() const
  {
   return current != begin;
  }

  bool end() const
  {
   return current_it != end_it;
  }

  void operator++()
  {
   current_it++;
  }

  void operator++(int)
  {
   current_it++;
  }

  void operator--()
  {
   current_it--;
  }

  void operator--(int)
  {
   current_it--;
  }

  T& operator->()
  {
   return (*current_it);
  }
  
  T& operator*()
  {
   return (*current_it);
  }

 protected:
  
  stl_const_iterator begin_it, end_it, current_it;
  
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



template<typename T> String join(const std::vector<T>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (std::vector<T>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}

template<typename T, typename AX> String join(const std::vector<T, AX>& values, const std::string& seperator = " ")
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

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif

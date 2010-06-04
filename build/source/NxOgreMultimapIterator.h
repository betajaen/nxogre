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

                                                                                       

#ifndef NXOGRE_MULTIMAP_ITERATOR_H
#define NXOGRE_MULTIMAP_ITERATOR_H

                                                                                       

#include "NxOgreGC.h"
#include "NxOgreSharedPointer.h"

#include <iostream>
#include <map>
#include <algorithm>


                                                                                       

namespace NxOgre
{

                                                                                       

template<typename K, typename T> 
class multimap_iterator
{

public:

inline multimap_iterator()
{ // empty constructor.
}


inline multimap_iterator(const multimap_iterator& other)
: begin_it(other.begin_it), end_it(other.end_it), current_it(begin_it)
{ // constructor. 
}


inline multimap_iterator(const typename std::multimap<K,T>::iterator& begin, const typename std::multimap<K,T>::iterator& end)
: begin_it(begin), end_it(end), current_it(begin)
{ // constructor.
}

inline ~multimap_iterator()
{
}

inline typename std::multimap<K, T>::iterator begin() const
{
 return begin_it;
}

inline typename std::multimap<K, T>::iterator end() const
{
 return end_it;
}

inline bool operator!=(const typename std::multimap<K, T>::iterator& comp)
{
 return current_it != comp;
}

inline bool operator==(const typename std::multimap<K, T>::iterator& comp)
{
 return current_it == comp;
}

inline void operator++()
{
 current_it++;
}

inline void operator++(int)
{
 current_it++;
}

inline void operator--()
{
 current_it--;
}

inline void operator--(int)
{
 current_it--;
}

inline K key() const
{
 return (*current_it).first;
}

inline T& operator->()
{
 return (*current_it).second;
}

inline T& operator*()
{
 return (*current_it).second;
}

protected:
 typename std::multimap<K, T>::iterator current_it, begin_it, end_it;

};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

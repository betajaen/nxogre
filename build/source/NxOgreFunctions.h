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

                                                                                       

#ifndef NXOGRE_FUNCTIONS_H
#define NXOGRE_FUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

/** \brief Fill a chunk of memory with a value
*/
template<typename T> void fill(T* start, T* end, T value)
{
 for (;start != end; ++start)
  (*start) = value;
}

/*! function. is_in.ref
    desc.
        Is a value in this vector.
*/
template<typename T > bool is_in(const T& look_up, const std::vector<T>& vec)
{
 for (std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
 {
  if ((*it) == look_up)
   return true;
 }
 return false;
}
 
/*! function. is_in
    desc.
         Is a value ptr in this vector.
*/
template<typename T> bool is_in(T* look_up, const std::vector<T>& vec)
{
 for (std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
 {
  if ((*it) == look_up)
   return true;
 }
 return false;
}

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

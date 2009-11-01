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

                                                                                       


#ifndef NXOGRE_TUPLE_H
#define NXOGRE_TUPLE_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief An ordered 2-tuple.
*/
template <typename T>
class NxOgrePublicClass Pair
{
 public:
  
  Pair()
  {
  }
  
  Pair(T _1st, T _2nd)
  : first(_1st), second(_2nd)
  {
  }
  
  T  first;
  T  second;
  
}; // class Pair

/** \brief An ordered 3-tuple.
*/
template <typename T>
class NxOgrePublicClass Triple
{
 public:
  
  Triple()
  {
  }
  
  Triple(T _1st, T _2nd, T _3rd)
  : first(_1st), second(_3rd), third(_3rd)
  {
  }
  
  T  first;
  T  second;
  T  third;
  
}; // class Triple

/** \brief An ordered 4-tuple.
*/
template <typename T>
class NxOgrePublicClass Quadruple
{
 public:
  
  Quadruple()
  {
  }
  
  Quadruple(T _1st, T _2nd, T _3rd, T _4th)
  : first(_1st), second(_3rd), third(_3rd), fourth(_4th)
  {
  }
  
  T  first;
  T  second;
  T  third;
  T  fourth;
  
}; // class Quadruple

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

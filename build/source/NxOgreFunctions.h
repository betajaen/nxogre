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

                                                                                       

/** \brief Just like strlen
*/
unsigned int getCStringLength(const char*);

/** \brief Convert any vector3 class to another, assuming both classes have public member variables x y z
*/
template<typename from, typename to>
to  NxOgreForceInline XYZ(const from& _from)
{
 to _to;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
 return _to;
}

/** \brief Convert any vector3 class to another, assuming both classes have public member variables x y z
*/
template<typename from, typename to>
void  NxOgreForceInline XYZ(const from& _from, to& _to)
{
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
}

/** \brief Convert any vector4 class to another, assuming both classes have public member variables w x y z
*/
template<typename from, typename to>
to  NxOgreForceInline WXYZ(const from& _from)
{
 to _to;
 _to.w = _from.w;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
 return _to;
}

/** \brief Convert any vector4 class to another, assuming both classes have public member variables w x y z
*/
template<typename from, typename to>
void  NxOgreForceInline WXYZ(const from& _from, to& _to)
{
 _to.w = _from.w;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
}

/** \brief Turn a const char* into a hash
*/
unsigned long generateHash(const char*, Enums::HashAlgorithm);


template<typename T> void fill(T* start, T* end, T value)
{
 for (;start != end; ++start)
  (*start) = value;
}

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

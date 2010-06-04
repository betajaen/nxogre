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




#ifndef NXOGRE_LIST_H
#define NXOGRE_LIST_H



#include "NxOgreStable.h"
#include "NxOgreString.h"
#include <list>



namespace NxOgre
{



namespace Lists
{


template<typename T> String join(const std::list<T>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (typename std::list<T>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}

template<typename T, typename AX> String join(const std::list<T, AX>& values, const std::string& seperator = " ")
{
 StringStream s;
 for (typename std::list<T, AX>::const_iterator it = values.begin(); it != values.end(); ++it)
  s << (*it) << seperator;
 std::string out = s.str();
 return out.substr(0, out.length() - seperator.length());
}




} // namespace Vectors



} // namespace NXOGRE_NAMESPACE



#endif

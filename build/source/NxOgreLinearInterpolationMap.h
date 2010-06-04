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



#ifndef NXOGRE_LINEARINTERPOLATIONMAP_H
#define NXOGRE_LINEARINTERPOLATIONMAP_H



#include "NxOgreStable.h"
#include "NxOgreMath.h"
#include <map>
#include <sstream>



namespace NxOgre
{



template<typename T> class LinearInterpolationMap
{

 public:

  typedef std::map<T, T>                 MapType;
  typedef typename std::map<T, T>::const_iterator Iterator;

  LinearInterpolationMap()
  : min(0), max(0)
  {
  }

 ~LinearInterpolationMap()
  {
  }

  void clear()
  {
   values.clear();
  }

  void insert(const T& index, const T& value)
  {

   if (values.empty())
   {
    min = max = index;
   }
   else
   {
    min = NxOgre::Math::min<T>(min, index);
    max = NxOgre::Math::max<T>(max, index);
   }

   values[index] = value;
  }

  bool valid(const T& number) const
  {
   return number >= min && number <= max;
  }

  T getValue(const T& number) const
  {
   Iterator lower = values.begin();
   if (number < min)
    return (*lower).second;
   Iterator upper = values.end();
   upper--;
   if (number > max)
    return (*lower).second;
   lower = upper;
   lower--;

   T w1 = number - (*lower).first;
   T w2 = (*upper).first - number;

   return ((w2 * (*lower).second) + (w1 * (*upper).second)) / (w1 + w2);
  }

  T at(int index)
  {
   Iterator it = values.begin();
   for (int i=0;i < index; i++)
    ++it;
   return (*it).second;
  }

  std::string to_s() const
  {
   std::ostringstream o;
   o << "[";
   for (Iterator it = values.begin(); it != values.end(); ++it)
    o << (*it).first << " => " << (*it).second << " ";
   o << "]";
   return o.str();
  }



  T       min, max;
  MapType values;

};



} // namespace NxOgre



#endif

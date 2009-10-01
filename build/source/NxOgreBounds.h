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

                                                                                       

#ifndef NXOGRE_BOUNDS_H
#define NXOGRE_BOUNDS_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

template<class VecT> class BoundsT
{
 public:
  
  typedef BoundsT<VecT>       BoundsType;
  
  BoundsT()
  {
  }
  
  BoundsT(const VecT& _min, const VecT& _max)
  {
   set(_min, _max);
  }
  
  BoundsT(const BoundsType& other)
  {
   set(other);
  }
  
  inline BoundsType operator=(const BoundsType& other)
  {
   set(other);
   return *this;
  }
  
  inline bool operator==(const BoundsType& other) const
  {
   return ((min == other.min) && (max == other.max));
  }

  inline void set(const VecT& _min, const VecT& _max)
  {
   min = _min;
   max = _max;
  }
  
  inline void set(const BoundsType& other)
  {
   min = other.min;
   max = other.max;
  }
  
  inline void merge(const BoundsType& other)
  {
   min.min(other.min);
   max.max(other.max);
  }
  
  inline void merge(const VecT& other)
  {
   min.min(other);
   max.max(other);
  }
  
  inline bool inside(const VecT& other) const
  {
   return (other > min && other < max);
  }
  
  inline bool intersects(const BoundsType& other) const
  {
   return (other.min > min && other.max < max);
  }
  
  inline VecT center() const
  {
   return (min + max) * (Real) 0.5;
  }
  
  inline VecT dimensions() const
  {
   return max - min;
  }
  
  inline VecT extents() const
  {
   return (max - min) * (Real) 0.5;
  }
  
  inline void setCenterExtents(const VecT& center, const VecT& extents)
  {
   min = c - e;
   min = c + e;
  }
  
  inline void scale(const Real& scalar)
  {
   setCenterExtents(center(), extents() * scalar);
  }
  
  inline void operator*=(const Real& scalar)
  {
   scale(scalar);
  }
  
  inline void empty()
  {
   min.x = FLT_MAX;
   min.y = FLT_MAX;
   min.z = FLT_MAX;
   max.x = -FLT_MAX;
   max.y = -FLT_MAX;
   max.z = -FLT_MAX;
  }
  
  template <typename BoundsType> static BoundsT from(const BoundsType& other)
  {
   return BoundsT(other.min, other.max);
  }
  
  VecT min, max;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

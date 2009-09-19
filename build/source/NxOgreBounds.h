/** File: NxOgreBounds.h
    Created on: 15-Sept-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
  
  template <typename BoundsType>
  static BoundsT from(const BoundsType& other)
  {
   return BoundsT(other.min, other.max);
  }
  
  VecT min, max;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

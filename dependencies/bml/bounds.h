/** File: bounds.h
    Created on: 15-May-09
    Author: Robin Southern "betajaen"
    Version: 20080515

    © Copyright, 2009 by Robin Southern, http://www.nxogre.org

    Betajaen's Math Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Betajaen's Math Library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef bounds_h_636aea61_048b_45ab_bc36_4fe778b38e53
#define bounds_h_636aea61_048b_45ab_bc36_4fe778b38e53

#include "bml/prototypes.h"
#include "bml/vector.h"

namespace bml
{
 
 template<class VectorType> class BoundsT
 {
  public:
   
   typedef typename VectorType::Type Type;
   typedef BoundsT<VectorType>       BoundsType;
   
   BoundsT()
   {
   }
   
   BoundsT(const VectorType& _min, const VectorType& _max)
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

   inline void set(const VectorType& _min, const VectorType& _max)
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
   
   inline void merge(const VectorType& other)
   {
    min.min(other);
    max.max(other);
   }
   
   inline bool inside(const VectorType& other) const
   {
    return (other > min && other < max);
   }
   
   inline bool intersects(const BoundsType& other) const
   {
    return (other.min > min && other.max < max);
   }
   
   inline VectorType center() const
   {
    return (min + max) * (Type) 0.5;
   }
   
   inline VectorType dimensions() const
   {
    return max - min;
   }
   
   inline VectorType extents() const
   {
    return (max - min) * (Type) 0.5;
   }
   
   inline void setCenterExtents(const VectorType& center, const VectorType& extents)
   {
    min = c - e;
    min = c + e;
   }
   
   inline void scale(const Type& scalar)
   {
    setCenterExtents(center(), extents() * scalar);
   }
   
   inline void operator*=(const Type& scalar)
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
   
   VectorType min, max;

 };


} // namespace

#endif

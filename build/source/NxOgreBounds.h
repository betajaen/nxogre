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



/*! class. BoundsT<class VecType>
    desc.
         A class containing the minimum and maximum bounds using a NxOgre Vector class.

    note.
         There are already *Bounds2*, *Bounds3*, *Bounds4* typedefs already created for the
         *Vector2*, *Vector3* and *Vector4* classes.

    example.
         Bounds3 bounds;
         b.merge(pos1);
         b.merge(pos2);
         b.merge(pos3);
         b.merge(pos4);
         Vec3 center = b.center();
*/
template<class VecType> class BoundsT
{
 public:

  typedef BoundsT<VecType>       BoundsType;

  /*! constructor. BoundsT
      desc.
       Empty constructor.
  */
  BoundsT()
  {
  }

  /*! constructor. BoundsT
      desc.
           Constructor with minimim and maximum as arguments.
      args.
           const VecType& __min__ -- Minimum
           const VecType& __max__ -- Maximum
      note.
           _min <= _max
  */
  BoundsT(const VecType& _min, const VecType& _max)
  {
   set(_min, _max);
  }

  /*! copy_constructor. BoundsT
      desc.
        Copy constructor
      args.
           const BoundsType& __other__ -- Other BoundsT
  */
  BoundsT(const BoundsType& other)
  {
   set(other);
  }

  /*! operator. operator=
      desc.
           Assignment operator
      args.
           const BoundsType& __other__ -- Other BoundsT
      return.
           **BoundsType** -- This bounds type
  */
  inline BoundsType operator=(const BoundsType& other)
  {
   set(other);
   return *this;
  }

  /*! operator. operator==
      desc.
           Comparision operator
      args.
           const BoundsType& __other__ -- Other BoundsT
      return.
           **bool** -- Is the other BoundsT equal to this?
  */
  inline bool operator==(const BoundsType& other) const
  {
   return ((min == other.min) && (max == other.max));
  }
  /*! function. set
      desc.
           Sets the min/max to new ones.
      args.
           const VecType& __min__ -- New minimum
           const VecType& __max__ -- New maximum
  */
  inline void set(const VecType& _min, const VecType& _max)
  {
   min = _min;
   max = _max;
  }

  /*! function. set
      desc.
           Sets the min/max to new ones from another BoundsT
      args.
           const BoundsType& __other__ -- Other BoundsT
  */
  inline void set(const BoundsType& other)
  {
   min = other.min;
   max = other.max;
  }

  /*! function. merge
      desc.
           Merge two min/max from another BoundsT into this one
      args.
           const BoundsType& __other__ -- Other BoundsT
  */
  inline void merge(const BoundsType& other)
  {
   min.min(other.min);
   max.max(other.max);
  }

  /*! function. merge
      desc.
           Merge a VectorT to change the min/max.
      args.
           const VecType& __other__ -- Merging Vector
  */
  inline void merge(const VecType& other)
  {
   min.min(other);
   max.max(other);
  }

  /*! function. inside
      desc.
           Is a Vector inside the bounds?
      args.
           const VecType& __other__ -- Vector to test
      return.
           **bool** -- If the vector is inside or not.
  */
  inline bool inside(const VecType& other) const
  {
   return (other > min && other < max);
  }

  /*! function. intersects
      desc.
           Is a Bounds inside the bounds?
      args.
           const BoundsType& __other__ -- Bounds to test
      return.
           **bool** -- If the bounds is inside or not.
  */
  inline bool intersects(const BoundsType& other) const
  {
   return (other.min > min && other.max < max);
  }

  /*! function. center
      desc.
           Get the center coordinates of the bounds
      return.
           **VecType** -- The center of the bounds.
  */
  inline VecType center() const
  {
   return (min + max) * (Real) 0.5;
  }

  /*! function. dimensions
      desc.
           Get the size of the bounds
      return.
           **VecType** -- The size of the bounds.
  */
  inline VecType dimensions() const
  {
   return max - min;
  }

  /*! function. extents
      desc.
           Get the extents of the bounds
      return.
           **VecType** -- The extents of the bounds.
  */
  inline VecType extents() const
  {
   return (max - min) * (Real) 0.5;
  }

  /*! function. setCenterExtents
      desc.
           Set min/max from extents and center coordinates.
      args.
           const VecType& __center__ -- The center of the extents.
           const VecType& __extents__ -- The extents themselves.
  */
  inline void setCenterExtents(const VecType& c, const VecType& e)
  {
   min = c - e;
   max = c + e;
  }

  /*! function. scale
      desc.
           Scale the bounds by a scalar
      args.
           const Real& __scalar__ -- Scalar
  */
  inline void scale(const Real& scalar)
  {
   setCenterExtents(center(), extents() * scalar);
  }

  /*! operator. operator*=
      desc.
           Scale the bounds by a scalar
      args.
           const Real& __scalar__ -- Scalar
  */
  inline void operator*=(const Real& scalar)
  {
   scale(scalar);
  }

  inline bool isEmpty() const
  {
   return (min.x > max.x &&
           min.y > max.y &&
           min.z > max.z);
  }

  inline void zero()
  {
   min.zero();
   max.zero();
  }

  /*! function. empty
      desc.
           Sets the min to infinity and max to negative infinity.
  */
  inline void empty()
  {
   min.x = FLT_MAX;
   min.y = FLT_MAX;
   min.z = FLT_MAX;
   max.x = -FLT_MAX;
   max.y = -FLT_MAX;
   max.z = -FLT_MAX;
  }

  /*! function. from
      desc.
           Copy's the bounds from another Bounds class from a different API.
      note.
           The other bounds type must have accessible "min" and "max" vector class
           variables and those vector classes must have accessible "x", "y", "z" member variables.
      args.
           const BoundsType& __other__ -- Other API bounds to copy from.
      example.
           NxBounds3 other_bounds = ...;
           Bounds3 bounds =  Bounds3::from<NxBounds3>(other_bounds);
      !static
  */
  template <typename BoundsType> static BoundsT from(const BoundsType& other)
  {
   return BoundsT(other.min, other.max);
  }

  inline String to_s() const;

  inline NxOgrePublicFunction friend std::ostream& operator << (std::ostream& o, const BoundsType& b)
  {
   o << b.min << ", " << b.max;
   return o;
  }

  /*! variable. min
      desc.
       Minimum bounds.
  */
  VecType min;

  /*! variable. min
      desc.
       Maximum bounds.
  */
  VecType max;

};



} // namespace NxOgre



#endif

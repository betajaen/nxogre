/** File: NxOgreIntVectors.h
    Created on: 15-Apr-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

#ifndef NXOGRE_INTVECTORS_H
#define NXOGRE_INTVECTORS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

/** \brief int2 is a mathemical 2 row vector with a int as a datatype.
*/
class NxOgrePublicClass int2
{
  
  public: // Functions
  
   int2(void)
   : x(0), y(0)
   {
   }

   int2(int _x, int _y)
   : x(_x), y(_y)
   {
   }

   ~int2(void)
   {
   }

   void operator+=(const int2& other)
   {
    x += other.x;
    y += other.y;
   }

   void operator-=(const int2& other)
   {
    x -= other.x;
    y -= other.y;
   }

   void operator*=(const int2& other)
   {
    x *= other.x;
    y *= other.y;
   }

   void operator/=(const int2& other)
   {
    x /= other.x;
    y /= other.y;
   }

   void operator*=(int r)
   {
    x *= r;
    y *= r;
   }
  
                        int                    x //< X component.
                                              ,y //< Y component.
                                              ;
  
  
}; // class int2

/** \brief int3 is a mathemical 3 row vector with a int as a datatype.
*/
class NxOgrePublicClass int3
{
  
  public: // Functions
  
    int3(void)
    : x(0), y(0), z(0)
    {
    }

    int3(int _x, int _y, int _z)
    : x(_x), y(_y), z(_z)
    {
    }

    ~int3(void)
    {
    }

    void operator+=(const int3& other)
    {
     x += other.x;
     y += other.y;
     z += other.z;
    }

    void operator-=(const int3& other)
    {
     x -= other.x;
     y -= other.y;
     z -= other.z;
    }

    void operator*=(const int3& other)
    {
     x *= other.x;
     y *= other.y;
     z *= other.z;
    }

    void operator/=(const int3& other)
    {
     x /= other.x;
     y /= other.y;
     z /= other.z;
    }

    void operator*=(int r)
    {
     x *= r;
     y *= r;
     z *= r;
    }
  
                        int                    x //< X component.
                                              ,y //< Y component.
                                              ,z //< Z component.
                                              ;
  
  
}; // class ClassName


/** \brief int4 is a mathemical 3 row vector with a int as a datatype.
*/
class NxOgrePublicClass int4
{
  
  
  public: // Functions
  
     int4(void)
     : w(0), x(0), y(0), z(0)
     {
     }

     int4(int _w, int _x, int _y, int _z)
     : w(_w), x(_x), y(_y), z(_z)
     {
     }

     ~int4(void)
     {
     }

     void operator+=(const int4& other)
     {
      w += other.w;
      x += other.x;
      y += other.y;
      z += other.z;
     }

     void operator-=(const int4& other)
     {
      w -= other.w;
      x -= other.x;
      y -= other.y;
      z -= other.z;
     }

     void operator*=(const int4& other)
     {
      w *= other.w;
      x *= other.x;
      y *= other.y;
      z *= other.z;
     }

     void operator/=(const int4& other)
     {
      w /= other.w;
      x /= other.x;
      y /= other.y;
      z /= other.z;
     }

     void operator*=(int r)
     {
      w *= r;
      x *= r;
      y *= r;
      z *= r;
     }
  
                        int                    w //< W (1st) component.
                                              ,x //< X (2nd) component.
                                              ,y //< Y (3rd) component.
                                              ,z //< Z (4th) component.
                                              ;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif

/** File: NxOgreIntVectors.h
    Created on: 15-Apr-09
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

#ifndef NXOGRE_INTVECTORS_H
#define NXOGRE_INTVECTORS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief int2 is a mathemical 2 row vector with a int as a datatype.
*/
class NxOgrePublicClass int2
{
  
  public: // Functions
   
   int2(void);
   
   int2(int _x, int _y);
   
  ~int2(void);
   
   void operator+=(const int2& other);
   
   void operator-=(const int2& other);
   
   void operator*=(const int2& other);
   
   void operator/=(const int2& other);
   
   void operator*=(int r);
   
   int x, y;
   
}; // class int2

/** \brief int3 is a mathemical 3 row vector with a int as a datatype.
*/
class NxOgrePublicClass int3
{
   
  public: // Functions
   
    int3(void);
   
    int3(int _x, int _y, int _z);
   
   ~int3(void);
   
    void operator+=(const int3& other);
   
    void operator-=(const int3& other);
   
    void operator*=(const int3& other);
   
    void operator/=(const int3& other);
   
    void operator*=(int r);
   
    int x, y, z;
   
}; // class ClassName


/** \brief int4 is a mathemical 3 row vector with a int as a datatype.
*/
class NxOgrePublicClass int4
{
   
  public: // Functions
   
   int4(void);
   
   int4(int _w, int _x, int _y, int _z);
   
  ~int4(void);
   
   void operator+=(const int4& other);
   
   void operator-=(const int4& other);
   
   void operator*=(const int4& other);
   
   void operator/=(const int4& other);
   
   void operator*=(int r);
   
   int w, x, y, z;
   
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

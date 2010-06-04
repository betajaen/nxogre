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
   
   int2();
   
   int2(int _x, int _y);
   
  ~int2();
   
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
   
    int3();
   
    int3(int _x, int _y, int _z);
   
   ~int3();
   
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
   
   int4();
   
   int4(int _w, int _x, int _y, int _z);
   
  ~int4();
   
   void operator+=(const int4& other);
   
   void operator-=(const int4& other);
   
   void operator*=(const int4& other);
   
   void operator/=(const int4& other);
   
   void operator*=(int r);
   
   int w, x, y, z;
   
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

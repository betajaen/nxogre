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

                                                                                       

#ifndef NXOGRE_GROUPSMASK_H
#define NXOGRE_GROUPSMASK_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief 128-bit mask used for collision filtering.
*/
class NxOgrePublicClass GroupsMask
{
  
  public:
  
  /*! constructor. GroupsMask
4  */
  GroupsMask();
  
  /*! constructor. GroupsMask
4  */
  GroupsMask(int bits0, int bits1, int bits2, int bits3);
  
  /*! destructor.
      desc.
          Required destructor
  */
 ~GroupsMask();
  
  /*! function. zero
      desc.
          Set bits0, bits1, bits2, bits3 to zero.
  */
  void zero();

  inline String to_s() const;

  inline NxOgrePublicFunction friend std::ostream& operator << (std::ostream& o, const GroupsMask& m)
  {
   o << m.to_s();
   return o;
  }

  template<typename T> T as() const
  {
   T ret;
   ret.bits0 = bits0;
   ret.bits1 = bits1;
   ret.bits2 = bits2;
   ret.bits3 = bits3;
   return ret;
  }

  unsigned int bits0, bits1, bits2, bits3;
  
}; // class GroupsMask

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

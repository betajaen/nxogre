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

                                                                                       

#ifndef NXOGRE_SPRINGDESCRIPTION_H
#define NXOGRE_SPRINGDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Describes a Joint Spring
*/
class NxOgrePublicClass SpringDescription
{
 public:
  
  /** \brief Constructor and calls reset.
  */
  SpringDescription();

  /** \brief Reset function
  */
  void reset();

  /** \brief Spring coefficient
      \see NxSpringDesc::spring
      \default 0
  */
  Real mSpring;

  /** \brief Damper coefficient
      \see NxSpringDesc::damper
      \default 0
  */
  Real mDamper;

  /** \brief Target value (either in radians or positional) of spring where the 
             spring force is zero.
      \see NxSpringDesc::targetValue
      \default 0
  */
  Radian mTargetValue;
  
}; // class SpringDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

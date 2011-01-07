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

                                                                                       

#ifndef NXOGRE_DISTANCEJOINTDESCRIPTION_H
#define NXOGRE_DISTANCEJOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJointDescription.h"
#include "NxOgreJointLimitDescription.h"
#include "NxOgreSpringDescription.h"
#include "NxOgreMotorDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass DistanceJointDescription : public JointDescription
{
 
  public: // Functions
  
  /** \brief Text
  */
                                              DistanceJointDescription();
  
  /** \brief Text
  */
                                             ~DistanceJointDescription();
  
  /** \brief Text
  */
  void                                        reset();
  
  /** \brief
  */
  bool                                        isValid() const;
  
  /** \brief The maximum allowed distance between the two rigid bodies.
      \default 0.0
      \see NxDistanceJointDesc::maxDistance
  */
  Real                                        mMaxDistance;
  
  /** \brief The minimum allowed distance between the two rigid bodies.
      \default 0.0
      \see NxDistanceJointDesc::minDistance
  */
  Real                                        mMinDistance;
  
  /** \brief Flags specific to the Distance Joint.
      \default 0
      \see Enums::DistanceJointFlags
  */
  int                                         mDistanceJointFlags;
  
  /** \brief 
      \default Spring::reset
  */
  SpringDescription                           mSpring;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

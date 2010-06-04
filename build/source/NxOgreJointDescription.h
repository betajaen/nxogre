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

                                                                                       

#ifndef NXOGRE_JOINTDESCRIPTION_H
#define NXOGRE_JOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass JointDescription
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              JointDescription();
  
  /** \brief Text
  */
  virtual                                    ~JointDescription();
  
  /** \brief Text
  */
  virtual void                                reset();
  
  /** \brief
  */
  virtual bool                                isValid() const;

  /** \brief
  */
  Vec3                                       mLocalNormal[2];
  
  
  /** \brief
  */
  Vec3                                       mLocalAxis[2];
  
  
  /** \brief
  */
  Vec3                                       mLocalAnchor[2];
  
  
  /** \brief
  */
  Real                                        mMaxForce;
  
  
  /** \brief
  */
  Real                                        mMaxTorque;
  
  /** \brief
  */
  Real                                        mSolverExtrapolationFactor;
  
  /** \brief
      \see NxJointDesc::useAccelerationSpring
      \default JointSpringType_Force
  */
  Enums::JointSpringType                      mSpringType;
  
  /** \brief Joint Flags, see Enums::JointFlag
      \note As with most flags, use the OR | operator to join flags together.
      \default Enums::JointFlag_Visualisation
      \see Enums::JointFlag
  */
  int                                         mJointFlags;
  
}; // class JointDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

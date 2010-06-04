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

                                                                                       

#ifndef NXOGRE_MATERIALDESCRIPTION_H
#define NXOGRE_MATERIALDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{
                                                                                       

/** \brief
*/
class NxOgrePublicClass MaterialDescription
{ 
  
  public: // Functions
  
  /** \brief MaterialDescription constructor, all it does is call MaterialDescription::reset.
  */
                                              MaterialDescription();
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                        reset();
  
  /** \brief Returns if the variables are in a valid range or not.
  */
                        bool                  valid();

  /** \brief Optional Name of the Material
  */
  String  mName;

  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \note If set to greater than staticFriction, the effective value of
            staticFriction will be increased to match.
      \default 0
  */
  Real  mDynamicFriction;
  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
  */
  Real  mStaticFriction;
  
  /** \brief Coefficient of restitution (bounce)
      \range [0, 1].
      \default 0
  */
  Real  mRestitution;

  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
      \note If set to greater than staticFriction, the effective value of
            staticFriction will be increased to match.
  */
  Real  mVDynamicFriction;
  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
  */
  Real  mVStaticFriction;
  
  /** \brief Shape space direction (unit vector) of anisotropy.
             This is only used if flags & ANISOTROPIC is set.
      \default 1 0 0
  */
  Vec3  mDirectionOfAnisotropy;

  /** \brief
      \default 0
  */
  unsigned int  mFlags;

  /** \brief
      \default CombineMode_Average
  */
  Enums::CombineMode  mFrictionCombineMode;

  /** \brief
      \default CombineMode_Average
  */
  Enums::CombineMode  mResitutionCombineMode;

 
 
}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

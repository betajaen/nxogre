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

                                                                                       

#ifndef NXOGRE_WORLDDESCRIPTION_H
#define NXOGRE_WORLDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass WorldDescription
{
  public: // Functions
  
  /** \brief WorldDescription constructor, all it does is call WorldDescription::reset.
  */
                                              WorldDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                        reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                  valid(void);
  
  /** \brief Disable simulation on a PPU or GPU completely.
      \default false
  */
  bool                                        mNoHardware;
  
  /** \brief Size of hardware mesh pages.
      \note  Currently the PhysX SDK only supports a value of 65536 only.
      \default 65536
  */
  unsigned int                                mHardwarePageSize;
  
  /** \brief Maximum number of hardware pages supported on the hardware, must be a power of 2.
      \default 256
  */
  unsigned int                                mHardwareMaximumPage;
  
  /** \brief Maximum number of convex meshes that would be resident on hardware, must be a power of 2.
      \default 2048
  */
  unsigned int                                mHardwareMaximumConvex;
  
  /** \brief Thread affinity mask for the background cooker thread.
      \default 0 (SDK determines the affinity).
  */
  unsigned int                                mCookerThreadMask;
  
  /** \brief What to do when there is an assertion from PhysX.
      \default PhysXAssertion_Continue
  */
  Enums::PhysXAssertionResponse               mAssertionResponse;
  
}; // class WorldDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

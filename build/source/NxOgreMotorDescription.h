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

                                                                                       

#ifndef NXOGRE_MOTORDESCRIPTION_H
#define NXOGRE_MOTORDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass MotorDescription
{
  
  public: // Functions
  
  /** \brief "Blank" constructor, calls reset
  */
  MotorDescription();

  /** \brief Alternate constructor
  */
  MotorDescription(Real velocityTarget, Real maxForce, bool freeSpin);
  
  /** \brief Resets the description per the PhysX SDK guidelines.
  */
  void reset();

  /** \brief The relative velocity the motor should try to reach.
      \see NxMotorDesc::velTarget
      \range [0,inf]
      \default NxOgrRealMax
  */
  Real       mVelocityTarget;
  
  /** \brief Max force (or torque) the motor can exert.
      \range [0, inf]
      \default 0 (Off)
  */
  Real       mMaxForce;
  
  /** \brief Break when the motor spins faster than the velocity target.
      \default false
  */
  bool       mFreeSpin;

}; // class MotorDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

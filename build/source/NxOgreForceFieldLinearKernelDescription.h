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

                                                                                       

#ifndef NXOGRE_FORCEFIELDLINEARKERNELDESCRIPTION_H
#define NXOGRE_FORCEFIELDLINEARKERNELDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ForceFieldLinearKernelDescription
*/
class NxOgrePublicClass ForceFieldLinearKernelDescription
{
  
  public: // Functions
  
  /*! constructor. ForceFieldKernelDescription
      desc.
          Calls RigidBodyDescription::reset
  */
  ForceFieldLinearKernelDescription();
  
  /*! function. reset
      desc.
          Resets everything to their default values, and pointers are set to NULL.
  */
  void reset();
  
  /*! function. valid
      desc.
          Returns if the variables are in a valid range or not.
      return.
          bool - If it is valid or not.
  */
  bool valid();
  
  /*! function. clone
      desc.
          Clone the properties of this into another ForceFieldDescription or a class derived from it.
      args.
         ForceFieldLinearKernelDescription& target -- Target to copy properties too.
  */
  void clone(ForceFieldLinearKernelDescription& target) const;
  
  /*! variable. mConstant
      desc.
          Constant part of force field function.
      default.
          Vec3::ZERO
  */
  Vec3  mConstant;
  
  /*! variable. mPositionMultiplier
      desc.
          Coefficient of force field function position term.
      default.
          Matrix33::ZERO
  */
  Matrix33  mPositionMultiplier;
  
  /*! variable. mPositionTarget
      desc.
          Force field position target.
      default.
          Vec3::ZERO
  */
  Vec3  mPositionTarget;
  
  /*! variable. mVelocityMultiplier
      desc.
          Coefficient of force field function velocity term.
      default.
          Matrix33::ZERO
  */
  Matrix33  mVelocityMultiplier;
  
  /*! variable. mVelocityTarget
      desc.
          Force field velocity target.
      default.
          Vec3::ZERO
  */
  Vec3  mVelocityTarget;
 
  /*! variable. mTorusRadius
      desc.
          Radius for Enums::CoordinateSystem_Toroidal type coordinates.
      default.
          0
  */
  Real  mTorusRadius; 
  
  /*! variable. mFalloffLinear
      desc.
          Linear term in magnitude falloff factor. Range (each component): [0, inf).
      default.
          Vec3::ZERO
  */
  Vec3  mFalloffLinear;
  
  /*! variable. falloffQuadratic
      desc.
          Quadratic term in magnitude falloff factor. Range (each component): [0, inf).
      default.
          Vec3::ZERO
  */
  Vec3  mFalloffQuadratic;
  
  /*! variable. mNoise
      desc.
          Noise scaling.
      default.
          Vec3::ZERO
  */
  Vec3  mNoise;
  
  /*! variable. mName
      desc.
          Optional name of the kernel
      default.
          NxOgre::BLANK_STRING
  */
  String mName;
  
}; // class ForceFieldLinearKernelDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

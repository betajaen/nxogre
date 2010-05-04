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

                                                                                       

#ifndef NXOGRE_PROTOTYPE_FUNCTIONS_H
#define NXOGRE_PROTOTYPE_FUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShape.h"

#ifdef NXOGRE_SDK
class NxPhysicsSDKDesc;
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

class NxOgrePublicClass PrototypeFunctions
{
 public:

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Joint properties to a NxJointDesc.
  */
  static void JointDescriptionToNxJointDescription(const JointDescription&, NxJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SphericalJoint properties to a NxSphericalJointDesc.
  */
  static void SphericalJointDescriptionToNxSphericalJointDescription(const SphericalJointDescription&, NxSphericalJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant RevoluteJoint properties to a NxRevoluteJointDesc.
  */
  static void RevoluteJointDescriptionToNxRevoluteJointDescription(const RevoluteJointDescription&, NxRevoluteJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Spring properties to a NxSpringDesc.
  */
  static void SpringDescriptionToNxSpringDesc(const SpringDescription&, NxSpringDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Limit properties to a NxLimitDesc.
  */
  static void JointLimitDescriptionToNxJointLimitDesc(const JointLimitDescription&, NxJointLimitDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Motor properties to a NxMotorDesc.
  */
  static void MotorDescriptionToNxMotorDesc(const MotorDescription&, NxMotorDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant D6 joint properties to a NxD6JointDesc.
  */
  static void D6JointDescriptionToNxD6JointDescription(const D6JointDescription&, NxD6JointDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant D6 joint properties to a NxD6JointDesc.
  */
  static void ClothDescriptionToNxClothDesc(const ClothDescription& source, NxClothDesc& desc);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SoftBody properties to a NxSoftBodyDesc.
  */
  static void SoftBodyDescriptionToNxSoftBodyDesc(const SoftBodyDescription& source, NxSoftBodyDesc& desc);
#endif
  
#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SoftBody properties to a NxSoftBodyDesc.
  */
  static void ForceFieldLinearKernelDescriptionToNxForceFieldLinearKernelDesc(const ForceFieldLinearKernelDescription&, NxForceFieldLinearKernelDesc&);
#endif
  
 private:
  
  PrototypeFunctions();
  
}; // class ClassName


                                                                                       

} // namespace Functions
                                                                                       

} // namespace NxOgre

                                                                                       

#endif

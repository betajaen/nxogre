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

                                                                                       

#ifndef NXOGRE_REASON_H
#define NXOGRE_REASON_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Reason is a collection of static functions that turns descriptions and error codes
           into why they could be invalid.
*/
class NxOgrePublicClass Reason
{
public:

#if NXOGRE_SDK
  static const char* why(NxSDKCreateError);
#endif

#if NXOGRE_SDK
  static const char* toCStr(NxErrorCode);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxPhysicsSDKDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSceneDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxActorDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxMaterialDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxHeightFieldDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxJointLimitDesc&, const char* sourceName);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSpringDesc&, const char* sourceName);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxJointDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSphericalJointDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxClothDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSoftBodyDesc&);
#endif

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

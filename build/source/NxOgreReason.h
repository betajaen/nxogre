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
#include "NxOgreString.h"
#include "NxOgrePhysXPrototypes.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Reason
    desc.
         Reason is a collection of static functions that turns descriptions and error codes into why they could be invalid.
*/
class NxOgrePublicClass Reason
{
  
 public:
  
  static const char* Exceptionise(int PhysXSDKCreateError);
  
  static const char* toCStr(int PhysXErrorEcode);
  
  static String Exceptionise(const NxPhysicsSDKDesc&, bool isSdkNull, int errorCode);
  
  static String Exceptionise(const NxSceneDesc&, bool isSDKNull, const String& sceneName);
  
  static String Exceptionise(const NxActorDesc&);
  
  static String Exceptionise(const NxMaterialDesc&);
  
  static String Exceptionise(const NxHeightFieldDesc&);
  
  static String Exceptionise(const NxJointLimitDesc&, const char* sourceName);
  
  static String Exceptionise(const NxSpringDesc&, const char* sourceName);
  
  static String Exceptionise(const NxJointDesc&);
  
  static String Exceptionise(const NxSphericalJointDesc&);
  
  static String Exceptionise(const NxRevoluteJointDesc&);
  
  static String Exceptionise(const NxClothDesc&);
  
  static String Exceptionise(const NxSoftBodyDesc&);
  
  static String Exceptionise(const Path& path, Enums::ResourceStatus status);
  
}; // class Reason

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

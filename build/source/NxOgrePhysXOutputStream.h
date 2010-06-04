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

                                                                                       

#ifndef NXOGRE_PHYSX_OUTPUTSTREAM_H
#define NXOGRE_PHYSX_OUTPUTSTREAM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK

/** \brief
*/
class NxOgrePublicClass PhysXOutputStream : public GenericBasedAllocatable, public NxUserOutputStream
{
  
  NXOGRE_GC_FRIEND_NEW0
  NXOGRE_GC_FRIEND_DELETE
  
  public:
  
  /** \brief What do when there is an assertion from PhysX
  */
  void setAssertionResponse(Enums::PhysXAssertionResponse);

  protected: // Functions
  
  /** \internal
  */
  PhysXOutputStream();
  
  /** \internal
  */
 ~PhysXOutputStream();
  
  /** \internal
  */
  void  reportError(NxErrorCode code, const char * message, const char *file, int line);

  /** \internal
  */
  NxAssertResponse  reportAssertViolation(const char * message, const char *file, int line);

  /** \internal
  */
  void  print(const char*);
  
  protected: // Variables
  
  NxAssertResponse  mAssertionResponse;
  
}; // class ClassName

#endif
                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       


#ifndef NXOGRE_PHYSXSTREAM_H
#define NXOGRE_PHYSXSTREAM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"

#ifdef NXOGRE_SDK
#  include "NxPhysics.h"
#  include "NxStream.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK

/** \internal DO NOT USE
*/
class NxOgrePublicClass PhysXStream : public NxStream
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              PhysXStream(Resource*);
  
  /** \brief Text
  */
                                             ~PhysXStream();
  
  /** \internal DO NOT USE
  */
  NxU8                                        readByte() const;

  /** \internal DO NOT USE
  */
  NxU16                                       readWord() const;

  /** \internal DO NOT USE
  */
  NxU32                                       readDword() const;

  /** \internal DO NOT USE
  */
  NxF32                                       readFloat() const;

  /** \internal DO NOT USE
  */
  NxF64                                       readDouble() const;

  /** \internal DO NOT USE
  */
  void                                        readBuffer(void* buffer, NxU32 size) const;

  /** \internal DO NOT USE
  */
  NxStream&                                   storeByte(NxU8 b);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeWord(NxU16 w);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeDword(NxU32 d);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeFloat(NxF32 f);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeDouble(NxF64 f);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeBuffer(const void* buffer, NxU32 size);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeByte(NxI8 b);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeWord(NxI16 w);

  /** \internal DO NOT USE
  */
  NxStream&                                   storeDword(NxI32 d);

  protected: // Variables
  
  Resource*                                 mResource;
  
FILE* fp;
  
}; // class ClassName

#endif

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

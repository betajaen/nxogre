/** File: NxOgrePhysXStream.h
    Created on: 28-Feb-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
                                             ~PhysXStream(void);
  
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

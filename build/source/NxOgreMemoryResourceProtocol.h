/** File: NxOgreMemoryResourceProtocol.h
    Created on: 08-Nov-08
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

#ifndef NXOGRE_MEMORYRESOURCEPROTOCOL_H
#define NXOGRE_MEMORYRESOURCEPROTOCOL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResourceProtocol.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Memory Archive Factory creates Resources to blocks of memory. It uses the "memory" as the protocol
           name. It does not use archives, or filenames for resources. It's intended usage for "scratch" space
           to write to. Initially the memory size is reserved to 64 bytes, but will increase automatically if
           needed.
    \note  A new block of memory is allocated each time an resource is opened, so 
           ResourceSystem::getSingleton()->open("memory:") == ResourceSystem::getSingleton()->open("memory:") 
           will never be true.
    \example
     <code>
      Resource* resource = ResourceSystem::getSingleton()->open("memory:");
      resource->writeInt(7737)
      resource->seekBeginning();
      int n = resource->readInt(); // n = 7737
     </code>
*/
class NxOgrePublicClass MemoryResourceProtocol : public PointerClass<Classes::_MemoryResourceProtocol>, public ResourceProtocol
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              MemoryResourceProtocol(void);
  
  /** \brief Text
  */
                                             ~MemoryResourceProtocol(void);
  
  /** \brief Text
  */
                       String           getProtocol(void);
  
  /** \brief Text
  */
                       unsigned long          getProtocolHash(void) const;
  
  /** \brief Is there only one archive by default?
  */
                       bool                   isSingleArchive(void) const;
  
  /** \brief Does the resources use filenames?
  */
                       bool                   usesNamelessResources(void) const;
  
  protected: // Functions
  
  
  /** \internal NOT USED.
  */
                       Archive*               openArchive(const String&, const UniformResourceIdentifier&);
  
  /** \internal NOT USED.
  */
                       void                   closeArchive(Archive*);
  
  /** \brief Initialise the memory resource protocol and creates the "memory" archive.
  */
                       void                   initialise(void);

  protected: // variables
  

  /** \brief Has the initialise function been called?
  */
                       bool                   mHasInit;
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

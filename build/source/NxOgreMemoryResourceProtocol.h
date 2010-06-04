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
class NxOgrePublicClass MemoryResourceProtocol : public ResourceProtocol
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              MemoryResourceProtocol();
  
  /** \brief Text
  */
                                             ~MemoryResourceProtocol();
  
  /** \brief Text
  */
                       String                 getProtocol();
  
  /** \brief Text
  */
                       StringHash             getProtocolHash() const;
  
  /** \brief Does the resources use filenames?
  */
                       bool                   usesNamelessResources() const;
  
                       Resource*              open(const Path&, Enums::ResourceAccess);
  
                       void                   close(Resource*);
  
  protected:
  
  /** \brief Initialise the memory resource protocol and creates the "memory" archive.
  */
                       void                   initialise();

  protected: // variables
  
                       String                 mProtocolName;
  
                       StringHash             mProtocolHash;
  
  /** \brief Has the initialise function been called?
  */
                       bool                   mHasInit;
  
}; // class MemoryResourceProtocol

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

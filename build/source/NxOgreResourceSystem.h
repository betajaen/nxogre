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

                                                                                       

#ifndef NXOGRE_RESOURCESYSTEM_H
#define NXOGRE_RESOURCESYSTEM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResourceProtocol.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ResourceSystem : public ::NxOgre::Singleton<ResourceSystem>, public BigClassAllocatable
{
  
  friend class World;
   
  public: // Functions
  
  NXOGRE_GC_FRIEND_NEW0
  NXOGRE_GC_FRIEND_DELETE
  
  typedef map<size_t, ResourceProtocol*>          Protocols;
  typedef map_iterator<size_t, ResourceProtocol*> ProtocolIterator;

  /** \brief Open an resource, using an Path. Archive will be created or opened based of the directories of the file, unless specified
             by the protocol.
      \usage
       <code>
        resource_system_ptr->open("file://c:/Program Files/My Game/Game.txt", Enums::ResourceAccess_ReadOnly);
       </code>
      \note  In the event of the resource not existing in the archive, the ResourceProtocol may create one for you.
  */
  Resource*  open(const Path&, Enums::ResourceAccess = Enums::ResourceAccess_ReadOnly);
  
  /*! function. close
      desc.
          Close a resource.
  */
  void  close(Resource*);
  
  /*! function. getProtocols
      desc.
          Return an iterator to the current protocols loaded.
      return.
          ProtocolIterator -- The iterator.
  */
  ProtocolIterator  getProtocols();

  /*! constructor. openProtocol
      desc.
          Open a resource protocol, pointer is owned by the ResourceSystem when passed on.
          ResourceProtocols last the entire lifetime of the ResourceSystem, so they can never
          be closed.
      note.
          The Protocol will be deleted according to its destruction policy. (ResourceProtocol::getDestructionPolicy)
  */
  void  openProtocol(ResourceProtocol*);
  
  protected:
  
  /*! constructor. ResourceSystem
      desc.
           Private Constructor
      see.
          World::precreateSingletons() or World::createWorld()
  */
  ResourceSystem();
  
  /*! destructor. ResourceSystem
      desc.
          Private Destructor
      see.
         World::destroySingletons() or World::destroyWorld()
  */
  ~ResourceSystem();
  
  /* \internal
     mProtocols
      Loaded protocols stored in an associative container using a StringHash as the protocol's lowercase 
      name with the ResourceProtocol stored and owned by the container.
  */
  Protocols  mProtocols;
  
}; // class ResourceSystem

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

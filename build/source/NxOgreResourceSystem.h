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
#include "NxOgreArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ResourceSystem : public ::NxOgre::Singleton<ResourceSystem, ::NxOgre::Classes::_ResourceSystem>
{
  
  friend class World;
   
  public: // Functions
  
  typedef ptr_hashmap<ResourceProtocol> Protocols;
  
  typedef ptr_hashmap<Archive>          Archives;

  /** \brief Open a resource protocol, pointer is owned by the ResourceSystem when passed on.
      \note  These can never be closed.
  */
                       void                   openProtocol(ResourceProtocol*);
  
  /** \brief Open an archive, using a path.
      \note  If BLANK_STRING is given as the name, then the ResourceProtocol given will calculate the archive name for you.
      \usage
       <code>
        resource_system_ptr->open("file://c:/Program Files/My Game/", "game");
       </code>
  */
                       Archive*               openArchive(const Path& path, const String& name = BLANK_STRING);

  /** \brief Open an resource, using an Path. Archive will be created or opened based of the directories of the file, unless specified
             by the protocol.
      \usage
       <code>
        resource_system_ptr->open("file://c:/Program Files/My Game/Game.txt", Enums::ResourceAccess_ReadOnly);
       </code>
      \note  In the event of the resource not existing in the archive, the ResourceProtocol may create one for you.
  */
                       Resource*              open(const Path&, Enums::ResourceAccess);
  
  /** \brief Open a resource with a previously opened archive, using a relative filename or identifier to that archive.
      \note  This is the fastest way to access a resource.
  */
                       Resource*              open(Archive*, const Path& relative_path, Enums::ResourceAccess);

  /** \brief Close a resource.
  */
                       void                   close(Resource*);
  
  /** \brief Close an archive, and close any resources of that archive.
  */
                       void                   closeArchive(Archive*);

  /** \brief Get archive by name.
  */
                       Archive*               getArchiveByName(const String& name);
  
  /** \brief Get archive by hash.
  */
                       Archive*               getArchiveByHash(const StringHash& hashed_name);
  
  protected:
  
                                              ResourceSystem();
  
  
                                             ~ResourceSystem();
  
  /** \brief Loaded protocols stored in an associative container using a StringHash as the protocol's lowercase
             name with the ResourceProtocol stored and owned by the container.
  */
                       Protocols              mProtocols;
  
  /** \brief All current archives opened, referenced by a StringHash of the ArchiveName, and the Archive is stored
             and owned by the container.
  */
                       Archives               mArchives;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

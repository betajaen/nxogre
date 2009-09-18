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

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ResourceSystem : public ::NxOgre::Singleton<ResourceSystem, ::NxOgre::Classes::_ResourceSystem>
{
  
  friend class World;
   
  public: // Functions
  
  /** \brief Register a resource protocol.
  */
                       void                   addProtocol(ResourceProtocol*);
  
  /** \brief Register an archive, using a name and a UniformResourceIdentifier.
  */
                       Archive*               openArchive(const String& name, const UniformResourceIdentifier&);
  
  /** \brief Open an resource.
      \note  In the event of the resource not existing in the archive, the resource system might create one for you.
  */
                       Resource*              open(const ArchiveResourceIdentifier&, Enums::ResourceAccess);
  
  /** \brief Close a resources.
  */
                       void                   close(Resource*);
  
  /** \brief Close an archive, and close any resources of that archive.
  */
                       void                   closeArchive(const String& name);

  /** \brief Get archive by name
  */
                       Archive*               getArchiveByName(const String& name);
  
  protected:
  
                                              ResourceSystem();
  
  
                                             ~ResourceSystem();
  
  /** \brief
  */
            Array<ResourceProtocol*>          mProtocols;
  
  /** \brief
  */
            Array<Archive*>                 mArchives;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

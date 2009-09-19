/** File: NxOgreResourceSystem.h
    Created on: 17-Nov-08
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

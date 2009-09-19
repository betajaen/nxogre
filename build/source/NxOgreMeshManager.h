/** File: NxOgreMeshManager.h
    Created on: 16-Jan-09
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

#ifndef NXOGRE_MESHMANAGER_H
#define NXOGRE_MESHMANAGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief MeshManager holds all meshes that are currently in the World.
*/
class NxOgrePublicClass MeshManager: public ::NxOgre::Singleton<MeshManager, ::NxOgre::Classes::_MeshManager>
{
  
  friend class World;
  
  public: // Functions
  
  /** \brief Load a mesh into the World, that can be used in any Scene.
      \note  It will take the resource name as it's name.
  */
  Mesh*                                       load(const ArchiveResourceIdentifier&);
  
  /** \brief Load a mesh into the World, that can be used in any Scene.
  */
  Mesh*                                       load(const ArchiveResourceIdentifier&, const String& name);
    
  /** \brief Load a mesh into the World, that can be used in any Scene.
      \note  It will try to take the resource name as it's name, otherwise a random one will be generated.
  */
  Mesh*                                       load(Resource*);
  
  /** \brief Load a mesh into the World, that can be used in any Scene.
  */
  Mesh*                                       load(Resource*, const String& name);
  
  /** \brief Text
  */
  Mesh*                                       getByName(const String& meshIdentifier);
  
  protected: // Variables
  
  /** \internal See World::precreateSingletons
  */
                                              MeshManager(void);
  
  /** \internal See World::destroySingletons
  */
                                             ~MeshManager(void);
  
  /** \brief Known loaded meshes in the World.
  */
  Array<Mesh*>                                mLoadedMeshes;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

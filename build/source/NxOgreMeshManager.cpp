/** File: NxOgreMeshManager.cpp
    Created on: 12-Mar-09
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMeshManager.h"
#include "NxOgreMesh.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreResource.h"

template<> NxOgre::MeshManager* NxOgre::Singleton<NxOgre::MeshManager, NxOgre::Classes::_MeshManager>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

MeshManager::MeshManager(void)
{
}

MeshManager::~MeshManager(void)
{
 mLoadedMeshes.destroyAll();
}

Mesh* MeshManager::load(const ArchiveResourceIdentifier& ari)
{
 Resource* resource = ResourceSystem::getSingleton()->open(ari, NxOgre::Enums::ResourceAccess_ReadOnly);
 if (resource == 0)
  return 0;
 Mesh* mesh = new Mesh(resource);
 mesh->setName(ari.getResourceName());
 mLoadedMeshes.insert(mesh);
 return mesh;
}


Mesh* MeshManager::load(const ArchiveResourceIdentifier& ari, const String& name)
{
 Resource* resource = ResourceSystem::getSingleton()->open(ari, NxOgre::Enums::ResourceAccess_ReadOnly);
 if (resource == 0)
  return 0;
 Mesh* mesh = new Mesh(resource);
 mesh->setName(name);
 mLoadedMeshes.insert(mesh);
 return mesh;
}

Mesh* MeshManager::load(Resource* resource)
{
 if (resource == 0)
  return 0;
 Mesh* mesh = new Mesh(resource);
 mesh->setName(resource->getArchiveResourceIdentifier().getResourceName());
 mLoadedMeshes.insert(mesh);
 return mesh;
}

Mesh* MeshManager::load(Resource* resource, const String& name)
{
 if (resource == 0)
  return 0;
 Mesh* mesh = new Mesh(resource);
 mesh->setName(name);
 mLoadedMeshes.insert(mesh);
 return mesh;
}

Mesh* MeshManager::getByName(const String& meshIdentifier)
{
 ArrayIterator<Mesh*> iterator = mLoadedMeshes.getIterator();
 for (Mesh* mesh = iterator.begin(); mesh = iterator.next(); )
 {
  if (mesh->getName() == meshIdentifier)
   return mesh;
 }
 return 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       

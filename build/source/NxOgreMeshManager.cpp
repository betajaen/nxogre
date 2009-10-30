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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMeshManager.h"
#include "NxOgreMesh.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreResource.h"
#include <iostream>
template<> NxOgre::MeshManager* NxOgre::Singleton<NxOgre::MeshManager>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

MeshManager::MeshManager(void)
{
}

MeshManager::~MeshManager(void)
{
 mMeshes.clear();
}

Mesh* MeshManager::load(const Path& path, const String& name)
{

// std::cout << path.dump() << "\n------------------\n";
 std::cout << path.getString() << "\n";

 Resource* resource = ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_ReadOnly);
 Mesh* mesh = load(resource, name);
 ResourceSystem::getSingleton()->close(resource);
 return mesh;
}

Mesh* MeshManager::load(Resource* resource, const String& name)
{
 if (resource == 0)
  return 0;
 
 Mesh* mesh = new Mesh(resource);
 
 if (name == BLANK_STRING)
 {
  String mesh_name = resource->getPath().getFilenameOnly();
  if (mesh_name.length() != 0)
   mesh->setName(mesh_name);
 }
 else
 {
  mesh->setName(name);
 }
 
 StringHash meshHash = mesh->getNameHash();
 mMeshes.insert(meshHash, mesh);
 return mesh;
}

Mesh* MeshManager::getByName(const String& meshIdentifier)
{
 return getByHash(Functions::StringHash(meshIdentifier));
}

Mesh* MeshManager::getByHash(const StringHash& hashed_name)
{
 return mMeshes.at(hashed_name);
}

MeshManager::MeshIterator MeshManager::getMeshes()
{
 return MeshIterator(mMeshes);
}

                                                                                       

} // namespace NxOgre

                                                                                       

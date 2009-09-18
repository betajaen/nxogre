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

                                                                                       

#ifndef NXOGRE_OPTIONS_MINIMAL
#ifndef NXOGRE_MESHFUNCTIONS_H
#define NXOGRE_MESHFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace Mesh
{

                                                                                       

/** \brief Calculate the number of vertices, indices, texture coordinates, tetrahedra of a mesh.
*/
NxOgrePublicFunction MeshStats calculateStats(NxOgre::Mesh*);

/** \brief Create a Triangle Mesh from a set of vertices, indexes and materials. It is "cooked" to a resource, which can be saved
           to a file as a "NXS" file. To read the mesh into PhysX then load it via the MeshManager e.x. MeshManager::load(resource)
    \param resource   The triangle mesh to save to.
    \param vertices   The vertices as 3 floats; x y z.
    \param indexes   The indexes which make the triangles.
    \param materials  Materials per index
    \note  Use the ManualMesh for a more easier interface to work with.
    \example
    <code>
     Buffer<float> vertices;
     vertices.add(1); vertices.add(2); vertices.add(3); // and so on.
     Buffer<unsigned int> indexes;
     indexes.add(1); indexes.add(2); indexes.add(3); // and so on.
     Buffer<unsigned int> materials;
     materials.add(1); materials.add(2); materials.add(2); // and so on.
     Resource* resource = ResourceSystem::getSingleton()->open("archiveName:myTriangleMesh.nxs");
     Function::Mesh::createTriangleMesh(resource, vertices, indexes, materials);
     Mesh* mesh = MeshManager::getSingleton()->load(resource, "Test");
    </code>
*/
NxOgrePublicFunction bool  createTriangleMesh(Resource*, MeshData*);

/** \brief
*/
NxOgrePublicFunction void  saveTriangleMesh(NxTriangleMesh*, MeshData*);

/** \brief Create a Convex Mesh/Point Cloud from a set of vertices and some optional indexes. It is cooked to a resource, which can be
           saved to a file as a "NXS" file. To read the mesh into PhysX then load it in via the MeshManager e.x. MeshManager::load(resource).
    \param resource   The triangle mesh to save to.
    \param vertices   The vertices as 3 floats; x y z.
    \param indexes    The indexes which make the triangles. (Optional)
    \param nbVertices Number of vertices (not number of floats)
    \param nbIndexes  Number of indexes.
    \note  Use the ManualMesh for a more easier interface to work with.
    <code>
     Buffer<float> vertices;
     vertices.add(1); vertices.add(2); vertices.add(3); // and so on.
     Resource* resource = ResourceSystem::getSingleton()->open("archiveName:myConvexMesh.nxs");
     Function::Mesh::createConvexMesh(resource, vertices, Buffer<unsigned int>(), materials);
     Mesh* mesh = MeshManager::getSingleton()->load(resource, "Test");
    </code>
*/
NxOgrePublicFunction bool  createConvexMesh(Resource* resource, MeshData*);

/** \brief
*/
NxOgrePublicFunction void  saveConvexMesh(NxConvexMesh*, MeshData*);


/** \brief Create a cloth from a set of vertices, indexes and some optional texture coordinates. It is cooked to a resource, which can be
           saved to a file as a "xcl" file. To read the mesh into PhysX then load it in via the MeshManager e.x. MeshManager::load(resource).
    \param resource       The triangle mesh to save to.
    \param vertices       The vertices as 3 floats; x y z.
    \param indexes        The indexes which make the triangles.
    \param texture_coords The Texture coordinates for each triangle (optional).
    \note  Use the ManualMesh for a more easier interface to work with.
    \note  Adding texture coordinates may cause an incompatiblity with other PhysX wrappers or PhysX itself other than NxOgre.
    <code>
     Buffer<float> vertices;
     vertices.add(1); vertices.add(2); vertices.add(3); // and so on.
     Resource* resource = ResourceSystem::getSingleton()->open("archiveName:myConvexMesh.nxs");
     Function::Mesh::createConvexMesh(resource, vertices, Buffer<unsigned int>(), materials);
     Mesh* mesh = MeshManager::getSingleton()->load(resource, "Test");
    </code>
*/
NxOgrePublicFunction bool createClothMesh(Resource* cookTo, MeshData*);

/** \brief
*/
NxOgrePublicFunction void  saveClothMesh(NxClothMesh*, MeshData*);

/** \brief Create a simple tetrahedra
*/
NxOgrePublicFunction bool createSoftBodyMesh(Resource* cookTo, MeshData*);

/** \brief Read texture coordinates from an extended cloth NXS mesh (xcl).
*/
NxOgrePublicFunction void loadExtendedCloth(Resource* resource, Buffer<float>&);

/** \brief Write texture coordinates to an extended cloth NXS mesh (xcl), resource pointer is expected to be at the end of the file.
*/
NxOgrePublicFunction void saveExtendedCloth(Resource* resource, Buffer<float>&);

/** \brief Helper function to create flat cloth.
*/
NxOgrePublicFunction ::NxOgre::Mesh*  generateFlatCloth(const ArchiveResourceIdentifier& target, const Vec2& size, Real distanceBetweenVertices);


                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif

/** File: NxOgreMeshFunctions.h
    Created on: 28-Feb-09
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

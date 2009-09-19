/** File: NxOgreManualMesh.h
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
#ifndef NXOGRE_MANUAL_MESH_H
#define NXOGRE_MANUAL_MESH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief ManualMesh is a class of functions designed to create PhysX meshes, cloth and tetrahedra soft bodies, within
           code. ManualMesh can also be used to convert a file-format to a PhysX one.
    \example
     <code>
      ManualMesh m;
      m.begin(NxOgre::Enums::MeshType_Convex, 4);
       m.vertex(-1,-1);
       m.vertex(-1, 1);
       m.vertex( 1,-1);
       m.vertex( 1, 1);
      Mesh* mesh = m.end();
     </code>
*/
class NxOgrePublicClass ManualMesh
{
  
  public: // Functions
  
  enum
  {
   AUTO_CALCULATE_TRIANGLES = -1
  };
  
  /** \brief ManualMesh constructor.
  */
                                              ManualMesh(void);
  
  /** \brief ManualMesh copy constructor.
  */
                                              ManualMesh(const ManualMesh& other);
  
  /** \brief ManualMesh destructor.
  */
                                             ~ManualMesh(void);
  
  /** \brief Assignment operator
  */
  ManualMesh&                                 operator=(ManualMesh& other);
  
  /** \brief Begin a definition of a mesh using type
      \param estimatedVerticesSize Rough estimate of how many vertices there are. ManualMesh will auto-resize if needed.
      \param estimatedTriangleSize Rough estimate of how many triangles there are. If value is "AUTO_CALCULATE_TRIANGLES" then it will
             use the indexCount * 3, if it is a mesh that uses Triangles, otherwise 0.
  */
  void                                        begin(NxOgre::Enums::MeshType type, unsigned int estimatedVerticesSize = 12, unsigned int AUTO_CALCULATE_TRIANGLES = -1);
  
  /** \brief Set the name of the mesh.
  */
  void                                        name(const String& name);
  
  /** \brief Set the name of the mesh.
  */
  void                                        name(const char*);
  
  /** \brief Get the name of the mesh.
  */
  String                                      name(void) const;
  
  /** \brief Clean the meshdata
  */
  void                                        clean();

  /** \brief Use the current mesh data and deallocate/unreference the existing mesh data.
      \note Do not use the mesh data from an existing ManualMesh as the mesh data may be unexpectedly deleted!
  */
  void                                        acquire(MeshData*);

  /** \brief Add a vertex
      \for   Triangle, Convex, Cloth, Tetrahedra.
  */
  void                                        vertex(float, float, float);
  
  /** \brief Add a vertex
      \for   Triangle, Convex, Cloth, Tetrahedra.
  */
  void                                        vertex(const Vec3&);
  
  /** \brief Adds an index.
      \for   Triangle, Convex (Optional), Cloth, Tetrahedra.
  */
  void                                        index(unsigned int);
  
  /** \brief Calls index three times.
      \for   Triangle, Convex (Optional), Cloth, Tetrahedra.
  */
  void                                        triangle(unsigned int, unsigned int, unsigned int);
  
  /** \brief Add a normal.
      \for   Cloth, Tetrahedra.
  */
  void                                        normal(float, float, float);
  
  /** \brief Add a normal.
      \for   Cloth, Tetrahedra.
  */
  void                                        normal(const Vec3&);
  
  /** \brief Add a texture coordinate.
      \for   Cloth, Tetrahedra.
  */
  void                                        textureCoordinate(float, float);
  
  /** \brief Add a texture coordinate.
      \for   Cloth, Tetrahedra.
  */
  void                                        textureCoordinate(const Vec2&);
  
  /** \brief Add a tetrahedra quad.
      \for   SoftBody
  */
  void                                        tetrahedra(unsigned int, unsigned int, unsigned int, unsigned int);
  
  /** \brief Add a material per triangle.
      \for   Triangle
      \param Material index MUST be the same material in the intended scene. Saving the mesh to disk, then using later, the material
             order in the Scene you cooked the mesh in, must be in the same order as you use the mesh in.
  */
  void                                        material(MaterialIdentifier);
  
  /** \brief Mass per vertex
      \for   Cloth
  */
  void                                        vertexMass(float);
  
  /** \brief flag per vertex
      \for   Cloth
  */
  void                                        vertexFlag(unsigned int);
  
  /** \brief Does the mesh meet the criteria for the mesh type?
  */
  bool                                        isValid(void) const;
  
  /** \brief Cook the mesh to a ResourceIdentifier target (default is memory) and return a Mesh to use. Mesh is automatically registered
             by the MeshManager. Mesh name is automatically generated unless MeshManager::name() is used.
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the mesh to a file, save in memory, or to something else.
  */
  Mesh*                                       end(bool cleanUp = true, const ArchiveResourceIdentifier& cookingTarget = ArchiveResourceIdentifier("memory:"));
  
  /** \brief Cook the mesh to a ResourceIdentifier target (default is memory).
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the mesh to a file, save in memory, or to something else.
  */
  void                                        endCookOnly(bool cleanUp = true, ArchiveResourceIdentifier& cookingTarget = ArchiveResourceIdentifier("memory:"));
  
  protected: // Variables
  
  MeshData*                                   mMesh;
  
  RefT*                                       mRef;
  
}; // class ManualMesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif

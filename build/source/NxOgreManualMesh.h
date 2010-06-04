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
     To modify an existing mesh.
     ManualMesh m(myMesh->getMeshData());
     for (unsigned int i=0;i < m.nbVertices();i++)
      m.scaleVertex(i, Vec3(2,2,2) );
     Mesh* myNewScaledMesh = m.end();
*/
class NxOgrePublicClass ManualMesh : public GenericBasedAllocatable
{
  
  public: // Functions
  
  enum
  {
   AUTO_CALCULATE_TRIANGLES = -1
  };
  
  /** \brief ManualMesh constructor.
  */
                                              ManualMesh();
  
  /** \brief ManualMesh copy constructor.
  */
                                              ManualMesh(const ManualMesh& other);
  
  /** \brief Alternative constructor using MeshData.
  */
                                              ManualMesh(MeshData* other);
  
  /** \brief ManualMesh destructor.
  */
                                             ~ManualMesh();
  
  /** \brief Assignment operator
  */
  ManualMesh&                                 operator=(ManualMesh& other);
  
  /** \brief Begin a definition of a mesh using type.
      \param estimatedVerticesSize Rough estimate of how many vertices there are. ManualMesh will auto-resize if needed.
      \param estimatedTriangleSize Rough estimate of how many triangles there are. If value is "AUTO_CALCULATE_TRIANGLES" then it will
             use the indexCount * 3, if it is a mesh that uses Triangles, otherwise 0.
      \note If using with an existing MeshData, this function may corrupt the existing data!
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
  String                                      name() const;
  
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
  
  /** \brief Set a vertex value
  */
  void                                        modifyVertex(unsigned index, const Vec3& newValue);
  
  /** \brief Set a vertex value
  */
  void                                        scaleVertex(unsigned index, const Vec3& factor);
  
  /** \brief Get number of vertices
  */
  unsigned int                                nbVertices() const;

  /** \brief Get number of triangles
  */
  unsigned int                                nbTriangles() const;

  /** \brief Get number of triangles
  */
  unsigned int                                nbTextureCoords() const;

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
  bool                                        isValid() const;
  
  /** \brief Cook the mesh to a ResourceIdentifier target (default is memory) and return a Mesh to use. Mesh is automatically registered
             by the MeshManager. Mesh name is automatically generated unless MeshManager::name() is used.
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the mesh to a file, save in memory, or to something else.
  */
  Mesh*                                       end(bool cleanUp = true, const Path& cookingPath = MEMORY_PATH);
  
  /** \brief Cook the mesh to a ResourceIdentifier target (default is memory).
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the mesh to a file, save in memory, or to something else.
  */
  void                                        endCookOnly(bool cleanUp = true, const Path& cookingPath = MEMORY_PATH);
  
  protected: // Variables
  
  NxOgre::SharedPointer<MeshData>             mMesh;
  
  
}; // class ManualMesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

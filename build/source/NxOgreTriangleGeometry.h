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

                                                                                       

#ifndef NXOGRE_TRIANGLEGEOMETRY_H
#define NXOGRE_TRIANGLEGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass TriangleGeometry : public Shape
{
  
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  unsigned int getShapeType() const;

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
  
  /** \brief Get the triangle mesh.
  */
  Mesh*  getTriangleMesh();
  
  /** \brief   Get a triangle based upon the triangleIndex.
      \params  Triangle; Triangle that was found
      \params  Flags; Flags of that triangle that was found, see Enums::TriangleFlags
      \params  triangleIndex; Index to find.
      \params  worldSpaceTranslation; If the triangle should be translated to world space.
      \params  worldSpaceTranslation; If the triangle should be rotated to world space.
  */
  void  getTriangle(Triangle& triangle, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation = true, bool worldSpaceRotation = true );

  /** \brief   Get a triangle based upon the triangleIndex.
      \params  triangle; World space triangle points.
      \params  edge; World space edge normals for triangle.
      \params  flags; Flags of that triangle that was found, see Enums::TriangleFlags
      \params  triangleIndex; Index to find.
      \params  worldSpaceTranslation; If the triangle should be translated to world space.
      \params  worldSpaceTranslation; If the triangle should be rotated to world space.
  */
  void  getTriangle(Triangle& triangle, Triangle& edge, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation = true, bool worldSpaceRotation = true );

  /** \brief Finds triangles touching the input bounds.
      \params bounds The Bounds to test against.
      \params queryFlags If the bounds are in world or local space, and if we return first contact only. See Enums::QueryFlags
      \params callback Used if the triangles overlay the AABB.
      \return True if there is an overlap, or is the shape has not been attached yet.
  */
  bool  overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const;

  /** \brief Send a page to the PhysX processor.
      \see NxTriangleMeshShape::mapPageInstance
      \param pageIndex the index of the page to map.
      \return False is there are insufficent resources available, or if the mesh is run in software mode, or is the shape has not been attached yet.
  */
  bool  mapPageInstance(unsigned int pageIndex);

  /** \brief Release a page instance from the PhysX processor.
      \see NxTriangleMeshShape::unmapPageInstance
      \param pageIndex Index to unmap.
     \return False if the page index isn't mapped, or the mesh is in software mode, or is the shape has not been attached yet.
  */
  void  unmapPageInstance(unsigned int pageIndex);

  /** \brief If a page instance is present from the PhysX processor.
      \see NxTriangleMeshShape::isPageInstanceMapped
      \param Page index to be queried.
      \return False if the page index isn't mapped, or the mesh is in software mode, or is the shape has not been attached yet.
  */
  bool  isPageInstanceMapped(unsigned int pageIndex) const;
  
  void saveToDescription(TriangleGeometryDescription& description);
  
  protected:

  /** \brief TriangleGeometry
  */
  TriangleGeometry(NxTriangleMeshShape*, Mesh*, bool isDirty = false);
  
  /** \brief TriangleGeometry
  */
 ~TriangleGeometry();
  
  protected:
  
  NxTriangleMeshShape*    mTriangleMeshShape;
  
  Mesh*                   mMesh;
  
}; // class TriangleGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreTriangleGeometry.h
    Created on: 15-Mar-09
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

#ifndef NXOGRE_TRIANGLEGEOMETRY_H
#define NXOGRE_TRIANGLEGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass TriangleGeometry : public PointerClass<Classes::_TriangleGeometry>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_TriangleGeometry>::operator new;

  using ::NxOgre::PointerClass<Classes::_TriangleGeometry>::operator delete;

  using ::NxOgre::PointerClass<Classes::_TriangleGeometry>::getClassType;

  /** \brief TriangleGeometry
  */
                                              TriangleGeometry(Mesh*, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  /** \brief TriangleGeometry
  */
                                             ~TriangleGeometry(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
                   Enums::ShapeFunctionType   getShapeFunctionType(void) const;
  
  /** \brief Get the triangle mesh.
  */
                      Mesh*                   getTriangleMesh(void);
  
  /** \brief   Get a triangle based upon the triangleIndex.
      \params  Triangle; Triangle that was found
      \params  Flags; Flags of that triangle that was found, see Enums::TriangleFlags
      \params  triangleIndex; Index to find.
      \params  worldSpaceTranslation; If the triangle should be translated to world space.
      \params  worldSpaceTranslation; If the triangle should be rotated to world space.
  */
                           void               getTriangle(Triangle& triangle, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation = true, bool worldSpaceRotation = true );

  /** \brief   Get a triangle based upon the triangleIndex.
      \params  triangle; World space triangle points.
      \params  edge; World space edge normals for triangle.
      \params  flags; Flags of that triangle that was found, see Enums::TriangleFlags
      \params  triangleIndex; Index to find.
      \params  worldSpaceTranslation; If the triangle should be translated to world space.
      \params  worldSpaceTranslation; If the triangle should be rotated to world space.
  */
                           void               getTriangle(Triangle& triangle, Triangle& edge, unsigned int* flags, Index triangleIndex, bool worldSpaceTranslation = true, bool worldSpaceRotation = true );

  /** \brief Finds triangles touching the input bounds.
      \params bounds The Bounds to test against.
      \params queryFlags If the bounds are in world or local space, and if we return first contact only. See Enums::QueryFlags
      \params callback Used if the triangles overlay the AABB.
      \return True if there is an overlap, or is the shape has not been attached yet.
  */
                           bool               overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const;

  /** \brief Send a page to the PhysX processor.
      \see NxTriangleMeshShape::mapPageInstance
      \param pageIndex the index of the page to map.
      \return False is there are insufficent resources available, or if the mesh is run in software mode, or is the shape has not been attached yet.
  */
                           bool               mapPageInstance(unsigned int pageIndex);

  /** \brief Release a page instance from the PhysX processor.
      \see NxTriangleMeshShape::unmapPageInstance
      \param pageIndex Index to unmap.
     \return False if the page index isn't mapped, or the mesh is in software mode, or is the shape has not been attached yet.
  */
                           void               unmapPageInstance(unsigned int pageIndex);

  /** \brief If a page instance is present from the PhysX processor.
      \see NxTriangleMeshShape::isPageInstanceMapped
      \param Page index to be queried.
      \return False if the page index isn't mapped, or the mesh is in software mode, or is the shape has not been attached yet.
  */
                           bool               isPageInstanceMapped(unsigned int pageIndex) const;



  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create(void);

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxTriangleMeshShape*    mTriangleMeshShape;

                      Mesh*                   mMesh;

}; // class TriangleGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

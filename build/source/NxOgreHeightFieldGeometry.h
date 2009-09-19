/** File: NxOgreHeightFieldGeometry.h
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

#ifndef NXOGRE_HEIGHTFIELDGEOMETRY_H
#define NXOGRE_HEIGHTFIELDGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreHeightFieldGeometryBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass HeightFieldGeometry : public PointerClass<Classes::_HeightFieldGeometry>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_HeightFieldGeometry>::operator new;

  using ::NxOgre::PointerClass<Classes::_HeightFieldGeometry>::operator delete;

  using ::NxOgre::PointerClass<Classes::_HeightFieldGeometry>::getClassType;


  /** \brief HeightFieldGeometry
  */
                                              HeightFieldGeometry(HeightField*, const Vec3& size, HeightFieldGeometryBlueprint* blue = new HeightFieldGeometryBlueprint());

  /** \brief HeightFieldGeometry
  */
                                              HeightFieldGeometry(HeightField*, HeightFieldGeometryBlueprint* blue = new HeightFieldGeometryBlueprint());

  /** \brief HeightFieldGeometry
  */
                                             ~HeightFieldGeometry(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
                   Enums::ShapeFunctionType   getShapeFunctionType(void) const;
  
  

  /** \brief HeightField in Use.
  */
                        HeightField*          getHeightField(void) const;

  /** \brief Terrain Centering in use.
      \default Enums::TerrainCentering_UseLocalPose
      \note    Returns TerrainCentering_UseLocalPose when HeightField is attached.
  */
                      Enums::TerrainCentering getTerrainCentering(void) const;
 
  /** \brief Use smooth sphere collisions
      \default false
      \note When the shape is attached, this cannot be fetched. False is returned instead.
  */
                      bool                    getSmoothSphereCollisions(void) const;

  /** \default Get the material index that RigidBody's can currently pass through.
      \note When the shape is attached, the hole material can not be fetched. 0 is returned instead.
  */
                      MaterialIdentifier      getHoleMaterial(void) const;


  /** \default Specifies the material for a heightfield HeightField along with the low order
               bits of the material index stored in each heightfield sample
      \default 0
      \note When the shape is attached, this cannot be fetched. 0 is returned instead.
  */
                      MaterialIdentifier      getHighBits(void) const;


  /** \brief Set the HeightField to Use.
      \note  ONLY applies when the shape is not attached. For an attached shape, create a new HeightFieldGeometry shape, and 
             replace that with this one.
  */
                           void               setHeightField(HeightField*);

  /** \brief Terrain Centering in use.
      \default Enums::TerrainCentering_LocalPose
      \note When the terrain is attached, use setLocalPose instead.
  */
                           void               setTerrainCentering(Enums::TerrainCentering = Enums::TerrainCentering_LocalPose);
 
  /** \brief Use smooth sphere collisions
      \default false
      \note When the shape is attached, this function does nothing.
  */
                           void               setSmoothSphereCollisions(bool = false);

  /** \default Material indexes for HeightFields, which RigidBody's can pass through.
      \default 65535
      \note When the shape is attached, this function does nothing.
  */
                           void               setHoleMaterial(MaterialIdentifier = 65535);


  /** \default Specifies the material for a heightfield HeightField along with the low order
               bits of the material index stored in each heightfield sample
      \default 0
      \note When the shape is attached, this function does nothing.
  */
                           void               setHighBits(MaterialIdentifier = 0);


  /** \brief  This sets the scale of the heightField to the following formula.
      <code>
              rowScale = size.x / nbRows;
              columnScale = size.z / nbColumns;
              heightScale = size.y / 32768.0f;
      </code>
      \see   HeightFieldGeometry::setScale, if want to directly adjust the scale. 
  */
                           void               setSize(const Vec3& size);

  /** \brief This sets the scale directly, without modification.
      \see   HeightFieldGeometry::setSize.
  */
                           void               setScale(const Vec3& scale);

  /** \brief Gets the heightfield height scale.
  */
                           Real               getHeightScale(void) const;

  /** \brief Gets the heightfield row scale.
  */
                           Real               getRowScale(void) const;

  /** \brief Gets the heightfield column scale.
  */
                           Real               getColumnScale(void) const;

  /** \brief Finds triangles touching the input bounds.
      \params bounds The Bounds to test against.
      \params queryFlags If the bounds are in world or local space, and if we return first contact only. See Enums::QueryFlags
      \params callback Used if the triangles overlay the AABB.
      \return True if there is an overlap.
  */
                           bool               overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const;

  /** \brief Sets the heightfield height scale.
  */
                           void               setHeightScale(Real scale);

  /** \brief Sets the heightfield row scale.
  */
                           void               setRowScale(Real scale);

  /** \brief Sets the heightfield column scale.
  */
                           void               setColumnScale(Real scale);

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


  /** \brief   Checks if the point in shape space projects onto the height field surface. 
  */
                           bool               isPointOnHeightField(const Vec2&);

  /** \brief   Checks if the point in shape space projects onto the height field surface. 
  */
                           bool               isPointOnHeightField(Real x, Real z);

  /** \brief   Returns the material index at the given point in shape space.
               The return value is the 7 low order bits as set in the samples array.
               The value may be compared directly with the hole material to determine if the heightfield has a hole at the given point. 
      \note    The low bits material index, or 0xFFFF if the point is out of range.
  */
                           MaterialIdentifier getMaterialAt(const Vec2&);

  /** \brief   Returns the material index at the given point in shape space.
               The return value is the 7 low order bits as set in the samples array.
               The value may be compared directly with the hole material to determine if the heightfield has a hole at the given point. 
      \note    The low bits material index, or 0xFFFF if the point is out of range.
  */
                           MaterialIdentifier getMaterialAt(Real x, Real z);

  /** \brief   Returns the normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
                           Vec3              getNormalAt(Real x, Real z);

  /** \brief   Returns the normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
                           Vec3              getNormalAt(const Vec2&);

  /** \brief   Returns the normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
                           Vec3              getSmoothNormalAt(Real x, Real z);

  /** \brief   Returns the smooth normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
                           Vec3              getSmoothNormalAt(const Vec2&);
  
  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxHeightFieldShape*     mHeightFieldShape;

                      HeightField*            mHeightField;
  
}; // class HeightFieldGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
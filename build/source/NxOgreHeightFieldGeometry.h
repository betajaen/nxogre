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

                                                                                       

#ifndef NXOGRE_HEIGHTFIELDGEOMETRY_H
#define NXOGRE_HEIGHTFIELDGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass HeightFieldGeometry : public Shape
{
  
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  

  unsigned int getShapeType() const;

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
  Enums::ShapeFunctionType   getShapeFunctionType() const;
  
  /** \brief HeightField in Use.
  */
  HeightField*  getHeightField() const;

  /** \brief  This sets the scale of the heightField to the following formula.
      <code>
              rowScale = size.x / nbRows;
              columnScale = size.z / nbColumns;
              heightScale = size.y / 32768.0f;
      </code>
      \see   HeightFieldGeometry::setScale, if want to directly adjust the scale. 
  */
  void  setSize(const Vec3& size);

  /** \brief This sets the scale directly, without modification.
      \see   HeightFieldGeometry::setSize.
  */
  void  setScale(const Vec3& scale);

  /** \brief Gets the heightfield height scale.
  */
  Real  getHeightScale() const;

  /** \brief Gets the heightfield row scale.
  */
  Real  getRowScale() const;

  /** \brief Gets the heightfield column scale.
  */
  Real  getColumnScale() const;

  /** \brief Finds triangles touching the input bounds.
      \params bounds The Bounds to test against.
      \params queryFlags If the bounds are in world or local space, and if we return first contact only. See Enums::QueryFlags
      \params callback Used if the triangles overlay the AABB.
      \return True if there is an overlap.
  */
  bool  overlapAAABTriangles(const Bounds3& bounds, unsigned int queryFlags, EntityReport<Index>* callback) const;

  /** \brief Sets the heightfield height scale.
  */
  void  setHeightScale(Real scale);

  /** \brief Sets the heightfield row scale.
  */
  void  setRowScale(Real scale);

  /** \brief Sets the heightfield column scale.
  */
  void  setColumnScale(Real scale);

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


  /** \brief   Checks if the point in shape space projects onto the height field surface. 
  */
  bool  isPointOnHeightField(const Vec2&);

  /** \brief   Checks if the point in shape space projects onto the height field surface. 
  */
  bool  isPointOnHeightField(Real x, Real z);

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
  Vec3  getNormalAt(Real x, Real z);

  /** \brief   Returns the normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
  Vec3  getNormalAt(const Vec2&);

  /** \brief   Returns the normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
  Vec3  getSmoothNormalAt(Real x, Real z);

  /** \brief   Returns the smooth normal of the heightfield surface at the given point in shape space.
      \return  The normal or Real3_Zero if the coordinates are out of range
  */
  Vec3  getSmoothNormalAt(const Vec2&);
  
  /*! desc. saveToDescription
  */
  void saveToDescription(HeightFieldGeometryDescription&);
  
  protected:
  
  /** \brief HeightFieldGeometry
  */
  HeightFieldGeometry(NxHeightFieldShape*, HeightField*, bool isDirty = false);
  
  /** \brief HeightFieldGeometry
  */
 ~HeightFieldGeometry();
  
  protected:
  
  NxHeightFieldShape*     mHeightFieldShape;
  
  HeightField*            mHeightField;
  
}; // class HeightFieldGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
/** File: NxOgreShapeBlueprint.h
    Created on: 5-Apr-09
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

#ifndef NXOGRE_SHAPEBLUEPRINT_H
#define NXOGRE_SHAPEBLUEPRINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A ShapeBlueprint is a possible configuration for Box, Spheres, Capsules, Convex and TriangleGeometry shapes.
*/
class NxOgrePublicClass ShapeBlueprint : public PointerClass<Classes::_ShapeBlueprint>
{
  
  public:
  
  /** \brief Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
                                              ShapeBlueprint();
  
  /** \brief Required destructor
  */
  virtual                                    ~ShapeBlueprint();
  
  
  /** \brief Resets the member variables to their default values according to the PhysX SDK.
  */
  virtual               void                  reset();

  /** \brief
  */
                        Matrix44              mLocalPose;

  /** \brief
  */
                        unsigned int          mFlags;

  /** \brief
  */
                        GroupIdentifier       mGroup;

  /** \brief
  */
                        MaterialIdentifier    mMaterial;

  /** \brief
  */
                        Mesh*                 mSkeleton;

  /** \brief
  */
                        Real                  mDensity;

  /** \brief
  */
                        Real                  mMass;

  /** \brief
  */
                        Real                  mSkinWidth;
  
  /** \brief
  */
                        int4                  mGroupsMask;
  
  /** \brief
  */
                        unsigned int          mShapesCompartmentTypes;
  
  /** \brief Size or Scale of the Shape.
  */
                        Vec4                  mSize;
  
  /** \brief TriangleGeometry mesh flags
      \see  NxOgre::Enums::MeshFlags
  */
                       unsigned int           mMeshFlags;

  /** \brief Convex or Triangle Mesh.
  */
                        Mesh*                 mMesh;
  
}; // class ShapeBlueprint

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

#ifndef NXOGRE_HEIGHTFIELDGEOMETRYSHAPEDESCRIPTION_H
#define NXOGRE_HEIGHTFIELDGEOMETRYSHAPEDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       


/** \brief A ShapeDescription is a possible configuration for Box, Spheres, Capsules, Convex and TriangleGeometry shapes.
*/
class NxOgrePublicClass HeightFieldGeometryDescription : public ShapeDescription
{
  
  public:
  
  /*! constructor. HeightFieldDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  HeightFieldGeometryDescription(HeightField*, const Vec3& dimensions, Enums::TerrainCentering = Enums::TerrainCentering_LocalPose);

   /*! constructor. HeightFieldDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  HeightFieldGeometryDescription(HeightField*, Real dimensions_x, Real dimensions_y, Real dimensions_z, Enums::TerrainCentering = Enums::TerrainCentering_LocalPose);
  
  /*! constructor. HeightFieldDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  HeightFieldGeometryDescription(HeightField*, const Vec3& dimensions, const Matrix44& local_pose);

   /*! constructor. HeightFieldDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  HeightFieldGeometryDescription(HeightField* = 0, Real dimensions_x = 1, Real dimensions_y = 1, Real dimensions_z = 1, const Matrix44& local_pose = Matrix44::IDENTITY);
  
  /*! destructor.
      desc.
          Required destructor
  */
 ~HeightFieldGeometryDescription();
  
  /*! function. createShapeDescription
      desc.
          Create NxBoxShapeDesc to be attached to an RigidBody.
          This is an internal function and shouldn't be used in the User's app.
      note.
         Pointer is owned by the class/function calling it, and should be deleted when no longer used.
  */
  NxShapeDesc*  createShapeDescription() const;

  /*! function. reset
      desc.
          Resets the member variables to their default values according to the PhysX SDK.
  */
  void reset();
  
  /*! variable. mHeightField
      desc.
          HeightField to use.
  */
  HeightField*  mHeightField;
  
  /*! variable. mDimensions
      desc.
          Dimensions of the heightfield. See mScaleDimensions 
  */
  Vec3 mDimensions;
  
  /*! variable. mScaleDimensions
      desc.
          Treat the dimensions as a scale or as a size.
      default.
          false (A size)
  */
  bool mScaleDimensions;
  
  /** \brief Terrain Centering to use.
      \default Enums::TerrainCentering_UseLocalPose
  */
  Enums::TerrainCentering mTerrainCentering;
 
  /** \brief Use smooth sphere collisions
      \default false
  */
  bool  mSmoothSphereCollisions;

  /** \default Material indexes for HeightFields, which RigidBody's can pass through.
      \default 65535
  */
  MaterialIdentifier  mHoleMaterial;

  /** \default Specifies the material for a heightfield HeightField along with the low order
               bits of the material index stored in each heightfield sample
      \default 0
  */
  MaterialIdentifier  mHighBits;
  
  /** \default 0 
  **/
  unsigned int mMeshFlags;
  
}; // class HeightFieldGeometryDescription



                                                                                       

} // namespace NxOgre

                                                                                       

#endif

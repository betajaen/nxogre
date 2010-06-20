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

                                                                                       

/*! class. HeightFieldGeometryDescription
    desc.
         Description to describe a Heightfield Geometry shape.
    properties.
      HeightField*  mHeightField -- HeightField to use. default: NULL
      Vec3 mDimensions -- Dimensions of the heightfield. (See mScaleDimensions)  default: mDimensions.set(1,1,1)
      bool mScaleDimensions -- Treat the dimensions as a scale or as a size. default: false
      Enums::TerrainCentering mTerrainCentering -- Terrain Centering to use. (See Enums::TerrainCentering_UseLocalPose) default: Enums::TerrainCentering_LocalPose
      bool mSmoothSphereCollisions -- Use smooth sphere collisions default: false
      MaterialIdentifier  mHoleMaterial -- Material indexes for HeightFields, which RigidBody's can pass through. default: 65535
      MaterialIdentifier  mHighBits -- Specifies the material for a heightfield HeightField along with the low order bits of the material index stored in each heightfield sample. default: 0
      unsigned mMeshFlags -- Flags default: 0
    validations.
      mHeightField pointer cannot be null -- mHeightField == NULL
    namespace. NxOgre
    from. ShapeDescription
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
 
 protected:
  
  /*! function. createShapeDescription
      desc.
          Create NxBoxShapeDesc to be attached to an RigidBody.
          This is an internal function and shouldn't be used in the User's app.
      note.
         Pointer is owned by the class/function calling it, and should be deleted when no longer used.
  */
  NxShapeDesc*  createShapeDescription() const;
  


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mDimensions
      desc.
          Dimensions of the heightfield. (See mScaleDimensions)
      default.
          mDimensions.set(1,1,1)
  */
  Vec3 mDimensions;

  /*! variable. mHeightField
      desc.
          HeightField to use.
      default.
          NULL
      condition.
          mHeightField pointer cannot be null
  */
  HeightField* mHeightField;

  /*! variable. mHighBits
      desc.
          Specifies the material for a heightfield HeightField along with the low order bits of the material index stored in each heightfield sample.
      default.
          0
  */
  MaterialIdentifier mHighBits;

  /*! variable. mHoleMaterial
      desc.
          Material indexes for HeightFields, which RigidBody's can pass through.
      default.
          65535
  */
  MaterialIdentifier mHoleMaterial;

  /*! variable. mMeshFlags
      desc.
          Flags
      default.
          0
  */
  unsigned mMeshFlags;

  /*! variable. mScaleDimensions
      desc.
          Treat the dimensions as a scale or as a size.
      default.
          false
  */
  bool mScaleDimensions;

  /*! variable. mSmoothSphereCollisions
      desc.
          Use smooth sphere collisions
      default.
          false
  */
  bool mSmoothSphereCollisions;

  /*! variable. mTerrainCentering
      desc.
          Terrain Centering to use. (See Enums::TerrainCentering_UseLocalPose)
      default.
          Enums::TerrainCentering_LocalPose
  */
  Enums::TerrainCentering mTerrainCentering;

  /*! constructor. HeightFieldGeometryDescription
      desc.
          Copy constructor for HeightFieldGeometryDescription
  */
  HeightFieldGeometryDescription(const HeightFieldGeometryDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  HeightFieldGeometryDescription& operator=(const HeightFieldGeometryDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this HeightFieldGeometryDescription as a pointer.
  */
  virtual HeightFieldGeometryDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of HeightFieldGeometryDescription into another.
  */
  virtual void copy_into(HeightFieldGeometryDescription*) const;

  /*! function. reset
      desc.
          Resets HeightFieldGeometryDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this HeightFieldGeometryDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "HeightFieldGeometryDescription-7faef2e0f69977508662fcb8cdce9424"

}; // class HeightFieldGeometryDescription



                                                                                       

} // namespace NxOgre

                                                                                       

#endif

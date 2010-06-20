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

                                                                                       

#ifndef NXOGRE_TRIANGLEGEOMETRYDESCRIPTION_H
#define NXOGRE_TRIANGLEGEOMETRYDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. TriangleGeometryDescription
    desc.
      Description to describe a TriangleGeometry shape.
    properties.
      Mesh* mMesh -- Mesh to use. default: NULL
      unsigned int mMeshFlags -- Mesh flags (see Enums::MeshFlags). default: 0
      Enums::MeshPagingMode mMeshPagingMode -- Paging mode. default: Enums::MeshPagingMode_Manual
    conditions.
      mMesh must not be a pointer -- (mMesh == NULL)
      mMesh must be a triangle mesh -- (mMesh->getType() != Enums::MeshType_Triangle)
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass TriangleGeometryDescription : public ShapeDescription
{
  
  public:
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  TriangleGeometryDescription(Mesh* = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! destructor.
      desc.
          Required destructor
  */
 ~TriangleGeometryDescription();
  
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

  /*! variable. mMesh
      desc.
          Mesh to use.
      default.
          NULL
  */
  Mesh* mMesh;

  /*! variable. mMeshFlags
      desc.
          Mesh flags (see Enums::MeshFlags).
      default.
          0
  */
  unsigned int mMeshFlags;

  /*! variable. mMeshPagingMode
      desc.
          Paging mode.
      default.
          Enums::MeshPagingMode_Manual
  */
  Enums::MeshPagingMode mMeshPagingMode;

  /*! constructor. TriangleGeometryDescription
      desc.
          Copy constructor for TriangleGeometryDescription
  */
  TriangleGeometryDescription(const TriangleGeometryDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  TriangleGeometryDescription& operator=(const TriangleGeometryDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this TriangleGeometryDescription as a pointer.
  */
  virtual TriangleGeometryDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of TriangleGeometryDescription into another.
  */
  virtual void copy_into(TriangleGeometryDescription*) const;

  /*! function. reset
      desc.
          Resets TriangleGeometryDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this TriangleGeometryDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "TriangleGeometryDescription-d9af3a15f5bb0ae28aeab780b06786f9"

}; // class BoxDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

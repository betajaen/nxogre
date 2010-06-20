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

                                                                                       

#ifndef NXOGRE_CONVEXDESCRIPTION_H
#define NXOGRE_CONVEXDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ConvexDescription
    desc.
         Description to describe a Capsule shape.
    properties.
      Mesh* mMesh -- Convex mesh to use default: NULL
      unsigned int mMeshFlags -- Flags to use (See Enums::MeshFlags) default: 0
    validations.
      mMesh pointer cannot be null -- mMesh == NULL
      mMesh must be a convex mesh -- (mMesh->getType() != Enums::MeshType_Convex)
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass ConvexDescription : public ShapeDescription
{
  
  public:
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  ConvexDescription(Mesh* = 0, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! destructor.
      desc.
          Required destructor
  */
 ~ConvexDescription();
  
 protected:
  
  NxShapeDesc*  createShapeDescription() const;

 

  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mMesh
      desc.
          Convex mesh to use
      default.
          NULL
      condition.
          mMesh must be a convex mesh
  */
  Mesh* mMesh;

  /*! variable. mMeshFlags
      desc.
          Flags to use (See Enums::MeshFlags)
      default.
          0
  */
  unsigned int mMeshFlags;

  /*! constructor. ConvexDescription
      desc.
          Copy constructor for ConvexDescription
  */
  ConvexDescription(const ConvexDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  ConvexDescription& operator=(const ConvexDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this ConvexDescription as a pointer.
  */
  virtual ConvexDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of ConvexDescription into another.
  */
  virtual void copy_into(ConvexDescription*) const;

  /*! function. reset
      desc.
          Resets ConvexDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this ConvexDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "ConvexDescription-24193e472d6f1101b59bc83412b4f9a3"

}; // class ConvexDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

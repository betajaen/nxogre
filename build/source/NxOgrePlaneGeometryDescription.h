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

                                                                                       

#ifndef NXOGRE_PLANEGEOMETRYDESCRIPTION_H
#define NXOGRE_PLANEGEOMETRYDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. PlaneGeometryDescription
    desc.
      Description to describe a Plane Geometry shape.
    properties.
      Vec3 mNormal -- Normal of the plane default. default: mNormal.set(0,1,0)
      Real mDistance -- Distance from the world scene. default: 0
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass PlaneGeometryDescription : public ShapeDescription
{
  
  public:

  /*! constructor. PlaneGeometryDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  PlaneGeometryDescription(const Vec3& normal = Vec3(0, 1, 0), Real distance = 0, const MaterialIdentifier& material = 0);

  /*! destructor.
      desc.
          Required destructor
  */
 ~PlaneGeometryDescription();
  
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

  /*! variable. mDistance
      desc.
          Distance from the world scene.
      default.
          0
  */
  Real mDistance;

  /*! variable. mNormal
      desc.
          Normal of the plane default.
      default.
          mNormal.set(0,1,0)
  */
  Vec3 mNormal;

  /*! constructor. PlaneGeometryDescription
      desc.
          Copy constructor for PlaneGeometryDescription
  */
  PlaneGeometryDescription(const PlaneGeometryDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  PlaneGeometryDescription& operator=(const PlaneGeometryDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this PlaneGeometryDescription as a pointer.
  */
  virtual PlaneGeometryDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of PlaneGeometryDescription into another.
  */
  virtual void copy_into(PlaneGeometryDescription*) const;

  /*! function. reset
      desc.
          Resets PlaneGeometryDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this PlaneGeometryDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "PlaneGeometryDescription-feeb338654014916cbab924900fc2cc3"

}; // class PlaneGeometryDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

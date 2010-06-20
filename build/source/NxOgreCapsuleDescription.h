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

                                                                                       

#ifndef NXOGRE_CAPSULEDESCRIPTION_H
#define NXOGRE_CAPSULEDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. CapsuleDescription
    desc.
         Description to describe a Capsule shape.
    properties.
      Real mHeight -- Height of the capsule default: 1.0
      Real mRadius -- Radius of the capsule default: 1.0
    validations.
      mReal cannot have negative or zero values -- mSize <= 0
      mRadius cannot have negative or zero values -- mSize <= 0
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass CapsuleDescription : public ShapeDescription
{
  
  public:
  
   /*! constructor. CapsuleDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  CapsuleDescription(Real radius = 1, Real height = 1, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

   /*! constructor. CapsuleDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  CapsuleDescription(const Vec2& size, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! destructor.
      desc.
          Required destructor
  */
  ~CapsuleDescription();
  
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

  /*! variable. mHeight
      desc.
          Height of the capsule
      default.
          1.0
  */
  Real mHeight;

  /*! variable. mRadius
      desc.
          Radius of the capsule
      default.
          1.0
  */
  Real mRadius;

  /*! constructor. CapsuleDescription
      desc.
          Copy constructor for CapsuleDescription
  */
  CapsuleDescription(const CapsuleDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  CapsuleDescription& operator=(const CapsuleDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this CapsuleDescription as a pointer.
  */
  virtual CapsuleDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of CapsuleDescription into another.
  */
  virtual void copy_into(CapsuleDescription*) const;

  /*! function. reset
      desc.
          Resets CapsuleDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this CapsuleDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "CapsuleDescription-900f57fddac29d8ea93d837ad5aae159"

}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

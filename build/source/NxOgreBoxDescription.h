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

                                                                                       

#ifndef NXOGRE_BOXDESCRIPTION_H
#define NXOGRE_BOXDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. BoxDescription
    desc.
         Description to describe a Box shape.
    properties.
      Vec3 mSize -- Size of the Box default: mSize.set(1,1,1)
    validations.
       mSize cannot have negative or zero values -- mSize.isNegative() || mSize.isZero()
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass BoxDescription : public ShapeDescription
{
  
  friend class RigidBody;
  
  public:
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  BoxDescription(const Vec3& size, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

   /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  BoxDescription(Real width, Real height, Real depth, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

   /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  BoxDescription(Real combined_width_height_and_depth = 1, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! destructor.
      desc.
          Required destructor
  */
  ~BoxDescription();

  protected:

  virtual NxShapeDesc* createShapeDescription() const;


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mSize
      desc.
          Size of the Box
      default.
          mSize.set(1,1,1)
      condition.
          mSize cannot have negative or zero values
  */
  Vec3 mSize;

  /*! constructor. BoxDescription
      desc.
          Copy constructor for BoxDescription
  */
  BoxDescription(const BoxDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  BoxDescription& operator=(const BoxDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this BoxDescription as a pointer.
  */
  virtual BoxDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of BoxDescription into another.
  */
  virtual void copy_into(BoxDescription*) const;

  /*! function. reset
      desc.
          Resets BoxDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this BoxDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "BoxDescription-885a63d715651674dfb3ebaeec29b0d0"

}; // class BoxDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
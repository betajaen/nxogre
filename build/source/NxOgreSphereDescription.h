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

                                                                                       

#ifndef NXOGRE_SPHEREDESCRIPTION_H
#define NXOGRE_SPHEREDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. SphereDescription
    desc.
      Description to describe a Sphere shape.
    properties.
      Real mRadius -- Radius of the Sphere. default: 0.5
    conditions.
      mRadius must be positive and not zero in length -- (mRadius <= 0.0f)
    namespace. NxOgre
    from. ShapeDescription
*/
class NxOgrePublicClass SphereDescription : public ShapeDescription
{
  
  public:
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  SphereDescription(Real radius = 0.5, const MaterialIdentifier& material = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! destructor.
      desc.
          Required destructor
  */
  ~SphereDescription();
  
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

  /*! variable. mRadius
      desc.
          Radius of the Sphere.
      default.
          0.5
  */
  Real mRadius;

  /*! constructor. SphereDescription
      desc.
          Copy constructor for SphereDescription
  */
  SphereDescription(const SphereDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  SphereDescription& operator=(const SphereDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this SphereDescription as a pointer.
  */
  virtual SphereDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of SphereDescription into another.
  */
  virtual void copy_into(SphereDescription*) const;

  /*! function. reset
      desc.
          Resets SphereDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this SphereDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "SphereDescription-a578ff25dea9c20bad4bad903f3efec2"

}; // class SphereDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

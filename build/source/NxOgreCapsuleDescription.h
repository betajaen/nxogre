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
    desc. A ShapeDescription is a possible configuration for Box, Spheres, Capsules, Convex and TriangleGeometry shapes.
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

  /*! function. reset
      desc.
          Resets the member variables to their default values according to the PhysX SDK.
  */
  void reset();
  
  /*! function. isValid
      desc. 
          Returns true if the description is valid.
  */
  bool isValid() const;
  
  /*! variable. mRadius
      desc.
          Radius of the capsule
  */
  Real mRadius;
  

  /*! variable. mHeight
      desc.
          Distance between the center of top and center of the bottom hemispheres of the capsule.
  */
  Real mHeight;

}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

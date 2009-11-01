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

                                                                                       

/** \brief A ShapeDescription is a possible configuration for Box, Spheres, Capsules, Convex and TriangleGeometry shapes.
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
  
  /*! function. createShapeDescription
      desc.
          Create NxBoxShapeDesc to be attached to an RigidBody.
          This is an internal function and shouldn't be used in the User's app.
      note.
         Pointer is owned by the class/function calling it, and should be deleted when no longer used.
         userData variable is the Mesh pointer assigned to the Shape. The Mesh is assigned to the userData
         for speed reasons, and replaced with a PhysXPointer once the Convex shape has been created.
  */
  NxShapeDesc*  createShapeDescription() const;

  /*! function. reset
      desc.
          Resets the member variables to their default values according to the PhysX SDK.
  */
  void reset();
  
  /*! variable. mMesh
      desc.
          Mesh to use.
  */
  Mesh* mMesh;
  
  /*! variable. mMeshFlags
      desc.
          Mesh flags to set.
  */
  unsigned int mMeshFlags;
  
}; // class ConvexDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

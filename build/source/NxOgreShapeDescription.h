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

                                                                                       

#ifndef NXOGRE_SHAPEBLUEPRINT_H
#define NXOGRE_SHAPEBLUEPRINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A ShapeDescription is a possible configuration for Box, Spheres, Capsules, Convex and TriangleGeometry shapes.
*/
class NxOgrePublicClass ShapeDescription : public GenericBasedAllocatable
{
  
  public:
  
  /** \brief Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  ShapeDescription();
  
  /** \brief Required destructor
  */
  virtual  ~ShapeDescription();
  
  
  /** \brief Resets the member variables to their default values according to the PhysX SDK.
  */
  virtual  void  reset(const MaterialIdentifier& = 0, const Matrix44& local_pose = Matrix44::IDENTITY);

  /*! function. createShapeDescription
      desc.
          Create the shape description
  */
  virtual NxShapeDesc* createShapeDescription() const;
  
  /*! function. isValid
  */
  virtual bool isValid() const;
  
  /** \brief
  */
  Matrix44              mLocalPose;

  /** \brief
  */
  unsigned int          mFlags;

  /** \brief
  */
  GroupIdentifier       mGroup;

  /** \brief
  */
  MaterialIdentifier    mMaterial;

  /** \brief
  */
  Mesh*                 mSkeleton;

  /** \brief
  */
  Real                  mDensity;

  /** \brief
  */
  Real                  mMass;

  /** \brief
  */
  Real                  mSkinWidth;
  
  /** \brief
  */
  GroupsMask            mGroupsMask;
  
  /** \brief
  */
  unsigned int          mShapesCompartmentTypes;
  
  /*! variable. mNonInteractingCompartmentTypes
  */
  unsigned int          mNonInteractingCompartmentTypes;

 protected:
  
  /*! function. setShapeDescription
      desc.
          
  */
  void setShapeDescription(NxShapeDesc*) const;
  
}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

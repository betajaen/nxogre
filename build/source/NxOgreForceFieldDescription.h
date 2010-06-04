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

                                                                                       

#ifndef NXOGRE_FORCEFIELDDESCRIPTION_H
#define NXOGRE_FORCEFIELDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreSimple.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ForceFieldDescription
{
  
  public: // Functions
  
  /** \brief ForceFieldDescription constructor, all it does is call RigidBodyDescription::reset.
  */
  ForceFieldDescription();
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void  reset();
  
  /** \brief Returns if the variables are in a valid range or not
  */
  bool  valid();
  
  /** \brief Clone the properties of this into another ForceFieldDescription or a class derived from it.
  */
  void  clone(ForceFieldDescription& target) const;

  /*! variable. mPose
      desc.
          Global (Or relative if RigidBody is set) transformation of the forcefield.
      default.
           Matrix44_Identity
  */
  Matrix44   mPose;
  
  /*! variable. mRigidBody
      desc.
          The Field's pose is relative to the RigidBody's pose and relative to the world frame if field is null.
      default.
          NULL
  */
  RigidBody*  mRigidBody;

  /*! variable. mCoordinates
      desc.
          Coordinate system of the field.
      default.
          Enums::CoordinateSystem_Cartesian
  */
  Enums::CoordinateSystem  mCoordinates;

  /*! variable. mGroup
      desc.
          Collision group used for collision filtering
      default.
          0
  */
  GroupIdentifier mGroup;
  
  /*! variable. mGroupsMask
      desc.
          Groups mask used for collision filtering.
      default.
          0
  */
  GroupsMask  mGroupsMask;
  
  /*! variable. mVariety
      desc.
          Force Field Variety index
      default.
          0
  */
  unsigned short mVariety;

  /*! variable. mFluidType
      desc.
          Force field type for fluids
      default.
          Enums::ForceFieldType_Other
  */
  Enums::ForceFieldType  mFluidType;

  /*! variable. mClothType
      desc.
          Force field type for cloth
      default.
          Enums::ForceFieldType_Other
  */
  Enums::ForceFieldType  mClothType;

  /*! variable. mSoftBodyType
      desc.
          Force field type for Soft bodies
      default.
          Enums::ForceFieldType_Other
  */
  Enums::ForceFieldType  mSoftBodyType;

  /*! variable. mRigidBodyType
      desc.
          Force field type for Rigid bodies.
      default.
          Enums::ForceFieldType_Other
  */
  Enums::ForceFieldType  mRigidBodyType;

  /*! variable. mFlags
      desc.
          Force field type for Rigid bodies.
      default.
           ForceFieldFlag_ScalingFluid | ForceFieldFlag_ScalingCloth | ForceFieldFlag_ScalingSoftBody | ForceFieldFlag_ScalingRigidBody
  */
  int  mFlags;
  
  /*! variable. mIncludeGroupShapes
      desc.
          Array of force field shapes descriptors which will be created inside the include group of this force field. This group moves with the force field and cannot be shared. 
      note.
          Pass the shapes on as references, not as pointers. As they will not be deleted by the Forcefield.
      example.
          bc. SimpleBox box(Vec3(1,8,1));
              ForceFieldDescription desc;
              desc.mIncludeGroupShapes.push_back(&box);
  */
  SimpleShapes mIncludeGroupShapes;

  /*! variable. mIncludeGroupShapes
      desc.
          Array of force field shapes descriptors which will be created inside the include group of this force field. This group moves with the force field and cannot be shared. 
      note.
          Pass the shapes on as references, not as pointers. As they will not be deleted by the Forcefield.
      example.
          bc. SimpleBox box(Vec3(1,8,1));
              ForceFieldDescription desc;
              desc.mShapeGroups.push_back(&box);
  */
  //SimpleShapes mShapeGroups;


  /*! variable. Name
  */
  String mName;

}; // class ForceFieldDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

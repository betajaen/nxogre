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

                                                                                       

#ifndef NXOGRE_SHAPEDESCRIPTION_H
#define NXOGRE_SHAPEDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreShapeFlags.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ShapeDescription
    desc.
         Generic Description for Shapes, inherited by BoxDescription, SphereDescription, etc.
    note.
         You should never need to create this class directly. Use a more specific shape description instead.
    properties.
      unsigned int mId -- Optional id of the ship. This is stored as a unsigne int instead of a string for memory reasons. default: 0
      Matrix44 mLocalPose -- The pose of the shape relative to the owning RigidBody. default: mLocalPose.identity()
      ShapeFlags mFlags -- Shape flags default: mFlags.reset()
      GroupIdentifier mGroup -- Shape Group to be assigned to. default: 0
      MaterialIdentifier mMaterial -- Material index of the shape. default: 0
      Mesh* mSkeleton -- CCD Skeleton to use. default: 0
      Real mDensity -- Density when computing mass for internal properties for a rigid body. default: 1.0
      Real mMass -- Mass of this shape when computing mass for internal properties for a rigid body. (Set to -1.0 to compute from density). default: -1.0
      Real mSkinWidth -- How much a shape can interpenetrate with each other. (Set to -1.0 to use global Skin width property). default: -1.0
      GroupsMask mGroupsMask -- Group bit mask for collision filtering. default: mGroupsMask.zero()
      unsigned int mNonInteractingCompartmentTypes -- Flags of what the shape should not interact with (See Enums::ShapeCompartmentType). default: 0
    validations.
       mGroup index should be in the first 32 groups -- (mGroup >= 32)
       mSkinwidth can be only -1.0 when negative -- (skinWidth != -1 && skinWidth < 0)
    namespace. NxOgre
*/
class NxOgrePublicClass ShapeDescription : public GenericBasedAllocatable
{
  
  friend class RigidBody;
  
  public:

  ShapeDescription();
  
  virtual  ~ShapeDescription();
  
  protected:
  
  virtual NxShapeDesc* createShapeDescription() const;
 
  void setShapeDescription(NxShapeDesc* description) const;


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mDensity
      desc.
          Density when computing mass for internal properties for a rigid body.
      default.
          1.0
  */
  Real mDensity;

  /*! variable. mFlags
      desc.
          Shape flags
      default.
          mFlags.reset()
  */
  ShapeFlags mFlags;

  /*! variable. mGroup
      desc.
          Shape Group to be assigned to.
      default.
          0
      condition.
          mGroup index should be in the first 32 groups
  */
  GroupIdentifier mGroup;

  /*! variable. mGroupsMask
      desc.
          Group bit mask for collision filtering.
      default.
          mGroupsMask.zero()
  */
  GroupsMask mGroupsMask;

  /*! variable. mId
      desc.
          Optional id of the ship. This is stored as a unsigne int instead of a string for memory reasons.
      default.
          0
  */
  unsigned int mId;

  /*! variable. mLocalPose
      desc.
          The pose of the shape relative to the owning RigidBody.
      default.
          mLocalPose.identity()
  */
  Matrix44 mLocalPose;

  /*! variable. mMass
      desc.
          Mass of this shape when computing mass for internal properties for a rigid body. (Set to -1.0 to compute from density).
      default.
          -1.0
  */
  Real mMass;

  /*! variable. mMaterial
      desc.
          Material index of the shape.
      default.
          0
  */
  MaterialIdentifier mMaterial;

  /*! variable. mNonInteractingCompartmentTypes
      desc.
          Flags of what the shape should not interact with (See Enums::ShapeCompartmentType).
      default.
          0
  */
  unsigned int mNonInteractingCompartmentTypes;

  /*! variable. mSkeleton
      desc.
          CCD Skeleton to use.
      default.
          0
  */
  Mesh* mSkeleton;

  /*! variable. mSkinWidth
      desc.
          How much a shape can interpenetrate with each other. (Set to -1.0 to use global Skin width property).
      default.
          -1.0
  */
  Real mSkinWidth;

  /*! constructor. ShapeDescription
      desc.
          Copy constructor for ShapeDescription
  */
  ShapeDescription(const ShapeDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  ShapeDescription& operator=(const ShapeDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this ShapeDescription as a pointer.
  */
  virtual ShapeDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of ShapeDescription into another.
  */
  virtual void copy_into(ShapeDescription*) const;

  /*! function. reset
      desc.
          Resets ShapeDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this ShapeDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "ShapeDescription-11f697d54f71eb074e1517ee08161adc"

}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

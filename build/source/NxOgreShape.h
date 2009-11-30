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

                                                                                       

#ifndef NXOGRE_SHAPE_H
#define NXOGRE_SHAPE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Shape
    desc.
         A shape is a piece of geometry used by itself or with others in an RigidBody to
         to physically collide with other RigidBodies and take actions against that collision.
*/
class NxOgrePublicClass Shape : public ShapeAllocatable
{
  
  friend class RigidBody;
  template<class T> friend inline void Functions::safe_delete(T*);

  public:
  
  /** \brief Get the c++ type of shape (as Classes::_ShapeName)
  */
  virtual unsigned int  getShapeType() const = 0;
  
  /** \brief Get the shape type based upon the NxShapeType enum.
  */
  Enums::ShapeFunctionType   getShapeFunctionType() const;
  
  /** \brief Get the NxShape (abstract)
  */
  NxShape*  getAbstractShape() const;
  
  /** \brief Get the name of the shape
  */
  StringHash  getNameHash() const;
  
  /** \brief Get the name of the shape
  */
  String  getName() const;
  
  /** \brief Set the name of the shape
  */
  void  setName(const String&);
  
  /** \brief Get the local pose of the shape
  */
  Matrix44  getLocalPose() const;
  
  /** \brief Set the local pose of the shape when attached.
  */
  void  setLocalPose(const Matrix44&);
  
  /** \brief Get the global pose of the shape
  */
  Matrix44  getGlobalPose() const;
  
  /** \brief Set the global pose of the shape when attached.
  */
  void setGlobalPose(const Matrix44&);
  
  /** \brief Get the flags of the shape
  */
  bool  getFlag(Enums::ShapeFlags) const;
  
  /** \brief Set the flags of the shape when attached.
  */
   void  setFlag(Enums::ShapeFlags, bool enabled = true);
  
  /** \brief Get the group of the shape
  */
   GroupIdentifier  getGroup() const;
  
  /** \brief Set the group of the shape when attached.
  */
  void  setGroup(const GroupIdentifier&);
  
  /** \brief Get the material of the shape
  */
  MaterialIdentifier  getMaterial() const;
  
  /** \brief Set the material of the shape when attached.
  */
  void  setMaterial(const MaterialIdentifier&);
  
#if 0
  /** \brief Get the skeleton of the shape
  */
               Mesh*                   getSkeleton() const;
  
  /** \brief Set the skeleton of the shape when attached.
  */
               void                    setSkeleton(Mesh*);
#endif
  
  /** \brief Get the density of the shape
  */
  float  getSkinWidth() const;
  
  /** \brief Set the density of the shape.
  */
  void  setSkinWidth(const float&);
  
  /** \brief Get the density of the shape
  */
  GroupsMask  getGroupMask() const;
  
  /** \brief Set the density of the shape.
  */
  void  setGroupMask(const int4&);
  
  /** \brief Get the interacting compartment types of the shape
  */
  int  getInteractingCompartmentTypes() const;
  
  /** \brief Set the interacting compartment types of the shape
  */
  void  setInteractingCompartmentTypes(const int&);
  
  /** \brief Get the RigidBody this shape is attached to.
  */
  RigidBody* getRigidBody();

  protected:
  
  /* Optional name of the shape.
  */
  String mName;
  
  /* Optional hash of the name of the shape.
  */
  StringHash  mNameHash;
  
  /* Abstract Shape to be used with the non-specific functions
  */
  NxShape*  mShape;
  
  protected:
  
  /* Inherited class constructor
  */
  Shape(NxShape*);
  
  /* Inherited class constructor
  */
 ~Shape(void);
  
  /* Deattach and destroy the NxShape
     Note: The destructor does not call this, as the destructor of the NxActor would do it anyway.
  */
  void destroy();
  
}; // class Shape


                                                                                       

typedef std::vector<ShapeDescription> ShapeDescriptions;

/** \brief A collection of shapes that belong to a RigidBody (long term storage).
*/
typedef ptr_vector<Shape> CollisionModel;

/** \brief
*/
typedef ptr_vector<Shape>::const_iterator_t CollisionModelIterator;

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

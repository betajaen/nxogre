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

                                                                                       

/* \brief A shape is a piece of geometry used by itself or with others in an Actor to
          create a complete "collision model" for itself to physically collide and take
          actions against that collision.
*/
class NxOgrePublicClass Shape : public PointerClass<Classes::_Shape>
{
  friend class RigidBody;
  friend class ::NxOgre::Functions::NxShapeFunctions;

  public:
  
  /** \brief DO NOT CREATE MANUALLY.
  */
                                              Shape(ShapeBlueprint*);
  
  /** \brief Shape destructor.
  */
  virtual                                    ~Shape(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  virtual             void                    reset(void);
  
  /** \brief Is this shape attached to a RigidBody
  */
                      bool                    isAttached() const;
  
  /** \brief Returns if the variables are in a valid range or not.
  */
                      bool                    valid(void);
  
  /** \brief Get the shape type based upon the NxShapeType enum.
  */
  virtual          Enums::ShapeFunctionType   getShapeFunctionType() const;
  
  /** \brief Get the shape blueprint - if it has one, otherwise NULL.
  */
                      ShapeBlueprint*         getBlueprint();
  
  /** \brief Get the name of the shape
  */
  virtual             String                  getName() const;
  
  /** \brief Set the name of the shape
  */
  virtual             void                    setName(const String&);
  
  
  /** \brief Get the local pose of the shape
  */
  virtual             Matrix44                getLocalPose() const;
  
  /** \brief Set the local pose of the shape
  */
  virtual             void                    setLocalPose(const Matrix44&);
  
  
  /** \brief Get the global pose of the shape
  */
  virtual             Matrix44                getGlobalPose() const;
  
  /** \brief Set the global pose of the shape
  */
  virtual             void                    setGlobalPose(const Matrix44&);
   

  /** \brief Get the flags of the shape
  */
  virtual             bool                    getFlag(Enums::ShapeFlags) const;
  
  /** \brief Set the flags of the shape
  */
  virtual             void                    setFlag(Enums::ShapeFlags, bool enabled = true);
  
  
  /** \brief Get the group of the shape
  */
  virtual             GroupIdentifier         getGroup() const;
  
  /** \brief Set the group of the shape
  */
  virtual             void                    setGroup(const GroupIdentifier&);
  
  
  /** \brief Get the material of the shape
  */
  virtual             MaterialIdentifier      getMaterial() const;
  
  /** \brief Set the material of the shape
  */
  virtual             void                    setMaterial(const MaterialIdentifier&);
  
#if 0
  /** \brief Get the skeleton of the shape
  */
  virtual             Mesh*                   getSkeleton() const;
  
  /** \brief Set the skeleton of the shape
  */
  virtual             void                    setSkeleton(Mesh*);
#endif
  /** \brief Get the density of the shape
      \note  0 is returned when the shape is attached.
  */
  virtual             Real                    getDensity() const;
  
  /** \brief Set the density of the shape
      \note  Nothing happens when the shape is attached.
  */
  virtual             void                    setDensity(const float&);
  
  /** \brief Get the density of the shape
      \note  0 is returned when the shape is attached.
  */
  virtual             Real                    getMass() const;
  
  /** \brief Set the density of the shape
      \note  Nothing happens when the shape is attached.
  */
  virtual             void                    setMass(const float&);
  
  /** \brief Get the density of the shape
  */
  virtual             float                   getSkinWidth() const;
  
  /** \brief Set the density of the shape
  */
  virtual             void                    setSkinWidth(const float&);
  
  /** \brief Get the density of the shape
  */
  virtual             int4                    getGroupMask() const;
  
  /** \brief Set the density of the shape
  */
  virtual             void                    setGroupMask(const int4&);
  
  /** \brief Get the interacting compartment types of the shape
  */
  virtual             int                     getInteractingCompartmentTypes() const;
  
  /** \brief Set the interacting compartment types of the shape
  */
  virtual             void                    setInteractingCompartmentTypes(const int&);
  
  /** \brief Get the NxShape (abstract)
  */
                      NxShape*                getAbstractShape();

  /** \internal
  */
  virtual               void                  assign(NxShape*) {}
  
  protected:
  
  /** \brief Optional name of the Shape
      \default "", (No name)
  */
                        String          mName;
  
  /** \brief
  */
                        ShapeBlueprint*       mBlueprint;
  
  /** \brief
  */
                        NxShape*              mShape;
  protected:
  
  /** \internal
  */
                        void                  createAbstract(NxShapeDesc*);
  
  /** \internal
  */
  virtual               NxShapeDesc*          create() {return 0;}

  /** \internal
  */
  virtual               void                  assignAbstract(NxShape*);
  
}; // class Shape


                                                                                       

/** \brief A collection of shapes handed to a RigidBody (short term storage).
*/
typedef std::vector<Shape*> Shapes;

/** \brief A collection of shapes that belong to a RigidBody (long term storage).
*/
typedef ptr_vector<Shape> CollisionModel;

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

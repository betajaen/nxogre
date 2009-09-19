/** File: NxOgreShape.h
    Created on: 7-Nov-08
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
  virtual               void                  assign(NxShape*) = 0;
  
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
  virtual               NxShapeDesc*          create() = 0;

  /** \internal
  */
  virtual               void                  assignAbstract(NxShape*);
  
}; // class Shape

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

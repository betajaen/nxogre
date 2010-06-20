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

                                                                                       

#ifndef NXOGRE_CAPSULE_H
#define NXOGRE_CAPSULE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Capsule
    desc.
        A Capsule is a capsule shape that can be used in Actors, KinematicActors, StaticGeometries and Volumes for
        collisions and testing against them.
        
    see. Shape
*/ 
class NxOgrePublicClass Capsule : public Shape
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  unsigned int getShapeType() const;
  
  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
  
  /*! function. setDimensions
      desc.
           Set the radius and height of the capsule.
      args.
           Real __radius__ -- Radius of the capsule
           Real __height__ -- Distance between the top and bottom centres hemispheres of the capsule.
  */
  void  setDimensions(Real radius, Real height);
  
  /*! function. setRadius
      desc.
           Set the radius of the capsule.
      args.
           Real __radius__ -- Radius of the capsule
  */
  void  setRadius(Real radius);
  
  /*! function. setHeight
      desc.
           Set the height of the capsule.
      args.
           Real __height__ -- Distance between the top and bottom centres hemispheres of the capsule.
  */
  void  setHeight(Real height);
  
  /*! function. getRadius
      desc.
           Get the radius of the capsule
      return.
           **Real** -- The radius of the capsule.
  */
  Real  getRadius() const;
  
  /*! function. getHeight
      desc.
           Get the height of the capsule
      return.
           **Real** -- Distance between the top and bottom centres hemispheres of the capsule.
  */
  Real  getHeight() const;
  
  /*! function. getWorldCapsule
      desc.
           Get the box represented as world space capsule.
      note.
           This function only works when the capsule is attached.
      return. **SimpleCapsule** -- World space capsule when attached or SimpleCapsule with default values.
  */
  SimpleCapsule  getWorldCapsule();
  
  /*! function. saveToDescription
      desc.
          Saves the capsule to a description
  */
  void saveToDescription(CapsuleDescription&);
    
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected:
  
  /*
  */
  Capsule(NxCapsuleShape*, bool isDirty = false);
  
  /*
  */
  ~Capsule();
  
  protected:
  
  NxCapsuleShape*         mCapsuleShape;
  
}; // class Capsule

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass Capsule : public PointerClass<Classes::_Capsule>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Capsule>::operator new;

  using ::NxOgre::PointerClass<Classes::_Capsule>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Capsule>::getClassType;

  /** \brief Capsule
  */
                                              Capsule(Real radius, Real height, ShapeBlueprint* box_blueprint = new ShapeBlueprint());
  
  /** \brief Capsule
  */
                                             ~Capsule(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
                   Enums::ShapeFunctionType   getShapeFunctionType() const;
  
  /** \brief Set Dimensions
  */
                      void                    setDimensions(Real radius, Real height);
  
  /** \brief Set radius
  */
                      void                    setRadius(Real radius);
  
  /** \brief Set radius
  */
                      void                    setHeight(Real height);
  
  /** \brief Get radius
  */
                      Real                    getRadius(void) const;
  
  /** \brief Get height
  */
                      Real                    getHeight(void) const;
  
  /** \brief Retrives the capsule parameters in world space.
  */
                      SimpleCapsule           getWorldCapsule(void);

  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxCapsuleShape*         mCapsuleShape;
  
}; // class Capsule

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

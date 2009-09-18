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

                                                                                       

#ifndef NXOGRE_GEOMETRYSHAPEBLUEPRINT_H
#define NXOGRE_GEOMETRYSHAPEBLUEPRINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass HeightFieldGeometryBlueprint : public ShapeBlueprint
{
  
  public:
  
  /** \brief Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
                                              HeightFieldGeometryBlueprint();
  
  /** \brief Required destructor
  */
  virtual                                    ~HeightFieldGeometryBlueprint();
  
  
  /** \brief Resets the member variables to their default values according to the PhysX SDK.
  */
                        void                 reset();
  

  /** \brief
  */
                        HeightField*          mHeightField;

  /** \brief
  */
    /** \brief Terrain Centering to use.
      \default Enums::TerrainCentering_UseLocalPose
  */
                      Enums::TerrainCentering mTerrainCentering;
 
  /** \brief Use smooth sphere collisions
      \default false
  */
                      bool                    mSmoothSphereCollisions;

  /** \default Material indexes for HeightFields, which RigidBody's can pass through.
      \default 65535
  */
                      MaterialIdentifier      mHoleMaterial;


  /** \default Specifies the material for a heightfield HeightField along with the low order
               bits of the material index stored in each heightfield sample
      \default 0
  */
                      MaterialIdentifier      mHighBits;

}; // class ShapeBlueprint

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

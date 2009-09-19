/** File: NxOgreGeometryShapeBlueprint.h
    Created on: 5-Apr-09
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

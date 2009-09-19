/** File: NxOgreShapeBlueprint.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ShapeBlueprint::ShapeBlueprint()
{
 reset();
}

ShapeBlueprint::~ShapeBlueprint()
{
}


void ShapeBlueprint::reset()
{
 mLocalPose.identity();
 mFlags                          = Enums::ShapeFlags_Visualisation | Enums::ShapeFlags_TwoWayCloth | Enums::ShapeFlags_TwoWaySoftBody;
 mGroup                          = 0;
 mMaterial                       = 0;
 mSkeleton                       = 0;
 mSkinWidth                      = 0;
 mDensity                        = Real(1.0);
 mMass                           = Real(-1.0);
 mGroupsMask.w                   = 0;
 mGroupsMask.x                   = 0;
 mGroupsMask.y                   = 0;
 mGroupsMask.z                   = 0;
 mShapesCompartmentTypes         = 0;
 mMesh                           = 0;
 mMeshFlags                      = 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       

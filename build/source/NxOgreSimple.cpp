/** File: NxOgreSimple.cpp
    Created on: 15-Nov-09
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
#include "NxOgreSimple.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

extern inline void SimpleShapeToActorDescription(NxActorDesc& description, SimpleShape* shape)
{
 switch(shape->mType)
 {
  case NxOgre::Enums::SimpleShape_Box:
  {
   SimpleBox* box = (SimpleBox*) shape;
   NxBoxShapeDesc s;
   s.dimensions.x = box->mExtents.x;
   s.dimensions.y = box->mExtents.y;
   s.dimensions.z = box->mExtents.z;
   description.shapes.push_back(&s);
  }
  break;
  case NxOgre::Enums::SimpleShape_Sphere:
  {
   SimpleSphere* sphere = (SimpleSphere*) shape;
   NxSphereShapeDesc s;
   s.radius = sphere->mRadius;
   description.shapes.push_back(&s);
  }
  break;

 }
}

extern inline void SimpleBoxToNxBox(const SimpleBox& s, NxBox& t)
{
 t.center.x = s.mCenter.x;
 t.center.y = s.mCenter.y;
 t.center.z = s.mCenter.z;
 t.extents.x = s.mExtents.x;
 t.extents.y = s.mExtents.y;
 t.extents.z = s.mExtents.z;
 t.rot.setColumnMajor(s.mRotation.ptr());
}

extern inline void NxBoxToSimpleBox(const NxBox& t, SimpleBox& s)
{
 s.mCenter.x = t.center.x;
 s.mCenter.y = t.center.y;
 s.mCenter.z = t.center.z;
 s.mExtents.x = t.extents.x;
 s.mExtents.y = t.extents.y;
 s.mExtents.z = t.extents.z;
 t.rot.getColumnMajor(s.mRotation.ptr());
}

extern void SimpleCapsuleToNxCapsule(const SimpleCapsule& s, NxCapsule& t)
{
 t.p0.x = s.mP0.x;
 t.p0.y = s.mP0.y;
 t.p0.z = s.mP0.z;

 t.p1.x = s.mP1.x;
 t.p1.y = s.mP1.y;
 t.p1.z = s.mP1.z;

 t.radius = s.Radius;
}

extern void NxCapsuleToSimpleCapsule(const NxCapsule& t, SimpleCapsule& s)
{
 s.mP0.x = t.p0.x;
 s.mP0.y = t.p0.y;
 s.mP0.z = t.p0.z;

 s.mP1.x = t.p1.x;
 s.mP1.y = t.p1.y;
 s.mP1.z = t.p1.z;

 s.Radius = t.radius;

}


                                                                                       

};

                                                                                       

} // namespace NxOgre

                                                                                       

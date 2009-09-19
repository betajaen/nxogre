/** File: NxOgreRigidBodyPrototype.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreRigidBodyPrototype.h"

                                                                                       

namespace NxOgre
{

                                                                                       

RigidBodyPrototype::RigidBodyPrototype(void)
: mShapes()
{
 reset();
}

RigidBodyPrototype::~RigidBodyPrototype(void)
{
}

void RigidBodyPrototype::reset(void)
{
 RigidBodyDescription::reset();
 mGlobalPose = Matrix44_Identity;
}

bool RigidBodyPrototype::valid(void)
{
 
 if (RigidBodyDescription::valid())
  return false;
 
 if (mShapes.size() == 0)
  return false;
 
 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

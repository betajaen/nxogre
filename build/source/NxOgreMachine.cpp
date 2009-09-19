/** File: NxOgreMachine.cpp
    Created on: 19-May-09
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
#include "NxOgreMachine.h"
#include "NxOgreWheelMachinePart.h"
                                                                                       

namespace NxOgre
{

                                                                                       

Machine::Machine() : ActorMachinePart()
{
}

Machine::~Machine()
{
}

void Machine::simulate(float user_deltaTime)
{
 ActorMachinePart::simulate(user_deltaTime);
 
 ArrayIterator<MachinePart*> it = mMachineParts.getIterator();
 for (MachinePart* part = it.begin(); part = it.next();)
  part->simulate(user_deltaTime);
}

MachinePart* Machine::createWheelMachinePart(Wheel* wheel, PointRenderable* point_renderable)
{
 WheelMachinePart* part = NxOgre_New(WheelMachinePart)(wheel, point_renderable);
 mMachineParts.insert(part);
 return part;
}

                                                                                       

} // namespace NxOgre

                                                                                       

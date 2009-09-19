/** File: NxOgreWorldDescription.cpp
    Created on: 2-Nov-08
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
#include "NxOgreWorldDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

WorldDescription::WorldDescription(void)
{
 reset();
}

void WorldDescription::reset(void)
{
 mCookerThreadMask = 0;
 mHardwareMaximumConvex = 2048;
 mHardwareMaximumPage = 256;
 mHardwarePageSize = 65536;
 mNoHardware = false;
}

bool WorldDescription::valid(void)
{
 // Hardware page size must be 65536
 if (mHardwarePageSize != 65536)
  return false;

 // Hardware Convex Maximum must be a power of 2.
 if (mHardwareMaximumConvex & (mHardwareMaximumConvex - 1))
  return false;

 // Hardware Page Maximum must be a power of 2
 if (mHardwareMaximumPage & (mHardwareMaximumPage - 1))
  return false;

 return true;
}

                                                                                       

} // namespace NxOgre

                                                                                       

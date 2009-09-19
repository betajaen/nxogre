/** File: NxOgreCompartmentDescription.cpp
    Created on: 31-May-09
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
#include "NxOgreCompartmentDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

CompartmentDescription::CompartmentDescription(void)
{
 reset();
}

void CompartmentDescription::reset(void)
{
 mType = Enums::CompartmentType_RigidBody;
 mDeviceCode = Enums::DeviceCode_AutoAssign;
 mGridHashCellSize = 100.0f;
 mGridHashTablePower = 8;
 mFlags = Enums::CompartmentFlags_InheritSettings;
 mTimeScale = 1.0f;
 mThreadMask = 0;
}

bool CompartmentDescription::valid(void)
{
 if (mDeviceCode != Enums::DeviceCode_PPU0 &&
     mDeviceCode != Enums::DeviceCode_AutoAssign &&
     mDeviceCode != Enums::DeviceCode_CPU)
   return false;
  
 if (mTimeScale < 0.0f)
  return false;
  
 return (mType <= Enums::CompartmentType_Cloth) && (mGridHashCellSize > 0.0f);
}

                                                                                       

} // namespace NxOgre

                                                                                       

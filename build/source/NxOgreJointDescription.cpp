/** File: NxOgreJointDescription.cpp
    Created on: 14-Apr-09
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
#include "NxOgreJointDescription.h"

                                                                                       

namespace NxOgre
{

                                                                                       

JointDescription::JointDescription(void)
{
 reset();
}

JointDescription::~JointDescription(void)
{
}

void JointDescription::reset(void)
{
 for (unsigned int i = 0; i < 2;i ++)
 {
  mLocalAxis[i].set(0,0,1);
  mLocalNormal[i].set(1,0,0);
  mLocalAnchor[i].zero();
 }
 mMaxForce = NxOgreRealMax;
 mMaxTorque = NxOgreRealMax;
 mSolverExtrapolationFactor = 1.0f;
 mSpringType = Enums::JointSpringType_Force;
 mJointFlags = Enums::JointFlag_Visualisation;
}

bool JointDescription::isValid(void) const
{
 return true; // temp.
}

                                                                                       

} // namespace NxOgre

                                                                                       

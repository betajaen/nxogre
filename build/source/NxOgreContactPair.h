/** File: NxOgreContactPair.h
    Created on: 20-Aug-09
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

#ifndef NXOGRE_CONTACTPAIR_H
#define NXOGRE_CONTACTPAIR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class ContactPair
{
 public:
  
  /** \brief The two RigidBodies that are in contact
  */
  RigidBody* mFirst, *mSecond;
  
  /** \brief The total contact normal force that was applied for this pair, to maintain nonpenetration constraints.
             You should set Enums::ContactPairFlags_Forces in order to receive this value. 
  */
  Vec3       mSumNormalForce;
  
  /** \brief The total tangential force that was applied for this pair.
             You should set Enums::ContactPairFlags_Forces in order to receive this value. 
  */
  Vec3       mSumFrictionForce;
  
};

                                                                                       

} // namespace PhysXEntityReport

                                                                                       

#endif

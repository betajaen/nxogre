/** File: NxOgreCompartmentDescription.h
    Created on: 11-Aug-09
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

#ifndef NXOGRE_COMPARTMENTDESCRIPTION_H
#define NXOGRE_COMPARTMENTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass CompartmentDescription
{
  
  public: // Functions
  
  /** \brief CompartmentDescription constructor, all it does is call RigidBodyDescription::reset.
  */
                                               CompartmentDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                         reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                   valid(void);
  
  /** \brief Compartment meant for this type of simulation.
      \default Enums::CompartmentType_RigidBody
  */
  Enums::CompartmentType                       mType;
  
  /** \brief Assigned device to simulate the compartment on.
      \note Cloth compartments must use a non-CPU processor.
      \default Enums::DeviceCode_AutoAssign
  */
  Enums::DeviceCode                            mDeviceCode;
  
  /** \brief Size in distance units of a single cell in the paging grid.
             Should be set to the size of the largest common dynamic object in this compartment.
      \default 100.0
  */
  Real                                         mGridHashCellSize;
  
  /** \brief 2-power used to determine size of the hash table that geometry gets hashed into.
             Hash table size is (1 << gridHashTablePower).
      \default 100.0
  */
  unsigned int                                 mGridHashTablePower;
  
  /** \brief Compartment Flags combination
      \default Enums::CompartmentFlags_InheritSettings
  */
  unsigned int                                 mFlags;
  
  /** \brief  Thread affinity mask for the compartment thread.
              Defaults to 0 which means the SDK determines the affinity.
      \default 0
  */
  unsigned int                                 mThreadMask;
  
  /** \brief  Timescale modifier
      \default 1.0f
      \note Must be non-negative.
  */
  Real                                         mTimeScale;
  
}; // class CompartmentDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

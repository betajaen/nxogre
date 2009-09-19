/** File: NxOgreWorldDescription.h
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

#ifndef NXOGRE_WORLDDESCRIPTION_H
#define NXOGRE_WORLDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass WorldDescription
{
  public: // Functions
  
  /** \brief WorldDescription constructor, all it does is call WorldDescription::reset.
  */
                                              WorldDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                        reset(void);
  
  /** \brief Returns if the variables are in a valid range or not
  */
                        bool                  valid(void);
  
  /** \brief Disable simulation on a PPU or GPU completely.
      \default false
  */
  bool                                        mNoHardware;
  
  /** \brief Size of hardware mesh pages.
      \note  Currently the PhysX SDK only supports a value of 65536 only.
      \default 65536
  */
  unsigned int                                mHardwarePageSize;
  
  /** \brief Maximum number of hardware pages supported on the hardware, must be a power of 2.
      \default 256
  */
  unsigned int                                mHardwareMaximumPage;
  
  /** \brief Maximum number of convex meshes that would be resident on hardware, must be a power of 2.
      \default 2048
  */
  unsigned int                                mHardwareMaximumConvex;
  
  /** \brief Thread affinity mask for the background cooker thread.
      \default 0 (SDK determines the affinity).
  */
  unsigned int                                mCookerThreadMask;
  
  /** \brief What to do when there is an assertion from PhysX.
      \default PhysXAssertion_Continue
  */
  Enums::PhysXAssertionResponse               mAssertionResponse;
  
}; // class WorldDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

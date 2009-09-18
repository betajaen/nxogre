/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
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

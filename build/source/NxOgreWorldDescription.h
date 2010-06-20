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

                                                                                       

#ifndef NXOGRE_WORLDDESCRIPTION_H
#define NXOGRE_WORLDDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. WorldDescription
    namespace. NxOgre
    desc. Description class for World
    
    properties.
     bool mNoHardware -- Disable simulation on a PPU or GPU completely. default: false
     unsigned int mHardwareMaximumPage -- Maximum number of hardware pages supported on the hardware. default: 256
     unsigned int mHardwareMaximumConvex -- Maximum number of convex meshes that would be resident on hardware. default: 2048
     unsigned int mCookerThreadMask -- Thread affinity mask for the background cooker thread. default: 0
     Enums::PhysXAssertionResponse mAssertionResponse -- What to do when there is an assertion from PhysX. default: Enums::PhysXAssertion_Continue
    validations.
     mHardwareMaximumConvex must be a power of 2 -- (mHardwareMaximumConvex & (mHardwareMaximumConvex - 1))
     mHardwareMaximumPage must be a power of 2 -- (mHardwareMaximumPage & (mHardwareMaximumPage - 1))
*/
class NxOgrePublicClass WorldDescription
{
  
  public:
    
  WorldDescription();
  


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:

  /*! variable. mAssertionResponse
      desc.
          What to do when there is an assertion from PhysX.
      default.
          Enums::PhysXAssertion_Continue
  */
  Enums::PhysXAssertionResponse mAssertionResponse;

  /*! variable. mCookerThreadMask
      desc.
          Thread affinity mask for the background cooker thread.
      default.
          0
  */
  unsigned int mCookerThreadMask;

  /*! variable. mHardwareMaximumConvex
      desc.
          Maximum number of convex meshes that would be resident on hardware.
      default.
          2048
      condition.
          mHardwareMaximumConvex must be a power of 2
  */
  unsigned int mHardwareMaximumConvex;

  /*! variable. mHardwareMaximumPage
      desc.
          Maximum number of hardware pages supported on the hardware.
      default.
          256
      condition.
          mHardwareMaximumPage must be a power of 2
  */
  unsigned int mHardwareMaximumPage;

  /*! variable. mNoHardware
      desc.
          Disable simulation on a PPU or GPU completely.
      default.
          false
  */
  bool mNoHardware;

  /*! constructor. WorldDescription
      desc.
          Copy constructor for WorldDescription
  */
  WorldDescription(const WorldDescription&);

  /*! function. operator=
      desc.
          Assignment operator
  */
  WorldDescription& operator=(const WorldDescription&);

  /*! function. duplicate
      desc.
          Create a duplicate of this WorldDescription as a pointer.
  */
  virtual WorldDescription* duplicate() const;

  /*! function. copy_into
      desc.
          Copy all of the properties of WorldDescription into another.
  */
  virtual void copy_into(WorldDescription*) const;

  /*! function. reset
      desc.
          Resets WorldDescription properties to their default values.
  */
  virtual void reset();

  /*! function. valid
      desc.
          Is this WorldDescription valid according to each property.
  */
  virtual bool valid() const;
  /*! function. inspect
      desc.
        Writes the contents of this to the console.
  */
  virtual void inspect() const;

  // END - Serialisation. "WorldDescription-7a85aefb65e9b14cfd7d19e5c8cc87cf"

}; // class WorldDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

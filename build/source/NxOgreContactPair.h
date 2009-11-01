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

                                                                                       

#ifndef NXOGRE_CONTACTPAIR_H
#define NXOGRE_CONTACTPAIR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ContactPair
    desc.
        Information about a contact event between two RigidBodies
*/
class ContactPair
{
  
 public:
  
  /*! variable. mFirst
      desc.
          The first RigidBody in contact.
      type.
          RigidBody*
  */
  RigidBody* mFirst;
  
  /*! variable. mSecond
      desc.
          The second RigidBody in contact.
      type.
          RigidBody*
  */
  RigidBody* mSecond;
  
  /*! variable. mSumNormalForce
      desc.
          The total contact normal force that was applied for this pair, to maintain nonpenetration constraints.
          You should set Enums::ContactPairFlags_Forces in order to receive this value.
      type.
          Vec3
  */
  Vec3 mSumNormalForce;
  
  /*! variable. mSumFrictionForce
      desc.
           The total tangential force that was applied for this pair.
           You should set Enums::ContactPairFlags_Forces in order to receive this value. 
      type.
           Vec3
  */
  Vec3 mSumFrictionForce;
  
}; // class ContactPair

                                                                                       

} // namespace PhysXEntityReport

                                                                                       

#endif

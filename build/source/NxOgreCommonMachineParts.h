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

                                                                                       

#ifndef NXOGRE_COMMONMACHINEPARTS_H
#define NXOGRE_COMMONMACHINEPARTS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMachinePart.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! constructor. MoverMachinePart
    desc.
        Applies a force to the parent machine every x seconds.
*/
class NxOgrePublicClass MoverMachinePart : public MachinePart
{
  
 public: // Functions
  
  /*! constructor. MoverMachinePart
  */
  MoverMachinePart(Machine*, const Vec3& force, Enums::ForceMode, float interval);
  
  /*! destructor.
  */
  ~MoverMachinePart();
  
  /*! function. simulate
  */
  void simulate(float user_deltaTime);
  
  /*! function. simulate
  */
  void render(float user_deltaTime);
  
 protected:
  
  Machine* mParent;
  
  Vec3 mForce;
  
  Enums::ForceMode mForceMode;
  
  float mInterval;
  
  float mNextInterval;

}; // class MoverMachinePart



/*! constructor. MoverMachinePart
    desc.
        Applies a torque to the parent machine every x seconds.
*/
class NxOgrePublicClass RotatorMachinePart : public MachinePart
{
  
 public: // Functions
  
  /*! constructor. MoverMachinePart
  */
  RotatorMachinePart(Machine*, const Vec3& torque, Enums::ForceMode, float interval);
  
  /*! destructor.
  */
  ~RotatorMachinePart();
  
  /*! function. simulate
  */
  void simulate(float user_deltaTime);
  
  /*! function. simulate
  */
  void render(float user_deltaTime);
  
 protected:
  
  Machine* mParent;
  
  Vec3 mForce;
  
  Enums::ForceMode mForceMode;
  
  float mInterval;
  
  float mNextInterval;

}; // class MoverMachinePart

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

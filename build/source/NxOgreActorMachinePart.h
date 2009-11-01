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

                                                                                       

#ifndef NXOGRE_ACTORMACHINEPART_H
#define NXOGRE_ACTORMACHINEPART_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMachinePart.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ActorMachinePart
    desc.
         ActorMachinePart is a MachinePart that is an Actor.
    
*/
class NxOgrePublicClass ActorMachinePart : public MachinePart
{
  
  public: // Functions
  
  /*! constructor. ActorMachinePart
      desc.
        Empty constructor.
  */
  ActorMachinePart();

  /*! constructor. ActorMachinePart
      args.
       Actor* __actor__ -- Existing actor to work with.
       PointRenderable* __pointrenderable__ -- Point renderable to render to.
  */
  ActorMachinePart(Actor* actor, PointRenderable* = 0);
  
  /*! destructor. ActorMachinePart
      desc.
       Destructor
  */
  ~ActorMachinePart();
  
  /*! function. simulate
      args.
       float __deltaTime__ -- Delta time
      !time_listener
      !virtual
  */
  virtual void                                simulate(float user_deltaTime);
  
  /* Assigned Actor
  */
  Actor*                                      mActor;
  
  /* Assigned PointRenderable
  */
  PointRenderable*                            mPointRenderable;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

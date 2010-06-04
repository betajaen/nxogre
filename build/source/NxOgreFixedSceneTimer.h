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

                                                                                       

#ifndef NXOGRE_FIXEDSCENETIMER_H
#define NXOGRE_FIXEDSCENETIMER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreSceneTimer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FixedSceneTimer
    desc.
         A fixed SceneTimer is used to divide the current timestep into neat smaller equal time values, any remaining
         time is carried on into the next timestep.

*/
class NxOgrePublicClass FixedSceneTimer : public SceneTimer
{
  
  public: // Functions
  
  /*! constructor. FixedSceneTimer
      desc.
           Constructor.
      args.
           Scene* __scene__ -- Scene to with with.
           Real __maxTime__ -- Maximum timestep.
           unsigned int __subSteps__ -- Number of substeps
  */
  FixedSceneTimer(Scene*, Real maxTime = _1_60);
  
  /*! destructor. FixedSceneTimer
      desc.
           Destructor.
  */
  ~FixedSceneTimer();
  
  /*! function. simulate
      desc.
           Simulate the PhysX scene.
      note.
           Do not call this function by hand. Scene will call this at the appropriate time.
      args.
           float __deltaTime__ -- Amount of time passed, this shouldn't be the maximum timeseep.
      
  */
  void  simulate(float deltaTime);
  
  /*! function. hasResults
      desc.
          Has PhysX finished simulating the timestep yet?
      return.
          **bool** -- If PhysX has finished simulating or not.
  */
  bool  hasResults() const;
  
  /*! function. fetchResults
      desc.
          Fetch the results and make changes to the scene to reflect them.
      note.
           Do not call this function by hand. Scene will call this at the appropriate time.
      
  */
  void  fetchResults();
  
  /*! function. getTimeStep
      desc.
          Get the current TimeStep.
  */
  const TimeStep&                             getTimeStep() const;
  
  protected:
  
  FixedTimeStep                               mTimeStep;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

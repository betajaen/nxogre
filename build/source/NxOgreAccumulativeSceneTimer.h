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

                                                                                       

#ifndef NXOGRE_ACCUMULATIVESCENETIMER_H
#define NXOGRE_ACCUMULATIVESCENETIMER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreSceneTimer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A Fixed SceneTimer is based upon a fixed timestep injected every second; due to the inaccuracies of
           the computer and a multi-tasking operating system. Each timestep will be off; to prevent this an
           accumulator will be used to "store" up time and correctly give the right time value for each frame.
           This method of timing is provided by the PhysX SDK, however the interpolation feature provided by
           The accumulator should be used with the SceneInterpolatorRenderer so each physics object is correctly
           rendered.

*/
class NxOgrePublicClass AccumulativeSceneTimer : public PointerClass<Classes::_AccumulativeSceneTimer>, public SceneTimer
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              AccumulativeSceneTimer(Scene*, Real maxTime = _1_5, Real expectedTime = _1_60);
  
  /** \brief Text
  */
                                             ~AccumulativeSceneTimer(void);
  
  /** \brief Text
      \return True if HasResults/FetchResults should be called later, later.
  */
  void                                       simulate(float user_deltaTime);
  
  /** \brief
  */
  bool                                       hasResults(void) const;
  
  /** \brief
  */
  void                                       fetchResults(void);
  
  protected:
  
  float                                      mOldTime, mAccumulator;
  
}; // class AccumulativeSceneTimer

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

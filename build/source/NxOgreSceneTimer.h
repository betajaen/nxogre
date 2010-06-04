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

                                                                                       

#ifndef NXOGRE_SCENE_TIMER_H
#define NXOGRE_SCENE_TIMER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SceneTimer : public GenericBasedAllocatable
{
  
  public: // Functions
  
  struct TimerSettings
  {
   Real mMaxTime;
  };
  
  /** \brief Text
  */
                                              SceneTimer(Scene*, Real maxTime);
  
  /** \brief Text
  */
  virtual                                    ~SceneTimer();
  
  /** \brief
  */
  TimerSettings                               getSettings();

  /** \brief Text
      \return True if HasResults/FetchResults should be called later, later.
  */
  virtual void                                simulate(float user_deltaTime);
  
  /** \brief
  */
  virtual bool                                hasResults() const;
  
  /** \brief
  */
  virtual void                                fetchResults();
  
  /*! function. getTimeStep
      desc.
          Get a reference to the Timestep.
  */
  virtual const TimeStep&                     getTimeStep() const = 0;
  
  /*! function. getTimerMode
      desc.
          Get the current TimerMode.
  */
  virtual Enums::TimerMode                    getTimerMode() const;

  protected:
  
  /** \brief Maximum time that can be injected.
  */
  Real mMaxTime;
  
  /** \brief
  */
  Scene* mParent;
  
  /** \brief
  */
  NxScene* mScene;
  
  
  Enums::TimerMode mTimerMode;

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

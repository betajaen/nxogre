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

                                                                                       

#ifndef NXOGRE_TIMECONTROLLER_H
#define NXOGRE_TIMECONTROLLER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreSingleton.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief The TimeController "injects" time events to various parts of NxOgre; i.e. for Scenes
           time is injected to forward the state of the scene.
           
           Time Controller uses a class called "TimeListener" to tell various parts of NxOgre and
           the user's application about the new timestep. It uses a priority system (and then a first
           come first serve) to determine what TimeListeners need to be used first. 
           
           The following is a recommendation on which priority to use.
           
            - High       : Scene calculations start.
            - MediumHigh : Scene calculations stop.
            - Medium     : User process results, render them on a screen, transmit over network
            - MediumLow  : User functions (machines) that need to be processed for the next frame.
            - Low        : User clean up functions, etc.
           
           As Scenes use the time controller twice; it is possible to move them down a "rank" and
           process the previous results. In a sense; "rendering" the physics in the previous frame
           into the next one. This can be achived via the ScenePrototype/SceneDescription.
           
*/
class NxOgrePublicClass TimeController : public ::NxOgre::Singleton<TimeController, ::NxOgre::Classes::_TimeController>
{
  
  typedef void (TimeController::*AdvancedFunc)(Real);
  friend class World;
  friend class Scene;
  public: // Functions
  
  /** \brief "Pause" the TimeController. This makes the TimeController to ignore any requests to
             advance the World
  */
                        void                pause(void);
  
  /** \brief Resume the TimeController and process any requests to advance the Worlds time state.  
  */
                        void                resume(void);
  
  /** \brief Is the simulation paused or not.
  */
                        bool                isPaused(void) const;
  
  /** \brief Advance forward in time (in seconds))  causing an update to every TimeListener in order of
             array insertion and priority.
      \note  deltaTime must be a positive real number.
  */
                        void                advance(Real deltaTime = _1_60);
  
  /** \brief Add a time-listener to the TimeController. TimeListeners will not be deleted when TimeController
             is destroyed so you will have to look after that pointer yourself.
  */
                        void                addTimeListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);
  
  /** \brief Add a time-listener to the TimeController. TimeListeners will not be deleted when TimeController
             is destroyed so you will have to look after that pointer yourself.
  */
                        void                removeTimeListener(TimeListener*, Enums::Priority = Enums::Priority_Medium);
  
  protected: // Functions

  /** \brief TimeController constructor.
  */
                                            TimeController(void);
  
  /** \brief TimeController destructor.
  */
                                           ~TimeController(void);

  /** \internal
  */
                        void                _literal(Real);

  /** \internal
  */
                        void                _pause(Real);

  protected: // Variables

                        World*               mWorld;
                        AdvancedFunc         mFunction;
                        bool                 mPaused;
                        Array<TimeListener*> mListeners[5];
                        Array<TimeListener*> mWaitingList;


}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

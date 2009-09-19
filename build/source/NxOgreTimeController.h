/** File: NxOgreTimeController.h
    Created on: 9-Nov-08
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

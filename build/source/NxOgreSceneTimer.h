/** File: NxOgreSceneTimer.h
    Created on: 10-May-09
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

#ifndef NXOGRE_SCENE_TIMER_H
#define NXOGRE_SCENE_TIMER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SceneTimer
{
  
  public: // Functions
  
  struct TimerSettings
  {
   bool mFixedTiming;
   Real mMaxTime;
  };
  
  
  /** \brief Text
  */
                                              SceneTimer(Scene*, Real maxTime, Real expectedTime);
  
  /** \brief Text
  */
  virtual                                    ~SceneTimer(void);
  
  /** \brief
  */
  TimerSettings                               getSettings();

  /** \brief Text
      \return True if HasResults/FetchResults should be called later, later.
  */
  virtual void                                simulate(float user_deltaTime);
  
  /** \brief
  */
  virtual bool                                hasResults(void) const;
  
  /** \brief
  */
  virtual void                                fetchResults(void);
  
  
  
  virtual Enums::TimerMode                    getTimerMode() const;

  protected:
  
  /** \brief Maximum time that can be injected.
  */
  Real mMaxTime;
  
  /** \brief Expected time to inject.
  */
  Real mExpectedTime;
  
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

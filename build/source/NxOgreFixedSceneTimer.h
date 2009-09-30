/** File: NxOgreXXX.h
    Created on: X-XXX-XX
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

#ifndef NXOGRE_FIXEDSCENETIMER_H
#define NXOGRE_FIXEDSCENETIMER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreSceneTimer.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A Fixed SceneTimer is based upon a fixed timestep injected every second; due to the inaccuracies of
           the computer and a multi-tasking operating system. Each timestep will be off; to prevent this an
           accumulator will be used to "store" up time and correctly give the right time value for each frame.
           This method of timing is provided by the PhysX SDK, however the interpolation feature provided by
           NxOgre is not compatible with the FixedSceneTimer, instead you should use the AccumaltiveSceneTimer.

           The accumulator should be used with the SceneInterpolatorRenderer so each physics object is correctly
           rendered.

*/
class NxOgrePublicClass FixedSceneTimer : public PointerClass<Classes::_FixedSceneTimer>, public SceneTimer
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              FixedSceneTimer(Scene*, Real maxTime = _1_60, Real expectedTime = _1_60);
  
  /** \brief Text
  */
                                             ~FixedSceneTimer(void);
  
  /** \brief Text
      \return True if HasResults/FetchResults should be called later, later.
  */
  void                                        simulate(float user_deltaTime);
  
  /** \brief
  */
  bool                                        hasResults(void) const;
  
  /** \brief
  */
  void                                        fetchResults(void);
  
  
  protected:
  
  float mMaxTimeStep, mOldTime, mAccumulator;
 
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

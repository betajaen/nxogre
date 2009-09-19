/** File: NxOgreTimeController.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreTimeController.h"
#include "NxOgreTimeListener.h"
#include "NxOgreTimeStep.h"

                                                                                       

template<> NxOgre::TimeController* NxOgre::Singleton<NxOgre::TimeController, NxOgre::Classes::_TimeController>::sSingleton = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

TimeController::TimeController(void)
{
 resume();
}

TimeController::~TimeController(void)
{
}

void TimeController::pause(void)
{
 mFunction = &TimeController::_pause;
 mPaused = true;
}

void TimeController::resume(void)
{
 mFunction = &TimeController::_literal;
 mPaused = false;
}

bool TimeController::isPaused(void) const
{
 return mPaused;
}

void TimeController::advance(Real deltaTime)
{
 (this->*mFunction)(deltaTime);
}

void TimeController::addTimeListener(TimeListener* listener, Enums::Priority priority)
{
 if (priority == Enums::Priority_High || priority == Enums::Priority_MediumHigh)
  mListeners[Enums::Priority_MediumHigh].insert(listener);
 else if (priority == Enums::Priority_Medium)
  mListeners[Enums::Priority_Medium].insert(listener);
 else if (priority == Enums::Priority_MediumLow)
  mListeners[Enums::Priority_MediumLow].insert(listener);
 else
  mListeners[Enums::Priority_Low].insert(listener);
}

void TimeController::removeTimeListener(TimeListener* listener, Enums::Priority priority)
{
 if (priority == Enums::Priority_High || priority == Enums::Priority_MediumHigh)
  mListeners[Enums::Priority_MediumHigh].remove(listener);
 else if (priority == Enums::Priority_Medium)
  mListeners[Enums::Priority_Medium].remove(listener);
 else if (priority == Enums::Priority_MediumLow)
  mListeners[Enums::Priority_MediumLow].remove(listener);
 else
  mListeners[Enums::Priority_Low].remove(listener);
}

void TimeController::_literal(Real user_deltaTime)
{

 Array<TimeListener*>::Iterator iterator;
 iterator = mWaitingList.getIterator();

 for (TimeListener* listener = iterator.begin();listener = iterator.next();)
 {
  listener->advance(user_deltaTime, Enums::Priority_Low);
 }

 mWaitingList.removeAll();
 bool NotOnList = false;
 for (unsigned int i=0;i < 5;i++)
 {
   iterator = mListeners[i].getIterator();
   for (TimeListener* listener = iterator.begin();listener = iterator.next();)
   {
    NotOnList = listener->advance(user_deltaTime, Enums::Priority(i));
    if (NotOnList == false)
     mWaitingList.insert(listener);
   }
 }

 iterator = mWaitingList.getIterator();
 for (TimeListener* listener = iterator.begin();listener = iterator.next();)
 {
  listener->advance(user_deltaTime, Enums::Priority_Low);
 }


}

void TimeController::_pause(Real)
{
}

} // namespace NxOgre

                                                                                       

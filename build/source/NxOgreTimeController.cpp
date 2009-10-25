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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreTimeController.h"
#include "NxOgreTimeListener.h"
#include "NxOgreTimeStep.h"

                                                                                       

template<> NxOgre::TimeController* NxOgre::Singleton<NxOgre::TimeController>::sSingleton = 0;

                                                                                       

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

                                                                                       

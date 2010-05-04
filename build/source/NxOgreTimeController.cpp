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

                                                                                       

TimeController::TimeController()
{
 resume();
}

TimeController::~TimeController()
{
}

void TimeController::pause(void)
{
 mTimeFunction = &TimeController::_pause;
 mPaused = true;
}

void TimeController::resume(void)
{
 mTimeFunction = &TimeController::_call_controllers;
 mPaused = false;
}

bool TimeController::isPaused(void) const
{
 return mPaused;
}

void TimeController::advance(Real deltaTime)
{
 (this->*mTimeFunction)(deltaTime);
}

void TimeController::_createTimeListenerGroup(Enums::Priority id)
{
 
 TimeListenerGroupIterator group = mListeners.find(id);
 if (group != mListeners.end())
  return;
 
 mListeners.insert(std::pair<Enums::Priority, vector<TimeListener*> >(id, vector<TimeListener*>()));
}

void TimeController::_removeTimeListenerGroup(Enums::Priority id)
{
 TimeListenerGroupIterator group = mListeners.find(id);
 if (group != mListeners.end())
  return;
 
 mListeners.erase(group);
 
}

void TimeController::addTimeListener(TimeListener* listener, NxOgre::Enums::Priority priority)
{
 TimeListenerGroupIterator group = mListeners.find(priority);
 if (group == mListeners.end())
 {
  _createTimeListenerGroup(priority);
  group = mListeners.find(priority);
 }

 (*group).second.push_back(listener);
}

void TimeController::removeTimeListener(TimeListener* listener, NxOgre::Enums::Priority priority)
{
 TimeListenerGroupIterator group = mListeners.find(priority);
 if (group == mListeners.end())
  return;
 
 (*group).second.destroy(listener);
}

void TimeController::_pause(Real)
{
 // Paused. Do not call the TimeListeners.
}

void TimeController::_call_controllers(Real deltaTime)
{
 
 // Run through the TimeListeners in order of priority.
 for(mGroupIterator = mListeners.begin(); mGroupIterator != mListeners.end(); ++mGroupIterator)
 {
  for (mListenerIterator = (*mGroupIterator).second.iterator(); mListenerIterator.end(); mListenerIterator++)
  {
   // Run the TimeListener, if returned false, then place the pointer into WaitingListeners.
   bool mListenerState = (*mListenerIterator)->advance(deltaTime, (*mGroupIterator).first);
   if (mListenerState == false)
    mWaitingListeners.push_back((*mListenerIterator));
  }
 }
 
 // If there are any WaitingListeners, run them again.
 if (mWaitingListeners.size())
 {
  for (mListenerIterator = mWaitingListeners.iterator(); mListenerIterator.end(); mListenerIterator++)
   (*mListenerIterator)->advance(deltaTime, Enums::Priority_Low);
  mWaitingListeners.clear();
 }
 
}


} // namespace NxOgre

                                                                                       

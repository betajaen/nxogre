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
#include "NxOgreTimeListenerGroup.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

TimeListenerGroup::TimeListenerGroup(Enums::Priority priority)
: mPriority(priority)
{ // empty constructor.
}

TimeListenerGroup::~TimeListenerGroup()
{ // empty destructor.
}

void TimeListenerGroup::push_back(TimeListener* listener)
{
 mListeners.push_back(listener);
}

void TimeListenerGroup::remove(TimeListener* listener)
{
 mListeners.remove(mListeners.index(listener));
}

void TimeListenerGroup::remove_all()
{
 mListeners.remove_all();
}

void TimeListenerGroup::advance(Real deltaTime, TimeListenerGroup* waiting_group)
{
 for (mIterator = mListeners.elements(); mIterator != mIterator.end(); mIterator++)
 {
  if (mIterator->advance(deltaTime, mPriority) == false)
   if (waiting_group)
    waiting_group->push_back((*mIterator));
 }
}

bool TimeListenerGroup::empty() const
{
 return mListeners.size() == 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       

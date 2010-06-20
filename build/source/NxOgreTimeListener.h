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

                                                                                       

#ifndef NXOGRE_TIMELISTENER_H
#define NXOGRE_TIMELISTENER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreTimeStep.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. TimeListener
    desc.
        A TimeListener is any class that needs to react when the timestep in a Scene goes forwards in NxOgre.
*/
class NxOgrePublicClass TimeListener
{
  
  public:
  
  /*! function. advance
      desc.
          Must be implemented by user. Called when a time step is injected into NxOgre.
          In some cases your class advance function may not be ready for use (such as waiting for
          a thread to finish); in that case return false to be placed onto a waiting list - which
          the time controller will try again for one time, once the other TimeListeners have had their turn.
      args.
          float deltaTime -- Time passed.
          const Enums::Priority& -- Priority assigned to this TimeListener.
          const Enums::SceneFunction& -- When was called; in the Render or Simulate function.
      return.
          True if the function was carried out normally, false if the function needs to be revisited later in this timestep.
      note.
          Calling false only applies if the TimeListener isn't placed on the "waiting list". returning false once the timelistener
          has had it's two turns will not give it a third. Anything that needs to be done should be done on the second visit.
  */
  virtual bool advance(float deltaTime, const Enums::Priority&, const Enums::SceneFunction&) = 0;
  
}; // class TimeListener

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

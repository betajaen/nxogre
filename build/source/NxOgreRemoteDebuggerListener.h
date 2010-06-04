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

                                                                                       

#ifndef NXOGRE_REMOTEDEBUGGERLISTENER_H
#define NXOGRE_REMOTEDEBUGGERLISTENER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Event listener for the RemoteDebugger.
*/
class NxOgrePublicClass RemoteDebuggerListener
{
  
  public: // Functions
  
  /** \brief Text
  */
  virtual                                    ~RemoteDebuggerListener();
  
  /** \brief Text
  */
  virtual void                                onConnect();
  
  /** \brief Text
  */
  virtual void                                onDisconnect();
  
  /** \brief Text
  */
  virtual void                                beforeMaskChange(unsigned int oldMask, unsigned int newMask);
  
  /** \brief Text
  */
  virtual void                                afterMaskChange(unsigned int oldMask, unsigned int newMask);
  
  
  protected: // Variables
  
  
}; // class RemoteDebuggerListener

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

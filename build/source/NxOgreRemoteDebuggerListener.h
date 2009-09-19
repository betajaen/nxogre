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
  virtual                                    ~RemoteDebuggerListener(void);
  
  /** \brief Text
  */
  virtual void                                onConnect(void);
  
  /** \brief Text
  */
  virtual void                                onDisconnect(void);
  
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

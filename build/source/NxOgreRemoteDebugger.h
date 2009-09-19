/** File: NxOgreRemoteDebugger.h
    Created on: 3-Apr-09
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

#ifndef NXOGRE_REMOTEDEBUGGER_H
#define NXOGRE_REMOTEDEBUGGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Allows a Scene to be debugged via a seperate application on this computer or a networked one.
*/
class NxOgrePublicClass RemoteDebugger
{
  
  
  public: // Functions
  
  /** \brief Text
  */
                                              RemoteDebugger(World*);
  
  /** \brief Text
  */
                                             ~RemoteDebugger(void);
  
  /** \brief Text
  */
  void                                        connect(const char* address = "localhost", unsigned int port = Constants::DefaultRemoteDebuggerPort, unsigned int eventMask = Enums::RemoteDebuggerMask_Everything);
  
  /** \brief Text
  */
  void                                        disconnect(void);
  
  /** \brief Text
  */
  void                                        flush(void);
  
  /** \brief Is NxOgre connected to the RemoteDebugger application?
  */
  bool                                        isConnected(void) const;
  
  /** \brief Text
  */
  void                                        frameBreak(void);
  
  /** \brief Text
  */
  void                                        createObject(void* object, Enums::RemoteDebuggerObjectType, const char *className, unsigned int mask);
  
  /** \brief Text
  */
  void                                        removeObject(void* object, unsigned int mask);
  
  /** \brief Text
  */
  void                                        addChild(void* object, void* child, unsigned int mask);
  
  /** \brief Text
  */
  void                                        removeChild(void* object, void* child, unsigned int mask);
  
  /** \brief Text
  */
  void                                        createParameter(const float& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const float& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        createParameter(const unsigned int& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const unsigned int& parameter, void* object, const char* name, unsigned int mask);
    
  /** \brief Text
  */
  void                                        createParameter(const Vec3& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const Vec3& parameter, void* object, const char* name, unsigned int mask);
      
  /** \brief Text
  */
  void                                        createParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const SimplePlane& parameter, void* object, const char* name, unsigned int mask);
#if 0
  /** \brief Text
  */
  void                                        createParameter(const Matrix44& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const Matrix44& parameter, void* object, const char* name, unsigned int mask);
          
  /** \brief Text
  */
  void                                        createParameter(const Matrix33& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const Matrix33& parameter, void* object, const char* name, unsigned int mask);
#endif
  /** \brief Text
  */
  void                                        createParameter(const unsigned char* parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const unsigned char* parameter, void* object, const char* name, unsigned int mask);
              
  /** \brief Text
  */
  void                                        createParameter(const char* parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const char* parameter, void* object, const char* name, unsigned int mask);
                
  /** \brief Text
  */
  void                                        createParameter(const bool& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const bool& parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        createParameter(const void* parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setParameter(const void* parameter, void* object, const char* name, unsigned int mask);
  
  /** \brief Text
  */
  void                                        setMask(unsigned int);
  
  /** \brief Text
  */
  unsigned int                                getMask(void);
  
  
  /** \brief Text
  */
  void*                                       getPickedObject();
  
  /** \brief Text
  */
  Vec3                                       getPickedPoint(void);
  

  /** \brief Text
  */
  void                                        registerListener(RemoteDebuggerListener*);

  /** \brief Text
  */
  void                                        unregisterListener(RemoteDebuggerListener*);

  protected: // Variables
  
  World*                                      mWorld;
  
  NxRemoteDebugger*                           mRemoteDebugger;
  
}; // class RemoteDebugger

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

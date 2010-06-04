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

                                                                                       

#ifndef NXOGRE_REMOTEDEBUGGER_H
#define NXOGRE_REMOTEDEBUGGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Allows a Scene to be debugged via a seperate application on this computer or a networked one.
*/
class NxOgrePublicClass RemoteDebugger : public GenericBasedAllocatable
{
  
  
  public: // Functions
  
  /** \brief Text
  */
                                              RemoteDebugger(World*);
  
  /** \brief Text
  */
                                             ~RemoteDebugger();
  
  /** \brief Text
  */
  void                                        connect(const char* address = "localhost", unsigned int port = Constants::DefaultRemoteDebuggerPort, unsigned int eventMask = Enums::RemoteDebuggerMask_Everything);
  
  /** \brief Text
  */
  void                                        disconnect();
  
  /** \brief Text
  */
  void                                        flush();
  
  /** \brief Is NxOgre connected to the RemoteDebugger application?
  */
  bool                                        isConnected() const;
  
  /** \brief Text
  */
  void                                        frameBreak();
  
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
  unsigned int                                getMask();
  
  
  /** \brief Text
  */
  void*                                       getPickedObject();
  
  /** \brief Text
  */
  Vec3                                       getPickedPoint();
  

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

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

                                                                                       

#ifndef NXOGRE_ERRORSTREAM_H
#define NXOGRE_ERRORSTREAM_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreSingleton.h"
#include "NxOgreString.h"
#include "NxogreException.h"
#include "NxogreWarning.h"
#include "NxogreNotice.h"

                                                                                       

namespace NxOgre
{

class Resource;

                                                                                       

/*! class. Error
    desc.
        Error is a single instance of an thrown error by NxOgre, carrying a message, it's type,
        and the file it was raised from.
*/
class NxOgrePublicClass ErrorListener
{
  
 public:
  
  /*! class. onException
      desc.
           When an exception has been thrown. This will be eventually be called. Depending on the platform and/or
           IDE, the application may exit before this is actually called.
  */
  virtual void onException(const Exception&);
  
  /*! class. onWarning
      desc.
          When a warning is serious enough to make note of.
  */
  virtual void onWarning(const Warning&);
  
  /*! class. onNotice
      desc.
          When a notice is serious enough to make note of.
  */
  virtual void onNotice(const Notice&);
  
}; // class Error

                                                                                       

/*! class. ErrorStream
    desc.
        ErrorStream records and makes a note of all exceptions, warnings and notices. By default these are written
        to the console, but may be written to a resource, or a user app class may listen in.
        
        ErrorStream is a Singleton class, and is created/destroyed via World::createSingletons, World::createWorld or World::destroySingletons.
        
*/
class NxOgrePublicClass ErrorStream : public Singleton<ErrorStream>, public BigClassAllocatable
{
  
  friend class World;
  
  public:
  
  NXOGRE_GC_FRIEND_NEW0
  NXOGRE_GC_FRIEND_DELETE
  
  /*! function. addException
      desc.
          Add an exception.
      note.
          Do not call manually. The exception class will do this for you.
  */
  void addException(const Exception&);
  
  /*! function. addWarning
      desc.
          Add a warning.
      note.
          Do not call manually. The warning class will do this for you.
  */
  void addWarning(const Warning&);
  
  /*! function. addNotice
      desc.
          Add a notice.
      note.
          Do not call manually. The notice class will do this for you.
  */
  void addNotice(const Notice&);
  
  /*! function. setLogResource
      desc.
          Set the Log resource to a new one, or NULL to close.
      note.
          Changing resources will not re-print the previous activity into the new one
  */
  void setLogResource(Resource* resource);
  
  /*! function. getLogResource
      desc. 
          Get the resource that the ErrorStream is writing to.
      note.
          Do not close or delete the Resource.
  */
  Resource* getLogResource();
  
  /*! function. addListener
      desc.
           Add a listener for exceptions, warnings and notices
  */
  void  addListener(ErrorListener*);
  
  /*! function. removeListener
      desc.
           Remove a listener.
  */
  void  removeListener(ErrorListener*);

  protected:
  
  /*! constructor. ErrorStream
  */
  ErrorStream();
  
  /*! destructor. ErrorStream
  */
 ~ErrorStream();
  
  protected: // Variables
  
  std::vector<ErrorListener*> mListeners;
  
  Resource*                   mLogResource;
  
}; // class ErrorStream

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

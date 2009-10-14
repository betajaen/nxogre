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
#include "NxOgrePointerClass.h"
#include "NxOgreArray.h"
#include "NxOgreString.h"
#include "NxOgreSharedStringStream.h"

                                                                                       

namespace NxOgre
{

class Resource;
class SharedStringStream;

                                                                                       

/*! class. Error
    desc.
        Error is a single instance of an thrown error by NxOgre, carrying a message, it's type,
        and the file it was raised from.
*/
class NxOgrePublicClass Error : public PointerClass<Classes::_ErrorStream>
{
 public:
   
   /*! constructor. Error
       desc.
           Constructor for Error.
       args.
           const String& __message__ -- Compiled message.
           const String& __file__ -- Filename of the file raising the error.
           unsigned int __line__ -- The line of code that raised the error.
           unsigned int __errorType__ -- The type of error; 
   */
   Error(const String& message, const String& file, unsigned int line, unsigned char errorType);
   
   /*! destructor. Error
       desc.
           Error destructor.
   */
  ~Error();
  
  /*! variable. mMessage
      desc.
          The error message.
  */
  String  mMessage;
  
  /*! variable. mFile
      desc.
          The file of the source raising the error.
  */
  String  mFile;
  
  /*! variable. mLine
      desc.
          Line of code that raised the error.
  */
  unsigned int  mLine;
  
  /*! variable. mType
      desc.
          Type of error.
  */
  unsigned char mType;
  
}; // class Error

                                                                                       

/*! class. ErrorStream
    desc.
        ErrorStream handles all NxOgre and PhysX errors. It is also the source of all assertions caused by NxOgre and PhysX.
        
        ErrorStream is a Singleton class, and is created/destroyed via World::createSingletons, World::createWorld or World::destroySingletons.
        
*/
class NxOgrePublicClass ErrorStream : public ::NxOgre::Singleton<ErrorStream, ::NxOgre::Classes::_ErrorStream>
{
  
  friend class World;
  
  public: // Functions
  
  /*! function. throwAssertion
      desc.
           Record an very serious error.
      note.
           Use the  NxOgre_ThrowAssertion or NxOgreThrowCaseAssertion macro to use this function properly.
      args.
           const char* __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  void  throwAssertion(const char* message, const char* file, unsigned int line);
  
  /*! function. throwError
      desc.
          Record an serious error.
      note.
          Use the NxOgre_ThrowError macro to use this function properly.
      args.
           const char* __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  void  throwError(const char* message, const char* file, unsigned int line);
  
  /*! function. throwError
      desc.
          Record an serious error.
      note.
          Use the NxOgre_ThrowError macro to use this function properly.
      args.
           String& __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  void  throwError(const String& message, const char* file, unsigned int line);
  
  /*! function. throwWarning
      desc.
          Record less serious but recoverable error.
      note.
          Use the NxOgre_ThrowWarning or NxOgreThrowCaseWarning macro to use this function properly.
      args.
           const char* __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  void  throwWarning(const char* message, const char* file, unsigned int line);
  
  /*! function. throwNotice
      desc.
          Record notice
      note.
          Use the NxOgre_ThrowWarning or NxOgreThrowCaseWarning macro to use this function properly.
      args.
           const char* __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  void  throwNotice(const char* message, const char* file, unsigned int line);
  
  /*! function. throwNotice
      desc.
          Record notice
      note.
          Use the NxOgre_ThrowWarning or NxOgreThrowCaseWarning macro to use this function properly.
      args.
           const char* __message__ -- Error message.
           const char* __file__ -- Source file of the error.
           unsigned int __line__ -- Line throwing the error.
  */
  static  ErrorStream*  getSingleton(void);

  /*! function. setLogResource
      desc.
          Set the resource to write log messages to.
      args.
          Resource* __resource__ -- New resource to write to.
  */
  void  setLogResource(Resource* resource);
  
  protected: // Functions
  
  /*! constructor. ErrorStream
      desc.
         Use World::precreateSingletons or World::createWorld
  */
  ErrorStream(void);
  
  /*! destructor. ErrorStream
  */
  ~ErrorStream(void);
  
  /*! function. print
      desc.
           Writes an Error to a Resource.
      args.
           Error* error -- Error to write.
  */
  void  print(Error* error);
  
  protected: // Variables
  
  Array<Error*>       mErrors;
  
  Resource*           mLogResource;
  
  SharedStringStream  mStringStream;
  
}; // class ErrorStream

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

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

                                                                                       

class NxOgrePublicClass Error : public PointerClass<Classes::_ErrorStream>
{
 public:

   Error(const String& message, const String& file, unsigned int line, unsigned char error_type);
  ~Error();

  String  mMessage;
  String  mFile;
  unsigned int  mLine;
  unsigned char mType;
};

                                                                                       

/** \brief ErrorStream handles all NxOgre and PhysX errors. It is also the source of
           all assertions caused by NxOgre and PhysX.
*/
class NxOgrePublicClass ErrorStream : public ::NxOgre::Singleton<ErrorStream, ::NxOgre::Classes::_ErrorStream>
{
  
  friend class World;
 
  public: // Functions
  
  /** \brief Record an assertion. But use NxOgre_ThrowAssertion or NxOgreThrowCaseAssertion macro
             to use this function properly.
  */
                       void                   throwAssertion(const char* message, const char* file, unsigned int line);
  
  /** \brief Record an error. But use NxOgre_ThrowError or NxOgreThrowCaseError macro
             to use this function properly.
  */
                       void                   throwError(const char* message, const char* file, unsigned int line);
  
  /** \brief Record a warning. But use NxOgre_ThrowWarning or NxOgreThrowCaseWarning macro
             to use this function properly.
  */
                       void                   throwWarning(const char* message, const char* file, unsigned int line);
  
  /** \brief Record a notice. But use NxOgre_ThrowNotice or NxOgreThrowCaseNotice macro
             to use this function properly.
  */
                       void                   throwNotice(const char* message, const char* file, unsigned int line);
  
  static                ErrorStream*          getSingleton(void);

  /** \brief
  */
                       void                   setLogResource(::NxOgre::Resource*);

  protected: // Classes and Structs
  
  
  protected: // Functions
  
  /** \internal use World::precreateSingletons or World::createWorld
  */
                                              ErrorStream(void);
  
  /** \internal
  */
                                             ~ErrorStream(void);
  
  /** \internal
  */
                      void                    print(Error*);
  
  protected: // Variables
  
  Array<Error*>                               mErrors;
  
  Resource*                                   mLogResource;
  
  SharedStringStream                          mStringStream;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

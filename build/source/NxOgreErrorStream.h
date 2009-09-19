/** File: NxOgreErrorStream.h
    Created on: 4-Nov-08
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

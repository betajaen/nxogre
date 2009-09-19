/** File: NxOgrePhysXOutputStream.cpp
    Created on: 6-Nov-08
    Author: Robin Southern "betajaen"
    Last-Modified-For: PhysX 2.8.1
    

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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePhysXOutputStream.h"
#include "NxOgreErrorStream.h"
#include "NxOgreReason.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXOutputStream::PhysXOutputStream(void)
: mAssertionResponse(NX_AR_CONTINUE)
{
}

PhysXOutputStream::~PhysXOutputStream(void)
{
}

void PhysXOutputStream::setAssertionResponse(Enums::PhysXAssertionResponse response)
{
 mAssertionResponse = NxAssertResponse(int(response));
}


void PhysXOutputStream::reportError(NxErrorCode code, const char * message, const char *file, int line)
{

 SharedStringStream stream;

 if (code == NXE_DB_WARNING)
 {
  stream << "PhysX warning:\n";
 }
 else
 {
  stream << "PhysX error:\n";
 }

 stream << message << "\nNxErroCode:" << Reason::toCStr(code);

 if (code == NXE_DB_WARNING)
  ::NxOgre::ErrorStream::getSingleton()->throwWarning(stream.get(), file, line);
 else
  ::NxOgre::ErrorStream::getSingleton()->throwError(stream.get(), file, line);


}

NxAssertResponse PhysXOutputStream::reportAssertViolation(const char * message, const char *file, int line)
{
 
 SharedStringStream stream;
 stream << "PhysX assertion:\n" << message;
 
 ::NxOgre::ErrorStream::getSingleton()->throwAssertion(stream.get(), file, line);
 
 return mAssertionResponse;
}

void PhysXOutputStream::print(const char* message)
{
 NxOgre_ThrowNotice(message);
}


                                                                                       

} // namespace NxOgre

                                                                                       

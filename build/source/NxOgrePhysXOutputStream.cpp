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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePhysXOutputStream.h"
#include "NxOgreErrorStream.h"
#include "NxOgreReason.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXOutputStream::PhysXOutputStream()
: mAssertionResponse(NX_AR_CONTINUE)
{
}

PhysXOutputStream::~PhysXOutputStream()
{
}

void PhysXOutputStream::setAssertionResponse(Enums::PhysXAssertionResponse response)
{
 mAssertionResponse = NxAssertResponse(int(response));
}


void PhysXOutputStream::reportError(NxErrorCode code, const char* message, const char *file, int line)
{
 
 StringStream stream;
 
 if (code == NXE_DB_WARNING)
 {
  stream << "PhysX warning:\n";
 }
 else
 {
  stream << "PhysX error:\n";
 }
 
 stream << message << "\nNxErrorCode:" << Reason::toCStr(code);
 
 if (code == NXE_DB_WARNING)
 {
  NxOgre_ThrowWarning(stream.str(), Classes::_PhysXOutputStream);
 }
 else
 {
  NxOgre_ThrowException(PhysXInternalErrorException, stream.str(), Classes::_PhysXOutputStream);
 }
 
}

NxAssertResponse PhysXOutputStream::reportAssertViolation(const char* message, const char *file, int line)
{
 
 StringStream stream;
 stream << "PhysX assertion:\n" << message;
 
 NxOgre_ThrowException(PhysXInternalErrorException, stream.str(), Classes::_PhysXOutputStream);
 
 return mAssertionResponse;
}

void PhysXOutputStream::print(const char* message)
{
 NxOgre_ThrowNotice(message);
}


                                                                                       

} // namespace NxOgre

                                                                                       

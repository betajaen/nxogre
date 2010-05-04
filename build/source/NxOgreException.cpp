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
#include "NxOgreException.h"
#include "NxOgreString.h"
#include "NxOgreErrorStream.h"

#include <iostream>

                                                                                       

namespace NxOgre
{

                                                                                       

Exception::Exception(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type, unsigned int exception_type, const std::string& exception_name)
: mFile(file),
  mLine(line),
  mDescription(description),
  mClassType(class_type),
  mExceptionType(exception_type),
  mExceptionName(exception_name)
{
 
 std::cout << to_s() << std::endl;
 
 if (NxOgre::ErrorStream::getSingleton())
  NxOgre::ErrorStream::getSingleton()->addException(*this);
 
}

Exception::Exception(const Exception& other)
: mFile(other.mFile),
  mLine(other.mLine),
  mDescription(other.mDescription),
  mClassType(other.mClassType),
  mExceptionType(other.mExceptionType),
  mExceptionName(other.mExceptionName)
{
}

Exception::~Exception() throw()
{
}

Exception& Exception::operator=(const Exception& other)
{
 mFile = other.mFile;
 mLine = other.mLine;
 mDescription = other.mDescription;
 mClassType = other.mClassType;
 mExceptionType = other.mExceptionType;
 mExceptionName = other.mExceptionName;
 return *this;
}

const std::string& Exception::getFile() const
{
 return mFile;
}

unsigned int Exception::getLine() const
{
 return mLine;
}

const std::string& Exception::getDescription() const
{
 return mDescription;
}

unsigned int Exception::getExceptionType() const
{
 return mExceptionType;
}

std::string Exception::getExceptionTypeAsString() const
{
 return mExceptionName;
}

unsigned int Exception::getClassType() const
{
 return mClassType;
}

std::string Exception::to_s() const
{

 // ExceptionName (ClassType)
 // =========================
 //
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // 
 // From: File.cpp#42

 std::ostringstream s;
 s << "\n=====================================================================\n";
 s << mExceptionName <<  " (" << Classes::TypeToCStr(mClassType) << ")\n";
 s << "=====================================================================\n";
 s << "\n" << mDescription << "\nFrom: " << mFile << "#" << mLine << "\n\n";
 s << "=====================================================================\n\n";
 return s.str();

}

                                                                                       

} // namespace NxOgre

                                                                                       

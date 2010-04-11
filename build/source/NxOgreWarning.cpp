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

                                                                                       

Warning::Warning(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type)
: mFile(file),
  mLine(line),
  mDescription(description),
  mClassType(class_type)
{
 
 std::cout << str() << std::endl;
 
 if (NxOgre::ErrorStream::getSingleton())
  NxOgre::ErrorStream::getSingleton()->addWarning(*this);
 
}

Warning::Warning(const Warning& other)
: mFile(other.mFile),
  mLine(other.mLine),
  mDescription(other.mDescription),
  mClassType(other.mClassType)
{
}

Warning::~Warning()
{
}

Warning& Warning::operator=(const Warning& other)
{
 mFile = other.mFile;
 mLine = other.mLine;
 mDescription = other.mDescription;
 mClassType = other.mClassType;
 return *this;
}

const std::string& Warning::getFile() const
{
 return mFile;
}

unsigned int Warning::getLine() const
{
 return mLine;
}

const std::string& Warning::getDescription() const
{
 return mDescription;
}

unsigned int Warning::getClassType() const
{
 return mClassType;
}

std::string Warning::str() const
{
 // Warning (ClassType)
 // ===================
 //
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // 
 // From: File.cpp#42

 StringStream s;
 std::string header("Warning (");
 header.append(Classes::TypeToCStr(mClassType));
 header.append(")");
 s << header << "\n";
 
 for (unsigned int i=0; i < header.length(); i++)
  s << "=";
 s << "\n\n" << mDescription << "\nFrom: " << mFile << "#" << mLine << "\n\n";
 
 return s.str();
}


                                                                                       

} // namespace NxOgre

                                                                                       

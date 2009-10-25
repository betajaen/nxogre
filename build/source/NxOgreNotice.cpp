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

                                                                                       

Notice::Notice(const std::string& file, unsigned int line, const std::string& description)
: mFile(file),
  mLine(line),
  mDescription(description)
{
 
 std::cout << str() << std::endl;
 
 if (NxOgre::ErrorStream::getSingleton())
  NxOgre::ErrorStream::getSingleton()->addNotice(*this);
 
}

Notice::Notice(const Notice& other)
: mFile(other.mFile),
  mLine(other.mLine),
  mDescription(other.mDescription)
{
}

Notice::~Notice()
{
}

Notice& Notice::operator=(const Notice& other)
{
 mFile = other.mFile;
 mLine = other.mLine;
 mDescription = other.mDescription;
 return *this;
}

const std::string& Notice::getFile() const
{
 return mFile;
}

unsigned int Notice::getLine() const
{
 return mLine;
}

const std::string& Notice::getDescription() const
{
 return mDescription;
}

std::string Notice::str() const
{
 // Notice (ClassType)
 // =========================
 //
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // Description Text. Description Text. Description Text. Description Text. Description Text. Description Text. 
 // 
 // From: File.cpp#42

 StringStream s;
 s << "Warning\n=======";
 s << "\n\n" << mDescription << "\nFrom: " << mFile << "#" << mLine << "\n\n";
 
 return s.str();
}


                                                                                       

} // namespace NxOgre

                                                                                       

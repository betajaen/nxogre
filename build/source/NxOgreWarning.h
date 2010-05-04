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

                                                                                       

#ifndef NXOGRE_WARNING_H
#define NXOGRE_WARNING_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreClasses.h"
#include <string>

                                                                                       

namespace NxOgre
{


                                                                                       

/*! class. Warning
    desc.
        Stores a description,file and line, of thrown warning by NxOgre or PhysX.
*/
class NxOgrePublicClass Warning
{
 public:
  
  /*! constructor. Warning
      desc.
  */
  Warning(const std::string& file, unsigned int line, const std::string& description, unsigned int class_type);
  
  /*! constructor. Warning.copy
      desc.
          Copy constructor.
  */
  Warning(const Warning&);
  
  /*! destructor. Warning
  */
  ~Warning();
  
  /*! function. Operator.assignment
      desc.
           Assignment operator.
  */
  Warning& operator=(const Warning& other);

  /*! function. getFile
      desc.
           Get file that threw the warning
  */
  const std::string& getFile() const;
  
  /*! function. getLine
      desc.
           Get the line in the file that threw the warning.
  */
  unsigned int getLine() const;
  
  /*! function. getDescription
      desc. 
           Get a descriptive message of why the warning was thrown.
  */
  const std::string& getDescription() const;
  
  /*! function. getClassType
      desc.
          Get type of class that threw the warning.
  */
  unsigned int getClassType() const;

  /*! function. str
      desc.
           Formats the warning as a markdown formatted string
  */
  std::string to_s() const;
  
 protected:
  
  std::string  mFile;
  unsigned int mLine;
  std::string  mDescription;
  unsigned int mClassType;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

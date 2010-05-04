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

                                                                                       

#ifndef NXOGRE_NOTICE_H
#define NXOGRE_NOTICE_H

                                                                                       

#include "NxOgreStable.h"
#include <string>

                                                                                       

namespace NxOgre
{


                                                                                       

/*! class. Notice
    desc.
        Stores a description,file and line, of thrown notice by NxOgre or PhysX.
*/
class NxOgrePublicClass Notice
{
 public:
  
  /*! constructor. Notice
      desc.
  */
  Notice(const std::string& file, unsigned int line, const std::string& description);
  
  /*! constructor. Notice.copy
      desc.
          Copy constructor.
  */
  Notice(const Notice&);
  
  /*! destructor. Notice
  */
  ~Notice();
  
  /*! function. Operator.assignment
      desc.
           Assignment operator.
  */
  Notice& operator=(const Notice& other);

  /*! function. getFile
      desc.
           Get file that threw the notice
  */
  const std::string& getFile() const;
  
  /*! function. getLine
      desc.
           Get the line in the file that threw the notice.
  */
  unsigned int getLine() const;
  
  /*! function. getDescription
      desc. 
           Get a descriptive message of why the notice was thrown.
  */
  const std::string& getDescription() const;
  
  /*! function. str
      desc.
           Formats the notice as a markdown formatted string
  */
  std::string to_s() const;
  
 protected:
  
  std::string  mFile;
  unsigned int mLine;
  std::string  mDescription;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

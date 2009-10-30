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
#include "NxOgreFileResourceProtocol.h"
#include "NxOgreFunctions.h"
#include "NxOgreArchive.h"
#include "NxOgreResource.h"
#include "NxOgreFileArchive.h"

#include "time.h"
#ifdef _DEBUG
#include <iostream>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

FileResourceProtocol::FileResourceProtocol(void)
{
 mProtocolName = "file";
 mProtocolHash = Functions::StringHash(mProtocolName);
}

FileResourceProtocol::~FileResourceProtocol(void)
{
}

Archive* FileResourceProtocol::openArchive(const String& name, const Path& path)
{
#ifdef _DEBUG
 std::cout << "Opening file archive as '" << name << "' from '" << path.getString() << std::endl;
#endif
 return new FileArchive(name, path, this);
}

void FileResourceProtocol::closeArchive(Archive* archive)
{
}

String FileResourceProtocol::getProtocol(void) const
{
 return mProtocolName;
}

StringHash FileResourceProtocol::getProtocolHash(void) const
{
 return mProtocolHash;
}

bool FileResourceProtocol::isSingleArchive(void) const
{
 return false;
}

bool FileResourceProtocol::usesNamelessResources(void) const
{
 return false;
}

void FileResourceProtocol::initialise(void)
{
 // No default archives, so nothing to do.
}

String FileResourceProtocol::calculateArchiveName(const Path& path)
{
 
 // Working Directory.
 if (path.isAbsolute() == false && path.getNbDirectories() == 0)
 {
  return String("working_directory");
 }
 
 if (path.getNbDirectories() == 0) // Root.
 {

  if (path.hasDrive() == false)
  {
   srand ( time(NULL) );
   std::stringstream ss;
   ss << "file_archive_" << std::hex << rand() % 10000000;
   return ss.str();
  }
  else
  {
   return path.getDrive();
  }
 }
 
 if (path.getNbDirectories() == 1)
 {
  return path.getDirectory();
 }
 else
 {
  
  std::cout << "+ Calculating archive name from " << path.getString() << std::endl;
  
  std::stringstream archive_name;
  unsigned int relative_path = 0;
  for (unsigned int i = 0;i < path.getNbDirectories();i++)
  {
   std::string dir_name = path.getDirectory(i);
   if (dir_name == "..")
   {
    relative_path++;
    continue;
   }
   
   if (relative_path)
   {
    archive_name << "#." << relative_path;
    relative_path = 0;
   }
   
   if (i!=0)
    archive_name << "#" << dir_name;
   else
    archive_name << dir_name;
  }
  
  if (relative_path)
  {
    archive_name << "#." << relative_path;
  }
  
  return archive_name.str();
 }
}


                                                                                       

} // namespace NxOgre

                                                                                       

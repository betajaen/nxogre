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
#include "NxOgrePath.h"
#include "NxOgreList.h"

#include <iostream>

                                                                                       

namespace NxOgre
{

std::map<String, String> Path::sAliases = std::map<String, String>();

                                                                                       
class PathHelper
{
  
 public:

   static bool is_directory(char c)         { return c == '\\' || c == '/'; }
   static bool is_drive(char c)             { return c == ':'; }
   static bool is_protocol(char c)          { return c == ':'; }
   static bool is_portion(char c)           { return c == '#'; }
   static bool is_extension(char c)         { return c == '.'; }
   static bool is_relative_path(char c)     { return c == '.'; }
   
   static char protocol()                   { return ':'; }
   static char drive()                      { return ':'; }
   static char directory()                  { return '/'; }
   static char extension()                  { return '.'; }
   static char portion()                    { return '#'; }
   static char relative_path()              { return '.'; }
   static String parent_marker()            { return String(".."); }
   
   static String working_directory_marker() { return String("."); }
   
   static bool next_is(const String& string, size_t pos, char delimiter)
   {
    if (pos + 1 >= string.length())
     return false;
    
    return (string[pos + 1] == delimiter);
   }
   
   static bool at_end(const String& string, size_t pos)
   {
    return (pos >= string.length() - 1);
   }
};

const Path Path::BAD_PATH = Path();

Path::Path() : mAbsolute(false)
{
}

Path::Path(const char* path)
{
 set(String(path));
}

Path::Path(const String& path)
{
 set(path);
}

Path::Path(const Path& other)
: mProtocol(other.mProtocol),
#if NxOgrePlatform == NxOgrePlatformWindows
  mDrive(other.mDrive),
#endif
  mFilename(other.mFilename),
  mExtension(other.mExtension),
  mPortion(other.mPortion),
  mDirectories(other.mDirectories),
  mAbsolute(other.mAbsolute)
{
}

Path::~Path()
{
}

void Path::SetAlias(const String& aliasName, const String& pathString)
{
 String aliasPath = pathString;
 if (aliasPath[aliasPath.length() - 1] == '//')
  aliasPath = aliasPath.substr(0, aliasPath.length() - 1);
 sAliases[aliasName] = aliasPath;
}

Path& Path::operator=(const Path& other)
{
 mProtocol = other.mProtocol;
#if NxOgrePlatform == NxOgrePlatformWindows
 mDrive = other.mDrive;
#endif
 mFilename = other.mFilename;
 mExtension = other.mExtension;
 mPortion = other.mPortion;
 mDirectories = other.mDirectories;
 mAbsolute = other.mAbsolute;
 return *this;
}

Path Path::operator /(const Path& other)
{
 // Can't do two absolute paths, or an relative path then another absolute.
 if ( (mAbsolute && other.mAbsolute) || (!mAbsolute && other.mAbsolute))
  return BAD_PATH;
 // Can't mix up protocols.
 if ( other.mProtocol.length())
  if ( (mProtocol != other.mProtocol) )
   return BAD_PATH;
 // Can't add two paths together, if this has a filename.
 if ( mFilename.length() )
  return BAD_PATH;

 Path out;
 out.mProtocol = mProtocol;
#if NxOgrePlatform == NxOgrePlatformWindows
 out.mDrive = mDrive;
#endif

 for (std::list<String>::const_iterator d = mDirectories.begin(); d != mDirectories.end(); d++)
  out.mDirectories.push_back((*d));

 for (std::list<String>::const_iterator d = other.mDirectories.begin(); d != other.mDirectories.end(); d++)
  out.mDirectories.push_back((*d));

 /*
 out.mDirectories.insert(out.mDirectories.begin(), mDirectories.begin(), mDirectories.end());
 
 for (std::list<String>::const_iterator d = other.mDirectories.begin(); d != other.mDirectories.end(); d++)
 {
  /*if ((*d) == PathHelper::parent_marker())
  {
   if (out.mDirectories.size())
    out.mDirectories.pop_back();
  }
  else
   
   out.mDirectories.push_back((*d));
 }
 */
 out.mFilename = other.mFilename;
 out.mExtension = other.mExtension;
 out.mProtocol = other.mProtocol;
 
 return out;
}

Path Path::operator /(const char* other)
{
 return operator/(Path(other));
}

Path Path::operator /(const String& other)
{
 return operator/(Path(other));
}

Path& Path::operator /=(const Path& other)
{
 // Can't do two absolute paths, or an relative path then another absolute.
 if ( (mAbsolute && other.mAbsolute) || (!mAbsolute && other.mAbsolute))
 {
  clear();
  return *this;
 }
 // Can't mix up protocols.
 if ( other.mProtocol.length())
  if ( (mProtocol != other.mProtocol) )
  {
   clear();
   return *this;
  } // Can't add two paths together, if this has a filename.
 if ( mFilename.length() )
 {
  clear();
  return *this;
 }

 for (std::list<String>::const_iterator d = other.mDirectories.begin(); d != other.mDirectories.end(); d++)
  mDirectories.push_back((*d));
 
 /*
 out.mDirectories.insert(out.mDirectories.begin(), mDirectories.begin(), mDirectories.end());
 
 for (std::list<String>::const_iterator d = other.mDirectories.begin(); d != other.mDirectories.end(); d++)
 {
  /*if ((*d) == PathHelper::parent_marker())
  {
   if (out.mDirectories.size())
    out.mDirectories.pop_back();
  }
  else
   
   out.mDirectories.push_back((*d));
 }
 */
 
 mFilename = other.mFilename;
 mExtension = other.mExtension;
 mProtocol = other.mProtocol;
 
 return *this;
}

Path& Path::operator /=(const String& other)
{
 return operator/=(Path(other));
}

Path& Path::operator /=(const char* other)
{
 return operator/=(Path(other));
}

Path Path::getParent() const
{
 Path parent;
 parent.mProtocol = mProtocol;
#if NxOgrePlatform == NxOgrePlatformWindows
 parent.mDrive = mDrive;
#endif
 
 for (std::list<String>::const_iterator d = mDirectories.begin(); d != mDirectories.end(); d++)
  parent.mDirectories.push_back((*d));
 
 // If there is a portion, then the file is the "parent".
 if (mPortion.length())
 {
  parent.mFilename = mFilename;
  parent.mExtension = mExtension;
 }
 else // Otherwise it is the directory, or drive.
 {
  if (mFilename.length() == 0 && parent.mDirectories.size())
   parent.mDirectories.pop_back();
 }

 return parent;
}

Path Path::getRelative() const
{
 Path current;
 current.mProtocol = mProtocol;
 current.mFilename = mFilename;
 current.mExtension = mExtension;
 current.mPortion = mPortion;
 return current;
}

String Path::getDirectory(unsigned int parent_level) const
{
 if (parent_level == 0)
  return (*mDirectories.rbegin());
 else
 {
  std::list<String>::const_reverse_iterator it = mDirectories.rbegin();
  for (unsigned int i=0; i < parent_level;i++)
   it++;
  return (*it);
 }
}

unsigned int Path::getNbDirectories() const
{
 return mDirectories.size();
}

String Path::getFilename() const
{
 StringStream s;
 if (mFilename.length())
  s << mFilename << PathHelper::extension();
 s << mExtension;
 return s.str();
}

bool Path::hasFilename() const
{
 return mFilename.length() > 0;
}

String Path::getFilenameOnly() const
{
 return mFilename;
}

String Path::getExtension() const
{
 return mExtension;
}

bool Path::hasExtension() const
{
 return mExtension.length() > 0;
}

String Path::getPortion() const
{
 return mPortion;
}

bool Path::hasPortion() const
{
 return mPortion.length() > 0;
}

String Path::getProtocol() const
{
 return mProtocol;
}

StringHash Path::getProtocolHash() const
{
 return Strings::hash(mProtocol);
}

#if NxOgrePlatform == NxOgrePlatformWindows
String Path::getDrive() const
{
 return mDrive;
}
#endif

#if NxOgrePlatform == NxOgrePlatformWindows
bool Path::hasDrive() const
{
 return mDrive.length() > 0;
}
#endif

bool Path::isAbsolute() const
{
 return mAbsolute;
}

String Path::getString() const
{
 StringStream s;
 if (mProtocol.length())
  s << mProtocol << "://";

#if NxOgrePlatform == NxOgrePlatformWindows
 if (mDrive.length())
  s << mDrive << PathHelper::directory();
#else
 if (mAbsolute)
  s << PathHelper::directory();
#endif
 
 for (std::list<String>::const_iterator d = mDirectories.begin(); d != mDirectories.end(); d++)
  s << (*d) << PathHelper::directory();
 
 if (mFilename.length())
  s << mFilename;
 if (mExtension.length())
  s << PathHelper::extension() << mExtension;
 if (mPortion.length())
  s << PathHelper::portion() << mPortion;

 return s.str();
}

String Path::getOSString()
{

 StringStream s;
 
#if NxOgrePlatform == NxOgrePlatformWindows
 if (mDrive.length())
  s << mDrive << PathHelper::directory();
#else
 if (mAbsolute)
  s << PathHelper::directory();
#endif
 
 for (std::list<String>::const_iterator d = mDirectories.begin(); d != mDirectories.end(); d++)
  s << (*d) << PathHelper::directory();
 
 if (mFilename.length())
  s << mFilename;
 if (mExtension.length())
  s << PathHelper::extension() << mExtension;

 return s.str();
}

void Path::clear()
{
 mAbsolute = false;
 mProtocol = String();
#if NxOgrePlatform == NxOgrePlatformWindows
 mDrive = String();
#endif
 mDirectories.clear();
 mFilename = String();
 mExtension = String();
 mPortion = String();
}

void Path::set(const String& string)
{
 clear();
 
 size_t pos = 0;
 String path(string);
 
 if (path.length() == 0)
  return;
 
 if (path.length() == 1) // One character? Then it could be a file, or path. Both are relative.
 {
  if (PathHelper::is_relative_path(path[pos]))
   mDirectories.push_back(path);
  else
   mFilename = path;
  mAbsolute = false;
  return;
 }

 if (path.length() == 2) // Two characters. File or path. Both are relative.
 {
  if (PathHelper::is_relative_path(path[pos]) && PathHelper::is_relative_path(path[pos + 1]))
   mDirectories.push_back(path);
  else
   mFilename = path;
  mAbsolute = false;
  return;
 }
 
 // Check for an alias; ~aliasname/
 if (path[0] == '+' && Strings::has(path, '/'))
 {
  std::cout << "alias" << std::endl;
  size_t ender = path.find_first_of('/');
  String alias = path.substr(1, ender - 1);
  
  std::cout << "alias => '" << alias << "'.\n";
  AliasIterator it =  sAliases.find(alias);
  
  if (it == sAliases.end()) // Unknown Alias.
   return;
  
  String after = path.substr(ender);
  std::cout << after << std::endl;
  set((*it).second + "/" + after);
  return;
 }

 // Check for drive or protocol. 
 String t;
 size_t begin = pos;
 while (pos < path.length() - 1)
 {
#if NxOgrePlatform == NxOgrePlatformLinux
  if (PathHelper::is_protocol(path[pos]))
  {
   t = path.substr(begin, pos - begin);

   if (PathHelper::next_is(path, pos, PathHelper::directory()) && PathHelper::next_is(path, pos + 1, PathHelper::directory()))
   {
    mProtocol = t;
    pos += 3;
    break;
   }
  }
#else
  if (PathHelper::is_protocol(path[pos]) || PathHelper::is_drive(path[pos]))
  {
   t = path.substr(begin, pos - begin);
   
   if (PathHelper::next_is(path, pos, PathHelper::directory()) && PathHelper::next_is(path, pos + 1, PathHelper::directory()))
   {
    mProtocol = t;
    pos += 3;
    break;
   }
   else
   {
    mDrive = t;
    mAbsolute = true;
    pos++;
    break;
   }
  }
#endif
  pos++;
 }

#if NxOgrePlatform == NxOgrePlatformLinux
 if (mProtocol.length() == 0)
  pos = 0;
#else
 if (mDrive.length() == 0 && mProtocol.length() == 0)
  pos = 0;
#endif

 if (PathHelper::at_end(path, pos))
  return;

#if NxOgrePlatform == NxOgrePlatformWindows
 // Check for a drive (again)
 if (mDrive.length() == 0)
 {
  if (PathHelper::next_is(path, pos, PathHelper::drive()))
  {
   mDrive = path.substr(pos, 1);
   mAbsolute = true;
   pos+=2;
  }
 }
#endif
 
#if NxOgrePlatform == NxOgrePlatformWindows
 // Check for initial '/' which isn't needed.
 if (path[pos] == PathHelper::directory())
  pos++;
#else
 // Check for initial '/' which indicates linux's root.
 if (path[pos] == PathHelper::directory())
 {
  pos++;
  mAbsolute = true;
 }
#endif
 
 // Start scanning for directories.
 begin = pos;
 
 while (pos < path.length() - 1)
 {
  pos++;
  
  // Prevent parsing of "/" in a portion part.
  if (PathHelper::is_portion(path[pos]))
   break;
  
  if (PathHelper::is_directory(path[pos]))
  {
   if (pos == begin)
   {
    begin++;
    continue; // Double "/"
   }
   
   t = path.substr(begin, pos - begin);

   if (t == PathHelper::working_directory_marker())
   {
    mAbsolute = false;
    begin = pos + 1;
    continue;
   }

   if (t == PathHelper::parent_marker() && mAbsolute)
   {
    if (mDirectories.size() )
     mDirectories.pop_back();
    begin = pos + 1;
    continue;
   }
   mDirectories.push_back(t);
   begin = pos + 1;
  }
 }
 
 if (PathHelper::at_end(path, begin))
  return;
 
 pos = begin;

 // Search for a extension marker.
 while (pos < path.length() - 1)
 {
  
  // Files that start with "."
  if (pos == begin && PathHelper::is_extension(path[pos]))
  {
   pos++;
   continue;
  }

  // filename and filename.extension (marker)
  if (mFilename.length() == 0 && PathHelper::is_extension(path[pos]))
  {
   mFilename = path.substr(begin, pos - begin);
   begin = pos;
   pos++;
   continue;
  }

  // # at the end of the string
  if (PathHelper::next_is(path, pos, PathHelper::portion()) && pos == path.length() - 2)
  {
   mExtension = path.substr(begin + 1, path.length() - begin - 2);
   break;
  }
 
  // filename.extension#portion
  if (mFilename.length() && PathHelper::is_portion(path[pos]))
  {
   mPortion = path.substr(pos + 1);
   pos--;
   break;
  }
  pos++;
 }
 
 if (mFilename.length() == 0)
  mFilename = path.substr(begin, pos - begin + 1);
 else if (mExtension.length() == 0)
  mExtension = path.substr(begin + 1, pos - begin);

 if (mExtension == "#")
  mExtension = String();
}

void Path::inspect() const
{
 
 std::cout << "[ ";

 if (mProtocol.length())
  std::cout << "'" << mProtocol << "'";
 
#if NxOgrePlatform == NxOgrePlatformWindows
 if (mDrive.length())
  std::cout << ", '" << mDrive << "'";
#endif
 
 if (mDirectories.size())
  std::cout << ", [" << Lists::join(mDirectories, ", ") << "]";
 
 if (mFilename.length())
  std::cout << ", " << mFilename;
 
 if (mExtension.length())
  std::cout << ", " << mExtension;
 
 if (mPortion.length())
  std::cout << ", " << mPortion;
 
 std::cout << "]\n";
 
}

                                                                                       

} // namespace NxOgre

                                                                                       

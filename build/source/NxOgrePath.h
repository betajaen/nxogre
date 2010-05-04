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

                                                                                       

#ifndef NXOGRE_PATH_H
#define NXOGRE_PATH_H

#include "NxOgreStable.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Path
    desc. Simple path class used with ResourceSystem to represent paths in a filesystem, or represent identifiers to
          resources in archives using a specific protocol.
          
          A path is formatted as;
          
          bc. protocol://drive:/directory_name/sub_directory_name/filename.extension#portion
          
   examples.
          
          file://C:/Program Files/Game/Game.exe               (Specific file)
          
          file://C:/Program Files/Game/                       (Directory)
          
          file://../Game/                                     (Relative Directory with ".." operator)
            Resolves to: file://..Game/

          file://C:/Program Files/Game/../OtherGame/Game.exe  (Directory ".." resolving)
            Resolves to:  file://C:/Program Files/OtherGame/Game.exe

          file://Game.exe                                     (Relative File)
          
          zip://C:/Program Files/Game/media.zip               (Example Zip Resource Protocol)
          
          zip://C:/Program Files/Game/media.zip#file.nxs      (Access file.nxs in media.zip)
          
          zip://media.zip#file.nxs                            (Relative file, accessing a file in file.nxs zip file)
          
          file:///home/franky/Desktop/file.nxs                (Supports Unix paths)
          
          memory://                                           (Protocol is given only)
          
          
   usage.
       # Basic usage -- @Path path("c:/Program Files/My Game/Game.exe");@
       # ".." modifiers work -- @Path path("c:/Program Files/My Game/../No my other game/Game.exe");@
       # Combining two paths together with the / operator -- @Path path = Path("c:/Program Files/My Game/../No my other game/) / Path("Game.exe");@
       # Combining a path and string together with the / operator -- @Path path = Path("c:/Program Files/My Game/../No my other game/) / "Game.exe";@
       # Multi-line combination of paths.
       bc.
        Path path("c:/Program Files/");
        path /= "My Game/";
        path /= "Game.exe";
       # Getting the parent path.
       bc.
        Path path("c:/Program Files/My Game");
        Path program_files = path.getParent().getParent();
        program_files /= "My Other Game/OtherGame.exe";
       
       # Getting the filename of the path
       bc.
        Path path("c:/Program Files/My Game/Game.exe");
        path.getFilename() => Game.exe
       
       # Getting the directory name of the file.
       bc.
        Path path("c:/Program Files/My Game/Game.exe");
        path.getDirectory() => My Game
       
       # Getting the parent directory name of the file.
       bc.
        Path path("c:/Program Files/My Game/Game.exe");
        path.getDirectory(1) => Program Files
       
       # Using protocols and portions.
       bc.
        Path path("zip://c:/Program Files/My Game/media.zip#poem.txt");
        path.getProtocol() => zip
        path.getPortion() => poem.txt
      
       # Natural protocols
       bc.
        Path path("file://c:/Program Files/My Game/Game.exe");
        path.getProtocol() => file
        Path path("c:/Program Files/My Game/Game.exe");
        path.getProtocol() => file
       
       # Don't repeat your self (Aliases)
       Aliases can be used to prevent repetition, and to define a partial path early
       on in your Application.
       bc.
        Path::AddAlias("game", "file://c:/Program Files/My Game/");
        Path path("+game/Game.exe");
       Which is equilvant to.
        Path path("file://c:/Program Files/My Game/Game.exe");
*/
class NxOgrePublicClass Path
{
 
 public:
   
   typedef std::map<String, String>                  Aliases;
   typedef std::map<String, String>::const_iterator  AliasIterator;
   
   static const Path BAD_PATH;
   
   Path();
   
   Path(const char* path);
   
   Path(const String& path);
   
   Path(const Path&);
   
  ~Path();
   
   Path& operator=(const Path&);
   
   Path operator /(const Path& other);
   
   Path operator /(const String& other);
   
   Path operator /(const char* other);
   
   Path& operator /=(const Path& other);
   
   Path& operator /=(const String& other);
   
   Path& operator /=(const char* other);
   
   /*! function. SetAlias
       desc.
           Set or add an path alias. Aliases can be used to prevent repetition, and to define a partial path early on in your Application.
           bc.
            Path::AddAlias("game", "file://c:/Program Files/My Game/");
            Path path("+game/Game.exe");
           Which is equilvant to.
            Path path("file://c:/Program Files/My Game/Game.exe");
   */
   static void SetAlias(const String& aliasName, const String& pathString); 
   
   /*! function. getDirectory
       desc.
           Get the directory of the path, or the directories of lower levels.
   */
   String getDirectory(unsigned int parent_level = 0) const;
      
   /*! function. getNbDirectories
       desc.
           Get the number of directories or how deep the file is.
   */
   unsigned int getNbDirectories() const;
   
   /*! function. getFilename
       desc.
           Get the filename (and extension)
   */
   String getFilename() const;
   
   /*! function. hasFilename
       desc.
           Has the path have a filename?
   */
   bool hasFilename() const;

   /*! function. getFilenameOnly
       desc.
            Get just the filename (no extension)
   */
   String getFilenameOnly() const;
   
      /*! function. getExtension
       desc.
            Get the extension
   */
   String getExtension() const;
   
   /*! function. hasExtension
       desc.
            Has an extension?
   */
   bool hasExtension() const;
   
   /*! function. getPortion
       desc.
            Get the portion
   */
   String getPortion() const;
   
   /*! function. hasPortion
       desc.
            Has an extension?
   */
   bool hasPortion() const;
   
   /*! function. getProtocol
       desc.
            Get the protocol
   */
   String getProtocol() const;
   
   /*! function. getProtocolHash
       desc.
            Get the hash of the protocol
   */
   StringHash getProtocolHash() const;
   
#if NxOgrePlatform == NxOgrePlatformWindows
   /*! function. getDrive
       desc.
            Get the drive.
   */
   String getDrive() const;
#endif

#if NxOgrePlatform == NxOgrePlatformWindows
   /*! function. hasDrive
       desc.
            Has an extension?
   */
   bool hasDrive() const;
#endif

   /*! function. isAbsolute
       desc.
            Is the path absolute or relative?
   */
   bool isAbsolute() const;
   
   /*! function. getParent
       desc.
            Get parent path. A directory (if has filename), drive (has one directory and no filename) or file (has portion).
   */
   Path getParent() const;

   /*! function. getRelative
       desc.
            Get relative path to the file, the path without directories or drives.
   */
   Path getRelative() const;
   
   /*! function. getString
       desc.
            Correctly format it.
   */
   String getString() const;
   
   /*! function. getOSString
       desc.
            Correctly format it as a OS string; no protocol or portion.
   */
   String getOSString();
   
   /*! function. inspect
       desc.
           Developer/Testing function.
   */
   void inspect() const;

 protected:
   
   /* Turns path into drive, filename, directories, etc.
   */
   void set(const String& path);
   
   /* Clears the path.
   */
   void clear();

   String            mProtocol,
#if NxOgrePlatform == NxOgrePlatformWindows
                     mDrive,
#endif
                     mFilename,
                     mExtension,
                     mPortion;
   
   std::list<String> mDirectories;
   
   bool              mAbsolute;
   
   static Aliases sAliases;
   
};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif

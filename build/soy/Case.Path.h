#ifndef TEST_PATH_H
#define TEST_PATH_H

#include "Soy.h"

CASE_BEGIN(Path)
Path()
{
 CASE_DESCRIPTION("NxOgre::Path");
 
 TEST_DESCRIPTION("Empty Path")
 {
  NxOgre::Path path;

  TEST_FAIL_IF(path.getProtocolHash(), "Has Protocol -> " + path.getProtocol())
  TEST_FAIL_IF(path.hasDrive(), "Has Drive -> " + path.getDrive())
  TEST_FAIL_IF(path.hasExtension(), "Has Extension" + path.getExtension())
  TEST_FAIL_IF(path.hasFilename(), "Has Filename" + path.getFilename())
  TEST_FAIL_IF(path.hasPortion(), "Has Portion" + path.getPortion());
 }

 TEST_DESCRIPTION("Protocol only test; 'file://'")
 {
  NxOgre::Path path("file://");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file'");
  TEST_FAIL_IF(path.getProtocolHash() == 0, "Protocol hash is zero");
 }

 TEST_DESCRIPTION("Long protocol test; 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx://'")
 {
  NxOgre::Path path("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx://");
  
  TEST_FAIL_IF(path.getProtocol() != "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "Protocol is not 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'");
  TEST_FAIL_IF(path.getProtocolHash() == 0, "Protocol hash is zero");
 }

 TEST_DESCRIPTION("Malformed protocol test; 'file:/a//'")
 {
  NxOgre::Path path("file:/a//");
  
  TEST_FAIL_IF(path.getProtocol() == "file:/a//", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getProtocolHash() != 0, "Protocol hash is not zero");
 }
 
 TEST_DESCRIPTION("Malformed protocol test 2; 'file://test#x://y/z'")
 {
  NxOgre::Path path("file://test#x://y/z");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getProtocolHash() == 0, "Protocol hash is zero");
 }

 TEST_DESCRIPTION("Drive test; 'file://c:/'")
 {
  NxOgre::Path path("file://c:/");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 0, "No directories in path, there are " + uintToString(path.getNbDirectories()));
 }
 
 TEST_DESCRIPTION("Drive test; 'file://c:/monkey.jpeg'")
 {
  NxOgre::Path path("file://c:/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 0, "No directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Folder test test; 'file://c:/pictures/monkey.jpeg'")
 {
  NxOgre::Path path("file://c:/pictures/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 1, "No directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures", "Parent is not 'monkey', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Folder test test; 'file://c:/pictures/monkey.jpeg'")
 {
  NxOgre::Path path("file://c:/pictures/monkey.jpeg");
   
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 1, "Not one directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures", "Parent is not 'monkey', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }

 TEST_DESCRIPTION("Many Folder test; 'file://c:/pictures/pictures1/pictures2/pictures3/pictures4/pictures5/monkey.jpeg'")
 {
  NxOgre::Path path("file://c:/pictures/pictures1/pictures2/pictures3/pictures4/pictures5/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 6, "Not six directories in path, there are " + uintToString(path.getNbDirectories()));
  
  TEST_FAIL_IF(path.getDirectory(0) != "pictures5", "Parent directory 0 is not 'pictures5', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "pictures4", "Parent directory 1 is not 'pictures4', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures3", "Parent directory 2 is not 'pictures3', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getDirectory(3) != "pictures2", "Parent directory 3 is not 'pictures2', it is " + path.getDirectory(3));
  TEST_FAIL_IF(path.getDirectory(4) != "pictures1", "Parent directory 4 is not 'pictures1', it is " + path.getDirectory(4));
  TEST_FAIL_IF(path.getDirectory(5) != "pictures", "Parent directory 5 is not 'pictures', it is " + path.getDirectory(5));
  
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Many Folder modified test; 'file://c:/pictures/pictures1/../pictures2/pictures3/pictures4/pictures5/monkey.jpeg'")
 {
  NxOgre::Path path("file://c:/pictures/pictures1/../pictures2/pictures3/pictures4/pictures5/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 5, "Not five directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures5", "Parent directory 0 is not 'pictures5', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "pictures4", "Parent directory 1 is not 'pictures4', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures3", "Parent directory 2 is not 'pictures3', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getDirectory(3) != "pictures2", "Parent directory 3 is not 'pictures2', it is " + path.getDirectory(3));
  TEST_FAIL_IF(path.getDirectory(4) != "pictures", "Parent directory 4 is not 'pictures', it is " + path.getDirectory(4));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Many Folder modified test 2; 'file://c:/pictures/pictures1/../pictures2/../pictures3/pictures4/pictures5/monkey.jpeg'")
 {  
  NxOgre::Path path("file://c:/pictures/pictures1/../pictures2/../pictures3/pictures4/pictures5/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 4, "Not four directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures5", "Parent directory 0 is not 'pictures5', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "pictures4", "Parent directory 1 is not 'pictures4', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures3", "Parent directory 2 is not 'pictures3', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getDirectory(3) != "pictures", "Parent directory 3 is not 'pictures', it is " + path.getDirectory(3));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 
 TEST_DESCRIPTION("Many Folder modified test 3; 'file://c:/pictures/pictures1/../pictures2/../pictures3/pictures4/pictures5/monkey.jpeg'")
 {  
  NxOgre::Path path("file://c:/pictures/pictures1/../pictures2/../../pictures3/pictures4/pictures5/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 3, "Not three directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures5", "Parent directory 0 is not 'pictures5', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "pictures4", "Parent directory 1 is not 'pictures4', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures3", "Parent directory 2 is not 'pictures3', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Many Folder modified test 4; 'file://c:/pictures/pictures1/../pictures2/../pictures3/pictures4/pictures5/monkey.jpeg'")
 { 
  NxOgre::Path path("file://c:/pictures/pictures1/../pictures2/../../../pictures3/pictures4/pictures5/monkey.jpeg");

  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 3, "Not three directories in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures5", "Parent directory 0 is not 'pictures5', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "pictures4", "Parent directory 1 is not 'pictures4', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures3", "Parent directory 2 is not 'pictures3', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Many Folder modified test 4; 'file://c:/../../../../pictures/../pictures1/../pictures2/monkey.jpeg'")
 { 
  NxOgre::Path path("file://c:/../../../../pictures/../pictures1/../pictures2/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getDrive() != "c", "Drive is not 'c', it is " + path.getDrive());
  TEST_FAIL_IF(path.getNbDirectories() != 1, "Not one directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures2", "Parent directory 0 is not 'pictures2', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
 
 TEST_DESCRIPTION("Relative test 1; 'file://monkey.jpeg'")
 { 
  NxOgre::Path path("file://monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getNbDirectories() != 0, "Not 0 directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
  
 TEST_DESCRIPTION("Relative test 2; 'file://../monkey.jpeg'")
 { 
  NxOgre::Path path("file://../monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getNbDirectories() != 1, "Not one directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "..", "Parent directory 0 is not '..', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
  
 TEST_DESCRIPTION("Relative test 2; 'file://../../pictures/monkey.jpeg'")
 { 
  NxOgre::Path path("file://../../pictures/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getNbDirectories() != 3, "Not three directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures", "Parent directory 0 is not 'pictures', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "..", "Parent directory 1 is not '..', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "..", "Parent directory 2 is not '..', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }
  
 TEST_DESCRIPTION("Relative test 3; 'file://../../pictures/../pictures2/monkey.jpeg'")
 { 
  NxOgre::Path path("file://../../pictures/../pictures2/monkey.jpeg");
  
  TEST_FAIL_IF(path.getProtocol() != "file", "Protocol is not 'file', it is " + path.getProtocol());
  TEST_FAIL_IF(path.getNbDirectories() != 5, "Not five directory in path, there are " + uintToString(path.getNbDirectories()));
  TEST_FAIL_IF(path.getDirectory(0) != "pictures2", "Parent directory 0 is not 'pictures', it is " + path.getDirectory(0));
  TEST_FAIL_IF(path.getDirectory(1) != "..", "Parent directory 1 is not '..', it is " + path.getDirectory(1));
  TEST_FAIL_IF(path.getDirectory(2) != "pictures", "Parent directory 2 is not '..', it is " + path.getDirectory(2));
  TEST_FAIL_IF(path.getDirectory(3) != "..", "Parent directory 3 is not '..', it is " + path.getDirectory(3));
  TEST_FAIL_IF(path.getFilenameOnly() != "monkey", "File name is not 'monkey' it is " + path.getFilenameOnly());
  TEST_FAIL_IF(path.getExtension() != "jpeg", "Extension is not 'jpeg' it is " + path.getExtension());
 }

} CASE_END

#endif
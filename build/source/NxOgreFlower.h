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

                                                                                       

#ifndef NXOGRE_FLOWER_H
#define NXOGRE_FLOWER_H


#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

                                                                                       

/*! class. Flower
    
    Collection of functions to handle Flower files.
*/
class NxOgrePublicClass Flower
{
  
 public:
  
  static void load(MeshData*, Resource*);
  
  static void save(MeshData*, Resource*);
  
  static String version();
  
 private:
  
  /** \internal DO NOT USE
  */
  Flower();
  
  /** \internal DO NOT USE
  */
 ~Flower();
  
}; // class Flower

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/*! page. Flower

h1. Flower Text File Schema

h2. Abstract

p. This document describes the file structure and allowed properties of the Flower file format for Flour.

h2. Layout

p. Each file is text based and can be edited by a normal text editor. Encoding is a non-issue as each command and property uses characters from the lower half of the standard ASCII character set. A flower file has the file extension @.flower@
 
h2. Comments

p. Comments may take up an entire line or be placed within a line. A comment is prefixed with the @#@ character. Once the @#@ character is read, the rest of the line is ignored.

p. Line and inline comments may use unicode.

h2. Multiple Meshes

More than one mesh may be stored in a flower file, each mesh and it's properties may be seperated by a triple hyphen @---@ to indicate the 
start of a new mesh. Each name of the mesh takes on the file name, a period @.@ and the number of times @---@ is encountered.

bc.. type convex
vertices -100.0,100.0,-100.0, ...

---

type triangle
vertices 1,3,4 5,6,3, 3,2,1, ...

p. Result

bc. test.0.nxs (convex), test.1.nxs (triangle)

h2. Numbers and Number Lists

p. A number can be an integer or real, and be like the following;

* 12
* -12
* 12.0
* -12
* 12E-8
* -12E-8

p. A list of numbers is seperated by a comma @,@ character, whitespace is ignored.

bc.. property 1,2,3,4,5,6,7,8,9

h2. Strings 

p. A string value may take up the entire line. The first character of the string is the first character in the value is not whitespace. The string is terminated by the last non-whitespace character in the line.

bc.. property I am a string.
property        I am a string.

h2. Flags

p. A flag is a PhysX mesh flag to change the mesh properties or the options of the cooker. Flags are strings prefixed with a @+@ character.

bc.. +16bit-indexes
+hardware

h3. List of Flags;


|_. Flag name|_. NxOgre Flag|_. Description|
|@+flip-normals@|MeshConstructionsFlags_FlipNormals|Flip the normals|
|@+16bit-indices@|MeshConstructionsFlags_16bitIndices|Use smaller 16bit indices|
|@+hardware@|MeshConstructionsFlags_HardwareMesh|Simulate the mesh on hardware|

h2. Properties

p. A property is a line that has a property name, some whitespace (tabs or spaces) then the value.

bc. property_name property_value

p. A property value may not be spanned across many lines. But some properties can be spread across many lines.

bc.. property_name property_value
property_name property_value2

p. The behavior of multiple properties is so;

* If the property accepts a range of numbers then the additional values are appended to the first, in order of lines read.
* If the property accepts a single value, then the new value replaces the previous one.

p. Depending on the mesh some properties may be ommitted.

* Vertices; Triangle, Convex, Cloth and SoftBodies
* Indexes; Triangle, Convex (Optional), Cloth and SoftBodies
* Normals; Cloth and SoftBodies
* Texture Coordinates; Cloth (Optional) and SoftBodies (Optional)
* Index Materials; Triangle (Optional)
* Vertex Flags; Cloth (Optional) and SoftBodies (Optional)
* Vertex Masses; Cloth (Optional) and SoftBodies (Optional)

h2. List of Properties 

|_. Property Name|_. Property Description|_. Property type|_. Restriction|
|type|Type of mesh|String|'convex', 'triangle', 'cloth' or 'softbody'|
|vertices|Vertices| Real list |list count must be divisible by 3|
|indices or indexes|Indices|Integer list|list count must be divisible by 3|
|normals|Vertex Normals|Real list|list count must be divisible by 3|
|texturecoords|Texture coordinates|Real list|list count must be divisible by 2|
|materials|Material indexes|Integer list|list count must be divisible by 3|
|vertexflags|Vertex flags|Integer list|list count must be vertices size|
|vertexmasses|Vertex masses|Real list|list count must be vertices size|
|weldingdistance|Welding distance for cloth/softbodies|Real|Used with the weld vertices flag|

h2. Example "cube.flower" file

bc.. # Cube
type convex
vertices -100.0,100.0,-100.0    #0
vertices 100.0,100.0,-100.0     #1
vertices 100.0,-100.0,-100.0    #2
vertices -100.0,-100.0,-100.0   #3
vertices -100.0,100.0,100.0     #4
vertices 100.0,100.0,100.0      #5
vertices 100.0,-100.0,100.0     #6
vertices -100.0,-100.0,100.0    #7

indexes 0,2,3 0,1,2, 1,6,2, 1,5,6, 4,6,5, 4,7,6, 0,7,4, 0,3,7, 0,5,1, 0,4,5, 2,7,3, 2,6,7

p. 

h2. Future

p. Future extensions to the flower file format may be the following;

* CCD Skeletons; as per development with NxOgre.

p. **Version**: 0.25, **Last modified**; 9-April-2010, **Authors:** Robin Southern

*/
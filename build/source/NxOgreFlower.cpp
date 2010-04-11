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
#include "NxOgreFlower.h"
#include "NxOgreResource.h"
#include "NxOgreMeshData.h"
#include "NxOgreResourceStream.h"

#include <iostream>

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Serialisation
{

static const String FLOWER_SCHEMA_VERSION = "0.2";
static const String FLOWER_SCHEMA_VERTICES_LIST = "vertices";
static const String FLOWER_SCHEMA_INDICES_LIST = "indices";
static const String FLOWER_SCHEMA_INDICES_LIST_ALT = "indexes";
static const String FLOWER_SCHEMA_NORMALS_LIST = "normals";
static const String FLOWER_SCHEMA_TEXTURECOORDINATES_LIST = "texturecoords";
static const String FLOWER_SCHEMA_MATERIALS_LIST = "materials";
static const String FLOWER_SCHEMA_VERTEXFLAGS_LIST = "vertexflags";
static const String FLOWER_SCHEMA_VERTEXMASSES_LIST = "vertexflags";
static const String FLOWER_SCHEMA_TYPE_PROPERTY = "type";
static const String FLOWER_SCHEMA_TYPE_VALUE_CONVEX = "convex";
static const String FLOWER_SCHEMA_TYPE_VALUE_TRIANGLE = "convex";
static const String FLOWER_SCHEMA_TYPE_VALUE_CLOTH = "cloth";
static const String FLOWER_SCHEMA_TYPE_VALUE_SOFTBODY = "softbody";
static const String FLOWER_SCHEMA_WELDINGDISTANCE_PROPERTY = "weldingdistance";
static const String FLOWER_SCHEMA_FLAG_PREFIX = "+";
static const String FLOWER_SCHEMA_FLAG_FLIPNORMALS = "flip-normals";
static const String FLOWER_SCHEMA_FLAG_16BITINDICES = "16bit-indices";
static const String FLOWER_SCHEMA_FLAG_HARDWARE = "hardware";
static const String FLOWER_SCHEMA_PROPERTY_WELDVERTICES = "weldingdistance";
static const unsigned int FLOWER_SCHEMA_VALUES_PER_LINE = 9;

void getLine(NxOgre::Resource* resource, NxOgre::Buffer<char>& buffer)
{
 buffer.clear();
 while(1)
 {
  char c = resource->readChar();
  if (resource->atEnd() || c == '\n')
   break;
  buffer.append(c);
 }
 if (buffer[buffer.size() - 1] == '\r')
  buffer[buffer.size() - 1] = 0;
 else
  buffer.append(0);
}

Flower::Flower()
{
 // Should never happen.
}

Flower::~Flower()
{
 // Should never happen.
}

void Flower::load(MeshData* mesh, Resource* resource)
{

 Buffer<char> lineBuffer;
 unsigned int line = 0;
 while(resource->atEnd() == false)
 {
  getLine(resource, lineBuffer);
  
  if (lineBuffer.size() == 1) // (0 characters + 1 byte null)
   continue;  // Skip empty lines 
  
  if (lineBuffer[0] == '#')
   continue;  // Skip full comment lines.
  
  std::string line(lineBuffer.first());
  
  Strings::slice_to_first_of(line, '#');
  Strings::trim(line);
  
  // vertices
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_VERTICES_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_VERTICES_LIST.length());
   Strings::split<float>(line, mesh->mVertices, ",");
   continue;
  }
  
  // indices
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_INDICES_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_INDICES_LIST.length());
   Strings::split<unsigned int>(line, mesh->mIndexes, ",");
   continue;
  }
  
  // indices (alternative spelling)
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_INDICES_LIST_ALT))
  {
   Strings::slice(line, FLOWER_SCHEMA_INDICES_LIST_ALT.length());
   Strings::split<unsigned int>(line, mesh->mIndexes, ",");
   continue;
  }

  // normals
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_NORMALS_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_NORMALS_LIST.length());
   Strings::split<float>(line, mesh->mNormals, ",");
   continue;
  }

  // texture coordinates
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_TEXTURECOORDINATES_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_TEXTURECOORDINATES_LIST.length());
   Strings::split<float>(line, mesh->mTextureCoordinates, ",");
   continue;
  }

  // materials
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_MATERIALS_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_MATERIALS_LIST.length());
   Strings::split<MaterialIdentifier>(line, mesh->mMaterials, ",");
   continue;
  }

  // vertexflags
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_VERTEXFLAGS_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_VERTEXFLAGS_LIST.length());
   Strings::split<unsigned int>(line, mesh->mFlags, ",");
   continue;
  }

  // vertexmasses
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_VERTEXMASSES_LIST))
  {
   Strings::slice(line, FLOWER_SCHEMA_VERTEXMASSES_LIST.length());
   Strings::split<float>(line, mesh->mMasses, ",");
   continue;
  }

  // weldingdistance
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_WELDINGDISTANCE_PROPERTY))
  {
   Strings::slice(line, FLOWER_SCHEMA_WELDINGDISTANCE_PROPERTY.length());
   mesh->mClothWeldingDistance = to_f(line);
   continue;
  }

  // type
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_TYPE_PROPERTY))
  {
   Strings::slice(line, FLOWER_SCHEMA_TYPE_PROPERTY.length());
   Strings::trim(line);
   Strings::lower(line);
   if (line.compare(FLOWER_SCHEMA_TYPE_VALUE_CONVEX) == 0)
    mesh->mType = Enums::MeshType_Convex;
   else if (line.compare(FLOWER_SCHEMA_TYPE_VALUE_TRIANGLE) == 0)
    mesh->mType = Enums::MeshType_Triangle;
   else if (line.compare(FLOWER_SCHEMA_TYPE_VALUE_CLOTH) == 0)
    mesh->mType = Enums::MeshType_Cloth;
   else if (line.compare(FLOWER_SCHEMA_TYPE_VALUE_SOFTBODY) == 0)
    mesh->mType = Enums::MeshType_SoftBody;
   continue;
  }
  
  // flags
  if (Strings::starts_insensitive(line, FLOWER_SCHEMA_FLAG_PREFIX))
  {
   Strings::slice(line, FLOWER_SCHEMA_FLAG_PREFIX.length());
   Strings::lower(line);
   if (line.compare(FLOWER_SCHEMA_FLAG_FLIPNORMALS) == 0)
    mesh->mMeshFlags |= Enums::MeshConstructionsFlags_FlipNormals;
   else if (line.compare(FLOWER_SCHEMA_FLAG_16BITINDICES) == 0)
    mesh->mMeshFlags |= Enums::MeshConstructionsFlags_16bitIndices;
   else if (line.compare(FLOWER_SCHEMA_FLAG_HARDWARE) == 0)
    mesh->mMeshFlags |= Enums::MeshConstructionsFlags_HardwareMesh;
  }

 } // while
}

void Flower::save(MeshData* mesh, Resource* resource)
{
 TextResourceStream stream(resource);
 
 // type.
 if (mesh->mType == Enums::MeshType_Convex)
  stream << FLOWER_SCHEMA_TYPE_PROPERTY << " " << FLOWER_SCHEMA_TYPE_VALUE_CONVEX << "\n";
 else if (mesh->mType == Enums::MeshType_Triangle)
  stream << FLOWER_SCHEMA_TYPE_PROPERTY << " " << FLOWER_SCHEMA_TYPE_VALUE_TRIANGLE << "\n";
 else if (mesh->mType == Enums::MeshType_Cloth)
  stream << FLOWER_SCHEMA_TYPE_PROPERTY << " " << FLOWER_SCHEMA_TYPE_VALUE_CLOTH << "\n";
 else if (mesh->mType == Enums::MeshType_SoftBody)
  stream << FLOWER_SCHEMA_TYPE_PROPERTY << " " << FLOWER_SCHEMA_TYPE_VALUE_SOFTBODY << "\n";

 if (mesh->mMeshFlags != 0)
  stream << "\n# flags\n";

 if (mesh->mMeshFlags & Enums::MeshConstructionsFlags_16bitIndices)
  stream << FLOWER_SCHEMA_FLAG_PREFIX << FLOWER_SCHEMA_FLAG_16BITINDICES << "\n";

 if (mesh->mMeshFlags & Enums::MeshConstructionsFlags_FlipNormals)
  stream << FLOWER_SCHEMA_FLAG_PREFIX << FLOWER_SCHEMA_FLAG_FLIPNORMALS << "\n";

 if (mesh->mMeshFlags & Enums::MeshConstructionsFlags_HardwareMesh)
  stream << FLOWER_SCHEMA_FLAG_PREFIX << FLOWER_SCHEMA_FLAG_HARDWARE << "\n";


 if (mesh->mClothWeldingDistance > 0)
  stream << "\n" << FLOWER_SCHEMA_WELDINGDISTANCE_PROPERTY << " " << mesh->mClothWeldingDistance << "\n";


 // vertices
 if (mesh->mVertices.size())
 {
  stream << "\n# " <<  mesh->mVertices.size() << " " << FLOWER_SCHEMA_VERTICES_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mVertices.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mVertices.size())
    b = mesh->mVertices.size();
   stream << FLOWER_SCHEMA_VERTICES_LIST << " " << Strings::join(mesh->mVertices.first() + a, mesh->mVertices.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // indexes
 if (mesh->mIndexes.size())
 {
  stream << "\n# " <<  mesh->mIndexes.size() << " " << FLOWER_SCHEMA_INDICES_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mIndexes.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mIndexes.size())
    b = mesh->mIndexes.size();
   stream << FLOWER_SCHEMA_INDICES_LIST << " " << Strings::join(mesh->mIndexes.first() + a, mesh->mIndexes.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // normals
 if (mesh->mNormals.size())
 {
  stream << "\n# " <<  mesh->mNormals.size() << " " << FLOWER_SCHEMA_NORMALS_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mNormals.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mNormals.size())
    b = mesh->mNormals.size();
   stream << FLOWER_SCHEMA_NORMALS_LIST << " " << Strings::join(mesh->mNormals.first() + a, mesh->mNormals.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // texture coordinates
 if (mesh->mTextureCoordinates.size())
 {
  stream << "\n# " <<  mesh->mTextureCoordinates.size() << " " << FLOWER_SCHEMA_TEXTURECOORDINATES_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mTextureCoordinates.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mTextureCoordinates.size())
    b = mesh->mTextureCoordinates.size();
   stream << FLOWER_SCHEMA_TEXTURECOORDINATES_LIST << " " << Strings::join(mesh->mTextureCoordinates.first() + a, mesh->mTextureCoordinates.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // materials
 if (mesh->mMaterials.size())
 {
  stream << "\n# " <<  mesh->mMaterials.size() << " " << FLOWER_SCHEMA_MATERIALS_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mMaterials.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mMaterials.size())
    b = mesh->mMaterials.size();
   stream << FLOWER_SCHEMA_MATERIALS_LIST << " " << Strings::join(mesh->mMaterials.first() + a, mesh->mMaterials.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // vertex flags
 if (mesh->mFlags.size())
 {
  stream << "\n# " <<  mesh->mFlags.size() << " " << FLOWER_SCHEMA_VERTEXFLAGS_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mFlags.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mFlags.size())
    b = mesh->mFlags.size();
   stream << FLOWER_SCHEMA_VERTEXFLAGS_LIST << " " << Strings::join(mesh->mFlags.first() + a, mesh->mFlags.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }

 // vertex masses
 if (mesh->mFlags.size())
 {
  stream << "\n# " <<  mesh->mMasses.size() << " " << FLOWER_SCHEMA_VERTEXMASSES_LIST << "\n";
  unsigned int a = 0, b = 0;
  while(a < mesh->mMasses.size())
  {
   b = a + FLOWER_SCHEMA_VALUES_PER_LINE;
   if (b > mesh->mMasses.size())
    b = mesh->mMasses.size();
   stream << FLOWER_SCHEMA_VERTEXMASSES_LIST << " " << Strings::join(mesh->mMasses.first() + a, mesh->mMasses.first() + b, ", ") << "\n";
   a += FLOWER_SCHEMA_VALUES_PER_LINE;
  }
 }


}

String Flower::version()
{
 return FLOWER_SCHEMA_VERSION;
}

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

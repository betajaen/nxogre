/**

    This file is part of NxOgre.

    Copyright (c) 2009 Robin Southern, http://www.nxogre.org

    Permission is hereby granted, free of charge, to Value person obtaining a copy
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
#include "NxOgreCommon.h"
#include "NxOgreFlatYAML.h"
#include "NxOgreResource.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreResourceStream.h"
#include "NxOgreValue.h"
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

static const String YAML_HEADER = "---\n# FlatYAML, NxOgre.org\n";
static const String YAML_TYPE_VEC3 = "!!nxogre/vec3";
static const String YAML_TYPE_QUAT = "!!nxogre/quat";

namespace Serialisation
{


FlatYAML::FlatYAML()
{
 // Should never happen.
}

FlatYAML::~FlatYAML()
{
 // Should never happen.
}

void FlatYAML::load(const Path& path, StringValueList& ret )
{
 Resource* resource = NxOgre::ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_ReadOnly);
 FlatYAML::load(resource, ret);
 NxOgre::ResourceSystem::getSingleton()->close(resource);
}

void FlatYAML::load(Resource* resource, StringValueList& ret )
{
 
 buffer<char> lineBuffer;
 std::pair<std::string, std::string> pair;
 bool didCut = false;
 
 while(resource->atEnd() == false)
 {
  NxOgre::Strings::getLine(resource, lineBuffer);
  
  if (lineBuffer.size() == 1) // (0 characters + 1 byte null)
   continue;  // Skip empty lines 
  
  if (lineBuffer[0] == '#')
   continue;  // Skip full comment lines.
  
  pair = Strings::cut(lineBuffer.first(), didCut);
  
  if (didCut)
  {
   
   if (Strings::starts(pair.second, YAML_TYPE_VEC3))
    Strings::slice(pair.second, YAML_TYPE_VEC3.length());
   else if (Strings::starts(pair.second, YAML_TYPE_QUAT))
    Strings::slice(pair.second, YAML_TYPE_QUAT.length());
   
   Strings::trim(pair.second);
   
   Value value = Value::from_s(pair.second);
   NxOgre_DebugPrint_FlatYAML("Read in key/pair.\n\t { key => '" << pair.first << "', value => '" << value.to_s() << "', type => '" << value.type_str() << "' }");
   ret.insert(pair.first, value);
  }
 } // while
 
}

void FlatYAML::save(const Path& path, const StringValueList& property_list)
{
 Resource* resource = NxOgre::ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_WriteOnly);
 FlatYAML::save(resource, property_list);
 NxOgre::ResourceSystem::getSingleton()->close(resource);
}

void FlatYAML::save(Resource* resource, const StringValueList& property_list)
{
 
 TextResourceStream stream(resource);
 stream << YAML_HEADER;
 
 for(StringValuePairIterator it = property_list.elements(); it != it.end(); it++)
 {
  if ((*it).isVec3())
   stream << it.key() << ": " << YAML_TYPE_VEC3 << " " << (*it).to_s() << "\n";
  else if ((*it).isQuat())
   stream << it.key() << ": " << YAML_TYPE_QUAT << " " << (*it).to_s() << "\n";
  else
   stream << it.key() << ": " << (*it).to_s() << "\n";
 }
 
}

                                                                                       

} // namespace Serialisation

                                                                                       

} // namespace NxOgre

                                                                                       

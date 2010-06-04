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
#include "NxOgreHeightField.h"
#include "NxOgreResourceSystem.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreManualHeightField.h"
#include "NxOgreHeightFieldData.h"
#include "NxOgreNXS.h"
#include "NxOgreX.h"


#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightField::HeightField()
{
 mHeightField = 0;
}

HeightField::HeightField(Resource* resource)
{
 mHeightField = 0;
 load(resource);
}

HeightField::HeightField(NxHeightField* heightfield)
: mHeightField(heightfield)
{
}

HeightField::~HeightField()
{
 unload();
}

bool HeightField::isLoaded() const
{
 return mHeightField != NULL;
}

bool HeightField::isUsed() const
{
 
 if (mHeightField)
 {
  return mHeightField->getReferenceCount() != 0;
 }
 
 return false;
}

void HeightField::load(Resource* resource)
{
 
 unload();
 
 if (Serialisation::X::isXFile(resource))
 {
  
  Enums::XType type = Serialisation::X::getXType(resource);
  
  if (type != Enums::XType_HeightField)
  {
   StringStream stream;
   stream << "Resource '" << resource->getPath().getString() << " is not a valid NxOgre X HeightField file.\n"
          << "Reason: Un-reconised header";
   NxOgre_ThrowException(IOException, stream.str(), Classes::_HeightField);
   return;
  }
  
  resource->seekBeginning();
  
  NxOgre_DebugPrint_HeightFields("Loading x heightfield from heightfield");
  mHeightField = Serialisation::X::loadHeightField(resource);
  
  return;
 }
 else
 {
  
  StringStream stream;
  stream << "Resource '" << resource->getPath().getString() << " is not a NxOgre X heightfield file.";
  NxOgre_ThrowException(IOException, stream.str(), Classes::_HeightField);
  return;
  
 }
  
}

unsigned int HeightField::getNbRows() const
{
 return mHeightField->getNbRows();
}

unsigned int HeightField::getNbColumns() const
{
 return mHeightField->getNbColumns();
}

void HeightField::unload()
{
 
 if (mHeightField)
 {
  NxPhysicsSDK* sdk = NxGetPhysicsSDK();
  sdk->releaseHeightField(*mHeightField);
 }
 
 mName = BLANK_STRING;
 mNameHash = BLANK_HASH;
 
}

NxHeightField* HeightField::getHeightField()
{
 return mHeightField;
}

void HeightField::setName(const char* name)
{
 setName(String(name));
}

void HeightField::setName(const String& name)
{
 mName = name;
 mNameHash = Strings::hash(name);
}

String HeightField::getName() const
{
 return mName;
}

StringHash HeightField::getNameHash() const
{
 return mNameHash;
}

HeightFieldData* HeightField::getHeightFieldData()
{
 
 HeightFieldData* data = GC::safe_new0<HeightFieldData>(NXOGRE_GC_THIS);
 Serialisation::X::saveHeightField(mHeightField, data);
 return data;
 
}

String HeightField::inspect() const
{
 std::ostringstream s;
 s << "{ 'name' => '" << getName() << "' }";
 return s.str();
}



                                                                                       

} // namespace NxOgre

                                                                                       

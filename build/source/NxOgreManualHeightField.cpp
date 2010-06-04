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
#include "NxOgreManualHeightField.h"
#include "NxOgreHeightField.h"
#include "NxOgreHeightFieldData.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreHeightFieldManager.h"
#include "NxOgreFunctions.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ManualHeightField::ManualHeightField()
: mHeightField(GC::safe_new0<HeightFieldData>(NXOGRE_GC_THIS))
{
}

ManualHeightField::ManualHeightField(const ManualHeightField& other)
: mHeightField(other.mHeightField)
{
}

ManualHeightField::ManualHeightField(HeightFieldData* data)
: mHeightField(data)
{
}

ManualHeightField::~ManualHeightField()
{
}

ManualHeightField& ManualHeightField::operator=(ManualHeightField& other)
{
 mHeightField = other.mHeightField;
 return *this;
}

void ManualHeightField::begin(unsigned int nbRows, unsigned int nbColumns)
{
 
 if (nbColumns == 0)
 {
  NxOgre_ThrowException(DescriptionInvalidException, "Column count must be more than 0", Classes::_ManualHeightField);
  return;
 }
 
 if (nbRows == 0)
 {
  NxOgre_ThrowException(DescriptionInvalidException, "Row count must be more than 0", Classes::_ManualHeightField);
  return;
 }
 
 mHeightField->clear();
 mHeightField->mNbRows = nbRows;
 mHeightField->mNbColumns = nbColumns;
 mHeightField->mSamples.resize(mHeightField->mNbRows * mHeightField->mNbColumns);
 
}

void ManualHeightField::clean()
{
 mHeightField->clear();
}

void ManualHeightField::name(const String& name)
{
 mHeightField->mName = name;
}

void ManualHeightField::name(const char* name)
{
 mHeightField->mName = name;
}

String ManualHeightField::name() const
{
 return mHeightField->mName;
}

void ManualHeightField::acquire(HeightFieldData* data)
{
 mHeightField = SharedPointer<HeightFieldData>(data);
}

void ManualHeightField::sample(HeightFieldSample sample)
{
 mHeightField->mSamples.push_back(sample);
}

void ManualHeightField::sample(short height, MaterialIdentifier mat0, MaterialIdentifier mat1, Enums::HeightFieldTesselation tesselation)
{
 HeightFieldSample sample;
 sample.mHeight = height;
 sample.mMaterial0 = mat0;
 sample.mMaterial1 = mat1;
 sample.mTessellationFlag = tesselation;
 mHeightField->mSamples.push_back(sample);
}

bool ManualHeightField::isValid() const
{ // NOTE: Incomplete function
 return true;
}

HeightField* ManualHeightField::end(bool cleanUp, const Path& cookingTarget)
{
 
 NxOgre_DebugPrint_HeightFields("ManualHeightField -- end");
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_ReadAndWrite);
 
 NxOgre_DebugPrint_HeightFields("Attempting to cook to resource");
 mHeightField->cook(cookingResource);
 
 NxOgre_DebugPrint_HeightFields("Attempting to read heightfield.");
 cookingResource->seekBeginning();

 HeightField* hf = 0;
 
 if (mHeightField->mName.length() == 0)
 {
  NxOgre_DebugPrint_HeightFields("load via CookingResource");
  hf = HeightFieldManager::getSingleton()->load(cookingResource);
 }
 else
 {
  NxOgre_DebugPrint_HeightFields("load via CookingResource under the name " << mHeightField->mName);
  hf = HeightFieldManager::getSingleton()->load(cookingResource, mHeightField->mName);
 }
 if (cookingResource->getStatus() == Enums::ResourceStatus_Opened)
  ResourceSystem::getSingleton()->close(cookingResource);
 
 if (cleanUp)
  clean();
 
 return hf;
}

void ManualHeightField::endCookOnly(bool cleanUp, const Path& cookingTarget)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(cookingTarget, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 mHeightField->cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
 if (cleanUp)
  clean();
 
}

                                                                                       

} // namespace NxOgre

                                                                                       

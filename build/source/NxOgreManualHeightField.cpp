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
#include "NxOgreHeightFieldSample.h"
#include "NxOgreHeightField.h"
#include "NxOgreHeightFieldManager.h"
#include "NxOgreReason.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldData::HeightFieldData()
 : mNbRows(0),
   mNbColumns(0),
   mAxis(Enums::Y),
   mThickness(0.0f),
   mVerticalExtent(0.0f),
   mConvexEdgeThreshold(0.0f),
   mNoEdgeBoundaries(false)
{
}

HeightFieldData::~HeightFieldData()
{
}

ManualHeightField::ManualHeightField(void)
{
 mHeightField = new HeightFieldData();
 mRef = (RefT*) NXOGRE_ALLOCATE(FourByteAllocator, (sizeof(RefT)));
 (*mRef) = 1;
}

ManualHeightField::~ManualHeightField(void)
{
 if(--(*mRef) == 0)
 {
  NXOGRE_DEALLOCATE(FourByteAllocator, mRef);
  delete mHeightField;
 }
}

ManualHeightField& ManualHeightField::operator=(ManualHeightField& other)
{
 if(--(*mRef) == 0)
 {
  NXOGRE_DEALLOCATE(FourByteAllocator, mRef);
  delete mHeightField;
 }
 mHeightField   = other.mHeightField;
 mRef           = other.mRef;
 (*mRef)++;
 return *this;
}

void ManualHeightField::begin(unsigned int nbColumns, unsigned int nbRows, Enums::Axis upAxis)
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
 
 mHeightField->mAxis = upAxis;
 mHeightField->mNbRows = nbRows;
 mHeightField->mNbColumns = nbColumns;
 mHeightField->mSamples.removeAll();
}

void ManualHeightField::name(const char* name)
{
 mHeightField->mName = name;
}

String ManualHeightField::name(void) const
{
 return mHeightField->mName;
}

HeightField* ManualHeightField::end(const String& name)
{
 HeightField* hf = new HeightField(name, cook());
 StringHash hashed_name = Strings::hash(name);
 HeightFieldManager::getSingleton()->mHeightFields.insert(hashed_name, hf);
 return hf;
}

NxHeightField* ManualHeightField::cook(void)
{
 
 NxHeightField* heightfield = 0;
 NxHeightFieldDesc description;
 
 description.setToDefault();
 description.nbRows = mHeightField->mNbRows;
 description.nbColumns = mHeightField->mNbColumns;
 description.samples = mHeightField->mSamples.ptr();
 description.format = NX_HF_S16_TM;
 description.thickness = mHeightField->mThickness;
 description.verticalExtent = mHeightField->mVerticalExtent;
 description.flags = 0;
 description.convexEdgeThreshold = mHeightField->mConvexEdgeThreshold;
 description.format = NX_HF_S16_TM;
 description.sampleStride = sizeof(unsigned int);
 description.flags = 0;
 
 if (description.isValid() == false)
 {
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(description), Classes::_ManualHeightField);
  return 0;
 }
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 heightfield = sdk->createHeightField(description);
 
 return heightfield;
}

bool ManualHeightField::isValid(void)
{
 if (mHeightField == 0)
  return false;
 if (mHeightField->mNbRows == 0)
  return false;
 if (mHeightField->mNbColumns == 0)
  return false;
 if (mHeightField->mSamples.size() == 0)
  return false;
 if (mHeightField->mSamples.size() != (mHeightField->mNbRows * mHeightField->mNbColumns))
  return false;
 return true;
}

void ManualHeightField::setVerticalExtent(Real v)
{
 mHeightField->mVerticalExtent = v;
}

Real ManualHeightField::getVerticalExtent(void)
{
 return mHeightField->mVerticalExtent;
}

void ManualHeightField::setConvexEdgeThreshold(Real v)
{
 mHeightField->mConvexEdgeThreshold = v;
}

Real ManualHeightField::getConvexEdgeThreshold(void) const
{
 return mHeightField->mConvexEdgeThreshold;
}

void ManualHeightField::setHasNoBoundaryEdges(bool v)
{
 mHeightField->mNoEdgeBoundaries = v;
}

bool ManualHeightField::getHasNoBoundaryEdges(void) const
{
 return mHeightField->mNoEdgeBoundaries;
}

void ManualHeightField::sample(HeightFieldSample sample)
{
 mHeightField->mSamples.insert(sample);
}

void ManualHeightField::sample(short height, MaterialIdentifier mat0, MaterialIdentifier mat1, Enums::HeightFieldTesselation tesselation)
{
 HeightFieldSample sample;
 sample.mHeight = height;
 sample.mMaterial0 = mat0;
 sample.mMaterial1 = mat1;
 sample.mTessellationFlag = tesselation;
 mHeightField->mSamples.insert(sample);
}

                                                                                       

} // namespace NxOgre

                                                                                       

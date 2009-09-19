/** File: NxOgreManualHeightField.cpp
    Created on: 22-Mar-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
 mRef = (RefT*) NxOgre_Allocate(sizeof(RefT), ::NxOgre::Classes::_ManualHeightFieldReferenceCounter);
 (*mRef) = 1;
}

ManualHeightField::~ManualHeightField(void)
{
 if(--(*mRef) == 0)
 {
  ::NxOgre::Memory::unallocate(mRef);
  delete mHeightField;
 }
}

ManualHeightField& ManualHeightField::operator=(ManualHeightField& other)
{
 if(--(*mRef) == 0)
 {
  ::NxOgre::Memory::unallocate(mRef);
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
  NxOgre_ThrowError("Column count must be more than 0");
  return;
 }
 
 if (nbRows == 0)
 {
  NxOgre_ThrowError("Row count must be more than 0");
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
 HeightFieldManager::getSingleton()->mLoadedHeightFields.insert(hf);
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
  SharedStringStream message(SharedStringStream::_LARGE); 
  message << "An error occured creating the NxHeightFieldDesc.\nThe reason(s) and cause(s) could be:\n\n" << Reason::whyAsStream(description);
  NxOgre_ThrowError(message.get());
  
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

                                                                                       

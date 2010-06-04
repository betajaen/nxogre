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
#include "NxOgreHeightFieldData.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreX.h"
#include "NxOgreHeightField.h"
#include "NxOgreHeightFieldManager.h"
#include "NxOgreReason.h"
#include "NxOgreWorld.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

HeightFieldData::HeightFieldData() :
 mNbRows(0),
 mNbColumns(0),
 mThickness(0),
 mVerticalExtent(0),
 mConvexEdgeThreshold(0),
 mNoEdgeBoundaries(false)
{
}

HeightFieldData::~HeightFieldData()
{
}

void HeightFieldData::clear()
{
 mName.clear();
 mSamples.remove_all();
 mNbRows = 0;
 mNbColumns = 0;
 mThickness = 0;
 mVerticalExtent = 0;
 mConvexEdgeThreshold = 0;
 mNoEdgeBoundaries = false;
}

void HeightFieldData::cook(Resource* resource)
{
 NxOgre_DebugPrint_Cooking("[HeightFieldData] Attempting to cook to resource");
 Serialisation::X::saveHeightField(resource, this);
}

void HeightFieldData::cook(const NxOgre::Path& path)
{
 
 Resource* cookingResource = ResourceSystem::getSingleton()->open(path, NxOgre::Enums::ResourceAccess_WriteOnly);
 
 cook(cookingResource);
 
 ResourceSystem::getSingleton()->close(cookingResource);
 
}

HeightField* HeightFieldData::cookQuickly()
{
 
 NxHeightFieldDesc desc;
 desc.nbColumns = mNbColumns;
 desc.nbRows = mNbRows;
 desc.samples = mSamples.first();
 desc.sampleStride = sizeof(HeightFieldSample);
 desc.convexEdgeThreshold = mConvexEdgeThreshold;
 desc.thickness = mThickness;
 desc.verticalExtent = mVerticalExtent;
 
 if (mNoEdgeBoundaries == false)
  desc.flags |= NX_HF_NO_BOUNDARY_EDGES;
 
 if (desc.isValid() == false)
 {
   NxOgre_ThrowException(DescriptionInvalidException, "Cannot cook HeightField. Reason(s) are: " + Reason::Exceptionise(desc) , Classes::_RigidBody);
 }
 
 NxPhysicsSDK* sdk = World::getSingleton()->getPhysXSDK();
 NxHeightField* nxhf = sdk->createHeightField(desc);
 HeightField* hf = GC::safe_new1<HeightField>(nxhf, NXOGRE_GC_THIS);
 NxOgre::HeightFieldManager::getSingleton()->load(hf, mName);
 return hf;
}

                                                                                       

} // namespace NxOgre

                                                                                       

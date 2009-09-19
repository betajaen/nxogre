/** File: NxOgreHeightField.cpp
    Created on: 16-Jan-09
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
#include "NxOgreHeightField.h"
#include "NxOgreResourceSystem.h"
#include "NxOgrePhysXStream.h"
#include "NxOgreXFunctions.h"
#include "NxOgreManualHeightField.h"
#include "NxOgrePhysXUserEntityReport.h"

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

HeightField::HeightField(const String& name, NxHeightField* hf)
 : mName(name),
   mHeightField(hf)
{
}

HeightField::~HeightField(void)
{
 if (mHeightField == 0)
  return;
 
 NxPhysicsSDK* sdk = NxGetPhysicsSDK();
 sdk->releaseHeightField(*mHeightField);
}


bool HeightField::isLoaded(void) const
{
 return mHeightField != 0;
}

bool HeightField::isUsed(void) const
{
 return (mHeightField && mHeightField->getReferenceCount() != 0);
}

void HeightField::load(Resource* resource)
{
 if (!Functions::XFunctions::isX(resource))
 {
  SharedStringStream ss;
  ss << "Error: " << resource->getArchiveResourceIdentifier().getArchive() << ":" << resource->getArchiveResourceIdentifier().getResourceName() << " is not a NxOgre file. Reasons(s) are:\n";
  ss << Functions::XFunctions::whyIsNotX(resource);
  NxOgre_ThrowError(ss.get());
  return;
 }

 if (!Functions::XFunctions::getXType(resource) == Enums::XType_HeightField)
 {
  SharedStringStream ss;
  ss << "Error: " << resource->getArchiveResourceIdentifier().getArchive() << ":" << resource->getArchiveResourceIdentifier().getResourceName() << " is not a NxOgre heightfield file\n";
  ss << Functions::XFunctions::whyIsNotX(resource);
  NxOgre_ThrowError(ss.get());
  return;
 }

 resource->seekBeginning();
 resource->seek(8);

 // hasMaterialAlias (Currently not implemented)
 bool hasMaterialAlias = resource->readBool();

 // nbRows (Number of Rows)
 unsigned short nbRows = resource->readShort();

 // nbColumns (Number of Columns)
 unsigned short nbColumns = resource->readShort();

 unsigned int wh = nbRows * nbColumns;
 
 ManualHeightField heightfield;
 heightfield.begin(nbColumns, nbRows);
 for (unsigned int i=0; i < wh; i++)
 {
  HeightFieldSample sample;
  resource->readCharArray( (char*) &sample, sizeof(NxHeightFieldSample));
  heightfield.sample(sample);
 }
 
 mHeightField = heightfield.cook();
}

void HeightField::setName(const char* name)
{
 mName = name;
}

void HeightField::setName(const String& name)
{
 mName = name;
}

String HeightField::getName() const
{
 return mName;
}

NxHeightField* HeightField::getHeightField(void)
{
 return mHeightField;
}


                                                                                       

} // namespace NxOgre

                                                                                       

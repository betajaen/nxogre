/** File: NxOgreXFunctions.cpp
    Created on: 18-Mar-09
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
#include "NxOgreXFunctions.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace XFunctions
{

                                                                                       

extern inline bool isX(Resource* resource)
{
 
 // False on a resource that isn't opened.
 if (resource->getStatus() != ::NxOgre::Enums::ResourceStatus_Opened)
  return false;

 // False on a resource that cannot be read.
 if (resource->getAccess() > ::NxOgre::Enums::ResourceAccess_ReadAndWrite)
  return false;

 // False on a resource that cannot be used at omidirectionally.
 if (resource->getDirectionality() != ::NxOgre::Enums::ResourceDirectionality_Omidirectional)
  return false;

 
 // False on a resource size less than eight bytes.
 if (resource->getSize() < 8)
  return false;
 
 // False on the resource not having 'N', 'x', 'O', '*' as the first four bytes of the file.
 {
  char header[4] = {0, 0, 0, 0};
  resource->seekBeginning();
  resource->readCharArray(header, 4);
  if ( (header[0] == 'N' && header[1] == 'x' && header[2] == 'O' && header[3] == '*') == false)
   return false;
 
 }
 
 // False on the resource not having an unknown mesh type; according to PhysX 2.8.1, 17-Jan-2009
 {
  char meshType[4] = {0, 0, 0, 0};
  resource->seekBeginning();
  resource->seek(4);
  resource->readCharArray(meshType, 4);
  
  // HeightField
  if ( (meshType[0] == 'H' || meshType[1] == 'T' || meshType[2] == 'F' || meshType[3] == 'D')  )
   return true;
  
  // Skeleton
  if ( (meshType[0] == 'S' || meshType[1] == 'K' || meshType[2] == 'E' || meshType[3] == 'L')  )
   return true;

 }
 
 return false;
}

extern inline SharedStringStream whyIsNotX(Resource* resource)
{
 SharedStringStream stream;

 // False on a resource that isn't opened.
 if (resource->getStatus() != ::NxOgre::Enums::ResourceStatus_Opened)
  stream << " - Resource is not opened.\n";

 // False on a resource that cannot be read.
 if (resource->getAccess() > ::NxOgre::Enums::ResourceAccess_ReadAndWrite)
  stream << " - Resource access cannot be read.\n";

 // False on a resource that cannot be used at omidirectionally.
 if (resource->getDirectionality() != ::NxOgre::Enums::ResourceDirectionality_Omidirectional)
  stream << " - Resource directionality omidirectional.\n";

 
 // False on a resource size less than eight bytes.
 if (resource->getSize() < 8)
  stream << " - Resource size is less than eight bytes.\n";
 
 // False on the resource not having 'N', 'x', 'O', '*' as the first four bytes of the file.
 {
  char header[4] = {0, 0, 0, 0};
  resource->seekBeginning();
  resource->readCharArray(header, 4);
  if ( (header[0] == 'N' && header[1] == 'x' && header[2] == 'O' && header[3] == '*') == false)
   stream << " - Resource header is not valid. Header is '" << header[0] << header[1] << header[2] << header[3] << "'\n";
 
 }
 
 bool b = true;
 // False on the resource not having an unknown mesh type; according to PhysX 2.8.1, 17-Jan-2009
 {
  char meshType[4] = {0, 0, 0, 0};
  resource->seekBeginning();
  resource->seek(4);
  resource->readCharArray(meshType, 4);
  
  // HeightField
  if ( (meshType[0] == 'H' || meshType[1] == 'T' || meshType[2] == 'F' || meshType[3] == 'D')  )
   b = false;
  
  // Skeleton
  if ( (meshType[0] == 'S' || meshType[1] == 'K' || meshType[2] == 'E' || meshType[3] == 'L')  )
   b = false;
 }

 if (b == false)
  stream << " - Resource file does not have a correct file-type header.\n";
 
 return stream;
}

extern inline Enums::XType getXType(Resource* resource)
{
 char meshType[4] = {0, 0, 0, 0};
 resource->seekBeginning();
 resource->seek(4);
 resource->readCharArray(meshType, 4);
 
 // HeightField
 if ( (meshType[0] == 'H' || meshType[1] == 'T' || meshType[2] == 'F' || meshType[3] == 'D')  )
  return Enums::XType_HeightField;
 
 // NxTriangleMesh
 if ( (meshType[0] == 'S' || meshType[1] == 'K' || meshType[2] == 'E' || meshType[3] == 'L')  )
  return Enums::XType_Skeleton;
 
 return Enums::XType_Unknown;
}


                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

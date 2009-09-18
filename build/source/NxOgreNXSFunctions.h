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

                                                                                       

#ifndef NXOGRE_NXSFUNCTIONS_H
#define NXOGRE_NXSFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace NXSFunctions
{

                                                                                       

/** \brief Is the resource a PhysX NXS file.
    \note Resource cannot be sucessional.
*/
inline bool isNXS(Resource*);

/** \brief Get the type of resource or Enums::MeshType_Unknown of a PhysX NXS file.
    \note Resource cannot be sucessional, it is assumed that the mesh has been run through the isNXS function.
*/
inline Enums::MeshType getMeshType(Resource*);

/// /** \brief Does the PhysX NXS file have NxOgre extended data attached to it?
///     \note Resource cannot be sucessional.
/// */
/// inline bool hasExtendedMeshData(Resource*);
/// 
/// /** \brief Get the extended data from a NXS file.
///     \note Resource cannot be sucessional.
/// */
/// inline void* getExtendedMeshData(Resource*, size_t& dataLength);

                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

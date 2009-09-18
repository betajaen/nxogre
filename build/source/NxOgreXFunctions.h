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

                                                                                       

#ifndef NXOGRE_XFUNCTIONS_H
#define NXOGRE_XFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace XFunctions
{

                                                                                       

/** \brief Is the resource a NxOgre X-file.
    \note Resource cannot be sucessional.
*/
inline bool isX(Resource*);


/** \brief Is the resource a NxOgre X-file.
    \note Resource cannot be sucessional.
*/
inline SharedStringStream whyIsNotX(Resource*);


/** \brief Get the type of resource or Enums::MeshType_Unknown of a NxOgre X-file.
    \note Resource cannot be sucessional, it is assumed that the mesh has been run through the isNXS function.
*/
inline Enums::XType getXType(Resource*);

                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

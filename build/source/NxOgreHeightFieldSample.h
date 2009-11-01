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

                                                                                       

#ifndef NXOGRE_HEIGHTFIELDSAMPLE_H
#define NXOGRE_HEIGHTFIELDSAMPLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief HeightFieldSample, compatible with NxHeightFieldSample.
*/
struct NxOgrePublicClass HeightFieldSample
{
  
   HeightFieldSample() {}
  ~HeightFieldSample() {}
  
  /** \brief Height of the heightfield sample, when applied to a terrain it is multiplied by the heightfield scale.
  */
  short mHeight : 16;
  
  /** \brief The low 7 bits of the material of a triangle index.
  */
  unsigned char mMaterial0 : 7;
  
  /** \brief Tesselation flag.
  */
  unsigned char mTessellationFlag : 1;

  /** \brief The upper 7 bits of the material of a triangle index.
  */
  unsigned char mMaterial1 : 7;
  
  /** \brief Reserved/Unused.
  */
  unsigned char mUnused : 1;
  
}; // class HeightFieldSample

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif

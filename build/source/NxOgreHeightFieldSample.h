/** File: NxOgreHeightFieldSample.h
    Created on: 19-Mar-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

    (c) Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

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

NxOgre_CompileAssertion(sizeof(HeightFieldSample) == 4, HeightFieldSampleMustBe4Bytes);

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif

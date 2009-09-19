/** File: NxOgreRestingParticle.h
    Created on: 17-Feb-09
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

#ifndef NXOGRE_RESTINGPARTICLE_H
#define NXOGRE_RESTINGPARTICLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A Resting particle is pretty much a 4x4 matrix that can be directly given to a renderable if needed, however
           the scale portions are replaced by userdata and a lifetime. For any renderable that uses the scale, you should
           treat them as 1.
*/
union NxOgrePublicClass RestingParticle
{
  float Matrix[16];
  struct
  {
   float _01_Internal;
   float _02_Internal;
   float _03_Internal;
   float _04_Internal;
   float _05_Internal;
   float _06_Internal;
   float _07_Internal;
   float _08_Internal;
   float _09_Internal;
   float _10_Internal;
   float _11_Internal;
   float _12_Internal;
   float _13_Lifespan;
   float _14_User1;
   float _15_User2;
   float _16_Internal;
  } Decompiled;

}; // class RestingParticle

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

/** File: NxOgreVec.h
    Created on: 14-May-09
    Author: Robin Southern "betajaen"
    SVN: $Id$

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

#ifndef NXOGRE_REAL_VECTORS_H
#define NXOGRE_REAL_VECTORS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMath.h"
#include "bml/bml.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       


#if (NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat)

typedef bml::Vector2<float>          Vec2;
typedef bml::Vector3<float>          Vec3;
typedef bml::Vector4<float>          Vec4;
typedef bml::QuaternionT<float>      Quat;

#else

typedef bml::Vector2<double>         Vec2;
typedef bml::Vector3<double>         Vec3;
typedef bml::Vector4<double>         Vec4;
typedef bml::QuaternionT<double>     Quat;

#endif

typedef bml::Vector2<double>         DoubleVec2;
typedef bml::Vector3<double>         DoubleVec3;
typedef bml::Vector4<double>         DoubleVec4;
typedef bml::QuaternionT<double>     DoubleQuat;

typedef bml::BoundsT<Vec2>           Bounds2;
typedef bml::BoundsT<Vec3>           Bounds3;
typedef bml::BoundsT<Vec4>           Bounds4;
typedef bml::BoundsT<DoubleVec2>     DoubleBounds2;
typedef bml::BoundsT<DoubleVec3>     DoubleBounds3;
typedef bml::BoundsT<DoubleVec4>     DoubleBounds4;

typedef Vec2                         Real2; //\warning Deprecated, use Vec2
typedef Vec3                         Real3; //\warning Deprecated, use Vec3
typedef Vec4                         Real4; //\warning Deprecated, use Vec4




                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif

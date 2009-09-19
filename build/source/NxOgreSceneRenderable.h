/** File: NxOgreXXX.h
    Created on: X-XXX-XX
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

#ifndef NXOGRE_SCENERENDERABLE_H
#define NXOGRE_SCENERENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief 28 byte struct containing 
*/
struct NxOgrePublicClass SceneRenderable
{
 Vec3 mAlphaPosition;
 Vec4 mAlphaQuaternion;
};

/** \brief A 32 byte struct to hold the last position of a RigidBody and the RigidBody itself. It is packed this way for
           memory reasons.
*/
struct NxOgrePublicClass RigidBodyRenderable : public SceneRenderable
{
 RigidBody* mRigidBody;        // This is the RigidBody.
};

                                                                                       

namespace Functions
{

                                                                                       

#if 0
inline Matrix44 RigidBodyRenderableToMatrix44(RigidBodyRenderable& r)
{
 Matrix44 m;
 Memory::copy(&m.m.m, &r.mAlphaPosition, 15 * sizeof(Real));
 m.m.s._44 = Real(1.0);
 return m;
}

inline RigidBodyRenderable Matrix44ToRigidBodyRenderable(const Matrix44& m)
{
 RigidBodyRenderable r;
 Memory::copy(&r.mAlpha, &m.m.m, 15 * sizeof(Real));
 return r;
}

inline void interpolateRigidBodyRenderable(const TimeStep& ts, RigidBodyRenderable& r);
#endif

                                                                                       

}

                                                                                       

NxOgre_CompileAssertion(sizeof(Real) == sizeof(RigidBody*), "Real and RigidBody must be the same size");
NxOgre_CompileAssertion(sizeof(RigidBodyRenderable) == 32, "RigidBodyRenderable must be 32 bytes");

                                                                                       

} // namespace NxOgre

                                                                                       

#endif

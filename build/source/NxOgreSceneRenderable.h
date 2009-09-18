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

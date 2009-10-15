/** File: OGRE3DPointRenderable.h
    Created on: 18-May-09
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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

#ifndef OGRE3D_PARTICLERENDERABLE_H
#define OGRE3D_PARTICLERENDERABLE_H

                                                                                       

#include "NxOgre.h"
#include "OGRE3DCommon.h"
#include <OgreSimpleRenderable.h>

                                                                                       

/** \brief A OGRE3D RenderSystem implementation of the PointRenderable class.
*/
class OGRE3DExportClass OGRE3DParticleRenderable : public NxOgre::PointerClass<_OGRE3DParticleRenderable>, public NxOgre::Renderable
{
  
  friend class OGRE3DRenderSystem;
  
  public:
  
   using ::NxOgre::PointerClass<_OGRE3DParticleRenderable>::operator new;
   
   using ::NxOgre::PointerClass<_OGRE3DParticleRenderable>::operator delete;
    
     
  public:
     
     void  drawSoftBodySimple(NxOgre::PhysXMeshData*, const NxOgre::Bounds3&) {}
     void  drawCloth(NxOgre::PhysXMeshData*, NxOgre::Buffer<float>& textureCoords, const NxOgre::Bounds3&) {}
     void  drawClothFast(NxOgre::PhysXMeshData*, const NxOgre::Bounds3&) {}
     void  drawVisualDebugger(NxOgre::VisualDebuggerMeshData*) {}
     
     /** \brief Text
     */
     void                                      drawFluid(NxOgre::PhysXParticleData*, const NxOgre::Bounds3&);
     
     /** \brief Get the Node.
     */
     Ogre::SceneNode*                          getNode();
     
     /** \brief Get the SceneManager used.
     */
     OGRE3DRenderSystem*                       getRenderSystem();

     /** \brief
     */
     Ogre::ParticleSystem*                     getParticleSystem();

     /** \brief
     */
     OGRE3DParticleRenderable(const Ogre::String& material, OGRE3DRenderSystem*);
     
     /** \brief
     */
    ~OGRE3DParticleRenderable(void);
     
  protected:
     
     void                   initialise(NxOgre::Fluid* fluid);
     
  protected:
     
     /** \brief SceneNode appointed to this OGRE3DPointRenderable.
     */
     Ogre::SceneNode*       mNode;
     
     /** \brief RenderSystem
     */
     OGRE3DRenderSystem*    mRenderSystem;
     
     /** \brief
     */
     Ogre::ParticleSystem*  mParticleSystem;
     
     /** \brief
     */
     Ogre::String           mMaterialName;
     
     /** \brief
     */
     NxOgre::Fluid*         mFluid;
     
};

                                                                                       

#endif

/*


*/
/** File: OGRE3DRenderable.cpp
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

                                                                                       

#include "OGRE3DParticleRenderable.h"
#include "OGRE3DRenderSystem.h"
#include "Ogre.h"

                                                                                       

OGRE3DParticleRenderable::OGRE3DParticleRenderable(const Ogre::String& material, OGRE3DRenderSystem* renderSystem)
: NxOgre::Renderable(OGRE3DFluidType_OgreParticle),
  mMaterialName(material),
  mRenderSystem(renderSystem),
  mParticleSystem(0)
{
}

OGRE3DParticleRenderable::~OGRE3DParticleRenderable(void)
{
 
 if (mParticleSystem)
 {
  if (mParticleSystem->isAttached())
   mParticleSystem->getParentSceneNode()->detachObject(mParticleSystem);
  
  mRenderSystem->getSceneManager()->destroyParticleSystem(mParticleSystem);
  mParticleSystem = 0;
 }
}

void OGRE3DParticleRenderable::initialise(NxOgre::Fluid* fluid)
{
 
 mFluid = fluid;
 
 mNode = mRenderSystem->getSceneManager()->getRootSceneNode()->createChildSceneNode();
 mParticleSystem = mRenderSystem->getSceneManager()->createParticleSystem(
   mRenderSystem->getUniqueName("OGRE3DParticleRenderable"),
   mFluid->getMaxParticles() * 2);
 mNode->attachObject(mParticleSystem);
 
 mParticleSystem->setDefaultDimensions(0.2, 0.2);
 mParticleSystem->setMaterialName(mMaterialName);
 mParticleSystem->setParticleQuota(mFluid->getMaxParticles());
 mParticleSystem->setSpeedFactor(0.0f);
 
}

void OGRE3DParticleRenderable::drawFluid(NxOgre::PhysXParticleData* data, const NxOgre::Bounds3& bounds)
{
 
 if (data->getNbParticles() > mParticleSystem->getNumParticles())
 {
   unsigned int newParticleCount = data->getNbParticles() - mParticleSystem->getNumParticles();
   for (unsigned int i=0;i < newParticleCount;i++)
   {
    Ogre::Particle* particle = mParticleSystem->createParticle();
    if (particle)
    {
     particle->timeToLive = 1.0f;
    }
   }
 }
 
 float* positions = data->getPositions();
 unsigned int i = 0;
 Ogre::ParticleIterator it = mParticleSystem->_getIterator();
 while(!it.end())
 {
  Ogre::Particle* particle = it.getNext();
  particle->position.x = positions[i];
  particle->position.y = positions[i+1];
  particle->position.z = positions[i+2];
  particle->colour.a = 0.2;
  i+=3;
 }
 
}

Ogre::SceneNode* OGRE3DParticleRenderable::getNode()
{
 return mNode;
}

OGRE3DRenderSystem* OGRE3DParticleRenderable::getRenderSystem()
{
 return mRenderSystem;
}


Ogre::ParticleSystem* OGRE3DParticleRenderable::getParticleSystem()
{
 return mParticleSystem;
}



                                                                                       

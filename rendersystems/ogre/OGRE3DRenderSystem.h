/** File: OGRE3DRenderSystem.h
    Created on: 25-Nov-08
    Author: Robin Southern "betajaen"
    SVN: $Id$

    Copyright (c) 2008 Robin Southern

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

#ifndef OGRE3D_RENDERSYSTEM_H
#define OGRE3D_RENDERSYSTEM_H

                                                                                       

#include "OGRE3DCommon.h"
#include "NxOgre.h"
#include "NxOgreArray.h"
#include "Ogre.h"

                                                                                       

class OGRE3DExportClass OGRE3DRenderSystem : public NxOgre::PointerClass<_OGRE3DRenderSystem>, public NxOgre::TimeListener
{
  public:

     /** \brief OGRE3DRenderSystem constructor.
         \param Scene* Scene to work with
         \param SceneManager SceneManager, or 0 to use the first available.
         
     */
     OGRE3DRenderSystem(NxOgre::Scene*, Ogre::SceneManager* = ::Ogre::Root::getSingletonPtr()->getSceneManagerIterator().getNext());

     /** \brief
     */
    ~OGRE3DRenderSystem(void);
     
     /** \brief Get the scene.
     */
     NxOgre::Scene*                       getScene(void);
     
     /** \brief Create a Body.
     */
     OGRE3DBody*                          createBody(NxOgre::Shape*, NxOgre::Vec3 position, const Ogre::String& meshName, const NxOgre::RigidBodyDescription& = NxOgre::RigidBodyDescription());
     
     /** \brief Create a Body.
     */
     OGRE3DBody*                          createBody(NxOgre::Shapes, NxOgre::Vec3 position, const Ogre::String& meshName, const NxOgre::RigidBodyDescription& = NxOgre::RigidBodyDescription());
     
     /** \brief Destroy a Body.
     */
     void                                 destroyBody(OGRE3DBody*);
     
     /** \brief Create and manage a Renderable.
     */
     OGRE3DRenderable*                    createRenderable(NxOgre::Enums::RenderableType, const Ogre::String& materialName = "BaseWhiteNoLighting");
     
     /** \brief Destroy a Renderable.
     */
     void                                 destroyRenderable(OGRE3DRenderable*);
     
     /** \brief Create and manage a point Renderable.
     */
     OGRE3DPointRenderable*               createPointRenderable(const Ogre::String& ogre_mesh_name);
     
     /** \brief Create and manage a point Renderable.
     */
     OGRE3DPointRenderable*               createPointRenderable(Ogre::MovableObject*);
     
     /** \brief Destroy a Renderable.
     */
     void                                 destroyPointRenderable(OGRE3DPointRenderable*);
     
     /** \brief Create a KinematicBody, a KinematicActor as a Body.
     */
     OGRE3DKinematicBody*                 createKinematicBody(NxOgre::Shape*, NxOgre::Vec3 position, const Ogre::String& meshName, const NxOgre::RigidBodyDescription& = NxOgre::RigidBodyDescription());
     
     /** \brief Destroy a KinematicBody.
     */
     void                                 destroyKinematicBody(OGRE3DKinematicBody*);
     
     /** \brief Helper function for Debug Visualisation.
     */
     void                                 setVisualisationMode(NxOgre::Enums::VisualDebugger);
     
     /** \brief Is the Visual Debuggger active?
     */
     bool                                 hasDebugVisualisation(void) const;

     /** \internal Do not call.
     */
     bool                                 advance(float user_deltaTime, const NxOgre::Enums::Priority&);
     
     /** \brief
     */
     Ogre::SceneManager*                  getSceneManager();

     /** \brief Create an unique name
     */
     Ogre::String                         getUniqueName(const Ogre::String& prefix) const;

     /** \brief Helper function to create a cloth using the OGRE3DRenderable
     */
     NxOgre::Cloth*                       createCloth(const NxOgre::ClothDescription&, const Ogre::String& material = "BaseWhiteNoLighting");

     /** \brief Helper function to destroya cloth with a OGRE3DRenderable
     */
     void                                 destroyCloth(NxOgre::Cloth*);

     /** \brief Helper function to create a soft body using the OGRE3DRenderable
     */
     NxOgre::SoftBody*                    createSoftBody(const NxOgre::SoftBodyDescription&, const Ogre::String& material = "BaseWhiteNoLighting");

     /** \brief Helper function to destroya soft body with a OGRE3DRenderable
     */
     void                                 destroySoftBody(NxOgre::SoftBody*);

  protected:
     
     NxOgre::Scene*                       mScene;
     
     Ogre::SceneManager*                  mSceneManager;

     NxOgre::Array<OGRE3DBody*>           mBodies;

     NxOgre::Array<OGRE3DKinematicBody*>  mKinematicBodies;

     NxOgre::Array<OGRE3DRenderable*>     mRenderables;

     NxOgre::Array<OGRE3DPointRenderable*> mPointRenderables;
     
     OGRE3DRenderable*                    mVisualDebuggerRenderable;
     
     Ogre::SceneNode*                     mVisualDebuggerNode;

     bool                                 mVisualDebuggerShown;
     
     static unsigned int                  mUniqueIdentifier;
};

                                                                                       

#endif

/** File: OGRE3DBody.h
    Created on: 25-Nov-08
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

#ifndef OGRE3D_Body_H
#define OGRE3D_Body_H

                                                                                       

#include "NxOgre.h"
#include "OGRE3DCommon.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreTimeListener.h"

                                                                                       

/** \brief A OGRE3DBody is just an Actor that is "rendered" on the screen. Not only containing
           the standard physics properties and functions of an Actor. It also contains some
           information describing the object visually; what shape it is, it's dimensions and
           it's colour. Once combined that with the getPose() function from Actor. It's pretty
           easy to use all of that information to draw something on the screen. Of course in
           different types of RenderSystems available; the render information would be different.
           Ogre's for example wouldn't be as low-level, and would only contain a pointer to a node
           on a scenegraph, as well as reference to the mesh it is using.
*/
class OGRE3DExportClass OGRE3DBody : public NxOgre::Actor, public NxOgre::TimeListener
{
   
  friend class OGRE3DRenderSystem;
  template<class T> friend inline void ::NxOgre::Functions::safe_delete(T*);
   
 public:
   
   /** \brief Returns "RigidBodyType_OGRE3DBody" as the type of RigidBody.
   */
   virtual unsigned int  getRigidBodyType() const;
   
   /** \brief Get the SceneManager that the SceneNode is in.
   */
   Ogre::SceneManager*  getSceneManager();
   
   /** \brief Get the SceneNode is in, or NULL if there isn't one.
   */
   Ogre::SceneNode*  getSceneNode();
    
   /** \brief Set the SceneNode to a new one
   */
   void  setSceneNode(Ogre::SceneNode*, OGRE3DSceneNodeDestructorBehaviour = OGRE3DSceneNodeDestructorBehaviour_Inherit);
   
   /** \brief Get the behaviour of the Scenenode when calling setSceneNode or the destructor.
   */
   OGRE3DSceneNodeDestructorBehaviour getSceneNodeDestructorBehaviour() const;
   
   /** \brief Get the behaviour of the Scenenode when calling setSceneNode or the destructor.
   */
   void setSceneNodeDestructorBehaviour(OGRE3DSceneNodeDestructorBehaviour);
   
   /** \brief "Drawing" function, called by the TimeListener - Changes the SceneNode pose to the same one as the NxActor's.
   */
   bool advance(float, const NxOgre::Enums::Priority&);
   
 protected:
   
   /** \internal. Use OGRE3DRenderSystem::createBody
   */
   OGRE3DBody(const NxOgre::ShapeDescription&, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription&, OGRE3DRenderSystem*);
     
   /** \internal. Use OGRE3DRenderSystem::createBody
   */
   OGRE3DBody(const NxOgre::ShapeDescriptions&, const NxOgre::Matrix44& pose, OGRE3DRigidBodyDescription&, OGRE3DRenderSystem*);
   
   /** \internal. Use OGRE3DRenderSystem::destroyBody
   */
   virtual ~OGRE3DBody(void);
   
   void _destructNode(OGRE3DSceneNodeDestructorBehaviour);
   
 protected:
     
     OGRE3DRenderSystem*                 mRenderSystem;   //< \brief Body's Rendersystem
     Ogre::SceneManager*                 mSceneManager;   //< \brief Scenenode's SceneManager.
     Ogre::SceneNode*                    mNode;           //< \brief Scenenode itself..
     NxOgre::Enums::Priority             mRenderPriority; //< \brief Render priority.
     OGRE3DSceneNodeDestructorBehaviour  mSceneNodeDestructorBehaviour; //< \brief Behaviour when deleting the SceneNode.
     NxOgre::Matrix44                    mAlphaPose;      //< \brief Interpolation pose.

};

                                                                                       

#endif

/*


*/
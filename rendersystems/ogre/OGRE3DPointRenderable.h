/** File: OGRE3DPointRenderable.h
    Created on: 18-May-09
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

#ifndef OGRE3D_POINTRENDERABLE_H
#define OGRE3D_POINTRENDERABLE_H

                                                                                       

#include "NxOgre.h"
#include "OGRE3DCommon.h"
#include <OgreSimpleRenderable.h>

                                                                                       

/** \brief A OGRE3D RenderSystem implementation of the PointRenderable class.
*/
class OGRE3DExportClass OGRE3DPointRenderable : NxOgre::PointerClass<_OGRE3DPointRenderable>, public NxOgre::PointRenderable
{
  
  friend class OGRE3DRenderSystem;
  
  public:
  
   using ::NxOgre::PointerClass<_OGRE3DPointRenderable>::operator new;
   
   using ::NxOgre::PointerClass<_OGRE3DPointRenderable>::operator delete;
    
     
  public:
     
     
     /** \brief Text
     */
     void                                      render(const NxOgre::Vec3&, const NxOgre::Quat&);


      /** \brief Add a pre-existing node to the node.
          \note If this node is a child of another, it will remove the node for you.
      */
     void                                      addSceneNode(Ogre::SceneNode*);

      /** \brief Add a pre-existing node to the node using a string as an identifier.
          \note If this node is a child of another, it will remove the node for you.
      */
      void                                     addSceneNode(const Ogre::String&);

      /** \brief Add a pre-existing entity to the node.
          \note If this entity is already attached to another scenenode it will remove it for you.
      */
      void                                      addEntity(Ogre::Entity*);

      /** \brief Add a movable object to this node.
          \note If this movable object is already attached to another scenenode it will remove it for you.
      */
      void                                      addMovableObject(Ogre::MovableObject*);

      /** \brief Removes a node from the node
      */
      void                                      removeSceneNode(Ogre::SceneNode*);


      /** \brief Removes a node from the node using a string as an identifier
      */
      void                                      removeSceneNode(const Ogre::String&);


      /** \brief Remove an entity from the node, but don't delete it
      */
      void                                      removeEntity(Ogre::Entity*);


      /** \brief Remove an entity from the node, but don't delete it,
      using a string as an identifier.
      */
      void                                      removeEntity(const Ogre::String&);


      /** \brief Destroys an entity from the node.
      */
      void                                      destroyEntity(Ogre::Entity*);


      /** \brief Destroys an entity from the node, using a string as
      an identifier.
      */
      void                                      destroyEntity(const Ogre::String&);


      /** \brief Remove an MovableObject from the node, but don't delete it.
      */
      void                                      removeMovableObject(Ogre::MovableObject*);


      /** \brief Remove an MovableObject from the node, but don't delete it, using a string as an identifier.
      */
      void                                      removeMovableObject(const Ogre::String&);


      /** \brief Destroys an MovableObject from the node.
      */
      void                                      destroyMovableObject(Ogre::MovableObject*);


      /** \brief Destroys an MovableObject from the node.
      */
      void                                      destroyMovableObject(const Ogre::String&);

      /** \brief Get the Node.
      */
      Ogre::SceneNode*                          getNode();

      /** \brief Get the SceneManager used.
      */
      Ogre::SceneManager*                       getSceneManager();
      
      /** \brief Get the SceneManager used.
      */
      OGRE3DRenderSystem*                       getRenderSystem();
     
     
     /** \brief
     */
     OGRE3DPointRenderable(OGRE3DRenderSystem*, const Ogre::String& ogre_mesh_name);
     
     /** \brief Alternate/Default constructor.
     */
     OGRE3DPointRenderable(OGRE3DRenderSystem*, Ogre::MovableObject*);
     
     /** \brief
     */
    ~OGRE3DPointRenderable(void);
     
  protected: // functions
     
     /** \internal
     */
     inline Ogre::Entity* fetchEntity(const Ogre::String& name);
     
     /** \internal
     */
     inline void destroyNode(Ogre::SceneNode*);
     
     /** \internal
     */
     inline void parseMovableObject(Ogre::MovableObject*);

  protected:

     /** \brief SceneNode appointed to this OGRE3DPointRenderable.
     */
     Ogre::SceneNode*     mNode;
     
     /** \brief RenderSystem
     */
     OGRE3DRenderSystem*  mRenderSystem;
};

                                                                                       

#endif

/*


*/
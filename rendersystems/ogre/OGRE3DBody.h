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
class OGRE3DExportClass OGRE3DBody : public NxOgre::PointerClass<_OGRE3DBody>, public NxOgre::Actor, public NxOgre::TimeListener
{
  friend class OGRE3DRenderSystem;
  friend class ::NxOgre::Functions::ArrayFunctions<OGRE3DBody*>::Write;

  public:
  
   /** \brief Required since Actor is also a "PointerClass".
   */
   using ::NxOgre::PointerClass<_OGRE3DBody>::operator new;

    /** \brief Required since Actor is also a "PointerClass".
    */
   using ::NxOgre::PointerClass<_OGRE3DBody>::operator delete;
  
    /** \brief Required since Actor is also a "PointerClass".
    */
   using ::NxOgre::PointerClass<_OGRE3DBody>::getClassType;
  
    /** \brief
    */
    unsigned int getClassType() const;

    /** \brief Get the SceneManager that the SceneNode is in.
    */
   Ogre::SceneManager* getSceneManager();
  
    /** \brief Get the SceneNode is in, or NULL if there isn't one.
    */
   Ogre::SceneNode*    getSceneNode();
  
    /** \brief Get the SceneNode is in, or NULL if there isn't one.
    */
   Ogre::Entity*       getEntity();
  
    /** \brief "Drawing" function, called by the TimeListener.
    */
   bool                advance(float, const NxOgre::Enums::Priority&);

  protected:
  
     /** \internal. Use OGRE3DRenderSystem::createBody
     */
     OGRE3DBody(OGRE3DRigidBodyPrototype*, OGRE3DRenderSystem*);
  
     /** \internal. Use OGRE3DRenderSystem::destroyBody
     */
    ~OGRE3DBody(void);
  
  protected:
  
     OGRE3DRenderSystem*     mRenderSystem;   //< \brief Body's Rendersystem
     Ogre::SceneManager*     mSceneManager;   //< \brief Node's parent.
     Ogre::SceneNode*        mNode;           //< \brief Bleh.
     Ogre::Entity*           mEntity;         //< \brief Attached Entity or NULL.
     NxOgre::Enums::Priority mRenderPriority; //< \brief Render priority.
     bool                    mSelfCreated;    //< \brief Was the node created by the Body, or was it passed on?
     static unsigned int     mNextBodyID;     //< \brief Not all actors have names. So when it comes to naming
                                              //<        nodes and entities. It will use nextBodyID as an unique
                                              //<        name; "ogre3d-entity-1", "ogre3d-node-1".

};

                                                                                       

#endif

/*


*/
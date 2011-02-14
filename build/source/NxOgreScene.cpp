/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#include "NxOgreScene.h"
#include "NxPhysics.h"

namespace NxOgre
{
 
 // --------------------------------------------------

 NxSceneDesc SceneDescription::to_physx_desc() const
 {
  NxSceneDesc desc;
  return desc;
 }

 // --------------------------------------------------

 String to_s(const SceneDescription::Reason& r)
 {
  OStringStream s;
  //if (r.assertion_policy)
  // s << "Assertion response\n";

  return s.str();
 }

 // --------------------------------------------------

 Scene::Scene(const SceneDescription& desc, World* parent)
 : mScene(NXOGRE_NULL_POINTER), mParent(parent)
 {
  loadFromDescription(desc);
 }

 // --------------------------------------------------

 Scene::~Scene()
 {
 }

 // --------------------------------------------------

 void Scene::loadFromDescription(const SceneDescription& desc)
 {
 }

 // --------------------------------------------------

 SceneDescription Scene::saveToDescription() const
 {
  return SceneDescription();
 }
 
 // --------------------------------------------------


} // namespace World

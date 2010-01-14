#ifndef TEST_BASIC_H
#define TEST_BASIC_H

#include "Soy.h"
#include "NxOgre.h"

CASE_BEGIN(Basic)
Basic()
{
 
 using namespace NxOgre;
 
 CASE_DESCRIPTION("NxOgre::Basic");
 
 World* case_World;
 Scene* case_Scene;
 Actor* case_Actor;
 BoxDescription case_BoxShapeDescription;

 TEST_DESCRIPTION("World Creation")
 {
  case_World = NxOgre::World::createWorld();
  TEST_FAIL_IF(case_World == 0, "World pointer is zero")
 }

 TEST_DESCRIPTION("Scene Creation")
 {
  NxOgre::SceneDescription case_scene_description;
  case_Scene = case_World->createScene(case_scene_description);
  TEST_FAIL_IF(case_Scene == 0, "Scene pointer is zero")
 }
 
 TEST_DESCRIPTION("Actor with Box")
 {
  case_BoxShapeDescription.mSize.set(1,1,1);
  case_Actor = case_Scene->createActor(case_BoxShapeDescription);
  TEST_FAIL_IF(case_Actor == 0, "Actor pointer is zero")
 }
 
}
CASE_END

#endif
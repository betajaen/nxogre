cmake_minimum_required(VERSION 2.8)
project(NxOgre)

### include additional cmake scripts
set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_MODULE_PATH}
)

find_package(PhysX REQUIRED)

if(NOT PHYSX_FOUND)
     message("PhysX not found")
endif(NOT PHYSX_FOUND)

message(${PHYSX_INCLUDES})
include_directories(${PHYSX_INCLUDES})

file(GLOB NxOgreLibH ${PROJECT_SOURCE_DIR}/source/*.h)
file(GLOB NxOgreLibSrc ${PROJECT_SOURCE_DIR}/source/*.cpp)

file(GLOB to_remove ${PROJECT_SOURCE_DIR}/source/NxOgre.cpp
)
list(REMOVE_ITEM NxOgreLibSrc ${to_remove})


add_library(NxOgre SHARED 
	${NxOgreLibH}
	${NxOgreLibSrc}
)

TARGET_LINK_LIBRARIES(NxOgre ${PHYSX_LIBRARIES})

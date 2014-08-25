cmake_minimum_required(VERSION 2.8)
project(NxOgre)

set (CMAKE_C_FLAGS "-m32")
set (CMAKE_CXX_FLAGS "-m32")

add_definitions( -DNXOGRE_SDK)

message("Using compiler: " ${CMAKE_CXX_COMPILER_ID} )



add_subdirectory(build)

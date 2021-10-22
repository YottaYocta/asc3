cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(asc3)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/src/examples)

## LIBRARY

set(LIB_SRCS
  ${SRC_DIR}/utils/canvas.cpp
  ${SRC_DIR}/core/primitives.cpp
  ${SRC_DIR}/core/materials.cpp
  ${SRC_DIR}/core/scene.cpp
  ${SRC_DIR}/core/lights.cpp
  ${SRC_DIR}/swpt/pathtracer.cpp
)
add_library(asc3 STATIC ${LIB_SRCS})
target_include_directories(asc3 PUBLIC ${INCLUDE_DIR})

## EXAMPLES

add_executable(asc3_gradient ${EXAMPLE_DIR}/gradient.cpp)
target_link_libraries(asc3_gradient PUBLIC asc3)

add_executable(asc3_software_pathtracer ${EXAMPLE_DIR}/software_pathtracer.cpp)
target_link_libraries(asc3_software_pathtracer PUBLIC asc3)

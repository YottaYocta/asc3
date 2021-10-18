cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(asc3)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

set(SRCS
  ${SRC_DIR}/examples/main.cpp
  ${SRC_DIR}/utils/canvas.cpp
)
add_executable(asc3_pathtracer ${SRCS})
target_include_directories(asc3_pathtracer PUBLIC include)

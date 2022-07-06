cmake_minimum_required(VERSION 3.16)

project(concepts)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_STANDARD 20)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})


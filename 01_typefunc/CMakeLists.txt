cmake_minimum_required(VERSION 3.21)

project(learncpp_20)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_STANDARD 20)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

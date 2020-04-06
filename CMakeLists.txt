cmake_minimum_required(VERSION 3.10)
project(catchcpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppfun src/main.cpp)
add_executable(catch tests/catch.hpp tests/CatchMain.cpp tests/Tests.cpp tests/TestStd.cpp tests/TestMis.cpp)

add_subdirectory(src)

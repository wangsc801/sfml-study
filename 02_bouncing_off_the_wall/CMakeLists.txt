cmake_minimum_required(VERSION 3.10)

project(bouncing_off_the_wall)

set(CMAKE_C_COMPILER "C:/mingw32/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw32/bin/g++.exe")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(bouncing_off_the_wall main.cpp)

target_link_libraries(bouncing_off_the_wall sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
cmake_minimum_required(VERSION 3.10)

project(snake)

set(CMAKE_C_COMPILER "C:/mingw32/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw32/bin/g++.exe")

set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(snake main.cpp Window.cpp Game.cpp World.cpp)

target_link_libraries(snake sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
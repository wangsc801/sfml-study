cmake_minimum_required(VERSION 3.10)

project(project_structure)

set(CMAKE_C_COMPILER "C:/mingw32/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw32/bin/g++.exe")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(project_structure main.cpp Window.cpp Game.cpp)

target_link_libraries(project_structure sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
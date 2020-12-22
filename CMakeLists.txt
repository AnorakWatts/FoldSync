cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(untitled main.cpp egg.cpp egg.h)

target_link_libraries(untitled sfml-graphics sfml-audio)
cmake_minimum_required(VERSION 3.5)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
message("Build type: ${CMAKE_BUILD_TYPE}")

project(justclipboard LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(justclipboard
  main.cpp
  justclipboard.cpp
  justclipboard.h
)

target_link_libraries(justclipboard PRIVATE Qt5::Widgets)

set_target_properties(justclipboard PROPERTIES LINK_FLAGS_RELEASE -s)

install(TARGETS justclipboard)

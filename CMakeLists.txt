cmake_minimum_required(VERSION 3.5)

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

install(TARGETS justclipboard
        RUNTIME DESTINATION bin)

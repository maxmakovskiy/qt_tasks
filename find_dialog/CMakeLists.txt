cmake_minimum_required(VERSION 3.16)

project(find_dialog VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(main
    main.cpp
    find_dialog.cc
)

target_link_libraries(main PRIVATE Qt6::Widgets)

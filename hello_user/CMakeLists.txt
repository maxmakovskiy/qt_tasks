cmake_minimum_required(VERSION 3.16)

project(hello_user)

# Meta-Ojbect Compiler (moc)
set(CMAKE_AUTOMOC ON)

# Resource Compiler (rcc)
set(CMAKE_AUTORCC ON)

# User Interface Compiler (uic)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(main
    main.cpp
)

target_link_libraries(main
    PRIVATE Qt6::Widgets
)



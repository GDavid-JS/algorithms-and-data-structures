cmake_minimum_required(VERSION 3.1.0)

project(sort VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Concurrent Widgets Charts REQUIRED)
# Установка пути к библиотеке QCustomPlot
include_directories(/usr/include)

add_executable(main
    main.cpp
)

target_link_libraries(main Qt5::Widgets Qt5::Charts Qt5::Concurrent qcustomplot)

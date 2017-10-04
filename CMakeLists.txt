cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME Widgets)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Button.cpp Button.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system pthread)
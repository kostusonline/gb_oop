cmake_minimum_required(VERSION 3.19)

PROJECT(lesson6)

file(GLOB sources "src/*.cpp")

add_executable(lesson6 ${sources})

target_include_directories(lesson6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

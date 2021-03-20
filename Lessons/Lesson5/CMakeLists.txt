cmake_minimum_required(VERSION 3.19)

PROJECT(lesson5)

file(GLOB sources "src/*.cpp")

add_executable(lesson5 ${sources})

target_include_directories(lesson5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

cmake_minimum_required(VERSION 3.19)

PROJECT(lesson7)

file(GLOB sources "src/*.cpp")

add_executable(lesson7 ${sources})

target_include_directories(lesson7 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson7 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

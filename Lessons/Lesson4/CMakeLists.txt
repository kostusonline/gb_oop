cmake_minimum_required(VERSION 3.19)

PROJECT(lesson4)

file(GLOB sources "src/*.cpp")

add_executable(lesson4 ${sources})

target_include_directories(lesson4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

cmake_minimum_required(VERSION 3.19)

PROJECT(bj)

file(GLOB sources "src/*.cpp")

add_executable(bj ${sources})

target_include_directories(bj PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(bj PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

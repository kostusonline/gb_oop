PROJECT(lesson2)

file(GLOB sources "src/*.cpp")

add_executable(lesson2 ${sources})

target_include_directories(lesson2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

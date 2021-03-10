PROJECT(lesson3)

file(GLOB sources "src/*.cpp")

add_executable(lesson3 ${sources})

target_include_directories(lesson3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lesson3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}../include)

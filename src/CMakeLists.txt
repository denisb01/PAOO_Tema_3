cmake_minimum_required(VERSION 3.7.2)

project(tema)

add_subdirectory(printer_resource)
target_include_directories(printer_resource PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/printer_resource/)

add_subdirectory(mutex_raii)
target_include_directories(mutex_raii PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mutex_raii/)

add_executable(app main.cpp)

target_link_libraries(app printer_resource mutex_raii)
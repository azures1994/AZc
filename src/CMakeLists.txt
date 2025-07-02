cmake_minimum_required(VERSION 3.16.3)
project(AZc VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(file/)
add_subdirectory(cv/)

add_library(${PROJECT_NAME} INTERFACE)
## target_include_directories may only set INTERFACE properties on INTERFACE
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE file cv)
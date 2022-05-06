cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(CoreLib Core.cpp)
target_include_directories(CoreLib PRIVATE ${INCLUDE_DIR})
target_link_libraries(CoreLib CommonLib)
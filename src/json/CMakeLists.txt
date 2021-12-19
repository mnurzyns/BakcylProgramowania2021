cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(JsonLib Json.cpp)
target_include_directories(JsonLib PRIVATE ${INCLUDE_DIR})

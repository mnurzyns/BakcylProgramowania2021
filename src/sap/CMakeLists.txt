cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(SapLib Sap.cpp)
target_include_directories(SapLib PRIVATE ${INCLUDE_DIR})

cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(CommonLib product.cpp productInstance.cpp)
target_include_directories(CommonLib PRIVATE ${INCLUDE_DIR})

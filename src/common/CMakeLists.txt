cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(COMMON_SOURCES
	product.cpp
	productInstance.cpp)

add_library(CommonLib ${COMMON_SOURCES})
target_include_directories(CommonLib PRIVATE ${INCLUDE_DIR})
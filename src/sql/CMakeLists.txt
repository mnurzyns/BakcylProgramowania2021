cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(SqlLib Sql.cpp)
target_include_directories(SqlLib PRIVATE ${INCLUDE_DIR})

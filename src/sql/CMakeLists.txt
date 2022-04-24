cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(SQL_SOURCES
    Sql.hpp
    Sql.cpp
    Product.hpp
    Product.cpp
    ProductInstance.hpp
    ProductInstance.cpp
    Location.hpp
    Location.cpp
)

add_library(SqlLib ${SQL_SOURCES})
target_link_libraries(SqlLib Threads::Threads ${QtSqlLib})

target_include_directories(SqlLib PRIVATE ${INCLUDE_DIR})

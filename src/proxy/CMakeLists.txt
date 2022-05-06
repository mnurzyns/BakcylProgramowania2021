cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(ProxyLib
Proxy.hpp
baseProxy.hpp
sqlProxy.hpp
sqlProxy.cpp
converters.hpp
converters.cpp
)

target_include_directories(ProxyLib PRIVATE ${INCLUDE_DIR})
target_link_libraries(ProxyLib SqlLib CommonLib)
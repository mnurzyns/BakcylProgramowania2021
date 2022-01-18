cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

add_library(MailLib Mail.cpp)
target_include_directories(MailLib PRIVATE ${INCLUDE_DIR})

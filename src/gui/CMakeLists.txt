cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(GUI_SOURCES
    Gui.hpp
    Gui.cpp)

add_library(GuiLib ${GUI_SOURCES})
target_link_libraries(GuiLib PRIVATE
                      Threads::Threads
                      ${QtLib})

target_include_directories(GuiLib PRIVATE ${INCLUDE_DIR})

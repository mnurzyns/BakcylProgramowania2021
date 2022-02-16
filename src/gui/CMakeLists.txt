cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(GUI_SOURCES
    )

add_library(GuiLib ${GUI_SOURCES})
target_include_directories(GuiLib PRIVATE ${INCLUDE_DIR})

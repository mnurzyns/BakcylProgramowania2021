cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(GUI_SOURCES
    Gui.hpp
    Gui.cpp
    searchboxcontroller.hpp
    searchboxcontroller.cpp
    ProductModel.hpp
    ProductModel.cpp
    ProductDataHandler.hpp
    ProductDataHandler.cpp
    ProductInstanceModel.hpp
    ProductInstanceModel.cpp
    DatabaseManager.cpp
    DatabaseManager.hpp)

add_library(GuiLib ${GUI_SOURCES})
target_link_libraries(GuiLib PRIVATE
                      Threads::Threads
                      ${QtLib} 
                      CoreLib)

target_include_directories(GuiLib PRIVATE ${INCLUDE_DIR})

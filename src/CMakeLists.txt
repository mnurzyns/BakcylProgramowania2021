cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(PROJECT_SOURCES
        main.cpp
        gui/resources/qml.qrc
)

add_subdirectory(gui)
add_subdirectory(core)
add_subdirectory(mail)
add_subdirectory(proxy)
add_subdirectory(sap)
add_subdirectory(sql)

add_subdirectory(common)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${CMAKE_PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Threads::Threads
    ${QtLib}
    ${QtSqlLib}	
    GuiLib
    CoreLib
    MailLib
    ProxyLib
    SapLib
    SqlLib
    CommonLib
)

add_custom_target(${CMAKE_PROJECT_NAME}-run
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
    )

cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

set(TEST_MAIN ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

include(${CMAKE_BASE_LIST_DIR}/cmake/add_ut.cmake)

set_property(GLOBAL PROPERTY ALL_TESTS_LIST)

add_subdirectory(core)
add_subdirectory(json)
add_subdirectory(mail)
add_subdirectory(proxy)
add_subdirectory(sap)
add_subdirectory(sql)

get_property(ALL_TESTS_LIST GLOBAL PROPERTY ALL_TESTS_LIST)

add_custom_target(all_tests
    DEPENDS
    ${ALL_TESTS_LIST}
    COMMAND ctest)

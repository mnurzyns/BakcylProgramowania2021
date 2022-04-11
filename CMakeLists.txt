set(CMAKE_REQUIRED_VERSION 3.14)
cmake_minimum_required(VERSION ${CMAKE_REQUIRED_VERSION})

project(BakcylProgramowania2021 LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(QT NAMES Qt5 COMPONENTS Core Quick Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Sql REQUIRED)
find_package(Threads REQUIRED)

set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/test)
set(CMAKE_BASE_LIST_DIR ${CMAKE_CURRENT_LIST_DIR})
set(QtLib Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
set(QtSqlLib Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
include(CTest)
enable_testing()
add_subdirectory(test)

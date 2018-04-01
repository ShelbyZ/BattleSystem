cmake_minimum_required(VERSION 3.5)
project(BattleSystem)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(${CMAKE_SOURCE_DIR}/cmake/compiler.cmake)
include(GenerateExportHeader)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    find_package(GTest PATH ${CMAKE_SOURCE_DIR}/lib REQUIRED)
    find_package(Threads REQUIRED)

    enable_testing()
    add_subdirectory(test)
endif()
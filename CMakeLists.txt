cmake_minimum_required(VERSION 3.10)
project(BattleSystem)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(${CMAKE_SOURCE_DIR}/cmake/compiler.cmake)
include(GenerateExportHeader)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(external)

    enable_testing()
    add_subdirectory(test)
endif()
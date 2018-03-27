cmake_minimum_required(VERSION 3.10)
project(BattleSystem)

include(${CMAKE_SOURCE_DIR}/cmake/compiler.cmake)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(external)
    add_subdirectory(test)
endif()
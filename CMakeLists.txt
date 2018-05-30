cmake_minimum_required(VERSION 3.5)
project(BattleSystem)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(${CMAKE_SOURCE_DIR}/cmake/compiler.cmake)
include(GenerateExportHeader)
include(ProcessorCount) 
ProcessorCount(CORES)

option(BUILD_TESTS "Build tests" OFF)
option(COVERAGE "Run Code Coverage" OFF)

if(COVERAGE)
    message(STATUS "Code Coverage enabled")
    include(${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake)
    set(COVERAGE_EXCLUDES "gtest/*" "c++/*" "src/arena/*" "CMakeFiles/*" "vcpkg/*")
    setup_target_for_coverage(NAME ${PROJECT_NAME}_coverage EXECUTABLE unit_tests -j ${CORES} DEPENDENCIES battle_system)

    append_coverage_compiler_flags()
endif()

add_subdirectory(src)

if(BUILD_TESTS)
    message(STATUS "Tests enabled")
    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)

    enable_testing()
    add_subdirectory(test)
endif()

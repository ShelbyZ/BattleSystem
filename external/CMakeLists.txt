cmake_minimum_required(VERSION 2.6.2)

project(googletest-distribution NONE)

enable_testing()

add_subdirectory(googletest)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_definitions(gtest PUBLIC _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
endif()

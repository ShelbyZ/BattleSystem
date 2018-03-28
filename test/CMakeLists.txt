project(BattleSystem)

#include(${CMAKE_SOURCE_DIR}/cmake/gtest.cmake)

include(GoogleTest)

add_executable(unit_tests
    battle_system_tests.cpp
)

target_include_directories(unit_tests PRIVATE
    ../external/googletest/include
    ../src/battle_system
)

target_link_libraries(unit_tests battle_system gtest gtest_main)

#gtest_add_tests(unit_tests SOURCES battle_system_tests.cpp)
gtest_add_tests(unit_tests "" AUTO)
#gtest_discover_tests(unit_tests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
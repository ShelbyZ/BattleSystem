project(BattleSystem)

add_executable(unit_tests
    battle_system_tests.cpp
)

if(MSVC)
    find_path(GTEST_INLCUDE_DIRS gtest/gtest.h)

    set(GTEST_BOTH_LIBRARIES GTest::GTest GTest::Main)
endif()

target_include_directories(unit_tests PRIVATE
    ${GTEST_INLCUDE_DIRS}
    ../src/battle_system
)

target_link_libraries(unit_tests battle_system ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

gtest_add_tests(unit_tests "" AUTO)

# fix once can figure this out
#gtest_discover_tests(unit_tests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
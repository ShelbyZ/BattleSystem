project(BattleSystem)

add_executable(arena
    main.cpp
)

target_include_directories(arena PRIVATE
    ../battle_system
)

target_link_libraries(arena PRIVATE battle_system)

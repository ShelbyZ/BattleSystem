project(BattleSystem)

add_definitions(-Dbattle_system_EXPORTS)

add_library(battle_system SHARED
    battle_system.cpp
)

# fix once msvc supports this
#generate_export_header(battle_system)

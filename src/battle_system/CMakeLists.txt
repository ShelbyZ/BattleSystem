project(BattleSystem)

# still not sure this is needed
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(battle_system SHARED
    battle_system.cpp
)

target_compile_definitions(battle_system PRIVATE battle_system_EXPORTS)

generate_export_header(battle_system)
file(COPY ${PROJECT_BINARY_DIR}/battle_system_export.h DESTINATION ${CMAKE_SOURCE_DIR}/src/battle_system)

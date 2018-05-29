#include "gtest/gtest.h"

#include "../battle_system/battle_system.h"

TEST(PLAYER, registerEntity)
{
    auto system = CBattleSystem();
    auto entity = CEntity("shelby");
    auto type = CBattleSystem::EntityType::PLAYER;

    system.registerEntity(entity, type);

    auto entities = system.getEntities(type);
    ASSERT_EQ(1, entities.size());
    //ASSERT_EQ(entity, entities.front());
}

TEST(ENEMY, registerEntity)
{
    auto system = CBattleSystem();
    auto entity = CEntity("shelby");
    auto type = CBattleSystem::EntityType::ENEMY;
    system.registerEntity(entity, type);

    auto entities = system.getEntities(type);
    ASSERT_EQ(1, entities.size());
    //ASSERT_EQ(entity, entities.front());
}

TEST(UNKNOWN, registerEntity)
{
    auto system = CBattleSystem();
    auto type = CBattleSystem::EntityType::UNKNOWN;
    auto entity = CEntity("shelby");

    ASSERT_THROW({
        system.registerEntity(entity, type);
    }, std::logic_error);
}

TEST(TypeNotValid, getEntities)
{
    auto system = CBattleSystem();
    auto type = CBattleSystem::EntityType::UNKNOWN;

    ASSERT_THROW({
        auto entities = system.getEntities(type);
    }, std::logic_error);
}

TEST(EntitiesFound, getEntities)
{
    auto system = CBattleSystem();
    auto type = CBattleSystem::EntityType::PLAYER;
    auto entity = CEntity("shelby");
    system.registerEntity(entity, type);

    auto entities = system.getEntities(type);
    ASSERT_EQ(1, entities.size());
}

TEST(EntitiesNotFound, getEntities)
{
    auto system = CBattleSystem();
    auto type = CBattleSystem::EntityType::UNKNOWN;

    ASSERT_THROW({
        auto entities = system.getEntities(type);
    }, std::logic_error);
}
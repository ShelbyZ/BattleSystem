#include "gtest/gtest.h"

#include "../battle_system/entity.h"

TEST(Reference, Constructor)
{
    auto name = "shelby";
    auto entity = CEntity(name);

    ASSERT_EQ(name, entity.getName());
}

TEST(Reference_EmptyName, Constructor)
{
    ASSERT_THROW({
        auto name = "";
        auto entity = CEntity(name);
    }, std::logic_error);
}

TEST(RValueReference, Constructor)
{
    auto entity = CEntity("shelby");

    ASSERT_EQ("shelby", entity.getName());
}

TEST(RValueReference_EmptyName, Constructor)
{
    ASSERT_THROW({
        auto entity = CEntity("");
    }, std::logic_error);
}

TEST(LhsEqualsRhs, operatorEquals)
{
    auto name = "shelby";
    auto entity = CEntity(name);

    auto result = (entity == entity);

    ASSERT_EQ(true, result);
}

TEST(LhsNotEqualsRhs, operatorEquals)
{
    auto name = "shelby";
    auto entity = CEntity(name);
    auto entity2 = CEntity("NotShelby");

    auto result = (entity == entity2);

    ASSERT_EQ(false, result);
}
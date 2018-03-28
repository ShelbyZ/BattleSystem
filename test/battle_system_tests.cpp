#include "gtest/gtest.h"

#include "../battle_system/battle_system.h"

TEST(GetValue, GenericTest)
{
    auto system = CBattleSystem();

    EXPECT_EQ(system.GetValue(), -1);
}

TEST(SetValue, GenericTest)
{
    auto system = CBattleSystem();
    auto value = 9988;
    system.SetValue(value);

    EXPECT_EQ(system.GetValue(), value);
}
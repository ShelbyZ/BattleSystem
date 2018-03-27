#include "battle_system.h"

CBattleSystem::CBattleSystem()
{
    _value = -1;
}

int CBattleSystem::GetValue() const
{
    return _value;
}

void CBattleSystem::SetValue(int value)
{
    _value = value;
}
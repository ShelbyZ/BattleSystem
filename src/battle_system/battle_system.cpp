#include <stdexcept>

#include "battle_system.h"

CBattleSystem::CBattleSystem()
{
}

void CBattleSystem::registerEntity(CEntity& entity, EntityType type)
{
    if (!isValidType(type))
    {
        throw std::logic_error("Type must be valid");
    }

    _entities[type].push_back(std::move(entity));
}

const std::vector<CEntity>& CBattleSystem::getEntities(EntityType type) const
{
    if (!isValidType(type))
    {
        throw std::logic_error("Type must be valid");
    }

    auto item = _entities.find(type);
    if (item != _entities.end())
    {
        return item->second;
    }
    else
    {
        throw std::logic_error("Type not found");
    }
}

bool CBattleSystem::isValidType(EntityType type) const
{
    switch(type)
    {
        case EntityType::PLAYER:
        case EntityType::ENEMY:
            return true;
        default:
            return false;
    }
}
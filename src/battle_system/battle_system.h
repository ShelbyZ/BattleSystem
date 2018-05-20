#ifndef _BATTLE_SYSTEM_H
#define _BATTLE_SYSTEM_H

#include <unordered_map>
#include <vector>

#include "battle_system_export.h"

#include "entity.h"

class CBattleSystem
{
    public:
        enum class EntityType
        {
            UNKNOWN,
            PLAYER,
            ENEMY
        };
        BATTLE_SYSTEM_EXPORT CBattleSystem(void);
        BATTLE_SYSTEM_EXPORT void registerEntity(CEntity&, EntityType);
        BATTLE_SYSTEM_EXPORT const std::vector<CEntity>& getEntities(EntityType) const;

    private:
        bool isValidType(EntityType) const;
        std::unordered_map<EntityType, std::vector<CEntity>> _entities;
};

#endif
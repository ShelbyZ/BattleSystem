#ifndef _BATTLE_SYSTEM_H
#define _BATTLE_SYSTEM_H

#include <unordered_map>
#include <vector>

#include "battle_system_export.h"

#include "entity.h"

class BATTLE_SYSTEM_EXPORT CBattleSystem
{
    public:
        enum class EntityType
        {
            UNKNOWN,
            PLAYER,
            ENEMY
        };
        CBattleSystem(void);
        void registerEntity(CEntity&, EntityType);
        const std::vector<CEntity>& getEntities(EntityType) const;

    private:
        bool isValidType(EntityType) const;
        std::unordered_map<EntityType, std::vector<CEntity>> _entities;
};

#endif
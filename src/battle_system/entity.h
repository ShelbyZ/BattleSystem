#ifndef _ENTITY_H
#define _ENTITY_H

#include "battle_system_export.h"

#include <string>
#include <string_view>

class CEntity
{
    public:
        BATTLE_SYSTEM_EXPORT CEntity(std::string& name);
        BATTLE_SYSTEM_EXPORT CEntity(std::string&& name);
        BATTLE_SYSTEM_EXPORT bool operator==(const CEntity&) const;
        BATTLE_SYSTEM_EXPORT std::string_view getName() const;

    private:
        void validateEntity();
        std::string _name;
};

#endif
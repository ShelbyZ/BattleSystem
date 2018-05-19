#ifndef _ENTITY_H
#define _ENTITY_H

#include "battle_system_export.h"

#include <string>
#include <string_view>

class BATTLE_SYSTEM_EXPORT CEntity
{
    public:
        CEntity(std::string& name);
        CEntity(std::string&& name);
        bool operator==(const CEntity&) const;
        std::string_view getName() const;

    private:
        void validateEntity();
        std::string _name;
};

#endif
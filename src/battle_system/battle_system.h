#ifndef _BATTLE_SYSTEM_H
#define _BATTLE_SYSTEM_H

#include "battle_system_export.h"

class BATTLE_SYSTEM_EXPORT CBattleSystem
{
    public:
        CBattleSystem(void);
        int GetValue() const;
        void SetValue(int value);

    private:
        int _value;
};

#endif
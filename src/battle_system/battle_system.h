#ifndef _BATTLE_SYSTEM_H
#define _BATTLE_SYSTEM_H

#include "exports.h"

class BATTLESYSTEM_API CBattleSystem
{
    public:
        CBattleSystem(void);
        int GetValue() const;
        void SetValue(int value);

    private:
        int _value;
};

#endif
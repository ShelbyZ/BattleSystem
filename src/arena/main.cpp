#include <iostream>

#include "../battle_system/battle_system.h"

int main(int argc, char *argv[])
{
    auto system = CBattleSystem();
    std::cout << "Value is: " << system.GetValue() << "\n";
    system.SetValue(199);
    std::cout << "Value is: " << system.GetValue() << "\n";

	return 0;
}
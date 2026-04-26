#pragma once
#include "Monster.h"


class Battle
{
public:
    
    int SelectAction();

    void PlayerAttack(Monster& player, Monster& enemy);

    void EnemyAttack(Monster& enemy, Monster& player);

    void StartBattle(Monster& player, Monster& enemy);
    
    bool TryCatch(Monster& enemy);

};

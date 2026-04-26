#pragma once
#include "Monster.h"
#include "Player.h"


class Battle
{
public:
    
    int SelectAction();

    bool PlayerAttack(Player& player, Monster& playerMonster, Monster& enemy);

    void EnemyAttack(Monster& enemy, Monster& player);

    void StartBattle(Player& player, Monster& playerMonster, Monster& enemy);
    
    bool TryCatch(Player& player, Monster& enemy);

};

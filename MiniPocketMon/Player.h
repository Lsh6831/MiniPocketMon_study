#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
    // inventory[0] = 상처약
    // inventory[1] = 몬스터볼
    int inventory[2];
public:
    Player();

    int GetPotionCount() const;
    int GetMonsterBallCount() const;

    bool UsePotion();
    bool UseMonsterBall();

    void PrintInventory() const;
    
};
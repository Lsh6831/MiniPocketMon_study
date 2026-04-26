#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
    // 0 = 상처약, 1 = 몬스터볼
    int inventory[2];

public:
    Player();

    int GetPotionCount() const;
    int GetMonsterBallCount() const;

    void UsePotion(int& hp, int maxhp);
    bool UseMonsterBall();

    void PrintInventory() const;
};
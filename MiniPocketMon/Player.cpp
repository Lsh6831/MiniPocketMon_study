#include "Player.h"

Player::Player()
{
    inventory[0] = 3; // 상처약
    inventory[1] = 5; // 몬스터볼
}

int Player::GetPotionCount() const
{
    return inventory[0];
}

int Player::GetMonsterBallCount() const
{
    return inventory[1];
}

void Player::UsePotion(int& hp, int maxhp)
{
    if (inventory[0] <= 0)
    {
        cout << "상처약이 없습니다!\n";
        return;
    }

    if (hp >= maxhp)
    {
        cout << "이미 체력이 가득 찼습니다!\n";
        return;
    }

    inventory[0]--;

    hp += 20;

    if (hp > maxhp)
        hp = maxhp;

    cout << "상처약 사용! 현재 HP: " << hp << "/" << maxhp << "\n";
}

bool Player::UseMonsterBall()
{
    if (inventory[1] <= 0)
    {
        cout << "몬스터볼이 없습니다!\n";
        return false;
    }

    inventory[1]--;

    cout << "몬스터볼 사용! 남은 개수: " << inventory[1] << "\n";

    return true;
}

void Player::PrintInventory() const
{
    cout << "\n[인벤토리]\n";
    cout << "상처약: " << inventory[0] << "\n";
    cout << "몬스터볼: " << inventory[1] << "\n";
}
#include "Player.h"

Player::Player()
{
    inventory[0] = 3; // 상처약
    inventory[1] = 5; // 몬스터볼
}

void Player::PlayerMove() const
{
    string playermove;
    while (true)
    {
        int r = rand() % 10+1;
        
        cout << "이동 입력: 위 아래 이동 : W S ,"<<"\n";
        cout << "이동 입력: 좌  우 이동 : A D ,"<<"\n";
        cin >> playermove;
        if (playermove == "W"||playermove == "S"||playermove == "D"||playermove == "A")
        {
            if (r>=2)
            {
                cout << playermove << "를 선택하였습니다!  "<<r<<"  \n";
                break;
            }
            else
            {
                cout << playermove << "를 선택하였습니다!  "<<r<<"  \n";
            }   
        }
        else
        {
            cout << "이동 을 정상적으로 입력해주세요 ,"<<"\n";
        }
    }
}


int Player::GetPotionCount() const
{
    return inventory[0];
}

int Player::GetMonsterBallCount() const
{
    return inventory[1];
}

bool Player::UsePotion()
{
    if (inventory[0] <= 0)
    {
        cout << "상처약이 없습니다!\n";
        return false;
    }

    inventory[0]--;

    cout << "상처약을 사용했습니다!\n";
    cout << "남은 상처약: " << inventory[0] << "개\n";

    return true;
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
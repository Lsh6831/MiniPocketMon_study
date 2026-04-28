#include "Battle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Battle::SelectAction()
{
    int action;

    cout << "\n행동을 선택하세요.\n";
    cout << "1. 기본 공격\n";
    cout << "2. 스킬 공격\n";
    cout << "3. 상처약 사용\n";
    cout << "4. 몬스터볼 던지기\n";
    cout << "선택: ";
    cin >> action;

    if (action < 1 || action > 4)
    {
        cout << "잘못 입력해서 기본 공격을 합니다.\n";
        action = 1;
    }

    return action;
}
void Battle::StartBattle(Player& player, Monster& playerMonster, Monster& enemy)
{
    while (true)
    {
        bool playerFirst;

        if (playerMonster.get_moving_speed() > enemy.get_moving_speed())
        {
            playerFirst = true;
        }
        else if (playerMonster.get_moving_speed() < enemy.get_moving_speed())
        {
            playerFirst = false;
        }
        else
        {
            playerFirst = rand() % 2;
        }

        if (playerFirst)
        {
            cout << "\n[플레이어 선공]\n";

            bool isCatchSuccess = PlayerAttack(player, playerMonster, enemy);

            if (isCatchSuccess)
            {
                cout << "\n전투 종료!\n";
                break;
            }

            if (enemy.get_hp() <= 0)
            {
                cout << "\n승리했습니다!\n";
                break;
            }

            cout << "\n[적 턴]\n";
            EnemyAttack(enemy, playerMonster);

            if (playerMonster.get_hp() <= 0)
            {
                cout << "\n패배했습니다!\n";
                break;
            }
        }
        else
        {
            cout << "\n[적 선공]\n";
            EnemyAttack(enemy, playerMonster);

            if (playerMonster.get_hp() <= 0)
            {
                cout << "\n패배했습니다!\n";
                break;
            }

            cout << "\n[플레이어 턴]\n";

            bool isCatchSuccess = PlayerAttack(player, playerMonster, enemy);

            if (isCatchSuccess)
            {
                cout << "\n전투 종료!\n";
                break;
            }

            if (enemy.get_hp() <= 0)
            {
                cout << "\n승리했습니다!\n";
                break;
            }
        }
    }
}
bool Battle::PlayerAttack(Player& player, Monster& playerMonster, Monster& enemy)
{
    int action = SelectAction();

    if (action == 1)
    {
        cout << "\n기본 공격!\n";

        enemy.TakeDamage(
       playerMonster.get_name(),
       "기본 공격",
       playerMonster.get_attack(),
       playerMonster.get_typecode(),
       enemy.get_defense(),
       enemy.get_typecode()
   );
    }
    else if (action == 2)
    {
        cout << "\n스킬 공격!\n";

        enemy.TakeDamage(
       playerMonster.get_name(),
       "스킬 공격",
       playerMonster.get_attack() + 3,
       playerMonster.get_typecode(),
       enemy.get_defense(),
       enemy.get_typecode()
   );
    }
    else if (action == 3)
    {
        if (player.UsePotion())
        {
            cout<<playerMonster.get_name()<<"이거 힐전\n";
            playerMonster.Heal(100);
        }
    }
    else if (action == 4)
    {
        if (TryCatch(player, enemy))
        {
            return true; // 포획 성공 → 전투 종료
        }
    }

    return false;
}

void Battle::EnemyAttack(Monster& enemy, Monster& playerMonster)
{
    int action = rand() % 2 + 1;

    if (action == 1)
    {
        cout << "\n적의 기본 공격!\n";

        playerMonster.TakeDamage(
     enemy.get_name(),           // 공격자 이름
     "기본 공격",
     enemy.get_attack(),
     enemy.get_typecode(),
     playerMonster.get_defense(),
     playerMonster.get_typecode()
 );
    }
    else
    {
        cout << "\n적의 스킬 공격!\n";

        playerMonster.TakeDamage(
     enemy.get_name(),           // 공격자 이름
    "스킬 공격",
     enemy.get_attack()+ 3,
     enemy.get_typecode(),
     playerMonster.get_defense(),
     playerMonster.get_typecode()
 );
    }
}

bool Battle::TryCatch(Player& player, Monster& enemy)
{
    if (!player.UseMonsterBall())
    {
        return false;
    }

    int hpPercent = enemy.get_hp() * 100 / enemy.get_maxhp();

    int catchRate = 20;

    if (hpPercent <= 25)
    {
        catchRate = 80;
    }
    else if (hpPercent <= 50)
    {
        catchRate = 50;
    }
    else if (hpPercent <= 75)
    {
        catchRate = 35;
    }

    int randomValue = rand() % 100 + 1;

    cout << "포획 확률: " << catchRate << "%\n";

    if (randomValue <= catchRate)
    {
        cout << "포획 성공!\n";
        return true;
    }

    cout << "포획 실패!\n";
    return false;
}


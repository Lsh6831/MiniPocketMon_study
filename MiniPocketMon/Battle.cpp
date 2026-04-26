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
    cout << "3. 몬스터볼 던지기\n";
    cout << "선택: ";
    cin >> action;

    if (action < 1 || action > 3)
    {
        cout << "잘못 입력해서 기본 공격을 합니다.\n";
        action = 1;
    }

    return action;
}

void Battle::PlayerAttack(Monster& player, Monster& enemy)
{
    int action = SelectAction();

    if (action == 1)
    {
        cout << "\n플레이어의 기본 공격!\n";

        enemy.TakeDamage(
            player.get_attack(),
            player.get_typecode(),
            enemy.get_defense(),
            enemy.get_typecode()
        );
    }
    else if (action == 2)
    {
        cout << "\n플레이어의 스킬 공격!\n";

        enemy.TakeDamage(
            player.get_attack() + 3,
            player.get_typecode(),
            enemy.get_defense(),
            enemy.get_typecode()
        );
    }
    else if (action == 3)
    {
        TryCatch(enemy);
    }
}

void Battle::EnemyAttack(Monster& enemy, Monster& player)
{
    int action = rand() % 2 + 1;

    if (action == 1)
    {
        cout << "\n적의 기본 공격!\n";

        player.TakeDamage(
            enemy.get_attack(),
            enemy.get_typecode(),
            player.get_defense(),
            player.get_typecode()
        );
    }
    else
    {
        cout << "\n적의 스킬 공격!\n";

        player.TakeDamage(
            enemy.get_attack() + 3,
            enemy.get_typecode(),
            player.get_defense(),
            player.get_typecode()
        );
    }
}
bool Battle::TryCatch(Monster& enemy)
{
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

    cout << "\n몬스터볼을 던졌다!\n";
    cout << "포획 확률: " << catchRate << "%\n";

    if (randomValue <= catchRate)
    {
        cout << "포획 성공!\n";
        return true;
    }
    else
    {
        cout << "포획 실패!\n";
        return false;
    }
}

void Battle::StartBattle(Monster& player, Monster& enemy)
{
    while (true)
    {
        bool playerFirst;

        if (player.get_moving_speed() > enemy.get_moving_speed())
        {
            playerFirst = true;
        }
        else if (player.get_moving_speed() < enemy.get_moving_speed())
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
            PlayerAttack(player, enemy);

            if (enemy.get_hp() <= 0)
            {
                cout << "\n승리했습니다!\n";
                break;
            }

            cout << "\n[적 턴]\n";
            EnemyAttack(enemy, player);

            if (player.get_hp() <= 0)
            {
                cout << "\n패배했습니다!\n";
                break;
            }
        }
        else
        {
            cout << "\n[적 선공]\n";
            EnemyAttack(enemy, player);

            if (player.get_hp() <= 0)
            {
                cout << "\n패배했습니다!\n";
                break;
            }

            cout << "\n[플레이어 턴]\n";
            PlayerAttack(player, enemy);

            if (enemy.get_hp() <= 0)
            {
                cout << "\n승리했습니다!\n";
                break;
            }
        }
    }
}
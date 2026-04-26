#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Player.h"
#include "Battle.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    cout << "=============================\n";
    cout << "      MONSTER BATTLE GAME    \n";
    cout << "=============================\n\n";

    Player player;

    cout << "몬스터를 선택하세요!\n\n";
    cout << "1. 파이리  [불]\n";
    cout << "2. 이상해씨  [풀]\n";
    cout << "3. 꼬부기    [물]\n";
    cout << "4. 파오리    [바람]\n\n";

    int choice;
    cout << "번호 입력: ";
    cin >> choice;

    Monster myMonster("파오리", 9, 8, 2, 7, 1, 4);

    if (choice == 1)
    {
        myMonster = Monster("파이리", 10, 7, 3, 4, 1, 1);
        cout << "\n파이리를 선택했습니다!\n";
    }
    else if (choice == 2)
    {
        myMonster = Monster("이상해씨", 12, 5, 4, 3, 1, 2);
        cout << "\n이상해씨를 선택했습니다!\n";
    }
    else if (choice == 3)
    {
        myMonster = Monster("꼬부기", 11, 6, 5, 2, 1, 3);
        cout << "\n꼬부기를 선택했습니다!\n";
    }
    else if (choice == 4)
    {
        myMonster = Monster("파오리", 9, 8, 2, 7, 1, 4);
        cout << "\n파오리를 선택했습니다!\n";
    }
    else
    {
        cout << "\n잘못 입력해서 기본 몬스터 파오리로 시작합니다.\n";
        myMonster = Monster("파오리", 9, 8, 2, 7, 1, 4);
    }

    Monster enemy("기본 적", 10, 7, 3, 4, 1, 1);

    int enemyType = rand() % 4 + 1;

    if (enemyType == 1)
    {
        enemy = Monster("야생 파이리", 10, 7, 3, 4, 1, 1);
        cout << "\n야생 파이리가 나타났다!\n";
    }
    else if (enemyType == 2)
    {
        enemy = Monster("야생 이상해씨", 12, 5, 4, 3, 1, 2);
        cout << "\n야생 이상해씨가 나타났다!\n";
    }
    else if (enemyType == 3)
    {
        enemy = Monster("야생 꼬부기", 11, 6, 5, 2, 1, 3);
        cout << "\n야생 꼬부기가 나타났다!\n";
    }
    else
    {
        enemy = Monster("야생 파오리", 9, 8, 2, 7, 1, 4);
        cout << "\n야생 파오리가 나타났다!\n";
    }

    player.PrintInventory();

    // 🔥 전투 시작
    Battle battle;
    battle.StartBattle(player, myMonster, enemy);

    return 0;
}
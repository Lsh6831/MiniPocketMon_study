#include <iostream>
#include "Monster.h"
#include "Battle.h"
#include <cstdlib> 
#include <ctime>
using namespace std;

int main()
{
    //매번 다른 랜덤값 생성됨
    srand((unsigned int)time(NULL));
    

    cout << "=============================\n";
    cout << "      MONSTER BATTLE GAME    \n";
    cout << "=============================\n\n";

    cout << "몬스터를 선택하세요!\n\n";
    cout << "1. 파이리  [불]\n";
    cout << "2. 이상해씨  [풀]\n";
    cout << "3. 꼬부기    [물]\n";
    cout << "4. 파오리    [바람]\n\n";

    int choice;
    cout << "번호 입력: ";
    cin >> choice;

    Monster player(10, 5, 3, 2, 1, 1);

    if (choice == 1)
    {
        player = Monster(10, 7, 3, 4, 1, 1);
        cout << "\n파이리를 선택했습니다!\n";
    }
    else if (choice == 2)
    {
        player = Monster(12, 5, 4, 3, 1, 2);
        cout << "\n이상해씨 선택했습니다!\n";
    }
    else if (choice == 3)
    {
        player = Monster(11, 6, 5, 2, 1, 3);
        cout << "\n꼬부기를 선택했습니다!\n";
    }
    else if (choice == 4)
    {
        player = Monster(9, 8, 2, 7, 1, 4);
        cout << "\n파오리를 선택했습니다!\n";
    }
    else
    {
        cout << "\n잘못 입력해서 기본 몬스터 파오리로 시작합니다.\n";
        player = Monster(9, 6, 2, 7, 1, 4);
    }

    cout << "\n===== 선택한 몬스터 정보 =====\n";
    cout << "HP: " << player.get_hp() << " / " << player.get_maxhp() << "\n";
    cout << "공격력: " << player.get_attack() << "\n";
    cout << "방어력: " << player.get_defense() << "\n";
    cout << "속도: " << player.get_moving_speed() << "\n";
    cout << "속성 코드: " << player.get_typecode() << "\n";

    cout << "\n전투를 시작합니다!\n";

    // 적 몬스터 생성
    Monster enemy(10, 7, 3, 4, 1, 1);

    int enemyType = rand() % 4 + 1;

    if (enemyType == 1)
    {
        enemy = Monster(10, 7, 3, 4, 1, 1);
        cout << "\n야생 파이리가 나타났다!\n";
    }
    else if (enemyType == 2)
    {
        enemy = Monster(12, 5, 4, 3, 1, 2);
        cout << "\n야생 이상해씨가 나타났다!\n";
    }
    else if (enemyType == 3)
    {
        enemy = Monster(11, 6, 5, 2, 1, 3);
        cout << "\n야생 꼬부기가 나타났다!\n";
    }
    else
    {
        enemy = Monster(9, 8, 2, 7, 1, 4);
        cout << "\n야생 파오리가 나타났다!\n";
    }

    Battle battle;
    battle.StartBattle(player, enemy);

    return 0;
}
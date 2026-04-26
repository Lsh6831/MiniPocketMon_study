#include <iostream>
#include <cstdlib>
#include <ctime>
#include  <vector>
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
    
    vector<Monster> monsters = {
        Monster("파이리", 10, 7, 3, 4, 1, 1),
        Monster("이상해씨", 12, 5, 4, 3, 1, 2),
        Monster("꼬부기", 11, 6, 5, 2, 1, 3),
        Monster("파오리", 9, 8, 2, 7, 1, 4)
    };
    
    cout << "몬스터를 선택하세요!\n\n";

    for (int i = 0; i < monsters.size(); i++)
    {
        cout << i + 1 << ". " << monsters[i].get_name() << "\n";
    }

    int choice;
    cout << "번호 입력: ";
    cin >> choice;

    Monster myMonster = monsters[0];

    int enemyIndex = rand() % monsters.size();
    Monster enemy = monsters[enemyIndex];

    cout << "\n야생 " << enemy.get_name() << "이(가) 나타났다!\n";

    player.PrintInventory();

    Battle battle;
    battle.StartBattle(player, myMonster, enemy);

    return 0;
}
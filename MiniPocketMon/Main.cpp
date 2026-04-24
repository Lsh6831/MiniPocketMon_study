#include <iostream>
#include "Monster.h"
using namespace std;
#include <cstdlib>
#include <ctime>

int main()
{
    srand((unsigned int)time(NULL));
    
    //몬스터잠시 예시  
    Monster monster(10,10,10,10,1,1);
    
    monster.TakeDamage(10,1,2,2);
}
#include <iostream>
#include "Monster.h"
using namespace std;


int main()
{
    Monster monster(10,10,10,10,1,1);
    cout<<"hi";
    
    monster.TakeDamage(10,1,2,2);
}
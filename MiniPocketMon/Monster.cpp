#include "Monster.h"
#include <string> 
#include <iostream>

Monster::Monster(string name, int eng, int att, int def, int spe, int lv, int typ)
    : name(name),energy(eng), attack(att), defense(def), movingSpeed(spe), level(lv), typecode(typ) 
{
    maxhp = energy*10;
    hp = maxhp;
}


void Monster::TakeDamage(string attackerName, string attackName, int attack, int skilltype, int defender_def, int defender_type)
{
    //typecode
    //1.FIRE 2.GRASS 3.WATER 4.WIND 
    float typeDamage = 1.0f;
    
    if (skilltype == 1 && defender_type == 2) typeDamage = 2.0f;
    if (skilltype == 1 && defender_type == 3) typeDamage = 0.5f;

    if (skilltype == 3 && defender_type == 1) typeDamage = 2.0f;
    if (skilltype == 3 && defender_type == 2) typeDamage = 0.5f;

    if (skilltype == 2 && defender_type == 3) typeDamage = 2.0f;
    if (skilltype == 2 && defender_type == 1) typeDamage = 0.5f;
    
    int critical_Chance = rand() % 11 + 1;
    
    int critical=1;
    
    if (critical_Chance==11) critical=2;
    
    float damage=attack*typeDamage*critical-defender_def;
    hp-=damage;
    
    if (typeDamage == 2.0f)
    {
        cout << "효과는 굉장했다!\n";
    }
    else if (typeDamage == 0.5f)
    {
        cout << "효과가 별로인 듯하다...\n";
    }

    if (critical == 2)
    {
        cout << "급소에 맞았다!\n";
    }

    cout << name << " HP: " << hp << " / " << maxhp << "\n";
    
}
void Monster::Heal(int amount)
{
    hp += amount;

    if (hp > maxhp)
    {
        hp = maxhp;
    }

    cout << name << "의 HP가 " << amount << " 회복되었습니다!\n";
    cout << name << " HP: " << hp << " / " << maxhp << "\n";
}
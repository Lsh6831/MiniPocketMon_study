#include "Monster.h"
#include <string> 
#include <iostream>

Monster::Monster(int eng, int att, int def, int spe, int lv, int typ)
    : energy(eng), attack(att), defense(def), movingSpeed(spe), level(lv), typecode(typ) 
{
    maxhp = energy*10;
    hp = maxhp;
}


void Monster::TakeDamage(int attack,int skiiltype,int deffender_def,int deffender_type)
{
    //typecode
    //1.FIRE 2.GRASS 3.WATER 4.WIND 
    float typedamage=1.0f;
    
        if ( skiiltype == 1 && deffender_type == 2) typedamage=2.0f;
        if ( skiiltype == 1 && deffender_type == 3) typedamage=0.5f;

        if ( skiiltype == 3 && deffender_type == 1) typedamage=2.0f;
        if ( skiiltype == 3 && deffender_type == 2) typedamage= 0.5f;

        if ( skiiltype == 2 && deffender_type == 3) typedamage= 2.0f;
        if ( skiiltype == 2 && deffender_type == 1) typedamage= 0.5f;

        if ( skiiltype == 4 && deffender_type == 2) typedamage=2.0f;
        if ( skiiltype == 4 && deffender_type == 1) typedamage=0.5f;
    
    int critical_Chance = rand() % 10 + 1;
    
    int critical=1;
    
    if (critical_Chance==10) critical=2;
    
    float damage=attack*typedamage*critical-deffender_def;
    hp-=damage;
    
    cout << "damage=" << damage <<"HP"<< hp <<"critical_Chance"<< critical_Chance<<"\n";
    
    cout << "damage=" << damage <<"HP"<< hp <<"critical_Chance"<< critical_Chance<<"\n";
}
#pragma once
#include  <string>
using namespace std;

class Monster
{
protected://기본 능력치(스테이터스)
    
    string name;
    int energy,attack,defense,movingSpeed;// 파생 능력치
    int level;
    int hp,maxhp;
    ;int typecode;
    
public:
    Monster(string name, int eng, int att, int def, int spe, int lv = 1, int typ = 1);
    
    string get_name() const { return name; }
    
    int get_energy() const{return energy;}

    int get_attack() const { return attack;}

    int get_defense() const { return defense;}

    int get_level() const { return level;}

    int get_hp() const{ return hp;}

    int get_maxhp() const{ return maxhp;}

    double get_moving_speed() const{ return movingSpeed;}

    int get_typecode() const{ return typecode;}
    
    
    void TakeDamage(string attackerName, string attackName, int attack, int skilltype, int defender_def, int defender_type);

};

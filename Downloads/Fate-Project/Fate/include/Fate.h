#ifndef FATE_H
#define FATE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Fate
{
    public:
        Fate(string);
        void initi();
        void printing(string);
        void roleSelect();
        void creating();
        void checkNumRandom();
        void checkpoint_1();
        void checkpoint_2();
        void checkpoint_3();
        void checkpoint_4();
        void checkpoint_5();
        void checkpoint_6();
        void battle();
        void fight();
        void monster_dead();
        void monster_fight();
        void randomFate();
        void event_change_HP(int);
        void role_dead();
        void event_change_DPS(int); ///Overload
        void reborn();
        void outputScore();
        void god();

//========== ==============
        void skillSelect();
        void hunter();
        void mage();
        void Drvid();
        void Warlock();
        int skillIndex;
        int energy;
        void skillRelease();
        void cheating(int code){
            cheatCode = code;
        }
        friend int cheatingFun(Fate &C); ///Friend function


       // int monsterIndex;
        int gold;
        int score;
        int rabbit;
        int cnt_1,cnt_2,cnt_3;
        int survial[3];
        int role;
        int level;
        int checkNum;
        string choice_correct;
        string role_array[9];
        string monster_array[9];
        int team[2];
        string playerName;
        string choice;


        ~Fate();

    private:
        int cheatCode;

};



class Skill:public Fate
{
public:
    int cjj;
    int ckk;
    void eating();
    void killmonster();
    void event_change_DPS(int);///Overload
};

class Boss
{
public:
    class TobinanSkill{    ///nested class
    public:
        void bigband();
        void deathVoice();
        void reborn();
    };
    class BossSkill:public TobinanSkill{
    public:
        void bigband();
        void deathVoice();
        void reborn();
        void aggressive();
    };
};






#endif // FATE_H

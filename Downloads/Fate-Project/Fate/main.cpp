#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Fate.h"


using namespace std;

int main()
{
    cout<<"Welcome to the Fate! The Fade is a text based RPG and a little RTS elements games."<<endl;
    cout<<"Most elements in the game is create by system randomly. So the Luck is important!"<<endl;
    string space;
    string playerName;
    cout<<"Now please tell me your name: "<<endl;
    cin>>playerName;
    Fate cjj(playerName);
    //Skill ckk();
    cjj.initi();
    cjj.printing(playerName);
    cjj.roleSelect();
    cjj.skillSelect();

    cout<<"Enter anything to continuous"<<endl;
    cin>>space;

    cjj.creating();
    cjj.checkNumRandom();
    cjj.randomFate();



}


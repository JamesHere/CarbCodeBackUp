#include "Fate.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

Fate myfate("false")

Fate::Fate(string c)
{
    choiche_correct = c;
    //ctor
}

Fate::~Fate()
{
    //dtor
}

int cheatingFun(Fate &C){

    return C.cheatCode;
}
void Fate::outputScore(){
FILE *fp = fopen("Adventure.txt","w");

fprintf(fp,"Game finish! Hope you enjoy!\nAuthor:James Chen\nCSCI-1310--Project1\nGame name: Fate");

cout<<"The game description file created!"<<endl;

}

void Fate::god(){
cout<<"You will fight with the powerful BOSS\nGet Ready!"<<endl;
cout<<"You receive 5 HP,1 damage and 2 energy"<<endl;
event_change_DPS(1);
event_change_HP(5);
energy+=2;
cout<<"Current energy: "<<energy<<endl;
 level = 0;
        monster_array[0] = "5";
        monster_array[1] = "Fear King";
        monster_array[2] = "20";
        battle();
        cout<<"Type 1 to attack!"<<endl;
        while(atoi(monster_array[2].c_str())>0){
        fight();
        monster_dead();
        monster_fight();

        battle();

        skillRelease();
        cout<<"Round finish,situation below:"<<endl;
        if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())<=0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        battle();
        if(atoi(monster_array[2].c_str())>0){cout<<"Type 1 to attack!"<<endl;}

    }
    cout<<"You win this battle\n final situation below"<<endl;
    battle();
    cout<<"UNLOCK ACHIVEMENT!  <Hight Level>"<<endl;
    cout<<"You are leaving this place..."<<endl;
    randomFate();
    }







void Fate::reborn(){
cout<<"Now, you are reborn "<<playerName<<" everything start from zero"<<endl;
cout<<"Your role will not change unless you restart the game"<<endl;
for(int i =0;i<9;i++){
    monster_array[i] = "0";
}
for(int i=0;i<3;i++){
    survial[i]=0;
}
team[0] = 0;
team[1] = 0;
choice_correct ="F";
rabbit = 0;
gold = 10;
energy = 1;
checkNum = -1;
creating();
cout<<"Good Luck! \n\n\n\n\n"<<endl;
randomFate();

}

void Fate::initi(){
for(int i =0;i<9;i++){
    monster_array[i] = "0";
}
for(int i =0;i<9;i++){
    role_array[i] = "0";
}
for(int i=0;i<3;i++){
    survial[i]=0;
}
team[0] = 0;
team[1] = 0;
choice_correct ="F";
rabbit = 0;
gold = 10;
energy = 1;
checkNum = -1;
}
//===============================
void Fate::skillSelect(){

    if(role==1){skillIndex = 1;}
    if(role==2){skillIndex = 2;}
    if(role==3){skillIndex = 3;}
    if(role==5){skillIndex = 5;}
}

//============================
void Fate::role_dead(){
    if(atoi(role_array[2].c_str())<=0){
        cout<<"You have been defeat!"<<endl;
        cout<<"\nGame over"<<endl;
        cout<<"Do you want to reborn?"<<endl;
        cout<<"1:Reborn\n2:Exit the adventure"<<endl;
        string born;
        cin>>born;
        while(born != "1" and born != "2"){
            cout<<"Please enter the correct number"<<endl;
        }
        if(born == "1"){reborn();}
        if(born == "2"){
                cout<<"You have survived for "<<checkNum<<" checkpoints!"<<endl;
                outputScore();
                exit(0);}
    }
}

//==================================
void Fate::event_change_HP(int HPchange){
        stringstream ss;
        int event = atoi(role_array[2].c_str())+HPchange;
        ss<<event;
        ss>>role_array[2];
        cout<<"Current HP: "<<role_array[2]<<endl;
        role_dead();

}
//=================================
void Fate::event_change_DPS(int DPS){
        stringstream ss;
        int event = atoi(role_array[0].c_str())+DPS;
        ss<<event;
        ss>>role_array[0];
        cout<<"Current damage: "<<role_array[0]<<endl;
}

//=================================

void Fate::randomFate(){
    checkNum++;
    for(int i =0;i<9;i++){
    monster_array[i] = "0";
}
    for(int i=0;i<3;i++){
    survial[i]=0;
}
    cout<<"\n\nYou enter the place of period. Fate will lead you\nBy go through the Portal, you will sent to different world.Bless you hero.\n\n"<<endl;
    cout<<"You have chance to challenge the Fear King(Very strong!)\n Type (boss) to enter\nType exit to quit the adventure\nType other things to continuous adventure"<<endl;
    string godchoice;
    cin>>godchoice;
    if(godchoice == "boss"){
        god();
    }
    else if(godchoice == "exit"){
            cout<<"You have survived for "<<checkNum<<" checkpoints!"<<endl;
                outputScore();
                exit(0);}


    else{cout<<"You give up the chance"<<endl;}
    cout<<"Now, type anything to go through the random portal"<<endl;
    string x;
    cin>>x;
    int checkpointNum;
    checkpointNum = (rand() % (6));
    //checkpointNum = 2;

    if(checkpointNum == 1){
        checkpoint_1();
    }
    if(checkpointNum == 2){
        checkpoint_2();
    }
    if(checkpointNum == 3){
        checkpoint_3();
    }
    if(checkpointNum == 4){
        checkpoint_4();
    }
    if(checkpointNum == 5){
        checkpoint_5();
    }
    if(checkpointNum == 6){
        checkpoint_6();
    }
}

void Fate::printing(string p){

    cout<<"Welcome! "<<p<<endl;
    playerName = p;
}



void Fate::roleSelect(){

    char a = playerName[0];
    if(a =='J' or a=='K' or a=='C' or a == 'B' or a=='R'){
        cout<<"\nEn..... You are a Hunter ! \nHunter is usual but powerful! Your unique skill can create extra damage.\n"<<endl;
        cout<<"Your skill is Arcane shooting. It can create 2 damage to any enemies"<<endl;
        role = 1;

    }
    else if(a=='Q' or a=='V' or a=='N' or a=='D' or a=='F' or a == 'P'){
        cout<<"\nEn.....You are a Mage ! \nMage control the deadly magical skill that can get buff\n "<<endl;
        cout<<"Your skill is Arcane Explosion"<<endl;
        role = 2;

    }
    else if(a=='W' or a=='E' or a=='T' or a=='Y' or a=='O'or a=='L'){
        cout<<"\nEn.....You are a Drvid ! \nDrvid control the nature power that can heeling yourself\n"<<endl;
        cout<<"Your skill is Rejuvenation. It can increase 3 HP to yourselves"<<endl;
        role = 3;

    }
    else if(a=='@'){
        cout<<"\nAHA! you are a Demon Hunter! How did you get this secret code? You must see my project's description~"<<endl;
        role =4;
    }
    else{
        cout<<"\nEn......You are a Warlock ! \nWarlock's power and energy is from demon which you can transfer your HP to attack\n "<<endl;
        cout<<"Your skill is Evasion. It can transfer your 2 HP into 1 damage"<<endl;
        role =5;

    }


}
void Fate::creating(){
    if(role == 1){
        role_array[0] ="3";
        role_array[1] = "Hunter-"+playerName;
        role_array[2] = "20";
        cout<<"Here is battle field,you can see your role. \nThe number on the left is attack and the number on the right is your HP.\n"<<endl;
        cout<<"============================================================================\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }


 if(role == 2){
        role_array[0] ="4";
        role_array[1] = "Mage-"+playerName;
        role_array[2] = "18";
        cout<<"Here is battle field,you can see your role. \nThe number on the left is attack and the number on the right is your HP.\n"<<endl;
        cout<<"============================================================================\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
 if(role == 3){
        role_array[0] ="2";
        role_array[1] = "Drvid-"+playerName;
        role_array[2] = "20";
        cout<<"Here is battle field,you can see your role. \nThe number on the left is attack and the number on the right is your HP.\n"<<endl;
        cout<<"============================================================================\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
if(role == 4){
        role_array[0] ="20";
        role_array[1] = "Demon Hunter-"+playerName;
        role_array[2] = "150";
        cout<<"Here is battle field,you can see your role. \nThe number on the left is attack and the number on the right is your HP.\n"<<endl;
        cout<<"============================================================================\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
if(role == 5){
        role_array[0] ="1";
        role_array[1] = "Warlock-"+playerName;
        role_array[2] = "25";
        cout<<"Here is battle field,you can see your role. \nThe number on the left is attack and the number on the right is your HP.\n"<<endl;
        cout<<"============================================================================\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
}

void Fate::checkNumRandom(){

    cout<<"\n\n\n===============================NOW, GAME ON============================================\n\n\n";

}

void Fate::checkpoint_1(){
    cout<<"-------------------World:Lost Forest-------------------\n"<<endl;
    cnt_1 = 0;
    cnt_2 = 0;
    cnt_3 = 0;
    level = (rand() % (3));
    //level = 2;
    cout<<"You enter the lost forest..This is the den of Orcs"<<endl;
    cout<< "and you decide....\n 1:Go straight\n 2:Bypass "<<endl;
    string choice_2;
    cin>>choice_2;
    while(choice_2 != "1" and choice_2 != "2"){
        cout<<"Please enter the correct number"<<endl;
        cin>>choice_2;
    }
    if(choice_2 =="2"){
        cout<<"You find a treasure! HP+5"<<endl;
        event_change_HP(5);
        cout<<"Current HP: "<<role_array[2]<<endl;
        randomFate();

    }

    if(choice_2=="1"){
    cout<<"You trapped! The Orcs find you!"<<endl;
    monster_array[0] = "2";
    monster_array[1] = "ORC Warrior";
    monster_array[2] = "5";
    if(level >0){
    monster_array[3] = "2";
    monster_array[4] = "ORC Mage";
    monster_array[5] = "8";
    }
    if(level == 2){
    monster_array[6] = "2";
    monster_array[7] = "ORC Warrior";
    monster_array[8] = "5";
    }

    battle();
    cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;

    while(atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0){
        fight();
        monster_dead();
        monster_fight();
        battle();


        if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())==0 or atoi(monster_array[2].c_str())<0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        if((level == 1  and cnt_2 == 0) or (level == 2 and cnt_2 == 0)){
        if(atoi(monster_array[5].c_str())==0 or atoi(monster_array[5].c_str())<0 ){
            cout<<monster_array[4]<<" has been defeat!\n"<<endl;
            monster_array[3] = "0";
            monster_array[4] = "☠";
            monster_array[5] = "0";
            survial[1] =1;
            cnt_2 = 1;
            battle();
        }
        }
        if(level == 2 and cnt_3 == 0){
        if(atoi(monster_array[8].c_str())==0 or atoi(monster_array[8].c_str())<0){
            cout<<monster_array[7]<<" 3has been defeat!\n"<<endl;
            monster_array[6] = "0";
            monster_array[7] = "☠";
            monster_array[8] = "0";
            survial[2] =1;
            cnt_3 = 1;
            battle();
        }
        }
        skillRelease();
        monster_dead();
        cout<<"Round finish,situation below:"<<endl;
        battle();


        if((atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0 ) and rabbit == 0){
        cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;

        }
    }
    cout<<"Final situation:\n"<<endl;
    battle();
    cout<<"You win this battle! Press anything to continuous..."<<endl;
    cout<<"You are leaving this place..."<<endl;
    randomFate();
    }
}
//=========================checkpoint2=====================
void Fate::checkpoint_2(){
    cout<<"-------------------------------------Paranoid Temple----------------------------------"<<endl;
    cnt_1 = 0;
    cout<<"You enter into a...weird temple. There is nothing here.\nSuddenly, there jump out a creepy guy."<<endl;
    cout<<"Greeting! traveller. Do you want to play a game?\nIf you wind, you can get award, else.....hahahahaha."<<endl;
    cout<<"1:Play\n2:leave"<<endl;
    string choice_2;
    int choice_3;
    cin>>choice_2;
    while(choice_2!="1" and choice_2!="2"){
        cout<<"Please enter a correct number"<<endl;
        cin>>choice_2;
    }
    if(choice_2 == "1"){
        int event = (rand() % (8));
        cout<<"\nThat's a good decision!\nNow,you need to guess a number from 0~7. Yes, guess~~"<<endl;
        cin>>choice_3;
        while(choice_3>7 or choice_3<0){
            cout<<"Please enter a correct number"<<endl;
            cin>>choice_3;
        }
        while(choice_3 != event){
        if(choice_3>event){
            cout<<"HIHI~ Too big!!!\nYou lose 2 HP"<<endl;
            event_change_HP(-2);
            role_dead();
            cin>>choice_3;
        }
        if(choice_3<event){
            cout<<"HIHI~Too small!!!\nYou lose 2 HP"<<endl;
            event_change_HP(-2);
            role_dead();
            cin>>choice_3;
        }
        }
        cout<<"\nOHAHAH~~~That's funny. Now that's you deserve!"<<endl;
        cout<<"You receive 2 golds"<<endl;
        gold+=2;
        cout<<"Current golds: "<<gold<<endl;
        randomFate();

    }else if(choice_2 == "2"){
        cout<<"Ok,okok,You will pay~\n Creepy man grab his weapon\n"<<endl;
        level = 0;
        monster_array[0] = "2";
        monster_array[1] = "Paranoid King";
        monster_array[2] = "10";
        battle();
        cout<<"Type 1 to attack!"<<endl;
        while(atoi(monster_array[2].c_str())>0){
        fight();
        monster_dead();
        monster_fight();

        battle();
     /*   if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())<=0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }*/
        skillRelease();
        cout<<"Round finish,situation below:"<<endl;
        if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())<=0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        battle();
        if(atoi(monster_array[2].c_str())>0){cout<<"Type 1 to attack!"<<endl;}

    }
    cout<<"You win this battle\n final situation below"<<endl;
    battle();
    cout<<"You find 8 gold in body"<<endl;
    gold+=8;
    cout<<"Current Golds: "<<gold<<endl;
    }
    cout<<"You are leaving this place..."<<endl;
    randomFate();
}

//====================================checkpoint3===============================
void Fate::checkpoint_3(){
    cnt_1 = 0;
    cout<<"----------------------------Absurd Circus -----------------------------"<<endl;
    cout<<"You enter into a Circus. There are a lot of creepy joker here..you decide:"<<endl;
    cout<<"1:Enter\n2:Leave"<<endl;
    string eventChoice;
    cin>>eventChoice;
    while(eventChoice != "1" and eventChoice != "2"){
        cout<<"Please enter the correct number"<<endl;
        cin>>eventChoice;
    }
    if(eventChoice == "2"){
        cout<<"There comes a joker and block the way out\nHey~Why not play a game?\n1:Just leave\n2:Play game"<<endl;
        string eventChoice_2;
        cin>>eventChoice_2;
    while(eventChoice != "1" and eventChoice != "2"){
        cout<<"Please enter the correct number"<<endl;
        cin>>eventChoice_2;
    }
    if(eventChoice_2 == "1"){
        cout<<"You take out your weapon and threaten him.\nBut suddenly you find there are many booms stick on your body! instead of weapon"<<endl;
        cout<<"Don't you get it? I am in charge now!\n one boom explosion and you receive 1 damage"<<endl;
        event_change_HP(-1);
        string space;
        cout<<"Press anything to continuous"<<endl;
        cin>>space;
        eventChoice_2 = "2";
    }
    if(eventChoice_2 == "2"){
        cout<<"You start playing game;\nOk,now you can use shield,sward and magic! \nI will use one of those too;\nThe sword can defeat the magic;\nThe magic can defeat the shield;\nThe shield can defeat the sword;"<<endl;
        cout<<"Get it? We play 3 round! Let's get start!\n1:sword\n2:shield\n3:magic"<<endl;
        string game;
        cin>>game;
        int opponent = 1;

        while(opponent<4){
            while(game != "1" and game!= "2" and game != "3"){
                cout<<"Please  enter the correct number"<<endl;
                cin>>game;
            }

            if(game == "1" and opponent == 1){cout<<"The joker use the sword and you use the sword\nDraw! again! again! again! hihi~"<<endl;
            opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }
            if(game == "1" and opponent == 2){cout<<"The joker use the shield and you use the sword\nYou lose! hihi~"<<endl;
                cout<<"The boom explosion and you lose 1 HP"<<endl;
                event_change_HP(-1);
                opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
                }
            if(game == "1" and opponent == 3){cout<<"The joker use the magic and you use the sword\nNot bad! you win hihi~"<<endl;
            opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }

                }
//====================
            if(game == "2" and opponent == 1){cout<<"The joker use the sword and you use the shield\nNot bad! you win hihi~"<<endl;
            opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }
            if(game == "2" and opponent == 2){cout<<"The joker use the shield and you use the shield\nDraw! again! again! again! hihi~"<<endl;
            opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }
            if(game == "2" and opponent == 3){cout<<"The joker use the magic and you use the shield\nYou lose! hihi~"<<endl;
            cout<<"The boom explosion and you lose 1 HP"<<endl;
                event_change_HP(-1);
                opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
                }

 //=======================
            if(game == "3" and opponent == 1){cout<<"The joker use the sword and you use the magic\nYou lose! hihi~"<<endl;
            cout<<"The boom explosion and you lose 1 HP"<<endl;
                event_change_HP(-1);
                opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }

            if(game == "3" and opponent == 2){cout<<"The joker use the shield and you use the magic\nNot bad! you win hihi~"<<endl;
            opponent++;
            if(opponent != 3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }
            if(game == "3" and opponent == 3){cout<<"The joker use the magic and you use the magic\nDraw! again! again! again! hihi~"<<endl;
            opponent++;
            if(opponent!=3){
            cout<<"Next round! Chose!"<<endl;
            cin>>choice;
            }
            }



        }
        cout<<"Thank you! Game finish, it's time to go!\n Suddenly, all booms in your body are explosion!\nYou receive 5 damage!"<<endl;
        event_change_HP(-5);
        cout<<"You are leaving this place..."<<endl;
        randomFate();

    }
    }
    if(eventChoice == "1"){
        cout<<"You enter inside and there are a lot of fun stuff here"<<endl;
        cout<<"Just when you at the happy time. A fire swept through here.\nAlthough you try to avoid that, you still get burned  "<<endl;
        cout<<"You lose 3 HP"<<endl;
        event_change_HP(-2);
        cout<<"And then you jump in the river but.....er There is a giant monster\n Get ready for the fight!"<<endl;
        level = 0;
        monster_array[0] = "1";
        monster_array[1] = "Anacondas of Abyss";
        monster_array[2] = "15";
        battle();
        cout<<"Type 1 to attack!"<<endl;
        while(atoi(monster_array[2].c_str())>0){
        fight();
        monster_dead();
        monster_fight();

        battle();
        if(cnt_1 ==0){
        if(atoi(monster_array[2].c_str())==0 or atoi(monster_array[2].c_str())<0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        }
        skillRelease();
        cout<<"Round finish,situation below:"<<endl;
        battle();
        if(atoi(monster_array[2].c_str())>0){cout<<"Type 1 to attack!"<<endl;}

    }
    cout<<"You win this battle\nfinal situation below:"<<endl;
    battle();
    cout<<"You absorb the energy from the monster. Energy + 2!"<<endl;
    energy+=2;
    cout<<"Current energy: "<<energy<<endl;
    cout<<"You are leaving this place"<<endl;
    randomFate();
    }
//==================================checkpoint4=============================
void Fate::checkpoint_4(){
cout<<"-------------------------------------The River of Life--------------------------------------"<<endl;
cout<<"You enter into a beautiful place! The famous rive of life is in here.\nYou receive 5 HP"<<endl;
event_change_HP(5);
cout<<"There comes a man\nGreeting! sir, My name is James, a business man here.\nI can help you recovery HP and energy, but all these are expensive"<<endl;
cout<<"1:1 HP-(1)golds\n2:1 energy-(2)golds\n3:leave"<<endl;
cout<<"Current golds: "<<gold<<endl;
string buychoice;
cin>>buychoice;
while(buychoice!="1" and buychoice!="2"and buychoice!="3"){
    cout<<"Please enter the correct number"<<endl;
    cin>>buychoice;
}
while(buychoice != "3"){
if(buychoice=="1"){
    if(gold<1){
        cout<<"You don't have enough golds"<<endl;
        cout<<"Anything else?"<<endl;
        cin>>buychoice;
    }
    if(gold>=1){
        cout<<"You buy 1 HP"<<endl;
        event_change_HP(1);
        gold-=1;
        cout<<"Current golds: "<<gold<<endl;
        cout<<"Anything else?"<<endl;
        cin>>buychoice;
    }
}
if(buychoice=="2"){
    if(gold<2){
        cout<<"You don't have enough golds"<<endl;
        cout<<"Anything else?"<<endl;
        cin>>buychoice;
    }
    if(gold>=2){
        cout<<"You buy 1 energy"<<endl;
        energy++;
        cout<<"Current energy: "<<energy<<endl;
        gold-=2;
        cout<<"Current golds: "<<gold<<endl;
        cout<<"Anything else?"<<endl;
        cin>>buychoice;
    }

}
}
cout<<"Thank you! Good Luck with your adventure!"<<endl;
cout<<"You are leaving this place"<<endl;
randomFate();
}
//==========================================checkpoint5==============================
void Fate::checkpoint_5(){
    cnt_1 == 0;
    cnt_2 == 0;
    cnt_3 == 0;
    cout<<"------------------------------------IronForge----------------------------------"<<endl;
    cout<<"It is very hot here.It only have rock, lava everywhere and....monster?"<<endl;
    cout<<"Get ready for fight\ntype anything to continuous"<<endl;
    string space;
    cin>>space;
    level =2;
            monster_array[0] = "3";
            monster_array[1] = "Lava scorpion ";
            monster_array[2] = "3";
            monster_array[3] = "3";
            monster_array[4] = "Lava scorpion ";
            monster_array[5] = "3";
            monster_array[6] = "3";
            monster_array[7] = "Lava scorpion ";
            monster_array[8] = "3";
            battle();
            cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;
    while(atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0){
        fight();
        cout<<"After fight"<<endl;
        monster_dead();
        monster_fight();
        battle();
        if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())==0 or atoi(monster_array[2].c_str())<0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        if((level == 1  and cnt_2 == 0) or (level == 2 and cnt_2 == 0)){
        if(atoi(monster_array[5].c_str())==0 or atoi(monster_array[5].c_str())<0 ){
            cout<<monster_array[4]<<" has been defeat!\n"<<endl;
            monster_array[3] = "0";
            monster_array[4] = "☠";
            monster_array[5] = "0";
            survial[1] =1;
            cnt_2 = 1;
            battle();
        }
        }
        if(level == 2 and cnt_3 == 0){
        if(atoi(monster_array[8].c_str())==0 or atoi(monster_array[8].c_str())<0){
            cout<<monster_array[7]<<" 3has been defeat!\n"<<endl;
            monster_array[6] = "0";
            monster_array[7] = "☠";
            monster_array[8] = "0";
            survial[2] =1;
            cnt_3 = 1;
            battle();
        }
        }
        skillRelease();
        monster_dead();
        cout<<"Round finish,situation below:"<<endl;
        battle();


        if((atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0 ) and rabbit == 0){
        cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;

        }
    }
    cout<<"You win this battle\nfinal situation below:"<<endl;
    battle();
    cnt_1 = 0;
    cout<<"You enter into the Forage..\nType anything to continuous"<<endl;
    cin>>space;
    cout<<"Hey!Wow! Good man! I saw you defeat those monsters!\nMy name is Chen, I am craftsman.\nIf you give me 4 golds, I can make your weapon +1 damage!"<<endl;
    cout<<"And other thing, I like fight, so if you can defeat me, I can increase 3 damage of your weapon and 5 HP for free!"<<endl;
    cout<<"NOTES: Once you chose challenge Chen, then you can't get back to shop\NOTES:And Chen is very powerful"<<endl;
    cout<<"1:1 damage-(4) golds\n2:Challenge Chen\n3:Leave"<<endl;
    string buychoice;
    cin>>buychoice;
    while(buychoice!= "1" and buychoice!="2"and buychoice!="3"){
        cout<<"Please enter the correct number"<<endl;
        cin>>buychoice;
    }
    while(buychoice!="3" and buychoice!="2"){
        if(buychoice == "1"){
            if(gold>=4){
            cout<<"You buy 1 damage"<<endl;
            gold-=4;
            cout<<"Current golds: "<<gold<<endl;
            event_change_DPS(1);
            cout<<"Anything else?"<<endl;
            cin>>buychoice;
            }
            if(gold<4){
                cout<<"No enough gold"<<endl;
                cout<<"Anything else?"<<endl;
                cin>>buychoice;
            }
        }
    }
        if(buychoice == "3"){
            cout<<"See you! "<<playerName<<endl;
            cout<<"You are leaving this place"<<endl;
            randomFate();
        }
        if(buychoice == "2"){
            cout<<"Lovely! Let's get start!"<<endl;
        level = 0;
        monster_array[0] = "8";
        monster_array[1] = "Chen";
        monster_array[2] = "10";
        battle();
        cout<<"Type anything to continuous!"<<endl;
        cin>>space;
        cout<<"Type 1 to attack"<<endl;
        while(atoi(monster_array[2].c_str())>0){
        fight();
        cout<<"After"<<endl;
        monster_dead();
        monster_fight();

        battle();
        if(cnt_1 ==0){
        if(atoi(monster_array[2].c_str())==0 or atoi(monster_array[2].c_str())<0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        }
        skillRelease();
        cout<<"Round finish,situation below:"<<endl;
        battle();
        if(atoi(monster_array[2].c_str())>0){cout<<"Type 1 to attack!"<<endl;}
        cout<<"WOW! You are strong! Here is the reward,You deserved!"<<endl;
        cout<<"You increase 3 damage and 5 HP"<<endl;
        event_change_DPS(3);
        event_change_HP(5);
        cout<<"You are leaving this place..."<<endl;
        randomFate();
        }
    }
//=====================================checkpoint6==========================
void Fate::checkpoint_6(){
    cout<<"-------------------Nuodo Castle-------------------\n"<<endl;
    cnt_1 = 0;
    cnt_2 = 0;
    cnt_3 = 0;
    level = (rand() % (3));
    //level = 2;
    cout<<"You enter the Nuodo castle..This is the den of Nuodo spirit"<<endl;
    cout<< "and you decide....\n 1:Go straight\n 2:Bypass "<<endl;
    string choice_2;
    cin>>choice_2;
    while(choice_2 != "1" and choice_2 != "2"){
        cout<<"Please enter the correct number"<<endl;
        cin>>choice_2;
    }
    if(choice_2 =="2"){
        cout<<"You find a Nuodo sword! damage+1"<<endl;
        event_change_DPS(1);
        cout<<"You are leaving this place.."<<endl;
        randomFate();

    }

    if(choice_2=="1"){
    cout<<"You trapped! The Nuodo spirit find you!"<<endl;
    monster_array[0] = "3";
    monster_array[1] = "Nuodo spirit";
    monster_array[2] = "4";
    if(level >0){
    monster_array[3] = "3";
    monster_array[4] = "Nuodo knight";
    monster_array[5] = "8";
    }
    if(level == 2){
    monster_array[6] = "3";
    monster_array[7] = "Nuodo knight";
    monster_array[8] = "8";
    }

    battle();
    cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;

    while(atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0){
        fight();
        monster_dead();
        monster_fight();
        battle();


        if(cnt_1 == 0){
        if(atoi(monster_array[2].c_str())==0 or atoi(monster_array[2].c_str())<0){
            cout<<monster_array[1]<<" has been defeat!\n"<<endl;
            monster_array[0] = "0";
            monster_array[1] = "☠";
            monster_array[2] = "0";
            survial[0] =1;
            cnt_1 = 1;
           battle();
        }
        }
        if((level == 1  and cnt_2 == 0) or (level == 2 and cnt_2 == 0)){
        if(atoi(monster_array[5].c_str())==0 or atoi(monster_array[5].c_str())<0 ){
            cout<<monster_array[4]<<" has been defeat!\n"<<endl;
            monster_array[3] = "0";
            monster_array[4] = "☠";
            monster_array[5] = "0";
            survial[1] =1;
            cnt_2 = 1;
            battle();
        }
        }
        if(level == 2 and cnt_3 == 0){
        if(atoi(monster_array[8].c_str())==0 or atoi(monster_array[8].c_str())<0){
            cout<<monster_array[7]<<" 3has been defeat!\n"<<endl;
            monster_array[6] = "0";
            monster_array[7] = "☠";
            monster_array[8] = "0";
            survial[2] =1;
            cnt_3 = 1;
            battle();
        }
        }
        skillRelease();
        cout<<"Round finish,situation below:"<<endl;
        battle();


        if((atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0 ) and rabbit == 0){
        cout<<"Please enter the monster number you want to attack (1~3 from left)"<<endl;

        }
    }
    cout<<"Final situation:\n"<<endl;
    battle();
    cout<<"You win this battle! Press anything to continuous..."<<endl;
    randomFate();
    }




}






void Fate::battle(){
cout<<"============================================================================\n\n"<<endl;
    if(level == 0){
        cout<<"                          "<<"("<<monster_array[0]<<")"<<monster_array[1]<<"("<<monster_array[2]<<")\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
    else if(level ==1){
        cout<<"            "<<"("<<monster_array[0]<<")"<<monster_array[1]<<"("<<monster_array[2]<<")"<<"            "<<"("<<monster_array[3]<<")"<<monster_array[4]<<"("<<monster_array[5]<<")\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
    else if(level == 2){
        cout<<"        "<<"("<<monster_array[0]<<")"<<monster_array[1]<<"("<<monster_array[2]<<")"<<"   "<<"("<<monster_array[3]<<")"<<monster_array[4]<<"("<<monster_array[5]<<")"<<"   "<<"("<<monster_array[6]<<")"<<monster_array[7]<<"("<<monster_array[8]<<")\n\n"<<endl;
        cout<<"                          "<<"("<<role_array[0]<<")"<<role_array[1]<<"("<<role_array[2]<<")"<<endl;
        cout<<"\n\n============================================================================"<<endl;
    }
}

void Fate::fight(){
   // string choice;
    if(rabbit == 0){
    cin>>choice;
    }
    if(atoi(monster_array[2].c_str())>0 or atoi(monster_array[5].c_str())>0 or atoi(monster_array[8].c_str())>0){


    if(level == 0){
        while(choice != "1"){
            cout<<"Monster didn't exist.Please type the correct number;"<<endl;
            cin>>choice;
        }
    }
    if(level == 1){
         while(choice != "1" and choice != "2"){
            cout<<"Monster didn't exist.Please type the correct number;"<<endl;
            cin>>choice;
        }
    }
    if(level == 2){
         while(choice != "1" and choice!= "2" and choice != "3"){
            cout<<"Monster didn't exist.Please type the correct number;"<<endl;
            cin>>choice;
        }
    }
}

    if (choice == "1" and survial[0] != 1){
    if(atoi(monster_array[2].c_str()) >0){
    int HP = atoi( monster_array[2].c_str() )-atoi(role_array[0].c_str());
    stringstream ss;
    ss<<HP;
    ss>>monster_array[2];

    stringstream sy;

    int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[0].c_str());
    sy<<HP_2;

    sy>>role_array[2];
    cout<<"You "<<" create "<<role_array[0]<<" damages to "<<monster_array[1]<<endl;
    cout<<"The monster strike back with "<<monster_array[0]<<" damages\n"<<endl;
    role_dead();

    }
}
//=========================2============================
    if(choice == "2" and survial[1]!=1){
    if(atoi(monster_array[5].c_str()) >0){
    int HP = atoi( monster_array[5].c_str() )-atoi(role_array[0].c_str());
    stringstream ss;
    ss<<HP;
    ss>>monster_array[5];
    stringstream sy;

    int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[3].c_str());
    sy<<HP_2;

    sy>>role_array[2];
    role_dead();
    }

}
//======================================================
if(choice == "3" and survial[2] !=1){
    if(atoi(monster_array[8].c_str()) >0){
    int HP = atoi( monster_array[8].c_str() )-atoi(role_array[0].c_str());
    stringstream ss;
    ss<<HP;
    ss>>monster_array[8];
    stringstream sy;

    int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[6].c_str());
    sy<<HP_2;

    sy>>role_array[2];
    role_dead();
    }

}

rabbit = 0;// bug when type 2 , will show battlefield
}
//========SKILL===========================
void Fate::skillRelease(){
    int temp = 0;
    string skillChoice;

    if(choice == "1" and survial[0] != 1){
        if(energy > 0){
            cout<<"Do you want to use the skill? (y/n)"<<endl;
            cout<<"\nCurrent energy: "<<energy<<endl;
            cin>>skillChoice;
            while(skillChoice != "y" and skillChoice !="n"){
                cout<<"Please enter y or n"<<endl;
                cin>>skillChoice;
            }
            if(skillChoice == "y"){
                if(skillIndex == 1){
                    hunter();
                    energy--;
                }
                if(skillIndex == 1){
                    hunter();
                    energy--;
                }
                if(skillIndex == 2){
                    mage();
                    energy--;
                }
                if(skillIndex == 3){
                    Drvid();
                    energy--;
                }
                if(skillIndex == 5){
                    Warlock();
                    energy--;
                }
            }
            else{cout<<"You are ready for next round"<<endl;}
        }
    }
    if(choice == "2" and survial[1] != 1){
        if(energy > 0){
            cout<<"Do you want to use the skill? (y/n)"<<endl;
            cout<<"\nCurrent energy: "<<energy<<endl;
            cin>>skillChoice;
            while(skillChoice != "y" and skillChoice !="n"){
                cout<<"Please enter y or n"<<endl;
                cin>>skillChoice;
            }
            if(skillChoice == "y"){
                if(skillIndex == 1){
                    hunter();
                    energy--;
                }
                if(skillIndex == 2){
                    mage();
                    energy--;
                }
                if(skillIndex == 3){
                    Drvid();
                    energy--;
                }
                if(skillIndex == 5){
                    Warlock();
                    energy--;
                }
            }
            else{cout<<"You are ready for next round"<<endl;}
        }

    if(choice == "3" and survial[2] != 1){
        if(energy > 0){
            cout<<"Do you want to use the skill? (y/n)"<<endl;
            cout<<"\nCurrent energy: "<<energy<<endl;
            cin>>skillChoice;
            while(skillChoice != "y" and skillChoice !="n"){
                cout<<"Please enter y or n"<<endl;
                cin>>skillChoice;
            }
            if(skillChoice == "y"){
                if(skillIndex == 1){
                    hunter();
                    energy--;
                }
                if(skillIndex == 1){
                    hunter();
                    energy--;
                }
                if(skillIndex == 2){
                    mage();
                    energy--;
                }
                if(skillIndex == 3){
                    Drvid();
                    energy--;
                }
                if(skillIndex == 5){
                    Warlock();
                    energy--;
                }
            }
            else{cout<<"You are ready for next round"<<endl;}
        }
    }
}

}




//=======================================
void Fate::hunter(){
    if(choice == "1"){
    int HP = atoi( monster_array[2].c_str() )-3;
    stringstream ss;
    ss<<HP;
    ss>>monster_array[2];
    stringstream sy;
    cout<<"You use the Arcane shooting ! create 2 damages to "<<monster_array[1]<<endl;

    }
    else if(choice == "2"){
    int HP = atoi( monster_array[5].c_str() )-3;
    stringstream ss;
    ss<<HP;
    ss>>monster_array[5];
    stringstream sy;
    cout<<"You use the Arcane shooting ! create 2 damages to "<<monster_array[4]<<endl;
    }
    else if(choice == "3"){
    int HP = atoi( monster_array[8].c_str() )-3;
    stringstream ss;
    ss<<HP;
    ss>>monster_array[8];
    stringstream sy;
    cout<<"You use the Arcane shooting ! create 2 damages to "<<monster_array[7]<<endl;
    }
}
void Fate::mage(){
    int HP = atoi(monster_array[2].c_str())-1;
    stringstream ss;
    ss<<HP;
    ss>>monster_array[2];

    HP = atoi(monster_array[5].c_str())-1;
    stringstream sx;
    sx<<HP;
    sx>>monster_array[5];

    HP = atoi(monster_array[8].c_str())-1;
    stringstream sy;
    sy<<HP;
    sy>>monster_array[8];

cout<<"You use the Arcane Explosion! All enemy suffer 1 damage!"<<endl;

}


void Fate::Drvid(){
int HP = atoi(role_array[2].c_str())+3;
stringstream ss;
ss<<HP;
ss>>role_array[2];
cout<<"You use the Rejuvenation ! HP+3"<<endl;

}

void Fate::Warlock(){
int HP = atoi(role_array[2].c_str())-2;
stringstream ss;
ss<<HP;
ss>>role_array[2];

HP = atoi(role_array[0].c_str())+1;
stringstream sx;
sx<<HP;
sx>>role_array[0];
cout<<"You use the Evasion! You transfer 2 HP into 1 damage"<<endl;
}


void Fate::monster_fight(){

    if(survial[0]!=1 and  level == 0){
        battle();
        cout<<"Monster Turn!\n"<<endl;

             int HP = atoi( monster_array[2].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[2];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[0].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[1]<<" create "<<monster_array[0]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
}
    if(level == 1){
        int la = 0;
        int d = (rand() % (2));
        while(la == 0){
        if(survial[0]!=1 and d == 0){
            int HP = atoi( monster_array[2].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[2];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[0].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[1]<<" create "<<monster_array[0]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
            la = 1;
        }
        if(survial[1]!=1 and d==1){
            int HP = atoi( monster_array[5].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[5];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[3].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[4]<<" create "<<monster_array[3]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
            la = 1;
        }
        d = (rand() % (1));
    }

    }
    if(level == 2){
            int la = 0;
            int d = (rand() % (3));
            while(la == 0){
            if(survial[0]!=1 and d == 0){
            int HP = atoi( monster_array[2].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[2];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[0].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[1]<<" create "<<monster_array[0]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
            la = 1;
        }
        if(survial[1]!=1 and d==1){
            int HP = atoi( monster_array[5].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[5];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[3].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[4]<<" create "<<monster_array[3]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
            la = 1;
        }
        if(survial[2]!=1 and d==2){
            int HP = atoi( monster_array[8].c_str() )-atoi(role_array[0].c_str());
            stringstream ss;
            ss<<HP;
            ss>>monster_array[8];

            stringstream sy;

            int HP_2 = atoi(role_array[2].c_str())-atoi(monster_array[6].c_str());
            sy<<HP_2;
            sy>>role_array[2];
            cout<<"The "<<monster_array[7]<<" create "<<monster_array[6]<<" damages to you!\n"<<endl;
            cout<<"You strike back with "<<role_array[0]<<" damages\n"<<endl;
            la = 1;
        }
        d = (rand() % (3));
    }

    }

}



void Fate::monster_dead(){

if(survial[0] == 1 or survial[1]==1 or survial[2]==1 ){
       // cout<<"into the loop"<<endl;
    while(choice_correct == "F"){
        if(survial[0]==1 and choice == "1"){
        cout<<"That monster has already dead! You need to attack another one !"<<endl;
        rabbit =1;
        cin>>choice;
        }
        if(survial[1]==1 and choice == "2"){
        cout<<"That monster has already dead! You need to attack another one !"<<endl;
        rabbit =1;
        cin>>choice;
        }
        if(survial[2]==1 and choice == "3"){
        cout<<"That monster has already dead! You need to attack another one !"<<endl;
        rabbit = 1;
        cin>>choice;
        }
        if(choice != "1" and survial[0] == 1){
            choice_correct = "T";

        }
        if(choice != "2" and survial[1] == 1){
            choice_correct = "T";

        }
        if(choice != "3" and survial[2] == 2){
            choice_correct = "T";

        }

    }
    choice_correct = "F";
    //cout<<"Choice correct"<<endl;
}
}








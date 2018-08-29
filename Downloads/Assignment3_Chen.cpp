#include <iostream>;
#include <cstdlib>;
#include <string>;


using namespace std;

string  board[20][20];
int cnt=0;
string ipC;
string ipTs;
string ipT;
string ipP;
string ipPs;
string b1 = "bike";
string d1 ="dresser";
string c1 = "chicken";
string m1 = "microwave";
string t1 = "truck";
int menu();
int display();
int flag = 1;


int search(string ipTs,string ipPs){
    if(ipTs =="b"){ipTs=b1;}
    if(ipTs=="d"){ipTs=d1;}
    if(ipTs=="c"){ipTs=c1;}
    if(ipTs=="m"){ipTs=m1;}
    if(ipTs=="t"){ipTs=t1;}
for(int i=0;i<cnt;i++){
    if(board[i][0]==ipTs){
            if(atoi(board[i][1].c_str())<= atoi(ipPs.c_str())){
        cout<<"sold:"<<"<"<<board[i][0]<<">,<"<<board[i][1]<<">"<<endl;
             for(int j=i;j<cnt-i;j++){
                board[i][0]=board[i+1][0];
                board[i][1]=board[i+1][1];
                flag = 0;
            }
            cnt--;

            break;}
           //else{cout<<"item not found~1"<<endl;}
    }

}
if(flag == 1){
    cout<<"item not found"<<endl;

}

menu();
}

int insert(string ipT, string ipP){
    if(ipT =="b"){ipT=b1;}
    if(ipT=="d"){ipT=d1;}
    if(ipT=="c"){ipT=c1;}
    if(ipT=="m"){ipT=m1;}
    if(ipT=="t"){ipT=t1;}

    board[cnt][0] = ipT;
    board[cnt][1] = ipP;
    cnt++;
    cout<<"add successful ! we have "<<cnt<<" items now."<<endl;

    menu();

}

    int menu(){
    cout<<"======================================================================"<<endl;
    cout<<"Welcome to the menu ! Please enter the number to select what to do next."<<endl;
    cout << "1. Insert an item." << endl;
    cout << "2. Search for an item." << endl;
    cout << "3. Print the message board." << endl;
    cout << "4. Quit."<< endl;
    string input;
    cin>>input;
    ipC = input;
    while(ipC != "4"){
    if(ipC == "1"){
        cout<<"Enter the item type-b,m,d,t,c:"<<endl;
        cout<<" b:bike \n m:microwave \n d:dresser \n t:truck \n c:chicken"<<endl;
        cin>>ipT;
        while(ipT != "b" && ipT != "m"&&ipT !="d"&&ipT!="t"&& ipT !="c"){
            cout<<"Please enter the correct type"<<endl;
            cin>>ipT;
        }
        cout<<"Please enter the Price"<<endl;
        cin>>ipP;
        int x = atoi(ipP.c_str());
        while(x>100000000 || x <1){
            cout<<"Please enter a valid number"<<endl;
        cin>>ipP;
        x = atoi(ipP.c_str());
        }
        insert(ipT,ipP);

    }
    if(ipC == "2"){
        cout<<"Enter the item type-b,m,d,t,c:"<<endl;
        cin>>ipTs;
        while(ipTs != "b" && ipTs != "m"&&ipTs !="d"&&ipTs!="t"&& ipTs !="c"){
            cout<<"Please enter the correct type"<<endl;
            cin>>ipTs;
            }
            cout<<"Enter the maximum item cost:"<<endl;
            cin>>ipPs;
           int y = atoi(ipPs.c_str());
        while(y>100000000 || y <1){
            cout<<"Please enter a valid number"<<endl;
            cin>>ipPs;
            y = atoi(ipPs.c_str());
        }

    search(ipTs,ipPs);
        }

    if(ipC == "3"){
        display();

    }
    if(ipC != "1" && ipC != "2"&&ipC !="3"&&ipC!="4"){
        cout<<"please enter a correct number 1~4"<<endl;
    }

    cin>>ipC;


}
if(ipC=="4"){cout<<"Quit program,now I can do a happy dance"<<endl;
return 0;}

}

int display(){
cout<<"	message	board:"<<endl;
for(int i =0;i<cnt;i++){
 cout<<"<"<<board[i][0]<<">,<"<<board[i][1]<<"$>"<<endl;
}
menu();
}



int main(){
 menu();
}




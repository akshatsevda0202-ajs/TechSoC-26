#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<string,int>>moves;
int damage=0;
class MOVE{
    public:
    string name;
    int power;
    MOVE(string n,int p){
        int p=power;
        string n=name;
    }
};
class BENDER{
//public:

private:

string element;
string name;
int maxhp;
int speed;
int hp;
int attack;
int defence;
vector<pair<string,int>>moves;
public:

BENDER(string e,string n,int a,int d, int s,int h,
    vector<pair<string,int>>m
) {
    name=n;
    element=e;
    a=attack;
    d=defence;
    hp=h;
speed=s;
moves=m;
}
bool isfainted(){
    return hp<0;
}
void takedamage(int damage){
    hp-=damage;
    if(hp<0){
        hp=0;
    }
}
void showhealth()
{cout<<"Hp="<<hp<<"/"<<"maxHp"<<maxhp<<endl;
}
void totaldamage(BENDER&attacker,BENDER&defender,int movesindex
    );


//damage=((attacker.attack*(movePower))/defender.defence);
    
void takedamage(int damage);
public:
void hit(BENDER&defender,int movesindex){
    string movename=moves[movesindex].first;
        int movePower=moves[movesindex].second;
damage=((attack*(movePower))/defender.defence);
defender.takedamage(damage);
cout<<defender.name<<"took"<<damage<<"damage!"<<endl;
defender.showhealth();
cout <<endl;
if(damage<0){
    damage=0;
}
if(hp<0){
    hp=0;
}
    }

void displayStatus(){
    cout<<"NAME" <<name <<endl;
    cout<< "HP"<<hp <<endl;
    cout<<"ELEMENT" <<element <<endl;
    cout<<"ATTACK" <<attack <<endl;
    cout<<"DEFENCE" << defence<<endl;
cout<<"SPEED" <<speed <<endl;
cout<<"moves"<<endl;
for(int i=0;i<4;i++){
    cout<<i<<"."<<moves[i].first<<"power"<<moves[i].second<<endl;
}
}
};


int main(){
BENDER kael("kael","fire",40,20,30,10,{{"EMBER SLASH",40},{"Quick jab",30},{"Focus",0},{"Flame Surge",70}});
    BENDER mira("mira","water",70,50,40,15,{{"water Ship",35},{"Tide Push",25},{"Mist Veli",0},{"Tidal Wave",60}});
kael.displayStatus();
mira.displayStatus();
    kael.hit(mira,0);
    mira.displayStatus();
    cout<<"mira is fainted"<<mira.isfainted()<<endl;
}

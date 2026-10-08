#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//#include<>
using namespace std;
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
    public:
    string name;
    string element;
    int Hp;
    int maxHp;
    int Speed;
    vector<MOVE>moves;
    BENDER(string e,string n,int h,int a,int s,vector<MOVE>m){
        string n=name;
        string e=element;
        int h=Hp;
     
       
        int s=Speed;
        moves=m;
    }
bool isAlive(){
    return Hp>0;
}
void takedamage(int damage){
    Hp-=damage;
    if(Hp<0){
        Hp=0;
    }
}
void showhealth(){
    cout<<"Hp="<<Hp<<"/"<<"maxHp"<<maxHp<<endl;
}
};

class DUAL{
    private:
    BENDER& bender1;

    BENDER&bender2;
    int turns;
    int criticalchance;
    int hits;
public:
DUAL(BENDER&b1,BENDER&b2):bender1(b1),bender2(b2){
     turns=0;
     criticalchance=0;
     hits=0;
}
bool ishits(string attackerelement,string defenderelement){
  if(  attackerelement=="WATER" && defenderelement=="FIRE"){
    return true;
  }
  if(  attackerelement=="FIRE" && defenderelement=="EARTH"){
    return true;
  }
  if(  attackerelement=="EARTH" && defenderelement=="AIR"){
    return true;
  }if(  attackerelement=="AIR" && defenderelement=="WATER"){
    return true;
  }
return false;
}
bool isnothits(string attackerelement,string defenderelement){
    if(  attackerelement=="FIRE" && defenderelement=="FIRE"){
    return true;}
    if(  attackerelement=="WATER" && defenderelement=="AIR"){
    return true;}
    if(  attackerelement=="AIR" && defenderelement=="EARTH"){
    return true;}
    if(  attackerelement=="AIR" && defenderelement=="FIRE"){
    return true;}
    return false;
}
int totaldamage(BENDER&attacker,BENDER&defender,MOVE&moves,
    bool critical){
        double damage=moves.power;
        if (ishits(attacker.element,defender.element)){damage*=2;
            hits++;
            cout <<"SUPER EFFECTIVE"<<attacker.element<<"is strong against"<<defender.element<<endl;
        }
else if (isnothits(attacker.element,defender.element)){
    damage*=0.5;

    cout<<"not very effective"<<attacker.element<<"is weak against"<<defender.element<<endl;
}
if (critical){
    damage*=2;
    criticalchance++;
    cout<<"critical hit"<<endl;
}
return 0;
    }

    void attack(BENDER&attacker,BENDER&defender,MOVE&moves,bool critical){
        cout<<attacker.name<<"used"<<moves.name<<"!"<<endl;
int damage=totaldamage(attacker,defender,moves,critical);
defender.takedamage(damage);
cout<<defender.name<<"took"<<"damage!"<<endl;
defender.showhealth();
cout <<endl;
    }
void start_duel(){
    cout<<"==DUEL BIGINS=="<<endl;
    cout <<bender1.name<<"("<<bender1.element<<"Hp"<<bender1.Hp<<"/"<<bender1.maxHp<<")vs"<<bender2.name<<endl;
    //find first
    BENDER*FIRST;
    BENDER*SECOND;
    if(bender1.Speed>bender2.Speed){
        FIRST=&bender1;
        SECOND=&bender2;
    }
    else{
        FIRST=&bender2;
        SECOND=&bender1;
    }
    turns++;
    cout<<"turn1"<<FIRST->name<<"goes first!"<<"Speed"<<FIRST->Speed<<""<<endl;
    attack(*FIRST,*SECOND,FIRST->moves[0],false);
    if(FIRST->isAlive()){
        finish(*SECOND,*FIRST);
        return ;
    }

}
void finish(BENDER&winner,BENDER&looser){
    cout<<looser.name<<"is fainted"<<endl;
    cout<<winner.name<<"wins with duel"<<endl;
    cout<<endl;
    cout<<"DUEL SUMMERY"<<endl;
    cout<<"winner:"<<winner.name<<endl;
    cout<<"turns"<<turns<<endl;
    cout<<"critical hits"<<criticalchance<<endl;
    cout<<"super effective hits"<<endl;

}
}
;
int main(){
    BENDER kael("kael","fire",40.20,{("EMBER SLASH",40),("Quick jab",30),("Focus",0),("Flame Surge",70)});
    BENDER mira("mira","water",70,50,{("water Ship",35),("Tide Push",25),("Mist Veli",0),("Tidal Wave",60)});
    DUAL DUAL(kael,mira);
    DUAL.start_duel();
    return 0;
}
#include <iostream>

using namespace std;

class ChampionBuild {
private:
    string champ;
    string mythic;
    string boots;
    string item1;
    string item2;
    string item3;
    string item4;



public:

    ChampionBuild(string ch, string my, string bt, string i1, string i2, string i3, string i4){
        item1 = i1;
        item2 = i2;
        item3 = i3;
        item4 = i4;
        boots = bt;
        mythic = my;
        champ = ch;
    }

    ChampionBuild(){
        item1 = "YOUR MOM";
        item2 = "YOUR MOM";
        item3 = "YOUR MOM";
        item4 = "YOUR MOM";
        boots = "YOUR MOM";
        mythic = "YOUR MOM";
    }

    string getItem1() {
        return item1;
    }
    string getItem2() {
        return item2;
    }
    string getItem3() {
        return item3;
    }
    string getItem4() {
        return item4;
    }
    string getBoots() {
        return boots;
    }
    string getMythic() {
        return mythic;
    }
    string getChamp(){
        return champ;
    }
    void setItem1(string i1){
        item1 = i1;
    }
    void setItem2(string i2){
        item2 = i2;
    }
    void setItem3(string i3){
        item3 = i3;
    }
    void setItem4(string i4){
        item4 = i4;
    }
    void setBoots(string bt){
        boots = bt;
    }
    void setMythic(string my){
        mythic = my;
    }
    void setChamp(string ch){
        champ = ch;
    }
    bool containsItem(string it){
        if((item1 == it) || (item2 == it) || (item3 == it) || (item4 == it) || (boots == it) || (mythic == it))
            return true;
        return false;
    }
    bool containsMythic(string my){
        if(mythic == my)
            return true;
        return false;
    }
    bool containsBoots(string bt){
        if(boots == bt)
            return true;
        return false;
    }

    string getBuild(){
        string temp = champ + ": " + mythic + ", " + boots + ", " + item1 + ", " + item2 + ", " + item3 + ", " + item4;
        return temp;
    }


};
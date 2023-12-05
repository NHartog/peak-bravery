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
        item1 = i1; //O(1)
        item2 = i2; //O(1)
        item3 = i3; //O(1)
        item4 = i4; //O(1)
        boots = bt; //O(1)
        mythic = my; //O(1)
        champ = ch; //O(1)
    }

    ChampionBuild(){
        item1 = "ERROR"; //O(1)
        item2 = "ERROR"; //O(1)
        item3 = "ERROR"; //O(1)
        item4 = "ERROR"; //O(1)
        boots = "ERROR"; //O(1)
        mythic = "ERROR"; //O(1)
    }

    string getItem1() {
        return item1; //O(1)
    }
    string getItem2() {
        return item2; //O(1)
    }
    string getItem3() {
        return item3; //O(1)
    }
    string getItem4() {
        return item4; //O(1)
    }
    string getBoots() {
        return boots; //O(1)
    }
    string getMythic() {
        return mythic; //O(1)
    }
    string getChamp(){
        return champ; //O(1)
    }
    bool containsItem(string it){ //O(1)
        if((item1 == it) || (item2 == it) || (item3 == it) || (item4 == it) || (boots == it) || (mythic == it))
            return true;
        return false;
    }
    bool containsMythic(string my){ //O(1)
        if(mythic == my)
            return true;
        return false;
    }
    bool containsBoots(string bt){ //O(1)
        if(boots == bt)
            return true;
        return false;
    }

    string getBuild(){ //O(1)
        string temp = champ + ": " + mythic + ", " + boots + ", " + item1 + ", " + item2 + ", " + item3 + ", " + item4;
        return temp;
    }


};
#include <iostream>

using namespace std;

class Class {
private:
    string champ;
    string item1;
    string item2;
    string item3;
    string item4;
    string item5;
    string item6;

public:

    Class(string ch, string i1, string i2, string i3, string i4, string i5, string i6){
        item1 = i1;
        item2 = i2;
        item3 = i3;
        item4 = i4;
        item5 = i5;
        item6 = i6;
        champ = ch;
    }

    Class(){
        item1 = "YOUR MOM";
        item2 = "YOUR MOM";
        item3 = "YOUR MOM";
        item4 = "YOUR MOM";
        item5 = "YOUR MOM";
        item6 = "YOUR MOM";
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
    string getItem5() {
        return item5;
    }
    string getItem6() {
        return item6;
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
    void setItem5(string i5){
        item5 = i5;
    }
    void setItem6(string i6){
        item6 = i6;
    }
    void setChamp(string ch){
        champ = ch;
    }
    bool containsItem(string it){
        if((item1 == it) || (item2 == it) || (item3 == it) || (item4 == it) || (item5 == it) || (item6 == it))
            return true;
        return false;
    }




};
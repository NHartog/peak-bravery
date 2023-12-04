//
// Created by nicho on 12/1/2023.
//


#include <random>
#include "Toolbox.h"


using namespace std;
using namespace sf;

ItemDisplay::ItemDisplay(vector<ChampionBuild> selection){
    this->selection = selection;
}

ItemDisplay::ItemDisplay(){

}

ChampionBuild ItemDisplay::getItemSet() {
    return selectedItem;
}

void ItemDisplay::setItemSet(sf::Event event) {
    int xC = event.mouseButton.x;
    int yC = event.mouseButton.y;
    int i= -1;

    if(yC > 360 && yC < 550){
        if(xC > 900 && xC < 1195){
            i = 0;
        }
        else if(xC > 550 && xC < 845){
            i = 1;
        }
        else if(xC > 1250 && xC < 1545){
            i = 2;
        }
    }else if(yC > 720 && yC < 915){
        if(xC > 900 && xC < 1195){
            i = 3;
        }
        else if(xC > 550 && xC < 845){
            i = 4;
        }
        else if(xC > 1250 && xC < 1545){
            i = 5;
        }
    }

    if(i != -1){
        selectedItem = selection[i];
        Toolbox::getInstance().programState->setBraveryStatus(ProgramState::PLAYING);
    }
}

void ItemDisplay::drawInitialChoice() {

    for(int i = 0; i < 6; i ++){
        Sprite item1;
        Sprite item2;
        Sprite item3;
        Sprite item4;
        Sprite item5;
        Sprite item6;
        Texture text1;
        Texture text2;
        Texture text3;
        Texture text4;
        Texture text5;
        Texture text6;
        int y = 360;
        int x;

        if(i>2){
            y = 720;
        }


        text1.loadFromFile("Item_Icons/" + selection[i].getMythic() + ".png");
        text2.loadFromFile("Item_Icons/" + selection[i].getBoots() + ".png");
        text3.loadFromFile("Item_Icons/" + selection[i].getItem1() + ".png");
        text4.loadFromFile("Item_Icons/" + selection[i].getItem2() + ".png");
        text5.loadFromFile("Item_Icons/" + selection[i].getItem3() + ".png");
        text6.loadFromFile("Item_Icons/" + selection[i].getItem4() + ".png");
        item1.setTexture(text1);
        item2.setTexture(text2);
        item3.setTexture(text3);
        item4.setTexture(text4);
        item5.setTexture(text5);
        item6.setTexture(text6);

        if(i>2){
            y = 720;
            x = ((i - 3) % 6 + 1) * 350 + 200;
        }else{
            x = (i % 6 + 1) * 350 + 200;
        }

        item1.setPosition(sf::Vector2f(x,y));
        x += 100;
        item2.setPosition(sf::Vector2f(x,y));
        x += 100;
        item3.setPosition(sf::Vector2f(x,y));
        x -= 200;
        y += 100;
        item4.setPosition(sf::Vector2f(x,y));
        x += 100;
        item5.setPosition(sf::Vector2f(x,y));
        x += 100;
        item6.setPosition(sf::Vector2f(x,y));

        item1.setScale(1.5f, 1.5f);
        item2.setScale(1.5f, 1.5f);
        item3.setScale(1.5f, 1.5f);
        item4.setScale(1.5f, 1.5f);
        item5.setScale(1.5f, 1.5f);
        item6.setScale(1.5f, 1.5f);

        Toolbox::getInstance().window.draw(item1);
        Toolbox::getInstance().window.draw(item2);
        Toolbox::getInstance().window.draw(item3);
        Toolbox::getInstance().window.draw(item4);
        Toolbox::getInstance().window.draw(item5);
        Toolbox::getInstance().window.draw(item6);

    }
}

void ItemDisplay::setSelection(vector<ChampionBuild> selection) {
    this->selection = selection;
}

void ItemDisplay::drawSelectedItems() {
    Sprite item1;
    Sprite item2;
    Sprite item3;
    Sprite item4;
    Sprite item5;
    Sprite item6;
    Texture text1;
    Texture text2;
    Texture text3;
    Texture text4;
    Texture text5;
    Texture text6;

    text1.loadFromFile("Item_Icons/" + selectedItem.getMythic() + ".png");
    text2.loadFromFile("Item_Icons/" + selectedItem.getBoots() + ".png");
    text3.loadFromFile("Item_Icons/" + selectedItem.getItem1() + ".png");
    text4.loadFromFile("Item_Icons/" + selectedItem.getItem2() + ".png");
    text5.loadFromFile("Item_Icons/" + selectedItem.getItem3() + ".png");
    text6.loadFromFile("Item_Icons/" + selectedItem.getItem4() + ".png");
    item1.setTexture(text1);
    item2.setTexture(text2);
    item3.setTexture(text3);
    item4.setTexture(text4);
    item5.setTexture(text5);
    item6.setTexture(text6);

    int y = 360;
    int x = (0 % 6 + 1) * 350 + 200;

    item1.setPosition(sf::Vector2f(x,y));
    x += 100;
    item2.setPosition(sf::Vector2f(x,y));
    x += 100;
    item3.setPosition(sf::Vector2f(x,y));
    x += 100;
    item4.setPosition(sf::Vector2f(x,y));
    x += 100;
    item5.setPosition(sf::Vector2f(x,y));
    x += 100;
    item6.setPosition(sf::Vector2f(x,y));

    item1.setScale(1.5f, 1.5f);
    item2.setScale(1.5f, 1.5f);
    item3.setScale(1.5f, 1.5f);
    item4.setScale(1.5f, 1.5f);
    item5.setScale(1.5f, 1.5f);
    item6.setScale(1.5f, 1.5f);

    Toolbox::getInstance().window.draw(item1);
    Toolbox::getInstance().window.draw(item2);
    Toolbox::getInstance().window.draw(item3);
    Toolbox::getInstance().window.draw(item4);
    Toolbox::getInstance().window.draw(item5);
    Toolbox::getInstance().window.draw(item6);

    map<string, vector<vector<string>>> runes;


}




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

void ItemDisplay::initializePrimaryRunes(map<string, vector<vector<string>>> runes) {
    //Precision Keystones
    runes["Precision"].at(0).push_back("Press the Attack");
    runes["Precision"].at(0).push_back("Lethal Tempo");
    runes["Precision"].at(0).push_back("Fleet Footwork");
    runes["Precision"].at(0).push_back("Conquerer");

    //Slot 1
    runes["Precision"].at(1).push_back("Overheal");
    runes["Precision"].at(1).push_back("Triumph");
    runes["Precision"].at(1).push_back("Presence of Mind");

    //Slot 2
    runes["Precision"].at(2).push_back("Legend: Alacrity");
    runes["Precision"].at(2).push_back("Legend: Tenacity");
    runes["Precision"].at(2).push_back("Legend: Bloodline");

    //Slot 3
    runes["Precision"].at(3).push_back("Coup de Grace");
    runes["Precision"].at(3).push_back("Cut Down");
    runes["Precision"].at(3).push_back("Last Stand");



    //Domination Keystones
    runes["Domination"].at(0).push_back("Electrocute");
    runes["Domination"].at(0).push_back("Predator");
    runes["Domination"].at(0).push_back("Dark Harvest");
    runes["Domination"].at(0).push_back("Hail of Blades");

    //Slot 1
    runes["Domination"].at(1).push_back("Cheap Shot");
    runes["Domination"].at(1).push_back("Tase of Blood");
    runes["Domination"].at(1).push_back("Sudden Impact");

    //Slot 2
    runes["Domination"].at(2).push_back("Zombie Ward");
    runes["Domination"].at(2).push_back("Ghost Poro");
    runes["Domination"].at(2).push_back("Eyeball Collection");

    //Slot 3
    runes["Domination"].at(3).push_back("Treasure Hunter");
    runes["Domination"].at(3).push_back("Ingenious Hunter");
    runes["Domination"].at(3).push_back("Relentless Hunter");
    runes["Domination"].at(3).push_back("Ultimate Hunter");



    //Sorcery Keystones
    runes["Sorcery"].at(0).push_back("Summon Aery");
    runes["Sorcery"].at(0).push_back("Arcane Comet");
    runes["Sorcery"].at(0).push_back("Phase Rush");

    //Slot 1
    runes["Sorcery"].at(1).push_back("Nullifying Orb");
    runes["Sorcery"].at(1).push_back("Manaflow Band");
    runes["Sorcery"].at(1).push_back("Nimbus Cloak");

    //Slot 2
    runes["Sorcery"].at(2).push_back("Transcendence");
    runes["Sorcery"].at(2).push_back("Celerity");
    runes["Sorcery"].at(2).push_back("Absolute Focus");

    //Slot 3
    runes["Sorcery"].at(3).push_back("Scorch");
    runes["Sorcery"].at(3).push_back("Waterwalking");
    runes["Sorcery"].at(3).push_back("Gathering Storm");



    //Resolve Keystones
    runes["Resolve"].at(0).push_back("Grasp of the Undying");
    runes["Resolve"].at(0).push_back("Aftershock");
    runes["Resolve"].at(0).push_back("Guardian");

    //Slot 1
    runes["Resolve"].at(1).push_back("Demolish");
    runes["Resolve"].at(1).push_back("Font of Life");
    runes["Resolve"].at(1).push_back("Shield Bash");

    //Slot 2
    runes["Resolve"].at(2).push_back("Conditioning");
    runes["Resolve"].at(2).push_back("Second Wind");
    runes["Resolve"].at(2).push_back("Bone Plating");

    //Slot 3
    runes["Resolve"].at(3).push_back("Overgrowth");
    runes["Resolve"].at(3).push_back("Revitalize");
    runes["Resolve"].at(3).push_back("Unflinching");



    //Inspiration Keystones
    runes["Inspiration"].at(0).push_back("Glacial Augment");
    runes["Inspiration"].at(0).push_back("Unsealed Spellbook");
    runes["Inspiration"].at(0).push_back("First Strike");

    //Slot 1
    runes["Inspiration"].at(1).push_back("Hextech Flashtraption");
    runes["Inspiration"].at(1).push_back("Magical Footwear");
    runes["Inspiration"].at(1).push_back("Perfect Timing");

    //Slot 2
    runes["Inspiration"].at(2).push_back("Future's Market");
    runes["Inspiration"].at(2).push_back("Minion Dematerializer");
    runes["Inspiration"].at(2).push_back("Biscuit Delivery");

    //Slot 3
    runes["Inspiration"].at(3).push_back("Cosmic Insight");
    runes["Inspiration"].at(3).push_back("Approach Velocity");
    runes["Inspiration"].at(3).push_back("Time Warp Tonic");
}

void ItemDisplay::getRandomRunePage() {
    
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




//
// Created by nicho on 12/1/2023.
//


#include <random>
#include <thread>
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
        if(xC > 550 && xC < 845){
            i = 0;
        }
        else if(xC > 900 && xC < 1195){
            i = 1;
        }
        else if(xC > 1250 && xC < 1545){
            i = 2;
        }
    }else if(yC > 720 && yC < 915){
        if(xC > 550 && xC < 845){
            i = 3;
        }
        else if(xC > 900 && xC < 1195){
            i = 4;
        }
        else if(xC > 1250 && xC < 1545){
            i = 5;
        }
    }
    cout << i << endl;
    if(i != -1){
        selectedItem = selection[i];
        Toolbox::getInstance().programState->setBraveryStatus(ProgramState::PLAYING);
        initializePrimaryRunes();
        initializeRandomSummonerSpells();
        setRandomSummonerSpells();
        setRandomRunePage();
        setRandomSecondaryRunePage();
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

void ItemDisplay::initializePrimaryRunes() {

    runes["Precision"] = vector<vector<string>>(4);
    runes["Domination"] = vector<vector<string>>(4);
    runes["Sorcery"] = vector<vector<string>>(4);
    runes["Resolve"] = vector<vector<string>>(4);
    runes["Inspiration"] = vector<vector<string>>(4);

    //Precision Keystones
    runes["Precision"].at(0).emplace_back("Press the Attack");
    runes["Precision"].at(0).emplace_back("Lethal Tempo");
    runes["Precision"].at(0).push_back("Fleet Footwork");
    runes["Precision"].at(0).emplace_back("Conquerer");

    //Slot 1
    runes["Precision"].at(1).push_back("Overheal");
    runes["Precision"].at(1).push_back("Triumph");
    runes["Precision"].at(1).push_back("Presence of Mind");

    //Slot 2
    runes["Precision"].at(2).push_back("Legend Alacrity");
    runes["Precision"].at(2).push_back("Legend Tenacity");
    runes["Precision"].at(2).push_back("Legend Bloodline");

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
    runes["Domination"].at(1).push_back("Taste of Blood");
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

void ItemDisplay::setRandomRunePage() {
     unsigned seed1 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
     std::default_random_engine generator1(seed1);
     std::uniform_int_distribution<int> distributionP(0, runes.size()-1);
     int Path = distributionP(generator1);

     auto it = runes.begin();
     for(int i = 0; i < Path; i++) { it++; }

     unsigned seed2 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
     std::default_random_engine generator2(seed1);
     std::uniform_int_distribution<int> distributionK(0, it->second[0].size()-1);
     int Keystone = distributionK(generator1);

     unsigned seed3 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
     std::default_random_engine generator3(seed1);
     std::uniform_int_distribution<int> distributionS1(0, it->second[1].size()-1);
     int slot1 = distributionS1(generator1);

     unsigned seed4 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
     std::default_random_engine generator4(seed1);
     std::uniform_int_distribution<int> distributionS2(0, it->second[2].size()-1);
     int slot2 = distributionS2(generator1);

     unsigned seed5 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
     std::default_random_engine generator5(seed1);
     std::uniform_int_distribution<int> distributionS3(0, it->second[3].size()-1);
     int slot3 = distributionS3(generator1);

     vector<string> res;

     res.push_back(it->first);
     res.push_back(it->second[0][Keystone]);
     res.push_back(it->second[1][slot1]);
     res.push_back(it->second[2][slot2]);
     res.push_back(it->second[3][slot3]);

     primary = res;
}

void ItemDisplay::setRandomSecondaryRunePage() {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionP(0, runes.size()-1);
    int Path = distributionP(generator);

    auto it = runes.begin();
    for (int i = 0; i < Path; i++) {
        it++;
    }

    // Guarantees Unique secondary Keystone
    while(it->first == primary[0]) {
        it++;
        if(it == runes.end()) {
            it = runes.begin();
        }
    }

    unsigned seed2 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator2(seed);
    std::uniform_int_distribution<int> distributionK(0, it->second[0].size()-1);
    int Keystone = distributionK(generator);

    unsigned seed3 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator3(seed);
    std::uniform_int_distribution<int> distributionS1(0, it->second[1].size()-1);
    int slot1 = distributionS1(generator);

    unsigned seed4 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator4(seed);
    std::uniform_int_distribution<int> distributionS2(0, it->second[2].size()-1);
    int slot2 = distributionS2(generator);

    unsigned seed5 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator5(seed);
    std::uniform_int_distribution<int> distributionS3(0, it->second[3].size()-1);
    int slot3 = distributionS3(generator);

    unsigned seed6 = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator6(seed);
    std::uniform_int_distribution<int> distributionSlots(0, 1);
    int slots = distributionSlots(generator);

    vector<string> res;

    res.push_back(it->first);
    res.push_back(it->second[0][Keystone]);
    res.push_back(it->second[1][slot1]);
    if(slots) {
        res.push_back(it->second[2][slot2]);
    } else {
        res.push_back(it->second[3][slot3]);
    }

    secondary = res;
}

void ItemDisplay::initializeRandomSummonerSpells() {
    vector<string> res;
    res.push_back("Barrier");
    res.push_back("Cleanse");
    res.push_back("Exhaust");
    res.push_back("Flash");
    res.push_back("Ghost");
    res.push_back("Heal");
    res.push_back("Ignite");
    res.push_back("Smite");
    res.push_back("Teleport");

    spells = res;
}

void ItemDisplay::setRandomSummonerSpells() {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(seed);

    std::uniform_int_distribution<int> distributionS1(0, spells.size());
    int spell1 = distributionS1(generator);

    std::uniform_int_distribution<int> distributionS2(0, spells.size());
    int spell2 = distributionS2(generator);

    string first = spells[spell1];
    string second = spells[spell2];

    summoner1 = first;
    summoner2 = second;
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

    Sprite path;
    Sprite keystone;
    Sprite slot1;
    Sprite slot2;
    Sprite slot3;

    Texture pathTex;
    Texture keystoneTex;
    Texture slot1Tex;
    Texture slot2Tex;
    Texture slot3Tex;

    Sprite pathSecond;
    Sprite slot1Second;
    Sprite slot2Second;

    Texture pathSecondTex;
    Texture slot1SecondTex;
    Texture slot2SecondTex;

    Sprite ss1;
    Sprite ss2;

    Texture ss1Text;
    Texture ss2Text;


    pathTex.loadFromFile("Rune Images/" + primary[0] + ".png");
    keystoneTex.loadFromFile("Rune Images/" + primary[1] + ".png");
    slot1Tex.loadFromFile("Rune Images/" + primary[2] + ".png");
    slot2Tex.loadFromFile("Rune Images/" + primary[3] + ".png");
    slot3Tex.loadFromFile("Rune Images/" + primary[4] + ".png");

    pathSecondTex.loadFromFile("Rune Images/" + secondary[0] + ".png");
    slot1SecondTex.loadFromFile("Rune Images/" + secondary[2] + ".png");
    slot2SecondTex.loadFromFile("Rune Images/" + secondary[3] + ".png");

    ss1Text.loadFromFile("Summoner Spells/" + summoner1 + ".png");
    ss2Text.loadFromFile("Summoner Spells/" + summoner2 + ".png");

    path.setTexture(pathTex);
    keystone.setTexture(keystoneTex);
    slot1.setTexture(slot1Tex);
    slot2.setTexture(slot2Tex);
    slot3.setTexture(slot3Tex);

    pathSecond.setTexture(pathSecondTex);
    slot1Second.setTexture(slot1SecondTex);
    slot2Second.setTexture(slot2SecondTex);

    ss1.setTexture(ss1Text);
    ss2.setTexture(ss2Text);

    pathSecond.setPosition(900, 800);
    slot1Second.setPosition(1000, 800);
    slot2Second.setPosition(1100, 800);

    path.setPosition(900, 600);
    keystone.setPosition(1000, 600);
    slot1.setPosition(1100, 600);
    slot2.setPosition(1200, 600);
    slot3.setPosition(1300, 600);

    ss1.setPosition(600, 800);
    ss2.setPosition(700, 800);

    path.setScale(2.0,2.0);
    pathSecond.setScale(2.0,2.0);
    Toolbox::getInstance().window.draw(path);
    Toolbox::getInstance().window.draw(keystone);
    Toolbox::getInstance().window.draw(slot1);
    Toolbox::getInstance().window.draw(slot2);
    Toolbox::getInstance().window.draw(slot3);

    Toolbox::getInstance().window.draw(pathSecond);
    Toolbox::getInstance().window.draw(slot1Second);
    Toolbox::getInstance().window.draw(slot2Second);

    Toolbox::getInstance().window.draw(ss1);
    Toolbox::getInstance().window.draw(ss2);

}




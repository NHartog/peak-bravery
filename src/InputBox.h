#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>
#include "stack"
#pragma once

//this class is for the box where user type in the champion they want
using namespace std;

class InputBox {
    sf::Vector2f position;
    sf::Text inputText;
    sf::RectangleShape inputBox;
    std::string userInput;
    std::vector<std::string> suggestions;
    //this is for the code to compare to valid champs as they type
    std::vector<std::string> champSuggestions = {
            "Aatrox", "Ahri", "Akali", "Akshan", "Alistar", "Amumu", "Anivia", "Annie", "Aphelios", "Ashe",
            "Aurelion Sol", "Azir", "Bard", "Bel'Veth", "Blitzcrank", "Brand", "Braum", "Caitlyn", "Camille",
            "Cassiopeia", "Cho'Gath", "Corki", "Darius", "Diana", "Dr. Mundo", "Draven", "Ekko",
            "Elise", "Evelynn", "Ezreal", "Fiddlesticks", "Fiora", "Fizz", "Galio", "Gangplank",
            "Garen", "Gnar", "Gragas", "Graves", "Gwen", "Hecarim", "Heimerdinger", "Illaoi", "Irelia",
            "Ivern", "Janna", "Jarvan IV", "Jax", "Jayce", "Jhin", "Jinx", "Kai'Sa", "Kalista",
            "Karma", "Karthus", "K'Sante", "Kassadin", "Katarina", "Kayle", "Kayn", "Kennen", "Kha'Zix",
            "Kindred", "Kled", "Kog'Maw", "LeBlanc", "Lee Sin", "Leona", "Lillia", "Lissandra",
            "Lucian", "Lulu", "Lux", "Malphite", "Malzahar", "Maokai", "Master Yi", "Milio", "Miss Fortune",
            "Mordekaiser", "Morgana", "Nami", "Nasus", "Nautilus", "Neeko", "Nidalee", "Nilah", "Nocturne",
            "Nunu & Willump", "Olaf", "Orianna", "Ornn", "Pantheon", "Poppy", "Pyke", "Qiyana",
            "Quinn", "Rakan", "Rammus", "Renata Glasc", "Rek'Sai", "Rell", "Renekton", "Rengar", "Riven", "Rumble",
            "Ryze", "Samira", "Sejuani", "Senna", "Seraphine", "Sett", "Shaco", "Shen", "Shyvana",
            "Singed", "Sion", "Sivir", "Skarner", "Sona", "Soraka", "Swain", "Sylas", "Syndra",
            "Tahm Kench", "Taliyah", "Talon", "Taric", "Teemo", "Thresh", "Tristana", "Trundle",
            "Tryndamere", "Twisted Fate", "Twitch", "Udyr", "Urgot", "Varus", "Vayne", "Veigar",
            "Vel'Koz", "Vex", "Vi", "Viego", "Viktor", "Vladimir", "Volibear", "Warwick", "Wukong",
            "Xayah", "Xerath", "Xin Zhao", "Yasuo", "Yone", "Yorick", "Yuumi", "Zac", "Zed", "Zeri",
            "Ziggs", "Zilean", "Zoe", "Zyra"
    };

    vector<string> matches;
    sf::Font font;
    bool activeBox;
    bool valid;


public:
    InputBox(float width, float height, sf::Vector2f position, string type);
    void draw();
    void handleEvent(sf::Event event);
    string toLower(std::string str);
    string getChamp();
    void setActive(bool _active);
    sf::Vector2f getPosition();

    void setChamp(string champ);
    sf::Text getText();
    string getInout();
    vector<string> getItems();
    bool validEntry();
    void validate();
    void setValid(bool valid);
};

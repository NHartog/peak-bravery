#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>
#include "stack"
#pragma once

using namespace std;

class InputBox {
    sf::Vector2f position;
    sf::Text inputText;
    sf::RectangleShape inputBox;
    std::string userInput;
    std::set<std::string> suggestions = {
            "Aatrox", "Ahri", "Akali", "Alistar", "Amumu", "Anivia", "Annie", "Aphelios", "Ashe",
            "Aurelion Sol", "Azir", "Bard", "Blitzcrank", "Brand", "Braum", "Caitlyn", "Camille",
            "Cassiopeia", "Cho'Gath", "Corki", "Darius", "Diana", "Dr. Mundo", "Draven", "Ekko",
            "Elise", "Evelynn", "Ezreal", "Fiddlesticks", "Fiora", "Fizz", "Galio", "Gangplank",
            "Garen", "Gnar", "Gragas", "Graves", "Hecarim", "Heimerdinger", "Illaoi", "Irelia",
            "Ivern", "Janna", "Jarvan IV", "Jax", "Jayce", "Jhin", "Jinx", "KaiSa", "Kalista",
            "Karma", "Karthus", "Kassadin", "Katarina", "Kayle", "Kayn", "Kennen", "Kha'Zix",
            "Kindred", "Kled", "Kog'Maw", "LeBlanc", "Lee Sin", "Leona", "Lillia", "Lissandra",
            "Lucian", "Lulu", "Lux", "Malphite", "Malzahar", "Maokai", "Master Yi", "Miss Fortune",
            "Mordekaiser", "Morgana", "Nami", "Nasus", "Nautilus", "Neeko", "Nidalee", "Nocturne",
            "Nunu & Willump", "Olaf", "Orianna", "Ornn", "Pantheon", "Poppy", "Pyke", "Qiyana",
            "Quinn", "Rakan", "Rammus", "Rek'Sai", "Rell", "Renekton", "Rengar", "Riven", "Rumble",
            "Ryze", "Samira", "Sejuani", "Senna", "Seraphine", "Sett", "Shaco", "Shen", "Shyvana",
            "Singed", "Sion", "Sivir", "Skarner", "Sona", "Soraka", "Swain", "Sylas", "Syndra",
            "Tahm Kench", "Taliyah", "Talon", "Taric", "Teemo", "Thresh", "Tristana", "Trundle",
            "Tryndamere", "Twisted Fate", "Twitch", "Udyr", "Urgot", "Varus", "Vayne", "Veigar",
            "VelKoz", "Vi", "Viego", "Viktor", "Vladimir", "Volibear", "Warwick", "Wukong",
            "Xayah", "Xerath", "Xin Zhao", "Yasuo", "Yone", "Yorick", "Yuumi", "Zac", "Zed",
            "Ziggs", "Zilean", "Zoe", "Zyra"
    };
    vector<string> matches;
    sf::Font font;
    bool activeBox;


public:
    InputBox(float width, float height, sf::Vector2f position);
    void draw();
    void handleEvent(sf::Event event);
    string toLower(std::string str);
    string toUpper(std::string str);
    string getChamp();
    void setActive(bool _active);
    bool isActive();
    sf::Vector2f getPosition();

    void setChamp(string champ);
    sf::Text getText();
};


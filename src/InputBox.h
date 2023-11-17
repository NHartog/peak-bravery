#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "stack"
#pragma once

using namespace std;

class InputBox {
    sf::Vector2f position;
    sf::Text inputText;
    sf::RectangleShape inputBox;
    std::string userInput;
    std::vector<std::string> suggestions;
    sf::Font font;

public:
    InputBox(float width, float height, sf::Vector2f position);
    void draw();
    void handleEvent(sf::Event event);

};



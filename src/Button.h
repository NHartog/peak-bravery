//
// Created by nicho on 11/28/2022.
//

#include <SFML/Graphics.hpp>
#include <functional>

#pragma once



class Button {
    //private attributes
    //Our functor
    int width, height;
    std::function<void(void)> clicked;
    sf::Vector2f position;
    sf::Text butText;
    sf::Font font;
    sf::RectangleShape buttonBox;
    std::string text;
public:
    //public methods
    Button(sf::Vector2f _position, int width, int height, std::function<void(void)> _onClick, std::string text);
    sf::Vector2f getPosition();
    void onClick();
    void draw(bool ghost = false);

};


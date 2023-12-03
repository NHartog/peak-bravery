//
// Created by nicho on 11/27/2023.
//

#include "Toolbox.h"


Icon::Icon(sf::Vector2f _position) {
    position = _position;
}

sf::Vector2f Icon::getPosition() {
    return position;
}

void Icon::setChampionImage(string champion) {
    string fileName = "Champion_Icons/" + champion + ".png";
    if (texture.loadFromFile(fileName)) {
        std::cout << "Texture loaded successfully!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(position.x, position.y));
        sprite.setScale(Vector2f(2.0,2.0));
    } else {
        Toolbox::getInstance().programState->setBraveryStatus(ProgramState::CHAMP_SELECT);
        fileName = "Images/trollface.png";
        texture.loadFromFile(fileName);
        std::cout << "Failed to load texture!" << std::endl;

    }
}

void Icon::setItemImage(string item) {
    string fileName = "league_icons/" + item + ".png";
    if (texture.loadFromFile(fileName)) {
        std::cout << "Texture loaded successfully!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(position.x, position.y));
    } else {
        Toolbox::getInstance().programState->setBraveryStatus(ProgramState::CHAMP_SELECT);
        fileName = "Images/trollface.png";
        texture.loadFromFile(fileName);
        std::cout << "Failed to load texture!" << std::endl;

    }
}

void Icon::draw() {
    Toolbox::getInstance().window.draw(sprite);
}

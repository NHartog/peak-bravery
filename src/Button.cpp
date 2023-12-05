//
// Created by nicho on 11/28/2022.
//

#include "Button.h"
#include "Toolbox.h"

//Constructs a new Button object at the specified _position which invokes the _onClick callback when clicked.
Button::Button(sf::Vector2f _position, int _width, int _height, std::function<void(void)> _onClick, string _text) {
    width = _width;
    height = _height;
    clicked = _onClick;
    position = _position;
    text = _text;
    font.loadFromFile("Fonts/BeaufortforLOL-Heavy.otf");
    active = true;
}
//Returns the position of the button.
sf::Vector2f Button::getPosition() {
    return position;
}
//sets sprite of the button

//Invokes the button’s callback method (usually called when clicked).
void Button::onClick() {
    clicked();
}

//draws button. Takes into account if it dims or not
void Button::draw(bool ghost) {
    if(ghost && (Toolbox::getInstance().inputChampionBox->getInout() == "" )){
        butText.setFillColor(sf::Color(0, 0, 0, 150));
        buttonBox.setFillColor(sf::Color(128, 128, 128, 150));
        active = false;
    }
    else{
        butText.setFillColor(sf::Color::Black);
        buttonBox.setFillColor(sf::Color::White);
        active = true;
    }
    butText.setString(text);
    butText.setFont(font);

    butText.setCharacterSize(24);
    butText.setPosition(position.x +10, position.y +10);

    buttonBox.setSize(sf::Vector2f(width,height));

    buttonBox.setPosition(sf::Vector2f(position.x,position.y));

    Toolbox::getInstance().window.draw(buttonBox);
    Toolbox::getInstance().window.draw(butText);
}

//special draw function for when the button is for the traversals
void Button::drawi(string traversal) {
    if(traversal == "DFS"){
        if(Toolbox::getInstance().programState->getTraversal() == ProgramState::DFS){
            butText.setFillColor(sf::Color::Black);
            buttonBox.setFillColor(sf::Color::White);
            active = true;
        }
        else{
            butText.setFillColor(sf::Color(0, 0, 0, 150));
            buttonBox.setFillColor(sf::Color(128, 128, 128, 150));
            active = false;
        }

    }
    else if(traversal == "BFS"){
        if(Toolbox::getInstance().programState->getTraversal() == ProgramState::BFS){
            butText.setFillColor(sf::Color::Black);
            buttonBox.setFillColor(sf::Color::White);
            active = true;
        }
        else{
            butText.setFillColor(sf::Color(0, 0, 0, 150));
            buttonBox.setFillColor(sf::Color(128, 128, 128, 150));
            active = false;
        }

    }
    butText.setString(text);
    butText.setFont(font);

    butText.setCharacterSize(24);
    butText.setPosition(position.x +10, position.y +10);

    buttonBox.setSize(sf::Vector2f(width,height));

    buttonBox.setPosition(sf::Vector2f(position.x,position.y));

    Toolbox::getInstance().window.draw(buttonBox);
    Toolbox::getInstance().window.draw(butText);
}
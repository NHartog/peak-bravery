//
// Created by nicho on 11/17/2023.
//

#include "InputBox.h"
#include "Toolbox.h"

InputBox::InputBox(float width, float height, sf::Vector2f position) {
    this->font.loadFromFile("Fonts/BeaufortforLOL-Heavy.otf");
    this->position.x = position.x;
    this->position.y = position.y;
    this->inputBox.setSize(sf::Vector2f(width,height));

    this->inputText.setFont(font);
    this->inputText.setCharacterSize(24);
    this->inputText.setFillColor(sf::Color::Black);
    this->inputBox.setFillColor(sf::Color::White);
}

void InputBox::draw() {
    Toolbox::getInstance().window.draw(inputBox);
    Toolbox::getInstance().window.draw(inputText);

    if(!userInput.empty()){
        vector<string> matchingSuggestions;
        for(string suggestion : this->suggestions){
            if (suggestion.find(userInput) == 0) {
                matchingSuggestions.push_back(suggestion);
            }
        }

        for (size_t i = 0; i < matchingSuggestions.size(); i++) {
            sf::Text suggestionText(matchingSuggestions[i], font, 20);
            suggestionText.setFillColor(sf::Color::Black);
            suggestionText.setPosition(inputBox.getPosition().x,
                                       inputBox.getPosition().y + inputBox.getSize().y + 10 + i * 30);
            Toolbox::getInstance().window.draw(suggestionText);
        }
    }
}

void InputBox::handleEvent(sf::Event event) {
    if (event.text.unicode < 128 && event.text.unicode != 8) {
        userInput += static_cast<char>(event.text.unicode);
    } else if (event.text.unicode == 8 && !userInput.empty()) {
        userInput.pop_back();
    }
    cout<< userInput << endl;
    inputText.setString(userInput);
    inputText.setPosition(inputBox.getPosition().x + 10, inputBox.getPosition().y + 10);
}

//
// Created by nicho on 11/17/2023.
//

#include "InputBox.h"
#include "Toolbox.h"
#include <algorithm>

//create the position and dimesnions for it
InputBox::InputBox(float width, float height, sf::Vector2f position, string type) {
    this->font.loadFromFile("Fonts/BeaufortforLOL-Heavy.otf");
    this->position.x = position.x;
    this->position.y = position.y;
    this->inputBox.setSize(sf::Vector2f(width,height));

    this->inputBox.setPosition(position.x, position.y);
    this->inputText.setFont(font);
    this->inputText.setCharacterSize(24);
    this->inputText.setFillColor(sf::Color::Black);
    this->inputBox.setFillColor(sf::Color(128, 128, 128, 150));

    suggestions = champSuggestions;
    activeBox = false;
    valid = true;
}

//draws it. If the user is not clicked in it, it will "ghost" until they click in the box again
void InputBox::draw() {
    if(!activeBox){
        inputBox.setFillColor(sf::Color(128, 128, 128, 150));
        Toolbox::getInstance().window.draw(inputBox);

        inputText.setFillColor(sf::Color(0, 0, 0, 150));
        Toolbox::getInstance().window.draw(inputText);
    }
    else{
        inputText.setFillColor(sf::Color::Black);
        inputBox.setFillColor(sf::Color::White);
        Toolbox::getInstance().window.draw(inputBox);
        Toolbox::getInstance().window.draw(inputText);

        if(!userInput.empty()){
            vector<string> matchingSuggestions;
            for(string suggestion : this->suggestions){
                if (toLower(suggestion).find(toLower(userInput)) == 0) {
                    matchingSuggestions.push_back(suggestion);
                }
            }
            matches = matchingSuggestions;

            sf::RectangleShape predictionBox(sf::Vector2f(inputBox.getSize().x, 10+ 30 * matches.size()));
            predictionBox.setFillColor(sf::Color::White);
            predictionBox.setPosition(inputBox.getPosition().x, inputBox.getPosition().y + inputBox.getSize().y);
            Toolbox::getInstance().window.draw(predictionBox);

            for (size_t i = 0; i < matches.size(); i++) {
                sf::Text suggestionText(matches[i], font, 20);
                suggestionText.setFillColor(sf::Color::Black);
                suggestionText.setPosition(inputBox.getPosition().x,
                                           inputBox.getPosition().y + inputBox.getSize().y + 10 + i * 30);
                Toolbox::getInstance().window.draw(suggestionText);
            }
        }
    }

}

//handles the typing inside the box. Also shows the predictive text
void InputBox::handleEvent(sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed and Toolbox::getInstance().programState->getBraveryStatus() == ProgramState::CHAMP_SELECT){
        int xC = event.mouseButton.x;
        int yC = event.mouseButton.y;

        //cout << xC << endl;
        //cout << yC << endl;

        if(xC >= position.x and xC <= position.x + 600 and yC >= 55 and yC <= 55 + 48 + 10 + matches.size()*30){ // <= 105
            //cout << 55 + 48 + 10 + matches.size()*30 << endl;
            activeBox = true;
        }
        else{
            activeBox = false;
        }

        if(yC >= 105 && activeBox){ // <= 105
            int pos = yC - (55 + 48 + 10);
            int i = pos/30;
            cout << yC << endl;
            cout << pos << endl;
            cout << i << endl;
            userInput = matches[i];
        }

    }


    if(activeBox and Toolbox::getInstance().programState->getBraveryStatus() == ProgramState::CHAMP_SELECT){
        //cout << event.text.unicode << endl;
        if ((event.text.unicode > 64  && event.text.unicode < 90) || (event.text.unicode > 96  && event.text.unicode < 123) && event.text.unicode != 8) {
            userInput += static_cast<char>(event.text.unicode);
        } else if (event.text.unicode == 8 && !userInput.empty()) {
            userInput.pop_back();
        }
        //cout<< userInput << endl;
        inputText.setString(userInput);
        inputText.setPosition(inputBox.getPosition().x + 10, inputBox.getPosition().y + 10);
    }

}

sf::Vector2f InputBox::getPosition() {
    return position;
}

string InputBox::toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    return str;
}

void InputBox::setActive(bool _active) {
    activeBox = _active;
}

string InputBox::getChamp() {
    return userInput;
}

void InputBox::setChamp(string champ) {
    userInput = champ;
}

string InputBox::getInout() {
    return userInput;
}

vector<string> InputBox::getItems() {
    return suggestions;
}

//validates if the user entered a champion that exists
void InputBox::validate() {
    auto it = find(suggestions.begin(),suggestions.end(), userInput);
    if(it == suggestions.end()){
        valid = false;
    }else{
        valid = true;
    }
}

void InputBox::setValid(bool valid) {
    this->valid = valid;
}

bool InputBox::validEntry() {
    return valid;
}

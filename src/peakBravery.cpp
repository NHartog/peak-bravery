#include "SFML/Graphics.hpp"
#include <iostream>
#include "Toolbox.h"
#include "peakBravery.h"

using namespace std;
using namespace sf;

int launch() {
    Toolbox &tool = Toolbox::getInstance();
    render();
    return 0;
}


void render() {
    Toolbox &tool = Toolbox::getInstance();
    sf::Image icon;
    std::string imagePath = "Images/Tyler1_Dent.jpg";
//    string meow = "cats";
//    if(meow.find("ca") == 0){
//        cout << "meow";
//    }
    vector<Texture> backgroundFrames;
    for (int i = 0; i <= 359; i++) {
        sf::Texture frame;
        int numZeros = 3 - to_string(i).length();
        string leadingZeros(numZeros, '0');
        string frameNum = leadingZeros + to_string(i);
        frame.loadFromFile("Images/backgroundGif/frame_" + frameNum + "_delay-0.05s.gif");
        backgroundFrames.push_back(frame);
    }
    int currentFrame = 0;
    sf::Sprite background;
    background.setTexture(backgroundFrames[currentFrame]);
    Clock clock;
    tool.window.display();

    if (icon.loadFromFile(imagePath)) {
        tool.window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        background.setScale(static_cast<float>(tool.window.getSize().x) / background.getTexture()->getSize().x,
                            static_cast<float>(tool.window.getSize().y) / background.getTexture()->getSize().y);
        while (tool.window.isOpen()) {

            // Game logic and rendering here
            if (clock.getElapsedTime().asSeconds() >= 0.01) {
                currentFrame = (currentFrame + 1) % backgroundFrames.size();
                background.setTexture(backgroundFrames[currentFrame]);
                clock.restart();
            }
            tool.window.clear();

            tool.window.draw(background);
            tool.inputBox->draw();
            tool.window.display();
            programLoop();
        }
    }
}

void programLoop(){
    Event event;
    Toolbox &tool = Toolbox::getInstance();

    while (tool.window.pollEvent(event)) {
        if(event.type == sf::Event::TextEntered){
            Toolbox::getInstance().inputBox->handleEvent(event);

        }
        if(event.type == sf::Event::MouseButtonPressed ){

            //checks if you have right clicked the button
//            if (event.mouseButton.button == sf::Mouse::Right){
//                //gets location of click so we can use it
//
//                int xC = event.mouseButton.x/32;
//                int yC =  event.mouseButton.y/32;
//
        }
        if (event.type == sf::Event::Closed) {
            tool.window.close();
        }
    }
}


int main(){
    return launch();
}

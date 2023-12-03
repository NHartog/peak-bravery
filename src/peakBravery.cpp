#include "SFML/Graphics.hpp"
#include <iostream>
#include "Toolbox.h"
#include "peakBravery.h"
#include "ProgramState.h"

using namespace std;
using namespace sf;

int launch() {
    Toolbox &tool = Toolbox::getInstance();
    tool.programState = new ProgramState();
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

    icon.loadFromFile(imagePath);
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
        if(Toolbox::getInstance().programState->getBraveryStatus() == ProgramState::CHAMP_SELECT){
            tool.inputBox->draw();
            tool.enterButton->draw(true);
        }
        else if(Toolbox::getInstance().programState->getBraveryStatus() == ProgramState::ITEM_SELECT){
            tool.inputBox->draw();
            tool.enterButton->draw(true);
            tool.champion->draw();
            tool.items->drawInitialChoice();
        }
        tool.restart->draw(false);
        tool.window.display();
        programLoop();
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


            if(tool.programState->getBraveryStatus() == ProgramState::CHAMP_SELECT){
                Toolbox::getInstance().inputBox->handleEvent(event);

                int xC = event.mouseButton.x;
                int yC =  event.mouseButton.y;

                cout << xC << endl;
                cout << yC << endl;

                if(1300 <=xC && xC <= 1375 && 55 <= yC && yC <= 105){
                    tool.enterButton->onClick();
                }
                else if(1400 <=xC && xC <= 1500 && 55 <= yC && yC <= 105){
                    tool.restart->onClick();
                }
            }

            else if(tool.programState->getBraveryStatus() == ProgramState::ITEM_SELECT){
                int xC = event.mouseButton.x;
                int yC =  event.mouseButton.y;

                if(1400 <=xC && xC <= 1500 && 55 <= yC && yC <= 105){
                    tool.restart->onClick();
                }
            }


        }
        if (event.type == sf::Event::Closed) {
            tool.window.close();
        }
    }
}

void setChamp(){
    string champion = Toolbox::getInstance().inputBox->getChamp();
    Toolbox::getInstance().programState->setBraveryStatus(ProgramState::ITEM_SELECT);
    Toolbox::getInstance().champion->setChampionImage(champion);
}

void startOver(){
    Toolbox::getInstance().inputBox->setChamp("");
    Toolbox::getInstance().programState->setBraveryStatus(ProgramState::CHAMP_SELECT);

}

int main(){
    return launch();
}

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Toolbox.h"
#include "peakBravery.h"
#include "ProgramState.h"
#include <fstream>

using namespace std;
using namespace sf;

int launch() {
    Toolbox &tool = Toolbox::getInstance();
    ParseInput(tool.LeagueGraph);
//    tool.LeagueGraph.printBuilds(tool.LeagueGraph.get6Builds("Aatrox", true));

    tool.programState = new ProgramState();
    //ParseInput(tool.LeagueGraph);
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
            tool.inputChampionBox->draw();
            tool.inputItemBox->draw();
            tool.enterButton->draw(true);
            tool.DFS->drawi("DFS");
            tool.BFS->drawi("BFS");
            if(!tool.inputChampionBox->validEntry()){
                Font font;
                font.loadFromFile("Fonts/BeaufortforLOL-Heavy.otf");
                sf::Text notFoundText("Champion or Item does not exist", font, 24);
                notFoundText.setPosition(100.f, 100.f);
                tool.window.draw(notFoundText);
            }
        }
        else if(Toolbox::getInstance().programState->getBraveryStatus() == ProgramState::ITEM_SELECT){
            tool.inputChampionBox->draw();
            tool.inputItemBox->draw();
            tool.enterButton->draw(true);
            tool.DFS->drawi("DFS");
            tool.BFS->drawi("BFS");
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
            Toolbox::getInstance().inputChampionBox->handleEvent(event);
            Toolbox::getInstance().inputItemBox->handleEvent(event);
        }
        if(event.type == sf::Event::MouseButtonPressed ){

            if(tool.programState->getBraveryStatus() == ProgramState::CHAMP_SELECT){
                Toolbox::getInstance().inputChampionBox->handleEvent(event);
                Toolbox::getInstance().inputItemBox->handleEvent(event);

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
    Toolbox& tool =  Toolbox::getInstance();
    string s = tool.inputChampionBox->getChamp();
    tool.inputChampionBox->validate();
    if(!tool.inputChampionBox->validEntry()){
        tool.inputChampionBox->setValid(false);
    }
    else{
        tool.inputChampionBox->setValid(true);
        vector<ChampionBuild> selection = tool.LeagueGraph.get6Builds(tool.inputChampionBox->getChamp(), true);
        tool.items->setSelection(selection);
        string champion = Toolbox::getInstance().inputChampionBox->getChamp();
        Toolbox::getInstance().programState->setBraveryStatus(ProgramState::ITEM_SELECT);
        Toolbox::getInstance().champion->setChampionImage(champion);
    }
}

void startOver(){
    Toolbox::getInstance().inputChampionBox->setChamp("");
    Toolbox::getInstance().inputItemBox->setChamp("");
    Toolbox::getInstance().inputChampionBox->setValid(true);
    Toolbox::getInstance().programState->setBraveryStatus(ProgramState::CHAMP_SELECT);

}

void setDFS(){
    Toolbox::getInstance().programState->setTraversal(0);
}

void setBFS(){
    Toolbox::getInstance().programState->setTraversal(1);
}

int main(){
    return launch();
}

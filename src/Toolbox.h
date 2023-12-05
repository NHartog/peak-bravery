#pragma once
#include "SFML/Graphics.hpp"
#include "InputBox.h"
#include "Button.h"
#include "ProgramState.h"
#include "Icon.h"
#include "ItemDisplay.h"
#include "Graph.h"

using namespace sf;

class Toolbox {
    Toolbox();
public:
    RenderWindow window;
    InputBox* inputChampionBox;
    Button* enterButton;
    Button* restart;
    Button* newBuilds;
    Button* DFS;
    Button* BFS;
    ProgramState* programState;
    Icon* champion;
    ItemDisplay* items;
    Graph LeagueGraph;
    Text* timingText;

    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
};



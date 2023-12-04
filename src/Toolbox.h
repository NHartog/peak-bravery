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
    InputBox* inputItemBox;
    Button* enterButton;
    Button* restart;
    Button* DFS;
    Button* BFS;
    ProgramState* programState;
    Icon* champion;
    ItemDisplay* items;
    Graph LeagueGraph;

    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
};



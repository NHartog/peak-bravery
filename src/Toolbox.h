#pragma once
#include "SFML/Graphics.hpp"
#include "InputBox.h"
#include "Button.h"
#include "ProgramState.h"
#include "Icon.h"

using namespace std;
using namespace sf;

class Toolbox {
    Toolbox();
public:
    RenderWindow window;
    InputBox* inputBox;
    Button* enterButton;
    Button* restart;
    ProgramState* programState;
    Icon* champion;

    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
};



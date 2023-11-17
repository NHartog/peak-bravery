#pragma once
#include "SFML/Graphics.hpp"
#include "InputBox.h"

using namespace std;
using namespace sf;

class Toolbox {
    Toolbox();
public:
    RenderWindow window;
    InputBox* inputBox;
    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
};



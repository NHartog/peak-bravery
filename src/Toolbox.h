#pragma once
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Toolbox {
    Toolbox();
public:
    RenderWindow window;

    static Toolbox& getInstance(){
        static Toolbox instance;
        return instance;
    }
};



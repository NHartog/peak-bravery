
#include "Toolbox.h"

Toolbox::Toolbox() {
    window.create(sf::VideoMode(1920u, 1080u), "P4 -  Minesweeper, <Nicholas Hartog>");
    window.setFramerateLimit(144);

    inputBox = new InputBox(64,64,Vector2f(64,12));


}
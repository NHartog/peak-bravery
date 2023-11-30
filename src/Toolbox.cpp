
#include "Toolbox.h"
#include "Button.h"
#include "peakBravery.h"

Toolbox::Toolbox() {
    window.create(sf::VideoMode(1920u, 1080u), "P4 -  Minesweeper, <Nicholas Hartog>");
    window.setFramerateLimit(144);

    programState = nullptr;

    inputBox = new InputBox(600,48,Vector2f(960-300,56));

    enterButton = new Button(Vector2f(1300,56),78, 48, setChamp, "Enter");

    restart = new Button(Vector2f(1400,56),100, 48, startOver, "Restart");

    champion = new Icon(Vector2f(100,56));

}
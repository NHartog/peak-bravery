#include "Toolbox.h"
#include "Button.h"
#include "peakBravery.h"

Toolbox::Toolbox() {
    window.create(sf::VideoMode(1920u, 1080u), "P4 -  Minesweeper, <Nicholas Hartog>");

    window.setFramerateLimit(144);

    programState = nullptr;

    inputChampionBox = new InputBox(290, 48, Vector2f(960 - 300, 56), "champions");

    inputItemBox = new InputBox(290, 48, Vector2f(960 , 56), "items");

    enterButton = new Button(Vector2f(1300,56),78, 48, setChamp, "Enter");

    restart = new Button(Vector2f(1400,56),100, 48, startOver, "Restart");

    DFS = new Button(Vector2f(1600,56),75, 48, setDFS, "DFS");

    BFS = new Button(Vector2f(1700,56),75, 48, setBFS, "BFS");

    champion = new Icon(Vector2f(100,440));

    items = new ItemDisplay();

    LeagueGraph = Graph();

}
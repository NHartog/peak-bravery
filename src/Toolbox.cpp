#include "Toolbox.h"
#include "Button.h"
#include "peakBravery.h"

Toolbox::Toolbox() {
    Font font;
    font.loadFromFile("Fonts/BeaufortforLOL-Heavy.otf");

    //holds all of our buttons, inputs, icons, etc that need to be accessed throughout the project.

    window.create(sf::VideoMode(1920u, 1080u), "PEAK BRAVERY");

    window.setFramerateLimit(144);

    programState = nullptr;

    inputChampionBox = new InputBox(590, 48, Vector2f(960 - 300, 56), "champions");

    enterButton = new Button(Vector2f(1300,56),78, 48, setChamp, "Enter");

    restart = new Button(Vector2f(1400,56),100, 48, startOver, "Restart");

    newBuilds = new Button(Vector2f(100,800),135, 48, newBuild, "New Build");

    DFS = new Button(Vector2f(1600,56),65, 48, setDFS, "DFS");

    BFS = new Button(Vector2f(1700,56),65, 48, setBFS, "BFS");

    champion = new Icon(Vector2f(100,440));

    items = new ItemDisplay();

    LeagueGraph = Graph();

    timingText =  new Text("", font, 24);
    timingText->setPosition(100,100);



}
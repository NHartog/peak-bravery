#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class ProgramState {

    int state;

public:
    ProgramState();
    enum BraveryStatus { CHAMP_SELECT, ITEM_SELECT, PLAYING };
    BraveryStatus getBraveryStatus();
    void setBraveryStatus(BraveryStatus _status);
};


#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class ProgramState {

    int state;
    int traversal;
    string champion;

public:
    ProgramState();
    enum BraveryStatus { CHAMP_SELECT, ITEM_SELECT, PLAYING };
    enum Traversal { DFS, BFS };
    BraveryStatus getBraveryStatus();
    void setBraveryStatus(BraveryStatus _status);
    Traversal getTraversal();
    void setTraversal(int _traversal);
    void setChampion(string champion);
    string getChampion();
};


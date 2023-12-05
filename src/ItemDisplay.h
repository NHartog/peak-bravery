#include <SFML/Graphics.hpp>
#include "ChampionBuild.h"
using namespace std;

class ItemDisplay {
    vector<ChampionBuild> selection;
    ChampionBuild selectedItem;
    map<string, vector<vector<string>>> runes;
    vector<string> primary;
    vector<string> secondary;
    vector<string> spells;
    string summoner1;
    string summoner2;

public:
    ItemDisplay(vector<ChampionBuild> selection);
    ItemDisplay();
    ChampionBuild getItemSet();
    void setItemSet(Event event);
    void drawInitialChoice();
    void drawSelectedItems();
    void setSelection(vector<ChampionBuild> select);
    void initializePrimaryRunes(map<string, vector<vector<string>>>);
    void getRandomRunePage();
};


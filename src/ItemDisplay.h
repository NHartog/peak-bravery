#include <SFML/Graphics.hpp>
#include "ChampionBuild.h"
using namespace std;

//this class is to handle the actual display of champions and its items/summoner spells/and runes
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
    ItemDisplay();
    ChampionBuild getItemSet();
    void setItemSet(Event event);
    void drawInitialChoice();
    void drawSelectedItems();
    void setSelection(vector<ChampionBuild> select);
    void initializePrimaryRunes();
    void initializeRandomSummonerSpells();
    void setRandomRunePage();
    void setRandomSecondaryRunePage();
    void setRandomSummonerSpells();
};


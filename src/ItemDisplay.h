#include <SFML/Graphics.hpp>
#include "ChampionBuild.h"
using namespace std;

class ItemDisplay {
    vector<ChampionBuild> selection;
    ChampionBuild selectedItem;

public:
    ItemDisplay(vector<ChampionBuild> selection);
    ItemDisplay();
    ChampionBuild getItemSet();
    void setItemSet(Event event);
    void drawInitialChoice();
    void drawSelectedItems();
    void setSelection(vector<ChampionBuild> select;
    void initializeRunes(const vector<vector<string>> &runes);
};


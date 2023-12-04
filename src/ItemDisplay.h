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
    void setItemSet(int selected);
    void drawInitialChoice();
    void drawSelectedItems();
    void setSelection(vector<ChampionBuild> selection);
};


#include <SFML/Graphics.hpp>
#include "TempThing.h"
using namespace std;

class ItemDisplay {
    vector<TempThing> selection;
    TempThing selectedItem;

public:
    ItemDisplay(vector<TempThing> selection);
    ItemDisplay();
    TempThing getItemSet();
    void setItemSet(int selected);
    void drawInitialChoice();
    void drawSelectedItems();
};


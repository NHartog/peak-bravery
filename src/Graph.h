#include <vector>
#include <map>
#include "Class.h"

class Graph{
private:
    //  champ         item 1  item 2   item 3
    map<string, vector<Class>> g;

public:
    void insert(string ch, string i1, string i2, string i3, string i4, string i5, string i6){

        Class c(ch, i1, i2, i3, i4, i5, i6);
        g[ch].push_back(c);
    }
    vector<Class> getAllOfChamp(string champ){
        return g[champ];
    }
    vector<Class> getAllOfItem(string item){

        vector<Class> retVec;

        auto it = g.begin();
        while(it != g.end()){
            ++it;
            for(int i = 0; i < it->second.size(); i++) {
                if (it->second[i].containsItem(item))
                    retVec.push_back(it->second[i]);
            }

        }
    }



};

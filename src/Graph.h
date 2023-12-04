#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <CMath>
#include <random>
#include <chrono>

class Graph {
private:
    //  item         item 1  item 2   item 3
    map<string, vector<ChampionBuild>> g;

public:

    Graph() {}

    void insert(string ch, string my, string i1, string i2, string i3, string i4, string i5) {

        ChampionBuild c(ch, my, i1, i2, i3, i4, i5);
        g[i2].push_back(c);
        g[i3].push_back(c);
        g[i4].push_back(c);
        g[i5].push_back(c);
        g[my].push_back(c);
        g[i1].push_back(c);
    }

    vector<ChampionBuild> GetAllOfChamp(string champ) {
        return g[champ];
    }

    void addWithOutDuplicates(vector<ChampionBuild>& vec, ChampionBuild build) {
        bool alreadyIn = false;

        for (int i = 0; i < vec.size(); i++) {
            if ((vec[i].getChamp() == build.getChamp()) && (vec[i].getItem1() == build.getItem1()) &&
                (vec[i].getItem2() == build.getItem2()) && (vec[i].getItem3() == build.getItem3()) &&
                (vec[i].getItem4() == build.getItem4()) && (vec[i].getBoots() == build.getBoots())) {
                alreadyIn = true;
            }
        }
        if(!alreadyIn){
            vec.push_back(build);
        }

    }

    vector<ChampionBuild> DFS_getAllOfChamp(string champ, string startNode) {

        vector<ChampionBuild> retVec;

        stack<string> stackOfNeighbors;
        map<string, bool> visited;

        stackOfNeighbors.push(startNode);

        while (!stackOfNeighbors.empty()) {
            string currentNode = stackOfNeighbors.top();
            stackOfNeighbors.pop();

            if (!visited[currentNode]) {
                //Process the current node (e.g., print or perform some operation)
                for (int i = 0; i < g[currentNode].size(); i++) {
                    if (g[currentNode][i].getChamp() == champ)
                        addWithOutDuplicates(retVec,g[currentNode][i]);
                }
                visited[currentNode] = true;
                // Push unvisited neighbors onto the stack
                for (int i = 0; i < g[currentNode].size(); ++i) {
                    ChampionBuild neighbor = g[currentNode][i];
                    if (!visited[neighbor.getItem1()] && currentNode != neighbor.getItem1()) {
                        stackOfNeighbors.push(neighbor.getItem1());
                        visited[neighbor.getItem1()] = true;
                    }
                    if (!visited[neighbor.getItem2()] && currentNode != neighbor.getItem2()) {
                        stackOfNeighbors.push(neighbor.getItem2());
                        visited[neighbor.getItem2()] = true;
                    }
                    if (!visited[neighbor.getItem3()] && currentNode != neighbor.getItem3()) {
                        stackOfNeighbors.push(neighbor.getItem3());
                        visited[neighbor.getItem3()] = true;
                    }
                    if (!visited[neighbor.getItem4()] && currentNode != neighbor.getItem4()) {
                        stackOfNeighbors.push(neighbor.getItem4());
                        visited[neighbor.getItem4()] = true;
                    }
                    if (!visited[neighbor.getBoots()] && currentNode != neighbor.getBoots()) {
                        stackOfNeighbors.push(neighbor.getBoots());
                        visited[neighbor.getBoots()] = true;
                    }
                    if (!visited[neighbor.getMythic()] && currentNode != neighbor.getMythic()) {
                        stackOfNeighbors.push(neighbor.getMythic());
                        visited[neighbor.getMythic()] = true;
                    }

                }
            }
        }
        return retVec;
    }

    vector<ChampionBuild> BFS_getAllOfChamp(string champ, string startNode) {

        vector<ChampionBuild> retVec;

        queue <string> Neighborsqueue;
        map<string, bool> visited;

        Neighborsqueue.push(startNode);
        visited[startNode] = true;

        while (!Neighborsqueue.empty()) {
            string currentNode = Neighborsqueue.front();
            Neighborsqueue.pop();

            // Process the current node (e.g., print or perform some operation)
            for (int i = 0; i < g[currentNode].size(); i++) {
                if (g[currentNode][i].getChamp() == champ)
                    addWithOutDuplicates(retVec,g[currentNode][i]);
            }

            visited[currentNode] = true;
            // Push unvisited neighbors onto the queue
            for (int i = 0; i < g[currentNode].size(); ++i) {
                ChampionBuild neighbor = g[currentNode][i];
                if (!visited[neighbor.getItem1()] && currentNode != neighbor.getItem1()) {
                    Neighborsqueue.push(neighbor.getItem1());
                    visited[neighbor.getItem1()] = true;
                }
                if (!visited[neighbor.getItem2()] && currentNode != neighbor.getItem2()) {
                    Neighborsqueue.push(neighbor.getItem2());
                    visited[neighbor.getItem2()] = true;
                }
                if (!visited[neighbor.getItem3()] && currentNode != neighbor.getItem3()) {
                    Neighborsqueue.push(neighbor.getItem3());
                    visited[neighbor.getItem3()] = true;
                }
                if (!visited[neighbor.getItem4()] && currentNode != neighbor.getItem4()) {
                    Neighborsqueue.push(neighbor.getItem4());
                    visited[neighbor.getItem4()] = true;
                }
                if (!visited[neighbor.getBoots()] && currentNode != neighbor.getBoots()) {
                    Neighborsqueue.push(neighbor.getBoots());
                    visited[neighbor.getBoots()] = true;
                }
                if (!visited[neighbor.getMythic()] && currentNode != neighbor.getMythic()) {
                    Neighborsqueue.push(neighbor.getMythic());
                    visited[neighbor.getMythic()] = true;
                }

            }
        }

    }

    vector<ChampionBuild> get6Builds(string champ, bool BFSorDFS) {
        //DFS = true
        //BFS = false

        vector<ChampionBuild> retVec;
        vector<ChampionBuild> temp;

        if (BFSorDFS) {
            temp = DFS_getAllOfChamp(champ, "Thornmail");
        }
        else {
            temp = BFS_getAllOfChamp(champ, "Thornmail");
        }
        set<int> randNums;
        while(randNums.size() < 6){
//            std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
//            std::uniform_int_distribution<int> distribution(0, temp.size());
//            int randomNumber = distribution(rng);
//            srand((unsigned) time(0));
//            int randomNumber = (rand() % temp.size()) + 1;
//            randNums.insert(randomNumber);
            unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> distribution(0, temp.size());
            int randomNumber = distribution(generator);
            randNums.insert(randomNumber);
        }
        for (int i = 0; i < 6; i++) {
            auto it = randNums.begin();
            retVec.push_back(temp[*it]);
            randNums.erase(it);
//            srand((unsigned) time(NULL));
//            double random = ((double) rand() / (RAND_MAX));
//            double grab = random * temp.size();

        }
        return retVec;

    }

    void printBuilds(vector<ChampionBuild> temp){
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i].getBuild() << endl;
        }
    }



};

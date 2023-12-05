#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <Cmath>
#include <random>
#include <chrono>

class Graph {
private:
    //  item         item 1  item 2   item 3
    unordered_map<string, vector<ChampionBuild>> g;
    double timing;

public:

    Graph() {}

    //O(7) ~ O(1)
    void insert(string ch, string my, string i1, string i2, string i3, string i4, string i5) {

        ChampionBuild c(ch, my, i1, i2, i3, i4, i5); //O(1)
        g[i2].push_back(c); //O(1)
        g[i3].push_back(c); //O(1)
        g[i4].push_back(c); //O(1)
        g[i5].push_back(c); //O(1)
        g[my].push_back(c); //O(1)
        g[i1].push_back(c); //O(1)
    }

    // O(n) where n is the the size of the vector
    void addWithOutDuplicates(vector<ChampionBuild>& vec, ChampionBuild build) {
        bool alreadyIn = false;

        for (int i = 0; i < vec.size(); i++) { // n is the vec.size() so O(n)
            if ((vec[i].getChamp() == build.getChamp()) && (vec[i].getItem1() == build.getItem1()) &&
                (vec[i].getItem2() == build.getItem2()) && (vec[i].getItem3() == build.getItem3()) &&
                (vec[i].getItem4() == build.getItem4()) && (vec[i].getBoots() == build.getBoots())) {
                alreadyIn = true;
            }
        }
        if(!alreadyIn){
            vec.push_back(build); // O(n)
        }
    }

    //O(i*outdeg(i)) = O(E) = O(V^2)
    vector<ChampionBuild> DFS_getAllOfChamp(string champ, string startNode) {

        vector<ChampionBuild> retVec; //O(1)

        stack<string> stackOfNeighbors; //O(1)
        unordered_map<string, bool> visited; //O(1)
        unordered_map<string, bool> InStack; //O(1)

        stackOfNeighbors.push(startNode); //O(1)

        while (!stackOfNeighbors.empty()) { //O(i)
            string currentNode = stackOfNeighbors.top(); //O(1)
            stackOfNeighbors.pop(); //O(1)

            if (!visited[currentNode]) { //O(1)
                //Process the current node (e.g., print or perform some operation)
                for (int i = 0; i < g[currentNode].size(); i++) { // O( outdegree(i))
                    if (g[currentNode][i].getChamp() == champ)
                        addWithOutDuplicates(retVec,g[currentNode][i]); //
                }
                visited[currentNode] = true;
                // Push unvisited neighbors onto the stack
                for (int i = 0; i < g[currentNode].size(); ++i) {// O( outdegree(i))
                    ChampionBuild neighbor = g[currentNode][i];
                    if (!visited[neighbor.getItem1()] && currentNode != neighbor.getItem1() && !InStack[neighbor.getItem1()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getItem1());
                        InStack[neighbor.getItem1()] = true;
                    }
                    if (!visited[neighbor.getItem2()] && currentNode != neighbor.getItem2() && !InStack[neighbor.getItem2()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getItem2());
                        InStack[neighbor.getItem2()] = true;
                    }
                    if (!visited[neighbor.getItem3()] && currentNode != neighbor.getItem3() && !InStack[neighbor.getItem3()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getItem3());
                        InStack[neighbor.getItem3()] = true;
                    }
                    if (!visited[neighbor.getItem4()] && currentNode != neighbor.getItem4() && !InStack[neighbor.getItem4()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getItem4());
                        InStack[neighbor.getItem4()] = true;
                    }
                    if (!visited[neighbor.getBoots()] && currentNode != neighbor.getBoots() && !InStack[neighbor.getBoots()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getBoots());
                        InStack[neighbor.getBoots()] = true;
                    }
                    if (!visited[neighbor.getMythic()] && currentNode != neighbor.getMythic() && !InStack[neighbor.getMythic()]) { //O(1)
                        stackOfNeighbors.push(neighbor.getMythic());
                        InStack[neighbor.getMythic()] = true;
                    }

                }
            }
        }
        return retVec;
    }

    vector<ChampionBuild> BFS_getAllOfChamp(string champ, string startNode) {

        vector<ChampionBuild> retVec;

        queue <string> Neighborsqueue;
        unordered_map<string, bool> visited;
        unordered_map<string, bool> InQueue;

        Neighborsqueue.push(startNode);


        int cnt = 0;
        while (!Neighborsqueue.empty()) {
            cnt++;
            string currentNode = Neighborsqueue.front();
            Neighborsqueue.pop();
            if (!visited[currentNode]) {
                visited[currentNode] = true;
                // Process the current node (e.g., print or perform some operation)
                for (int i = 0; i < g[currentNode].size(); i++) {
                    if (g[currentNode][i].getChamp() == champ)
                        addWithOutDuplicates(retVec, g[currentNode][i]);
                }

                visited[currentNode] = true;
                // Push unvisited neighbors onto the queue
                for (int i = 0; i < g[currentNode].size(); ++i) {
                    ChampionBuild neighbor = g[currentNode][i];
                    if (!visited[neighbor.getItem1()] && currentNode != neighbor.getItem1() && !InQueue[neighbor.getItem1()]) {
                        Neighborsqueue.push(neighbor.getItem1());
                        InQueue[neighbor.getItem1()] = true;
                    }
                    if (!visited[neighbor.getItem2()] && currentNode != neighbor.getItem2() && !InQueue[neighbor.getItem2()]) {
                        Neighborsqueue.push(neighbor.getItem2());
                        InQueue[neighbor.getItem2()] = true;
                    }
                    if (!visited[neighbor.getItem3()] && currentNode != neighbor.getItem3() && !InQueue[neighbor.getItem3()]) {
                        Neighborsqueue.push(neighbor.getItem3());
                        InQueue[neighbor.getItem3()] = true;
                    }
                    if (!visited[neighbor.getItem4()] && currentNode != neighbor.getItem4() && !InQueue[neighbor.getItem4()]) {
                        Neighborsqueue.push(neighbor.getItem4());
                        InQueue[neighbor.getItem4()] = true;
                    }
                    if (!visited[neighbor.getBoots()] && currentNode != neighbor.getBoots() && !InQueue[neighbor.getBoots()]) {
                        Neighborsqueue.push(neighbor.getBoots());
                        InQueue[neighbor.getBoots()] = true;
                    }
                    if (!visited[neighbor.getMythic()] && currentNode != neighbor.getMythic() && !InQueue[neighbor.getMythic()]) {
                        Neighborsqueue.push(neighbor.getMythic());
                        InQueue[neighbor.getMythic()] = true;
                    }

                }
            }
        }
        return retVec;

    }

    vector<ChampionBuild> get6Builds(string champ, bool BFSorDFS) {
        //DFS = true
        //BFS = false

        vector<ChampionBuild> retVec;
        vector<ChampionBuild> temp;
        std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

        // "Zhonya's Hourglass "is the start node
        if (BFSorDFS) {
            temp = DFS_getAllOfChamp(champ, "Zhonya's Hourglass");
        }
        else {
            temp = BFS_getAllOfChamp(champ, "Zhonya's Hourglass");
        }

        set<int> randNums;
        while(randNums.size() < 6){
            unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> distribution(0, temp.size()-1);
            int randomNumber = distribution(generator);
            randNums.insert(randomNumber);
        }
        for (int i = 0; i < 6; i++) {
            auto it = randNums.begin();
            retVec.push_back(temp[*it]);
            randNums.erase(it);
        }
        std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
        std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;
        timing = duration.count();
        return retVec;

    }

    void printBuilds(vector<ChampionBuild> temp){
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i].getBuild() << endl;
        }
    }

    string getTime(){
        return to_string(timing);
    }

};

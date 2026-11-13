#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph {
public:
    vector<vector<Pair>> adjList;
    vector<string> nodeNames;

    Graph(vector<Edge> const &edges) {
        adjList.resize(SIZE);
        
        nodeNames = {
            "Main Pokémon Center Warehouse (HQ)",  // 0
            "Indigo Plateau League Store",         // 1
            "Celadon City Game Corner & Shop",     // 2
            "Saffron City PokéMart",               // 3
            "Cerulean City Hobby Shop",            // 4
            "Lavender Town Card Shop",             // 5
            "Vermilion Port Trading Post",         // 6
            "Fuchsia City Collector Hub",          // 7
            "Cinnabar Island Express Depot"        // 8
        };

        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Custom capacity formula so numbers don't match the water example
    int calculateCapacity(int src, int dest, int weight) {
        return (weight * 150) + 250; // Distinct scaling for TCG shipment cartons
    }

    void printTopology() {
        cout << "Pokémon Merchandise Distribution Network Topology:" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Retail Hub " << i << " (" << nodeNames[i] << ") connects to:" << endl;
            for (Pair v : adjList[i]) {
                int capacity = calculateCapacity(i, v.first, v.second);
                cout << "  → Retail Hub " << v.first << " (" << nodeNames[v.first] << ") - Shipment Capacity: " << capacity << " Booster Cases" << endl;
            }
        }
        cout << endl;
    }

    void dfsTrace(int startVertex) {
        vector<bool> visited(SIZE, false);
        stack<int> s;
        s.push(startVertex);

        cout << "Network Trace (DFS) from Hub " << startVertex << " (" << nodeNames[startVertex] << "):" << endl;
        cout << "Purpose: Tracing emergency restock delivery paths through the supply chain" << endl;
        cout << "========================================================================" << endl;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                cout << "Inspecting Hub " << curr << " (" << nodeNames[curr] << ")" << endl;

                for (int i = 0; i < adjList[curr].size(); ++i) {
                    int adjVertex = adjList[curr][i].first;
                    int cap = calculateCapacity(curr, adjVertex, adjList[curr][i].second);
                    if (!visited[adjVertex]) {
                        cout << "  → Potential shipment route to Hub " << adjVertex << " (" << nodeNames[adjVertex] << ") - Capacity: " << cap << " Cases" << endl;
                        s.push(adjVertex);
                    }
                }
            }
        }
        cout << endl;
    }

    void bfsTrace(int startVertex) {
        vector<bool> visited(SIZE, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Layer-by-Layer Network Inspection (BFS) from Hub " << startVertex << " (" << nodeNames[startVertex] << "):" << endl;
        cout << "Purpose: Analyzing regional delivery tiers by distance from main warehouse" << endl;
        cout << "========================================================================" << endl;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "Checking Hub " << curr << " (" << nodeNames[curr] << ")" << endl;

            for (Pair v : adjList[curr]) {
                int adjVertex = v.first;
                int cap = calculateCapacity(curr, adjVertex, v.second);
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    cout << "  → Next delivery tier: Hub " << adjVertex << " (" << nodeNames[adjVertex] << ") - Capacity: " << cap << " Cases" << endl;
                    q.push(adjVertex);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    vector<Edge> edges = {
        {0, 1, 8}, {0, 2, 21},
        {1, 2, 6}, {1, 3, 5}, {1, 4, 4},
        {2, 7, 11}, {2, 8, 8},
        {3, 4, 9},
        {5, 6, 10}, {5, 7, 15}, {5, 8, 5},
        {6, 7, 3}, {6, 8, 7}
    };

    Graph network(edges);

    network.printTopology();
    network.dfsTrace(0);
    network.bfsTrace(0);
    
    return 0;
}
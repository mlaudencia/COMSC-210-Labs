// COMSC-210 | Lab 34 | Jeremy Laudencia

// Here, the LLM added <iostream> and <string> to handle the printing to the 
//console, <vector> for the graph, <queue> for BFS, <stack> for DFS, and
// <climits> for Dijkstra's Algorithm, and <algorithm> for the sort for MST.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

const int SIZE = 9;
const int CAPACITY_MULTIPLIER = 150;
const int CAPACITY_ADDITIVE = 250;

struct Edge {
    int src, dest, weight;
    
    // Comparator for sorting edges in Kruskal's algorithm (Step 5)
    // BELOW WAS STEP 5
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) helper structure for Kruskal's MST algorithm
// ALSO FOR STEP 5
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Prototypes
void bfsTrace(int startVertex);
int calculateCapacity(int src, int dest, int weight);
void printTopology();
void dfsTrace(int startVertex);
void shortestPathDijkstra(int startVertex);
void findMinimumSpanningTree();

typedef pair<int, int> Pair;

class Graph {
public:
    vector<vector<Pair>> adjList;
    vector<string> nodeNames;
    vector<Edge> allEdges; // Stored for MST calculation

    Graph(vector<Edge> const &edges) {
        adjList.resize(SIZE);
        allEdges = edges; // Save edges for Kruskal's algorithm
        
        nodeNames = {
            "Main Pokemon Center Warehouse (HQ)",  // 0
            "Indigo Plateau League Store",         // 1
            "Celadon City Game Corner & Shop",     // 2
            "Saffron City PokeMart",               // 3
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

    // calculateCapacity() scales the weight to be different for the program
    // compared to the example.
    // arguments: int src, int dest, int weight
    // returns: an integer
    int calculateCapacity(int src, int dest, int weight) {
        return (weight * CAPACITY_MULTIPLIER) + CAPACITY_ADDITIVE; // Distinct scaling for TCG shipment cartons
    }

    // printTopology() prints out each Pokemon hub and its adjacent hubs along
    // with each of their capacities.
    // arguments: none
    // returns: nothing
    void printTopology() {
        cout << "\nPokemon Merchandise Distribution Network Topology:" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Retail Hub " << i << " (" << nodeNames[i] << ") connects to:" << endl;
            for (Pair v : adjList[i]) {
                int capacity = calculateCapacity(i, v.first, v.second);
                cout << "  > Retail Hub " << v.first << " (" << nodeNames[v.first] << ") - Shipment Capacity: " << capacity << " Booster Cases" << endl;
            }
        }
        cout << endl;
    }

    // dfsTrace() follows a path of Pokemon hubs as deep as it can until it
    // reaches an end, then it goes down an untraversed path. This search uses
    // a stack to traverse through the hubs.
    // arguments: int startVertex
    // returns: nothing
    void dfsTrace(int startVertex) {
        vector<bool> visited(SIZE, false);
        stack<int> s;
        s.push(startVertex);

        cout << "\nNetwork Trace (DFS) from Hub " << startVertex << " (" << nodeNames[startVertex] << "):" << endl;
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
                        cout << "  > Potential shipment route to Hub " << adjVertex << " (" << nodeNames[adjVertex] << ") - Capacity: " << cap << " Cases" << endl;
                        s.push(adjVertex);
                    }
                }
            }
        }
        cout << endl;
    }

    // bfsTrace() traverses through the hubs by exploring each neighbor of the
    // startVertex. This search uses a queue to traverse through the hubs.
    // arguments: int startVertex
    // returns: nothing
    void bfsTrace(int startVertex) {
        vector<bool> visited(SIZE, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "\nLayer-by-Layer Network Inspection (BFS) from Hub " << startVertex << " (" << nodeNames[startVertex] << "):" << endl;
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
                    cout << "  > Next delivery tier: Hub " << adjVertex << " (" << nodeNames[adjVertex] << ") - Capacity: " << cap << " Cases" << endl;
                    q.push(adjVertex);
                }
            }
        }
        cout << endl;
    }

    // shortestPathDijkstra() finds the shortest path from a given vertex to
    // every other vertex on the graph.
    // arguments: int startVertex
    // returns: nothing
    void shortestPathDijkstra(int startVertex) {
        vector<int> dist(SIZE, INT_MAX);
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        dist[startVertex] = 0;
        pq.push({0, startVertex});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // I was a bit confused by this at first, but I understand now
                // as the distance or weight a hub has.
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest delivery path cost from Hub " << startVertex << " (" << nodeNames[startVertex] << "):" << endl;
        cout << "=========================================================================" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << startVertex << " -> " << i << " : " << dist[i] << endl;
        }
        cout << endl;
    }

    // Step 5: Minimum Spanning Tree (Kruskal's Algorithm)
    // ALSO FOR STEP 5

    // findMinimumSpanningTree() finds the lowest cost way for all hubs to be
    // connected to each other.
    // arguments: nothing
    // returns: nothing
    void findMinimumSpanningTree() {
        vector<Edge> edgesSorted = allEdges;
        sort(edgesSorted.begin(), edgesSorted.end());

        DisjointSet ds(SIZE);
        cout << "\nMinimum Spanning Tree edges:" << endl;
        cout << "===========================" << endl;

        for (auto &edge : edgesSorted) {
            int rootSrc = ds.find(edge.src);
            int rootDest = ds.find(edge.dest);

            if (rootSrc != rootDest) {
                ds.unite(rootSrc, rootDest);
                cout << "Edge from " << edge.src << " to " << edge.dest << " with capacity: " << edge.weight << " units" << endl;
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
    int choice;

    do {
        cout << "Pokemon Distribution Network Menu:" << endl;
        cout << "[1] Display Pokemon distribution network" << endl;
        cout << "[2] Check contaminant spread (BFS)" << endl;
        cout << "[3] Plan inspection route  (DFS)" << endl;
        cout << "[4] Calculate shortest paths" << endl;
        cout << "[5] Find Minimum Spanning Tree" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                network.printTopology();
                break;
            case 2:
                network.bfsTrace(0);
                break;
            case 3:
                network.dfsTrace(0);
                break;
            case 4:
                network.shortestPathDijkstra(0);
                break;
            case 5:
                network.findMinimumSpanningTree();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n" << endl;
        }
    } while (choice != 0);
    
    return 0;
}
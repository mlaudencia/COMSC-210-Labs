#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 9;
struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair; // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);
        // add edges to the directed graph
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // for an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph() {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    // Depth-First Search (DFS)
    void dfs(int startVertex) {
        vector<bool> visited(SIZE, false);
        stack<int> s;
        s.push(startVertex);

        cout << "DFS starting from vertex " << startVertex << ":" << endl;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                cout << curr << " ";

                // Iterate forward (0 to size-1) so the last neighbor (3) 
                // is pushed last and ends up on top of the stack
                for (int i = 0; i < adjList[curr].size(); ++i) {
                    int adjVertex = adjList[curr][i].first;
                    if (!visited[adjVertex]) {
                        s.push(adjVertex);
                    }
                }
            }
        }
        cout << endl;
    }

    // Breadth-First Search (BFS)
    void bfs(int startVertex) {
        vector<bool> visited(SIZE, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS starting from vertex " << startVertex << ":" << endl;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (Pair v : adjList[curr]) {
                int adjVertex = v.first;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        {0, 1, 8}, {0, 2, 21},
        {1, 2, 6}, {1, 3, 5}, {1, 4, 4},
        {2, 7, 11}, {2, 8, 8},
        {3, 4, 9},
        {5, 6, 10}, {5, 7, 15}, {5, 8, 5},
        {6, 7, 3}, {6, 8, 7}
    };  

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    // Perform DFS and BFS starting from vertex 0
    graph.dfs(0);
    graph.bfs(0);
    
    return 0;
}
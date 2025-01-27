#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Data structure to represent a connected, undirected, weighted graph
class Graph {
public:
    int V, E; // Number of vertices and edges in the graph
    vector<Edge> edges; // Vector to store edges of the graph

    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    // Function to find the subset of an element 'i'
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Function to perform union of two subsets
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // Function to implement Kruskal's algorithm
    void KruskalMST() {
        vector<Edge> result; // This will store the resultant MST

        // Step 1: Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        // Allocate memory for creating V subsets
        vector<int> parent(V, -1);

        int edge_count = 0; // An index variable used for result[]

        // Number of edges to be taken is equal to V-1
        while (edge_count < V - 1 && !edges.empty()) {
            // Step 2: Pick the smallest edge. And increment the index for next iteration
            Edge next_edge = edges.front();
            edges.erase(edges.begin());

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            // If including this edge doesn't cause a cycle, include it in the result
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
                edge_count++;
            }
        }

        // Print the contents of result[] to display the built MST
        cout << "Edges of Minimum Spanning Tree:\n";
        int minimumCost = 0;
        for (Edge edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
            minimumCost += edge.weight;
        }
        cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
    }
};

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph(V, E);

    // add edge: src, dest, weight
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find Minimum Spanning Tree
    graph.KruskalMST();

    return 0;
}

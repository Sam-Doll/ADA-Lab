#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

// Comparator function to sort edges by weight
bool compare(Edge &a, Edge &b) {
    return a.weight < b.weight;
}

// Union-find data structure
vector<int> parent;

int find(int i) {
    while(parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Kruskal's Algorithm to find MST
int kruskal(int n, vector<Edge>& edges) {
    // Sort edges in increasing order of weight
    sort(edges.begin(), edges.end(), compare);

    // Initialize parent array
    parent.resize(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int minCost = 0; // Total cost of MST
    int edgeCount = 0; // Count of edges added to MST

    // Process edges one by one
    for(int i = 0; i < edges.size() && edgeCount < n - 1; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // If the edge does not form a cycle
        if(find(src) != find(dest)) {
            minCost += weight; // Add the weight of the edge to MST
            unionSet(src, dest); // Union the sets of the two vertices
            edgeCount++;

            // Print the selected edge
            cout << src << " -- " << dest << " = " << weight << endl;
        }
    }

    if(edgeCount != n - 1) {
        cout << "Graph is not connected, so MST is not possible." << endl;
        return -1;
    }
    else {
        return minCost;
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };

    cout << endl << "Minimum Spanning Tree cost: " << kruskal(n, edges) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, minIndex;
    
    // Find the vertex with the smallest key value that hasn't been included in MST
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[V][V]) {
    // Array to store the constructed MST
    vector<int> parent(V);
    
    // Key values to pick minimum weight edge in cut
    vector<int> key(V, INT_MAX);
    
    // To represent the set of vertices not yet included in MST
    vector<bool> mstSet(V, false);
    
    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;
    
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST set
        mstSet[u] = true;
        
        // Update the key and parent values of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print the constructed MST
    cout << "Edge \t Weight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t " << graph[i][parent[i]] << endl;
    }
}

int main() {
    // Example graph represented by an adjacency matrix
    // A 5-vertex graph
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    // Call the function to construct the MST
    primMST(graph);
    
    return 0;
}

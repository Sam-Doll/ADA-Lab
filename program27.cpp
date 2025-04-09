#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 9

// Function to find the vertex with minimum distance value from the source
int minDistance(int dist[], bool S[]) {
    int min = INT_MAX;
    int min_index;

    for(int i = 0; i < V; i++) {
        if(S[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the solution
void printSolution(int dist[], int v) {
    cout << "Vertex \t Distance from Source\n";
    for(int i = 0; i < v; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    bool S[V];  // S[] stores whether a vertex is included in the shortest path tree or not
    int dist[V]; // dist[i] holds the minimum distance from source to vertex i

    // Initialize all distances as INFINITE and S[i] as false
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        S[i] = false;
    }

    // Distance of source vertex from itself is 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for(int i = 1; i < V; i++) {
        // Pick the vertex with the minimum distance value that is not yet processed
        int u = minDistance(dist, S);

        // Mark the picked vertex as processed
        S[u] = true;

        // Update dist values of the adjacent vertices of the picked vertex
        for(int j = 0; j < V; j++) {
            // Update dist[j] if:
            // 1. vertex j is not in the shortest path tree (S[j] is false)
            // 2. there is an edge from u to j
            // 3. the total weight of the path from source to j through u is smaller than the current value of dist[j]
            if(!S[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j]; // Relaxation
            }
        }
    }

    // Print the shortest distances
    printSolution(dist, V);
}

int main() {
    // Graph represented as an adjacency matrix
    int graph[V][V] = { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    // Call Dijkstra's algorithm for the source vertex 0
    dijkstra(graph, 0);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &adj, int n)
{
    // Floyd-Warshall algorithm to find the shortest path between all pairs of vertices
    for(int k = 0; k < n; k++) // k is the intermediate vertex
    {
        for(int i = 0; i < n; i++) // i is the source vertex
        {
            for(int j = 0; j < n; j++) // j is the destination vertex
            {
                // If there's no direct edge between i and j, or if the new path is shorter than the current one
                if(((adj[i][j] == -1) || (adj[i][j] > adj[i][k] + adj[k][j])) && (adj[k][j] != -1 && adj[i][k] != -1))
                {
                    adj[i][j] = adj[i][k] + adj[k][j]; // Update the shortest path from i to j
                }
            }
        }
    }
}

int main()
{
    int n = 4; // Number of vertices
    // -1 in graph represents there is no direct edge between the vertices
    // Weights in graph can be negative but not -1 (as it represents INFINITY)
    vector<vector<int>> graph = {
        {0, 3, -1, 7},  // Edge weights between vertex 0 and other vertices
        {8, 0, -1, -1}, // Edge weights between vertex 1 and other vertices
        {-1, 1, 0, 2},  // Edge weights between vertex 2 and other vertices
        {-1, -1, -1, 0} // Edge weights between vertex 3 and other vertices
    };

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph, n);

    // Output the shortest distances matrix
    cout << "Shortest distances between every pair of vertices: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j] == -1) 
                cout << "INF" << " ";  // If there's no path, print INF
            else
                cout << graph[i][j] << " "; // Print the shortest path distance
        }
        cout << endl;
    }

    return 0;
}

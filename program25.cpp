#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Function to find the minimum cost path using dynamic programming
int multistageGraph(vector<vector<pair<int,int> > > &graph, int stages, int n)
{
    // cost[] stores the minimum cost from vertex i to reach the last node
    vector<int> cost(n, INF);
    // path[] helps reconstruct the shortest path
    vector<int> path(n, -1);

    // The cost to reach the last node is 0
    cost[n-1] = 0;

    // Traverse the graph from the second last node to the first node
    for(int i = n-2; i >= 0; i--)
    {
        for(auto edge: graph[i])
        {
            int v = edge.first; // destination vertex
            int w = edge.second; // weight of the edge

            // If a better path is found to reach vertex i
            if(w + cost[v] < cost[i] && cost[v] != INF)
            {
                cost[i] = w + cost[v];
                path[i] = v;
            }
        }
    }

    // Print the minimum cost from source to destination
    cout << "Minimum cost: " << cost[0] << endl;

    // Print the shortest path using backtracking
    cout << "Path: ";
    int curr = 0;
    while (curr != -1) {
        cout << curr << " ";
        curr = path[curr];
    }
    cout << endl;
}

int main()
{
    int n = 8; // Number of vertices
    int stages = 4; // Number of stages
    vector<vector<pair<int, int>>> graph(n);

    // Creating the graph: graph[i] stores (destination, weight) pairs
    graph[0] = {{1, 1}, {2, 2}, {3, 5}};
    graph[1] = {{4, 4}, {5, 11}};
    graph[2] = {{4, 9}, {5, 5}, {6, 16}};
    graph[3] = {{6, 2}};
    graph[4] = {{7, 18}};
    graph[5] = {{7, 13}};
    graph[6] = {{7, 2}};

    // Call the function to find the minimum cost path
    multistageGraph(graph, stages, n);

    return 0;
}

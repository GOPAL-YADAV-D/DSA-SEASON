#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::cout << "Enter number of vertices and edges: ";
    std::cin >> n >> m;

    // Adjacency Matrix Representation in case of zero-based Indexing
    int adjMatrix[n][n];

    // Adjacency Matrix For 1-based Indexing
    // int adMatrix[n+1][n+1];

    for(int i=0 ; i<m ; i++){
        int u, v;
        std::cout << "Enter edge " << i+1 << " (u v): ";
        std::cin >> u >> v;

        // For unweighted graph 
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // For weighted Graph
        // int w;
        // adjMatrix[u][v] = w;
    }


    // Adjacency List Representation
    std::vector<int> adjList[n];
    // weighted adjacency list
    // std::vector<std::pair<int, int>> adjList[n];

    for(int i=0 ; i<m ; i++){
        int u, v;
        std::cout << "Enter edge " << i+1 << " (u v) : ";
        std::cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        // For weighted Graph
        // int w;
        // adjList[u].push_back((v, w));
    }

}
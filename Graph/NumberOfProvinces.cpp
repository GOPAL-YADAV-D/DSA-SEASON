#include <iostream>
#include <vector>

int findCircleNum(std::vector<std::vector<int>>& isConnected){
    // A question of zero indexed isConnected matrix
    std::vector<bool> visited(isConnected.size(), false);
    int provinces = 0;
    for(int i=0 ; i<isConnected.size() ; i++){
        if(!visited[i]){
            provinces++;
            std::vector<int> queue;
            queue.push_back(i);

            while(!queue.empty()){
                int node = queue.front();
                queue.erase(queue.begin());
                visited[node] = true;
                for(int neighbour =0 ; neighbour<isConnected.size() ; neighbour++){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        queue.push_back(neighbour);
                    }
                }
            }
        }
    }

    return provinces;
}   


int main(){
    // Graph Input using Adjacency Matrix
    int nodes, edges;
    std::cin >> nodes >> edges;
    
    std::vector<std::vector<int>> isConnected;

    for(int i=0 ; i<edges ; i++){
        int source, destination;
        std::cin >> source >> destination;
        isConnected[source][destination] = 1;
        isConnected[destination][source] = 1;
    }

    int provinces = findCircleNum(isConnected);
}


#include <iostream>
#include <vector>

int main(){
    int n , m;
    std::cin >> n >> m;
    std::vector<int> adj[n+1];

    for(int i=0 ; i< m ; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    std::vector<bool> visited(n+1, false);
    std::vector<int>bfs;

    std::vector<int> queue;
    queue.push_back(1);
    visited[1] = true;

    while(!queue.empty()){
        int node = queue.front();
        queue.erase(queue.begin());
        bfs.push_back(node);

        for(int neighbor : adj[node]){
            if((!visited[neighbor])){
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }

    for(int i=0 ; i<bfs.size() ; i++){
        std::cout << bfs[i] << " " ;
    }
}
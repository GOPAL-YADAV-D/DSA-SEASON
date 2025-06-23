#include <iostream>
#include <vector>
#include <stack>

void dfs(int node, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, std::vector<int>& dfsOrder){
    visited[node] = true;
    dfsOrder.push_back(node);

    for(int neightbor : adjList[node]){
        if(!visited[neightbor]){
            dfs(neightbor, adjList, visited, dfsOrder);
        }
    }
}

int main(){
    // Got the Graph Input as an adjacency list 
    std::vector<bool> visited(n+1, false);
    std::stack<int> stack;
    std::vector<int>dfsOrder;

    stack.push(start);
    
    while(!stack.empty()){
     int node = stack.top();
     stack.pop();

     if(!visited[node){
        visited[node] = true;
        dfsOrder.push_back(node);

            for(int neighbor : adjList[node]){
                if(!visited[neighbor]){
                    stack.push(neighbor);
                }
            }
     }
    }
}
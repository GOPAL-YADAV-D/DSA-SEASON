#include <iostream>
#include <vector>
#include <queue>


int numberOfIslands(std::vector<std::vector<int>>& grid){
    // The first step is to find the number of rows and number of columns
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Usually the directions in which a step inside the grid can be taken is mentioned
    // For this question the step is 4 directional that is it can be either horizonal or vertical
    
    std::vector<std::pair<int,int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };
    
    // Now the task is to iterate over all map and find the cells with land and then mark an island visited and then repeat until all the islands have been visited
    
    // count of the number of islands
    int numberOfIslands = 0;
    
    // Using BFS
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(grid[i][j] == 1){
                numberOfIslands++;
                
                std::queue<std::pair<int,int>> queue;
                queue.push({i,j});
                grid[i][j] = 0;
                
                while(!queue.empty()){
                    auto [x,y] = queue.front();
                    queue.pop();
                    
                    for(auto [dx,dy] : directions){
                        int nx = x + dx;
                        int ny = y + dy;
                        
                        if(nx >= 0 && ny >=0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                            queue.push({nx,ny});
                            grid[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }
    
    return numberOfIslands;
}

int main(){
    int rows, cols;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;    

    std::vector<std::vector<int>> mapGrid;
    
    for(int i=0 ; i<rows ; i++){
        std::vector<int> row;
        for(int j=0 ; j<cols ; j++){
            int element;
            std::cin >> element;
            row.push_back(element);
        }
        mapGrid.push_back(row);
    }
}


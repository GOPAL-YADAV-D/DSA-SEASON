#include <iostream>
#include <vector>
#include <stack>

void maxIslandArea(std::vector<std::vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    
    std::vector<std::pair<int,int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };
    
    int maxArea = 0;
    
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(grid[i][j] == 1){
                std::stack<std::pair<int,int>> stack;
                stack.push({i,j});
                grid[i][j] = 0;
                int currentArea = 0;
                
                while(!stack.empty()){
                    auto [x,y] = stack.top();
                    stack.pop();
                    currentArea++;
                    
                    for(auto [dx,dy]: directions){
                        int nx = x + dx;
                        int ny = y + dy;
                        
                        if(nx >=0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                            stack.push({nx,ny});
                            grid[nx][ny] =0;
                        }
                    }
                }
                
                maxArea = (currentArea > maxArea)? currentArea:maxArea;
            }
        }
    }
    
    std::cout << "Max Island Area is: " << maxArea;
    return;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> mapGrid(rows, std::vector<int>(cols));

    std::cout << "Enter the grid values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> mapGrid[i][j];
        }
    }
    
    maxIslandArea(mapGrid);
    
    return 0;
}
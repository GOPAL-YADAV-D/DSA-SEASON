#include <iostream>
#include <vector>
#include <queue>

int timeToRot(std::vector<std::vector<int>>& fruitGrid){
    int rows = fruitGrid.size();
    int cols = fruitGrid[0].size();
    
    std::vector<std::pair<int,int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };
    
    std::queue<std::pair<int,int>> queue;
    
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(fruitGrid[i][j] == 2) queue.push({i,j});
        }
    }
    
    int minutes = 0;
    
    while(!queue.empty()){
        int size = queue.size();
        bool newRot = false;
        
        while(size--){
            auto [x,y] = queue.front();
            queue.pop();
            
            for(auto [dx,dy]:directions){
                int nx = x + dx, ny = y + dy;
                
                if(nx >=0 && ny >= 0 && nx < rows && ny <cols && fruitGrid[nx][ny] == 1){
                    fruitGrid[nx][ny] = 2;
                    queue.push({nx,ny});
                    newRot = true;
                }
            }
        }
        
        if(newRot) minutes++;
    }
    
    return minutes;
}

int main(){
    int rows, cols;
    std::cout << "Enter the Rows and Columns: ";
    std::cin >> rows >> cols;
    
    std::vector<std::vector<int>> fruitPeti;
    
    for(int i=0 ; i<rows ; i++){
        std::vector<int>row;
        for(int j=0 ; j<cols ; j++){
            int cellValue;
            std::cin >> cellValue;
            row.push_back(cellValue);
        }
        fruitPeti.push_back(row);
    }
}
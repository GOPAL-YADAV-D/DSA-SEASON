#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void printGrid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::cout << "[ ";
    for (int i = 0; i < rows; i++) {
        std::cout << "[ ";
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

void floodFill(int sr, int sc, int color, std::vector<std::vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[sr][sc] == color) return;

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    int originalColor = grid[sr][sc];
    std::stack<std::pair<int,int>> stack;
    stack.push({sr,sc});
    
    while(!stack.empty()){
        auto [x,y] = stack.top();
        stack.pop();
        grid[x][y] = color;
        
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == originalColor) {
                stack.push({nx, ny});
            }
        }
    }
    
    return;
}

void floodFill(std::vector<std::vector<int>>& grid, int sr, int sc, int color) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[sr][sc] == color) return;

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int originalColor = grid[sr][sc];
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    grid[sr][sc] = color;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == originalColor) {
                grid[nx][ny] = color;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> imageGrid(rows, std::vector<int>(cols));

    std::cout << "Enter the grid values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> imageGrid[i][j];
        }
    }

    int sr, sc, color;
    std::cout << "Enter the Starting Row, Column, and New Color: ";
    std::cin >> sr >> sc >> color;

    std::cout << "Original Grid:\n";
    printGrid(imageGrid);

    floodFill(imageGrid, sr, sc, color);

    std::cout << "Grid After Flood Fill:\n";
    printGrid(imageGrid);

    return 0;
}

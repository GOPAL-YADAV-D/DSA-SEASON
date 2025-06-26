#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

void distanceToRoom(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                q.push({i, j});
            }
        }
    }


    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                grid[nx][ny] != -1 && grid[nx][ny] > grid[x][y] + 1) {
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> buildingMap;

    std::cout << "Enter the grid values (use 0 for gate, -1 for wall, and a large number like 2147483647 for empty rooms):\n";
    for (int i = 0; i < rows; i++) {
        std::vector<int> row;
        for (int j = 0; j < cols; j++) {
            int mapValue;
            std::cin >> mapValue;
            row.push_back(mapValue);
        }
        buildingMap.push_back(row);
    }

    distanceToRoom(buildingMap);

    std::cout << "Updated grid:\n";
    for (auto& row : buildingMap) {
        for (int val : row) {
            if (val == INT_MAX)
                std::cout << "INF ";
            else
                std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

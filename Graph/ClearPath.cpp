#include <iostream>
#include <vector>
#include <queue>

int shortestPath(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] != 0 || grid[rows - 1][cols - 1] != 0) return -1;

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;  // use 1 as starting step count

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == rows - 1 && y == cols - 1) return grid[x][y];

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0) {
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> regionalMap(rows, std::vector<int>(cols));

    std::cout << "Enter the grid (0 = empty, 1 = blocked):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> regionalMap[i][j];
        }
    }

    int shortestDistance = shortestPath(regionalMap);
    if (shortestDistance == -1) {
        std::cout << "No path exists\n";
    } else {
        std::cout << "Shortest Distance is: " << shortestDistance << "\n";
    }

    return 0;
}

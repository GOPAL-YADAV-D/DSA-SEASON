#include <iostream>
#include <vector>
#include <stack>

void markingRegions(std::vector<std::vector<char>>& grid, int sr, int sc) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    std::stack<std::pair<int, int>> s;
    s.push({sr, sc});
    grid[sr][sc] = 'G'; // Mark as safe

    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 'O') {
                s.push({nx, ny});
                grid[nx][ny] = 'G';
            }
        }
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> regionalMap(rows, std::vector<char>(cols));

    std::cout << "Enter the grid (O or X):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> regionalMap[i][j];
        }
    }

    // Mark safe regions connected to border
    for (int i = 0; i < rows; i++) {
        if (regionalMap[i][0] == 'O') markingRegions(regionalMap, i, 0);
        if (regionalMap[i][cols - 1] == 'O') markingRegions(regionalMap, i, cols - 1);
    }

    for (int i = 0; i < cols; i++) {
        if (regionalMap[0][i] == 'O') markingRegions(regionalMap, 0, i);
        if (regionalMap[rows - 1][i] == 'O') markingRegions(regionalMap, rows - 1, i);
    }

    // Final conversion
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (regionalMap[i][j] == 'G') regionalMap[i][j] = 'O';
            else if (regionalMap[i][j] == 'O') regionalMap[i][j] = 'X';
        }
    }

    // Print result
    std::cout << "Processed grid:\n";
    for (const auto& row : regionalMap) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

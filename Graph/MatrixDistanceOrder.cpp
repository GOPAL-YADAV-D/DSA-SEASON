#include <iostream>
#include <vector>
#include <queue>

void matrixDistance(int rows, int cols, int rCenter, int cCenter) {
    if (rows == 0 || cols == 0) return;

    std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, -1));
    std::vector<std::pair<int, int>> distanceOrder;

    std::queue<std::pair<int, int>> q;
    q.push({rCenter, cCenter});
    matrix[rCenter][cCenter] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        distanceOrder.push_back({x, y});

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && matrix[nx][ny] == -1) {
                matrix[nx][ny] = matrix[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    std::cout << "Cells in order of increasing Manhattan distance:\n";
    for (auto [x, y] : distanceOrder) {
        std::cout << "(" << x << ", " << y << ") ";
    }
    std::cout << std::endl;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of Rows and Columns: ";
    std::cin >> rows >> cols;

    int rCenter, cCenter;
    std::cout << "Enter the Starting Position Row and Column: ";
    std::cin >> rCenter >> cCenter;

    matrixDistance(rows, cols, rCenter, cCenter);

    return 0;
}

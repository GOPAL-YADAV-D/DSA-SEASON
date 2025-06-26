#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, -1));

    // Start BFS from all 0s
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    std::vector<std::pair<int,int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for(auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist;
}

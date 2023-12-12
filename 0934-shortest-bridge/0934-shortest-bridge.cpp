class Solution {
private:
    vector<vector<int>> next;

    bool isValidCell(int i, int j, int m, int n) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }

    void traceIsland(vector<vector<int>>& grid, int m, int n, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int i, int j) {
        visited[i][j] = true;
        q.push({i, j});
        for (auto& dir: next) {
            int i1 = i + dir[0], j1 = j + dir[1];
            if (isValidCell(i1, j1, m, n) && grid[i1][j1] == 1 && !visited[i1][j1]) {
                traceIsland(grid, m, n, visited, q, i1, j1);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        next = vector<vector<int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid[0].size(), dist = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    traceIsland(grid, m, n, visited, q, i, j);
                    i = m, j = n; // break out of both loops
                }
            }
        }
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                auto [x, y] = q.front(); q.pop();
                for (auto& dir: next) {
                    int x1 = x + dir[0], y1 = y + dir[1];
                    if (isValidCell(x1, y1, m, n) && !visited[x1][y1]) {
                        if (grid[x1][y1] == 0) { // water
                            q.push({x1, y1});
                            visited[x1][y1] = true;
                        } else if (grid[x1][y1] == 1) { // second island
                            return dist;
                        }
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};

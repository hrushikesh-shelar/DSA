class Solution {
    
    
    vector<vector<int>> DIR = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    
    bool isValid(int x, int y, int ROWS, int COLS) {
        if(x<0 || y<0 || x>=ROWS || y>=COLS) {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, int ROWS, int COLS, int& area) {
        if(!isValid(row, col, ROWS, COLS) || grid[row][col]!=1 || vis[row][col]) {
            return;
        }
        vis[row][col] = 1;
        area++;
        for(auto dir: DIR) {
            dfs(grid, vis, row+dir[0], col+dir[1], ROWS, COLS, area);
        }
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, 0));
        int res=0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    int area = 0;
                    dfs(grid, vis, i, j, ROWS, COLS, area);
                    res = max(area, res);
                }
            }
        }
        return res;
    }
};
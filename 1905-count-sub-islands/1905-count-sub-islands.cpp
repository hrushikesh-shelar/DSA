class Solution {
    vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool isValid(int x, int y, int ROWS, int COLS) {
        if(x<0 || y<0 || x>=ROWS || y>=COLS) {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis, int x, int y, int ROWS, int COLS, bool& subIsland) {
        if (!isValid(x, y, ROWS, COLS)) return;
        if (vis[x][y] || grid2[x][y]==0) return;
        vis[x][y] = true;
        if(grid1[x][y]!=grid2[x][y]) {
            subIsland = false;
        }
        for(auto dir: DIR) {
            int newX=x+dir[0], newY=y+dir[1];
            dfs(grid1, grid2, vis, newX, newY, ROWS, COLS, subIsland);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ROWS = grid1.size(), COLS = grid1[0].size();
        vector<vector<bool>> vis(ROWS, vector<bool> (COLS, false));
        int res=0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(grid2[i][j]==1 and !vis[i][j]) {
                    bool subIsland = true;
                    dfs(grid1, grid2, vis, i, j, ROWS, COLS, subIsland);
                    if(subIsland) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
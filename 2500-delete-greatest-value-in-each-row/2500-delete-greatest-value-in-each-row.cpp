class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> maxHeaps(grid.size());
        int res=0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
                maxHeaps[i].push(grid[i][j]);
        
        for(int j=0; j<grid[0].size(); j++) {
            int maxInt = 0;
            for(int i=0; i<grid.size(); i++) {
                maxInt = max(maxInt, maxHeaps[i].top());
                maxHeaps[i].pop();
            }
            res+=maxInt;
        }
        return res;
    }
};
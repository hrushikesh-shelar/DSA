class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=0,y=0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int totalSize = m * n;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        
        while(totalSize--) {
            // cout<<"x:"<<x<<" y:"<<y<<endl;
            // cout<<"x+directions[dir][0]:"<<x+directions[dir][0]<<" y+directions[dir][1]:"<<y+directions[dir][1]<<endl;
            // cout<<matrix[x+directions[dir][0]][y+directions[dir][1]]<<endl;
            res.push_back(matrix[x][y]);
            matrix[x][y] = 200;
            if((x+directions[dir][0]<m && x+directions[dir][0]>=0 && y+directions[dir][1]<n && y+directions[dir][1]>=0) && matrix[x+directions[dir][0]][y+directions[dir][1]]<200) {
                x=x+directions[dir][0];
                y=y+directions[dir][1];
                
            } else {
                dir++;
                if(dir>=directions.size()) {
                    dir = 0;
                }
                if((x+directions[dir][0]<m && x+directions[dir][0]>=0 && y+directions[dir][1]<n && y+directions[dir][1]>=0)) {
                    x=x+directions[dir][0];
                    y=y+directions[dir][1];
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
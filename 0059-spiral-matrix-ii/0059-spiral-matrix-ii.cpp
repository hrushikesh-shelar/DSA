class Solution {
public:

    bool isValid(int row, int col, int n) {
        return (row>=0 && col>=0 && row<n && col<n);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n, 0));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            if(!isValid(row + dir[d][0], col + dir[d][1], n) || result[row + dir[d][0]][col + dir[d][1]] != 0) {
                d = (d + 1) % 4;
            }
            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
};
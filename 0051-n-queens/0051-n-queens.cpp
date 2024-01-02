class Solution {
public:
    bool isDiagonallyValid(vector<string> &curr, int row, int col, int n) {
        for(int i=row-1; i>=0; i--) {
            if(col-(row-i)>=0 && curr[i][col-(row-i)]=='Q')
                return false;
            if(col+(row-i) < n && curr[i][col+(row-i)]=='Q')
                return false;
        }
        return true;
    }

    void backtrack(int n, vector<vector<string>>& res, int currIdx, vector<string>& curr, vector<int>&  filledCols) {
        if(currIdx==n) {
            res.push_back(curr);
            return;
        }
        for(int col=0; col<n; col++) {
            if(!filledCols[col] && isDiagonallyValid(curr, currIdx, col, n)) {
                filledCols[col] = 1;
                string newRow(n, '.');
                newRow[col]='Q';
                curr.push_back(newRow);
                backtrack(n, res, currIdx+1, curr, filledCols);
                curr.pop_back();
                filledCols[col] = 0;
            }
        }
    };
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr;
        vector<int> filledCols(n, 0);
        backtrack(n, res, 0, curr, filledCols);
        return res;
    }
};
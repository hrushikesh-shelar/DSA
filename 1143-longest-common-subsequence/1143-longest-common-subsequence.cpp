class Solution {
    int longestCommonSubsequenceRec(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& dp) {
        if(idx1>=text1.size() || idx2>=text2.size()) {
            return 0;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        if( text1[idx1]==text2[idx2] ) {
            return dp[idx1][idx2] = 1 + longestCommonSubsequenceRec(text1, text2, idx1+1, idx2+1, dp);
        }
        return dp[idx1][idx2] = max(longestCommonSubsequenceRec(text1, text2, idx1+1, idx2, dp), longestCommonSubsequenceRec(text1, text2, idx1, idx2+1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return longestCommonSubsequenceRec(text1, text2, 0, 0, dp);
    }
};
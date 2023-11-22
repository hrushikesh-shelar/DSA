class Solution {
    bool wordBreakRec(string& s, vector<string>& wordDict, int idx, vector<int>& dp) {
        if(idx>=s.size()) {
            return true;
        }
        if(dp[idx]!=-1) {
            return dp[idx];
        }
        
        bool ans = false;
        for(string word: wordDict) {
            if(s.substr(idx, word.size()) == word){
                ans = ans or wordBreakRec(s, wordDict, idx+word.size(), dp);
            }
            if(ans) {
                return dp[idx] = ans;
            }
        }
        return dp[idx]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return wordBreakRec(s, wordDict, 0, dp);
    }
};
class Solution {
    void wordBreakRec(string& s, vector<string>& wordDict, string currString, vector<string>& ans, int idx) {
        if(idx>=s.size()) {
            ans.push_back(currString);
            return;
        }
        
        for(string word: wordDict) {
            if(s.substr(idx, word.size())==word) {
                string currStringModified = currString.size()>0 ? (currString+" "+word) : word;
                wordBreakRec(s, wordDict, currStringModified, ans, idx+word.size());
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        // vector<vector<string>> dp(s.size());
        wordBreakRec(s, wordDict, "", ans, 0);
        return ans;
    }
};
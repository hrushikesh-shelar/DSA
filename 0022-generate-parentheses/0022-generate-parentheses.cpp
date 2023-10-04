class Solution {
public:
    void gen(int n, string s, int open, int close, vector<string>& res) {
        if(s.length() == 2*n) {
            res.push_back(s);
            return;
        }
        
        if(open<n) {
            gen(n, s+'(', open+1, close, res);
        }
        
        if(close<open) {
            gen(n, s+')', open, close+1, res);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen(n, "", 0, 0, res);
        return res;
    }
};
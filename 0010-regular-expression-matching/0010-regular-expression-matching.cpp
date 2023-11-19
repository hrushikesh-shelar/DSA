// . -> single character -> single case
// * -> 2 cases

class Solution {
    bool isMatchHelper(string& s, string& p, int si, int pi, vector<vector<int>>& memo) {
        if(si>=s.size() && pi>=p.size()) {
            return (true);
        }
        if(pi>=p.size()) {
            return false;
        }
        
        if(memo[si][pi]!=-1) {
            return memo[si][pi];
        }
        
        bool match = si<s.size() and (s[si]==p[pi] or p[pi]=='.');
        
        if ((pi+1)<p.size() && p[pi+1]=='*') {
            return memo[si][pi] = isMatchHelper(s, p, si, pi+2, memo) or (match and isMatchHelper(s, p, si+1, pi, memo));
        } 
        return memo[si][pi] = (match && isMatchHelper(s, p, si+1, pi+1, memo));
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(30, vector<int>(30, -1));
        return isMatchHelper(s, p, 0, 0, memo);
    }
};
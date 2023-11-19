// . -> single character -> single case
// * -> 2 cases

class Solution {
    bool isMatchHelper(string& s, string& p, int si, int pi) {
        if(si>=s.size() && pi>=p.size()) {
            return (true);
        }
        if(pi>=p.size()) {
            return false;
        }
        
        bool match = si<s.size() and (s[si]==p[pi] or p[pi]=='.');
        
        if ((pi+1)<p.size() && p[pi+1]=='*') {
            return isMatchHelper(s, p, si, pi+2) or (match and isMatchHelper(s, p, si+1, pi));
        } else if (match) {
            return isMatchHelper(s, p, si+1, pi+1);
        }
        
        return false;
        
    }
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }
};
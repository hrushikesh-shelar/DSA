class Solution {
public:
    bool isPre(vector<string>& strs, int idx) {
        if(idx>=strs[0].size()) return false;
        char ch = strs[0][idx];
        for(int i=1; i<strs.size(); i++) {
            if(idx<strs[i].size() and strs[i][idx]==ch)
                continue;
            return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int idx=0;
        while(isPre(strs, idx)) {
            res.push_back(strs[0][idx]);
            idx++;
        }
        return res;
    }
};
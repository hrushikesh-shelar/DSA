class Solution {
    string sortedString(string str) {
        sort(str.begin(), str.end());
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto str: strs) {
            mp[sortedString(str)].push_back(str);
        }
        for(auto x = mp.begin(); x!=mp.end(); x++) {
            res.push_back(x->second);
        }
        return res;
    }
};
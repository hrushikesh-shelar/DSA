class Solution {
public:
    
    void backtrack(string digits, unordered_map<char, vector<char>>& mob, vector<string>& res, int i, string curr) {
        
        if(i >= digits.size()) {
            res.push_back(curr);
            return;
        }
        
        for(char ch : mob[digits[i]]) {
            curr.push_back(ch);
            backtrack(digits, mob, res, i + 1, curr);
            curr.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<char>> mob;
        mob['2'] = {'a', 'b', 'c'};
        mob['3'] = {'d', 'e', 'f'};
        mob['4'] = {'g', 'h', 'i'};
        mob['5'] = {'j', 'k', 'l'};
        mob['6'] = {'m', 'n', 'o'};
        mob['7'] = {'p', 'q', 'r', 's'};
        mob['8'] = {'t', 'u', 'v'};
        mob['9'] = {'w', 'x', 'y', 'z'};
        
        int n = digits.size();
        if(n==0) {
            return {};
        }
        
        vector<string> res;
        backtrack(digits, mob, res, 0, "");
        return res;
    }
};

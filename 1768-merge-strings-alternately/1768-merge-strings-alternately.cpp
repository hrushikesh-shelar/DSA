class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int minLen = min(word1.size(), word2.size());
        int ptr = 0;
        while(ptr<minLen) {
            res.push_back(word1[ptr]);
            res.push_back(word2[ptr]);
            ptr++;
        }
        
        while(ptr<word1.size()) {
            res.push_back(word1[ptr]);
            ptr++;
        }
        while(ptr<word2.size()) {
            res.push_back(word2[ptr]);
            ptr++;
        }
        return res;
    };
};


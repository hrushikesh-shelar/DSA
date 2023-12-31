class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, vector<int>> chatToIndices;
        for(int i=0; i<s.size(); i++) {
            chatToIndices[s[i]].push_back(i);
        }
        int maxLen = -1;
        for(auto indices: chatToIndices) {
            if(indices.second.size()>1) {
                int n = indices.second.size();
                maxLen = max(maxLen, indices.second[n-1] - indices.second[0]-1);
            }
        }
        return maxLen;
    }
};
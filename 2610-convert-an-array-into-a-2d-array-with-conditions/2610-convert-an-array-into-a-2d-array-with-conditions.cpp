class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        vector<vector<int>> res(maxFreq, vector<int>());
        for(auto ptr = freq.begin(); ptr!=freq.end(); ptr++) {
            int curr=0;
            while(ptr->second--)
                res[curr++].push_back(ptr->first);
        }
        return res;
    }
};
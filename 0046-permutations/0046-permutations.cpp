class Solution {
public:
    
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& res) {
        if(idx==nums.size()){
            res.push_back(nums);
        }
        
        for(int j=idx; j<nums.size(); j++) {
            swap(nums[idx], nums[j]);
            backtrack(nums, idx+1, res);
            swap(nums[idx], nums[j]);
                
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
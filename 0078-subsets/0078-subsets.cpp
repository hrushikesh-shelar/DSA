class Solution {
    void helper(vector<int>& nums, int idx,vector<vector<int>>& res, vector<int> curr) {
        if(idx>=nums.size()) {
            res.push_back(curr);
            return;
        }
        
        helper(nums, idx+1, res, curr);
        curr.push_back(nums[idx]);
        helper(nums, idx+1, res, curr);
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res, {});
        return res;
    }
};
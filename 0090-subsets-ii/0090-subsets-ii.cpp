class Solution {
    void subsetsWithDupHelp(vector<int>& nums, set<vector<int>>& res, int currPos, vector<int> currSubset) {
        if(currPos>=nums.size()) {
            res.insert(currSubset);
            return;
        }
        subsetsWithDupHelp(nums, res, currPos+1, currSubset);
        for(int i=currPos; i<nums.size(); i++){
            currSubset.push_back(nums[i]);
            subsetsWithDupHelp(nums, res, i+1, currSubset);
            currSubset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        subsetsWithDupHelp(nums, res, 0, {});
        return vector<vector<int>> (res.begin(), res.end());
    }
};
class Solution {
private:
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
        int lo=i+1, hi=nums.size()-1;
        while(lo<hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                result.push_back({ nums[i], nums[lo++], nums[hi--] });
                while (lo < hi && nums[lo] == nums[lo - 1])
                    ++lo;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++) {
            if ((i == 0 || nums[i - 1] != nums[i]) && i<(nums.size()-2)) {
                twoSum(nums, i, result);
            }
        }
        return result;
    }
};
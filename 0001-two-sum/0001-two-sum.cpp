class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for(int j=0; j<nums.size(); j++) {
            if(mp.find(target-nums[j]) != mp.end() and mp[target-nums[j]] != j) {
                return { j, mp[target-nums[j]] };
            }
        }
        return {};
    }
};
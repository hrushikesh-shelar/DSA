class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res=0;
        int min_till_now=0;
        int max_till_now=0;
        int curr_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            res = max(res, abs(curr_sum-min_till_now));
            res = max(res, abs(curr_sum-max_till_now));
            min_till_now = min(min_till_now, curr_sum);
            max_till_now = max(max_till_now, curr_sum);
        }
        return res;
    }
};
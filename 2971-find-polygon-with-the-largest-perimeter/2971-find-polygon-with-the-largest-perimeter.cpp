class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prefixSum= (long long) (nums[0]+nums[1]), res=-1;
        for(int i=2; i<nums.size(); i++) {
            // cout<<"prefixSum:"<<prefixSum<<" nums:"<<nums[i]<<" res:"<<res<<endl;
            if(prefixSum>nums[i]) {
                res = max(res, prefixSum+nums[i]);
            }
            prefixSum += (long long) nums[i];
        }
        return res;
    }
};
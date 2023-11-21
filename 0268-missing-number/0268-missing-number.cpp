class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]<n) nums[nums[i]] += (n+1);
            else if(nums[i]>=(n+1) && nums[i]<(2*n+1)) nums[nums[i]-n-1] += (n+1);
        }
        for(auto x: nums) {
            cout<<x<<" ";
        }
        for(int i=0; i<n; i++) {
            if(nums[i] < (n+1)) {
                return i; 
            }
        }
        return n;
    }
};
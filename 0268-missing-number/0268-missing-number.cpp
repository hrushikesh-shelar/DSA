class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int totalSum = 0;
        for(int i=0; i<n; i++) {
            totalSum += nums[i];
        }
        return (int) (n*(n+1)/2 - totalSum);
    }
};
class Solution {
    vector<int> dp;
public:
    Solution() {
        dp.resize(50, 0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
    }
    int climbStairs(int n) {
        if(dp[n]!=0) {
            return dp[n];
        }
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
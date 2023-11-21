
class Solution {
    vector<int> dp;
public:
    Solution() : dp(50, -1) {}

    int climbStairs(int n) {
        if(dp[n]!=-1) return dp[n];
        if(n==0 or n==1) {
            return dp[n]=1;
        }
        return dp[n] = ( climbStairs(n-1) + climbStairs(n-2) );
    }
};
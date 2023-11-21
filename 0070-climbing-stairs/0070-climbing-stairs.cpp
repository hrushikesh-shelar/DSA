vector<int> dp(50, -1);
class Solution {
public:
    int climbStairs(int n) {
        if(dp[n]!=-1) return dp[n];
        if(n==0 or n==1) {
            return dp[n]=1;
        }
        return dp[n] = ( climbStairs(n-1) + climbStairs(n-2) );
    }
};
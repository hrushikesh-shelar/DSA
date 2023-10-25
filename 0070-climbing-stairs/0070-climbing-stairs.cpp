class Solution {
public:
//     int helper(int n, vector<int>& memo) {
//         if(memo[n] != -1) {
//             return memo[n];
//         }
        
//         return memo[n] = helper(n-1, memo) + helper(n-2, memo);
//     }
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
        
//         vector<int> memo(n+1, -1);
//         memo[0] = 1; memo[1] = 1;
//         return helper(n, memo);
        
        // if(n==0 or n==1) {
        //     return 1;
        // }
        
        
//         return climbStairs(n-1) + climbStairs(n-2);
    }
};
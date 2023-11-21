class Solution {
    int coinChangeRec(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount==0) {
            return 0;
        }
        if(amount<0) {
            return INT_MAX;
        }
        
        if(dp[amount]!=-1) {
            return dp[amount];
        }
        int ans=INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            ans = coinChangeRec(coins, amount-coins[i], dp)!=INT_MAX ?
                min(ans, coinChangeRec(coins, amount-coins[i], dp)+1)
                : ans;
        }
        return dp[amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0;
    
        sort(coins.rbegin(), coins.rend());
        vector<int> dp(amount+1, -1);
        
        coinChangeRec(coins, amount, dp);
        
        
        return dp[amount]!=INT_MAX ? dp[amount] : -1;
    }
};
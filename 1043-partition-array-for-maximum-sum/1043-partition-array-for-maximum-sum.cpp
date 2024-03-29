class Solution {
    int maxSum(vector<int>& arr, int k, int dp[], int start) {
        int N = arr.size();
        
        if (start >= N) {
            return 0;
        }
        
        // Return the already calculated answer.
        if (dp[start] != -1) {
            return dp[start];
        }
        
        int currMax = 0, ans = 0;
        int end = min(N, start + k);
        for (int i = start; i < end; i++) {
            currMax = max(currMax, arr[i]);
            // Store the maximum of all options for the current subarray.
            ans = max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }

        // Store the answer to be reused.
        return dp[start] = ans;
    }
    
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[arr.size()];
        memset(dp, -1, sizeof(dp));
        
        return maxSum(arr, k, dp, 0);
    }
};
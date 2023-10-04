class Solution {
public:
    int compute(vector<int>& satisfaction, int idx, int sr, vector<vector<int>>& memo) {
        if(idx>=satisfaction.size()) {
            return 0;
        }
        if(memo[idx][sr] != INT_MIN) {
            return memo[idx][sr];
        }
        int ans = max(
            satisfaction[idx]*(sr+1) + compute(satisfaction, idx+1, sr+1, memo),
            compute(satisfaction, idx+1, sr, memo)
        );
        memo[idx][sr] = ans;
        return ans;
    } 
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> memo(satisfaction.size()+1, vector<int>(satisfaction.size()+1, INT_MIN));
        return compute(satisfaction, 0, 0, memo);
    }
};
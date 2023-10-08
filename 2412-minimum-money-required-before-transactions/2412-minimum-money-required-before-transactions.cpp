class Solution {
public:
    static bool cust(vector<int> a, vector<int> b) {
        long long opt1 = min(-a[0], -a[0] + a[1] - b[0]); 
		long long opt2 = min(-b[0], -b[0] + b[1] - a[0]); 
		if (opt1 != opt2)
			return opt1 < opt2;
		return a[0] > b[0];
    }
    
    long long minimumMoney(vector<vector<int>>& t) {
        long long val=0, ans = 0;
        sort(t.begin(), t.end(), cust);
        for(auto x:t) {
            ans = max(ans, val);
            val = val + x[0];
            ans = max(ans, val);
            val = val - x[1];
            ans = max(ans, val);
        }
        return ans;
    }
};
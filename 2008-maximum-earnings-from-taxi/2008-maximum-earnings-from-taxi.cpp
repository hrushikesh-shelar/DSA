class Solution {
    
    int findNextIdx(vector<vector<int>>& rides, int low, int endTime) {
        int high=rides.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(rides[mid][0]>=endTime) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
      
        return ans;
    }
    
    long long calculateMaxEarning(int idx, int n, vector<vector<int>>& rides, vector<long long>& dp) {
        // cout<<"idx:"<<idx<<" ";
        if(idx>=rides.size()) {
            // cout<<"returned"<<endl;
            return 0ll;
        }
        if(dp[idx]!=-1) {
            return dp[idx];
        }
        int currentRideEndTime = rides[idx][1];
        int nextIdx = findNextIdx(rides, idx+1, currentRideEndTime);
        // cout<<"nextIdx:"<<nextIdx<<endl;
        
        long long takeRide = calculateMaxEarning(nextIdx, n, rides, dp) + (long long) (rides[idx][1]-rides[idx][0]+rides[idx][2]);
        long long skipRide = calculateMaxEarning(idx+1, n, rides, dp);
        
        return dp[idx] = max(takeRide, skipRide);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size()+1, -1);
        return calculateMaxEarning(0, n, rides, dp);
    }
};
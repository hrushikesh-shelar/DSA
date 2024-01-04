class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        for(auto it=freq.begin(); it!=freq.end(); it++) {
            if(it->second==1) {
                return -1;
            } else {
                int currOps;
                if(it->second%3==0) {
                    currOps = (it->second/3);
                } else if(it->second%3==1) {
                    currOps = (it->second-4)/3 + 2;
                } else if(it->second%3==2) {
                    currOps = (it->second-2)/3 + 1;
                }
                res+=currOps;
            }
        }
        return res;
    }
};
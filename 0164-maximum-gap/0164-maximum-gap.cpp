class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) {
            return 0;
        }
        priority_queue<int> maxHeap;
        for(int i=0; i<nums.size(); i++) {
            maxHeap.push(nums[i]);
        }
        int curr = maxHeap.top();
        maxHeap.pop();
        int res = 0;
        while(maxHeap.size()>0) {
            res = max(res, curr-maxHeap.top());
            curr = maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};
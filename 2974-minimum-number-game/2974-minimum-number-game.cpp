class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto i:nums) {
            minHeap.push(i);
        }
        vector<int> res;
        while(!minHeap.empty()) {
            int minimum= minHeap.top(); minHeap.pop();
            int minimum2= minHeap.top(); minHeap.pop();
            res.push_back(minimum2);
            res.push_back(minimum);
        }
        return res;
    }
};
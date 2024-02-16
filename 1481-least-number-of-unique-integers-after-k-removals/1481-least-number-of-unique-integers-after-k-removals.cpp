class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> freq;
        for(int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
        }
        for(auto it=freq.begin(); it!=freq.end(); it++) {
            minHeap.push(it->second);
        }
        // cout<<"1 minHeap.top():"<<minHeap.top()<<endl;
        while(!minHeap.empty() && k>=minHeap.top()) {
            // cout<<"minHeap.top():"<<minHeap.top()<<endl;
            k -= minHeap.top();
            minHeap.pop();
        }
        return minHeap.size();
    }
};
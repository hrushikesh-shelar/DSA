class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0; i<arr.size(); i++) {
            minHeap.push({abs(arr[i]-x), i});
        }
        vector<int> res;
        while(k--) {
            res.push_back(arr[minHeap.top().second]);
            minHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
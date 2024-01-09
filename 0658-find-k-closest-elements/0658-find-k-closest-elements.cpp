class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0; i<arr.size(); i++) {
            maxHeap.push({abs(arr[i]-x), i});
            if(maxHeap.size()>k) {
                maxHeap.pop();
            }
        }
        vector<int> res;
        while(k--) {
            res.push_back(arr[maxHeap.top().second]);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
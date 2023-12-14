class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int> maxHeap;
        int n = citations.size();
        for(int i=0; i<n; i++) {
            maxHeap.push(citations[i]);
        }
        int i =0;
        while (maxHeap.size()>0 && maxHeap.top() > i) {
            i++;
            // cout<<"i:"<<i<<endl;
            maxHeap.pop();
        }
        // cout<<"Final i:"<<i<<endl;
        return i;
    }
};
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for(int i=0; i<gifts.size(); i++) {
            maxHeap.push(gifts[i]);
        }
        long long ans = 0ll;
        while(k--) {
            int topEle = (int) sqrt(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(topEle);
        }
        while(!maxHeap.empty()) {
            ans += (long long) maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        priority_queue<int> maxHeap;
        if(amount[0]) maxHeap.push(amount[0]);
        if(amount[1]) maxHeap.push(amount[1]);
        if(amount[2]) maxHeap.push(amount[2]);
        
        while(maxHeap.size()>1) {
            int c1 = maxHeap.top(); maxHeap.pop(); c1--;
            int c2 = maxHeap.top(); maxHeap.pop(); c2--;
            if(c1) maxHeap.push(c1);
            if(c2) maxHeap.push(c2);
            ans++;
        }
        if(maxHeap.size()) ans+=maxHeap.top();
        return ans;
    }
};
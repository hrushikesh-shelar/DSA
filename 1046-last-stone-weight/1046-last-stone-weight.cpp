class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int weight: stones) {
            maxHeap.push(weight);
        }
        while(maxHeap.size()>1) {
            int w1 = maxHeap.top(); maxHeap.pop();
            int w2 = maxHeap.top(); maxHeap.pop();
            if(w1!=w2) {
                maxHeap.push(abs(w1-w2));
            }
        }
        return !maxHeap.empty() ? maxHeap.top() : 0;
    }
};
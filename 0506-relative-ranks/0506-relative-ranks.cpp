class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0; i<score.size(); i++) {
            maxHeap.push({score[i], i});
        }
        if(!maxHeap.size()) {
            return res;
        }
        res[maxHeap.top().second] = "Gold Medal";
        maxHeap.pop();
        if(!maxHeap.size()) {
            return res;
        }
        res[maxHeap.top().second] = "Silver Medal";
        maxHeap.pop();
        if(!maxHeap.size()) {
            return res;
        }
        res[maxHeap.top().second] = "Bronze Medal";
        maxHeap.pop();
        int rank = 4;
        while(maxHeap.size()) {
            res[maxHeap.top().second] = to_string(rank);
            maxHeap.pop();
            rank++;
        }
        return res;
    }
};
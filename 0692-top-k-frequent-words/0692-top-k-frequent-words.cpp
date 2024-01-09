struct compareHeapElements {
    bool operator()(pair<int, string> a, pair<int, string> b) {
        if(a.first!=b.first) {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for(auto word: words) {
            freqMap[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, compareHeapElements> maxHeap;
        for(auto it=freqMap.begin(); it!=freqMap.end(); it++) {
            maxHeap.push({it->second, it->first});
        }
        vector<string> res;
        while(k--) {
            // cout<<maxHeap.top().second<<" "<<maxHeap.top().first<<endl;
            res.push_back(maxHeap.top().second); maxHeap.pop();
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        map<int, priority_queue<int>> idToAvg;
        for(auto item: items)
            idToAvg[item[0]].push(item[1]);
        for(auto it=idToAvg.begin(); it!=idToAvg.end(); it++) {
            int id = it->first;
            int sum = 0;
            int five = 5;
            while(five--) {
                sum += it->second.top();
                it->second.pop();
            }
            res.push_back({id, sum/5});
        }
        return res;
    }
};
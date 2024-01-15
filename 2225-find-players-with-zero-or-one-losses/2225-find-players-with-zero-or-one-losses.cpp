class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> resultAggregate;
        for(int i=0; i<matches.size(); i++) {
            if(resultAggregate.find(matches[i][0])!=resultAggregate.end()) {
                resultAggregate[matches[i][0]].first++;
            } else {
                resultAggregate[matches[i][0]] = {1, 0};
            }
            
            if(resultAggregate.find(matches[i][1])!=resultAggregate.end()) {
                resultAggregate[matches[i][1]].second++;
            } else {
                resultAggregate[matches[i][1]] = {0, 1};
            }
        }
        
        vector<vector<int>> res;
        res.push_back({});
        res.push_back({});
        for(auto it=resultAggregate.begin(); it!=resultAggregate.end(); it++) {
            if((it->second).second==0) {
                res[0].push_back(it->first);
            } else if ((it->second).second==1) {
                res[1].push_back(it->first);
            }
        }
        return res;
    }
};
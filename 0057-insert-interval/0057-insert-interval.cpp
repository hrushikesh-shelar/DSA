class Solution {
    void insertIntervalInStack(stack<vector<int>>& intervalStack, vector<int> newInterval) {
        if(intervalStack.empty()) {
            intervalStack.push(newInterval);
            return;
        }
        if(intervalStack.top()[1]<newInterval[0]){
            intervalStack.push(newInterval);
        } else {
            vector<int> top = intervalStack.top();
            intervalStack.pop();
            vector<int> modifiedInterval = {
                min(top[0], newInterval[0]), max(top[1], newInterval[1])
            };
            intervalStack.push(modifiedInterval);
        }
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        bool isNewIntervalInserted = false;
        stack<vector<int>> intervalStack;
        for(int i=0; i<n; i++) {
            if(!isNewIntervalInserted && intervals[i][0]>newInterval[0]) {
                isNewIntervalInserted = true;
                insertIntervalInStack(intervalStack, newInterval);
            }
            insertIntervalInStack(intervalStack, intervals[i]);
        }
        if(!isNewIntervalInserted) {
            insertIntervalInStack(intervalStack, newInterval);
        }
        
        vector<vector<int>> res;
        while(!intervalStack.empty()) {
            res.push_back(intervalStack.top());
            intervalStack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    void combinationSumRec(vector<int>& candidates, int target, set<vector<int>>& res, vector<int> currCombo) {
        if(target==0) {
            sort(currCombo.begin(), currCombo.end());
            res.insert(currCombo);
            return;
        }
        if(target<0) {
            return;
        }
        for(int i=0; i<candidates.size(); i++) {
            currCombo.push_back(candidates[i]);
            combinationSumRec(candidates, target-candidates[i], res, currCombo);
            currCombo.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        combinationSumRec(candidates, target, res, {});
        vector<vector<int>> finalRes (res.begin(), res.end());
        return finalRes;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> backtrack(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo){
        vector<TreeNode*> res;
        if(start>end) {
            res.push_back(nullptr);
            return res;
        }
        if(start==end) {
            TreeNode* root = new TreeNode(start);
            res.push_back(root);
            return res;
        }
        
        if(memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }
        
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftTrees =  backtrack(start, i-1, memo);
            vector<TreeNode*> rightTrees =  backtrack(i+1, end, memo);
            
            for(auto left: leftTrees) {
                for(auto right: rightTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        map<pair<int, int>, vector<TreeNode*>> memo;
        
        res = backtrack(1, n, memo);
        return res;
    }
};
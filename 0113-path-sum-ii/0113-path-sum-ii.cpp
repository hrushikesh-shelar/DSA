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
    void pathSumHelper(TreeNode* root, int targetSum, int currSum, vector<int> currPath, vector<vector<int>>& ans) {
       if(!root) {
           return;
       }
       currSum += root->val;
       currPath.push_back(root->val);
       if(!root->left and !root->right) {
           if(currSum==targetSum)
             ans.push_back(currPath);
           return;
       }
       pathSumHelper(root->left, targetSum, currSum, currPath, ans);
       pathSumHelper(root->right, targetSum, currSum, currPath, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        int currSum=0;
        pathSumHelper(root, targetSum, currSum, currPath, ans);
        return ans;
    }
};
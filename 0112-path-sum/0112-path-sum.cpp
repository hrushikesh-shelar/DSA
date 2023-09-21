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
    void pathSumHelper(TreeNode* root, int targetSum, int currSum, bool& ans) {
        if(!root) {
            return;
        }
        
        currSum += root->val;
        if(!root->left && !root->right) {
            if(currSum==targetSum)
               ans = true;
            return;
        }
        
        pathSumHelper(root->left, targetSum, currSum, ans);
        pathSumHelper(root->right, targetSum, currSum, ans);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int currSum = 0;
        pathSumHelper(root, targetSum, currSum, ans);
        return ans;
            
    }
};
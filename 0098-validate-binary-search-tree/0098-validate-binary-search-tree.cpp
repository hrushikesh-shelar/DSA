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
    bool checkIsValid(TreeNode* root, long minLimit, long maxLimit) {
        if(!root) {
            return true;
        }
        if((long)root->val < minLimit or (long) root->val > maxLimit) {
            return false;
        }
        
        return (checkIsValid(root->left, minLimit, (long)root->val-1) and checkIsValid(root->right, (long)root->val+1, maxLimit));
    }
    
    bool isValidBST(TreeNode* root) {
        return checkIsValid(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};
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
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& pre) {
        if (!root) return;
        
        inorder(root->left, first, second, pre);
        
        if (pre && root->val < pre->val) {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        
        inorder(root->right, first, second, pre);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre = nullptr;
        
        inorder(root, first, second, pre);
        
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};

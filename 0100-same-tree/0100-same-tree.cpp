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
    bool inorder(TreeNode* p, TreeNode* q) {
        if(!((p and q) or (!p and !q))) {
            return false;
        }
        if(!p and !q) {
            return true;
        }
        
        return (p->val == q->val) and inorder(p->left, q->left) and inorder(p->right, q->right);
        
        
    };
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return inorder(p, q);
    }
};
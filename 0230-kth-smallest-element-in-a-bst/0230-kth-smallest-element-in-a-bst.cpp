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
    void inorderTraversal(TreeNode* root, int& count, int k, int& ans) {
        if(root==nullptr) {
            return;
        }
        inorderTraversal(root->left, count, k, ans);
        count++;
        if(count==k) {
            ans = root->val;
        }
        inorderTraversal(root->right, count, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0, ans = -1;
        inorderTraversal(root, cnt, k, ans);
        return ans;
    }
};
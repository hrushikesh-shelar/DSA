/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void printChildrenNodesAtGivenDistance(TreeNode* root, int k, vector<int>& ans) {
        if(root==nullptr || k<0){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        printChildrenNodesAtGivenDistance(root->left, k-1, ans);
        printChildrenNodesAtGivenDistance(root->right, k-1, ans);
    }
    int traverseAndPrintNode(TreeNode* root, TreeNode* target, int k, vector<int>& ans){
        if(root==nullptr) {
            return -1;
        } 
        if(root==target) {
            printChildrenNodesAtGivenDistance(root, k, ans);
            return 0;
        }
        
        int leftDistance = traverseAndPrintNode(root->left, target, k, ans);
        if(leftDistance !=-1) {
            if(leftDistance+1 == k) {
                ans.push_back(root->val);
            } else{
              printChildrenNodesAtGivenDistance(root->right, k-leftDistance-2, ans);   
            }
            return leftDistance+1;
        }
        
        int rightDistance = traverseAndPrintNode(root->right, target, k, ans);
        if(rightDistance !=-1) {
            if(rightDistance+1 == k) {
                ans.push_back(root->val);
            } else{
              printChildrenNodesAtGivenDistance(root->left, k-rightDistance-2, ans);   
            }
            return rightDistance+1;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        traverseAndPrintNode(root, target, k, ans);
        return ans;
    }
};
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
    
    int robHelper(TreeNode* root, bool isParentRobbed, unordered_map<TreeNode*, int>& withNodeRobbed, unordered_map<TreeNode*, int>& withoutNodeRobbed) {
        if(root==nullptr) {
            return 0;
        }
        
        
        if(isParentRobbed) {
            if(withoutNodeRobbed.find(root)!=withoutNodeRobbed.end()) {
                return withoutNodeRobbed[root];
            }
            return withoutNodeRobbed[root] = robHelper(root->left, false, withNodeRobbed, withoutNodeRobbed)+robHelper(root->right, false, withNodeRobbed, withoutNodeRobbed);
        }
        
        if(withoutNodeRobbed.find(root)!=withoutNodeRobbed.end() && withNodeRobbed.find(root)!=withNodeRobbed.end()) {
            return withoutNodeRobbed[root] +  withNodeRobbed[root];
        }
        
        int withRootRobbed = withNodeRobbed.find(root)!=withNodeRobbed.end() ? withNodeRobbed[root] : (root->val + robHelper(root->left, true, withNodeRobbed, withoutNodeRobbed)+robHelper(root->right, true, withNodeRobbed, withoutNodeRobbed));
        
        int withoutRootRobbed = withoutNodeRobbed.find(root)!=withoutNodeRobbed.end() ? withoutNodeRobbed[root] : (robHelper(root->left, false, withNodeRobbed, withoutNodeRobbed)+robHelper(root->right, false, withNodeRobbed, withoutNodeRobbed));
        
        return max(withNodeRobbed[root] = withRootRobbed, withoutNodeRobbed[root] = withoutRootRobbed);
        
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> withNodeRobbed;
        unordered_map<TreeNode*, int> withoutNodeRobbed;
        
        return max(root->val+robHelper(root->left, true, withNodeRobbed, withoutNodeRobbed)+robHelper(root->right, true, withNodeRobbed, withoutNodeRobbed), robHelper(root->left, false, withNodeRobbed, withoutNodeRobbed)+robHelper(root->right, false, withNodeRobbed, withoutNodeRobbed));
    }
};
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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
        //     cout<<"inorder:"<<inLeft<<" "<<inRight<<endl;
        // cout<<"postorder:"<<postLeft<<" "<<postRight<<endl;
            if(inLeft==inRight) {
                return new TreeNode(inorder[inLeft]);
            }
            if(inLeft>inRight) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(postorder[postRight]);
            int currentRootIdx;
            for(int i=inLeft; i<=inRight; i++) {
                if(inorder[i]==postorder[postRight]) {
                    currentRootIdx = i;
                }
            }
            int leftLength = currentRootIdx - inLeft;
            int rightLength = inRight - currentRootIdx;
            root->left = helper(inorder, postorder, inLeft, inLeft+leftLength-1, postLeft, postLeft + leftLength-1);
            root->right = helper(inorder, postorder, currentRootIdx+1, inRight, postRight-rightLength, postRight-1);
        return root;
            
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) {
            return nullptr;
        }
        
        return helper(inorder, postorder, 0, n-1, 0, n-1);
        
    }
};
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
    void traverseChildNodes(TreeNode* root, int& maxTime, int currTime){
        if(root==nullptr) {
            return;
        }
        if(currTime>maxTime){
            maxTime = currTime;
        }
        cout<<root->val<<" "<<currTime<<" "<<maxTime<<endl;
        traverseChildNodes(root->left, maxTime, currTime+1);
        traverseChildNodes(root->right, maxTime, currTime+1);
    }
    
    int getDistanceOfNodeFromStart(TreeNode* root, int& start, int& maxTime) {
        if(root==nullptr) {
            return -1;
        }

        if(root->val==start) {
            traverseChildNodes(root, maxTime, 0);
            return 0;
        }
        
        int dl = getDistanceOfNodeFromStart(root->left, start, maxTime);
        if(dl!=-1){
            if(dl+1>maxTime){
                maxTime = dl+1;
            }
            cout<<"left: "<<root->val<<" "<<dl+1<<" "<<maxTime<<endl;
            traverseChildNodes(root->right, maxTime, dl+2);
            return dl+1;
        }
        
        int dr = getDistanceOfNodeFromStart(root->right, start, maxTime);
        if(dr!=-1){
            if(dr+1>maxTime){
                maxTime = dr+1;
            }
            cout<<"right:"<<root->val<<" "<<dr+1<<" "<<maxTime<<endl;
            traverseChildNodes(root->left, maxTime, dr+2);
            return dr+1;
        }
        return -1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int maxTime=0;
        getDistanceOfNodeFromStart(root, start, maxTime);
        return maxTime;
    }
};
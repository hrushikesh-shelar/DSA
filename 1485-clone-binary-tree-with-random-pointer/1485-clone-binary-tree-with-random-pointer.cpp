/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(!root) {
            return nullptr;
        }
        unordered_map<Node*, NodeCopy*> copy;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            Node* curr = nodeQueue.front();
            copy[curr] = new NodeCopy(curr->val);
            nodeQueue.pop();
            if(curr->left)  nodeQueue.push(curr->left);
            if(curr->right) nodeQueue.push(curr->right);
        }
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            Node* curr = nodeQueue.front();
            nodeQueue.pop();
            if(curr->random) copy[curr]->random = copy[curr->random];
            if(curr->left)  {
                copy[curr]->left = copy[curr->left];
                nodeQueue.push(curr->left);
            }
            if(curr->right)  {
                copy[curr]->right = copy[curr->right];
                nodeQueue.push(curr->right);
            }
        }
        return copy[root];
    }
};
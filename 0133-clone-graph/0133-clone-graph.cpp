/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) {
            return nullptr;
        }
        map<Node*, Node*> originalToCopyNode;
        originalToCopyNode[node] = new Node(node->val);
        queue<Node*> bfs;
        bfs.push(node);
        
        while(!bfs.empty()) {
            Node* curr = bfs.front();
            bfs.pop();
            
            for(Node* neighbor: curr->neighbors) {
                if(originalToCopyNode.find(neighbor)==originalToCopyNode.end()) {
                    originalToCopyNode[neighbor] = new Node(neighbor->val);
                    bfs.push(neighbor);
                }
                originalToCopyNode[curr]->neighbors.push_back(originalToCopyNode[neighbor]);
            }
        }
        return originalToCopyNode[node];
    }
};
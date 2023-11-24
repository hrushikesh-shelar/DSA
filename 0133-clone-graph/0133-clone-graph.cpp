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
    map<Node*, bool> visitedMap;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> originalNodeToClonedNodeMap;
        Node* clonedNode = new Node(node->val);
        originalNodeToClonedNodeMap[node] = clonedNode;
        
        queue<Node*> bfsQueue;
        bfsQueue.push(node);
        
        while(!bfsQueue.empty()) {
            Node* currOriginalNode = bfsQueue.front();
            bfsQueue.pop();
            
            for(Node* neighborOriginalNode: currOriginalNode->neighbors) {
                if(!originalNodeToClonedNodeMap.count(neighborOriginalNode)) {
                    Node* clonedNeighborNode = new Node(neighborOriginalNode->val);
                    bfsQueue.push(neighborOriginalNode);
                    originalNodeToClonedNodeMap[neighborOriginalNode] = clonedNeighborNode;
                }
                originalNodeToClonedNodeMap[currOriginalNode]->neighbors.push_back(originalNodeToClonedNodeMap[neighborOriginalNode]);
            }
            
        }
        return clonedNode;
    }
};

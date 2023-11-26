class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        map<int, int> parent;
        parent[0] = -1;
        stack<int> dfsStack;
        dfsStack.push(0);
        while(!dfsStack.empty()) {
            int currNode = dfsStack.top();
            dfsStack.pop();
            for(int neighbor:adj[currNode]) {
                if(parent[currNode]==neighbor) {
                    continue;
                }
                if(parent.contains(neighbor)){
                    return false;
                }
                dfsStack.push(neighbor);
                parent[neighbor]=currNode;
            }
        }
        return parent.size()==n;
    }
};
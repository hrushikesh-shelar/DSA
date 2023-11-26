class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> seen(n, false);
        int numberOfComponents = 0;
        for(int i=0; i<n; i++){
            if(!seen[i]) {
                numberOfComponents++;
                queue<int> bfsQ;
                bfsQ.push(i);
                seen[i] = true;
                while(!bfsQ.empty()) {
                    int curr = bfsQ.front();
                    bfsQ.pop();
                    for(int neighbor: adj[curr]) {
                        if(!seen[neighbor]) {
                            bfsQ.push(neighbor);
                            seen[neighbor] = true;
                        }
                    }
                }
            }
        }
        return numberOfComponents;
    }
};
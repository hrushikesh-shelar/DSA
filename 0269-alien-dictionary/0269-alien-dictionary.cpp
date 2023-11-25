class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        map<char, vector<char>> graph;
        map<char, int> indegree;
        for (string word : words) {
            for (char c : word) {
                indegree[c]=0;
                graph[c] = {};
            }
        }
        
        for(int i=0; i<words.size()-1; i++) {
            string previousWord = words[i];
            string nextWord = words[i+1];
            if(previousWord.size() > nextWord.size() and previousWord.substr(0, nextWord.size())==nextWord)
                return "";
            for(int j=0; j<min(previousWord.size(), nextWord.size()); j++) {
                if(previousWord[j]!=nextWord[j]) {
                    graph[previousWord[j]].push_back(nextWord[j]);
                    indegree[nextWord[j]]++;
                    break;
                }
            }
        }
        
        queue<char> bfsGraph;
        for(auto &x: indegree) {
            // cout<<"x.first:"<<x.first<<"  x.second:"<<x.second<<endl;
            if(x.second==0) {
                bfsGraph.push(x.first);
            }
        }
        
        string ans;
        while(!bfsGraph.empty()) {
            char curr = bfsGraph.front();
            bfsGraph.pop();
            ans.push_back(curr);
            for(int i=0; i<graph[curr].size(); i++) {
                indegree[graph[curr][i]]--;
                if(!indegree[graph[curr][i]])
                    bfsGraph.push(graph[curr][i]);
            }
        }
        if(ans.size()<indegree.size()){
            return "";
        }
        return ans;
    }
};
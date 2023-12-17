class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;

        // All servers are free at the beginning.

        for (int i = 0; i < k; ++i) {
            free.insert(i);
        }
        
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];
            // Move free servers from 'busy' to 'free'.
            while (!busy.empty() && busy.top().first <= start) {
                auto [_, serverId] = busy.top();
                busy.pop();
                free.insert(serverId);
            }

            // If we have free servers, use binary search to find the 
            // target server.
            if (!free.empty()) {
                auto ptr = free.lower_bound(i % k);
                if (ptr == free.end()) {
                    ptr = free.begin();
                }
                int busyId = *ptr;
                free.erase(busyId);
                busy.push(make_pair(start + load[i], busyId));
                count[busyId]++;
            }
        }

        // Find the servers that have the maximum workload.
        vector<int> answer;
        auto maxJob = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};
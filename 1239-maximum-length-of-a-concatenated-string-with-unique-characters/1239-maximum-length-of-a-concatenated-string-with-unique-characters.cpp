class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> results = {""};
        int best = 0;
        for (string word : arr) {
            // We only want to iterate through results
            // that existed prior to this loop
            int resultsLen = results.size();
            for (int i = 0; i < resultsLen; i++) {
                // Form a new result combination and
                // use a set to check for duplicate characters
                string newRes = results[i] + word;
                unordered_set<char> newResSet(newRes.begin(), newRes.end());
                if (newRes.size() != newResSet.size())
                    continue;

                // Add valid options to results and
                // keep track of the longest so far
                results.push_back(newRes);
                best = max(best, (int)newRes.size());
            }
        }
        return best;
    }
};
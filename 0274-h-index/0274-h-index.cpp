class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int n = citations.size();
        int i = 0;
        while (i < n && citations[i] > i) {
            i++;
        }
        return i;
    }
};
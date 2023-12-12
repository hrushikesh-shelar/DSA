class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) {
            return 0;
        }
        priority_queue<int> descending;
        priority_queue<int, vector<int>, greater<int>> ascending;
        
        for(auto x: nums) {
            descending.push(x); ascending.push(x);
        }
        vector<int> large;
        int counter = 4;
        while(counter--) {
            large.push_back(descending.top());
            descending.pop();
        }
        int minDiff = INT_MAX;
        counter = 4;
        while(counter) {
            minDiff = min(minDiff, large[counter-1]-ascending.top());
            ascending.pop();
            counter--;
        }
        return minDiff;
    }
};


// large1 large2 large3 large4
// small1 small2 small3 small4

// [1,5,0,10,14]
// 14 10 5 1
// 0  1  5 10
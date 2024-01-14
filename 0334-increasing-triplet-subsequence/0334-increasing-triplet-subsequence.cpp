class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_num = INT_MAX;
        int second_num = INT_MAX;
        for (int n: nums) {
            if (n <= first_num) {
                first_num = n;
            } else if (n <= second_num) {
                second_num = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
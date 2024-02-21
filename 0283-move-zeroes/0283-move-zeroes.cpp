class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]!=0) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        while(ptr<n) {
            nums[ptr]=0;
            ptr++;
        }
    }
};
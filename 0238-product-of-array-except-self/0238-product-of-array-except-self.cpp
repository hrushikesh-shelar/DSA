class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lengthOfNums = nums.size();
        vector<int> res(lengthOfNums, 0);
        res[lengthOfNums-1] = nums[lengthOfNums-1];
        
        for(int i=lengthOfNums-2; i>=0; i--) {
            res[i] = res[i+1]*nums[i];
        }
        
        res[0] = res[1];
        int prefixProduct = 1;
        for(int i=1; i<lengthOfNums-1; i++) {
            prefixProduct = prefixProduct*nums[i-1];
            res[i] = res[i+1]*prefixProduct;
        }
        prefixProduct = prefixProduct*nums[lengthOfNums-2];
        res[lengthOfNums-1] = prefixProduct;
        return res;
        
    }
};
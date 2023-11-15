class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1]>=nums[0]){
            return nums[0];
        }
        int start = 0, end = n-1;
        while(start<=end) {
            int mid = (start+end)/2;
            // cout<<"start:"<<start<<" end:"<<end<<" mid:"<<mid<<endl;
            if(mid>0 && nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            if(nums[mid]<nums[0]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
        
    }
};
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=4){
            return 0;
        }
        //1st
        int res=nums[n-1]-nums[3];
        //2nd
        res=min(res,nums[n-4]-nums[0]);
        //3rd
        res=min(res,nums[n-2]-nums[2]);
        //4th
        res=min(res,nums[n-3]-nums[1]);
        return res;
    }
};


// large1 large2 large3 large4
// small1 small2 small3 small4

// [1,5,0,10,14]
// 14 10 5 1
// 0  1  5 10
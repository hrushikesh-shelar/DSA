class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityEle = nums[0];
        int cnt=1;
        for(int i=1; i<nums.size(); i++) {
            cout<<"majorityEle:"<<majorityEle<<"  count:"<<cnt<<endl;
            if(nums[i]==majorityEle) {
                cnt++;
            } else {
                cnt--;
                if(cnt<0) {
                    majorityEle = nums[i];
                    cnt = 1;
                }
            }
        }
        // int majorityEleCount = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i]==majorityEle) {
        //         majorityEleCount++;
        //     }
        // }
        // if(majorityEleCount<=(nums.size()/2)) {
        //     return majorityEle;
        // }
        return majorityEle;
        
    }
};
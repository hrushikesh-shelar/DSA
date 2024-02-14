class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> res(numSize, 0);
        int posIdx = 0, negIdx =1;
        for(int i=0; i<numSize; i++) {
            if(nums[i]>0) {
                // cout<<"posIdx:"<<posIdx<<endl;
                res[posIdx] = nums[i];
                posIdx += 2;
            } else {
                // cout<<"negIdx:"<<negIdx<<endl;
                res[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        return res;
    }
};
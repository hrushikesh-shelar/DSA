class KthLargest {
    priority_queue<int, vector<int>, greater<int>> kLargestElements;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++) {
            if(kLargestElements.size()>=this->k) {
                if(nums[i]>kLargestElements.top()) {
                    kLargestElements.pop();
                    kLargestElements.push(nums[i]);
                }
            } else {
                kLargestElements.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(kLargestElements.size()>=this->k) {
                if(val>kLargestElements.top()) {
                    kLargestElements.pop();
                    kLargestElements.push(val);
                }
            } else {
                kLargestElements.push(val);
            }
        return kLargestElements.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
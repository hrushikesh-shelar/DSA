class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n) {
            // cout<<n<<endl;
            res+=n&1;
            n/=2;
        }
        return res;
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int msb = n & (1<<31);
        if(!msb)
            n = ~n;
        while(n) {
            res = res*2 + n%2;
            n/=2;
        }
        if(!msb)
            res = ~res;
        return res;
    }
};
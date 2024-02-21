class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // turn off rightmost 1-bit
            n = n & (n - 1);
        }
        return m & n;
    }
};
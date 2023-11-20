class Solution {
public:
    int getSum(int a, int b) {
        int x=abs(a), y=abs(b);
        if(x<y){return getSum(b, a);}
        int sign = a<0 ? -1 : 1;
        
        if(a*b>0) {
            while(y) {
                int summation = x^y;
                int carry = (x&y) << 1;
                x = summation;
                y = carry;
            }
        } else {
            while(y) {
                int summation = x^y;
                int carry = (~x&y) << 1;
                x = summation;
                y = carry;
            }
        }
        return sign*x;
    }
};
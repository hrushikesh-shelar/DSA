class Solution {
public:
    long reverse(int x) {
        long res=0;
        while(x) {
            int t = x%10;
            res = res*10 + t;
            cout<<"t:"<<t<<" ";
            cout<<"res:"<<res<<" ";
            cout<<"x:"<<x<<endl;
            x /= 10;
        }
        return res;
    }

    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        long rev = reverse(x);
        if(rev == (long) x) {
            return true;
        }

        return false;
    }
};
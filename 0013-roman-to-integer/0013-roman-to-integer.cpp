class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='M') {
                res+=1000;
            }
            if(s[i]=='D') {
                res+=500;
            }
            if(s[i]=='C') {
                if(i+1<s.size() && (s[i+1]=='D' or s[i+1]=='M')) {
                    res+=(-100);   
                }
                else {
                    res+=(100);
                }
            }
            if(s[i]=='L') {
                res+=50;
            }
            if(s[i]=='X') {
                if(i+1<s.size() && (s[i+1]=='L' or s[i+1]=='C')) {
                    res+=(-10);   
                }
                else {
                    res+=(10);
                }

            }
            if(s[i]=='V') {
                res+=5;
            }
            if(s[i]=='I') {
                if(i+1<s.size() && s[i+1]!='I')
                    res+=(-1);
                else {
                    res+=(1);
                }
            }
        }
        return res;
    }
};
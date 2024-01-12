class Solution {
public:
    bool halvesAreAlike(string s) {
        int leftCnt =0, rightCnt=0;
        int n = s.size();
        for(int i=0; i<n/2; i++) {
            if(
                s[i]=='a' or 
                s[i]=='e' or 
                s[i]=='i' or
                s[i]=='o' or
                s[i]=='u' or
                s[i]=='A' or
                s[i]=='E' or
                s[i]=='I' or
                s[i]=='O' or
                s[i]=='U'
            ) {
                leftCnt++;
            }
            
            if(
                s[n-1-i]=='a' or 
                s[n-1-i]=='e' or 
                s[n-1-i]=='i' or
                s[n-1-i]=='o' or
                s[n-1-i]=='u' or
                s[n-1-i]=='A' or
                s[n-1-i]=='E' or
                s[n-1-i]=='I' or
                s[n-1-i]=='O' or
                s[n-1-i]=='U'
            ) {
                rightCnt++;
            }
        }
        return leftCnt == rightCnt;
    }
};
class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int diff=0;diff<n;diff++)
        {
            for(int i =0,j=i+diff;j<n;i++,j++)
            {
                if(i==j)
                {
                    // single letter is always a palindrome
                    dp[i][j]=1;
                }
                else if(diff==1)
                {
                    // if true then store 2 else 0 
                    dp[i][j]=(s[i]==s[j])?2:0;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j] && j-i+1>maxi)
                {
                    maxi=j-i+1;
                    ans=s.substr(i,maxi);
                }
            }
        }
        
        return ans;
    }
};
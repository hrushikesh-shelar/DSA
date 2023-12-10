class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans=0; 
        unordered_map<char,int> count;
        int l=0, r=0, N=s.size();
        while (r<N) {
          count[s[r]]++;
          while (count.size()>2 && r>=l) {
            count[s[l]]--;      
            if (count[s[l]]==0)
                count.erase(s[l]);
            l++;
          }  
          ans=max(ans,r-l+1);  
          r++;
        }
        return ans;
    }
};
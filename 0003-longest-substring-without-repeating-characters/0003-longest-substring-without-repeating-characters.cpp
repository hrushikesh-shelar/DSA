class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, beg = 0, end = 0;
        map<char, int> mp;
        
        for(int i=0; i<s.size(); i++) {
            // cout<<"Map:"<<endl;
            // for(auto x:mp) {
            //     cout<<
            // }
            if(mp.find(s[i]) != mp.end() && mp[s[i]]>0) {
                while(s[beg] != s[i]){
                    mp[s[beg]]--;
                    beg++;   
                }
                mp[s[beg]]--;
                beg++;
                
            }
            mp[s[i]]++;
            end = i;
            res = max(res, end-beg+1);
            // cout<<"beg:"<<beg<<" end:"<<end<<" res:"<<res<<endl;
        }
        return res;
    }
};
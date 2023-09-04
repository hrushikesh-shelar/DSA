class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length(), n = needle.length();
        if(h<n){
            return -1;
        }
        
        for(int i=0; i<=(h-n); i++) {
            // cout<<"i:"<<i<<" i+n:"<<(i+n)<<endl;
            // cout<<"needle:"<<needle<<"  haystack:"<<haystack.substr(i, n)<<endl;
            if(needle == haystack.substr(i, n))
                return i;
        }
        return -1;
    }
};
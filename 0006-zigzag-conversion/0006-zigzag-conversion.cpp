class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int n = s.length();
        int clusterSize = numRows*2-2;
        string res;
        for(int i=0; i<n; i+=clusterSize) {
            cout<<i<<" ";
            res.push_back(s[i]);
        }
        int n_clusters = n%clusterSize == 0 ? n/clusterSize : n/clusterSize+1;
        for(int j=1; j<clusterSize/2; j++) {
             for(int i=0; i<=n_clusters; i++) {
                cout<<i*clusterSize+j<<" ";
                if(i*clusterSize+j < n)
                    res.push_back(s[i*clusterSize+j]);
                cout<<(i+1)*clusterSize-j<<" ";
                if((i+1)*clusterSize-j < n)
                    res.push_back(s[(i+1)*clusterSize-j]);
            }
        }
        for(int i=0; i<n; i+=clusterSize) {
            cout<<i+numRows-1<<" ";
            if(i+numRows-1 < n)
            res.push_back(s[i+numRows-1]);
        }
        return res;
        
    }
};
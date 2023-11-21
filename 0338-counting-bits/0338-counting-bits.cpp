class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0){
            return res;
        }
        res.push_back(1);
        if(n==1){
            return res;
        }
        for(int i=2; i<=n; i++) {
            if(i%2==0) {
                res.push_back(res[i/2]);
            }
            else {
                res.push_back(res[i/2]+1);
            }
        }
        return res;
    }
};
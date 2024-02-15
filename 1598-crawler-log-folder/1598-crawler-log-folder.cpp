class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res=0;
        for(int i=0; i<logs.size(); i++) {
            if(logs[i]=="../") {
                res = res-1 > 0 ? res-1: 0;
            } else if(logs[i]=="./") {
                
            } else {
                res++;
            }
        }
        return res;
    }
};
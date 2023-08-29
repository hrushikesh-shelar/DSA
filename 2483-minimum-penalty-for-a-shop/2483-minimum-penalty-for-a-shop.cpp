class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n+1, 0), post(n+1, 0);

        for(int i=0; i<=n; i++) {
            if(i!=0) pre[i] = pre[i-1] + ( customers[i-1] == 'Y' ? 0 : 1 );
            if(i!=n) post[n-1-i] = post[n-i] + ( customers[n-i-1] == 'N' ? 0 : 1 );
        }

        int res=0, min_penalty = n+10;
        for(int i=0; i<=n; i++) {
            if(min_penalty>(pre[i]+post[i])) {
                res = i;
                min_penalty = (pre[i]+post[i]);
            }
        }

        return res;
    }
};
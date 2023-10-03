class Solution {
public:
    int egg(int k, int n, vector<vector<int>>& memo) {
    
        if(n==1 or n==0 or k==1) {
            return n;
        }
        // cout<<"n:"<<n<<" k:"<<k<<endl;
        if(memo[k][n] != -1) {
            return memo[k][n];
        }
        int ans = INT_MAX;
        // for(int i=2; i<=n; i++) {
        //     ans = min(ans, 1 + max(egg(k-1, i-1, memo), egg(k, n-i, memo)));
        // }
        
        int l = 2, h = n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=egg(k-1,mid-1,memo);
            int right=egg(k,n-mid,memo) ;
            int temp=1+max(left,right);
            if(left<right){
              l=mid+1;
            }
            else
            {    
                h=mid-1;
            }
            ans=min(ans,temp);
        }
        
        memo[k][n] = ans;
        return ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        // cout<<"memo.length():"<<memo.size()<<" memo[0].length():"<<memo[0].size()<<endl;
        return egg(k, n, memo);
    }
};
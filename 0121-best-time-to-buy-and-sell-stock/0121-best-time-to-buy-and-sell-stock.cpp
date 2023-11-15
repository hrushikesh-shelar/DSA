class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = 10001, currProfit = 0;
        for(int i=0; i<prices.size();i++) {
            if(prices[i]<lowestPrice) lowestPrice = prices[i];
            if(currProfit<(prices[i]-lowestPrice)) currProfit = prices[i]-lowestPrice;
        }
        return currProfit;
    }
};
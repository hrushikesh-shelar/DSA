class StockPrice {
    int latestTime;
    unordered_map<int, int> stockPrice; // timestamp - price
    map<int, int> priceFrequency;
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        if(stockPrice.contains(timestamp)) {
            int existingStockPrice = stockPrice[timestamp];
            stockPrice[timestamp] = price;
            priceFrequency[existingStockPrice]--;
            if(priceFrequency[existingStockPrice]==0) {
                priceFrequency.erase(existingStockPrice);
            }
            priceFrequency[price]++;
        } else {
            if(timestamp>latestTime) {
                latestTime = timestamp;
            }
            stockPrice[timestamp] = price;
            priceFrequency[price]++;
        }
    }
    
    int current() {
        return stockPrice[latestTime];
    }
    
    int maximum() {
        return priceFrequency.rbegin()->first;
    }
    
    int minimum() {
        return priceFrequency.begin()->first;
    }
};

// 10, 1, 3

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
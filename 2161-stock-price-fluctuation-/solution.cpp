class StockPrice {
private:
    int latestTime;
    map<int, int> priceCount;
    unordered_map<int, int> timePrice;
public:
    StockPrice() 
    {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) 
    {
        latestTime = max(latestTime, timestamp);
        
        if(timePrice.find(timestamp) != timePrice.end())
        {
            int old = timePrice[timestamp];
            priceCount[old]--;
            
            if(priceCount[old] == 0)
            {
                priceCount.erase(old);
            }
        }
        timePrice[timestamp] = price;
        priceCount[price]++;
        
    }
    
    int current() 
    {
       return timePrice[latestTime];
    }
    
    int maximum() 
    {
        return priceCount.rbegin()->first;   
    }
    
    int minimum() 
    {
        return priceCount.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

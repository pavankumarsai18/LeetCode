class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int totalDays = prices.size();
        
        int maxProfit = 0;
        int minPrice  = prices[0];
        
        for(int day = 1; day < totalDays; day++)
        {
            int profit = prices[day] - minPrice;
            if(profit > maxProfit)
            {
                maxProfit = profit;
            }
            if(prices[day] < minPrice)
            {
                minPrice = prices[day];
            }
        }
        
        return maxProfit;
        
    }
};

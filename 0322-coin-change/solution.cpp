class Solution {
public:
    int minimumCoins(vector<int>& coins, int amount, unordered_map<int, int> & cache)
    {
        // cout<<amount<<endl;
        // for(auto & item: cache)
        //     cout<<item.first<<": "<<item.second<<endl;
        // cout<<"--------\n";

        if(cache.find(amount) != cache.end())
            return cache[amount];
            
        if(amount < 0)
        {
            cache[amount] = -1;
            return -1;
        }
        
        
        int numCoins = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int coinsRequired = minimumCoins(coins, amount-coins[i], cache);
            // cout<<coins[i]<<" "<<coinsRequired<<endl;;

            if(coinsRequired >= 0 &&coinsRequired < INT_MAX)
            {
                numCoins = min(numCoins, coinsRequired + 1);
                cache[amount] = numCoins;
            }
        }
        
        if(numCoins == INT_MAX)
        {
           cache[amount] = -1;
        }
        
        return cache[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        unordered_map<int, int> cache;
        for(auto coin:coins)
            cache[coin] = 1;
        cache[0] = 0;
        return minimumCoins(coins, amount, cache);
    
    }
};

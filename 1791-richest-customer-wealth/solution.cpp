class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for(auto customer: accounts)
        {
            int total = 0;
            for(auto money: customer)
            {
                total += money;
            }
            
            if(result < total)
                result = total;
        }
        
        return result;
    }
};

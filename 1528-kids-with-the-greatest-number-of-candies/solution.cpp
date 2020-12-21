class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int max = candies[0];
        
        for(auto c: candies){
            if(max < c)
                max = c;
        }
        
        vector<bool> result(candies.size(), true);
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i]+extraCandies >= max){
                result[i] = true;
            }
            else
            {
                result[i] = false;
            }
        }
        
        return result;
        
    }
};

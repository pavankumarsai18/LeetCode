class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        
        const int n = ratings.size();
        
        auto count = [](int n){return n*(n+1)/2;};
        
        if(n <= 1)
            return 1;
        int candies, up, down, oldSlope;
       
        candies = up = down = oldSlope = 0;
        
        for(int i = 1; i < n; i++)
        {
            int newSlope = (ratings[i] > ratings[i-1])? 1: (ratings[i] < ratings[i-1])? -1:0;
            
            if(oldSlope > 0 && newSlope == 0 || oldSlope < 0 && newSlope >= 0)
            {
                candies += (count(up) + count(down) + max(up, down));
                up = down = 0;
            }
            
            if(newSlope > 0)
            {
                up++;
            }
            else if(newSlope < 0)
            {
                down++;
            }
            else
            {
                candies++;
            }
            oldSlope = newSlope;
            
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }
};

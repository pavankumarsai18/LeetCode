class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> result(num_people,0);
        
        int i = 0;
        int count = 1;
        while(1)
        {
            if(candies > count)
            {
                result[i] += count;
                candies -= count;
            }
            else
            {
                result[i] += candies;
                candies = 0;
                break;
            }
            
            i++;
            count ++;
            if(i >= result.size())
                i = 0;
            
        }
        return result;
        
    }
};

class Solution {
public:    
    int thirdMax(vector<int>& nums) 
    {
        unordered_set<int> items;
        
        for(int i = 0; i < nums.size(); i++)
        {
            items.insert(nums[i]);
            if(items.size() > 3)
            {
                int minimum = *(items.begin()++);
                for(auto & item: items)
                {
                    minimum = min(minimum, item);
                }
                items.erase(minimum);
            }
        }
        if(items.size() == 3)
        {
            int minimum = *(items.begin()++);
            for(auto & item: items)
            {
                minimum = min(minimum, item);
            }
            return minimum;
            
        }
        
        int maximum = *(items.begin()++);
        for(auto & item: items)
        {
            maximum = max(maximum, item);
        }
        return maximum;
    }
};

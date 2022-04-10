class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) 
    {
        
        int maximum;
        maximum=nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            maximum = max(maximum, nums[i]);
        }
        
        vector<int> counts(maximum + 1, 0);
        
        for(int i = 0;i < nums.size();i++)
        {
            counts[nums[i]]++;
        }
        
        for(int i = counts.size()-1; i >= 0; i--)
        {
            if(counts[i] == 1)
            {
                return i;
            }
        }
        return -1;
        
    }
};

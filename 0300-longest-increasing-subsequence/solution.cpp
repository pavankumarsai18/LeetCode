class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> subSequence;
        
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = lower_bound(subSequence.begin(), subSequence.end(), nums[i]);
            if(itr == subSequence.end())
            {
                subSequence.push_back(nums[i]);
            }
            else
            {
                *itr = nums[i];
            }
        }
        
        return subSequence.size();
        
    }
};

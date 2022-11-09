class Solution {
public:
    int countElements(vector<int>& nums) {
        int maximum = *std::max_element(nums.begin(), nums.end());
        int minimum = *std::min_element(nums.begin(), nums.end());
        
        if(maximum == minimum) return 0;
        
        int num_remove = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maximum || nums[i] == minimum)
                num_remove++;
        }
        
        return nums.size() - num_remove;
        
    }
};

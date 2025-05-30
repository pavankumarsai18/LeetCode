class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) 
    {
        const int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
            {
                count++;
            }
        }
        return (count > n/2);
        
    }
};

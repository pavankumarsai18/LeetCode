class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        
        // modify the partition algorithm based on %2 
        const int pivotValue = 0;
        
        int startIndex = -1;
        for(int endIndex = 0; endIndex < nums.size(); endIndex++)
        {
            if((nums[endIndex]&1) == 0)
            {
                swap(nums[++startIndex], nums[endIndex]);
            }
        }
        
        return nums;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        const int n = nums.size();
        int invIndex = -1;
        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(invIndex != -1)
                    return false;
                invIndex = i;
            }
        }
        
        // [3,4,2,3]
        // 
        return (invIndex <= 0 || invIndex == n-2 || nums[invIndex-1] <= nums[invIndex+1] || nums[invIndex] <= nums[invIndex+2]);
        
    }
};
